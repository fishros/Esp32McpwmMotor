#ifndef __ESP32MCPWMMOTOR_H__
#define __ESP32MCPWMMOTOR_H__

#include "Arduino.h"
#include <stdio.h>

#include "esp_system.h"
#include "esp_attr.h"

#include "driver/mcpwm.h"
#include "soc/mcpwm_reg.h"
#include "soc/mcpwm_struct.h"

class Esp32McpwmMotor
{
private:
    /* 电机速度，单位mm */
    int16_t speeds[2]{0, 0};
    bool mMotorAttached[2]{false, false};

public:
    Esp32McpwmMotor(/* args */) = default;
    ~Esp32McpwmMotor() = default;
    void attachMotor(uint8_t gpioIn1, uint8_t gpioIn2);
    void attachMotors(uint8_t gpioIn1, uint8_t gpioIn2, uint8_t gpioIn3, uint8_t gpioIn4);
    void stopMotor(int8_t motorId = -1);
    void updateMotorSpeed(int8_t id, int16_t pwmValue);
};

#endif // __ESP32MCPWMMOTOR_H__