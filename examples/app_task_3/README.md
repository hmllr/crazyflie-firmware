# Task 3 App for Crazyflie 2.X

This folder contains the app layer application for the task 3 of the "Studienwoche".

PROGRAMMING TASK 3:
Your goal is to get to know the sensors as well as the logging and parameter system!
Step 1: Log the accelerometer data to the cfclient. 
Step 2: Add a parameter in the app and print its value to the cfclient console
Step 3: Modify the parameter from the cfclient
Step 4: (advanced) use a parameter to chose which tone or even song the drone should play
 
some hints:
DEBUG_PRINT("Hello World! %d \n", a); will print Hello World!, a previously defined integer (number without comma), and a new line
Check out https://www.bitcraze.io/documentation/repository/crazyflie-firmware/master/userguides/logparam/

See App layer API guide and build instructions [here](https://www.bitcraze.io/documentation/repository/crazyflie-firmware/master/userguides/app_layer/)