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
*	函 数 名: GetUARTDevice
*	功能说明: 通过串口名获取串口设备操作结构体
*	形    参: 无
*	返 回 值: 无
*   日期          版本号        修改人
*   2023/12/12    V1.0        @尝试早睡
*********************************************************************************************************
*/
PUARTDevice GetUARTDevice(char *name);