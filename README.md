# off-the-shelf-drone-control 
Interfaced an inexpensive drone($18) with Arduino in order to control drone inputs through Arduino IDE.
# Initial Steps: 
* Received the drone (sky viper nano) and Arduino Uno kit
* Installed arduino IDE (integrated development environment) on my laptop
* Tested the drone

![The Sky Viper Nano drone is a lightweight mini drone](SkyViperNano.png)


[The Sky Viper Nano drone is a lightweight mini drone](https://www.amazon.com/Sky-Viper-Drone-Black-Green/dp/B07G1RJXGF)

# Interfacing: 
* Unscrewed the drone controller
* Identified the joystick connections on the PCB (printed circuit board)
* Measured the voltage for three connections on each joystick potentiometer (3.35v between ends and ~1.68v the middle base in relaxed status)
* Cut the middle bases of joysticks on PCB (because we want to control it ourselves) and soldered wires to the traces that lead to the chip, as well soldered wires to the ground/on-off button connection(don’t need to cut this with cutter) / launch & land connections on the drone controller PCB
* Wrote an Arduino code to generate PWM (pulse-wave modulation) outputs on Arduino’s four output PWM pins

# Drone Controller

![](DroneController.png)
* Numbers indicate joystick connections#1 represents roll, #2 is pitch, #3 is throttle, #4 is yaw, #5 is land/launch


# Stabilizing and Launching

* Added low-pass RC filters (PWM to DC) and OP-AMPs to Arduino’s 4 PWM outputs
* Added one PWM output in the code for launch/land followed by an RC filter(C connected to 3.35 v) to the new PWM pin.
* After this testing was complete, I wrote a program to control the drone launch/land, throttle, pitch, and yaw through the Arduino IDE
* I was able to make it turn on and ascend/descend with triggering launch/land. Orbit was done using yaw and roll, and speed control was done by pitch. 
* I also saw that adding a pause before landing improves control and makes it more smooth.

# Circuit Schematic + Expansion Board Circuit

![](CircuitSchematic.png)


