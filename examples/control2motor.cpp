#include <Arduino.h>
#include <Esp32McpwmMotor.h>

Esp32McpwmMotor motor;

void setup()
{
    Serial.begin(115200);

    motor.attachMotor(0, 33, 25);
    motor.attachMotor(1, 26, 27);
}

void loop()
{
    motor.updateMotorSpeed(0, -70);
    motor.updateMotorSpeed(1, 70);
    delay(2000);
    motor.updateMotorSpeed(0, 70);
    motor.updateMotorSpeed(1, -70);
    delay(2000);
}
