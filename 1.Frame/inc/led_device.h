#ifndef LED_DEVICE_H
#define LED_DEVICE_H

#define LED_RED 0       
#define LED_RED_TRIGGERPATH "/sys/class/leds/sys-led/trigger"
#define LED_RED_BRIGHTNESSPATH "/sys/class/leds/sys-led/brightness"

typedef struct LEDDevice
{
    int which;
    char *TriggerPath;          //led mode
    char *BrightnessPath;       //led brightness
    int (*Init)(struct LEDDevice *ptLEDDevice);
    int (*Control)(struct LEDDevice *ptLEDDevice, int iStatus);
    int (*SetColor)(struct LEDDevice *ptLEDDevice, int iR, int iG, int iB);
    int (*SetBrightness)(struct LEDDevice *ptLEDDevice, int iBrightness);
} LEDDevice, *PLEDDevice;

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
PLEDDevice GetLEDDevice(int which);

#endif