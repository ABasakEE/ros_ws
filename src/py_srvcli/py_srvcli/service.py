from example_interfaces.srv import AddTwoInts
import rclpy
from rclpy.node import Node

class MinimalService(Node):

    def __init__(self) -> None:
        super().__init__('minimal_service')
        self.create_service(AddTwoInts,'add_two_ints',self.req_callback)

    def req_callback(self,request,response):
        response.sum = request.a + request.b 
        self.get_logger().info('Incoming request\na: %d b: %d' % (request.a, request.b))
        return response
    

def main(args=None):
    rclpy.init(args=args)

    minimal_service=MinimalService()

    rclpy.spin(minimal_service)

    rclpy.shutdown()

if __name__=='main':
    main()




    