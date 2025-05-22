///
/// @file       CRC8.h
///
///             Implements the CRC-8-CCITT algorithm used by the CKAS V3 protocol.  
///             See Appendix A of the "CKAS Motion System Gen III ICD" (revision 1.2).
///
/// @ingroup    KSRTC Simulator
///
/// @author     Peter Byrne
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2018
///

#ifndef CRC8_H
#define CRC8_H

#include <memory>
#include <string>


namespace crc 
{
    /// Implements the CRC-8-CCITT algorithm used by the CKAS V3 protocol.  
    /// The CKAS uses the "least-significant bit first" format for the calculation,
    /// with a reversed representation for the polynomial.
    class ccitt_8
    {
    public:

        /// Calculate the CRC from the first len bytes of the buffer 'buf'.
        ///
        /// It is the caller's responsibility to ensure that the buf actually contains
        /// 'len' bytes of data.  This method can perform no error checking on that 
        /// condition.
        ///
        /// @param buf      A pointer to the data for which we calculate the CRC
        /// @param len      The number of bytes to consider in the data.
        ///
        /// @return Single byte CRC value
        static unsigned int ccitt_8::calculate (const unsigned char * const buf, unsigned int len);
    
        /// Calculate the CRC from the first len bytes of the buffer 'buf'.
        ///
        /// Casts the 'char *' buffers commonly returned from strings into 'unsigned char *'
        /// used in the calculation.
        ///
        /// It is the caller's responsibility to ensure that the buf actually contains
        /// 'len' bytes of data.  This method can perform no error checking on that 
        /// condition.
        ///
        /// @param buf      A pointer to the data for which we calculate the CRC
        /// @param len      The number of bytes to consider in the data.
        ///
        /// @return Single byte CRC value
        static unsigned int ccitt_8::calculate (const char * const buf, unsigned int len) 
        { 
            return calculate(reinterpret_cast<const unsigned char * const>(buf), len);
        }
        
        /// Calculate the CRC from a string.
        ///
        /// @param buf      The string for which we calculate the CRC
        ///
        /// @return Single byte CRC value
        static unsigned int ccitt_8::calculate (const std::string &buf)
        {
            return calculate(buf.c_str(), buf.length());
        }

    private:
        // Lookup table used in our CRC calculation
        static const std::unique_ptr<const unsigned char[]> s_remainders_table;
        static       std::unique_ptr<const unsigned char[]> generate_remainders_table();
    
        // Constants for defining the polynomial & algorithm used in this CRC.
        //
        // As mentioned above, the CKAS uses the reversed representation for the 
        // polynomial.

        static const unsigned char s_poly = 0xE0;
        static const unsigned char s_init = 0xFF;
        static const unsigned char s_post = 0xFF;
    };

};
// TODO Check if there is already a common CRC implementation class elsewhere

#endif
