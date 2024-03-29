import rclpy
from rclpy.node import Node
from tutorial_interfaces.srv import CVImg
from cv_bridge import CvBridge 
import cv2 as cv


class MinimalClient(Node):

    def __init__(self)->None:
        super().__init__('aruco_client')
        self.cli=self.create_client(CVImg,'cv_img')
        while not self.cli.wait_for_service(timeout_sec=1.0): #waiting for sever to respond
            self.get_logger().info('service not available, waiting again...')
        self.req = CVImg.Request()


    def send_request(self, img):
        self.req.img = img
        self.future = self.cli.call_async(self.req)
        rclpy.spin_until_future_complete(self, self.future)
        return self.future.result()
    



def main(args=None):
    path=input('Enter the path of the video file:')
    #can use the code for a single picture also
    video=cv.VideoCapture(path)
    
    if not video.isOpened():
        print('No video found. Terminating program...')
        return
    
    rclpy.init(args=args)
    minimal_client = MinimalClient()    
        
    #enter the file name here
    #path='/home/arjoe/ros_ws/src/py_srvcli/py_srvcli/Aruco_1.MOV'
    #window='test'
    #here take a photo from the path, convert it into ros img and then send request
    #img=cv.imread(path,cv.IMREAD_ANYCOLOR) 
    bridge=CvBridge() #initialise CVBridge
    
    
    while True:
        isTrue, frame=video.read() 
        if (not isTrue): #break loop when video ends
            print('No frames detected')
            break   
       
        
        ros_msg=bridge.cv2_to_imgmsg(frame,encoding='passthrough') #converting to a ROS msg
    
        response = minimal_client.send_request(ros_msg)
        print('request sent')
        while rclpy.ok():
            rclpy.spin_once(minimal_client)
            if minimal_client.future.done():
                try:
                    response = minimal_client.future.result()
                except Exception as e:
                    minimal_client.get_logger().info('Service call failed %r' % (e,))
                except KeyboardInterrupt:
                    print('Program terminated')
                    minimal_client.destroy_node()
                    rclpy.shutdown()
                else:
                    minimal_client.get_logger().info('Info received')
                    #processing the response sent
                    print('IDs detected:')
                    for id in response.ids:
                        print(id,end=' ')
                    print()
                    #breaking into groups of 2 and step
                    print('Corners detected')
                    i,j=0,0
                    for corner in response.corners:
                        i+=1
                        j+=1
                        if i==1: 
                            print('(',end=' ')
                        print(corner,end=' ')
                        if (i==2):
                            print(')',end=' ')
                            i=0
                        if (j==8): #move to the next row
                            j=0
                            print('\n')
                                  
            break

    minimal_client.destroy_node()
    rclpy.shutdown()

if __name__=='main':
    main()
