#include "Esp32McpwmMotor.h"

void Esp32McpwmMotor::attachMotor(uint8_t gpioIn1, uint8_t gpioIn2)
{
    attachMotors(gpioIn1, gpioIn2, 0, 0);
}
void Esp32McpwmMotor::attachMotors(uint8_t gpioIn1, uint8_t gpioIn2, uint8_t gpioIn3, uint8_t gpioIn4)
{

    // Attach motor 0 input pins.

    // Set MCPWM unit 0

    mcpwm_gpio_init(MCPWM_UNIT_0, MCPWM0A, gpioIn1);
    mcpwm_gpio_init(MCPWM_UNIT_0, MCPWM0B, gpioIn2);

    // Indicate the motor 0 is attached.

    this->mMotorAttached[0] = true;

    // Attach motor 1 input pins.

    if (!(gpioIn3 == 0 && gpioIn4 == 0))
    {

        // debug("init MCPWM Motor 1");

        // Set MCPWM unit 1

        mcpwm_gpio_init(MCPWM_UNIT_1, MCPWM1A, gpioIn3);
        mcpwm_gpio_init(MCPWM_UNIT_1, MCPWM1B, gpioIn4);

        // Indicate the motor 1 is attached.

        this->mMotorAttached[1] = true;
    }

    // Initial MCPWM configuration

    // debug("Configuring Initial Parameters of MCPWM...");

    mcpwm_config_t pwm_config;
    pwm_config.frequency = 5000; // frequency,
    pwm_config.cmpr_a = 0;       // duty cycle of PWMxA = 0
    pwm_config.cmpr_b = 0;       // duty cycle of PWMxb = 0
    pwm_config.counter_mode = MCPWM_UP_COUNTER;
    pwm_config.duty_mode = MCPWM_DUTY_MODE_0;

    mcpwm_init(MCPWM_UNIT_0, MCPWM_TIMER_0, &pwm_config); // Configure PWM0A & PWM0B with above settings

    mcpwm_init(MCPWM_UNIT_1, MCPWM_TIMER_1, &pwm_config); // Configure PWM1A & PWM1B with above settings

    // debug("MCPWM initialized");
}
void Esp32McpwmMotor::stopMotor(int8_t motorId)
{
}
void Esp32McpwmMotor::updateMotorSpeed(int8_t id, int16_t pwmValue)
{

    if (id == 0)
    {
        if (pwmValue > 0)
        {
            mcpwm_set_signal_low(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_B);                   // 将B设置成低电平
            mcpwm_set_duty(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_A, pwmValue);               // 设置A周期值
            mcpwm_set_duty_type(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_A, MCPWM_DUTY_MODE_0); // call this each time, if operator was previously in low/high state
        }
        else
        {
            mcpwm_set_signal_low(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_A);                   // 将A设置成低电平
            mcpwm_set_duty(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_B, -pwmValue);               // 设置A周期值
            mcpwm_set_duty_type(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_B, MCPWM_DUTY_MODE_0); // call this each time, if operator was previously in low/high state
        }
    }
    else if (id == 1)
    {
        if (pwmValue > 0)
        {

            mcpwm_set_signal_low(MCPWM_UNIT_1, MCPWM_TIMER_1, MCPWM_OPR_B);
            mcpwm_set_duty(MCPWM_UNIT_1, MCPWM_TIMER_1, MCPWM_OPR_A, pwmValue);
            mcpwm_set_duty_type(MCPWM_UNIT_1, MCPWM_TIMER_1, MCPWM_OPR_A, MCPWM_DUTY_MODE_0); // call this each time, if operator was previously in low/high state
        }
        else
        {
            mcpwm_set_signal_low(MCPWM_UNIT_1, MCPWM_TIMER_1, MCPWM_OPR_A);
            mcpwm_set_duty(MCPWM_UNIT_1, MCPWM_TIMER_1, MCPWM_OPR_B, -pwmValue);
            mcpwm_set_duty_type(MCPWM_UNIT_1, MCPWM_TIMER_1, MCPWM_OPR_B, MCPWM_DUTY_MODE_0); // call this each time, if operator was previously in low/high state
        }
    }
}