#include "main.h"
#include "cal_keydevice.h"


/**********************************************************************
 * 函数名称： thread_function
 * 功能描述： 输入事件读取线程
 * 输入参数： 无
 * 输出参数： 
 * 返 回 值： 0-成功, 其他值-失败
 * 修改日期        版本号     修改人	      修改内容
 * -----------------------------------------------
 * 2023/11/21	     V1.0	  @尝试早睡		      创建
 ***********************************************************************/
void *thread_function(void *arg)
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
*	功能说明: 按键初始化
*	形    参: 无
*	返 回 值: 返回值1 表示按下(导通），0表示未按下（释放）
*   日期        版本号     修改人	      修改内容
*   2023/11/21   V1.0      @尝试早睡	      创建
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
    int result = pthread_create(&thread_input, NULL, thread_function, &KeyDevice->InputDeviceFd);
    if (result != 0)
    {
        perror("Thread creation failed");
        exit(-1);
    }
}