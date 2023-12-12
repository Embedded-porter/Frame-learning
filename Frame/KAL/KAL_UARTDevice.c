#include "main.h"
#include "kal_uartdevice.h"
/*
*********************************************************************************************************
*	�� �� ��: KAL_UARTDeviceInit
*	����˵��: �ں˳����Ĵ��ڳ�ʼ������, �ں˲�һ��ʱ���޸Ĵ˺���
*	��    ��:  ptUARTDevice-ָ�������豸 
*	�� �� ֵ: ��
*   ����          �汾��        �޸���
*   2023/12/12    V1.0        @������˯
*********************************************************************************************************
*/
int KAL_UARTDeviceInit(struct UARTDevice *ptUARTDevice)
{
    return CAL_UARTDeviceInit(ptUARTDevice);
}

/*
*********************************************************************************************************
*	�� �� ��: KAL_UARTDeviceReceive
*	����˵��: �ں˳����Ĵ��ڽ��պ���, �ں˲�һ��ʱ���޸Ĵ˺���
*	��    ��:  ptUARTDevice-ָ�������豸   ptUartMessage -���ջ�����  len-���ջ���������
*	�� �� ֵ: ��
*   ����          �汾��        �޸���
*   2023/12/12    V1.0        @������˯
*********************************************************************************************************
*/
int KAL_UARTDeviceReceive(struct UARTDevice *ptUARTDevice, ptUartMessage buf, int len)
{
    return CAL_UARTDeviceReceive(ptUARTDevice, buf, len);
}

/*
*********************************************************************************************************
*	�� �� ��: KAL_UARTDeviceSend
*	����˵��: �ں˳����Ĵ��ڷ��ͺ���, �ں˲�һ��ʱ���޸Ĵ˺���
*	��    ��:  ptUARTDevice-ָ�������豸   ptUartMessage -���ͻ�����  len-���ͻ���������
*	�� �� ֵ: ��
*   ����          �汾��        �޸���
*   2023/12/12    V1.0        @������˯
*********************************************************************************************************
*/
int KAL_UARTDeviceSend(struct UARTDevice *ptUARTDevice, ptUartMessage buf, int len)
{
    return CAL_UARTDeviceSend(ptUARTDevice, buf, len);
}