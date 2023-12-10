#include "main.h"
#include "kal_leddevice.h"
/**********************************************************************
 * 函数名称： KAL_LEDDeviceInit
 * 功能描述： 内核抽象层的LED初始化函数, 内核不一样时请修改此函数
 * 输入参数： ptLEDDevice-哪个LED设备
 * 输出参数： 无
 * 返 回 值： 0-成功
 * 修改日期          版本号     修改人	      修改内容
 * -----------------------------------------------
 * 2023/11/16	     V1.0	 Embedded Lin	      创建
 ***********************************************************************/
int KAL_LEDDeviceInit(struct LEDDevice *ptLEDDevice)
{
    return CAL_LEDDeviceInit(ptLEDDevice);
}
/**********************************************************************
 * 函数名称： KAL_LEDDeviceControl
 * 功能描述： 内核抽象层的LED控制函数, 内核不一样时请修改此函数
 * 输入参数： ptLEDDevice-哪个LED设备
 * 输出参数： 无
 * 返 回 值： 0-成功
 * 修改日期          版本号     修改人	      修改内容
 * -----------------------------------------------
 * 2023/11/16	     V1.0	 Embedded Lin	      创建
 ***********************************************************************/
int KAL_LEDDeviceControl(struct LEDDevice *ptLEDDevice, int iStatus)
{
    return CAL_LEDDeviceControl(ptLEDDevice, iStatus);
}
/**********************************************************************
 * 函数名称： KAL_LEDDeviceInit
 * 功能描述： 内核抽象层的LED颜色设置函数, 内核不一样时请修改此函数
 * 输入参数： ptLEDDevice-哪个LED设备
 * 输出参数： 无
 * 返 回 值： 0-成功
 * 修改日期          版本号     修改人	      修改内容
 * -----------------------------------------------
 * 2023/11/16	     V1.0	 Embedded Lin	      创建
 ***********************************************************************/
int KAL_LEDDeviceSetColor(struct LEDDevice *ptLEDDevice, int iR, int iG, int iB)
{
    return CAL_LEDDeviceSetColor(ptLEDDevice, iR, iG, iB);
}
/**********************************************************************
 * 函数名称： KAL_LEDDeviceSetBrightness
 * 功能描述： 内核抽象层的LED亮度设置函数, 内核不一样时请修改此函数
 * 输入参数： ptLEDDevice-哪个LED设备
 * 输出参数： 无
 * 返 回 值： 0-成功
 * 修改日期          版本号     修改人	      修改内容
 * -----------------------------------------------
 * 2023/11/16	     V1.0	 Embedded Lin	      创建
 ***********************************************************************/
int KAL_LEDDeviceSetBrightness(struct LEDDevice *ptLEDDevice, int iBrightness)
{
    return CAL_LEDDeviceSetBrightness(ptLEDDevice, iBrightness);
}