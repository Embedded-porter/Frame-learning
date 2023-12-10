#include "main.h"
#include "kal_uartdevice.h"

int KAL_UARTDeviceInit(struct UARTDevice *ptUARTDevice)
{
    return CAL_UARTDeviceInit(ptUARTDevice);
}
int KAL_UARTDeviceReceive(struct UARTDevice *ptUARTDevice, ptUartMessage buf, int len)
{
    return CAL_UARTDeviceReceive(ptUARTDevice, buf, len);
}
int KAL_UARTDeviceSend(struct UARTDevice *ptUARTDevice, ptUartMessage buf, int len)
{
    return CAL_UARTDeviceSend(ptUARTDevice, buf, len);
}