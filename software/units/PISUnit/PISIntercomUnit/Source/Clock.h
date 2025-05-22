/// @file TestClock.h
///
/// @author    Simon Wade (simon.wade@sydac.com.au)
/// @copyright © SYDAC Pty Ltd, 2016
#pragma once
#include "IClock.h"

namespace PIS
{
    namespace Intercom
    {
        class Clock : public Input::IClock
        {
        public:
            Clock(std::chrono::milliseconds initial_time = std::chrono::milliseconds::zero());

            std::chrono::milliseconds GetTime() override;

            void SetTime(const std::chrono::milliseconds new_time);

        private:
            std::chrono::milliseconds m_current_time;
        };
    }
}
