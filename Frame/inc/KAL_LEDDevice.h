#ifndef KAL_LEDDEVICE_H
#define KAL_LEDDEVICE_H

extern int KAL_LEDDeviceInit(struct LEDDevice *ptLEDDevice);
extern int KAL_LEDDeviceControl(struct LEDDevice *ptLEDDevice, int iStatus);
extern int KAL_LEDDeviceSetColor(struct LEDDevice *ptLEDDevice, int iR, int iG, int iB);
extern int KAL_LEDDeviceSetBrightness(struct LEDDevice *ptLEDDevice, int iBrightness);

#endif // !CAL_LEDDEVICE_H