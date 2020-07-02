import cv2
import numpy as np
from PIL import ImageGrab
import time
import pyautogui as pag

##countdown from 3
for i in list(range(3))[::-1]:
    print(i+1)
    time.sleep(1)

##entering keystrokes as inputs into heboris ue exe
##pag.keyDown('z')
##pag.keyUp('z')
##pag.keyDown('left')
##pag.keyUp('left')
##pag.keyDown('right')
##pag.keyUp('right')
##pag.keyDown('up')
##pag.keyUp('up')
##pag.keyDown('down')
##pag.keyUp('down')
##pag.keyDown('z')
##pag.keyUp('z')
##pag.keyDown('z')
##pag.keyUp('z')

##manipulating the recording of the screen to make data simpler
def process(screen):
    processed_img = cv2.cvtColor(screen, cv2.COLOR_BGR2GRAY)
    processed_img = cv2.inRange(processed_img, lowerb=20, upperb=255)
    return processed_img

##recording an area of the screen
last_time = time.time()
while(True):
    screen = np.array(ImageGrab.grab(bbox=(450, 40, 830, 855)))
    screen2 = process(screen)
    #print('Loop time:', time.time()-last_time) #shows how fast the program is running
    last_time = time.time()
    cv2.imshow('Processed Tetris', screen2) #creates a window
    if cv2.waitKey(25) and 0xFF == ord('q'):
        cv2.destroyAllWindows()
        break



