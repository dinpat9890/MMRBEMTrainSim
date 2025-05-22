///
/// @file       CRC8.cpp
///
///             Implements the CRC-8-CCITT algorithm used by the CKAS V3 protocol.  
///             It uses the "least-significant bit first" format for the calculation,
///             with a reversed representation for the polynomial.
///
///             This implementation is based on the reference implementation given 
///             in Appendix A of the "CKAS Motion System Gen III ICD" (revision 1.2).
///
/// @ingroup    KSRTC Simulator
///
/// @author     Peter Byrne
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2018
///

#include "CRC8.h"

namespace crc 
{
    /// Definition for the static polynomial remainders lookup table
    const std::unique_ptr<const unsigned char[]> ccitt_8::s_remainders_table = ccitt_8::generate_remainders_table();

    /// Calculate the lookup table of the remainder of every possible byte of
    /// data.
    std::unique_ptr<const unsigned char[]> ccitt_8::generate_remainders_table() 
    {
        auto polynomial_table = new unsigned char[256]();

        for (int n = 0; n < 256; n++) 
        {
            unsigned char c8 = n;
            for (auto i = 8; i > 0; i--) 
            {
                if (c8 & 1) 
                {
                    c8 = (c8 >> 1) ^ s_poly;
                } else 
                {
                    c8 >>= 1;
                }
            }
            polynomial_table[n] = c8;
        }
    
        // Return the calculated table, but now each element can be 'const' so we change 
        // the type accordingly.  So we first cast the array as a pointer-to-const and 
        // then return a unique_ptr from that.

        auto const_table = static_cast<const unsigned char*>( polynomial_table );
    
        return std::unique_ptr<const unsigned char[]>( const_table );
    }


    /// Calculate the CRC from the first len bytes of the buffer 'buf'.
    ///
    /// Because we are using a bare pointer the algorithm cannot know if
    /// the data actually contains len bytes.
    unsigned int ccitt_8::calculate (const unsigned char * const buf, unsigned int len) 
    {
        auto crc = s_init;

        for (auto i = 0u; i < len; i++) 
        {
            auto next_byte = buf[i];
            crc = s_remainders_table [crc ^ next_byte];
        }

        return crc ^ s_post;
    }
}