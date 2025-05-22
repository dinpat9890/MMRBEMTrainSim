///
/// @file       GenIIIResponses.h
///
///             Representation of the responses sent by the CKAS controller.
///
///             The syntax of the response string is defined in section 5.6 of "CKAS Motion System 
///             Gen III ICD" (revision 1.3); the set of possible responses is listed in section 5.8.
///
/// @ingroup    KSRTC Simulator
///
/// @author     Peter Byrne
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2018
///

#ifndef GENIIIRESPONSES_H
#define GENIIIRESPONSES_H

#include <array>
#include <vector>
#include <bitset>
#include <memory>
#include <string>
#include <iostream>

#include "JournalEntryBase.h"
#include "GenIIIProtocolConstants.h"

namespace ckas_interface 
{   
    ///
    /// Base class for responses returned by the CKAS controller
    class gen3_response : public journal_entry_base
    {
    protected:
        std::string       m_original_response;
        
        /// Implementation for the debug / logging output in the derived classes.
        virtual std::ostream&   format_for_logging(std::ostream& os) const = 0;

        /// Format the response for debug / logging output
        std::ostream&   format_for_output(std::ostream& os) const override
        {
            os << "RES: ";
            return format_for_logging(os);
        }

    public:
        gen3_response(const std::string &full_response)
            : m_original_response(full_response)
        {}

        /// Return the token that starts this response
        virtual const std::string token() = 0;
        
        /// Build a suitable gen3_response object that represents the received string.
        /// 
        /// @param response_string  A complete single response message sent by the CKAS, including
        ///                         the end-of-line terminator characters.
        /// @returns    Pointer to the response object.
        static std::unique_ptr<gen3_response>   parse_response(const std::string &full_response);
    };

    /// 
    /// A catch-all class for any responses from the CKAS that we haven't
    /// implemented in a concrete class of their own.
    ///
    class unimplemented_response : public gen3_response
    {
    private:
        /// The first token in the response string
        const std::string       m_response_token;

        unimplemented_response(const std::string &response_token, const std::string &full_response)
            : gen3_response(full_response),
              m_response_token(response_token)
        {}
        
        /// Implementation for the debug / logging output 
        std::ostream&       format_for_logging(std::ostream& os) const override
        {
            os << "[Unimplemented] " << m_original_response;
            return os;
        }

    public:
        /// Return the token that starts this response
        const std::string   token() { return m_response_token; }
        
        /// Helper method for creating unique_ptr to the response.
        /// 
        /// @param      full_response   The original response string from the CKAS.
        ///
        /// @returns    Pointer to the response object.
        ///
        /// @remarks Just used to keep parse_response a little tidier,
        ///          since we don't have std::make_unique.
        static std::unique_ptr<gen3_response> create(const std::string &response_token, const std::string &full_response)
        {
            return std::unique_ptr<unimplemented_response>(new unimplemented_response(response_token, full_response));
        }
    };

    ///
    /// CKAS individual motor status word, returned as part of some responses,
    /// especially the move response.  Described in section 5.8.8.1.
    ///
    struct motor_status 
    {
        
    public:
        /// Fault and general status codes as described in section 5.8.8.1.2
        ///
        /// The one byte of data is used to return either operating status or a
        /// fault code; the meaning depends on the value of the fault condition
        /// bit in the other byte.  We combine the small number of codes that
        /// we care about into this single enumeration.
        enum class status_fault_code
        {
            /// Status response.  Fault condition bit should be 0.
            status_not_enabled = 0x02,
            
            /// Status response.  Fault condition bit should be 0.
            status_enabled = 0x04,
            
            /// Fault code.  Fault condition bit should be 1.
            fault_configuration_error = 0x80,
            
            /// Fault code.  Fault condition bit should be 1; motor position 
            /// bit should also be 1.
            fault_out_of_range = 0x81,
            
            /// Fault code.  Fault condition bit should be 1.
            fault_unable_to_find_home = 0x82,

            /// Fault code.  Fault condition bit should be 1.
            fault_encoder_error = 0x83,
            
            /// Fault code.  Fault condition bit should be 1.
            fault_motor_communication_timeout = 0xA0
        };

    private:
        /// A copy of the original status word
        unsigned int        m_status_word;

        /// The low byte broken into individual bits.
        std::bitset<8>      m_status_bits;

        // Constants identifying the individual bits in the status word.
        enum status_bits
        {
            output_stage_enabled = 0,
            inverter_ready,
            data_enabled,
            reported_position_invalid,
            motor_position_error,
            fault_condition,
            motor_operational,
            hardware_park
        };

        /// The high byte interpreted as either a fault or status code.
        status_fault_code   m_status_fault_code;

        static const int low_byte_mask                 = 0x00FF;
        static const int high_byte_mask                = 0xFF00;

    public:

        motor_status(const unsigned int status_word) 
            : m_status_word(status_word),
              m_status_bits(status_word & low_byte_mask),
              m_status_fault_code(static_cast<status_fault_code> ((m_status_word & high_byte_mask) >> 8))
        {
        }
        
        /// Return the entire original status word
        unsigned int        get_status_word()               const { return m_status_word; }

        /// Return the 8 individual status bits from the lower byte
        std::bitset<8>      get_status_bits()               const { return m_status_bits; }

        /// Return the status code from the upper byte
        status_fault_code   get_status_fault_code()         const { return m_status_fault_code; }

        /// Output stage enabled (motor is powered)
        bool                get_output_stage_enabled()      const { return m_status_bits.test(output_stage_enabled);}

        /// Inverter ready
        bool                get_inverter_ready()            const { return m_status_bits.test(inverter_ready);}

        /// Data enabled; 0 here indicates that the inverter is not configured 
        /// properly
        bool                get_data_enabled()              const { return m_status_bits.test(data_enabled);}

        /// Reported position is not valid. This may happen during the home seek
        /// procedure after start-up or upon communication error with the motor.
        bool                get_reported_position_invalid() const { return m_status_bits.test(reported_position_invalid); }

        /// Motor position is not being updated due to kinematic error, or has 
        /// been restricted due to envelope protection. This flag may be raised
        /// when a position requested by the move command is beyond the physical
        /// limits of the System.
        bool                get_motor_position_error()      const { return m_status_bits.test(motor_position_error);}

        /// Fault/warning condition. If this is 1, then the status/fault code 
        /// specifies the fault code; otherwise the status/fault code is the
        /// current status code.
        bool                get_fault_condition()           const { return m_status_bits.test(fault_condition);}

        /// Motor position is in operational range. 0 here normally produces
        /// an immediate fault (fault_out_of_range), unless the motor is in a 
        /// special debug mode
        bool                get_motor_operational()         const { return m_status_bits.test(motor_operational);}

        /// Hardware park switch. The System automatically parks when this bit
        /// on unit 1 is reset to 0. On other units, this bit may be reassigned
        /// in the future
        bool                get_hardware_park()             const { return m_status_bits.test(hardware_park);}
        
        /// Checks if the status indicates an error.
        ///
        /// Because we are going to act on an error status by resetting the 
        /// controller, it is not clear if we should consider only the "fault
        /// condition" bit as an error, or also consider  bits like "position
        /// invalid" or "motor operational".  For now it's just fault condition.
        bool                is_error()                      const { return get_fault_condition(); }

        /// Formats a status word for debug output
        friend std::ostream& operator<<(std::ostream& os, const motor_status& status);
    };

    ///
    /// Normal response from the CKAS controller to a move command.  Response
    /// is defined in section 5.8.3.1.
    ///
    /// Format:  @M <x> <y> <z> <yaw> <pitch> <roll> <statuses ...> [| <crc>]
    ///
    /// This format includes the '@M' prefix and the optional checksum byte,
    /// both of which are stripped earlier in the process.  We only have to
    /// process the position, rotation and status data.
    ///
    class move_response : public gen3_response
    {
    private:
        /// Current position for the platform; all units are mm, relative to 
        /// the neutral position.
        const std::array<const float, 3>    m_platform_position;

        /// Current orientation of the platform; Euler angles in degrees around the
        /// Z, Y, and X axes respectively (i.e. yaw-pitch-roll).
        const std::array<const float, 3>    m_platform_rotation;

        /// Reported status 
        const std::vector<motor_status> m_motor_status;
        
        /// Hidden constructor.  External clients should use 'create'
        move_response(const std::string &full_response,
                      const std::array<const float, 3> &position, 
                      const std::array<const float, 3> &rotation,
                      const std::vector<motor_status> &statuses) 
            : gen3_response(full_response),
              m_platform_position(position),
              m_platform_rotation(rotation),
              m_motor_status(statuses)
        {}
        
        /// Implementation for the debug / logging output
        std::ostream&       format_for_logging(std::ostream& os) const override;

    public:
        
        /// Return the token that starts the response
        const std::string token() { return response_tokens::move_token; }

        /// Checks the status words to see if any are reporting an error
        /// condition.
        bool                is_error_response() const;

        /// 
        /// Construct a move_response out of the response string.
        ///
        /// @param parameters   The contents of the response string between the 
        ///                     response token and the optional checksum or
        ///                     comment.  So if the full response string was:
        ///
        ///     @M -0.01 0.00 2.12 0.00 3.50 0.00 447 447 447 447 447 447 |98 # some comments
        ///
        /// the parameter string will be:
        ///
        ///     -0.01 0.00 2.12 0.00 3.50 0.00 447 447 447 447 447 447
        ///
        static std::unique_ptr<move_response> create(const std::string &parameters, const std::string &full_response);
    };

    ///
    /// Response sent when the system is completely parked.  Defined in section
    /// 5.8.6.1
    ///
    /// This response may come several seconds after sending a park_command, but
    /// if it never comes then that indicates an error.  It may also be sent
    /// "unsolicited", although just what that means isn't clear.
    class parked_response : public gen3_response
    {
        // This response includes no extra data, just the string "@Parked".
    private:
        
        parked_response(const std::string &full_response)
            : gen3_response(full_response)
        {}
        
        /// Implementation for the debug / logging output
        std::ostream&       format_for_logging(std::ostream& os) const override 
        {
            os << "Platform parked";
            return os;
        }

    public:
        
        /// Return the token "Parked"
        const std::string token() { return response_tokens::parked_token; }
        
        /// Helper method for creating unique_ptr to the response.
        /// 
        /// @param      full_response   The original response string from the CKAS.
        ///
        /// @returns    Pointer to the response object.
        ///
        /// @remarks Just used to keep parse_response a little tidier,
        ///          since we don't have std::make_unique.
        static std::unique_ptr<gen3_response> create(const std::string &full_response)
        {
            return std::unique_ptr<parked_response>(new parked_response(full_response));
        }
    };

    
    ///
    /// Response reporting the controller sent a reset to the inverters. Defined
    /// in section 5.8.7.5
    ///
    class reset_response : public gen3_response
    {
    private:
        /// This response includes no extra data, just the string "@reset sent".

        reset_response(const std::string &full_response)
            : gen3_response(full_response)
        {}
        
        /// Implementation for the debug / logging output
        std::ostream&       format_for_logging(std::ostream& os) const override 
        {
            os << "Inverter reset sent";
            return os;
        }

    public:
        
        /// Return the token "reset"
        const std::string token() { return response_tokens::reset_token; }
        
        /// Helper method for creating a unique_ptr to the response.
        /// 
        /// @param      full_response   The original response string from the CKAS.
        ///
        /// @returns    Pointer to the response object.
        static std::unique_ptr<gen3_response> create(const std::string &full_response)
        {
            return std::unique_ptr<reset_response>(new reset_response(full_response));
        }
    };

    ///
    /// Error message reported by the CKAS.  Defined in section 5.8.1.1
    ///
    class error_message : public gen3_response
    {
    private:
        /// The error message sent in the response
        std::string         m_error_message;

        error_message(const std::string &message, const std::string &full_response)
            : gen3_response(full_response),
              m_error_message(message)
        {}
        
        /// Implementation for the debug / logging output 
        std::ostream&       format_for_logging(std::ostream& os) const override 
        {
            os << "Error from CKAS: " << m_error_message;
            return os;
        }

    public:
        /// Return the token "Error:"
        const std::string token() { return response_tokens::error_token; }        
        
        /// Helper method for creating unique_ptr to the response.
        /// 
        /// @param      message         The error message from the CKAS
        /// @param      full_response   The original response string from the CKAS.
        ///
        /// @returns    Pointer to the response object.
        ///
        /// @remarks Just used to keep parse_response a little tidier,
        ///          since we don't have std::make_unique.
        static std::unique_ptr<gen3_response> create(const std::string &message, const std::string &full_response)
        {
            return std::unique_ptr<error_message>(new error_message(message, full_response));
        }
    };

    ///
    /// Warning message from the CKAS.  Defined in section 5.8.1.2
    ///
    class warning_message : public gen3_response
    {
    private:
        /// The warning message sent in the response
        std::string         m_warning_message;

        warning_message(const std::string &message, const std::string &full_response) :
            gen3_response(full_response),
            m_warning_message(message)
        {}
        
        /// Implementation for the debug / logging output 
        std::ostream&       format_for_logging(std::ostream& os) const override 
        {
            os << "Warning from CKAS: " << m_warning_message;
            return os;
        }

    public:
        /// Return the token "Warning:"
        const std::string token() { return response_tokens::warning_token; }
                
        /// Helper method for creating unique_ptr to the response.
        /// 
        /// @param      message         The warning message from the CKAS
        /// @param      full_response   The original response string from the CKAS.
        ///
        /// @returns    Pointer to the response object.
        ///
        /// @remarks Just used to keep parse_response a little tidier,
        ///          since we don't have std::make_unique.
        static std::unique_ptr<gen3_response> create(const std::string &message, const std::string &full_response)
        {
            return std::unique_ptr<warning_message>(new warning_message(message, full_response));
        }
    };

    ///
    /// Information message from the CKAS.  Defined in section 5.8.1.3
    ///
    /// The message may be just a single line or (in response to commands like 
    /// "~status") part of a multiline message.  Multiline messages are ended
    /// by the line "#-" (see text_end_message).  We don't try to group consecutive
    /// messages into one large message, each line in a multiline message is
    /// returned as a separate response (since we're not trying to parse the
    /// messages anyway).
    ///
    class text_message : public gen3_response
    {
    private:
        /// The message sent in the response
        std::string         m_text_message;

        text_message(const std::string &message, const std::string &full_response) :
            gen3_response(full_response),
            m_text_message(message)
        {}
        
        /// Implementation for the debug / logging output 
        std::ostream&       format_for_logging(std::ostream& os) const override 
        {
            os << "Message: " << m_text_message;
            return os;
        }

    public:
        /// Response doesn't have a token, so return an empty string
        const std::string token() { return std::string(""); }
        
        /// Helper method for creating unique_ptr to the response.
        /// 
        /// @param      message         The message from the CKAS
        /// @param      full_response   The original response string from the CKAS.
        ///
        /// @returns    Pointer to the response object.
        ///
        /// @remarks Just used to keep parse_response a little tidier,
        ///          since we don't have std::make_unique.
        static std::unique_ptr<gen3_response> create(const std::string &message, const std::string &full_response)
        {
            return std::unique_ptr<text_message>(new text_message(message, full_response));
        }
    };

    ///
    /// End of multiline message.  Defined in section 5.8.1.4
    ///
    class text_end_message : public gen3_response
    {
        // This response includes no extra data, just the string "#-".
    private:

        text_end_message(const std::string &full_response)
            : gen3_response(full_response)
        {}
        
        /// Format the response for debug / logging output
        std::ostream&       format_for_logging(std::ostream& os) const override 
        {
            os << "[End multiline message]";
            return os;
        }

    public:
        
        /// Response doesn't have a token, but we return the string "-" which
        /// marks the end of the message.
        const std::string token() { return std::string("-"); }

                
        /// Helper method for creating unique_ptr to the response.
        /// 
        /// @param      full_response   The original response string from the CKAS.
        ///
        /// @returns    Pointer to the response object.
        ///
        /// @remarks Just used to keep parse_response a little tidier,
        ///          since we don't have std::make_unique.
        static std::unique_ptr<gen3_response> create(const std::string &full_response)
        {
            return std::unique_ptr<text_end_message>(new text_end_message(full_response));
        }
    };
};

#endif