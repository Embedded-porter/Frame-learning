#include <config.h>
#include <encoding_manager.h>
#include <string.h>

static int isUtf16beCoding(unsigned char *pucBufHead); /* UTF-16 big endian编码判断 */
static int Utf16beGetCodeFrmBuf(unsigned char *pucBufStart, unsigned char *pucBufEnd, unsigned int *pdwCode); /* 从缓冲区中取得UTF-16 big endian码 */ 

static T_EncodingOpr g_tUtf16beEncodingOpr = {
	.name          = "utf-16be",
	.iHeadLen	   = 2,
	.isSupport     = isUtf16beCoding,
	.GetCodeFrmBuf = Utf16beGetCodeFrmBuf,
};

/*
*********************************************************************************************************
*	函 数 名: isUtf16beCoding
*	功能说明: 判断是否是UTF-16be编码
*	形    参: pucBufHead - 缓冲区头指针
*	返 回 值: 无
*   日期          版本号        修改人
*   2023/12/11    V1.0        @尝试早睡
*********************************************************************************************************
*/
static int isUtf16beCoding(unsigned char *pucBufHead)
{
	const char aStrUtf16be[] = {0xFE, 0xFF, 0};
	
	if (strncmp((const char*)pucBufHead, aStrUtf16be, 2) == 0)
	{
		/* UTF-16 big endian */
		return 1;
	}
	else
	{
		return 0;
	}
}

/*
*********************************************************************************************************
*	函 数 名: Utf16beGetCodeFrmBuf
*	功能说明: 从缓冲区中取得UTF-16be码
*	形    参: pucBufStart - 缓冲区头指针 pucBufEnd - 缓冲区尾指针 pdwCode - 获取到的UTF-16be编码
*	返 回 值: 无
*   日期          版本号        修改人
*   2023/12/11    V1.0        @尝试早睡
*********************************************************************************************************
*/
static int Utf16beGetCodeFrmBuf(unsigned char *pucBufStart, unsigned char *pucBufEnd, unsigned int *pdwCode)
{
	if (pucBufStart + 1 < pucBufEnd)
	{
		*pdwCode = (((unsigned int)pucBufStart[0])<<8) + pucBufStart[1];
		return 2;
	}
	else
	{
		return 0;
	}
}

/*
*********************************************************************************************************
*	函 数 名: Utf16beEncodingInit
*	功能说明: 初始化UTF-16be编码,给其他函数调用
*	形    参: 无
*	返 回 值: 无
*   日期          版本号        修改人
*   2023/12/11    V1.0        @尝试早睡
*********************************************************************************************************
*/
int  Utf16beEncodingInit(void)
{
	AddFontOprForEncoding(&g_tUtf16beEncodingOpr, GetFontOpr("freetype"));
	AddFontOprForEncoding(&g_tUtf16beEncodingOpr, GetFontOpr("ascii"));
	return RegisterEncodingOpr(&g_tUtf16beEncodingOpr);
}



