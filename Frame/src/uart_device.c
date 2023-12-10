#include "main.h"
#include "uart_device.h"

static int UARTDeviceInit(struct UARTDevice *ptUARTDevice)
{
    return KAL_UARTDeviceInit(ptUARTDevice);
}
static int UARTDeviceReceive(struct UARTDevice *ptUARTDevice, ptUartMessage buf, int len)
{
    return KAL_UARTDeviceReceive(ptUARTDevice, buf, len);
}
static int UARTDeviceSend(struct UARTDevice *ptUARTDevice, ptUartMessage buf, int len)
{
    return KAL_UARTDeviceSend(ptUARTDevice, buf, len);
}
static UARTDevice g_tUARTDevice[] = {
    {"uart3",
     -1,
     UART3_Path,
     Uart3_Baudrate,
     UARTDeviceInit,
     UARTDeviceReceive,
     UARTDeviceSend}};

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