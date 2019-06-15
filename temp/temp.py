import numpy as np
import cv2

img = cv2.imread("./Neighborhood_watch_bw.png", cv2.IMREAD_GRAYSCALE)
string = ""
for i in range(img.shape[0]):
    for j in range(img.shape[1]):
        if(img[i][j] == 0):
            string = string + '0'
        else:
            string = string + '1'

text_file = open("test_case_img.txt", "w")
text_file.write(string)
text_file.close()



