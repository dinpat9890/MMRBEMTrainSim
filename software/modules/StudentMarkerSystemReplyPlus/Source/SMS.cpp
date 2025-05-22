///******************************************************************************
///
/// @File: SMS.cpp
///
/// @Description: main function for SMS application
/// @Reference:
///
/// @Author: Dheeraj Jha
///
/// @ Copyright: SYDAC Pty Ltd, 2015
///
///******************************************************************************

#include "SMSApplication.h"
#include "Utility/ConsoleMain.h"

namespace
{
    const char *const PROPERTIES_FILE = "StudentMarkerSystemReplyPlus.ini";
}

int main(int argc, char *argv[])
{
    return Core::ConsoleMain<SMS::SMSApplication>(PROPERTIES_FILE, argc, argv);
}
