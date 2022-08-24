# Video Control with Hand Gestures
## ROBT 206 Microcontrollers course project 

### Team members
* Sultan B.
* Bauyrzhan Zh.  <@BZWayne>

### Project Description
For implementing this project we used the following components:
* Arduino UNO
* 2 Ultrasonic sensors
* Breadboard
* 18x Dupont wire (M-to-M)
* 8x Dupont wire (F-to-F)
* 2x Dupont wire (F-to-M)
* LED (Red)
* Resistor (220Ω)

The aim of the project is to simplify the process of watching video via VLC player.

The purpose of simplifying video watching is to provide an easy way of controlling video, more specifically play/pause, sound level, rewind, and forward.

Ultrasonic sensor will measure the distance between hands and sensors that will allow to control the video via VLC Player. LED will turn on or flash during the every action. 

* If both the hands are in front of left and right sensors, then video will Play/Pause.
* If hand is placed in front of the right sensor, then the video should Fast Forward one step.
* If hand is placed in front of the left sensor, then the video should Fast Rewind one step.
* If hand is placed at right sensor in a particular close distance and then moving towards the sensor will fast forward continuously the video, otherwise rewind continuously.
* If hand is placed at left sensor in a particular close distance and then moving towards the sensor will increase the sound level of video otherwise decrease.
