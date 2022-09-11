#include "gpio_hal.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#include <stdint.h>

/* Translate from adapter to ST HAL */

GPIO_TypeDef* _ports[GH_PORT_COUNT] = 
{
    [GH_PORT_A] = GPIOA,
    [GH_PORT_B] = GPIOB,
    [GH_PORT_C] = GPIOC,
    [GH_PORT_D] = GPIOD,
    [GH_PORT_E] = GPIOE,
    [GH_PORT_F] = GPIOF,
};

uint32_t _pins[GH_PIN_COUNT] = 
{
    [GH_PIN_0] = GPIO_PIN_0,
    [GH_PIN_1] = GPIO_PIN_1,
    [GH_PIN_2] = GPIO_PIN_2,
    [GH_PIN_3] = GPIO_PIN_3,
    [GH_PIN_4] = GPIO_PIN_4,
    [GH_PIN_5] = GPIO_PIN_5,
    [GH_PIN_6] = GPIO_PIN_6,
    [GH_PIN_7] = GPIO_PIN_7,
    [GH_PIN_8] = GPIO_PIN_8,
    [GH_PIN_9] = GPIO_PIN_9,
    [GH_PIN_10] = GPIO_PIN_10,
    [GH_PIN_11] = GPIO_PIN_11,
    [GH_PIN_12] = GPIO_PIN_12,
    [GH_PIN_13] = GPIO_PIN_13,
    [GH_PIN_14] = GPIO_PIN_14,
    [GH_PIN_15] = GPIO_PIN_15,
};

uint8_t _pull[GH_PULL_COUNT] = 
{
    [GH_PULL_NONE] = GPIO_NOPULL,
    [GH_PULL_UP] = GPIO_PULLUP,
    [GH_PULL_DOWN] = GPIO_PULLDOWN,
};

uint8_t _modes[GH_MODE_COUNT] = 
{
    [GH_MODE_INPUT] = GPIO_MODE_INPUT,
    [GH_MODE_OUTPUT_PP] = GPIO_MODE_OUTPUT_PP,
    [GH_MODE_OUTPUT_OD] = GPIO_MODE_OUTPUT_OD,
};

GPIO_PinState _states[GH_STATE_COUNT] = 
{
    [GH_STATE_RESET] = GPIO_PIN_RESET,
    [GH_STATE_SET] = GPIO_PIN_SET
};

void gpio_init(GPIOPort_e port, GH_Init_s* gpio)
{
    GPIO_InitTypeDef st_gpio;
    GPIO_TypeDef* st_port = _ports[port];

    st_gpio.Pin = _pins[gpio->pin];
    st_gpio.Mode = _modes[gpio->mode];
    st_gpio.Pull = _pull[gpio->pull];

    HAL_GPIO_Init(st_port, &st_gpio);
}

void gpio_write(GPIOPort_e port, GPIOPin_e pin, GPIOState_e state)
{
    GPIO_TypeDef* st_port = _ports[port];
    uint32_t st_pin = _pins[pin];
    GPIO_PinState st_state = _states[state];

    HAL_GPIO_WritePin(st_port, st_pin, st_state);
}
