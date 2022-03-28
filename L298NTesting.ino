#include <L298N.h>
// https://github.com/AndreaLombardo/L298N
//Ok so this is a test program for the L298N library.
//It will run a the actuator forward and backwards, depending how it is wired.
/*
    Functions from the Library:
    void setSpeed(int speed);
    void getSpeed();
    void setDirection(int direction); //0 = forward, 1 = backward, or you can use L298N::FORWARD and L298N::BACKWARD
    void getDirection();
    L298N forward();
    L298N backward();

    These are the main ones, there are more so checkout the github but this is most of it.
    Keep in mind we'll use two motors with a single L298N, and look at how I've implemented the demo below.

    setup runs before loop, and loop loops.

*/

const unsigned int IN1 = 2;
const unsigned int IN2 = 4;
const unsigned int EN = 3;
L298N motor(EN, IN1, IN2);

// 255 is VERY loud

void setup()
{

    // Start serial at 9600
    Serial.begin(9600);
    while (!Serial)
    {
        Serial.println("Serial not connected");
    }
    motor.setSpeed(155);
}

void loop(){
    motor.forward();

    delay(5000);
    motor.stop();
    motor.setSpeed(255);
    motor.backward();
    delay(5000);
}