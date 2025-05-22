// @file       InPA declaration
///
/// @author     Nand Kumar Sharma
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2020
#pragma once

#include "ICommand.h"
#include "MessageController.h"

namespace PIS
{
    namespace Interface
    {
        class InPA :
            public ICommand
        {
        public:
            void Executer(const Message& message, const std::shared_ptr<MessageController> controller) override;
        };
    }
}
