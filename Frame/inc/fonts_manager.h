#ifndef _FONTS_MANAGER_H
#define _FONTS_MANAGER_H

typedef struct FontBitMap
{
    int iXLeft; /*位图的最左侧 x 坐标*/
    int iYTop;  /*位图的最上侧 y 坐标*/
    int iXMax;  /*位图的最大 x 坐标*/
    int iYMax;  /*位图的最大 y 坐标*/
    int iBpp;   /*每像素的位数*/
    int iPitch; /* 对于单色位图, 两行象素之间的跨度 */
    int iCurOriginX;
    int iCurOriginY;
    int iNextOriginX;
    int iNextOriginY;
    unsigned char *pucBuffer; /*显存在buf*/
} T_FontBitMap, *PT_FontBitMap;

typedef struct FontOpr
{
    char *name;                                                            /*字体名*/
    int (*FontInit)(char *pcFontFile, unsigned int dwFontSize);            /*初始化字体*/
    int (*GetFontBitmap)(unsigned int dwCode, PT_FontBitMap ptFontBitMap); /*获取字体位图*/
    struct FontOpr *ptNext;                                                /*下一个字体*/
} T_FontOpr, *PT_FontOpr;

int RegisterFontOpr(PT_FontOpr ptFontOpr);
void ShowFontOpr(void);
int FontsInit(void);
int ASCIIInit(void);
int GBKInit(void);
int FreeTypeInit(void);
PT_FontOpr GetFontOpr(char *pcName);

#endif