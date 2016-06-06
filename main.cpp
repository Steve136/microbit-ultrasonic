#include "MicroBit.h"
MicroBit uBit;

DigitalInOut pingPin(MICROBIT_PIN_P1); //Set the Ping pin on the HC-SR04 to PIN 1 on the Microbit.
DigitalInOut echoPin(MICROBIT_PIN_P0); //Set the Echo pin on the HC-SR04 to PIN 0 on the Microbit.

long msToIn(long microseconds);
long msToCm(long microseconds);
long readSensor();

int main() {
   uBit.init();
   
    while(1) {
        //Perform a read of the sensor.
        long ms = readSensor();

        //Print out the results, converting to Inches and CM
        uBit.serial.printf("Sensor Returned: Inches: %ld, CM: %ld\n", msToIn(ms), msToCm(ms));
        uBit.sleep(5000);
    }
}

long msToIn(long microseconds) {
    return microseconds / 147;
}
 
long msToCm(long microseconds) {
    return microseconds / 59;
}

long readSensor() {
     Timer t;
     pingPin.output();
     pingPin = 0;
     uBit.sleep(0.2);
     pingPin = 1; 
     uBit.sleep(0.5);
     pingPin = 0;
        
     echoPin.input();

     while (!echoPin); 
     t.start();
     while (echoPin); 
     long duration = t.read_us();
        
     t.stop();
     t.reset();
     return duration;
}
