#include "main.h"

void delay_ms(unsigned int milliseconds)
{
    struct timespec ts;
    ts.tv_sec = milliseconds / 1000;
    ts.tv_nsec = (milliseconds % 1000) * 1000000;
    nanosleep(&ts, NULL);
}

int main(int argc, char *argv[])
{
    struct input_event in_ev;

    ptUartMessage uart_msg3 = malloc(sizeof(UartMessage));

    memset(uart_msg3, 0, sizeof(UartMessage));

    /*获取LEDDevice*/
    PLEDDevice pLEDdevice_RED = GetLEDDevice(LED_RED);
    /*初始化 LEDDevice*/
    pLEDdevice_RED->Init(pLEDdevice_RED);

    /*初始化输入消息队列*/
    InitInputQueue();

    /* 初始化串口消息队列*/
    InitUartEvent(); 

    /*添加所有的输入设备*/
    AddInputDevices();

    /*初始化所有的输入设备 */
    InitInputDevices();

    /*获取串口设备句柄*/
    PUARTDevice pUARTDevice = GetUARTDevice("uart3");

    /*初始化串口设备*/
    pUARTDevice->Init(pUARTDevice);
    
    strcpy(uart_msg3->mbuf, "System start running");

    pUARTDevice->Send(pUARTDevice, uart_msg3, strlen(uart_msg3->mbuf));

    while (1)
    {
        if (GetInputEvent(&in_ev) == 0)
        {
            if (EV_KEY == in_ev.type)
            {
                switch (in_ev.value)
                {
                case 0:
                    printf("code<%d>: 松开\n", in_ev.code);
                    break;
                case 1:
                    printf("code<%d>: 按下\n", in_ev.code);
                    break;
                case 2:
                    printf("code<%d>: 长按\n", in_ev.code);
                    break;
                }
            }
             memset(&in_ev,0,sizeof( struct input_event));
        }

        pLEDdevice_RED->Control(pLEDdevice_RED, 1);
        delay_ms(100);
        pLEDdevice_RED->Control(pLEDdevice_RED, 0);
        delay_ms(100);
    }
    free(uart_msg3); // 在使用完后记得释放内存
}
