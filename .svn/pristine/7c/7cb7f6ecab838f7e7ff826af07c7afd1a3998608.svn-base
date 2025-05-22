/// @file Publisher.h
///
/// @author    Simon Wade (simon.wade@sydac.com.au)
/// @copyright © SYDAC Pty Ltd, 2016
#pragma once
#include "SimComms/Object.h"
#include "SimComms/Gateway.h"
#include <vector>

#include <functional>

namespace Project
{
    ///
    class Publisher
    {
    public:
        /// @param
        Publisher(Comms::Gateway &gateway)
          : m_gateway(gateway)
        {
        }

        void SubmitChange(Comms::Object object,
                          const Sim::Number::ID number_id,
                          const Sim::Number::Type new_value)
        {
            m_add_requests.push_back([this, object, number_id, new_value]()
            {
                const std::lock_guard<Comms::Gateway> COMMS_LOCK(m_gateway);

                const auto current_value = object.Numbers().Store().Get(number_id).value;
                const auto value_changed = current_value != new_value;
                if(value_changed)
                    m_numbers_to_set.push_back(Sim::Number(new_value, number_id, object.GetID()));
            });
        }

        /// @brief
        /// @pre Ownership of the Comms mutex.
        void Publish()
        {
            //m_numbers_to_set.reserve(m_add_requests.size());
            for(const auto &add_request : m_add_requests)
                add_request();

            m_add_requests.clear();

            if(!m_numbers_to_set.empty())
            {
                const std::lock_guard<Comms::Gateway> COMMS_LOCK(m_gateway);
                m_gateway.SetNumbers(m_numbers_to_set.data(),
                                     m_numbers_to_set.data() + m_numbers_to_set.size());
                m_numbers_to_set.clear();
            }
        }

    private:
        Publisher(const Publisher &);
        Publisher& operator=(const Publisher &);

        Comms::Gateway               &m_gateway;
        std::vector<Sim::TimedNumber> m_numbers_to_set;

        std::vector<std::function<void (void)>> m_add_requests;
    };
}