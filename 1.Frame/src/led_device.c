#include "main.h"
#include "led_device.h"

/*
*********************************************************************************************************
*	函 数 名: LEDDeviceInit
*	功能说明: 应用层LED设备初始化
*	形    参: 无
*	返 回 值: 无
*   日期          版本号        修改人
*   2023/12/12    V1.0        @尝试早睡
*********************************************************************************************************
*/
static int LEDDeviceInit(struct LEDDevice *ptLEDDevice)
{
    return KAL_LEDDeviceInit(ptLEDDevice);
}

/*
*********************************************************************************************************
*	函 数 名: LEDDeviceControl
*	功能说明: 应用层LED设备控制
*	形    参: 无
*	返 回 值: 无
*   日期          版本号        修改人
*   2023/12/12    V1.0        @尝试早睡
*********************************************************************************************************
*/
static int LEDDeviceControl(struct LEDDevice *ptLEDDevice, int iStatus)
{
    return KAL_LEDDeviceControl(ptLEDDevice,iStatus);
}

/*
*********************************************************************************************************
*	函 数 名: LEDDeviceSetColor
*	功能说明: 应用层LED设备颜色设置函数
*	形    参: 无
*	返 回 值: 无
*   日期          版本号        修改人
*   2023/12/12    V1.0        @尝试早睡
*********************************************************************************************************
*/
static int LEDDeviceSetColor(struct LEDDevice *ptLEDDevice, int iR, int iG, int iB)
{
    return KAL_LEDDeviceSetColor(ptLEDDevice, iR, iG, iB);
}

/*
*********************************************************************************************************
*	函 数 名: LEDDeviceSetBrightness
*	功能说明: 应用层LED设备亮度设置函数
*	形    参: 无
*	返 回 值: 无
*   日期          版本号        修改人
*   2023/12/12    V1.0        @尝试早睡
*********************************************************************************************************
*/
static int LEDDeviceSetBrightness(struct LEDDevice *ptLEDDevice, int iBrightness)
{
    return KAL_LEDDeviceSetBrightness(ptLEDDevice, iBrightness);
}
/*定义一个LED设备操作结构体*/
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

/*
*********************************************************************************************************
*	函 数 名: GetLEDDevice
*	功能说明: 获取LED设备函数
*	形    参: 无
*	返 回 值: 无
*   日期          版本号        修改人
*   2023/12/12    V1.0        @尝试早睡
*********************************************************************************************************
*/
PLEDDevice GetLEDDevice(int which)
{
    if (which >= LED_RED)
        return &g_tLEDDevice[which];
    else
        return NULL;
}
