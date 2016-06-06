# microbit-ultrasonic
Example usage of a HC-SR04 Ultrasonic Sensor and the BBC Micro:Bit. The example will return the duration in microseconds and then convert this to a valid Inches or Centimeters value.

Change the lines below to match your Ultrasonic Echo and Ping sensor:

DigitalInOut pingPin(**MICROBIT_PIN_P1**); 
DigitalInOut echoPin(**MICROBIT_PIN_P0**);

Check out the **main_display_blick.cpp** for an example of how to provide visual feedback to the Micro:Bit display. This will show three different size blocks, depending on how close to the sensor an object is.

**Note: The HC-SR04 Ultrasonic Sensor is a 5v device. It needs 5v to operate, not the supplied 3v from the BBC Micro:Bit. You will need an external power source. The Trigger and Echo pin connect to the Micro:Bit.**
