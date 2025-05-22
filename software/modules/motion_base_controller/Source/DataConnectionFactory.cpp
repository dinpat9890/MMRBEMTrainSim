#include "DataConnectionFactory.h"

namespace
{
    #define DELIM "."

    int IsValidDigit(char *ip_str)
    {
        while (*ip_str) {
            if (*ip_str >= '0' && *ip_str <= '9')
                ++ip_str;
            else
                return 0;
        }
        return 1;
    }


    // ip_to_validate passed by value and not by reference coz of strtok
    bool IsValidIPAddress(const std::string ip_to_validate)
    {
        int  num, dots = 0;
        char *ptr;


        char *local_str = const_cast<char *>(ip_to_validate.c_str());

        if (local_str == NULL)
            return false;

        ptr = strtok(local_str, DELIM);

        if (ptr == NULL)
            return false;

        while (ptr) {

            /* after parsing string, it must contain only digits */
            if (!IsValidDigit(ptr))
                return false;

            num = atoi(ptr);

            /* check for valid IP */
            if (num >= 0 && num <= 255) {
                /* parse remaining string */
                ptr = strtok(NULL, DELIM);
                if (ptr != NULL)
                    ++dots;
            } else
                return false;
        }

        /* valid IP string must contain 3 dots */
        if (dots != 3)
            return false;


        return true;
    }
}

bool DataConnectionFactory::IsIPAddress(const std::string &ip_address)
{
    return IsValidIPAddress(ip_address);
}

