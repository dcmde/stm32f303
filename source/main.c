#include "stm32f30x_gpio.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"

int main(void) {

    RCC->AHBENR |= RCC_AHBPeriph_GPIOC;

    GPIO_InitTypeDef gpioInitTypeDef;
    gpioInitTypeDef.GPIO_Mode = GPIO_Mode_OUT;
    gpioInitTypeDef.GPIO_Speed = GPIO_Speed_2MHz;
    gpioInitTypeDef.GPIO_OType = GPIO_OType_PP;
    gpioInitTypeDef.GPIO_Pin = GPIO_Pin_13;

    GPIO_Init(GPIOC, &gpioInitTypeDef);

    uint32_t i;
    /* Infinite loop */
    while (1) {
        for (i = 0; i < 0xFFFFFF; ++i) {

        }
        GPIOC->ODR ^= GPIO_Pin_13;
    }
}


#pragma clang diagnostic pop