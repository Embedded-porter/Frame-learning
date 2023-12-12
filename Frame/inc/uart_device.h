#ifndef UART_DEVICE_H
#define UART_DEVICE_H

#include "uart_ringbuffer.h"

#define UART3_Path "/dev/ttymxc2"
#define Uart3_Baudrate 115200

typedef struct UARTDevice
{
    char *name;
    int SerialPortFd;
    char *SerialPortPath;
    int Baudrate;
    int (*Init)(struct UARTDevice *ptUARTDevice);
    int (*Receive)(struct UARTDevice *ptUARTDevice, ptUartMessage buf, int len);
    int (*Send)(struct UARTDevice *ptUARTDevice, ptUartMessage buf, int len);
} UARTDevice, *PUARTDevice;
#endif

/*
*********************************************************************************************************
*	�� �� ��: GetUARTDevice
*	����˵��: ͨ����������ȡ�����豸�����ṹ��
*	��    ��: ��
*	�� �� ֵ: ��
*   ����          �汾��        �޸���
*   2023/12/12    V1.0        @������˯
*********************************************************************************************************
*/
PUARTDevice GetUARTDevice(char *name);