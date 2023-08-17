
import cv2 
import numpy as np 
src = cv2.imread('images/dz-7.jpg', cv2.IMREAD_UNCHANGED) 
print(src.shape) # assign blue channel to zeros 
src[:,:,0] = np.zeros([src.shape[0], src.shape[1]]) #save image 
cv2.imshow('D:/no-blue-channel.png',src)
cv2.waitKey(0)
