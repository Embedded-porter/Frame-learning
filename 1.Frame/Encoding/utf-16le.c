#include <config.h>
#include <encoding_manager.h>
#include <string.h>

static int isUtf16leCoding(unsigned char *pucBufHead); /* UTF-16 little endian???? */
static int Utf16leGetCodeFrmBuf(unsigned char *pucBufStart, unsigned char *pucBufEnd, unsigned int *pdwCode); /* ???????UTF-16 little endian? */

static T_EncodingOpr g_tUtf16leEncodingOpr = {
	.name          = "utf-16le",
	.iHeadLen	   = 2,
	.isSupport     = isUtf16leCoding,
	.GetCodeFrmBuf = Utf16leGetCodeFrmBuf,
};

/*
*********************************************************************************************************
*	函 数 名: isUtf16leCoding
*	功能说明: 判断是否是UTF-16le编码
*	形    参: pucBufHead - 缓冲区头指针
*	返 回 值: 无
*   日期          版本号        修改人
*   2023/12/11    V1.0        @尝试早睡
*********************************************************************************************************
*/
static int isUtf16leCoding(unsigned char *pucBufHead)
{
	const char aStrUtf16le[] = {0xFF, 0xFE, 0};
	if (strncmp((const char *)pucBufHead, aStrUtf16le, 2) == 0)
	{
		/* UTF-16 little endian */
		return 1;
	}
	else
	{
		return 0;
	}
}

/*
*********************************************************************************************************
*	函 数 名: Utf16leGetCodeFrmBuf
*	功能说明: 从缓冲区中取得UTF-16le码
*	形    参: pucBufStart - 缓冲区头指针 pucBufEnd - 缓冲区尾指针 pdwCode - 获取到的UTF-16be编码
*	返 回 值: 无
*   日期          版本号        修改人
*   2023/12/11    V1.0        @尝试早睡
*********************************************************************************************************
*/
static int Utf16leGetCodeFrmBuf(unsigned char *pucBufStart, unsigned char *pucBufEnd, unsigned int *pdwCode)
{
	if (pucBufStart + 1 < pucBufEnd)
	{
		*pdwCode = (((unsigned int)pucBufStart[1])<<8) + pucBufStart[0];
		return 2;
	}
	else
	{
		return 0;
	}
}

/*
*********************************************************************************************************
*	函 数 名: Utf16leEncodingInit
*	功能说明: 初始化UTF-16le编码,给其他函数调用
*	形    参: 无
*	返 回 值: 无
*   日期          版本号        修改人
*   2023/12/11    V1.0        @尝试早睡
*********************************************************************************************************
*/
int  Utf16leEncodingInit(void)
{
	AddFontOprForEncoding(&g_tUtf16leEncodingOpr, GetFontOpr("freetype"));
	AddFontOprForEncoding(&g_tUtf16leEncodingOpr, GetFontOpr("ascii"));
	return RegisterEncodingOpr(&g_tUtf16leEncodingOpr);
}


