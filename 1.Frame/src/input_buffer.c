#include "input_buffer.h"
#include "main.h"

#if No_OS
static InputEventBuffer g_tInputBuffer;
#elif FreeRTOS
static QueueHandle_t g_xQueueInput; /*��Ϣ���б�������*/
#elif Linux
static int InputMsgKey = 1234; /*��Ϣ���е���Կ*/
int InputMsgid;				   /*��Ϣ����ID*/
#endif

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
int InitInputQueue(void)
{
#if No_OS
	g_tInputBuffer.pR = 0;
	g_tInputBuffer.pW = 0;
	return 0;

#elif FreeRTOS
	g_xQueueInput = xQueueCreate(BUFFER_SIZE, sizeof(InputEvent));
	if (g_xQueueInput == NULL)
	{
		printf("can not create queue\r\n");
		return -1;
	}
	else
	{
		return 0;
	}
#elif Linux
	InputMsgid = msgget(InputMsgKey, IPC_CREAT | 0666);
	if (InputMsgid == -1)
	{
		perror("msgget");
		return -1;
	}
	else
		return 0;
#endif
}

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
#if No_OS || FreeRTOS
int PutInputEvent(PInputEvent ptInputEvent)
#elif Linux
int PutInputEvent(struct input_event *ptInputEvent)
#endif
{
#if No_OS
	int i = (g_tInputBuffer.pW + 1) % BUFFER_SIZE;

	/* ����ʽ��� */
	if (!ptInputEvent)
		return -1;

	if (i != g_tInputBuffer.pR) // ���λ�����û��д��
	{
		g_tInputBuffer.buffer[g_tInputBuffer.pW] = *ptInputEvent;
		g_tInputBuffer.pW = i;
		return 0;
	}
	return -1;
#elif FreeRTOS
	/* д���� */
	xQueueSendFromISR(g_xQueueInput, ptInputEvent, NULL);
	return 0;
#elif Linux
	msgsnd(InputMsgid, (void *)ptInputEvent, sizeof(struct input_event), 0);
	return 0;
#endif
}

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
#if No_OS || FreeRTOS
int GetInputEvent(PInputEvent ptInputEvent)
#elif Linux
int GetInputEvent(struct input_event *ptInputEvent)
#endif
{
#if No_OS
	/* ����ʽ��� */
	if (!ptInputEvent)
		return -1;

	/* ���λ�������, �򷵻�-1 */
	if (g_tInputBuffer.pR == g_tInputBuffer.pW)
	{
		return -1;
	}
	else
	{
		*ptInputEvent = g_tInputBuffer.buffer[g_tInputBuffer.pR];
		g_tInputBuffer.pR = (g_tInputBuffer.pR + 1) % BUFFER_SIZE;
		return 0;
	}
#elif FreeRTOS
	/* д���� */
	xQueueSendFromISR(g_xQueueInput, ptInputEvent, NULL);
	return 0;
#elif Linux
	msgrcv(InputMsgid, (void *)ptInputEvent, sizeof(struct input_event), 0, IPC_NOWAIT);
	return 0;
#endif
}
