#ifndef _GPIO_HPP_
#define _GPIO_HPP_

extern "C"
{
    extern void AVR_digitalWrite(unsigned char Cpy_u8PinNum , unsigned char Cpy_u8SignalType);
    extern unsigned char AVR_digitalRead(unsigned char Cpy_u8PinNum);
    extern void AVR_pinMode(unsigned char Cpy_u8PinNum , unsigned char Cpy_u8PinMode);
    extern void ARM_digitalWrite(unsigned char Cpy_u8PinNum , unsigned char Cpy_u8SignalType);
    extern unsigned char ARM_digitalRead(unsigned char Cpy_u8PinNum);
    extern void ARM_pinMode(unsigned char Cpy_u8PinNum , unsigned char Cpy_u8PinMode);
}


typedef enum
{
    AVR = 0,
    ARM
}Mc;


class GPIO
{
    private:
        Mc McType;
    public:
        GPIO(Mc Cpy_McType);
        void pinMode(unsigned char Cpy_u8PinNum , unsigned char Cpy_u8PinMode);
        void digitalwrite(unsigned char Cpy_u8PinNum , unsigned char Cpy_u8SignalType);
        unsigned char digitalRead(unsigned char Cpy_u8PinNum);

};

#endif