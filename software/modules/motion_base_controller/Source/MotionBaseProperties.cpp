///
/// @file       MotionBaseProperties.cpp
///
///             Implements the MotionBaseProperties class
///
/// @ingroup    Core Train Sim
///
/// @author     Andy Cooper
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2013
///

#include "MotionBaseProperties.h"
#include "common/Properties.h"

namespace
{
    const char *const    COMMS_SECTION             = "Comms";
    const char *const    REQUEST_FREQUENCY_KEY     = "Request Frequency";
    const double         DEFAULT_REQUEST_FREQUENCY = 0;

    // Hardware Properties
    const char *const    HARDWARE_PROPERTIES_SECTION = "Motion Base Hardware";
    const char *const    DESTINATION_ADDR_KEY        = "Destination Address";
    const char *const    DESTINATION_PORT_KEY        = "Destination Port";
    const char *const    LOCAL_PORT_KEY              = "Local Port";
    const char *const    CONN_TIMEOUT_KEY            = "Connection Timeout";
    const char *const    POLLING_RATE_KEY            = "Polling Rate";

    const char *const    DEFAULT_DEST_ADDRESS        = "localhost";
    const unsigned short DEFAULT_DEST_PORT           = 1254;
    const unsigned short DEFAULT_LOCAL_PORT          = 1354;
    const double         DEFAULT_CONN_TIMEOUT        = 10.0;  // seconds
    const double         DEFAULT_POLLING_RATE        = 100.0; // Hertz

    /// Roll Limits Properties
    const char *const    ROLL_PROPERTIES_SECTION     = "Roll Limits";

    /// Roll Limits Properties
    const char *const    PITCH_PROPERTIES_SECTION    = "Pitch Limits";

    /// Common limits Keys
    const char *const    MIN_KEY                     = "Minimum Degrees";
    const char *const    MAX_KEY                     = "Maximum Degrees";
    const char *const    RATE_CONSTANT_KEY           = "Rate Limit Constant";
    const char *const    DELTA_KEY                   = "Rate Limit Delta";

    /// Limits Defaults
    const double         DEFAULT_MAX                 = 2.0;  // Degrees
    const double         DEFAULT_MIN                 = -2.0; // Degrees
    const double         DEFAULT_RATE_CONSTANT       = 0.8;
    const double         DEFAULT_DELTA               = 0.1;  // Degrees

    // Journal
    const auto           JOURNAL_SECTION            = "Motion Base Journal";
    const auto           ENABLE_JOURNAL_KEY         = "Enable Journal";
    const auto           DEFAULT_ENABLE_JOURNAL     = false;

    const double         DEGREESTORADIANS            = 0.0174532925;
}

namespace Project
{

    /// Constructor for the MotionBaseProperties class. Stores a reference to the given properties file and
    /// instantiates another properties class from the configuration found in the first properties.
    ///
    /// @param properties  The properties to extract configuration from.

    MotionBaseProperties::MotionBaseProperties(const Common::Properties &properties)
        : m_properties(properties)
    { }

    double MotionBaseProperties::GetRequestFrequency() const
    {
        return m_properties.GetProperty<double>(COMMS_SECTION, REQUEST_FREQUENCY_KEY, DEFAULT_REQUEST_FREQUENCY);
    }


    /// Returns a string representing the address that the motion base should
    /// be found at. This can be a string (syd-work-42 say) or an IPv4 address.
    ///
    /// @return The ip address to connect to the motion base at.

    std::string MotionBaseProperties::GetDestinationAddress() const
    {
        return m_properties.GetProperty<std::string>(HARDWARE_PROPERTIES_SECTION, DESTINATION_ADDR_KEY, DEFAULT_DEST_ADDRESS);
    }

    /// Returns the port at the address returned from the above function that
    /// we will try to connect to the motion base on.
    ///
    /// @return The port to connect to the motion base at.

    unsigned short MotionBaseProperties::GetDestinationPort() const
    {
        return m_properties.GetProperty<unsigned short>(HARDWARE_PROPERTIES_SECTION, DESTINATION_PORT_KEY, DEFAULT_DEST_PORT);
    }

    /// Returns the port that we will bind ourselves to, for the "server"
    /// part of the UDP connection.
    ///
    /// @return The port to listen to data from the motion base.

    unsigned short MotionBaseProperties::GetLocalPort() const
    {
        return m_properties.GetProperty<unsigned short>(HARDWARE_PROPERTIES_SECTION, LOCAL_PORT_KEY, DEFAULT_LOCAL_PORT);
    }

    /// Returns the timeout in seconds that we will wait before a lack of
    /// communication from the motion base means there is (probably) a problem.
    ///
    /// @return The timeout that we will use to determine problems with communication with the motion base.

    double MotionBaseProperties::GetConnectionTimeout() const
    {
        return m_properties.GetProperty<double>(HARDWARE_PROPERTIES_SECTION, CONN_TIMEOUT_KEY, DEFAULT_CONN_TIMEOUT);
    }

    /// Returns the polling rate specified in the properties file.
    ///
    /// @return The polling rate stored in the ini file - or the default if its not specified
    ///         in the properties file

    double MotionBaseProperties::GetPollingRate() const
    {
        return m_properties.GetProperty<double>(HARDWARE_PROPERTIES_SECTION, POLLING_RATE_KEY, DEFAULT_POLLING_RATE);
    }

    /// Returns the minimum roll (converted to radians) specified in the properties file.
    ///
    /// @return The minimum roll (in radians) - or the default if its not specified
    double MotionBaseProperties::GetRollMinimum() const
    {
        return DEGREESTORADIANS*m_properties.GetProperty<double>(ROLL_PROPERTIES_SECTION, MIN_KEY, DEFAULT_MIN);
    }

    /// Returns the maximum roll (converted to radians) specified in the properties file.
    ///
    /// @return The maximum roll (in radians) - or the default if its not specified
    double MotionBaseProperties::GetRollMaximum() const
    {
        return DEGREESTORADIANS*m_properties.GetProperty<double>(ROLL_PROPERTIES_SECTION, MAX_KEY, DEFAULT_MAX);
    }

    /// Returns the Roll rate limit constant specified in the properties file.
    ///
    /// @return The rate limit constant - or the default if its not specified
    double MotionBaseProperties::GetRollK() const
    {
        return m_properties.GetProperty<double>(ROLL_PROPERTIES_SECTION, RATE_CONSTANT_KEY, DEFAULT_RATE_CONSTANT);
    }

    /// Returns the Roll rate limit delta (in radians) specified in the properties file.
    ///
    /// @return The rate limit delta - or the default if its not specified
    double MotionBaseProperties::GetRollDelta() const
    {
        return DEGREESTORADIANS*m_properties.GetProperty<double>(ROLL_PROPERTIES_SECTION, DELTA_KEY, DEFAULT_DELTA);
    }

        /// Returns the minimum pitch (converted to radians) specified in the properties file.
    ///
    /// @return The minimum pitch (in radians) - or the default if its not specified
    double MotionBaseProperties::GetPitchMinimum() const
    {
        return DEGREESTORADIANS*m_properties.GetProperty<double>(PITCH_PROPERTIES_SECTION, MIN_KEY, DEFAULT_MIN);
    }

    /// Returns the maximum pitch (converted to radians) specified in the properties file.
    ///
    /// @return The maximum pitch (in radians) - or the default if its not specified
    double MotionBaseProperties::GetPitchMaximum() const
    {
        return DEGREESTORADIANS*m_properties.GetProperty<double>(PITCH_PROPERTIES_SECTION, MAX_KEY, DEFAULT_MAX);
    }

    /// Returns the Pitch rate limit constant specified in the properties file.
    ///
    /// @return The rate limit constant - or the default if its not specified
    double MotionBaseProperties::GetPitchK() const
    {
        return m_properties.GetProperty<double>(PITCH_PROPERTIES_SECTION, RATE_CONSTANT_KEY, DEFAULT_RATE_CONSTANT);
    }

    /// Returns the Pitch rate limit delta (converted to radians) specified in the properties file.
    ///
    /// @return The rate limit delta - or the default if its not specified
    double MotionBaseProperties::GetPitchDelta() const
    {
        return DEGREESTORADIANS*m_properties.GetProperty<double>(PITCH_PROPERTIES_SECTION, DELTA_KEY, DEFAULT_DELTA);
    }


	/// Returns a profile command string
	///
	/// @return the string
	std::vector<std::string>    MotionBaseProperties::GetProfileCommands() const
	{
        auto commands = std::vector<std::string>();
        for (auto key: m_properties.ListKeys("Motion Base Profile")) 
        {
            auto command = m_properties.GetProperty<std::string>("Motion Base Profile", key);
            commands.push_back(command);
        }
		return commands;
	}

    bool MotionBaseProperties::IsJournalEnabled() const
    {
        return m_properties.GetProperty(JOURNAL_SECTION, ENABLE_JOURNAL_KEY, DEFAULT_ENABLE_JOURNAL);
    }
}


