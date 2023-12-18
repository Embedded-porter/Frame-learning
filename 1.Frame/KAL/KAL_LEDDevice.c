#include "main.h"
#include "kal_leddevice.h"

/*
*********************************************************************************************************
*	�� �� ��: KAL_LEDDeviceInit
*	����˵��: �ں˳�����LED��ʼ������, �ں˲�һ��ʱ���޸Ĵ˺���
*	��    ��:  ptLEDDevice-�ĸ�LED�豸
*	�� �� ֵ: ��
*   ����          �汾��        �޸���
*   2023/12/12    V1.0        @������˯
*********************************************************************************************************
*/
int KAL_LEDDeviceInit(struct LEDDevice *ptLEDDevice)
{
    return CAL_LEDDeviceInit(ptLEDDevice);
}

/*
*********************************************************************************************************
*	�� �� ��: KAL_LEDDeviceControl
*	����˵��: �ں˳�����LED���ƺ���, �ں˲�һ��ʱ���޸Ĵ˺���
*	��    ��:  ptLEDDevice-�ĸ�LED�豸  iStatus-LED�豸״̬
*	�� �� ֵ: ��
*   ����          �汾��        �޸���
*   2023/12/12    V1.0        @������˯
*********************************************************************************************************
*/
int KAL_LEDDeviceControl(struct LEDDevice *ptLEDDevice, int iStatus)
{
    return CAL_LEDDeviceControl(ptLEDDevice, iStatus);
}

/*
*********************************************************************************************************
*	�� �� ��: KAL_LEDDeviceSetColor
*	����˵��: �ں˳�����LED��ɫ���ú���, �ں˲�һ��ʱ���޸Ĵ˺���
*	��    ��:  ptLEDDevice-�ĸ�LED�豸  iR-��ɫֵ  iG-��ɫֵ  iB-��ɫֵ
*	�� �� ֵ: ��
*   ����          �汾��        �޸���
*   2023/12/12    V1.0        @������˯
*********************************************************************************************************
*/
int KAL_LEDDeviceSetColor(struct LEDDevice *ptLEDDevice, int iR, int iG, int iB)
{
    return CAL_LEDDeviceSetColor(ptLEDDevice, iR, iG, iB);
}

/*
*********************************************************************************************************
*	�� �� ��: KAL_LEDDeviceSetBrightness
*	����˵��: �ں˳�����LED�������ú���, �ں˲�һ��ʱ���޸Ĵ˺���
*	��    ��:  ptLEDDevice-�ĸ�LED�豸  iBrightness-����
*	�� �� ֵ: ��
*   ����          �汾��        �޸���
*   2023/12/12    V1.0        @������˯
*********************************************************************************************************
*/
int KAL_LEDDeviceSetBrightness(struct LEDDevice *ptLEDDevice, int iBrightness)
{
    return CAL_LEDDeviceSetBrightness(ptLEDDevice, iBrightness);
}