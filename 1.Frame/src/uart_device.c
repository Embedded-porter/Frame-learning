#include "main.h"
#include "uart_device.h"

/*
*********************************************************************************************************
*	�� �� ��: UARTDeviceInit
*	����˵��: Ӧ�ò�UART�豸��ʼ������
*	��    ��: ��
*	�� �� ֵ: ��
*   ����          �汾��        �޸���
*   2023/12/12    V1.0        @������˯
*********************************************************************************************************
*/
static int UARTDeviceInit(struct UARTDevice *ptUARTDevice)
{
    return KAL_UARTDeviceInit(ptUARTDevice);
}

/*
*********************************************************************************************************
*	�� �� ��: UARTDeviceReceive
*	����˵��: Ӧ�ò�UART�豸���պ���
*	��    ��: ��
*	�� �� ֵ: ��
*   ����          �汾��        �޸���
*   2023/12/12    V1.0        @������˯
*********************************************************************************************************
*/
static int UARTDeviceReceive(struct UARTDevice *ptUARTDevice, ptUartMessage buf, int len)
{
    return KAL_UARTDeviceReceive(ptUARTDevice, buf, len);
}

/*
*********************************************************************************************************
*	�� �� ��: UARTDeviceSend
*	����˵��: Ӧ�ò�UART�豸���ͺ���
*	��    ��: ��
*	�� �� ֵ: ��
*   ����          �汾��        �޸���
*   2023/12/12    V1.0        @������˯
*********************************************************************************************************
*/
static int UARTDeviceSend(struct UARTDevice *ptUARTDevice, ptUartMessage buf, int len)
{
    return KAL_UARTDeviceSend(ptUARTDevice, buf, len);
}
/*����һ�������豸*/
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
*	�� �� ��: GetUARTDevice
*	����˵��: ͨ����������ȡ�����豸�����ṹ��
*	��    ��: ��
*	�� �� ֵ: ��
*   ����          �汾��        �޸���
*   2023/12/12    V1.0        @������˯
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