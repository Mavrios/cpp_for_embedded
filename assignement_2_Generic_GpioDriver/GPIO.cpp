#include <iostream>
#include "ARM_GPIO.h"
#include "GPIO.hpp"

using namespace std;

void GPIO::pinMode(unsigned char Cpy_u8PinNum , unsigned char Cpy_u8PinMode)
{
    #ifdef _AVR_GPIO_H_
    AVR_pinMode(Cpy_u8PinNum , Cpy_u8PinMode);
    #endif
    #ifdef _ARM_GPIO_H_
    ARM_pinMode(Cpy_u8PinNum , Cpy_u8PinMode);
    #endif
    
}
void GPIO :: digitalwrite(unsigned char Cpy_u8PinNum , unsigned char Cpy_u8SignalType)
{
    #ifdef _AVR_GPIO_H_
    AVR_digitalWrite(Cpy_u8PinNum , Cpy_u8SignalType);
    #endif
    #ifdef _ARM_GPIO_H_
    ARM_digitalWrite(Cpy_u8PinNum , Cpy_u8SignalType);
    #endif

}
unsigned char GPIO :: digitalRead(unsigned char Cpy_u8PinNum)
{
    unsigned char Result;
    #ifdef _AVR_GPIO_H_
    Result = AVR_digitalRead(Cpy_u8PinNum);
    #endif
    #ifdef _ARM_GPIO_H_
    Result = ARM_digitalRead(Cpy_u8PinNum);
    #endif

    return Result;
}
