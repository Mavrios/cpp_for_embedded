#ifndef _ARM_GPIO_H_
#define _ARM_GPIO_H_

extern "C"
{
void ARM_pinMode(unsigned char Cpy_u8PinNum , unsigned char Cpy_u8PinMode);
void ARM_digitalWrite(unsigned char Cpy_u8PinNum , unsigned char Cpy_u8SignalType);
unsigned char ARM_digitalRead(unsigned char Cpy_u8PinNum);
}

#endif