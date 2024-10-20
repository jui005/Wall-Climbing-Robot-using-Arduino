note : change the int1,int2,int3,int4 according to your gpio arduino connections.
Project Overview: Wall-Climbing Robot
The wall-climbing robot is a compact, versatile system designed to move on vertical surfaces by leveraging a suction mechanism. It uses an Arduino for control, an IR remote for user inputs, and an LN298N motor driver to manage the movement of the robot in four directions: forward, backward, left, and right.

Key Components:
Arduino: Acts as the central control unit, receiving input signals from the IR remote and directing the motor drivers.
LN298N Motor Driver: Controls four DC motors responsible for the directional movement (forward, backward, left, right). These motors are connected to the motor driver, which receives control signals from the Arduino.
1kHz Motor (Suction Motor): Positioned at the center of the robot, this motor generates enough suction to enable the robot to stick to walls. It operates at 1kHz frequency to create a stable vacuum for adhesion.
Servo Tester: Controls the suction motor by varying the input signals. It regulates the speed and power of the suction, ensuring the robot can stay attached to surfaces.
IR Remote: Provides wireless control to the user, allowing them to direct the robot's motion through the Arduino, which interprets these signals and controls the motors accordingly.
Functionality:
Movement: The robot uses four motors, with two controlling forward and backward motion and the other two controlling right and left turns. The LN298N motor driver, interfaced with the Arduino, ensures precise control over these motions.
Suction System: The 1kHz motor in the center generates suction, which allows the robot to climb and stay attached to walls. The motor's speed and suction power are modulated using the servo tester, providing stability even on vertical surfaces.
Remote Control: The IR remote sends signals to the Arduino, enabling the user to control the robot's direction wirelessly.
Overview of Operation:
Initialization: The Arduino initializes the motor driver and sets up communication with the IR remote.
User Input: The user sends directional commands via the IR remote.
Directional Control: The Arduino processes the IR signals and activates the corresponding motors via the LN298N motor driver to move the robot in the desired direction.
Suction Activation: The suction motor, controlled by the servo tester, is activated to create a vacuum that keeps the robot adhered to the wall.
Movement on Wall: While the robot remains attached to the surface, it can move in any direction based on the user's input.
