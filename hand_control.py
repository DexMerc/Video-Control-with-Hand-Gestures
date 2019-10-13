import serial #To get data from Arduino
import time #Short delay is required
import pyautogui #To 

ArduinoSerial = serial.Serial('COM4',9600) #COM4 is depends on computer and port we are using
time.sleep(2) #To be sure that everything is connected

while True: # Just infinite loop :)
    data = str (ArduinoSerial.readline()) #read data and print it
    print(data)
    
    #This commands strictly for VLC player, other player may have different hotkeys
    if 'Play/Pause' in data:
        pyautogui.typewrite(['space'], 0.2)

    if 'Rewind' in data:
        pyautogui.hotkey('ctrl', 'left')  

    if 'Forward' in data:
        pyautogui.hotkey('ctrl', 'right') 

    if 'Vup' in data:
        pyautogui.hotkey('ctrl', 'up')
        
    if 'Vdown' in data:
        pyautogui.hotkey('ctrl', 'down')

    data = ""; #To refresh
    