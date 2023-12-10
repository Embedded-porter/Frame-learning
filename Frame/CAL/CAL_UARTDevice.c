#include "main.h"
#include "cal_uartdevice.h"

/**********************************************************************
 * 函数名称： CAL_GetBaudrate
 * 功能描述： 串口波特率设置函数
 * 输入参数： 波特率
 * 输出参数： 
 * 返 回 值： 0-成功, 其他值-失败
 * 修改日期        版本号     修改人	      修改内容
 * -----------------------------------------------
 * 2023/11/21	     V1.0	  尝试早睡		      创建
 ***********************************************************************/
speed_t CAL_GetBaudrate(int baudrate)
{
    switch (baudrate)
    {
    case 0:
        return B0;
    case 50:
        return B50;
    case 75:
        return B75;
    case 110:
        return B110;
    case 134:
        return B134;
    case 150:
        return B150;
    case 200:
        return B200;
    case 300:
        return B300;
    case 600:
        return B600;
    case 1200:
        return B1200;
    case 1800:
        return B1800;
    case 2400:
        return B2400;
    case 4800:
        return B4800;
    case 9600:
        return B9600;
    case 19200:
        return B19200;
    case 38400:
        return B38400;
    case 57600:
        return B57600;
    case 115200:
        return B115200;
    case 230400:
        return B230400;
    case 460800:
        return B460800;
    case 500000:
        return B500000;
    case 576000:
        return B576000;
    case 921600:
        return B921600;
    case 1000000:
        return B1000000;
    case 1152000:
        return B1152000;
    case 1500000:
        return B1500000;
    case 2000000:
        return B2000000;
    case 2500000:
        return B2500000;
    case 3000000:
        return B3000000;
    case 3500000:
        return B3500000;
    case 4000000:
        return B4000000;
    default:
        return -1;
    }
}

/**********************************************************************
 * 函数名称： CAL_UARTDeviceInit
 * 功能描述： 串口初始化
 * 输入参数： 串口设备结构体
 * 输出参数： 
 * 返 回 值： 0-成功, 其他值-失败
 * 修改日期        版本号     修改人	      修改内容
 * -----------------------------------------------
 * 2023/11/21	     V1.0	  @尝试早睡		      创建
 ***********************************************************************/
int CAL_UARTDeviceInit(struct UARTDevice *ptUARTDevice)
{
    struct termios tty;
    speed_t Speed;
    ptUARTDevice->SerialPortFd = open(ptUARTDevice->SerialPortPath, O_RDWR|O_NONBLOCK);
    if (ptUARTDevice->SerialPortFd < 0)
    {
        perror("open SerialPortFd");
        return -1;
    }
    Speed = CAL_GetBaudrate(ptUARTDevice->Baudrate);
    if (tcgetattr(ptUARTDevice->SerialPortFd, &tty) != 0)
    {
        perror("Error getting serial port attributes");
        return -1;
    }
    // Set serial port parameters
    cfsetospeed(&tty, Speed); // Output baud rate of
    cfsetispeed(&tty, Speed); // Input baud rate of
    tty.c_cflag &= ~PARENB;   // No parity
    tty.c_cflag &= ~CSTOPB;   // 1 stop bit
    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8;      // 8 data bits
    tty.c_cflag &= ~CRTSCTS; // Disable hardware flow control
    // Apply the configured parameters
    if (tcsetattr(ptUARTDevice->SerialPortFd, TCSANOW, &tty) != 0)
    {
        perror("Error setting serial port attributes");
        return -1;
    }
    return 0;
}
int CAL_UARTDeviceReceive(struct UARTDevice *ptUARTDevice, ptUartMessage buf, int len)
{
    int bytesRead = read(ptUARTDevice->SerialPortFd, buf, len); // 读取串口数据
    if(bytesRead != 0 )
    {
        GetUartEvent(buf);
    }
    return bytesRead;// 返回实际读取到的字节数
}
int CAL_UARTDeviceSend(struct UARTDevice *ptUARTDevice, ptUartMessage buf, int len)
{
    int bytesWritten = write(ptUARTDevice->SerialPortFd, buf, len); // 向串口写入数据
    if(bytesWritten != 0 )
    {
         PutUartEvent(buf);
    }
    return bytesWritten; // 返回实际写入的字节数
}