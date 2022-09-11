#include "src/LED.h"

int main(void)
{
    ledInit();
    ledOn();
}

#if 0
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
// #include "stm32f4xx_it.h"

/*
ORANGE  PD13
GREEN   PD12
BUTTON  PA0
*/

int main(void)
{
    HAL_Init();
    
    __HAL_RCC_GPIOD_CLK_ENABLE();
    
    GPIO_InitTypeDef gpio;
    gpio.Pin = GPIO_PIN_13;
    gpio.Mode = GPIO_MODE_OUTPUT_PP;
    HAL_GPIO_Init(GPIOD, &gpio);
    
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
    
}

#endif
