#include "input_buffer.h"
#include "main.h"

#if No_OS
static InputEventBuffer g_tInputBuffer;
#elif FreeRTOS
static QueueHandle_t g_xQueueInput; /*消息队列变量定义*/
#elif Linux
static int InputMsgKey = 1234; /*消息队列的密钥*/
int InputMsgid;				   /*消息队列ID*/
#endif

/*
*********************************************************************************************************
*	函 数 名: InitInputQueue
*	功能说明: 初始化环形缓冲区
*	形    参: 无
*	返 回 值: 无
*   日期          版本号        修改人
*   2023/12/12    V1.0        @尝试早睡
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
*	函 数 名: PutInputEvent
*	功能说明: 往环形缓冲区放入数据
*	形    参: ptInputEvent-输入事件
*	返 回 值: 无
*   日期          版本号        修改人
*   2023/12/12    V1.0        @尝试早睡
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

	/* 防御式编程 */
	if (!ptInputEvent)
		return -1;

	if (i != g_tInputBuffer.pR) // 环形缓冲区没有写满
	{
		g_tInputBuffer.buffer[g_tInputBuffer.pW] = *ptInputEvent;
		g_tInputBuffer.pW = i;
		return 0;
	}
	return -1;
#elif FreeRTOS
	/* 写队列 */
	xQueueSendFromISR(g_xQueueInput, ptInputEvent, NULL);
	return 0;
#elif Linux
	msgsnd(InputMsgid, (void *)ptInputEvent, sizeof(struct input_event), 0);
	return 0;
#endif
}

/*
*********************************************************************************************************
*	函 数 名: GetInputEvent
*	功能说明: 获取环形缓冲区数据
*	形    参: ptInputEvent-输入事件
*	返 回 值: 无
*   日期          版本号        修改人
*   2023/12/12    V1.0        @尝试早睡
*********************************************************************************************************
*/
#if No_OS || FreeRTOS
int GetInputEvent(PInputEvent ptInputEvent)
#elif Linux
int GetInputEvent(struct input_event *ptInputEvent)
#endif
{
#if No_OS
	/* 防御式编程 */
	if (!ptInputEvent)
		return -1;

	/* 环形缓冲区空, 则返回-1 */
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
	/* 写队列 */
	xQueueSendFromISR(g_xQueueInput, ptInputEvent, NULL);
	return 0;
#elif Linux
	msgrcv(InputMsgid, (void *)ptInputEvent, sizeof(struct input_event), 0, IPC_NOWAIT);
	return 0;
#endif
}
