#include "main.h"
#include "kal_uartdevice.h"
/*
*********************************************************************************************************
*	函 数 名: KAL_UARTDeviceInit
*	功能说明: 内核抽象层的串口初始化函数, 内核不一样时请修改此函数
*	形    参:  ptUARTDevice-指定串口设备 
*	返 回 值: 无
*   日期          版本号        修改人
*   2023/12/12    V1.0        @尝试早睡
*********************************************************************************************************
*/
int KAL_UARTDeviceInit(struct UARTDevice *ptUARTDevice)
{
    return CAL_UARTDeviceInit(ptUARTDevice);
}

/*
*********************************************************************************************************
*	函 数 名: KAL_UARTDeviceReceive
*	功能说明: 内核抽象层的串口接收函数, 内核不一样时请修改此函数
*	形    参:  ptUARTDevice-指定串口设备   ptUartMessage -接收缓冲区  len-接收缓冲区长度
*	返 回 值: 无
*   日期          版本号        修改人
*   2023/12/12    V1.0        @尝试早睡
*********************************************************************************************************
*/
int KAL_UARTDeviceReceive(struct UARTDevice *ptUARTDevice, ptUartMessage buf, int len)
{
    return CAL_UARTDeviceReceive(ptUARTDevice, buf, len);
}

/*
*********************************************************************************************************
*	函 数 名: KAL_UARTDeviceSend
*	功能说明: 内核抽象层的串口发送函数, 内核不一样时请修改此函数
*	形    参:  ptUARTDevice-指定串口设备   ptUartMessage -发送缓冲区  len-发送缓冲区长度
*	返 回 值: 无
*   日期          版本号        修改人
*   2023/12/12    V1.0        @尝试早睡
*********************************************************************************************************
*/
int KAL_UARTDeviceSend(struct UARTDevice *ptUARTDevice, ptUartMessage buf, int len)
{
    return CAL_UARTDeviceSend(ptUARTDevice, buf, len);
}