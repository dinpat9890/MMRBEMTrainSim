// @file       ICommand declaration
///
/// @author     Nand Kumar Sharma
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2020
#pragma once

#include "ConstantDefined.h"

namespace PIS::Announcement { class MessageController;  }

namespace PIS
{
    namespace Interface
    {
        class ICommand
        {
        public:
            virtual void Executer(const PIS::Intercom::Message& message, const std::shared_ptr<PIS::Announcement::MessageController> controller) = 0;
        };
    }
}


