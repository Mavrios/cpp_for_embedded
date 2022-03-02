#ifndef GENERIC_REGISTER_HPP
#define GENERIC_REGISTER_HPP

/*MACRO TO GET_BIT*/
#define GET_BIT(REG,Bit_NO)     ((REG>>Bit_NO)&(0x01))

/*ERROR STATUS ENUM*/
typedef enum{
    NOK=0,
    OK
}ERROR_STATUS;

/*REGISTER_PERMISSIONS*/
typedef enum{
    READ_ONLY=0,
    WRITE_ONLY,
    READ_AND_WRITE,
    RESERVED
}REGISTER_PERMISSION;


/*GENERIC REGISTER CLASS WITH TEMPELATE*/
template <class T>
class GenRegister
{
    private:
    /*REGISTER POINTER*/
        T * Register;
        /*WHOLE REGISTER PERMISSION*/
        REGISTER_PERMISSION Permission;
        /*BITS PERMISSIONS VARIABLES*/
        /*EVERY BIT IN THESE VARIABLE REPRESENT THE BIT IN REGISTER
        *i.e IF BIT (ZERO) IN REGISTER IS RESERVED BIT SO, THE (ReservedBits) VARIABLE SHOULD HAVE BIT (ZERO) SET (1) 
        */
        T WriteOnlyBits;    
        T ReadOnlyBits;
        T ReservedBits;
    public:
        /*CONSTRUCTOR*/
        GenRegister(T * Register , REGISTER_PERMISSION RegPrem = READ_AND_WRITE);
        /*APIS*/
        ERROR_STATUS    setRegisterValue   (T Value);
        ERROR_STATUS    getRegisterValue   (T & Result);
        ERROR_STATUS    setBit             (std::uint8_t BitNo);
        ERROR_STATUS    clrBit             (std::uint8_t BitNo);
        ERROR_STATUS    getBit             (std::uint8_t & Result, std::uint8_t BitNo);
        ERROR_STATUS    setPermission      (REGISTER_PERMISSION RegisterPrem = READ_AND_WRITE );
        ERROR_STATUS    setPermissionBit   (std::uint8_t BitNo ,REGISTER_PERMISSION RegisterPrem);
        ERROR_STATUS    setPermission      (T Mask, REGISTER_PERMISSION RegisterPrem);
};


template <class T>
GenRegister<T>::GenRegister(T *Register, REGISTER_PERMISSION RegPrem)
{
    this->Register = Register;
    Permission = RegPrem;
    WriteOnlyBits = ReadOnlyBits = ReservedBits = 0;

}

template <class T>
ERROR_STATUS GenRegister<T>::setRegisterValue(T Value)
{
    ERROR_STATUS enumError_Status = OK;
    if (Permission == READ_AND_WRITE || Permission == WRITE_ONLY)
    {
        if (Value & ReadOnlyBits || Value & ReservedBits)
        {
            enumError_Status = NOK;
        }
        else
        {
            *(this->Register) = Value;
        }
    }
    else
    {
        enumError_Status = NOK;
    }

    return enumError_Status;
}

template <class T>
ERROR_STATUS GenRegister<T>::getRegisterValue(T &Result)
{
    ERROR_STATUS enumError_Status = OK;
    if (Permission == READ_AND_WRITE || Permission == READ_ONLY)
    {
        if (WriteOnlyBits || ReservedBits)
        {
            enumError_Status = NOK;
        }
        else
        {
            Result = *(this->Register);
        }
    }
    else
    {
        enumError_Status = NOK;
    }

    return enumError_Status;
}

template <class T>
ERROR_STATUS GenRegister<T>::setBit(uint8_t BitNo)
{
    ERROR_STATUS enumError_Status = OK;
    if (Permission == READ_AND_WRITE || Permission == WRITE_ONLY)
    {
        if (GET_BIT(ReadOnlyBits, BitNo) || GET_BIT(ReservedBits, BitNo))
        {
            enumError_Status = NOK;
        }
        else
        {
            *(this->Register) |= (1 << BitNo);
        }
    }
    else
    {
        enumError_Status = NOK;
    }

    return enumError_Status;
}

template <class T>
ERROR_STATUS GenRegister<T>::clrBit(std::uint8_t BitNo)
{
    ERROR_STATUS enumError_Status = OK;
    if (Permission == READ_AND_WRITE || Permission == WRITE_ONLY)
    {
        if (GET_BIT(ReadOnlyBits, BitNo) || GET_BIT(ReservedBits, BitNo))
        {
            enumError_Status = NOK;
        }
        else
        {
            *(this->Register) &= ~(1 << BitNo);
        }
    }
    else
    {
        enumError_Status = NOK;
    }

    return enumError_Status;
}

template <class T>
ERROR_STATUS GenRegister<T>::getBit(uint8_t &Result, std::uint8_t BitNo)
{
    ERROR_STATUS enumError_Status = OK;
    if (Permission == READ_AND_WRITE || Permission == READ_ONLY)
    {
        if (GET_BIT(WriteOnlyBits, BitNo) || GET_BIT(ReservedBits, BitNo))
        {
            enumError_Status = NOK;
        }
        else
        {
            Result = (*(this->Register) >> BitNo) & (0x01);
        }
    }
    else
    {
        enumError_Status = NOK;
    }

    return enumError_Status;
}

template <class T>
ERROR_STATUS GenRegister<T>::setPermission(REGISTER_PERMISSION RegisterPrem)
{
    ERROR_STATUS enumError_Status = OK;
    Permission = RegisterPrem;

    return enumError_Status;
}

template <class T>
ERROR_STATUS GenRegister<T>::setPermissionBit(std::uint8_t BitNo, REGISTER_PERMISSION RegisterPrem)
{
    ERROR_STATUS enumError_Status = OK;
    switch (RegisterPrem)
    {
    case READ_ONLY:
        ReadOnlyBits |= (1 << BitNo);
        WriteOnlyBits &= ~(1 << BitNo);
        ReservedBits &= ~(1 << BitNo);
        break;
    case WRITE_ONLY:
        WriteOnlyBits |= (1 << BitNo);
        ReadOnlyBits &= ~(1 << BitNo);
        ReservedBits &= ~(1 << BitNo);
        break;
    case RESERVED:
        ReservedBits |= (1 << BitNo);
        WriteOnlyBits &= ~(1 << BitNo);
        ReadOnlyBits &= ~(1 << BitNo);
        break;
    case READ_AND_WRITE:
        ReservedBits &= ~(1 << BitNo);
        WriteOnlyBits &= ~(1 << BitNo);
        ReadOnlyBits &= ~(1 << BitNo);
        break;

    }

    return enumError_Status;
}

template <class T>
ERROR_STATUS GenRegister<T>::setPermission(T Mask, REGISTER_PERMISSION RegisterPrem)
{
    ERROR_STATUS enumError_Status = OK;
    switch (RegisterPrem)
    {
    case READ_ONLY:
        ReadOnlyBits = Mask;
        WriteOnlyBits &= ~(Mask);
        ReservedBits &= ~(Mask);
        break;
    case WRITE_ONLY:
        WriteOnlyBits = (Mask);
        ReadOnlyBits &= ~(Mask);
        ReservedBits &= ~(Mask);
        break;
    case RESERVED:
        ReservedBits = (Mask);
        WriteOnlyBits &= ~(Mask);
        ReadOnlyBits &= ~(Mask);
        break;
    case READ_AND_WRITE:
        ReservedBits &= ~(Mask);
        WriteOnlyBits &= ~(Mask);
        ReadOnlyBits &= ~(Mask);
        break;

    }

    return enumError_Status;
}
#endif