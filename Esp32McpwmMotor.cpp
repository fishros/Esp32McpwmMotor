#include "Esp32McpwmMotor.h"

/*
MOTORID PCNTID(ID/3+ID)      IOA((ID%3)*2)     IOB(ID*2+1)    TIMER
0       MCPWM_UNIT_0          0                1              0
1       MCPWM_UNIT_0          2                3
2       MCPWM_UNIT_0          4                5
3       MCPWM_UNIT_1          0                1
4       MCPWM_UNIT_1          2                3
5       MCPWM_UNIT_1          4                5
*/
void Esp32McpwmMotor::attachMotor(uint8_t id, uint8_t gpioIn1, uint8_t gpioIn2)
{
    // 根据ID计算出mcpwm_num和mcpwm_timer
    mcpwm_unit_t mcpwm_num = MCPWM_UNIT_0;
    mcpwm_io_signals_t io_signal_a = mcpwm_io_signals_t((id % 3) * 2);
    mcpwm_io_signals_t io_signal_b = mcpwm_io_signals_t((id % 3) * 2 + 1);
    if (id / 3 == 1)
    {
        mcpwm_num = MCPWM_UNIT_1;
    }
    mcpwm_timer_t mcpwm_timer = MCPWM_TIMER_0;
    if (id % 3 == 1)
    {
        mcpwm_timer = MCPWM_TIMER_1;
    }
    else if (id % 3 == 2)
    {
        mcpwm_timer = MCPWM_TIMER_2;
    }

    // Set MCPWM unit 0
    mcpwm_gpio_init(mcpwm_num, io_signal_a, gpioIn1);
    mcpwm_gpio_init(mcpwm_num, io_signal_b, gpioIn2);
    this->mMotorAttached[id] = true;
    // Initial MCPWM configuration
    mcpwm_config_t pwm_config;
    pwm_config.frequency = 5000; // frequency,
    pwm_config.cmpr_a = 0;       // duty cycle of PWMxA = 0
    pwm_config.cmpr_b = 0;       // duty cycle of PWMxb = 0
    pwm_config.counter_mode = MCPWM_UP_COUNTER;
    pwm_config.duty_mode = MCPWM_DUTY_MODE_0;
    mcpwm_init(mcpwm_num, mcpwm_timer, &pwm_config);
}

void Esp32McpwmMotor::stopMotor(int8_t motorId)
{
}

void Esp32McpwmMotor::updateMotorSpeed(int8_t id, int16_t pwmValue)
{
    mcpwm_unit_t mcpwm_num = MCPWM_UNIT_0;
    if (id / 3 == 1)
    {
        mcpwm_num = MCPWM_UNIT_1;
    }
    mcpwm_timer_t mcpwm_timer = MCPWM_TIMER_0;
    if (id % 3 == 1)
    {
        mcpwm_timer = MCPWM_TIMER_1;
    }
    else if (id % 3 == 2)
    {
        mcpwm_timer = MCPWM_TIMER_2;
    }
    
    if (pwmValue > 0)
    {
        mcpwm_set_signal_low(mcpwm_num, mcpwm_timer, MCPWM_OPR_B);                   // 将B设置成低电平
        mcpwm_set_duty(mcpwm_num, mcpwm_timer, MCPWM_OPR_A, pwmValue);               // 设置A周期值
        mcpwm_set_duty_type(mcpwm_num, mcpwm_timer, MCPWM_OPR_A, MCPWM_DUTY_MODE_0); // call this each time, if operator was previously in low/high state
    }
    else
    {
        mcpwm_set_signal_low(mcpwm_num, mcpwm_timer, MCPWM_OPR_A);                   // 将A设置成低电平
        mcpwm_set_duty(mcpwm_num, mcpwm_timer, MCPWM_OPR_B, -pwmValue);              // 设置A周期值
        mcpwm_set_duty_type(mcpwm_num, mcpwm_timer, MCPWM_OPR_B, MCPWM_DUTY_MODE_0); // call this each time, if operator was previously in low/high state
    }
}