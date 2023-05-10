# Task 2 App for Crazyflie 2.X

This folder contains the app layer application for the task 2 of the "Studienwoche".

PROGRAMMING TASK 2:
Your goal is to play a song with the motors!
Step 1: Play a tone with one motor - use the prepared motorsPlayTone() function for this. 
Step 2: Play a tone on all motors - still using the same function
Step 3: Use the prepared function motorsPlayMelody to play a melody of your choice.

some hints:
we need to cheat a bit - to prevent the firmware from turning off the motors you can just slightly move your drone the first minute after turning on, such that it will not succeed in calibrating.
you have the four motors, with IDs MOTOR_M1 to MOTOR_M4
in motors.h you find defines for the frequencies from C4 to B7
The timer clock frequency is MOTORS_TIM_BEEP_CLK_FREQ
The function you should use is:
void motorsBeep(int id, bool enable, uint16_t frequency, uint16_t compareRegister)
where the id is the id of the motor you want to address, 
enable is true or false depending on if you want to enable the motor at all or not, 
frequency is the target frequency of the beep and 
compareRegister is the value until the PWM is high. 
20% duty cycle is a good choice.

See App layer API guide and build instructions [here](https://www.bitcraze.io/documentation/repository/crazyflie-firmware/master/userguides/app_layer/)