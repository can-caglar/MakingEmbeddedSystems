#include "button.h"
#include "nvic_hal.h"
#include "rcc_hal.h"
#include "gpio_hal.h"
#include "system_hal.h"
#include "global.h"

static GH_Init_s _gpio = 
{
    .pin = GH_PIN_0,
    .pull = GH_PULL_NONE,
    .mode = GH_MODE_IT_RISING_FALLING,
};

static GPIOPort_e _port = GH_PORT_A;
static const uint32_t debounceTime = 50; // ms
static uint32_t lastIrq = 0;
static int buttonPressed = 0;

STATIC void button_irq(void)
{
    uint32_t t_now = get_tick();
    if (t_now - lastIrq >= debounceTime)
    {
        buttonPressed = gpio_read(_port, _gpio.pin);
    }
    lastIrq = t_now;
}

void button_init(void)
{
    rcc_gpioa_clk_enable();
    gpio_init(_port, &_gpio);
    gpio_register_interrupt_callback(_gpio.pin, button_irq);
    nvic_enable_irq(NVIC_EXTI0);
}

int button_pressed(void)
{
    return buttonPressed;
}
