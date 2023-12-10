#include "main.h"
#include "kal_leddevice.h"
/**********************************************************************
 * �������ƣ� KAL_LEDDeviceInit
 * ���������� �ں˳�����LED��ʼ������, �ں˲�һ��ʱ���޸Ĵ˺���
 * ��������� ptLEDDevice-�ĸ�LED�豸
 * ��������� ��
 * �� �� ֵ�� 0-�ɹ�
 * �޸�����          �汾��     �޸���	      �޸�����
 * -----------------------------------------------
 * 2023/11/16	     V1.0	 Embedded Lin	      ����
 ***********************************************************************/
int KAL_LEDDeviceInit(struct LEDDevice *ptLEDDevice)
{
    return CAL_LEDDeviceInit(ptLEDDevice);
}
/**********************************************************************
 * �������ƣ� KAL_LEDDeviceControl
 * ���������� �ں˳�����LED���ƺ���, �ں˲�һ��ʱ���޸Ĵ˺���
 * ��������� ptLEDDevice-�ĸ�LED�豸
 * ��������� ��
 * �� �� ֵ�� 0-�ɹ�
 * �޸�����          �汾��     �޸���	      �޸�����
 * -----------------------------------------------
 * 2023/11/16	     V1.0	 Embedded Lin	      ����
 ***********************************************************************/
int KAL_LEDDeviceControl(struct LEDDevice *ptLEDDevice, int iStatus)
{
    return CAL_LEDDeviceControl(ptLEDDevice, iStatus);
}
/**********************************************************************
 * �������ƣ� KAL_LEDDeviceInit
 * ���������� �ں˳�����LED��ɫ���ú���, �ں˲�һ��ʱ���޸Ĵ˺���
 * ��������� ptLEDDevice-�ĸ�LED�豸
 * ��������� ��
 * �� �� ֵ�� 0-�ɹ�
 * �޸�����          �汾��     �޸���	      �޸�����
 * -----------------------------------------------
 * 2023/11/16	     V1.0	 Embedded Lin	      ����
 ***********************************************************************/
int KAL_LEDDeviceSetColor(struct LEDDevice *ptLEDDevice, int iR, int iG, int iB)
{
    return CAL_LEDDeviceSetColor(ptLEDDevice, iR, iG, iB);
}
/**********************************************************************
 * �������ƣ� KAL_LEDDeviceSetBrightness
 * ���������� �ں˳�����LED�������ú���, �ں˲�һ��ʱ���޸Ĵ˺���
 * ��������� ptLEDDevice-�ĸ�LED�豸
 * ��������� ��
 * �� �� ֵ�� 0-�ɹ�
 * �޸�����          �汾��     �޸���	      �޸�����
 * -----------------------------------------------
 * 2023/11/16	     V1.0	 Embedded Lin	      ����
 ***********************************************************************/
int KAL_LEDDeviceSetBrightness(struct LEDDevice *ptLEDDevice, int iBrightness)
{
    return CAL_LEDDeviceSetBrightness(ptLEDDevice, iBrightness);
}