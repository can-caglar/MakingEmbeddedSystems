#include "button.h"
#include "nvic_hal.h"
#include "rcc_hal.h"
#include "gpio_hal.h"
#include "global.h"

static GH_Init_s _gpio = 
{
    .pin = GH_PIN_0,
    .pull = GH_PULL_NONE,
    .mode = GH_MODE_IT_RISING_FALLING,
};

static GPIOPort_e _port = GH_PORT_A;

STATIC void button_irq(void)
{
    
}

void button_init(void)
{
    rcc_gpioa_clk_enable();
    gpio_init(_port, &_gpio);
    gpio_register_interrupt_callback(_gpio.pin, button_irq);
    nvic_enable_irq(NVIC_EXTI0);
}
