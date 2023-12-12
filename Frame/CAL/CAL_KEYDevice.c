#include "main.h"
#include "cal_keydevice.h"


/*
*********************************************************************************************************
*	�� �� ��: KeyProcessPthread
*	����˵��: ���������߳�
*	��    ��: ��
*	�� �� ֵ: ��
*   ����          �汾��        �޸���
*   2023/12/12    V1.0        @������˯
*********************************************************************************************************
*/
 static void *KeyProcessPthread(void *arg)
{
    int fd = *(int *)arg;
    struct input_event in_ev;
    while (1)
    {
        /* ѭ����ȡ���� */
        if (sizeof(struct input_event) != read(fd, &in_ev, sizeof(struct input_event)))
        {
            perror("read error");
            exit(-1);
        }
        else
        {
            if (EV_KEY == in_ev.type)
            {
                PutInputEvent(&in_ev);
            }
        }
    }
    return NULL;
}

/*
*********************************************************************************************************
*	�� �� ��: CAL_KEYDeviceInit
*	����˵��: оƬ�����İ�����ʼ������, оƬ��һ��ʱ���޸Ĵ˺���
*	��    ��: ��
*	�� �� ֵ: ��
*   ����          �汾��        �޸���
*   2023/12/12    V1.0        @������˯
*********************************************************************************************************
*/
void CAL_KEYDeviceInit(void)
{
    pthread_t thread_input;

    PInputDevice KeyDevice = malloc(sizeof(InputDevice));
    if (KeyDevice == NULL)
    {
        perror("Memory allocation failed");
        exit(-1);
    }
    if (0 > (KeyDevice->InputDeviceFd = open(KEY_DEVICE_NAME, O_RDONLY)))
    {
        perror("open error");
        free(KeyDevice);
        close(KeyDevice->InputDeviceFd);
    }
    int result = pthread_create(&thread_input, NULL, KeyProcessPthread, &KeyDevice->InputDeviceFd);
    if (result != 0)
    {
        perror("Thread creation failed");
        exit(-1);
    }
}