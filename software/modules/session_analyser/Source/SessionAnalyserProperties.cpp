///
/// @file       SessionAnalyserProperties.h
///
///             Defines the SessionAnalyserProperties class which provides consistent access to
///             properties.
///
/// @ingroup    Core Train Sim
///
/// @author     Dijon Page
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2009
///

#include "SessionAnalyserProperties.h"

namespace
{
    const std::string SESSION_ANALYSER_SECTION              = "Session Analyser";

    const std::string DEFAULT_SPEED_LIMIT_KEY               = "Default Speed Limit";
    const double      DEFAULT_DEFAULT_SPEED_LIMIT           = 27.778; // m/s (100 kph)

    const std::string SOLAR_ELEVATION_DAY_KEY               = "Solar Elevation Day";
    const double      SOLAR_ELEVATION_DAY_DEFAULT           = 0.34; // radians

    const std::string SOLAR_ELEVATION_NIGHT_KEY             = "Solar Elevation Night";
    const double      SOLAR_ELEVATION_NIGHT_DEFAULT         = 0.00; // radians

    const std::string INFRACTION_IGNORE_TIME_KEY            = "Infraction Ignore Time";
    const double      INFRACTION_IGNORE_TIME_DEFAULT        = 5.0; // seconds

    const std::string WHISTLE_BOARD_NAME_KEY                = "Whistle Board Feature";
    const std::string WHISTLE_BOARD_NAME_DEFAULT            = "Whistle Board";

    const std::string  TUNNEL_REGION_NAME_KEY               = "Tunnel Region Feature";
    const std::string  TUNNEL_REGION_NAME_DEFAULT           = "Tunnel";

    const std::string TOWN_REGION_NAME_KEY                  = "Town Region Feature";
    const std::string TOWN_REGION_NAME_DEFAULT              = "Town Region";

    const std::string SAVE_COMMAND_KEY                      = "Save Command";

    const std::string RULE_CONFIG_SECTION_BASE              = "RuleConfig";
    const std::string RULE_KEY_BASE                         = "Rule.";
    const std::string CARCONFIG_CLASS_KEY_BASE              = "CarConfig.CarClass.";
    const std::string CARCONFIG_HUB_MODE_KEY_BASE           = "CarConfig.HubMode.";

    const std::string INFRACTION_RULES_SECTION              = "Infraction Rules";
    const std::string INFRACTION_MONITORING_DELAY_KEY       = "InfractionMonitorDelayFromSystemStart";
    const double      INFRACTION_MONITORING_DELAY_DEFAULT   = 1; // seconds
}

namespace Project
{

/// Extracts the SaveCommand from the properties file. There is no default, so will throw an
/// exception if the property was not found.
///
/// @return The save command.

std::string SessionAnalyserProperties::GetSaveCommand() const
{
    return m_properties.GetProperty<std::string>(SESSION_ANALYSER_SECTION, SAVE_COMMAND_KEY);
}

/// Returns a vector of strings that represent the names of infraction rules associated with the
/// supplied car class/hub mode pair.
///
/// @param car_class  The car class to retrieve the infraction rules for.
/// @param hub_mode   The hub mode of the car_class to retrieve infraction rules for.
///
/// @return The list of active infraction rules applicable to the given car class in the given mode.

std::vector<std::string> SessionAnalyserProperties::GetActiveInfractionRules(const std::string &car_class, const std::string &hub_mode) const
{
    // We need to run through the configuration file to find the configuration that matches the 
    // car_class and hub_mode that we have been given. We'll throw an exception if there wasn't
    // a matching configuration found.

    // The configurations are found in sections that have names like [RuleConfig.1], with the
    // characters after 'RuleConfig.' just used to make the sections unique (i.e. it doesn't
    // matter what in particular is in them). The car class and hub mode configs are in pairs 
    // of keys within these sections and look like this:
    
    // CarConfig.CarClass.1 = 378A
    // CarConfig.HubMode.1  = Driver

    // The number at the end associates the two keys with each other.
    // There can be any number of these configurations per section so we'll need to
    // keep looking until we find a pair matching the values given to this function.

    // Since these car class and hub mode keys could be anywhere within the section,
    // we might as well parse the rules specified at the same time as finding the car config.

    const std::vector<std::string> &SECTIONS = m_properties.ListSections();
    for (auto &section : SECTIONS)
    {
        // We only care about the 'RuleConfig' sections here.
        if (section.find(RULE_CONFIG_SECTION_BASE) == 0)
        {
            typedef std::map<int, std::pair<std::string, std::string> > CarConfigMap;

            CarConfigMap             car_config_map;
            std::vector<std::string> rules;
            bool                     config_found = false;

            // Run through all of the keys in this section. These will either be
            // part of a configuration pair (CarConfigMap) or the name of 
            // an infraction rule.
            const std::vector<std::string> &KEYS = m_properties.ListKeys(section);
            for (const auto &key : KEYS)
            {
                if (key.find(RULE_KEY_BASE) == 0)
                {
                    // We take the string after the 'Rule.' part of the key
                    // as the name of the infraction rule. Thus we need the key
                    // to be at least one char longer than the size of 'Rule.'.
                    if (key.size() > RULE_KEY_BASE.size())
                    {
                        // The property for this key needs to be castable to
                        // a boolean. If this is 'true', we add this to the rule
                        // list.
                        if (m_properties.GetProperty<bool>(section, key, false))
                        {
                            rules.push_back(key.substr(RULE_KEY_BASE.size()));
                        }
                    }
                    else
                    {
                        Trace::g_plog->STAMP(Trace::WARN) << "[" << section << " - " << key << "] property has no infraction name." << Trace::EndLog();
                    }
                }
                else if (key.find(CARCONFIG_CLASS_KEY_BASE) == 0)
                {
                    if (key.size() > CARCONFIG_CLASS_KEY_BASE.size())
                    {
                        try
                        {
                            const std::string           &CAR_CLASS  = m_properties.GetProperty<std::string>(section, key);
                            const int                    CONFIG_NUM = Common::LexicalCast<int>(key.substr(CARCONFIG_CLASS_KEY_BASE.size()));
                            const CarConfigMap::iterator CONFIG     = car_config_map.find(CONFIG_NUM);
                            if (CONFIG != car_config_map.end())
                            {
                                // We may have just completed a carconfig pair,
                                // so test whether this is the config we are looking
                                // for. If it is, say that this section is the one
                                // we want (config_found).
                                CONFIG->second.first = CAR_CLASS;
                                if ((CAR_CLASS == car_class) && (CONFIG->second.second == hub_mode))
                                {
                                    config_found = true;
                                }
                            }
                            else
                            {
                                car_config_map.insert(std::make_pair(CONFIG_NUM, std::make_pair(CAR_CLASS, "")));
                            }
                        }
                        catch(CommonException)
                        {
                            Trace::g_plog->STAMP(Trace::WARN) << "[" << section << " - " << key << "] is not a valid CarConfig property." << Trace::EndLog();
                        }
                    }
                    else
                    {
                        Trace::g_plog->STAMP(Trace::WARN) << "[" << section << " - " << key << "] is not a valid CarConfig property." << Trace::EndLog(); 
                    }
                }
                else if (key.find(CARCONFIG_HUB_MODE_KEY_BASE) == 0)
                {
                    // We need the hub mode keys to have at least one
                    // char after the base, so that we can use it to
                    // find its partner.
                    if (key.size() > CARCONFIG_HUB_MODE_KEY_BASE.size())
                    {
                        try
                        {
                            // Either modify the existing entry if it exists
                            // or insert a new one.
                            const std::string           &HUB_MODE   = m_properties.GetProperty<std::string>(section, key);
                            const int                    CONFIG_NUM = Common::LexicalCast<int>(key.substr(CARCONFIG_HUB_MODE_KEY_BASE.size()));
                            const CarConfigMap::iterator CONFIG     = car_config_map.find(CONFIG_NUM);
                            if (CONFIG != car_config_map.end())
                            {
                                // We may have just completed a carconfig pair,
                                // so test whether this is the config we are looking
                                // for. If it is, say that this section is the one
                                // we want (config_found).
                                CONFIG->second.second = HUB_MODE;
                                if ((CONFIG->second.first == car_class) && (HUB_MODE == hub_mode))
                                {
                                    config_found = true; 
                                }
                            }
                            else
                            {
                                car_config_map.insert(std::make_pair(CONFIG_NUM, std::make_pair("", HUB_MODE))); 
                            }
                        }
                        catch(CommonException)
                        {
                            Trace::g_plog->STAMP(Trace::WARN) << "[" << section << " - " << key << "] is not a valid HubMode property." << Trace::EndLog();
                        }
                    }
                    else
                    {
                        Trace::g_plog->STAMP(Trace::WARN) << "[" << section << " - " << key << "] is not a valid HubMode property (no unique identifier)." << Trace::EndLog(); 
                    }
                }
            }

            // If this section contains the desired configuration, we want to return
            // the active infraction rules that we found in it. We also want to ensure
            // that the list of infraction rules is unique, so we need to sort the list
            // then uniqueify it before returning it.
            if (config_found)
            {
                std::sort(rules.begin(), rules.end());
                rules.erase(std::unique(rules.begin(), rules.end()), rules.end());
                return rules;
            }
        }
    }

    // No sections matched the requested hub mode and car class,
    // so we notify this by throwing an exception (we have nothing
    // worthwhile to return).
    throw CommonException(FLSTAMP, "No infraction rules found for CarClass: ") << car_class << ", HubMode: " << hub_mode << ".";
}

double SessionAnalyserProperties::GetSunElevationDay() const
{
    return m_properties.GetProperty<double>(SESSION_ANALYSER_SECTION, SOLAR_ELEVATION_DAY_KEY, SOLAR_ELEVATION_DAY_DEFAULT);
}

double SessionAnalyserProperties::GetSunElevationNight() const
{
    return m_properties.GetProperty<double>(SESSION_ANALYSER_SECTION, SOLAR_ELEVATION_NIGHT_KEY, SOLAR_ELEVATION_NIGHT_DEFAULT);
}

double SessionAnalyserProperties::GetInfractionIgnoreTime() const
{
    return m_properties.GetProperty<double>(SESSION_ANALYSER_SECTION, INFRACTION_IGNORE_TIME_KEY, INFRACTION_IGNORE_TIME_DEFAULT);
}


/// Returns the delay in start of monitoring the infraction from the session start, to ignore any infraction
/// raised due to scenario settings like train has initial velocity at the start of the scenario.
///
/// @return     Delay in seconds
double SessionAnalyserProperties::GetInfractionMonitoringDelayTime() const
{
    return m_properties.GetProperty<double>(INFRACTION_RULES_SECTION, INFRACTION_MONITORING_DELAY_KEY, INFRACTION_MONITORING_DELAY_DEFAULT);
}

std::string SessionAnalyserProperties::GetWhistleBoardFeatureName() const
{
    return m_properties.GetProperty<std::string>(SESSION_ANALYSER_SECTION, WHISTLE_BOARD_NAME_KEY, WHISTLE_BOARD_NAME_DEFAULT);
}

std::string SessionAnalyserProperties::GetTunnelRegionFeatureName() const
{
    return m_properties.GetProperty<std::string>(SESSION_ANALYSER_SECTION, TUNNEL_REGION_NAME_KEY, TUNNEL_REGION_NAME_DEFAULT);
}

std::string SessionAnalyserProperties::GetTownRegionFeatureName() const
{
    return m_properties.GetProperty<std::string>(SESSION_ANALYSER_SECTION, TOWN_REGION_NAME_KEY, TOWN_REGION_NAME_DEFAULT);
}

}
