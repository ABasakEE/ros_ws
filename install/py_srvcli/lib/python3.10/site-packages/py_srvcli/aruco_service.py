from tutorial_interfaces.srv import CVImg                                                           # CHANGE

import numpy as np
import rclpy
from rclpy.node import Node
import cv2 as cv
from cv_bridge import CvBridge


class MinimalService(Node):

    def __init__(self,dict):
        super().__init__('aruco_service')
        self.arucoDict=dict
        self.bridge = CvBridge() #initialising the bridge
        self.srv = self.create_service(CVImg, 'cv_img', self.detectAruco)       

    def detectAruco(self, request, response):
        cv_img = request.img        
        img = self.bridge.imgmsg_to_cv2(cv_img,desired_encoding='passthrough')                                  
        self.get_logger().info('Incoming request img received')
        
        #performing aruco detection
        arucoDict=cv.aruco.getPredefinedDictionary(self.arucoDict)
        arucoParams = cv.aruco.DetectorParameters()
        detector=cv.aruco.ArucoDetector(arucoDict,arucoParams)
        (corners,ids,rej)=detector.detectMarkers(img)
        
        #print('c\n',len(c[0]),'i',len(i[0]))
        
        #converting to 1D
        #corners=np.ndarray.flatten(c[0])
        #ids=np.ndarray.flatten(i[0])
        #rejected=np.ndarray.flatten(rej[0])
        
        #print(corners.dtype,ids.dtype)
        
        #print(ids,'\nids\n',corners,'\ncorners')
        detectedCorners=list()
        detectedIDs=list()
        try:
            for corner in corners:
                c=np.ndarray.flatten(corner).tolist()
                detectedCorners.extend(c)
            detectedIDs=np.ndarray.flatten(ids).tolist()
        except:
            print('No arucos detected in front of me')

        
        if (len(detectedCorners)>0):#corners detected
            for corner in detectedCorners:
                response.corners.append(corner)
        if (len(detectedIDs)>0): #ids detected
            for id in detectedIDs:
                response.ids.append(id)
        
        
        #returning the response
        return response

def main(args=None):
    rclpy.init(args=args)
    aruco_dict=cv.aruco.DICT_4X4_250

    minimal_service = MinimalService(aruco_dict)
    try:
        rclpy.spin(minimal_service)
    except KeyboardInterrupt:
        print('Program terminated')
        minimal_service.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()