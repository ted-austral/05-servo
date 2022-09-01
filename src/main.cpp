/*
 *     Project 05-servo - main.cpp
 *
 * 
 *       IntroCom - Austral - 2022 - EAM
 *       Shows how a servo is positioned as per table
 *       Using ESP32 development board
 *
 *       Uses a C++ library for ESP32 servo
 */

#include <Arduino.h>

#include <Servo.h>

/*
 *  Constants defined in platformio.ini
 *      MY_SERVO    GPIO where data is connected
 *      SERIAL_BAUD Serial port Baud rate
 */

#define END_LIST    -1      //  Only to terminate array by value

Servo servo;                //    A new object of type Servo

void
setup(void)
{
    Serial.begin(SERIAL_BAUD);
    servo.attach(MY_SERVO); //    Attach GPIO pin to object Servo
    Serial.printf("\n\r\n08-servo\n\r");
    delay(2000);
}

//    Positioning table

static const int grads[] = {0, 45, 90, 135, 180, 135, 90,45, END_LIST};

void
loop(void)
{
    int i;

    for (i = 0; grads[i] >= 0; ++i)
    {
        Serial.println("grads = " + String(grads[i]) );
        servo.write(grads[i]);
        delay(1000);
    }
}


