# Esp32McpwmMotor

[中文](./README.md) | [English](./README_EN.md)

基于ESP32的MCPWM（Motor Control Pulse Width Modulator）实现的电机驱动库，最多支持6路电机驱动。


使用方式：platformio.ini

```ini
lib_deps = 
	https://github.com/fishros/Esp32McpwmMotor.git
```

两路电机例程：

```cpp
#include <Arduino.h>
#include <Esp32McpwmMotor.h>

Esp32McpwmMotor motor; // 创建一个名为motor的对象，用于控制电机

void setup()
{
    Serial.begin(115200); // 初始化串口通信，波特率为115200

    motor.attachMotor(0, 33, 25); // 将电机0连接到引脚33和引脚25
    motor.attachMotor(1, 26, 27); // 将电机1连接到引脚26和引脚27
}

void loop()
{
    motor.updateMotorSpeed(0, -70); // 设置电机0的速度为负70
    motor.updateMotorSpeed(1, 70); // 设置电机1的速度为正70
    delay(2000); // 延迟两秒

    motor.updateMotorSpeed(0, 70); // 设置电机0的速度为正70
    motor.updateMotorSpeed(1, -70); // 设置电机1的速度为负70
    delay(2000); // 延迟两秒
}
```



四路电机例程：

```cpp
#include <Arduino.h>
#include <Esp32McpwmMotor.h>

Esp32McpwmMotor motor; // 创建一个名为motor的对象，用于控制电机

void setup()
{
    Serial.begin(115200); // 初始化串口通信，波特率为115200

    motor.attachMotor(0, 33, 25); // 将电机0连接到引脚33和引脚25
    motor.attachMotor(1, 26, 27); // 将电机1连接到引脚26和引脚27
    motor.attachMotor(2, 12, 22); // 将电机2连接到引脚12和引脚22
    motor.attachMotor(3, 16, 17); // 将电机3连接到引脚16和引脚17
}

void loop()
{
    motor.updateMotorSpeed(0, -70); // 设置电机0的速度为负70（70%占空比）
    motor.updateMotorSpeed(1, 70); // 设置电机1的速度为正70
    motor.updateMotorSpeed(2, -70); // 设置电机2的速度为负70
    motor.updateMotorSpeed(3, 70); // 设置电机3的速度为正70
    delay(2000); // 延迟两秒

    motor.updateMotorSpeed(0, 70); // 设置电机0的速度为正70
    motor.updateMotorSpeed(1, -70); // 设置电机1的速度为负70
    motor.updateMotorSpeed(2, 70); // 设置电机2的速度为正70
    motor.updateMotorSpeed(3, -70); // 设置电机3的速度为负70
    delay(2000); // 延迟两秒
}
```



Autor: 小鱼(fishros@foxmail.com)