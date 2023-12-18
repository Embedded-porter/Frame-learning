#ifndef __INPUT_BUFFER_H
#define __INPUT_BUFFER_H

#include "main.h"

#define No_OS 0
#define FreeRTOS 0
#define Linux 1

#define BUFFER_SIZE 1024 /* ���λ������Ĵ�С */

typedef struct
{
    InputEvent buffer[BUFFER_SIZE]; /* �������ռ� */
    volatile unsigned int pW;       /* д��ַ */
    volatile unsigned int pR;       /* ����ַ */
} InputEventBuffer;

extern int msgid;

#if No_OS||FreeRTOS

/*
*********************************************************************************************************
*	�� �� ��: InitInputQueue
*	����˵��: ��ʼ�����λ�����
*	��    ��: ��
*	�� �� ֵ: ��
*   ����          �汾��        �޸���
*   2023/12/12    V1.0        @������˯
*********************************************************************************************************
*/
int InitInputQueue(void);

/*
*********************************************************************************************************
*	�� �� ��: PutInputEvent
*	����˵��: �����λ�������������
*	��    ��: ptInputEvent-�����¼�
*	�� �� ֵ: ��
*   ����          �汾��        �޸���
*   2023/12/12    V1.0        @������˯
*********************************************************************************************************
*/
int PutInputEvent(PInputEvent ptInputEvent);

/*
*********************************************************************************************************
*	�� �� ��: GetInputEvent
*	����˵��: ��ȡ���λ���������
*	��    ��: ptInputEvent-�����¼�
*	�� �� ֵ: ��
*   ����          �汾��        �޸���
*   2023/12/12    V1.0        @������˯
*********************************************************************************************************
*/
int GetInputEvent(PInputEvent ptInputEvent);

#elif Linux 

/*
*********************************************************************************************************
*	�� �� ��: InitInputQueue
*	����˵��: ��ʼ�����λ�����
*	��    ��: ��
*	�� �� ֵ: ��
*   ����          �汾��        �޸���
*   2023/12/12    V1.0        @������˯
*********************************************************************************************************
*/
int InitInputQueue(void);

/*
*********************************************************************************************************
*	�� �� ��: PutInputEvent
*	����˵��: �����λ�������������
*	��    ��: ptInputEvent-�����¼�
*	�� �� ֵ: ��
*   ����          �汾��        �޸���
*   2023/12/12    V1.0        @������˯
*********************************************************************************************************
*/
int PutInputEvent(struct input_event* ptInputEvent);

/*
*********************************************************************************************************
*	�� �� ��: GetInputEvent
*	����˵��: ��ȡ���λ���������
*	��    ��: ptInputEvent-�����¼�
*	�� �� ֵ: ��
*   ����          �汾��        �޸���
*   2023/12/12    V1.0        @������˯
*********************************************************************************************************
*/
int GetInputEvent(struct input_event* ptInputEvent);

#endif

#endif /* __INPUT_BUFFER_H */