#ifndef _AVR_GPIO_H_
#define _AVR_GPIO_H_

extern "C"
{
void AVR_pinMode(unsigned char Cpy_u8PinNum , unsigned char Cpy_u8PinMode);
void AVR_digitalWrite(unsigned char Cpy_u8PinNum , unsigned char Cpy_u8SignalType);
unsigned char AVR_digitalRead(unsigned char Cpy_u8PinNum);
}

#endif