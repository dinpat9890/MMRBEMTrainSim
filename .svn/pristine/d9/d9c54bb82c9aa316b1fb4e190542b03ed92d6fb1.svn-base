///
/// @file       SimPropertyWatcher.h
///
///             Declares the SimPropertyWatcher, that transforms watching
///             of hierachical comms into a two dimensional space of
///             properties according to a scenario train
///
/// @ingroup    Integrated Scenarios, AC05-004
///
/// @author     James Errington
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2005
///
#ifndef SIM_PROPERTY_WATCHER_H
#define SIM_PROPERTY_WATCHER_H

#include "core_data_access/CoreDataAccess.h"
#include "utility/CallbackCollection.h"
#include "utility/Locking.h"
#include "sim_comms/Object.h"

#include <vector>
#include <map>
#include <set>

class SimPropertyWatcher : private Core::Locking<std::mutex>
{
public:
    enum class Group
    {
        TRAIN,
        VEHICLE,
        VEHICLE_INPUTS,
        VEHICLE_OUTPUTS,
        FEATURE,
        ENVIRONMENT,
        CAMERA,
        AUTO_TRAIN, // not watched
        REFERENCE_TRAIN,
		CBTC_VEHICLE_INPUTS,
		CBTC_VEHICLE_OUTPUTS,
		CBTC_ONBOARD_INPUTS,
		CBTC_ONBOARD_OUTPUTS,
        CBTC_PLATFORM_OUTPUTS,
		VEHICLE_AUDIO_OUTPUT,
        TCMS_VEHICLE_OUTPUT
    };

    /// A number as a property, having an ID and an element. Used in callbacks, with a reason
    /// given for the callback.
    struct PropertyNumber
    {
        Group             group_id;
        Sim::PropertyID   property_id;
        int               element;
        Sim::Number::Type value;

        enum
        {
            Found,
            Changed,
            Lost
        } reason;
    };

    typedef std::function<void(PropertyNumber)> PropertyNumberCallback;

    // Constructor
    explicit SimPropertyWatcher(Comms::Object root_object);

    // Initialization
    void SetPropertyIDs(Common::DataAccess &data_access);
    int GetPropertyID(Group group, const std::string &property_name);

    void SetProperties(const std::vector<int> &properties);

    // Callback registration
    void AddPropertyChangedCallback(const PropertyNumberCallback &cb);

    // Activation
    void Start();
    void Stop();

	// for creating reading the value of numbers under active cab need these functions...
	void SetActiveCabVehicleIndex(int);
	int  GetActiveCabVehicleIndex();

private:
    // Callbacks
    void TrainCreation(Comms::Object object);
    
    void ObjectCreated(Comms::Object object);
    void ObjectDestruction(Comms::Object object);

    void NumberChanged(const Sim::TimedNumber &objnum);

    // Helper function
    void PropertiesFound(Comms::Object object, Group group, int element = -1);

    struct PropertyDefinition
    {

        PropertyDefinition(Group group_id, int property_id, int element)
            : group_id(group_id), property_id(property_id), element(element)
        {}

        Group           group_id;
        Sim::PropertyID property_id;
        int             element;
    };

    std::map<Sim::ObjectID, std::map<Sim::Number::ID, PropertyDefinition> > m_object_number_property_map;

    // Entry to this collection will be guarded from all entry points of comms and the collection will also protect itself,
    // ie if callbacks are added at the same time
    // This will guarantee callbacks are called individually
    std::mutex                                   m_mutex;
    SafeCallbackCollection<void, PropertyNumber> m_callbacks;

private:
    Comms::Object               m_root_object;

    // Property ID allocation
    std::map<Group, std::vector<std::pair<std::string, int> > > m_properties_map;
    int m_next_property_id;

    std::vector<int> m_properties_requested;

    // Remember our root creation callback so that we can remove it
    Comms::Object::ListenerID m_root_creation_cb_id;

    // Remember our train creation callback for removal
    Comms::CallbackID m_train_creation_cb_id;

	// to hold the index of the active cab...
	int m_stored_active_cab_index;
};

#endif //SIM_PROPERTY_WATCHER_H
