/// @file Clock.cpp
///
/// @author    Simon Wade (simon.wade@sydac.com.au)
/// @copyright © SYDAC Pty Ltd, 2016
#include "Clock.h"

using namespace PIS::Intercom;

Clock::Clock(std::chrono::milliseconds initial_time)
  : m_current_time(initial_time)
{
}

std::chrono::milliseconds Clock::GetTime()
{
    return m_current_time;
}

void Clock::SetTime(const std::chrono::milliseconds new_time)
{
    m_current_time = new_time;
}
