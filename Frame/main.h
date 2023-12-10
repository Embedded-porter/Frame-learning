#ifndef _MAIN_H_
#define _MAIN_H_

/*System header files*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <linux/input.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <config.h>

/*LEDDevice header files*/
#include "led_device.h"
#include "cal_leddevice.h"
#include "kal_leddevice.h"

/*UARTDevice header files*/
#include "uart_device.h"
#include "cal_uartdevice.h"
#include "kal_uartdevice.h"
#include "uart_ringbuffer.h"

/*KeyDevice header files*/
#include "key_device.h"
#include "cal_keydevice.h"
#include "kal_keydevice.h"

/*input system  header files*/ 
#include "input_system.h"
#include "input_buffer.h"

#endif
