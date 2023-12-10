#include "main.h"
#include "input_system.h"

static PInputDevice g_ptInputDevices;

/**********************************************************************
 * 函数名称： InputDeviceRegister
 * 功能描述： 注册一个输入设备
 * 输入参数： ptInputDevice-输入设备
 * 输出参数： 无
 * 返 回 值： 无
 * 修改日期        版本号     修改人	      修改内容
 * -----------------------------------------------
 * 2023/11/27	   V1.0	    尝试早睡	      创建
 ***********************************************************************/
void InputDeviceRegister(PInputDevice ptInputDevice)
{
	ptInputDevice->pNext = g_ptInputDevices;
	g_ptInputDevices = ptInputDevice;
}

/**********************************************************************
 * 函数名称： AddInputDevices
 * 功能描述： 注册多个输入设备
 * 输入参数： 无
 * 输出参数： 无
 * 返 回 值： 无
 * 修改日期        版本号     修改人	      修改内容
 * -----------------------------------------------
 * 2023/11/27	   V1.0	    尝试早睡	      创建
 ***********************************************************************/
void AddInputDevices(void)
{
	AddInputDeviceKey();
}

/**********************************************************************
 * 函数名称： InitInputDevices
 * 功能描述： 初始化所有的输入设备
 * 输入参数： 无
 * 输出参数： 无
 * 返 回 值： 无
 * 修改日期        版本号     修改人	      修改内容
 * -----------------------------------------------
 * 2023/11/27	   V1.0	    尝试早睡	      创建
 ***********************************************************************/
void InitInputDevices(void)
{
	PInputDevice pDev = g_ptInputDevices;

	while (pDev)
	{
		pDev->DeviceInit();
		pDev = pDev->pNext;
	}
}
