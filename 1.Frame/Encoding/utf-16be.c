#include <config.h>
#include <encoding_manager.h>
#include <string.h>

static int isUtf16beCoding(unsigned char *pucBufHead); /* UTF-16 big endian�����ж� */
static int Utf16beGetCodeFrmBuf(unsigned char *pucBufStart, unsigned char *pucBufEnd, unsigned int *pdwCode); /* �ӻ�������ȡ��UTF-16 big endian�� */ 

static T_EncodingOpr g_tUtf16beEncodingOpr = {
	.name          = "utf-16be",
	.iHeadLen	   = 2,
	.isSupport     = isUtf16beCoding,
	.GetCodeFrmBuf = Utf16beGetCodeFrmBuf,
};

/*
*********************************************************************************************************
*	�� �� ��: isUtf16beCoding
*	����˵��: �ж��Ƿ���UTF-16be����
*	��    ��: pucBufHead - ������ͷָ��
*	�� �� ֵ: ��
*   ����          �汾��        �޸���
*   2023/12/11    V1.0        @������˯
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
*	�� �� ��: Utf16beGetCodeFrmBuf
*	����˵��: �ӻ�������ȡ��UTF-16be��
*	��    ��: pucBufStart - ������ͷָ�� pucBufEnd - ������βָ�� pdwCode - ��ȡ����UTF-16be����
*	�� �� ֵ: ��
*   ����          �汾��        �޸���
*   2023/12/11    V1.0        @������˯
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
*	�� �� ��: Utf16beEncodingInit
*	����˵��: ��ʼ��UTF-16be����,��������������
*	��    ��: ��
*	�� �� ֵ: ��
*   ����          �汾��        �޸���
*   2023/12/11    V1.0        @������˯
*********************************************************************************************************
*/
int  Utf16beEncodingInit(void)
{
	AddFontOprForEncoding(&g_tUtf16beEncodingOpr, GetFontOpr("freetype"));
	AddFontOprForEncoding(&g_tUtf16beEncodingOpr, GetFontOpr("ascii"));
	return RegisterEncodingOpr(&g_tUtf16beEncodingOpr);
}



