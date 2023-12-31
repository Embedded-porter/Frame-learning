#ifndef CAL_UARTDEVICE_H
#define CAL_UARTDEVICE_H

#include "uart_ringbuffer.h"
/*
*********************************************************************************************************
*	函 数 名: CAL_UARTDeviceInit
*	功能说明: 芯片抽象层的串口初始化函数, 芯片不一样时请修改此函数
*	形    参: ptUARTDevice - 指定串口设备
*	返 回 值: 无
*   日期          版本号        修改人
*   2023/12/12    V1.0        @尝试早睡
*********************************************************************************************************
*/
int CAL_UARTDeviceInit(struct UARTDevice *ptUARTDevice);

/*
*********************************************************************************************************
*	函 数 名: CAL_UARTDeviceReceive
*	功能说明: 芯片抽象层的串口接收函数, 芯片不一样时请修改此函数
*	形    参: ptUARTDevice - 指定串口设备   ptUartMessage -接收缓冲区  len-接收缓冲区长度
*	返 回 值: 无
*   日期          版本号        修改人
*   2023/12/12    V1.0        @尝试早睡
*********************************************************************************************************
*/
int CAL_UARTDeviceReceive(struct UARTDevice *ptUARTDevice, ptUartMessage buf, int len);

/*
*********************************************************************************************************
*	函 数 名: CAL_UARTDeviceSend
*	功能说明: 芯片抽象层的串口发送函数, 芯片不一样时请修改此函数
*	形    参: ptUARTDevice - 指定串口设备   ptUartMessage -接收缓冲区  len-接收缓冲区长度
*	返 回 值: 无
*   日期          版本号        修改人
*   2023/12/12    V1.0        @尝试早睡
*********************************************************************************************************
*/
int CAL_UARTDeviceSend(struct UARTDevice *ptUARTDevice, ptUartMessage buf, int len);


#endif 