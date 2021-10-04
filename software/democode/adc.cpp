#include "adc.h"

CBattery::CBattery()
{
	/* 初始化列表成员 */
	m_adc_val = 0;
	m_voltage = 0.0f;
	m_percentage = 100;
}

CBattery::~CBattery()
{
}

word CBattery::GetADC(void)
{
	m_adc_val = analogRead(ADC_PIN);
	return m_adc_val;
}

float CBattery::GetVoltage(void)
{
	int adc = analogRead(ADC_PIN);
	/* ADC引脚输入电压为0~1V，量化1024 */
	m_voltage = adc / ADC_MAX * ADC_SCALE - 0.12;
	return m_voltage;
}

byte CBattery::GetPercentage(void)
{
  int adc = analogRead(ADC_PIN);
	m_percentage = adc / ADC_MAX * ADC_SCALE * 1000 / VOLTAGE_MAX * 100;
  if(m_percentage >= 100)
    m_percentage = 100;
	return m_percentage;
}

