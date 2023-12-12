#include "main.h"
#include "cal_leddevice.h"

static int TriggerFd, BrightnessFd;

/*
*********************************************************************************************************
*	函 数 名: CAL_KEYDeviceInit
*	功能说明: 芯片抽象层的LED初始化函数, 芯片不一样时请修改此函数
*	形    参: 无
*	返 回 值: 无
*   日期          版本号        修改人
*   2023/12/12    V1.0        @尝试早睡
*********************************************************************************************************
*/
int CAL_LEDDeviceInit(struct LEDDevice *ptLEDDevice)
{
    TriggerFd = open(ptLEDDevice->TriggerPath, O_RDWR);
    if (TriggerFd < 0)
    {
        perror("open TriggerFd");
        return -1;
    }
    BrightnessFd = open(ptLEDDevice->BrightnessPath, O_RDWR);
    if (BrightnessFd < 0)
    {
        perror("open BrightnessFd");
        return -1;
    }
    return 0;
}

/*
*********************************************************************************************************
*	函 数 名: CAL_LEDDeviceControl
*	功能说明: 芯片抽象层的LED控制函数, 芯片不一样时请修改此函数
*	形    参: ptLEDDevice - 指定哪个LED设备 iStatus - LED设备状态
*	返 回 值: 无
*   日期          版本号        修改人
*   2023/12/12    V1.0        @尝试早睡
*********************************************************************************************************
*/
int CAL_LEDDeviceControl(struct LEDDevice *ptLEDDevice, int iStatus)
{
    char *Status;
    int ret = 0;
    if (!ptLEDDevice)
    {
        return -1;
    }
    Status = iStatus ? "1" : "0";
    switch (ptLEDDevice->which)
    {
    case LED_RED:
        ret = write(TriggerFd, "none", 4);
        if (ret < 0)
        {
            perror("write Trigger");
        }
        ret = write(BrightnessFd, Status, 1);
        if (ret < 0)
        {
            perror("write Brightness");
        }
        break;
    default:
        break;
    }
    return 0;
}

/*
*********************************************************************************************************
*	函 数 名: CAL_LEDDeviceSetColor
*	功能说明: 芯片抽象层的LED颜色设置函数, 芯片不一样时请修改此函数
*	形    参: ptLEDDevice - 指定哪个LED设备  iR - 红色值  iG - 绿色值  iB - 蓝色值
*	返 回 值: 无
*   日期          版本号        修改人
*   2023/12/12    V1.0        @尝试早睡
*********************************************************************************************************
*/
int CAL_LEDDeviceSetColor(struct LEDDevice *ptLEDDevice, int iR, int iG, int iB)
{
    return 0;
}

/*
*********************************************************************************************************
*	函 数 名: CAL_LEDDeviceSetBrightness
*	功能说明: 芯片抽象层的LED亮度设置函数, 芯片不一样时请修改此函数
*	形    参: ptLEDDevice - 指定哪个LED设备  iBrightness - 亮度
*	返 回 值: 无
*   日期          版本号        修改人
*   2023/12/12    V1.0        @尝试早睡
*********************************************************************************************************
*/
int CAL_LEDDeviceSetBrightness(struct LEDDevice *ptLEDDevice, int iBrightness)
{
    return 0;
}