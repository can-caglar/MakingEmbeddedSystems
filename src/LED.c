#include "LED.h"
#include "gpio_hal.h"

void ledInit(void)
{
    GPIOPort_e port = GH_PORT_D;
    GH_Init_s gpio = { 0 };

    gpio_init(port, &gpio);
}
