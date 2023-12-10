#ifndef KAL_UARTDEVICE_H
#define KAL_UARTDEVICE_H

#include "uart_ringbuffer.h"

extern int KAL_UARTDeviceInit(struct UARTDevice *ptUARTDevice);

extern int KAL_UARTDeviceReceive(struct UARTDevice *ptUARTDevice, ptUartMessage buf, int len);

extern int KAL_UARTDeviceSend(struct UARTDevice *ptUARTDevice, ptUartMessage buf, int len);

#endif