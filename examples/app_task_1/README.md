# Task 1 App for Crazyflie 2.X

This folder contains the app layer application for the task 1 of the "Studienwoche".

PROGRAMMING TASK 1:
Your goal is to blink the front left LED!
Step 1: turn on the front left LED in red or green
Step 2: blink the LED instead
Step 3: can you change the brightness of the LED by pulsing it? (meaning turning it on and off faster than you can see)

some hints:
void ledSet(led_t led, bool value) can be used to turn on (value 1) and off (value 0) the LEDs. 
The identifier of the front left red LED is: LED_RED_L
The identifier of the front left green LED is: LED_GREEN_L


See App layer API guide and build instructions [here](https://www.bitcraze.io/documentation/repository/crazyflie-firmware/master/userguides/app_layer/)