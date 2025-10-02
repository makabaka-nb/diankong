//
// Created by ROG STRIX on 2025/10/2.
//
#include "main.h"
#include "usart.h"
extern uint8_t rx_msg[4];
extern uint8_t tx_huanchong[4];
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
    if (huart==&huart7) {
        for (uint8_t i=0;i<3;i++) tx_huanchong[i] = rx_msg[i];
        HAL_UART_Transmit_IT(&huart7,tx_huanchong,3);HAL_UART_Receive_IT(&huart7,rx_msg,3);

    }
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart) {
    if (huart==&huart7) {
        
    }
}