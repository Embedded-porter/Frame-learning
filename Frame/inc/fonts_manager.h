#ifndef _FONTS_MANAGER_H
#define _FONTS_MANAGER_H

typedef struct FontBitMap
{
    int iXLeft; /*λͼ������� x ����*/
    int iYTop;  /*λͼ�����ϲ� y ����*/
    int iXMax;  /*λͼ����� x ����*/
    int iYMax;  /*λͼ����� y ����*/
    int iBpp;   /*ÿ���ص�λ��*/
    int iPitch; /* ���ڵ�ɫλͼ, ��������֮��Ŀ�� */
    int iCurOriginX;
    int iCurOriginY;
    int iNextOriginX;
    int iNextOriginY;
    unsigned char *pucBuffer; /*�Դ���buf*/
} T_FontBitMap, *PT_FontBitMap;

typedef struct FontOpr
{
    char *name;                                                            /*������*/
    int (*FontInit)(char *pcFontFile, unsigned int dwFontSize);            /*��ʼ������*/
    int (*GetFontBitmap)(unsigned int dwCode, PT_FontBitMap ptFontBitMap); /*��ȡ����λͼ*/
    struct FontOpr *ptNext;                                                /*��һ������*/
} T_FontOpr, *PT_FontOpr;

int RegisterFontOpr(PT_FontOpr ptFontOpr);
void ShowFontOpr(void);
int FontsInit(void);
int ASCIIInit(void);
int GBKInit(void);
int FreeTypeInit(void);
PT_FontOpr GetFontOpr(char *pcName);

#endif