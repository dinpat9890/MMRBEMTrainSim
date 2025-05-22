///
/// @file       GenIIIResponses.cpp
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

#include "GenIIIResponses.h"
#include "GenIIIProtocolConstants.h"
#include "CRC8.h"
#include "common/CommonExceptions.h"

#include <iomanip>
#include <sstream>

namespace ckas_interface
{
    /// Build a suitable gen3_response object that represents the received string.
    ///
    /// The syntax of the response string is defined in section 5.6; the set of possible responses
    /// is listed in section 5.8.
    ///
    /// @param response_string  A complete single response message sent by the CKAS, including the 
    ///                         end-of-line terminator characters.
    ///
    /// @returns    Pointer to the response object.
    ///
    /// @remarks    This method would be cleaner if we could use std::string_view.
    std::unique_ptr<gen3_response> gen3_response::parse_response(const std::string &response_string)
    {
        // We assume that the response string we have been given ends in one of the terminator characters.
        // We also require that there is only one terminator in the string.

        if (s_response_terminators.find(response_string.back()) == std::string::npos)
        {
            std::stringstream message;
            message << "Unterminated response: '" << response_string << "'";
            throw CommonException(FLSTAMP, message.str().c_str() );
        }
        
        // We make a copy of the original response string to work on, trimming the terminator
        auto response_without_terminators = response_string;
        auto last_terminator_pos = response_without_terminators.find_last_not_of(s_response_terminators) + 1;
        response_without_terminators.erase(last_terminator_pos);

        auto response_working_copy = response_without_terminators;

        // TODO Could there be trailing spaces? do I need to trim the end of the string?

        // First, if the response starts with a '@' prefix, we trim that away.
        if (response_working_copy.front() == s_response_prefix)
        {
            response_working_copy.erase(0,1);
        }

        // Comments - see section 5.6.7
        //
        // Next, check for a '#' character.  This character marks that the
        // rest of the reply is a comment.  These are often used to send 
        // messages back to the client, like in the response to a "~status"
        // command.

        auto comment       = std::string();
        auto comment_start = response_working_copy.find(s_comment_start);

        if (std::string::npos != comment_start)
        {
            // We found the comment marker, so prune that part off of the reply.
            //
            // Typically these comments will be the ENTIRE response, so at the 
            // end of this step response_working_copy may be empty.  However, it's 
            // possible that the comment could appear part way through the
            // response, in which case we still have to parse the rest of the
            // response string.

            comment               = response_working_copy.substr(comment_start + 1);
            response_working_copy = response_working_copy.erase(comment_start);
        }

        // Checksum - see section 5.6.6
        //
        // If the response contains a "|", it must either be (a) part of a
        // comment, or (b) it marks the start of an optional checksum.  In the
        // case of a checksum, it must appear be followed by two hex digits,
        // which gives the value of the CRC checksum byte.
        //
        // These are the only times that '|' can appear in a response, so if we
        // find that marker we will assume that the next two characters must be 
        // hex digits and interpret them as such.
        //
        // If I'm wrong about that assumption, it  means that it's possible 
        // that this step could throw an std::invalid_argument exception.
        auto checksum_start = response_working_copy.find(s_checksum_separator);
        if (std::string::npos != checksum_start)
        {
            // Take the next two characters, interpret them as a checksum; check
            // it matches what we calculate for the remaining response.

            auto checksum_chars     = response_working_copy.substr(checksum_start + 1, 2);
            auto response_checksum  = std::stoi(checksum_chars, 0, 16);

            // Drop everything before the separator from the actual response.
            // Compare the calculated checksum for that response with the byte
            // we read from after the separator.

            response_working_copy = response_working_copy.erase(checksum_start);

            auto calculatedChecksum = crc::ccitt_8::calculate(response_working_copy);
            
            if (calculatedChecksum != response_checksum)
            {
                std::stringstream message;
                message << "Response failed checksum: calculated " << calculatedChecksum 
                        << ", expected " << response_checksum 
                        << " in response: " << response_without_terminators;
                throw CommonException(FLSTAMP, message.str().c_str() );
            }
        }

        // Finally, we car start looking at the content of the response to build
        // our response object.
        //
        // First, if the response_working_copy is empty, then we check the comment instead.

        if (response_working_copy.empty())
        {
            // We distinguish between text messages and a message terminator.

            if (comment == s_text_end_message)
            {
                return text_end_message::create(response_without_terminators);
            }
            
            return text_message::create(comment, response_without_terminators);
        }

        // The response string consists of a series of tokens separated by spaces
        // or tabs.  At this stage we're only interested in the first token,
        // which identifies the type of response; the remaining tokens are the
        // parameters for that response.
        auto response_token = std::string();
        auto response_parameters = std::string();

        auto token_separator_pos = response_working_copy.find_first_of(s_token_separators);
        if (std::string::npos != token_separator_pos)
        {
            response_token = response_working_copy.substr(0,token_separator_pos);
            // The parameters are everything after the separator, so start from
            // the next position.
            //
            // Strictly speaking we should handle multiple separators
            response_parameters = response_working_copy.substr(token_separator_pos + 1);
        }
        else
        {
            response_token = response_working_copy;
        }

        if (response_tokens::move_token == response_token) 
        {
            return move_response::create(response_parameters, response_without_terminators);
        }
        else if (response_tokens::parked_token == response_token)
        {
            return parked_response::create(response_without_terminators);
        }
        else if (response_tokens::error_token == response_token)
        {
            return error_message::create(response_parameters, response_without_terminators);
        }
        else if (response_tokens::warning_token == response_token)
        {
            return warning_message::create(response_parameters, response_without_terminators);
        }
        else if (response_tokens::reset_token == response_token)
        {
            return reset_response::create(response_without_terminators);
        }

        // Finally, if we got down here we don't recognise the response, so we
        // return this as an "unimplemented" response

        return unimplemented_response::create(response_token, response_without_terminators);
    }


    ///
    /// Format a status word for debug output.  For example, the status word
    /// 0x0447 will report as:
    ///
    ///     01000111 Status: Enabled
    ///
    /// whereas 0xA028 will report as:
    ///
    ///     00101000 FAULT: Motor communication timeout
    ///
    std::ostream&       operator<<(std::ostream& os, const motor_status& status)
    {
        os << status.m_status_bits << "\t";

        // For the fault or status code byte, change the output format to
        // hex.
        std::ios current_fmt(nullptr);
        current_fmt.copyfmt(os);

        os << std::hex;

        if (status.get_fault_condition()) 
        {
            os << "FAULT: x" << static_cast<int>(status.m_status_fault_code) << " ";
                
            switch(status.m_status_fault_code) 
            {
            case motor_status::status_fault_code::fault_configuration_error:
                os << "Configuration error";
                break;

            case motor_status::status_fault_code::fault_out_of_range:
                os << "Motion out of range";
                break;

            case motor_status::status_fault_code::fault_unable_to_find_home:
                os << "Unable to find home position";
                break;

            case motor_status::status_fault_code::fault_encoder_error:
                os << "Encoder error";
                break;
                
            case motor_status::status_fault_code::fault_motor_communication_timeout:
                os << "Motor communication timeout";
                break;

            default:
                os << "(unknown)";
            }
        }
        else
        {
            os << "Status: x" << static_cast<int>(status.m_status_fault_code) << " ";

            switch(status.m_status_fault_code) 
            {
            case motor_status::status_fault_code::status_not_enabled:
                os << "Not enabled";
                break;

            case motor_status::status_fault_code::status_enabled:
                os << "Enabled";
                break;
                
            default:
                os << "(unknown)";
            }
        }

        os.copyfmt(current_fmt);

        return os;
    }


    /// Parse a response to the move command.  Response syntax is defined in section
    /// 5.7.2.1 as:
    ///
    ///     @M <x> <y> <z> <yaw> <pitch> <roll> <statuses ...> 
    ///
    /// Examples:
    ///
    ///     # ~2.1 mm down, 3.5 deg nose up, all motors OK and active, 6-DOF system:
    ///
    ///     @M -0.01 0.00 2.12 0.00 3.50 0.00 447 447 447 447 447 447 |98
    ///
    ///     # Timeout (error) of all motors on a 3-DOF system:
    ///
    ///     @M NaN NaN NaN NaN NaN NaN A028 A028 A028 |0F
    ///
    /// These examples include the '@' prefix and the optional checksum byte,
    /// both of which are stripped earlier in the process.  We only have to
    /// process the position, rotation and status data.
    ///
    std::unique_ptr<move_response> move_response::create(const std::string &parameters, const std::string &full_response)
    {
        // To split the string into elements, because they are separated by spaces
        // we can use the stringstream trick to read them into a vector.
        //
        // Note the extra parenthesis in the first parameter to the constructor
        // for 'tokens'; this is to work around the "vexing parse" problem (without
        // them 'tokens' is parsed as a function not a variable; see 
        // https://en.wikipedia.org/wiki/Most_vexing_parse and thanks to Jonathan 
        // Boccara's blog for pointing this out)

        auto iss    = std::istringstream (parameters);
        auto tokens = std::vector<std::string>( (std::istream_iterator<std::string>(iss)),
                                                 std::istream_iterator<std::string>());

        // Check how many tokens we got; there should be at least 6 (for the position and rotation
        // values) and then more for the statuses. Different systems may have different numbers of
        // motors, so we can't say exactly how many status words we expect; for now we just say we
        // expect more than zero.
        //
        // TODO find a better way to propagate how many statuses to expect (ie how many degrees of freedom).
        if (tokens.size() <= 6) 
        {
            std::stringstream message;
            message << "Move response had too few tokens: expect at least 6, found " << tokens.size() << " in response: " << full_response;
            throw CommonException(FLSTAMP, message.str().c_str() );
        }

        std::array<const float, 3> positions = { std::stof(tokens[0]), std::stof(tokens[1]), std::stof(tokens[2]) };
        std::array<const float, 3> rotations = { std::stof(tokens[3]), std::stof(tokens[4]), std::stof(tokens[5]) };

        std::vector<motor_status> statuses;

        // All the tokens after the first six are status words.  Each status
        // word is 2 bytes formatted as a four hex-digit string.
        for (auto token = tokens.begin() + 6; token != tokens.end(); token++) 
        {
            // The status word tokens should be interpreted as hex, but they don't
            // have a "0x" prefix, so we have to specify the base in the parse.
            auto status_word = std::stoi(*token, 0, 16);

            // Check the status word is within our expected size.
            if (status_word > 0xFFFF) 
            {
                auto message = "Move response had a malformed motor status '" + *token + "' in response: " + full_response;
                throw CommonException(FLSTAMP, message.c_str() );
            }

            statuses.push_back(motor_status(status_word));
        }

        return std::unique_ptr<move_response>(
            new move_response(full_response, positions, rotations, statuses)
        );
    }
    

    /// 
    /// Checks if any of the status words indicate an error
    bool            move_response::is_error_response() const 
    {
        return std::any_of( m_motor_status.begin(), 
                            m_motor_status.end(), 
                            [](motor_status status){ return status.is_error(); });
    }
    
    
    ///
    /// Format the response data for debug output.
    std::ostream&   move_response::format_for_logging(std::ostream& os) const 
    {
        os << m_original_response;
        
        if (! is_error_response())
        {
            return os;
        }

        std::ios current_fmt(nullptr);
        current_fmt.copyfmt(os);

        os << std::setprecision(4);

        os << std::endl
           << "Move: " 
           << "Pos (" << m_platform_position[0] << ", " << m_platform_position[1] << ", " << m_platform_position[2] << ") "
           << "Rot (" << m_platform_rotation[0] << ", " << m_platform_rotation[1] << ", " << m_platform_rotation[2] << ") "
           << std::endl
           << "Motor status:" << std::endl
           << "#\tHMFPRDIO\tCode" << std::endl;

        int motor = 1;
        for(auto status: m_motor_status) 
        {
            os << motor << "\t" << status << std::endl;

            ++motor;
        }

        os.copyfmt(current_fmt);

        return os;
    }
}