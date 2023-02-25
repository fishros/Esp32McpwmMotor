# Esp32McpwmMotor


[中文](./README.md) | [English](./README_EN.md)

The motor driving library based on ESP32's MCPWM (Motor Control Pulse Width Modulator) supports up to 6 channels of motor driving.

Usage in platformio.ini:

```ini
lib_deps = 
	https://github.com/fishros/Esp32McpwmMotor.git
```


Example code for two motors:

```cpp
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
    motor.updateMotorSpeed(0, -70);  // 70% duty cycle
    motor.updateMotorSpeed(1, 70);
    delay(2000);
    motor.updateMotorSpeed(0, 70);
    motor.updateMotorSpeed(1, -70);
    delay(2000);
}
```


Example code for four motors:

```cpp
#include <Arduino.h>
#include <Esp32McpwmMotor.h>

Esp32McpwmMotor motor;

void setup()
{
    Serial.begin(115200);

    motor.attachMotor(0, 33, 25);
    motor.attachMotor(1, 26, 27);
    motor.attachMotor(2, 12, 22);
    motor.attachMotor(3, 16, 17);
}

void loop()
{
    motor.updateMotorSpeed(0, -70);  // 70% duty cycle
    motor.updateMotorSpeed(1, 70);
    motor.updateMotorSpeed(2, -70);
    motor.updateMotorSpeed(3, 70);
    delay(2000);
    motor.updateMotorSpeed(0, 70);
    motor.updateMotorSpeed(1, -70);
    motor.updateMotorSpeed(2, 70);
    motor.updateMotorSpeed(3, -70);
    delay(2000);
}
```

Author: fishros (fishros@foxmail.com)