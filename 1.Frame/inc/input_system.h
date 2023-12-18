#ifndef __INPUT_SYSTEM_H
#define __INPUT_SYSTEM_H

#ifndef NULL
#define NULL (void *)0
#endif

#define TIME_T int
#define INTPU_BUF_LEN 50

typedef enum
{    
	INPUT_EVENT_TYPE_KEY,
	INPUT_EVENT_TYPE_TOUCH,
	INPUT_EVENT_TYPE_NET,
	INPUT_EVENT_TYPE_STDIO
}INPUT_EVENT_TYPE;

typedef struct InputEvent {
	TIME_T time;
	INPUT_EVENT_TYPE eType;
	int iX;
	int iY;
	int iKey;
	int iPressure;
	char str[INTPU_BUF_LEN];
}InputEvent, *PInputEvent;

typedef struct InputDevice {
	int  InputDeviceFd;   	
	char *name;
	int (*GetInputEvent)(PInputEvent ptInputEvent);
	int (*DeviceInit)(void);
	int (*DeviceExit)(void);
	struct InputDevice *pNext;
}InputDevice, *PInputDevice;



/*
*********************************************************************************************************
*	函 数 名: AddInputDevices
*	功能说明: 注册多个输入设备
*	形    参: 无
*	返 回 值: 无
*   日期          版本号        修改人
*   2023/12/12    V1.0        @尝试早睡
*********************************************************************************************************
*/
void AddInputDevices(void);


/*
*********************************************************************************************************
*	函 数 名: InitInputDevices
*	功能说明: 初始化所有的输入设备
*	形    参: 无
*	返 回 值: 无
*   日期          版本号        修改人
*   2023/12/12    V1.0        @尝试早睡
*********************************************************************************************************
*/
void InitInputDevices(void);

/*
*********************************************************************************************************
*	函 数 名: InputDeviceRegister
*	功能说明: 注册所有的一个输入设备
*	形    参: 无
*	返 回 值: 无
*   日期          版本号        修改人
*   2023/12/12    V1.0        @尝试早睡
*********************************************************************************************************
*/
void InputDeviceRegister(PInputDevice ptInputDevice);


#endif /* __INPUT_SYSTEM_H */



