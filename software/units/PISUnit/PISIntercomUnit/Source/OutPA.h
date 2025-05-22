// @file       OutPA declaration
///
/// @author     Nand Kumar Sharma
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2020
#pragma once

//#ifndef  OUT_PA_H
//#define OUT_PA_H

#include "ICommand.h"
#include "MessageController.h"

namespace PIS
{
    namespace Interface
    {
        class OutPA : public ICommand
        {
        public:
            void Executer(const Message& message, const std::shared_ptr<MessageController> controller) override;
        };
    }
}