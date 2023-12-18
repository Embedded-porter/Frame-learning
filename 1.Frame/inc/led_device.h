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
*	�� �� ��: GetLEDDevice
*	����˵��: ��ȡLED�豸����
*	��    ��: ��
*	�� �� ֵ: ��
*   ����          �汾��        �޸���
*   2023/12/12    V1.0        @������˯
*********************************************************************************************************
*/
PLEDDevice GetLEDDevice(int which);

#endif