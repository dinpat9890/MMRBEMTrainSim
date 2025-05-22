//**************************************************************************************************
//
//  File:           MotionBaseExceptions.h
//
//  Description:    Implements exceptions used by MotionBaseComms.
//
//  Reference:      AC07-015 - PPP
//
//  Author:         Dijon Page
//
//  (C) Copyright:  SYDAC Pty Ltd, 2008
//
//**************************************************************************************************

#ifndef MOTION_BASE_EXCEPTIONS_H
#define MOTION_BASE_EXCEPTIONS_H

#include "common/CommonExceptions.h"

class SocketException : public CommonException
{
public:
    SocketException() throw()
        : CommonException("Socket Error ") {}
    explicit SocketException(const char *pdesc) throw()
        : CommonException((std::string("Socket Error ") + pdesc).c_str()) {}
    SocketException(const char *pfile, int line) throw()
        : CommonException(pfile, line, "Socket Error ") {}
    SocketException(const char *pfile, int line, const char *pdesc) throw()
        : CommonException(pfile, line, (std::string("Socket Error ") + pdesc).c_str()) {}

    // Define the insertion operator so that we can use throw on the same line
    // as inserting into the exception
    template <typename T>
    SocketException &operator<<(const T &in)
    {
        static_cast<CommonException &> (*this) << in;
        return *this;
    }
};

#endif // MOTION_BASE_EXCEPTIONS_H