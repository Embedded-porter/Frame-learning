#include <display_device.h>
#include <string.h>
#include <config.h>

static PT_DispOpr g_ptDispOprHead; /*定义一个指向显示设备的指针*/

/*
*********************************************************************************************************
*	函 数 名: RegisterDispOpr
*	功能说明: 链表遍历注册显示设备
*	形    参: ptDispOpr -显示设备指针结构体
*	返 回 值: 无
*   日期          版本号        修改人
*   2023/12/11    V1.0        @尝试早睡
*********************************************************************************************************
*/
int RegisterDispOpr(PT_DispOpr ptDispOpr)
{
	PT_DispOpr ptTmp;

	if (!g_ptDispOprHead)
	{
		g_ptDispOprHead = ptDispOpr; /*指定链表头*/
		ptDispOpr->ptNext = NULL;
	}
	else
	{
		ptTmp = g_ptDispOprHead; /*先将链表节点赋值*/
		while (ptTmp->ptNext)	 /*遍历链表*/
		{
			ptTmp = ptTmp->ptNext;
		}
		ptTmp->ptNext = ptDispOpr; /*将ptTmp节点添加到链表尾部*/
		ptDispOpr->ptNext = NULL;
	}

	return 0;
}

/*
*********************************************************************************************************
*	函 数 名: ShowDispOpr
*	功能说明: 打印出全部的显示设备
*	形    参: 无
*	返 回 值: 无
*   日期          版本号        修改人
*   2023/12/11    V1.0        @尝试早睡
*********************************************************************************************************
*/
void ShowDispOpr(void)
{
	int i = 0;
	PT_DispOpr ptTmp = g_ptDispOprHead;

	while (ptTmp)
	{
		printf("%02d %s\n", i++, ptTmp->name);
		ptTmp = ptTmp->ptNext;
	}
}

/*
*********************************************************************************************************
*	函 数 名: GetDispOpr
*	功能说明: 通过显示设备名字获取设备结构体指针
*	形    参: 无
*	返 回 值: 无
*   日期          版本号        修改人
*   2023/12/11    V1.0        @尝试早睡
*********************************************************************************************************
*/
PT_DispOpr GetDispOpr(char *pcName)
{
	PT_DispOpr ptTmp = g_ptDispOprHead;

	while (ptTmp)
	{
		if (strcmp(ptTmp->name, pcName) == 0)
		{
			return ptTmp;
		}
		ptTmp = ptTmp->ptNext;
	}
	return NULL;
}

/*
*********************************************************************************************************
*	函 数 名: DisplayInit
*	功能说明: 初始化显示设备
*	形    参: 无
*	返 回 值: 无
*   日期          版本号        修改人
*   2023/12/11    V1.0        @尝试早睡
*********************************************************************************************************
*/
int DisplayInit(void)
{
	int iError;

	iError = FBInit();

	return iError;
}
