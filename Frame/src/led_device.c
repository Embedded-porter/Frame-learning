#include "main.h"
#include "led_device.h"
/**********************************************************************
 * 函数名称： LEDDeviceInit
 * 功能描述： 应用层LED设备初始化
 * 输入参数： 无
 * 输出参数： 无
 * 返 回 值： 0-成功, 其他值-失败
 * 修改日期        版本号     修改人	      修改内容
 * -----------------------------------------------
 * 2023/11/17	   V1.0	    尝试早睡 	      创建
 ***********************************************************************/ 
static int LEDDeviceInit(struct LEDDevice *ptLEDDevice)
{
    return KAL_LEDDeviceInit(ptLEDDevice);
}
/**********************************************************************
 * 函数名称： LEDDeviceControl
 * 功能描述： 应用层LED设备控制函数
 * 输入参数： 无
 * 输出参数： 无
 * 返 回 值： 0-成功, 其他值-失败
 * 修改日期        版本号     修改人	      修改内容
 * -----------------------------------------------
 * 2023/11/17	   V1.0	    尝试早睡 	      创建
 ***********************************************************************/ 
static int LEDDeviceControl(struct LEDDevice *ptLEDDevice, int iStatus)
{
    return KAL_LEDDeviceControl(ptLEDDevice,iStatus);
}
/**********************************************************************
 * 函数名称： LEDDeviceSetColor
 * 功能描述： 应用层LED设备颜色设置函数
 * 输入参数： LED设备  RGB值
 * 输出参数： 无
 * 返 回 值： 0-成功, 其他值-失败
 * 修改日期        版本号     修改人	      修改内容
 * -----------------------------------------------
 * 2023/11/17	   V1.0	    尝试早睡 	      创建
 ***********************************************************************/ 
static int LEDDeviceSetColor(struct LEDDevice *ptLEDDevice, int iR, int iG, int iB)
{
    return KAL_LEDDeviceSetColor(ptLEDDevice, iR, iG, iB);
}

/**********************************************************************
 * 函数名称： LEDDeviceSetBrightness
 * 功能描述： 应用层LED设备亮度设置函数
 * 输入参数： 无
 * 输出参数： 无
 * 返 回 值： 0-成功, 其他值-失败
 * 修改日期        版本号     修改人	      修改内容
 * -----------------------------------------------
 * 2023/11/17	   V1.0	    尝试早睡 	      创建
 ***********************************************************************/ 
static int LEDDeviceSetBrightness(struct LEDDevice *ptLEDDevice, int iBrightness)
{
    return KAL_LEDDeviceSetBrightness(ptLEDDevice, iBrightness);
}
static LEDDevice g_tLEDDevice[] = {
    {
        LED_RED,
        LED_RED_TRIGGERPATH,
        LED_RED_BRIGHTNESSPATH,
        LEDDeviceInit,
        LEDDeviceControl,
        LEDDeviceSetColor,
        LEDDeviceSetBrightness,
    },
};
/**********************************************************************
 * 函数名称： GetLEDDevice
 * 功能描述： 获取LED设备函数
 * 输入参数： 无
 * 输出参数： 无
 * 返 回 值： 0-成功, 其他值-失败
 * 修改日期        版本号     修改人	      修改内容
 * -----------------------------------------------
 * 2023/11/17	   V1.0	    尝试早睡 	      创建
 ***********************************************************************/ 
PLEDDevice GetLEDDevice(int which)
{
    if (which >= LED_RED)
        return &g_tLEDDevice[which];
    else
        return NULL;
}
