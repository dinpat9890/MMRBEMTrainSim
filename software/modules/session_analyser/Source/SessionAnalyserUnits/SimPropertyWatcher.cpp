///
/// @file       SimPropertyWatcher.cpp
///
///             Defines the SimPropertyWatcher, that transforms watching
///             of hierachical comms into a two dimensional space of
///             properties according to a scenario train
///
/// @ingroup    Integrated Scenarios, AC05-004
///
/// @author     James Errington
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2005
///
#include "SimPropertyWatcher.h"

#include "train_comms_structure/TrainObjectConstants.h"

#include <utility/Utilities.h>
#include <common/StandardLogging.h>
#include <core_data_access/SimProperty.h>
#include "project_comms_structure/ProjectObjectConstants.h"

namespace
{
    const double REQUEST_FREQUENCY = 20.0;

    std::map<std::string, SimPropertyWatcher::Group> g_object_name_to_group =
    {
        { "Train", SimPropertyWatcher::Group::TRAIN },
        { "Vehicle", SimPropertyWatcher::Group::VEHICLE },
        { "VehicleInputs", SimPropertyWatcher::Group::VEHICLE_INPUTS },
        { "VehicleOutputs", SimPropertyWatcher::Group::VEHICLE_OUTPUTS },
        { "Feature", SimPropertyWatcher::Group::FEATURE },
        { "Environment", SimPropertyWatcher::Group::ENVIRONMENT },
        { "Camera", SimPropertyWatcher::Group::CAMERA },
        { "AutoTrain", SimPropertyWatcher::Group::AUTO_TRAIN },
        { "ReferenceTrain", SimPropertyWatcher::Group::REFERENCE_TRAIN },
		{ "CBTCVehicleInputs", SimPropertyWatcher::Group::CBTC_VEHICLE_INPUTS },
		{ "CBTCVehicleOutputs", SimPropertyWatcher::Group::CBTC_VEHICLE_OUTPUTS },
		{ "CBTC Onboard Inputs", SimPropertyWatcher::Group::CBTC_ONBOARD_INPUTS },
		{ "CBTC Onboard Outputs", SimPropertyWatcher::Group::CBTC_ONBOARD_OUTPUTS },
        { "CBTC Platform Outputs", SimPropertyWatcher::Group::CBTC_PLATFORM_OUTPUTS},
        { "TCMSVehicleOutputs", SimPropertyWatcher::Group::TCMS_VEHICLE_OUTPUT}
    };
}

/// Constructor.
///
/// @param root_object  Comms root object
/// @param tpw          Train path watcher, this identifies the train

SimPropertyWatcher::SimPropertyWatcher(Comms::Object root_object)
    : m_root_object(root_object)
    , m_next_property_id(1)
	, m_stored_active_cab_index(0)// default active cab index...
{
}

/// Adds a callback for property change. This is notified when a property number changes (or is
/// found or lost). These will be called in a single threaded fashion so the client does not need
/// to handle multithreading.
///
/// @param cb  callback to add

void SimPropertyWatcher::AddPropertyChangedCallback(const PropertyNumberCallback &cb)
{
    m_callbacks.AddCallback(cb);
}

/// Sets up property IDs according to their allocation in the database
///
/// @param data_access  data access

void SimPropertyWatcher::SetPropertyIDs(Common::DataAccess &data_access)
{
    // Empty initially
    std::vector<Core::Data::SimProperty> properties;
    m_next_property_id = 1;

    try
    {
        Core::Database::SimProperty property(data_access);
        properties = property.GetAllSimProperties();
    }
    catch(CommonException &e)
    {
        e.AddStackTrace(FLSTAMP, "Getting all sim properties");
        Trace::g_plog->LogException(e);
    }

    for (const auto &property : properties)
    {
        if (const auto map_iterator{g_object_name_to_group.find(property.object_name)};map_iterator != std::cend(g_object_name_to_group))
        {
            m_properties_map[map_iterator->second].push_back(make_pair(property.property_name, property.property_id));
			//Trace::g_plog->STAMP(Trace::WARN) << "Object Name :"  <<" "<<  property.object_name << "  " << property.property_name<< Trace::EndLog();
            m_next_property_id = std::max(m_next_property_id, property.property_id);
        }
        else
        {
            Trace::g_plog->STAMP(Trace::WARN) << "Object Name '" << property.object_name << " is unknown." << Trace::EndLog();
        }
    }
}

/// Gets the property ID for a property by name in the specified group. If none is allocated, one
/// is added using m_next_property_id as an autonumber.
///
/// @param group          group, specified by an OBJECT_ constant
/// @param property_name  name of the property of an object of the group
///
/// @return Unique ID to use for this property

int SimPropertyWatcher::GetPropertyID(Group group, const std::string &property_name)
{
    std::vector<std::pair<std::string, int> > &props = m_properties_map[group];

    std::vector<std::pair<std::string, int> >::const_iterator i
        = find_if(props.begin(), props.end(),
                  [&property_name](std::pair<std::string, int>& prop) { return prop.first == property_name; });

    int property_id;
    if (i != props.end())
    {
        property_id = i->second;
    }
    else
    {
        property_id = m_next_property_id++;
        props.push_back(make_pair(property_name, property_id));
    }

    return property_id;
}

/// Sets the properties to be watched.
///
/// @param properties  properties, order does not matter

void SimPropertyWatcher::SetProperties(const std::vector<int> &properties)
{
    m_properties_requested = properties;
    sort(m_properties_requested.begin(), m_properties_requested.end());
}

/// Activates the watcher by adding callbacks for train creation and root child creation.

void SimPropertyWatcher::Start()
{
    // Feature state is a special group. A feature watcher is not used here
    // because all features are being watched and it is not necessary to track
    // geometric position or velocity. Using our own listener is also easier.
    m_root_creation_cb_id = AddCreationCallback(m_root_object, Guard([&](Comms::Object object){ ObjectCreated(object); }));
}

/// Deactivates the watcher by removing callbacks. This must only be done once the session has
/// terminated.

void SimPropertyWatcher::Stop()
{
    if (m_root_object.IsValid())
    {
        m_root_object.RemoveChildCreationListener(m_root_creation_cb_id);
    }
}

/// Initializes an object to be watched, as the specified element of a group
///
/// @param object   Object just found
/// @param group    Group the object belongs to
/// @param element  Element of the group this object is (-1 if not applicable)

void SimPropertyWatcher::PropertiesFound(Comms::Object object, Group group, int element)
{
    // Work out the events that need to be watched
    std::vector<Sim::Number::ID> events;

    const std::vector<std::pair<std::string, int> > &props = m_properties_map[group];

    for (const auto &prop : props)
    {
        if (std::binary_search(m_properties_requested.begin(), m_properties_requested.end(), prop.second))
        {
            Sim::Number::ID id = object.Numbers().Info().GetID(prop.first);

            if (id != Sim::INVALID_NUMBER)
            {
                m_object_number_property_map[object.GetID()].emplace(std::make_pair(id, PropertyDefinition(group, prop.second, element)));
                events.push_back(id);
            }
            else
            {
                // Only feedback from properties wanted, but not found. State is legitimate
                if (prop.first != "State")
                {
                    Trace::g_plog->STAMP(Trace::WARN) << "Property not found under object: " << object.GetName() << '.' << prop.first << " (" << prop.second << ")" << Trace::EndLog();
                }
            }
        }
    }

    // Start a request on each using the info
    if (!events.empty())
    {
        // Need notification of change and loss
        AddIndividualListener(object.Numbers().Store(), Guard([&](const Sim::TimedNumber &objnum){ NumberChanged(objnum); }));
        AddDestructionCallback(object, Guard([&](Comms::Object object){ ObjectDestruction(object); }));

        // Request and retrieve
        std::vector<Sim::NumberInfo> request_events;
        std::vector<Sim::Number>     retrieve_events;
        transform(events.begin(), events.end(), std::back_inserter(request_events), std::bind(&Comms::Library<Sim::Number>::GetInfo, &object.Numbers().Info(), std::placeholders::_1));
        copy(events.begin(), events.end(), back_inserter(retrieve_events));

        // Used to do a retrieve, but this requires blocking and this has been deemed no good for 
        // comms. Now we use the initial value and updates from requests.
        //object.Numbers().Store().Retrieve(retrieve_events.begin(), retrieve_events.end());
        object.Numbers().Store().Get(retrieve_events.begin(), retrieve_events.end());
        object.Numbers().Store().Request(request_events.begin(), request_events.end(), REQUEST_FREQUENCY);

        // Found with initial values
        {
            std::map<Sim::Number::ID, PropertyDefinition> &m = m_object_number_property_map[object.GetID()];

            for (const auto &retrieve_event : retrieve_events)
            {
                PropertyNumber pn;
                
                
                if (const auto map_iterator{m.find(retrieve_event.id)}; map_iterator != std::cend(m))
                {
                    const auto& property_definition{map_iterator->second};
                    pn.group_id    = property_definition.group_id;
                    pn.property_id = property_definition.property_id;
                    pn.element     = property_definition.element;
                    pn.value       = retrieve_event.value;
                    pn.reason      = PropertyNumber::Found;

                    m_callbacks.Call(pn);
                }

            }
        }
    }
}

/// Adds a child creation callback under the train for vehicles

void SimPropertyWatcher::TrainCreation(Comms::Object object)
{
    PropertiesFound(object, Group::TRAIN);

    AddCreationCallback(object, Guard([&](Comms::Object object){ ObjectCreated(object); }));
}

void SimPropertyWatcher::ObjectCreated(Comms::Object object)
{
    int class_id = Core::GetClassID(object);

    if (class_id == Core::ClassID::WORLD)
    {
        AddCreationCallback(object, Guard([&](Comms::Object object){ ObjectCreated(object); }));
    }
    else if (class_id == Train::ClassID::TRAIN)
    {
        PropertiesFound(object, Group::TRAIN);
        AddCreationCallback(object, Guard(std::bind(&SimPropertyWatcher::ObjectCreated, this, std::placeholders::_1)));
    }
    else if (class_id == Core::ClassID::FEATURES)
    {
        AddCreationCallback(object, Guard([&](Comms::Object object){ ObjectCreated(object); }));
    }
    else if (class_id == Core::ClassID::FEATURE)
    {
        try
        {
            int element = static_cast<int>(object.Numbers().Get(Core::ValueName::Feature::FEATURE_ID).value);

            PropertiesFound(object, Group::FEATURE, element);
        }
        catch(CommonException &e)
        {
            e.AddStackTrace(FLSTAMP, "Getting feature ID");
            Trace::g_plog->LogException(e);
        }
    }
    else if (class_id == Core::ClassID::ENVIRONMENT)
    {
        PropertiesFound(object, Group::ENVIRONMENT);
        Trace::GetLogger().STAMP(Trace::INFO) << "ENVIRONMENT Found ..." << Trace::EndLog();
        AddCreationCallback(object, Guard([&](Comms::Object object){ ObjectCreated(object); }));
    }

    else if (class_id == Train::ClassID::VEHICLE)
    {
        try
        {
            int element = static_cast<int>(object.Numbers().Get(Train::ValueName::Vehicle::INDEX).value);

            PropertiesFound(object, Group::VEHICLE, element);

            // VehicleInputs and VehicleOutputs are under the vehicle
            AddCreationCallback(object, Guard([&](Comms::Object object){ ObjectCreated(object); }));
        }
        catch(CommonException &e)
        {
            e.AddStackTrace(FLSTAMP, "Getting vehicle index");
            Trace::g_plog->LogException(e);
        }
    }
    else if (class_id == Train::ClassID::VEHICLE_INPUTS)
    {
        try
        {
            // Use our parent 'vehicle' object's Index as our element number.
            int element = static_cast<int>(object.GetParent().Numbers().Get(Train::ValueName::Vehicle::INDEX).value);

            PropertiesFound(object, Group::VEHICLE_INPUTS, element);
        }
        catch(CommonException &e)
        {
            e.AddStackTrace(FLSTAMP, "Getting vehicle index");    
            Trace::g_plog->LogException(e);
        }
    }
    else if (class_id == Train::ClassID::VEHICLE_OUTPUTS)
    {
        try
        {
            // Use our parent 'vehicle' object's Index as our element number.
            int element = static_cast<int>(object.GetParent().Numbers().Get(Train::ValueName::Vehicle::INDEX).value);

            PropertiesFound(object, Group::VEHICLE_OUTPUTS, element);
        }
        catch(CommonException &e)
        {
            e.AddStackTrace(FLSTAMP, "Getting vehicle index");
            Trace::g_plog->LogException(e);
        }
    }
	else if (class_id == Project::ClassID::CBTC_VEHICLE_OUTPUTS)
	{
		try
		{
			int element = static_cast<int>(object.GetParent().Numbers().Get(Train::ValueName::Vehicle::INDEX).value);

			if (m_stored_active_cab_index == element)
			{
				PropertiesFound(object, Group::CBTC_VEHICLE_OUTPUTS, element);
			}
		}
		catch (CommonException &e)
		{
			e.AddStackTrace(FLSTAMP, "Getting vehicle index");
			Trace::g_plog->LogException(e);
		}
	}
	else if (class_id == Project::ClassID::CBTC_VEHICLE_INPUTS)
	{
		try
		{
			int element = static_cast<int>(object.GetParent().Numbers().Get(Train::ValueName::Vehicle::INDEX).value);

			if (m_stored_active_cab_index == element)
			{
				PropertiesFound(object, Group::CBTC_VEHICLE_INPUTS, element);
			}
		}
		catch (CommonException &e)
		{
			e.AddStackTrace(FLSTAMP, "Getting vehicle index");
			Trace::g_plog->LogException(e);
		}
	}
	else if (class_id == Project::ClassID::CBTC_ONBOARD_OUTPUTS)
	{
		try
		{
			int element = static_cast<int>(object.GetParent().Numbers().Get(Train::ValueName::Vehicle::INDEX).value);

			if (m_stored_active_cab_index == element)
			{
				PropertiesFound(object, Group::CBTC_ONBOARD_OUTPUTS, element);
			}
		}
		catch (CommonException &e)
		{
			e.AddStackTrace(FLSTAMP, "Getting vehicle index");
			Trace::g_plog->LogException(e);
		}
	}
    else if (class_id == Project::ClassID::CBTC_PLATFORM_OUTPUTS)
    {
    try
    {
        int element = static_cast<int>(object.GetParent().Numbers().Get(Train::ValueName::Vehicle::INDEX).value);

        if (m_stored_active_cab_index == element)
        {
            PropertiesFound(object, Group::CBTC_PLATFORM_OUTPUTS, element);
        }
    }
    catch (CommonException &e)
    {
        e.AddStackTrace(FLSTAMP, "Getting vehicle index");
        Trace::g_plog->LogException(e);
    }
    }
	else if (class_id == Project::ClassID::CBTC_ONBOARD_INPUTS)
	{
	try
	{
		int element = static_cast<int>(object.GetParent().Numbers().Get(Train::ValueName::Vehicle::INDEX).value);

		if (m_stored_active_cab_index == element)
		{
			PropertiesFound(object, Group::CBTC_ONBOARD_INPUTS, element);
		}
	}
	catch (CommonException &e)
	{
		e.AddStackTrace(FLSTAMP, "Getting vehicle index");
		Trace::g_plog->LogException(e);
	}
	}
	else if (class_id == Train::ClassID::AUDIO_OUTPUT)
			{
			try
			{
				int element = static_cast<int>(object.GetParent().Numbers().Get(Train::ValueName::Vehicle::INDEX).value);

				if (m_stored_active_cab_index == element)
				{
					PropertiesFound(object, Group::VEHICLE_AUDIO_OUTPUT, element);
				}
			}
			catch (CommonException &e)
			{
				e.AddStackTrace(FLSTAMP, "Getting vehicle index");
				Trace::g_plog->LogException(e);
			}
	}
    else if (class_id == Project::ClassID::TCMS_VEHICLE_OUTPUTS)
    {
    try
    {
        int element = static_cast<int>(object.GetParent().Numbers().Get(Train::ValueName::Vehicle::INDEX).value);

        if (m_stored_active_cab_index == element)
        {
            PropertiesFound(object, Group::TCMS_VEHICLE_OUTPUT, element);
        }
    }
    catch (CommonException &e)
    {
        e.AddStackTrace(FLSTAMP, "Getting vehicle index");
        Trace::g_plog->LogException(e);
    }
    }
}

/// Cleans the object out of the live object list. Notifies callbacks that its properties have
/// been lost
///
/// @param object  Object just destroyed

void SimPropertyWatcher::ObjectDestruction(Comms::Object object)
{
    std::map<Sim::ObjectID, std::map<Sim::Number::ID, PropertyDefinition> >::iterator iter = m_object_number_property_map.find(object.GetID());

    if (iter != m_object_number_property_map.end())
    {
        {
            const std::map<Sim::Number::ID, PropertyDefinition> &ids_to_properties = iter->second;

            for (auto &id_to_property : ids_to_properties)
            {
                PropertyNumber pn;
                pn.group_id    = id_to_property.second.group_id;
                pn.property_id = id_to_property.second.property_id;
                pn.element     = id_to_property.second.element;
                pn.reason      = PropertyNumber::Lost;

                // Value is not applicable (it could be the last value in a future version)
                pn.value       = 0.0;

                m_callbacks.Call(pn);
            }
        }

        m_object_number_property_map.erase(iter);
    }
}

/// Called when a number that may be a property has changed. If it is a property, callbacks are
/// notified.

void SimPropertyWatcher::NumberChanged(const Sim::TimedNumber &objnum)
{
    const auto &ids_to_properties = m_object_number_property_map[objnum.object_id];

    // It is legitimate that the number to change is not a property as we have an AllCallbacks listener.
    std::map<Sim::Number::ID, PropertyDefinition>::const_iterator iter = ids_to_properties.find(objnum.id);
    if (iter != ids_to_properties.end())
    {
        PropertyNumber pn;
        pn.group_id    = iter->second.group_id;
        pn.property_id = iter->second.property_id;
        pn.element     = iter->second.element;
        pn.value       = objnum.value;
        pn.reason      = PropertyNumber::Changed;

        m_callbacks.Call(pn);
    }
}

void SimPropertyWatcher::SetActiveCabVehicleIndex(int vehicle_index)
{
	m_stored_active_cab_index = vehicle_index;
	/*SetFoundProperty();*/
}

int SimPropertyWatcher::GetActiveCabVehicleIndex()
{
	return m_stored_active_cab_index;
}
