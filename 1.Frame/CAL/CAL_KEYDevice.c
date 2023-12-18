#include "main.h"
#include "cal_keydevice.h"


/*
*********************************************************************************************************
*	函 数 名: KeyProcessPthread
*	功能说明: 按键处理线程
*	形    参: 无
*	返 回 值: 无
*   日期          版本号        修改人
*   2023/12/12    V1.0        @尝试早睡
*********************************************************************************************************
*/
 static void *KeyProcessPthread(void *arg)
{
    int fd = *(int *)arg;
    struct input_event in_ev;
    while (1)
    {
        /* 循环读取数据 */
        if (sizeof(struct input_event) != read(fd, &in_ev, sizeof(struct input_event)))
        {
            perror("read error");
            exit(-1);
        }
        else
        {
            if (EV_KEY == in_ev.type)
            {
                PutInputEvent(&in_ev);
            }
        }
    }
    return NULL;
}

/*
*********************************************************************************************************
*	函 数 名: CAL_KEYDeviceInit
*	功能说明: 芯片抽象层的按键初始化函数, 芯片不一样时请修改此函数
*	形    参: 无
*	返 回 值: 无
*   日期          版本号        修改人
*   2023/12/12    V1.0        @尝试早睡
*********************************************************************************************************
*/
void CAL_KEYDeviceInit(void)
{
    pthread_t thread_input;

    PInputDevice KeyDevice = malloc(sizeof(InputDevice));
    if (KeyDevice == NULL)
    {
        perror("Memory allocation failed");
        exit(-1);
    }
    if (0 > (KeyDevice->InputDeviceFd = open(KEY_DEVICE_NAME, O_RDONLY)))
    {
        perror("open error");
        free(KeyDevice);
        close(KeyDevice->InputDeviceFd);
    }
    int result = pthread_create(&thread_input, NULL, KeyProcessPthread, &KeyDevice->InputDeviceFd);
    if (result != 0)
    {
        perror("Thread creation failed");
        exit(-1);
    }
}