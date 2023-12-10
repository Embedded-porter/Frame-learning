#ifndef CAL_LEDDEVICE_H
#define CAL_LEDDEVICE_H

extern int TriggerFd,BrightnessFd;


extern int CAL_LEDDeviceInit(struct LEDDevice *ptLEDDevice);
extern int CAL_LEDDeviceControl(struct LEDDevice *ptLEDDevice, int iStatus);
extern int CAL_LEDDeviceSetColor(struct LEDDevice *ptLEDDevice, int iR, int iG, int iB);
extern int CAL_LEDDeviceSetBrightness(struct LEDDevice *ptLEDDevice, int iBrightness);

#endif // !CAL_LEDDEVICE_H