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

/*
*********************************************************************************************************
*	函 数 名: InitUartEvent
*	功能说明: 初始化串口环形缓冲区
*	形    参: 无
*	返 回 值: 无
*   日期          版本号        修改人
*   2023/12/12    V1.0        @尝试早睡
*********************************************************************************************************
*/
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

/*
*********************************************************************************************************
*	函 数 名: PutUartEvent
*	功能说明: 往串口环形缓冲区放入数据
*	形    参: 无
*	返 回 值: 无
*   日期          版本号        修改人
*   2023/12/12    V1.0        @尝试早睡
*********************************************************************************************************
*/
int PutUartEvent(ptUartMessage ptUartEvent)
{
#if No_OS
	int i = (g_tUartBuffer.pW + 1) % BUFFER_SIZE;

	/* 防御式编程 */
	if (!ptUartEvent)
		return -1;

	if (i != g_tUartBuffer.pR) // 环形缓冲区没有写满
	{
		g_tUartBuffer.buffer[g_tUartBuffer.pW] = *ptUartEvent;
		g_tUartBuffer.pW = i;
		return 0;
	}
	return -1;
#elif FreeRTOS
	/* 写队列 */
	xQueueSendFromISR(g_xQueueUart, ptUartEvent, NULL);
	return 0;
#elif Linux
	msgsnd(UartMsgid, (void *)ptUartEvent, sizeof(UartMessage), 0);
	return 0;
#endif
}

/*
*********************************************************************************************************
*	函 数 名: GetUartEvent
*	功能说明: 获取串口环形缓冲区数据
*	形    参: 无
*	返 回 值: 无
*   日期          版本号        修改人
*   2023/12/12    V1.0        @尝试早睡
*********************************************************************************************************
*/
int GetUartEvent( ptUartMessage ptUartEvent)
{
#if No_OS
	/* 防御式编程 */
	if (!ptUartEvent)
		return -1;

	/* 环形缓冲区空, 则返回-1 */
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
	/* 写队列 */
	xQueueSendFromISR(g_xQueueUart, ptUartEvent, NULL);
	return 0;
#elif Linux
	msgrcv(UartMsgid, (void *)ptUartEvent, sizeof(UartMessage), 0, IPC_NOWAIT);
	return 0;
#endif
}
