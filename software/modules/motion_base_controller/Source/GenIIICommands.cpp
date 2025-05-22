///
/// @file       GenIIICommands.cpp
///
///             Representation of the commands sent to the CKAS controller.
///
/// @ingroup    KSRTC Simulator
///
/// @author     Peter Byrne
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2018
///

#include "GenIIICommands.h"
#include "CoordinateMapper.h"
#include "CRC8.h"
#include "common/CommonExceptions.h"
#include <iomanip>
#include <algorithm>

// Is there a preferred assertion library to use?
// Good question. I'm not aware of a preference.
#include <cassert>
#include <cmath>

/// TODO - this is VC++ specific, but MSVC 2012 doesn't support std::isfinite.
/// Make this platform independent
#include <cfloat>
#define _IS_FINITE(d)       _finite(d)

namespace
{
    const auto pi = std::acos(-1.0);
    const auto rad2deg = 180.0 / pi;

    /// @param orientation
    ///        Radians of rotation around each simulator axis.
    /// @return A vector representing the manual platform rotation, in the
    ///         format required by the move command (see the Description in
    ///         section 5.7.2.1).
    inline glm::dvec3 sim_to_gen3_manual_platform_rotation(
        const glm::dvec3 &orientation)
    {
        // Switch coordinate systems, then convert from radians to degrees.
        return ckas_interface::CoordinateMapper::sim_to_gen3(orientation) * rad2deg;
    }
}

namespace ckas_interface
{
    /// Return the string that should be sent to the controller for this command,
    /// including the '~' prefix, the CRC checksum, and the terminating carriage
    /// return.
    std::string     gen3_command::format_for_transmission() const
    {
        auto command_string = format_command_string();

        auto checksum = crc::ccitt_8::calculate(command_string);

        std::stringstream output_command;
        output_command << s_command_prefix << command_string
                       << s_checksum_separator << std::setfill('0') << std::setw(2) << std::hex << checksum
                       << s_command_terminator;

        return output_command.str();
    }

    /////////////////////////////////////////////////////////////////
    //
    // class: keep_alive
    //

    namespace
    {
        /// The keep alive command is just a tilde followed by the line terminator
        static const std::string s_keep_alive_command = std::string(1, s_command_prefix) + s_command_terminator;
    }

    /// This class overrides the format_for_transmission method, so nothing
    /// should call this method.
    std::string     keep_alive::format_command_string() const
    {
        throw CommonException(FLSTAMP, "format_command_string called for a keep_alive command");
    }

    /// Return the string that should be sent to the controller for this command.
    ///
    /// @remarks
    /// Override the default behaviour, since we don't bother with the optional CRC.
    std::string     keep_alive::format_for_transmission() const
    {
        return s_keep_alive_command;
    }

    /////////////////////////////////////////////////////////////////
    //
    // class: no_op
    //

    namespace
    {
        /// The no-op command is just an empty string, not even a terminator
        static const std::string s_no_op_command = std::string();
    }

    /// This class overrides the format_for_transmission method, so nothing
    /// should call this method.
    std::string     no_op::format_command_string() const
    {
        throw CommonException(FLSTAMP, "format_command_string called for a no_op command");
    }

    /// Return the string that should be sent to the controller for this command.
    ///
    /// @remarks
    /// Override the default behaviour, since we don't send anything at all: no
    /// prefix, no CRC, not even the line terminator.
    std::string     no_op::format_for_transmission() const
    {
        return s_no_op_command;
    }


    /////////////////////////////////////////////////////////////////
    //
    // class: move_command
    //

    /// Construct from motion base parameters
    /// @warning
    /// The platform translation *must* be in millimetres, which it currently
    /// is because that's how it's written into Comms. However, this is in
    /// violation of our principle to keep Comms in SI units (which dictates
    /// metres for this value). If the values in Comms ever change to what
    /// they should be, a unit conversion will have to occur here.
    move_command::move_command(const MotionBase::Parameters &parameters)
        : m_platform_translation    (CoordinateMapper::sim_to_gen3(parameters.GetSimulatorPlatformManualPosition())),
          m_inertial_acceleration   (CoordinateMapper::sim_to_gen3(parameters.GetVehicleAcceleration())),
          m_gravity_acceleration    (CoordinateMapper::sim_to_gen3(parameters.GetVehicleGravityAccelerationProjection())),
          m_angular_velocity        (CoordinateMapper::sim_to_gen3(parameters.GetVehicleAngularVelocity())),
          m_platform_rotation       (sim_to_gen3_manual_platform_rotation(parameters.GetSimulatorPlatformManualOrientation()))
    {
        assert(parameters.IsValid());
    }


    /// Checks the parameters for the command are valid
    ///
    /// TODO - this check isn't very strong, what other checks should we be
    /// making? For example, checking the ranges of the values.
    ///
    /// @return     True if the command's parameters are valid values.
    bool            move_command::is_valid() const
    {
        return _IS_FINITE(m_platform_translation.x) &&
               _IS_FINITE(m_platform_translation.y) &&
               _IS_FINITE(m_platform_translation.z) &&
               _IS_FINITE(m_inertial_acceleration.x) &&
               _IS_FINITE(m_inertial_acceleration.y) &&
               _IS_FINITE(m_inertial_acceleration.z) &&
               _IS_FINITE(m_gravity_acceleration.x) &&
               _IS_FINITE(m_gravity_acceleration.y) &&
               _IS_FINITE(m_gravity_acceleration.z) &&
               _IS_FINITE(m_angular_velocity.x) &&
               _IS_FINITE(m_angular_velocity.y) &&
               _IS_FINITE(m_angular_velocity.z) &&
               _IS_FINITE(m_platform_rotation.x) &&
               _IS_FINITE(m_platform_rotation.y) &&
               _IS_FINITE(m_platform_rotation.z);
    }

    /// @brief  Format a move command string to transmit to the controller.
    ///
    /// Command syntax is defined in section 5.7.2.1 like so:
    ///
    ///     ~M[ <x> <y> <z> <yaw> <pitch> <roll>[ <axi> <ayi> <azi> <axg>
    ///         <ayg> <azg> <wz> <wy> <wx>]]
    ///
    /// and they provide this example
    ///
    ///     # Simulate acceleration forward with 0.1g:
    ///     ~M 0 0 0 0 0 0 0.98 0 0 0 0 9.8 0 0 0
    ///
    /// Many of the parameters are optional (a move might just have position and
    /// rotation, but no acceleration, for example) but we don't support those
    /// variations, just a command with all the parameters.
    ///
    /// The "~" prefix and the optional CRC checksum will be added by a later stage
    /// so we don't add them here.
    ///
    /// @return     A string representation of the move command
    std::string     move_command::format_command_string() const
    {
        std::stringstream output_command;

        // 6 DOF so we include all 6 kinematic parameters and the remaning 9 accelerations and angular velocity perameters.
        output_command << std::setprecision(4)
            << "M "
            << m_platform_translation.x  << " " << m_platform_translation.y  << " " << m_platform_translation.z  << " "
            << m_platform_rotation.z     << " " << m_platform_rotation.y     << " " << m_platform_rotation.x     << " "
            << m_inertial_acceleration.x << " " << m_inertial_acceleration.y << " " << m_inertial_acceleration.z << " "
            << m_gravity_acceleration.x  << " " << m_gravity_acceleration.y  << " " << m_gravity_acceleration.z  << " "
            << m_angular_velocity.x      << " " << m_angular_velocity.y      << " " << m_angular_velocity.z;

        return output_command.str();
    }

    ///
    /// Format the command data for debug output.
    std::ostream&   move_command::format_for_logging(std::ostream& os) const
    {
        auto precision = os.precision();

        os  << std::setprecision(4)
            << "Move:"
            << " Tr "  << glm::to_string(m_platform_translation)
            << " Rot " << glm::to_string(m_platform_rotation)
            << " Acc " << glm::to_string(m_inertial_acceleration)
            << " Gra " << glm::to_string(m_gravity_acceleration)
            << " Ang " << glm::to_string(m_angular_velocity)
            << std::setprecision(precision);

        return os;
    }


    /////////////////////////////////////////////////////////////////
    //
    // class: profile_command
    //

    /// Return the string that should be sent to the controller for this command.
    ///
    /// @remarks
    /// Overrides the default behaviour as the commands written in the profile
    /// include the command prefix; this just adds a checksum to the string in
    /// the profile.
    std::string     profile_command::format_for_transmission() const
    {
        unsigned int checksum;

        // Most commands from the profile include the prefix.  The CRC calculation
        // doesn't include that prefix, so skip that character if there is one.

        if (m_command_string[0] == s_command_prefix)
        {
            // If the command is just the `~` prefix (a "keep alive" message) don't bother with the checksum.
            if (m_command_string.length() == 1)
            {
                return m_command_string;
            }

            checksum = crc::ccitt_8::calculate(m_command_string.substr(1));
        }
        else
        {
            checksum = crc::ccitt_8::calculate(m_command_string);
        }

        std::stringstream output_command;
        output_command << m_command_string
                       << s_checksum_separator << std::setfill('0') << std::setw(2) << std::hex << checksum
                       << s_command_terminator;

        return output_command.str();
    }

    /// This class overrides the format_for_transmission method, so nothing
    /// should call this method.
    std::string     profile_command::format_command_string() const
    {
        throw CommonException(FLSTAMP, "format_command_string called for a profile_command");
    }
}
