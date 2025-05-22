///
/// @file       GenIIICommands.h
///
///             Representation of the commands sent to the CKAS controller.
///
/// @ingroup    KSRTC Simulator
///
/// @author     Peter Byrne
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2018
///

#ifndef GENIIICOMMANDS_H
#define GENIIICOMMANDS_H

#include <string>
#include <iostream>
#include <memory>

#include "glm\mat3x3.hpp"
#include "glm\mat4x4.hpp"
#include "glm\vec3.hpp"
#include "glm/gtx/string_cast.hpp"

#include "MotionBaseParameters.h"
#include "JournalEntryBase.h"
#include "GenIIIProtocolConstants.h"

namespace ckas_interface 
{
    ///
    /// Base class for commands to the CKAS controller using the GenIII protocol
    class gen3_command : public journal_entry_base
    {
    protected:
        /// Return the string that should be sent to the controller for this command.
        /// Should not include the "~" prefix nor the CRC check byte, each of which
        /// are added at a later stage.
        virtual std::string     format_command_string() const = 0;

        /// Implementation for the debug / logging output in the derived classes.
        virtual std::ostream&   format_for_logging(std::ostream& os) const = 0;

        /// Format the command for debug / logging output
        std::ostream&   format_for_output(std::ostream& os) const override
        {
            return format_for_logging(os);
        }

    public:
        /// Constructor
        ///
        /// @param  write_type  Defaults to EntryWriteType::TraceAndJournal, which
        ///                     is only overwritten by the no_op command.
        gen3_command(const EntryWriteType write_type = EntryWriteType::TraceAndJournal) 
            : journal_entry_base(write_type) 
        {}

        /// Return the string that should be sent to the controller for this command.
        virtual std::string format_for_transmission() const;
    };


    /// Reset the CKAS controllers timeouts that would park the platform if it
    /// gets no commands.
    class keep_alive : public gen3_command
    {
        // This command has no parameters, it doesn't even have a command string.
        // The string sent to the CKAS is just "~", which gets added by the
        // client, so we just return an empty string
        
    private:
        /// This class overrides the format_for_transmission method, so nothing
        /// should call this method.
        std::string     format_command_string() const override ;

    public:
        /// Return the string that should be sent to the controller for this command.
        /// Override the default behaviour, since it doesn't include the checksum
        std::string     format_for_transmission() const;

        /// Format the command for debug / logging output.
        std::ostream&   format_for_logging(std::ostream& os) const override
        {
            os << "Keep alive";
            return os;
        }
        
        static std::unique_ptr<gen3_command> create()
        {
            return std::unique_ptr<keep_alive>(new keep_alive());
        }
    };


    /// Represents a phase where we should send no command at all. Typically used when we detect an
    /// error and we want the platform to shutdown.
    class no_op : public gen3_command
    {
    private:
        /// This class overrides the format_for_transmission method, so nothing
        /// should call this method.  Should we throw an exception here?
        std::string     format_command_string() const override;
    
    public:
        no_op() : gen3_command(EntryWriteType::TraceOnly) {}

        /// Return an empty string. Override the default behaviour, since it is literally no command.
        std::string     format_for_transmission() const;

        /// Format the command for debug / logging output.
        std::ostream&   format_for_logging(std::ostream& os) const override
        {
            os << "[no-op] ";
            return os;
        }
        
        static std::unique_ptr<gen3_command> create()
        {
            return std::unique_ptr<no_op>(new no_op());
        }
    };


    /// Move the platform to a new position / orientation and update the dynamic 
    /// parameters.
    ///
    /// Note, this command class does not support the bare "~M" variant; that
    /// command has a separate class, "report_position".
    class move_command : public gen3_command
    {
    private:
        /// Manual translation for the platform, all units are mm, relative to 
        /// the neutral position.
        const glm::dvec3 m_platform_translation;

        /// Manual rotation of the platform; Euler angles in degrees around the
        /// Z, Y, and X axes respectively (i.e. yaw-pitch-roll).
        const glm::dvec3 m_platform_rotation;

        /// Acceleration without the gravity component in body axes; units are
        /// in m/(s^2).
        const glm::dvec3 m_inertial_acceleration;

        /// Projection of acceleration due to gravity onto body axes; units are
        /// in m/(s^2).
        const glm::dvec3 m_gravity_acceleration;

        /// Angular velocity of the body around the Z, Y, and X axes respectively
        /// (i.e. yaw-pitch-roll).  Units are in rad/s.
        const glm::dvec3 m_angular_velocity;

    protected:
        /// Return the string to send to the CKAS for this command.
        std::string     format_command_string() const override;

    public:

        /// Construct from motion base parameters
        move_command(const MotionBase::Parameters &parameters);

        /// Checks the parameters for the command are valid
        bool            is_valid() const;


        /// Format the command for debug / logging output.
        std::ostream&   format_for_logging(std::ostream& os) const override;
        
        static std::unique_ptr<gen3_command> create(const MotionBase::Parameters &parameters)
        {
            return std::unique_ptr<move_command>(new move_command(parameters));
        }
    };

    ///
    /// Request a position / status update from the CKAS controller
    class report_position : public gen3_command
    {
        /// This command has no parameters, it consists only of the command
        /// letter 'M'

    protected:
        /// Return the string to send to the CKAS for this command.
        std::string     format_command_string() const override 
        { 
            return command_tokens::move_token; 
        }

    public:

        /// Format the command for debug / logging output.
        std::ostream&   format_for_logging(std::ostream& os) const override 
        { 
            os << "Report position";
            return os;
        }
        
        static std::unique_ptr<gen3_command> create()
        {
            return std::unique_ptr<report_position>(new report_position());
        }
    };

    ///
    /// Park the platform.  Command is defined in section 5.7.4.1
    ///
    /// Note this command only supports parking the platform at the default speed
    /// 
    class park_platform : public gen3_command
    {
        /// This command has no parameters, it consists only of the command
        /// string 'park'

    protected:
        /// Return the string to send to the CKAS for this command.
        std::string     format_command_string() const override 
        { 
            return command_tokens::park_token; 
        }

    public:

        /// Format the command for debug / logging output.
        std::ostream&   format_for_logging(std::ostream& os) const override 
        { 
            os << "Park platform";
            return os;
        }
        
        static std::unique_ptr<gen3_command> create()
        {
            return std::unique_ptr<park_platform>(new park_platform());
        }
    };

    ///
    /// Reset all inverters.  Command is defined in section 5.7.5.3
    ///
    /// Note that this class only supports the command to reset all the inverters,
    /// not the variant that resets just one specific inverter.
    ///
    class reset_all_inverters : public gen3_command
    {
        /// This command has no parameters, it consists only of the command
        /// string 'reset'

    protected:
        /// Return the string to send to the CKAS for this command.
        std::string     format_command_string() const override 
        { 
            return command_tokens::reset_token; 
        }

    public:

        /// Format the command for debug / logging output.
        std::ostream&   format_for_logging(std::ostream& os) const override 
        { 
            os << "Reset all inverters";
            return os;
        }
        
        static std::unique_ptr<gen3_command> create()
        {
            return std::unique_ptr<reset_all_inverters>(new reset_all_inverters());
        }
    };

    ///
    /// Reset all inverters.  Command is defined in section 5.7.5.3
    ///
    /// Note that this class only supports the command to reset all the inverters,
    /// not the variant that resets just one specific inverter.
    ///
    class profile_command : public gen3_command
    {
    private:
        std::string     m_command_string;

    protected:
        /// This class overrides the format_for_transmission method, so nothing
        /// should call this method.  Should we throw an exception here?
        std::string     format_command_string() const override ;

    public:

        profile_command(const std::string &command) 
            : m_command_string(command)
        {
        }
        
        /// Return the string that should be sent to the controller for this command.
        /// Overrides the default behaviour as the profile commands include the 
        /// command prefix; this just adds a checksum to the string in the profile.
        std::string     format_for_transmission() const;

        /// Format the command for debug / logging output.
        std::ostream&   format_for_logging(std::ostream& os) const override 
        { 
            os << "From profile: " << m_command_string;
            return os;
        }
        
        static std::unique_ptr<gen3_command> create(const std::string &command)
        {
            return std::unique_ptr<profile_command>(new profile_command(command));
        }

    };
};

#endif