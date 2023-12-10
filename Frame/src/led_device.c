#include "main.h"
#include "led_device.h"
/**********************************************************************
 * �������ƣ� LEDDeviceInit
 * ���������� Ӧ�ò�LED�豸��ʼ��
 * ��������� ��
 * ��������� ��
 * �� �� ֵ�� 0-�ɹ�, ����ֵ-ʧ��
 * �޸�����        �汾��     �޸���	      �޸�����
 * -----------------------------------------------
 * 2023/11/17	   V1.0	    ������˯ 	      ����
 ***********************************************************************/ 
static int LEDDeviceInit(struct LEDDevice *ptLEDDevice)
{
    return KAL_LEDDeviceInit(ptLEDDevice);
}
/**********************************************************************
 * �������ƣ� LEDDeviceControl
 * ���������� Ӧ�ò�LED�豸���ƺ���
 * ��������� ��
 * ��������� ��
 * �� �� ֵ�� 0-�ɹ�, ����ֵ-ʧ��
 * �޸�����        �汾��     �޸���	      �޸�����
 * -----------------------------------------------
 * 2023/11/17	   V1.0	    ������˯ 	      ����
 ***********************************************************************/ 
static int LEDDeviceControl(struct LEDDevice *ptLEDDevice, int iStatus)
{
    return KAL_LEDDeviceControl(ptLEDDevice,iStatus);
}
/**********************************************************************
 * �������ƣ� LEDDeviceSetColor
 * ���������� Ӧ�ò�LED�豸��ɫ���ú���
 * ��������� LED�豸  RGBֵ
 * ��������� ��
 * �� �� ֵ�� 0-�ɹ�, ����ֵ-ʧ��
 * �޸�����        �汾��     �޸���	      �޸�����
 * -----------------------------------------------
 * 2023/11/17	   V1.0	    ������˯ 	      ����
 ***********************************************************************/ 
static int LEDDeviceSetColor(struct LEDDevice *ptLEDDevice, int iR, int iG, int iB)
{
    return KAL_LEDDeviceSetColor(ptLEDDevice, iR, iG, iB);
}

/**********************************************************************
 * �������ƣ� LEDDeviceSetBrightness
 * ���������� Ӧ�ò�LED�豸�������ú���
 * ��������� ��
 * ��������� ��
 * �� �� ֵ�� 0-�ɹ�, ����ֵ-ʧ��
 * �޸�����        �汾��     �޸���	      �޸�����
 * -----------------------------------------------
 * 2023/11/17	   V1.0	    ������˯ 	      ����
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
 * �������ƣ� GetLEDDevice
 * ���������� ��ȡLED�豸����
 * ��������� ��
 * ��������� ��
 * �� �� ֵ�� 0-�ɹ�, ����ֵ-ʧ��
 * �޸�����        �汾��     �޸���	      �޸�����
 * -----------------------------------------------
 * 2023/11/17	   V1.0	    ������˯ 	      ����
 ***********************************************************************/ 
PLEDDevice GetLEDDevice(int which)
{
    if (which >= LED_RED)
        return &g_tLEDDevice[which];
    else
        return NULL;
}
