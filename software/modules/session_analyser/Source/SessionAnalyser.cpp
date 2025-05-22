///
/// @file       SessionAnalyser.cpp
///
///             Contains the main() function for the Session Analyser Module.
///
/// @ingroup    Integrated Scenarios, AC05-004
///
/// @author     James Errington
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2005
///

#include "Utility/ConsoleMain.h"
#include "SessionAnalyserModule.h"

namespace
{
    // Some constants for easy modification
    const char *const PROPERTIES_FILE = "SessionAnalyser.ini";
}

/// The main function. Defers to ConsoleMain as this is a console application.

int main(int argc, char *argv[])
{
    return Core::ConsoleMain<SessionAnalyserModule>(PROPERTIES_FILE, argc, argv);
}

// EOF
