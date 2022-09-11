#include "unity.h"
#include "LED.h"
#include "mock_gpio_hal.h"
#include "mock_rcc_hal.h"
#include "helper.h"

#if 0
void setUp(void)
{

}

void tearDown(void)
{

}
#endif

void test_LedInitWillInitialiseCorrectPort(void)
{
    GPIOPort_e port = GH_PORT_D;
    GH_Init_s gpio;
    gpio.mode = GH_MODE_OUTPUT_PP;
    gpio.pull = GH_PULL_NONE;
    gpio.pin = GH_PIN_13;

    rcc_gpiod_clk_enable_Expect();
    gpio_init_Expect(GH_PORT_D, &gpio);

    ledInit();
}

void test_LedOnTest(void)
{
    gpio_write_Expect(GH_PORT_D, GH_PIN_13, GH_STATE_SET);
    ledOn();
}

void test_LedOffTest(void)
{
    gpio_write_Expect(GH_PORT_D, GH_PIN_13, GH_STATE_RESET);
    ledOff();
}

/*
- [x] Led can be turned on
- [x] Led can be turned off
*/