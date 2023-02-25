# Esp32McpwmMotor

基于ESP32的MCPWM（Motor Control Pulse Width Modulator）实现的电机驱动库，最多支持6路电机驱动。


使用方式：platformio.ini

```ini
lib_deps = 
	https://github.com/fishros/Esp32McpwmMotor.git
```

两路舵机例程：

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
    motor.updateMotorSpeed(0, -70);   // 70%占空比
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



四路舵机例程：

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
    motor.updateMotorSpeed(0, -70);  // 70%占空比
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



Autor: 小鱼(fishros@foxmail.com)