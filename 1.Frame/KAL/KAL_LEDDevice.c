#include "main.h"
#include "kal_leddevice.h"

/*
*********************************************************************************************************
*	函 数 名: KAL_LEDDeviceInit
*	功能说明: 内核抽象层的LED初始化函数, 内核不一样时请修改此函数
*	形    参:  ptLEDDevice-哪个LED设备
*	返 回 值: 无
*   日期          版本号        修改人
*   2023/12/12    V1.0        @尝试早睡
*********************************************************************************************************
*/
int KAL_LEDDeviceInit(struct LEDDevice *ptLEDDevice)
{
    return CAL_LEDDeviceInit(ptLEDDevice);
}

/*
*********************************************************************************************************
*	函 数 名: KAL_LEDDeviceControl
*	功能说明: 内核抽象层的LED控制函数, 内核不一样时请修改此函数
*	形    参:  ptLEDDevice-哪个LED设备  iStatus-LED设备状态
*	返 回 值: 无
*   日期          版本号        修改人
*   2023/12/12    V1.0        @尝试早睡
*********************************************************************************************************
*/
int KAL_LEDDeviceControl(struct LEDDevice *ptLEDDevice, int iStatus)
{
    return CAL_LEDDeviceControl(ptLEDDevice, iStatus);
}

/*
*********************************************************************************************************
*	函 数 名: KAL_LEDDeviceSetColor
*	功能说明: 内核抽象层的LED颜色设置函数, 内核不一样时请修改此函数
*	形    参:  ptLEDDevice-哪个LED设备  iR-红色值  iG-绿色值  iB-蓝色值
*	返 回 值: 无
*   日期          版本号        修改人
*   2023/12/12    V1.0        @尝试早睡
*********************************************************************************************************
*/
int KAL_LEDDeviceSetColor(struct LEDDevice *ptLEDDevice, int iR, int iG, int iB)
{
    return CAL_LEDDeviceSetColor(ptLEDDevice, iR, iG, iB);
}

/*
*********************************************************************************************************
*	函 数 名: KAL_LEDDeviceSetBrightness
*	功能说明: 内核抽象层的LED亮度设置函数, 内核不一样时请修改此函数
*	形    参:  ptLEDDevice-哪个LED设备  iBrightness-亮度
*	返 回 值: 无
*   日期          版本号        修改人
*   2023/12/12    V1.0        @尝试早睡
*********************************************************************************************************
*/
int KAL_LEDDeviceSetBrightness(struct LEDDevice *ptLEDDevice, int iBrightness)
{
    return CAL_LEDDeviceSetBrightness(ptLEDDevice, iBrightness);
}