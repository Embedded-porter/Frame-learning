#include <config.h>
#include <encoding_manager.h>
#include <string.h>
#include <stdlib.h>

static PT_EncodingOpr g_ptEncodingOprHead = NULL; /*编码管理链表*/

/*
*********************************************************************************************************
*	函 数 名: RegisterEncodingOpr
*	功能说明: 通过单链表注册编码
*	形    参: dwCode - 字符编码  ptFontBitMap - 字体位图存储位置
*	返 回 值: 无
*   日期          版本号        修改人
*   2023/12/11    V1.0        @尝试早睡
*********************************************************************************************************
*/
int RegisterEncodingOpr(PT_EncodingOpr ptEncodingOpr)
{
    PT_EncodingOpr ptTmp;

    if (!g_ptEncodingOprHead)
    {
        g_ptEncodingOprHead = ptEncodingOpr;
        ptEncodingOpr->ptNext = NULL;
    }
    else
    {
        ptTmp = g_ptEncodingOprHead;
        while (ptTmp->ptNext)
        {
            ptTmp = ptTmp->ptNext;
        }
        ptTmp->ptNext = ptEncodingOpr;
        ptEncodingOpr->ptNext = NULL;
    }

    return 0;
}
/*
*********************************************************************************************************
*	函 数 名: ShowEncodingOpr
*	功能说明: 打印出所以的编码格式
*	形    参: 无
*	返 回 值: 无
*   日期          版本号        修改人
*   2023/12/11    V1.0        @尝试早睡
*********************************************************************************************************
*/
void ShowEncodingOpr(void)
{
    int i = 0;
    PT_EncodingOpr ptTmp = g_ptEncodingOprHead;

    while (ptTmp)
    {
        printf("%02d %s\n", i++, ptTmp->name);
        ptTmp = ptTmp->ptNext;
    }
}

/*
*********************************************************************************************************
*	函 数 名: SelectEncodingOprForFile
*	功能说明: 选择文件的编码格式
*	形    参: 无
*	返 回 值: 无
*   日期          版本号        修改人
*   2023/12/11    V1.0        @尝试早睡
*********************************************************************************************************
*/
PT_EncodingOpr SelectEncodingOprForFile(unsigned char *pucFileBufHead)
{
    PT_EncodingOpr ptTmp = g_ptEncodingOprHead;

    while (ptTmp)
    {
        if (ptTmp->isSupport(pucFileBufHead))
            return ptTmp;
        else
            ptTmp = ptTmp->ptNext;
    }
    return NULL;
}

/*
*********************************************************************************************************
*	函 数 名: AddFontOprForEncoding
*	功能说明: 为编码格式添加字体
*	形    参: ptEncodingOpr - 编码格式  ptFontOpr - 字体
*	返 回 值: 无
*   日期          版本号        修改人
*   2023/12/11    V1.0        @尝试早睡
*********************************************************************************************************
*/
int AddFontOprForEncoding(PT_EncodingOpr ptEncodingOpr, PT_FontOpr ptFontOpr)
{
    PT_FontOpr ptFontOprCpy;

    if (!ptEncodingOpr || !ptFontOpr)
    {
        return -1;
    }
    else
    {
        ptFontOprCpy = malloc(sizeof(T_FontOpr));
        if (!ptFontOprCpy)
        {
            return -1;
        }
        else
        {
            memcpy(ptFontOprCpy, ptFontOpr, sizeof(T_FontOpr));
            ptFontOprCpy->ptNext = ptEncodingOpr->ptFontOprSupportedHead;
            ptEncodingOpr->ptFontOprSupportedHead = ptFontOprCpy;
            return 0;
        }
    }
}
/*
*********************************************************************************************************
*	函 数 名: DelFontOprFrmEncoding
*	功能说明: 删除字体的编码格式
*	形    参: ptEncodingOpr - 编码格式  ptFontOpr - 字体
*	返 回 值: 无
*   日期          版本号        修改人
*   2023/12/11    V1.0        @尝试早睡
*********************************************************************************************************
*/
int DelFontOprFrmEncoding(PT_EncodingOpr ptEncodingOpr, PT_FontOpr ptFontOpr)
{
    PT_FontOpr ptTmp;
    PT_FontOpr ptPre;

    if (!ptEncodingOpr || !ptFontOpr)
    {
        return -1;
    }
    else
    {
        ptTmp = ptEncodingOpr->ptFontOprSupportedHead;
        if (strcmp(ptTmp->name, ptFontOpr->name) == 0)
        {
            /* 删除头节点 */
            ptEncodingOpr->ptFontOprSupportedHead = ptTmp->ptNext;
            free(ptTmp);
            return 0;
        }

        ptPre = ptEncodingOpr->ptFontOprSupportedHead;
        ptTmp = ptPre->ptNext;
        while (ptTmp)
        {
            if (strcmp(ptTmp->name, ptFontOpr->name) == 0)
            {
                /* 从链表里取出、释放 */
                ptPre->ptNext = ptTmp->ptNext;
                free(ptTmp);
                return 0;
            }
            else
            {
                ptPre = ptTmp;
                ptTmp = ptTmp->ptNext;
            }
        }

        return -1;
    }
}

/*
*********************************************************************************************************
*	函 数 名: EncodingInit
*	功能说明: 全部编码格式初始化
*	形    参: 无
*	返 回 值: 无
*   日期          版本号        修改人
*   2023/12/11    V1.0        @尝试早睡
*********************************************************************************************************
*/
int EncodingInit(void)
{
    int iError;

    iError = AsciiEncodingInit();
    if (iError)
    {
        DBG_PRINTF("AsciiEncodingInit error!\n");
        return -1;
    }

    iError = Utf16leEncodingInit();
    if (iError)
    {
        DBG_PRINTF("Utf16leEncodingInit error!\n");
        return -1;
    }

    iError = Utf16beEncodingInit();
    if (iError)
    {
        DBG_PRINTF("Utf16beEncodingInit error!\n");
        return -1;
    }

    iError = Utf8EncodingInit();
    if (iError)
    {
        DBG_PRINTF("Utf8EncodingInit error!\n");
        return -1;
    }

    return 0;
}
