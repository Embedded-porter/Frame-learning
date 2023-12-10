#include "uart_ringbuffer.h"
#include "main.h"

#if No_OS
static UartMessage g_tUartBuffer;
#elif FreeRTOS
static QueueHandle_t g_xQueueUart;
#elif Linux
static int UartMsgKey = 1235;
int UartMsgid;
#endif

/**********************************************************************
 * �������ƣ� InitUartEvent
 * ���������� ��ʼ�����λ�����
 * ��������� ptUartMessage-�����¼�
 * ��������� ��
 * �� �� ֵ�� 0-�ɹ�, ����ֵ-ʧ��
 * �޸�����        �汾��    	 �޸���	      �޸�����
 * -----------------------------------------------
 * 2023/11/21	     V1.0	  ������˯	      ����
 ***********************************************************************/
int InitUartEvent(void)
{
#if No_OS
	g_tUartBuffer.pR = 0;
	g_tUartBuffer.pW = 0;
	return 0;

#elif FreeRTOS
	g_xQueueUart = xQueueCreate(BUFFER_SIZE, sizeof(UartMessage));
	if (g_xQueueUart == NULL)
	{
		printf("can not create queue\r\n");
		return -1;
	}
	else
	{
		return 0;
	}
#elif Linux
	UartMsgid = msgget(UartMsgKey, IPC_CREAT | 0666);
	if (UartMsgid == -1)
	{
		perror("msgget");
		return -1;
	}
	else
		return 0;
#endif
}
/**********************************************************************
 * �������ƣ� PutUartMessage
 * ���������� �����λ�������������
 * ��������� ptUartMessage-�����¼�
 * ��������� ��
 * �� �� ֵ�� 0-�ɹ�, ����ֵ-ʧ��
 * �޸�����        �汾��    	 �޸���	      �޸�����
 * -----------------------------------------------
 * 2023/11/21	     V1.0	  ������˯	      ����
 ***********************************************************************/
int PutUartEvent(ptUartMessage ptUartEvent)
{
#if No_OS
	int i = (g_tUartBuffer.pW + 1) % BUFFER_SIZE;

	/* ����ʽ��� */
	if (!ptUartEvent)
		return -1;

	if (i != g_tUartBuffer.pR) // ���λ�����û��д��
	{
		g_tUartBuffer.buffer[g_tUartBuffer.pW] = *ptUartEvent;
		g_tUartBuffer.pW = i;
		return 0;
	}
	return -1;
#elif FreeRTOS
	/* д���� */
	xQueueSendFromISR(g_xQueueUart, ptUartEvent, NULL);
	return 0;
#elif Linux
	msgsnd(UartMsgid, (void *)ptUartEvent, sizeof(UartMessage), 0);
	return 0;
#endif
}

/**********************************************************************
 * �������ƣ� GetUartMessage
 * ���������� ���λ�����
 * ��������� ��
 * ��������� 
 * �� �� ֵ�� 0-�ɹ�, ����ֵ-ʧ��
 * �޸�����        �汾��     	�޸���	      �޸�����
 * -----------------------------------------------
 * 2023/11/21	     V1.0	  ������˯		      ����
 ***********************************************************************/

int GetUartEvent( ptUartMessage ptUartEvent)
{
#if No_OS
	/* ����ʽ��� */
	if (!ptUartEvent)
		return -1;

	/* ���λ�������, �򷵻�-1 */
	if (g_tUartBuffer.pR == g_tUartBuffer.pW)
	{
		return -1;
	}
	else
	{
		*ptUartEvent = g_tUartBuffer.buffer[g_tUartBuffer.pR];
		g_tUartBuffer.pR = (g_tUartBuffer.pR + 1) % BUFFER_SIZE;
		return 0;
	}
#elif FreeRTOS
	/* д���� */
	xQueueSendFromISR(g_xQueueUart, ptUartEvent, NULL);
	return 0;
#elif Linux
	msgrcv(UartMsgid, (void *)ptUartEvent, sizeof(UartMessage), 0, IPC_NOWAIT);
	return 0;
#endif
}
