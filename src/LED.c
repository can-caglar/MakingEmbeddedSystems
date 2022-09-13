#include "LED.h"
#include "gpio_hal.h"
#include "rcc_hal.h"

/*
ORANGE  PD13
GREEN   PD12
*/

void ledInit(void)
{
    GPIOPort_e port = GH_PORT_D;
    GH_Init_s gpio;

    gpio.mode = GH_MODE_OUTPUT_PP;
    gpio.pin = GH_PIN_13;
    gpio.pull = GH_PULL_NONE;

    rcc_gpiod_clk_enable();
    gpio_init(port, &gpio);
}

void ledOn(void)
{
    gpio_write(GH_PORT_D, GH_PIN_13, GH_STATE_SET);
}

void ledOff(void)
{
    gpio_write(GH_PORT_D, GH_PIN_13, GH_STATE_RESET);
}
