# HP.NEL.iHMI

iHMI code

1. Robot
   1) Hardware 
   Robot was ( Magician Robot, DOBOT ) connected to Arduino Mega 2560 with serial communication method.
   Analog pin A0 to A4 was connected to each strain sensors.

  2) Running
    After hardware configuration, every code in 'Robot' folder should be stored in same directory and 
   'dobot.ino' should be uploaded to arduino.

  2. Virtual reality
   1) Hardware
   Arduino Mega 2560 was connected to laptop computer by serial communication method. Digital pin D4 
   to D8 were connected to vibration motor for haptic feedback. Analog pin A0 to A4 was connected to 
   each strain sensors.

   2) Virtual space(Unity 2021.3.7f1)
   In virtual space, Avatar and ball object(sphere) was created
  
  - Object and component settings
    Avatar`s left hand was located above the ball and capsule collider component was added with same size of finger at the last joint of left hand. The code in 'unity code' folder 'touchfeedback1.cs' to 'touchfeedback5.cs' was inserted in each last joint object of avatar in order of thumb to little finger. Text 1 to 5, Text (legacy) object was inserted in each element.
    'motion_controller.cs' in 'unity code' folder was added in avatar object. Each parameters from Flex 1 to 5 and and Bend 1 to 5 was 
 measured while calibration process. And Text 1 to 5, Text (legacy) object was inserted. In 'Moving' elements, second joint and third joint of each finger was inserted.

   3) Arduino mega 2560    
final_demo_v1.ino should be uploaded on arduino.
    


    
