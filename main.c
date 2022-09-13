#if 1
#include "src/LED.h"
#include "src/button.h"
#include "src/system_hal.h"

#include "stm32f4xx_hal.h"

int main(void)
{
    system_init();
    ledInit();
    ledOn();
    ledOff();
    ledOn();
    button_init();

    while(1)
    {
        volatile int aa = get_tick();
        volatile int a = 1;
    }
}

#endif

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
    volatile int v = 1;

    HAL_Init();

    // __HAL_RCC_SYSCFG_CLK_ENABLE ?
    __HAL_RCC_GPIOA_CLK_ENABLE();
    
    GPIO_InitTypeDef gpio = { 0 };
    gpio.Pin = GPIO_PIN_0;
    gpio.Mode = GPIO_MODE_IT_RISING;

    HAL_GPIO_Init(GPIOA, &gpio);

    //HAL_NVIC_SetPriority(EXTI0_IRQn, 10, 0);
    HAL_NVIC_EnableIRQ(EXTI0_IRQn);
    #if 0
    #endif
    
    while(1)
    {
        volatile int b = 4;
    }
}

void HAL_GPIO_EXTI_Callback(uint16_t pin)
{
    if (pin == GPIO_PIN_0)
    {
        volatile int a = 5;
    }
}

void EXTI0_IRQHandler(void)
{
    HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_0);
    //__BKPT(1);
}

#endif
