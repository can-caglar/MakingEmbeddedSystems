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

void test_LedInitWillInitialiseCorrectPort(void)
{
    GPIOPort_e port = GH_PORT_D;
    GH_Init_s gpio;
    gpio.mode = GH_MODE_OUTPUT_PP;
    gpio.pull = GH_PULL_NONE;
    gpio.pin = GH_PIN_13;

    gpio_init_Expect(GH_PORT_D, &gpio);

    ledInit();
}

void test_LedOnTest(void)
{
    gpio_write_Expect(GH_PORT_D, GH_PIN_13, GH_STATE_SET);
    ledOn();
}

/*
Note:

ORANGE  PD13
GREEN   PD12
BUTTON  PA0

- [ ] Input line on PA0 
- [ ] Interrupt routed to button
- [ ] Input line is debounced
- [ ] Output on PD13 when button pressed

*/