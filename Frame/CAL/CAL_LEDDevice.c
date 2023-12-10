#include "main.h"
#include "cal_leddevice.h"

int TriggerFd, BrightnessFd;

/**********************************************************************
 * 函数名称： KAL_LEDDeviceInit
 * 功能描述： 芯片抽象层的LED初始化函数, 芯片不一样时请修改此函数
 * 输入参数： ptLEDDevice-哪个LED设备
 * 输出参数： 无
 * 返 回 值： 0-成功
 * 修改日期          版本号     修改人	      修改内容
 * -----------------------------------------------
 * 2023/11/16	     V1.0	 尝试早睡	      创建
 ***********************************************************************/
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
/**********************************************************************
 * 函数名称： CAL_LEDDeviceControl
 * 功能描述： 芯片抽象层的LED控制函数, 芯片不一样时请修改此函数
 * 输入参数： ptLEDDevice-哪个LED设备
 * 输出参数： 无
 * 返 回 值： 0-成功
 * 修改日期          版本号     修改人	      修改内容
 * -----------------------------------------------
 * 2023/11/16	     V1.0	 尝试早睡	      创建
 ***********************************************************************/
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
/**********************************************************************
 * 函数名称： CAL_LEDDeviceSetColor
 * 功能描述： 芯片抽象层的LED颜色设置函数, 芯片不一样时请修改此函数
 * 输入参数： ptLEDDevice-哪个LED设备
 * 输出参数： 无
 * 返 回 值： 0-成功
 * 修改日期          版本号     修改人	      修改内容
 * -----------------------------------------------
 * 2023/11/16	     V1.0	 尝试早睡	      创建
 ***********************************************************************/
int CAL_LEDDeviceSetColor(struct LEDDevice *ptLEDDevice, int iR, int iG, int iB)
{
    return 0;
}
/**********************************************************************
 * 函数名称： CAL_LEDDeviceSetBrightness
 * 功能描述： 芯片抽象层的LED亮度设置函数, 芯片不一样时请修改此函数
 * 输入参数： ptLEDDevice-哪个LED设备
 * 输出参数： 无
 * 返 回 值： 0-成功
 * 修改日期          版本号     修改人	      修改内容
 * -----------------------------------------------
 * 2023/11/16	     V1.0	 尝试早睡	      创建
 ***********************************************************************/
int CAL_LEDDeviceSetBrightness(struct LEDDevice *ptLEDDevice, int iBrightness)
{
    return 0;
}