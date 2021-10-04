#ifndef __ADC_H__
#define __ADC_H__

#include <arduino.h>

#define ADC_PIN A0
#define ADC_MAX 1024.0
#define ADC_SCALE 11
#define VOLTAGE_MAX 4200

class CBattery
{
private:
  word m_adc_val; /* 电池电压AD值 */
  float m_voltage; /* 电池电压值 */
  byte m_percentage; /* 电量百分比 */
public:
  CBattery();
  ~CBattery();
  word GetADC(void);
  float GetVoltage(void);
  byte GetPercentage(void);
};


#endif /* __ADC_H__ */
