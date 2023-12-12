#include "main.h"
#include "input_system.h"

static PInputDevice g_ptInputDevices = NULL;

/*
*********************************************************************************************************
*	�� �� ��: InputDeviceRegister
*	����˵��: ע�����е������豸
*	��    ��: ��
*	�� �� ֵ: ��
*   ����          �汾��        �޸���
*   2023/12/12    V1.0        @������˯
*********************************************************************************************************
*/
void InputDeviceRegister(PInputDevice ptInputDevice)
{
	PInputDevice ptTmp;
	if (NULL != g_ptInputDevices)
	{
		g_ptInputDevices = ptInputDevice;
		ptInputDevice->pNext = NULL;
	}
	else
	{
		ptTmp = g_ptInputDevices;
		while (ptTmp->pNext)
		{
			ptTmp = ptTmp->pNext;
		}
	}
	ptTmp->pNext = ptInputDevice;
	ptInputDevice->pNext = NULL;
}

/*
*********************************************************************************************************
*	�� �� ��: AddInputDevices
*	����˵��: ע���������豸
*	��    ��: ��
*	�� �� ֵ: ��
*   ����          �汾��        �޸���
*   2023/12/12    V1.0        @������˯
*********************************************************************************************************
*/
void AddInputDevices(void)
{
	AddInputDeviceKey();
}

/*
*********************************************************************************************************
*	�� �� ��: InitInputDevices
*	����˵��: ��ʼ�����е������豸
*	��    ��: ��
*	�� �� ֵ: ��
*   ����          �汾��        �޸���
*   2023/12/12    V1.0        @������˯
*********************************************************************************************************
*/
void InitInputDevices(void)
{
	PInputDevice pDev = g_ptInputDevices;

	while (pDev)
	{
		pDev->DeviceInit();
		pDev = pDev->pNext;
	}
}
