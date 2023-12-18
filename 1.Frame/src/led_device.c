#include "main.h"
#include "led_device.h"

/*
*********************************************************************************************************
*	�� �� ��: LEDDeviceInit
*	����˵��: Ӧ�ò�LED�豸��ʼ��
*	��    ��: ��
*	�� �� ֵ: ��
*   ����          �汾��        �޸���
*   2023/12/12    V1.0        @������˯
*********************************************************************************************************
*/
static int LEDDeviceInit(struct LEDDevice *ptLEDDevice)
{
    return KAL_LEDDeviceInit(ptLEDDevice);
}

/*
*********************************************************************************************************
*	�� �� ��: LEDDeviceControl
*	����˵��: Ӧ�ò�LED�豸����
*	��    ��: ��
*	�� �� ֵ: ��
*   ����          �汾��        �޸���
*   2023/12/12    V1.0        @������˯
*********************************************************************************************************
*/
static int LEDDeviceControl(struct LEDDevice *ptLEDDevice, int iStatus)
{
    return KAL_LEDDeviceControl(ptLEDDevice,iStatus);
}

/*
*********************************************************************************************************
*	�� �� ��: LEDDeviceSetColor
*	����˵��: Ӧ�ò�LED�豸��ɫ���ú���
*	��    ��: ��
*	�� �� ֵ: ��
*   ����          �汾��        �޸���
*   2023/12/12    V1.0        @������˯
*********************************************************************************************************
*/
static int LEDDeviceSetColor(struct LEDDevice *ptLEDDevice, int iR, int iG, int iB)
{
    return KAL_LEDDeviceSetColor(ptLEDDevice, iR, iG, iB);
}

/*
*********************************************************************************************************
*	�� �� ��: LEDDeviceSetBrightness
*	����˵��: Ӧ�ò�LED�豸�������ú���
*	��    ��: ��
*	�� �� ֵ: ��
*   ����          �汾��        �޸���
*   2023/12/12    V1.0        @������˯
*********************************************************************************************************
*/
static int LEDDeviceSetBrightness(struct LEDDevice *ptLEDDevice, int iBrightness)
{
    return KAL_LEDDeviceSetBrightness(ptLEDDevice, iBrightness);
}
/*����һ��LED�豸�����ṹ��*/
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
*	�� �� ��: GetLEDDevice
*	����˵��: ��ȡLED�豸����
*	��    ��: ��
*	�� �� ֵ: ��
*   ����          �汾��        �޸���
*   2023/12/12    V1.0        @������˯
*********************************************************************************************************
*/
PLEDDevice GetLEDDevice(int which)
{
    if (which >= LED_RED)
        return &g_tLEDDevice[which];
    else
        return NULL;
}
