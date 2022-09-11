#include "unity.h"
#include "LED.h"
#include "mock_gpio_hal.h"
#include "helper.h"

void setUp(void)
{

}

void tearDown(void)
{

}

void test_LedCanBeEnabled(void)
{
    GH_Init_s gpio = { 0 };
    gpio_init_Expect(GH_PORT_D, &gpio);
    ledInit();
}

/*
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"

Note:

ORANGE  PD13
GREEN   PD12
BUTTON  PA0

- [ ] Input line on PA0 
- [ ] Interrupt routed to button
- [ ] Input line is debounced
- [ ] Output on PD13 when button pressed

*/