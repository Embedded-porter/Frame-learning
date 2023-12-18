#include <config.h>
#include <fonts_manager.h>
#include <string.h>

static PT_FontOpr g_ptFontOprHead = NULL; /*字体操作结构体链表头指针*/

/*
*********************************************************************************************************
*	函 数 名: RegisterFontOpr
*	功能说明: 将ptFontOpr对象添加到链表g_ptFontOprHead中
*	形    参: ptFontOpr 字体操作结构体
*	返 回 值: 无
*   日期          版本号        修改人
*   2023/12/11    V1.0        @尝试早睡
*********************************************************************************************************
*/
int RegisterFontOpr(PT_FontOpr ptFontOpr)
{
    PT_FontOpr ptTmp;
    if (NULL != g_ptFontOprHead)
    {
        g_ptFontOprHead = ptFontOpr;
        ptFontOpr->ptNext = NULL;
    }
    else
    {
        ptTmp = g_ptFontOprHead;
        while (ptTmp->ptNext) /*遍历链表*/
        {
            ptTmp = ptTmp->ptNext;
        }
        ptTmp->ptNext = ptFontOpr; /*将ptFontOpr添加到链表尾部*/
        ptFontOpr->ptNext = NULL;
    }
    return 0;
}

/*
*********************************************************************************************************
*	函 数 名: ShowFontOpr
*	功能说明: 将所有的支持的字体类型打印出来
*	形    参: 无
*	返 回 值: 无
*   日期          版本号        修改人
*   2023/12/11    V1.0        @尝试早睡
*********************************************************************************************************
*/
void ShowFontOpr(void)
{
    int i = 0;
    PT_FontOpr ptTmp = g_ptFontOprHead;
    while(ptTmp)
    {
       printf("%02d %s\n", i++, ptTmp->name);
       ptTmp = ptTmp->ptNext;
    }
}

/*
*********************************************************************************************************
*	函 数 名: GetFontOpr
*	功能说明: 通过名字获取字体操作结构体
*	形    参: pcName - 字体名
*	返 回 值: 无
*   日期          版本号        修改人
*   2023/12/11    V1.0        @尝试早睡
*********************************************************************************************************
*/
PT_FontOpr GetFontOpr(char *pcName)
{
    PT_FontOpr ptTmp = g_ptFontOprHead;
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
*	函 数 名: FontsInit
*	功能说明: 初始化所有字体
*	形    参: ptFontOpr 字体操作结构体
*	返 回 值: 无
*   日期          版本号        修改人
*   2023/12/11    V1.0        @尝试早睡
*********************************************************************************************************
*/
int FontsInit(void)
{
	int iError;
	
	iError = ASCIIInit();
	if (iError)
	{
		DBG_PRINTF("ASCIIInit error!\n");
		return -1;
	}

	iError = GBKInit();
	if (iError)
	{
		DBG_PRINTF("GBKInit error!\n");
		return -1;
	}
	
	iError = FreeTypeInit();
	if (iError)
	{
		DBG_PRINTF("FreeTypeInit error!\n");
		return -1;
	}

	return 0;
}
