import cv2 as cv

path='Aruco_2.MOV'
window='test'
wait_time=15
dict=cv.aruco.DICT_4X4_250

def rescaleFrame(frame,scale=0.5):
    width=int(frame.shape[1]*scale)
    height=int(frame.shape[0]*scale)
    dimensions=(width,height)
    
    return cv.resize(frame,dimensions,interpolation=cv.INTER_AREA)

arucoDict=cv.aruco.getPredefinedDictionary(dict)
arucoParams = cv.aruco.DetectorParameters()
detector=cv.aruco.ArucoDetector(arucoDict,arucoParams)

video=cv.VideoCapture(path)

while True:
    isTrue, frame=video.read() 
    if (not isTrue): #break loop when video ends
        print('No frames detected')
        break
    
    (corners,ids,rejected)=detector.detectMarkers(frame) #work on each frame
    cv.imshow(window,rescaleFrame(cv.aruco.drawDetectedMarkers(frame,corners,ids),0.6))

    
    keyCode = cv.waitKey(wait_time)
    if (keyCode & 0xFF) == ord("q"):
        cv.destroyAllWindows()
        break

video.release()

