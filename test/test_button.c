#include "unity.h"
#include "button.h"
#include "mock_gpio_hal.h"
#include "mock_rcc_hal.h"
#include "mock_nvic_hal.h"
#include "helper.h"

extern void button_irq(void);

void test_buttonInit(void)
{
    GH_Init_s gpio = { 0 };
    gpio.mode = GH_MODE_IT_RISING_FALLING;
    gpio.pin = GH_PIN_0;
    gpio.pull = GH_PULL_NONE;

    rcc_gpioa_clk_enable_Expect();
    gpio_init_Expect(GH_PORT_A, &gpio);
    gpio_register_interrupt_callback_Expect(GH_PIN_0, button_irq); // TODO, continue with this callback
    nvic_enable_irq_Expect(NVIC_EXTI0);

    button_init();
}

/*

- [ ] Learn about input HAL, & how to configure interrupts
- [ ] Learn about HAL for timer / systick. make adapter for it.
*/