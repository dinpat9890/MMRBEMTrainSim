#ifndef GENIII_PROTOCOL_CONSTANTS_H
#define GENIII_PROTOCOL_CONSTANTS_H

#include <string>

namespace ckas_interface
{
    static const char           s_command_terminator    = '\r';
    static const std::string    s_response_terminators  = "\r\n";
    static const char           s_command_prefix        = '~';
    static const char           s_response_prefix       = '@';
    static const char           s_checksum_separator    = '|';
    static const char           s_comment_start         = '#';
    static const std::string    s_text_end_message      = "-";
    static const std::string    s_token_separators      = " \t";
     
    namespace response_tokens 
    {
        const std::string move_token = "M";
        const std::string parked_token = "Parked";
        const std::string reset_token = "reset";
        const std::string error_token = "Error:";
        const std::string warning_token = "Warning:";
    };

    
    namespace command_tokens 
    {
        const std::string move_token = "M";
        const std::string park_token = "park";
        const std::string reset_token = "reset";
    };
};

#endif