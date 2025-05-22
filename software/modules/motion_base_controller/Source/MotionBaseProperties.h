///
/// @file       MotionBaseProperties.h
///
///             Declares the MotionBaseProperties class
///
/// @ingroup    Core Train Sim
///
/// @author     Andy Cooper
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2013
///

#ifndef MOTIONBASE_PROPERTIES_H
#define MOTIONBASE_PROPERTIES_H

#include "common/Properties.h"

#include <string>
#include <vector>
#include <map>

namespace Project
{
    /// Contains logic to extract a number of MotionBase-specific properties from the given property file
    class MotionBaseProperties
    {
    public:
        MotionBaseProperties(const Common::Properties &properties);

        double GetRequestFrequency() const;

        // Hardware properties
        std::string    GetDestinationAddress() const;
        unsigned short GetDestinationPort() const;
        unsigned short GetLocalPort() const;
        double         GetConnectionTimeout() const;
        double         GetPollingRate() const;

        // Dynamics properties

        double GetRollMinimum() const;
        double GetRollMaximum() const;
        double GetRollK() const;
        double GetRollDelta() const;

        double GetPitchMinimum() const;
        double GetPitchMaximum() const;
        double GetPitchK() const;
        double GetPitchDelta() const;

        // Profile properties or commands
        std::vector<std::string> GetProfileCommands() const;

        /// @return True if the controller should generate a journal.
        bool IsJournalEnabled() const;

    private:
        const Common::Properties &m_properties;
    };
}
#endif // MOTIONBASE_PROPERTIES_H
