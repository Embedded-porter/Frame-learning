#include <config.h>
#include <fonts_manager.h>
#include <string.h>

static PT_FontOpr g_ptFontOprHead = NULL;

/**********************************************************************
 * 函数名称： RegisterFontOpr
 * 功能描述： 将ptFontOpr对象添加到链表g_ptFontOprHead中
 * 输入参数： ptFontOpr 结构体
 * 输出参数：
 * 返 回 值： 0-成功, 其他值-失败
 * 修改日期        版本号     修改人	      修改内容
 * -----------------------------------------------
 * 2023/12/10	     V1.0	  尝试早睡		      创建
 ***********************************************************************/
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

/**********************************************************************
 * 函数名称： ShowFontOpr
 * 功能描述： 将所有的字体名打印
 * 输入参数： 无
 * 输出参数：
 * 返 回 值： 0-成功, 其他值-失败
 * 修改日期        版本号     修改人	      修改内容
 * -----------------------------------------------
 * 2023/12/10	     V1.0	  尝试早睡		      创建
 ***********************************************************************/
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

/**********************************************************************
 * 函数名称： GetFontOpr
 * 功能描述： 获取指定名字的字体信息
 * 输入参数： pcName - 字体名称
 * 返 回 值： PT_FontOpr -字体信息结构体指针
 * 修改日期        版本号     修改人	      修改内容
 * -----------------------------------------------
 * 2023/12/10	     V1.0	  尝试早睡		      创建
 ***********************************************************************/
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

/**********************************************************************
 * 函数名称： FontsInit
 * 功能描述： 初始化字体
 * 输入参数： 无
 * 返 回 值： 无
 * 修改日期        版本号     修改人	      修改内容
 * -----------------------------------------------
 * 2023/12/10	     V1.0	  尝试早睡		      创建
 ***********************************************************************/
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
