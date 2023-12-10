#ifndef CAL_UARTDEVICE_H
#define CAL_UARTDEVICE_H

#include "uart_ringbuffer.h"

extern int CAL_UARTDeviceInit(struct UARTDevice *ptUARTDevice);

extern int CAL_UARTDeviceReceive(struct UARTDevice *ptUARTDevice, ptUartMessage buf, int len);

extern int CAL_UARTDeviceSend(struct UARTDevice *ptUARTDevice, ptUartMessage buf, int len);


#endif 