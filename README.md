# Esp32McpwmMotor
 Esp32 Motor Driver Use MCPWM.

Example Control Two Motor.

```
#include <Arduino.h>
#include <Esp32McpwmMotor.h>

Esp32McpwmMotor motor;

void setup()
{
  Serial.begin(115200);
  motor.attachMotors(22, 23, 12, 13);
}

void loop()
{
  motor.updateMotorSpeed(0, 50);
  motor.updateMotorSpeed(1, -50);
}
```