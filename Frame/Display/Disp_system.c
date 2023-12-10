#include <display_device.h>
#include <string.h>
#include <config.h>

static PT_DispOpr g_ptDispOprHead;/*定义一个指向显示设备的指针*/

/**********************************************************************
 * 函数名称： RegisterDispOpr
 * 功能描述： 链表遍历显示设备
 * 输入参数： ptDispOpr -显示设备指针结构体
 * 输出参数： 无
 * 返 回 值： 无
 * 修改日期        版本号     修改人	      修改内容
 * -----------------------------------------------
 * 2023/12/10	   V1.0	    @尝试早睡	      创建
 ***********************************************************************/
int RegisterDispOpr(PT_DispOpr ptDispOpr)
{
	PT_DispOpr ptTmp;

	if (!g_ptDispOprHead)
	{
		g_ptDispOprHead   = ptDispOpr;
		ptDispOpr->ptNext = NULL;
	}
	else
	{
		ptTmp = g_ptDispOprHead;
		while (ptTmp->ptNext)
		{
			ptTmp = ptTmp->ptNext;
		}
		ptTmp->ptNext	  = ptDispOpr;
		ptDispOpr->ptNext = NULL;
	}

	return 0;
}

/**********************************************************************
 * 函数名称： ShowDispOpr
 * 功能描述： 打印出全部的显示设备
 * 输入参数： 无
 * 输出参数： 无
 * 返 回 值： 无
 * 修改日期        版本号     修改人	      修改内容
 * -----------------------------------------------
 * 2023/12/10	   V1.0	    @尝试早睡	      创建
 ***********************************************************************/
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

/**********************************************************************
 * 函数名称： GetDispOpr
 * 功能描述： 通过名字获取显示设备结构体指针
 * 输入参数： pcName - 显示设备名
 * 返 回 值： PT_DispOpr -显示设备结构体指针
 * 修改日期        版本号     修改人	      修改内容
 * -----------------------------------------------
 * 2023/12/10	   V1.0	     @尝试早睡	      创建
 ***********************************************************************/
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

/**********************************************************************
 * 函数名称： DisplayInit
 * 功能描述： 初始化显示设备
 * 输入参数： 无
 * 返 回 值： 是否初始化成功
 * 修改日期        版本号     修改人	      修改内容
 * -----------------------------------------------
 * 2023/12/10	   V1.0	     @尝试早睡	      创建
 ***********************************************************************/
int DisplayInit(void)
{
	int iError;
	
	iError = FBInit();

	return iError;
}

