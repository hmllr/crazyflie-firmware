# Task 5 for Crazyflie 2.X

This is task 5 of the "Studienwoche". Note that this task does not involve any programming.

TASK 5:
Your goal is to tune the PID controller!
Step 1: Open the cfclient and in it the "tuner" toolbox 
Step 2: Choose a PID to tune
Step 3: Tune (one parameter at a time)!
Step 4: Repeat step 2 and 3.

P (proportional) gain:
        increase this for more responsiveness
        reduce if the response is overshooting and/or oscillating (up to a certain point increasing the D gain also helps).
D (derivative) gain:
        this can be increased to dampen overshoots and oscillations
        increase this only as much as needed, as it amplifies noise (and can lead to hot motors)
I (integral) gain:
        used to reduce steady-state error
        if too low, the response might never reach the setpoint (e.g. in wind)
        if too high, slow oscillations can occur

See App layer API guide and build instructions [here](https://www.bitcraze.io/documentation/repository/crazyflie-firmware/master/userguides/app_layer/)