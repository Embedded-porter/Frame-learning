#include "main.h"
#include "cal_leddevice.h"

int TriggerFd, BrightnessFd;

/**********************************************************************
 * �������ƣ� KAL_LEDDeviceInit
 * ���������� оƬ������LED��ʼ������, оƬ��һ��ʱ���޸Ĵ˺���
 * ��������� ptLEDDevice-�ĸ�LED�豸
 * ��������� ��
 * �� �� ֵ�� 0-�ɹ�
 * �޸�����          �汾��     �޸���	      �޸�����
 * -----------------------------------------------
 * 2023/11/16	     V1.0	 ������˯	      ����
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
 * �������ƣ� CAL_LEDDeviceControl
 * ���������� оƬ������LED���ƺ���, оƬ��һ��ʱ���޸Ĵ˺���
 * ��������� ptLEDDevice-�ĸ�LED�豸
 * ��������� ��
 * �� �� ֵ�� 0-�ɹ�
 * �޸�����          �汾��     �޸���	      �޸�����
 * -----------------------------------------------
 * 2023/11/16	     V1.0	 ������˯	      ����
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
 * �������ƣ� CAL_LEDDeviceSetColor
 * ���������� оƬ������LED��ɫ���ú���, оƬ��һ��ʱ���޸Ĵ˺���
 * ��������� ptLEDDevice-�ĸ�LED�豸
 * ��������� ��
 * �� �� ֵ�� 0-�ɹ�
 * �޸�����          �汾��     �޸���	      �޸�����
 * -----------------------------------------------
 * 2023/11/16	     V1.0	 ������˯	      ����
 ***********************************************************************/
int CAL_LEDDeviceSetColor(struct LEDDevice *ptLEDDevice, int iR, int iG, int iB)
{
    return 0;
}
/**********************************************************************
 * �������ƣ� CAL_LEDDeviceSetBrightness
 * ���������� оƬ������LED�������ú���, оƬ��һ��ʱ���޸Ĵ˺���
 * ��������� ptLEDDevice-�ĸ�LED�豸
 * ��������� ��
 * �� �� ֵ�� 0-�ɹ�
 * �޸�����          �汾��     �޸���	      �޸�����
 * -----------------------------------------------
 * 2023/11/16	     V1.0	 ������˯	      ����
 ***********************************************************************/
int CAL_LEDDeviceSetBrightness(struct LEDDevice *ptLEDDevice, int iBrightness)
{
    return 0;
}