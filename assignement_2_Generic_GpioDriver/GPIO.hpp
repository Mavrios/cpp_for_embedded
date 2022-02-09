#ifndef _GPIO_HPP_
#define _GPIO_HPP_



class GPIO
{
    public:
        void pinMode(unsigned char Cpy_u8PinNum , unsigned char Cpy_u8PinMode);
        void digitalwrite(unsigned char Cpy_u8PinNum , unsigned char Cpy_u8SignalType);
        unsigned char digitalRead(unsigned char Cpy_u8PinNum);
};

#endif