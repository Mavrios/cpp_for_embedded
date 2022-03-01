#include <iostream>
#include "Generic_Register.hpp"
// #include "Generic_Register.cpp" //<<<<<<
int main(void)
{
    std::uint32_t x = 0;
    std::uint8_t BitResult;
    std::uint32_t RegResult;
    ERROR_STATUS ErrorCheck = OK;
    GenRegister RegX(&x);
    ErrorCheck = RegX.setBit(0);
    if(ErrorCheck == OK)
    {
        std::cout<<"SET_BIT: X = "<<x<<std::endl;
    }
    else
    {
        std::cout<<"SET_BIT:Permission Denied"<<std::endl;
    }

    ErrorCheck = RegX.clrBit(0);
    if(ErrorCheck == OK)
    {
        std::cout<<"CLR_BIT: X = "<<x<<std::endl;
    }
    else
    {
        std::cout<<"CLR_BIT:Permission Denied"<<std::endl;
    }

    ErrorCheck = RegX.getBit(BitResult, 0);
    if(ErrorCheck == OK)
    {
        std::cout<<"GET_BIT: X = "<<(unsigned) BitResult<<std::endl;
    }
    else
    {
        std::cout<<"GET_BIT:Permission Denied"<<std::endl;
    }

    ErrorCheck = RegX.setRegisterValue(128);
    if(ErrorCheck == OK)
    {
        std::cout<<"SET_REG: X = "<<x<<std::endl;
    }
    else
    {
        std::cout<<"GET_BIT:Permission Denied"<<std::endl;
    }

    ErrorCheck = RegX.getRegisterValue(RegResult);
    if(ErrorCheck == OK)
    {
        std::cout<<"SET_REG: X = "<<x<<std::endl;
    }
    else
    {
        std::cout<<"GET_BIT:Permission Denied"<<std::endl;
    }

    ///////////////////////////////////////////////////////////////////

    RegX.setPermission(0,READ_ONLY);
    ErrorCheck = RegX.setBit(0);
    if(ErrorCheck == OK)
    {
        std::cout<<"SET_BIT: X = "<<x<<std::endl;
    }
    else
    {
        std::cout<<"SET_BIT:Permission Denied"<<std::endl;
    }

    ErrorCheck = RegX.setBit(1);
    if(ErrorCheck == OK)
    {
        std::cout<<"SET_BIT: X = "<<x<<std::endl;
    }
    else
    {
        std::cout<<"SET_BIT:Permission Denied"<<std::endl;
    }
    return 0;
}