import cv2 as cv
import numpy as np

path='/home/arjoe/Pictures/Screenshots/aruco_test1.png'
window_name='test'
wait_time = 1000

image=cv.imread(path,cv.IMREAD_ANYCOLOR)

arucoDict=cv.aruco.getPredefinedDictionary(cv.aruco.DICT_6X6_1000)
arucoParams = cv.aruco.DetectorParameters()
detector=cv.aruco.ArucoDetector(arucoDict,arucoParams)
(corners,ids,rejected)=detector.detectMarkers(image)
'''print('corners')
print(corners)
print('ids')
print(ids)
print('rejected')
print(rejected)'''

try:
    for corner in corners:
        c=np.ndarray.flatten(corner).tolist()
        print(c,len(c))
    id=np.ndarray.flatten(ids).tolist()
    print(id,len(id))
    print('List creation')
    pass
except:
    print('No arucos detected in front of me')

cv.imshow(window_name,cv.aruco.drawDetectedMarkers(image,corners,ids))

#cv.imshow(window_name,image) #(window_name,image_link)
cv.waitKey(0) #wait for key command





while cv.getWindowProperty(window_name, cv.WND_PROP_VISIBLE) >= 1:
    keyCode = cv.waitKey(wait_time)
    if (keyCode & 0xFF) == ord("q"):
        cv.destroyAllWindows()
        break
