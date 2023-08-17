import cv2
import numpy as np
## Read and merge
img = cv2.imread("images/dz-6.jpg")
img_hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
arr = []
## Gen lower mask (0-5) and upper mask (175-180) of RED
mask1 = cv2.inRange(img_hsv, (0,50,20), (5,255,255))
mask2 = cv2.inRange(img_hsv, (175,50,20), (180,255,255))

## Merge the mask and crop the red regions
mask = cv2.bitwise_or(mask1, mask2 )
croped = cv2.bitwise_and(img, img, mask=mask)
contours,h = cv2.findContours(mask,cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
for cnt in contours:
            area = cv2.contourArea(cnt)
            if(area > 200.0):
                    arr.append(area)
print(max(arr))
## Display
cv2.imshow("mask", mask)
cv2.imshow("croped", croped)
cv2.waitKey()

            
