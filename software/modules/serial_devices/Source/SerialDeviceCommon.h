#ifndef SERIAL_DEVICE_COMMON_H
#define SERIAL_DEVICE_COMMON_H

#include <string>
#include "sydac_common/LexicalCast.h"
#include "sim_common/DataTypes.h"
#include <algorithm>

namespace
{
    void PrintZeroNumber(int number, char *buf, size_t length)
    {
        std::string formatted_number = Sydac::LexicalCast<std::string, int>(number);
        while(formatted_number.size() > length)
        {
           *buf++ = '0';
            --length;
        }
        // If there are extra characters, the most significant are chopped off.
        copy(formatted_number.begin() + std::max<size_t>(0, length - formatted_number.size()), formatted_number.end(), buf);
    }

    inline void InsertString(char *buf, char *str)
    {
        while(*str)
            *buf++ = *str++;
    }

    template<typename T>
    bool Change(T &assigned_value, const T &value)
    {
        bool ret;
        if(ret = (value != assigned_value))
            assigned_value = value;

        return ret;
    }

    bool Change(double &assigned_value, const Sim::Number &number)
    {
        return number.id != Sim::INVALID_NUMBER && Change(assigned_value, number.value);
    }
}

#endif // SERIAL_DEVICE_COMMON_H
