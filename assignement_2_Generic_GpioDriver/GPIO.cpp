#include <iostream>
#include "AVR_GPIO.h"
#include "ARM_GPIO.h"
#include "GPIO.hpp"

using namespace std;

GPIO::GPIO(Mc Cpy_McType)
{
    McType = Cpy_McType;
}

void GPIO::pinMode(unsigned char Cpy_u8PinNum , unsigned char Cpy_u8PinMode)
{
    switch(McType)
    {
        case AVR:
        {
            AVR_pinMode(Cpy_u8PinNum , Cpy_u8PinMode);
            break;
        }

        case ARM:
        {
            ARM_pinMode(Cpy_u8PinNum , Cpy_u8PinMode);
            break;
        }
    }
}
void GPIO :: digitalwrite(unsigned char Cpy_u8PinNum , unsigned char Cpy_u8SignalType)
{
    switch(McType)
    {
        case AVR:
        {
            AVR_digitalWrite(Cpy_u8PinNum , Cpy_u8SignalType);
            break;
        }

        case ARM:
        {
            ARM_digitalWrite(Cpy_u8PinNum , Cpy_u8SignalType);
            break;
        }
    }
}
unsigned char GPIO :: digitalRead(unsigned char Cpy_u8PinNum)
{
    unsigned char Result;
    switch(McType)
    {
        case AVR:
        {
            Result = AVR_digitalRead(Cpy_u8PinNum);
            break;
        }

        case ARM:
        {
            Result = ARM_digitalRead(Cpy_u8PinNum);
            break;
        }
    }
}
