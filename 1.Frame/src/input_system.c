#include "main.h"
#include "input_system.h"

static PInputDevice g_ptInputDevices = NULL;

/*
*********************************************************************************************************
*	函 数 名: InputDeviceRegister
*	功能说明: 注册所有的输入设备
*	形    参: 无
*	返 回 值: 无
*   日期          版本号        修改人
*   2023/12/12    V1.0        @尝试早睡
*********************************************************************************************************
*/
void InputDeviceRegister(PInputDevice ptInputDevice)
{
	ptInputDevice->pNext = g_ptInputDevices;
	g_ptInputDevices = ptInputDevice;
}

/*
*********************************************************************************************************
*	函 数 名: AddInputDevices
*	功能说明: 注册多个输入设备
*	形    参: 无
*	返 回 值: 无
*   日期          版本号        修改人
*   2023/12/12    V1.0        @尝试早睡
*********************************************************************************************************
*/
void AddInputDevices(void)
{
	AddInputDeviceKey();
}

/*
*********************************************************************************************************
*	函 数 名: InitInputDevices
*	功能说明: 初始化所有的输入设备
*	形    参: 无
*	返 回 值: 无
*   日期          版本号        修改人
*   2023/12/12    V1.0        @尝试早睡
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
