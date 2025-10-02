//
// Created by ROG STRIX on 2025/10/2.
//
#include <math.h>

#include"main.h"
#include"gpio.h"
#include"tim.h"

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
    if (GPIO_Pin==GPIO_PIN_2) {
        uint32_t arr_value=__HAL_TIM_GetAutoreload(&htim1)+1;
        uint32_t brightness=(__HAL_TIM_GetCompare(&htim1,TIM_CHANNEL_2)+100)%arr_value;
        __HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_2,brightness);
    }

}
uint32_t count=0;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
    if (htim==&htim1) {
        count++;
        uint32_t arr_value=__HAL_TIM_GET_AUTORELOAD(&htim1)+1;
        uint32_t brightness=arr_value*sinf(4*HAL_GetTick()/1000.f)-1;
        __HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_2,brightness);
    }
}