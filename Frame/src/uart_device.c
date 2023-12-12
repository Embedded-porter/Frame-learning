#include "main.h"
#include "uart_device.h"

/*
*********************************************************************************************************
*	函 数 名: UARTDeviceInit
*	功能说明: 应用层UART设备初始化函数
*	形    参: 无
*	返 回 值: 无
*   日期          版本号        修改人
*   2023/12/12    V1.0        @尝试早睡
*********************************************************************************************************
*/
static int UARTDeviceInit(struct UARTDevice *ptUARTDevice)
{
    return KAL_UARTDeviceInit(ptUARTDevice);
}

/*
*********************************************************************************************************
*	函 数 名: UARTDeviceReceive
*	功能说明: 应用层UART设备接收函数
*	形    参: 无
*	返 回 值: 无
*   日期          版本号        修改人
*   2023/12/12    V1.0        @尝试早睡
*********************************************************************************************************
*/
static int UARTDeviceReceive(struct UARTDevice *ptUARTDevice, ptUartMessage buf, int len)
{
    return KAL_UARTDeviceReceive(ptUARTDevice, buf, len);
}

/*
*********************************************************************************************************
*	函 数 名: UARTDeviceSend
*	功能说明: 应用层UART设备发送函数
*	形    参: 无
*	返 回 值: 无
*   日期          版本号        修改人
*   2023/12/12    V1.0        @尝试早睡
*********************************************************************************************************
*/
static int UARTDeviceSend(struct UARTDevice *ptUARTDevice, ptUartMessage buf, int len)
{
    return KAL_UARTDeviceSend(ptUARTDevice, buf, len);
}
/*定义一个串口设备*/
static UARTDevice g_tUARTDevice[] = {
    {"uart3",
     -1,
     UART3_Path,
     Uart3_Baudrate,
     UARTDeviceInit,
     UARTDeviceReceive,
     UARTDeviceSend}};

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
PUARTDevice GetUARTDevice(char *name)
{
    int i = 0;
    for (i = 0; i < sizeof(g_tUARTDevice) / sizeof(g_tUARTDevice[0]); i++)
    {
        if (strcmp(g_tUARTDevice[i].name, name) == 0)
        {
            return &g_tUARTDevice[i];
        }
    }
    return NULL;
}