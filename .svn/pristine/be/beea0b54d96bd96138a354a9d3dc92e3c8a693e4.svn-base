///
/// @file       PSDFaultsAndEventsUnit.cpp
///
/// Unit will handle faults from Door Unit as well as scc.
/// The faults that this unit handles are:
/// Signals or events from the Train Door Unit to this unit:
/// Vehicle::CBTCVehicleOutputs: For all Vehicles.
///
///                             Door 1 Inhibited.
///                             Door 2 Inhibited.
///                             Door 3 Inhibited.
///                             Door 4 Inhibited.
///
/// Signals or events from the SCC unit:
/// Train:
///                             PSDS All Fail To Close
///                             PSDS All Fail To Open
/// Train::vehicle
///                             Door Forced Open
///                             Pram Trapped Passenger Door
///                             PSD Cannot Open Before Station
///                             PSD Cannot Open In Station
///                             PSD Cannot Close
///
/// @ingroup    PSDFaultsAndEventsUnit.dll
///
/// @author     Raghu Gandi
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2017

#include "PSDFaultsAndEventsUnit.h"
#include "project_comms_structure\FeatureConstants.h"
#include "project_comms_structure\ProjectObjectConstants.h"

#include "train_comms_structure\TrainObjectConstants.h"

#include "common\Callback.h"
#include "utility\Utilities.h"
#include <assert.h>

/// @brief Constructs PSD Faults And Events Unit.
///
/// @param gateway
/// @param data_access
/// @param simulator train id
PSDFaultsAndEventsUnit::PSDFaultsAndEventsUnit(Comms::Gateway& gateway, Common::Data::DataAccess& data_access, int train_id)
  : SessionUnit(gateway), m_psd_not_working(false)
{
    // Populate all internal structures
    PopulateInternalStructures(data_access, train_id);

    // We need a lock to access the root object
    OS::Lock<Comms::Gateway> lock(gateway);

    // Register callback for root child creation.
    AddCreationCallback(gateway.GetRootObject(), [this](Comms::Object object) { this->CommsObjectCreated(object); });

    Trace::GetLogger().STAMP(Trace::VERBOSE) << "PSDFaultsAndEventsUnit - Started" << Trace::EndLog();
}

/// @brief Destroys PSD Faults And Events Unit.
///             There is a chance that the raw pointers (that are part of m_fault_id_to_fault_info_map are poining to
///             faults which are part of input structure and that are created on stack) would be dangling pointers if
///             they are used after input structure got deleted. This is very rare scenario but possible. This scenario
///             is possible if destructor and CBTCFaultsOREventsStateChanged functions got called in parallel. So in
///             order to resolve this issue, the local lock is taken and the raw pointers are made null pointers in the
///             destructor before input structure got destroyed and the same local lock is used before checking for the
///             pointer validity and usage in CBTCFaultsOREventsStateChanged function.
///
PSDFaultsAndEventsUnit::~PSDFaultsAndEventsUnit()
{
    const std::lock_guard<std::mutex> lock(m_mutex);
    for (auto fault_id_to_fault_info : m_fault_id_to_fault_info_map)
    {
        fault_id_to_fault_info.second.fault_address = nullptr;
    }
}

/// @brief      Populate below internal structures:
///             input structure
///             output structure
///
/// @param data_access
/// @param scenario_train_id
void PSDFaultsAndEventsUnit::PopulateInternalStructures(Common::Data::DataAccess& data_access, int train_id)
{
    const std::lock_guard<std::mutex> lock(m_mutex);
    auto                              vehicles_list = Train::Database::Train(data_access).GetTrainElements(train_id);
    for (auto vehicle : vehicles_list)
    {
        // Get all vehicle indices and orientation from database and fill the structure.
        m_vehicle_index_to_fault_info_map[vehicle.position] = std::move(VehicleFaultsInfoStructure(
          InputStructure(vehicle.orientation, vehicle.class_code), OutputStructure(), VisionFaults()));
    }
}

/// @brief This function is called whenever interested object created.
///         This will also registers callback for interested comms child objects.
///
/// @param object               Comms Object
void PSDFaultsAndEventsUnit::CommsObjectCreated(Comms::Object object)
{
    int class_id = Core::GetClassID(object);

    if (class_id == Core::ClassID::WORLD)
    {
        AddCreationCallback(object, [this](Comms::Object object) { this->CommsObjectCreated(object); });
    }
    else if (class_id == Train::ClassID::TRAIN)
    {
        AddCreationCallback(object, [this](Comms::Object object) { this->CommsObjectCreated(object); });
        TrainObjectCreated(object);
    }
    else if (class_id == Train::ClassID::VEHICLE)
    {
        AddCreationCallback(object, [this](Comms::Object object) { this->CommsObjectCreated(object); });
        VehicleObjectCreated(object);
    }
    else if (class_id == Project::ClassID::CBTC_VEHICLE_OUTPUTS)
    {
        CBTCVehicleOutputsObjectCreated(object);
    }
    else if (class_id == Project::ClassID::CBTC_PLATFORM_OUTPUTS)
    {
        CBTCPlatformOutputsObjectCreated(object);
    }
    else if (class_id == Project::ClassID::CBTC_PLATFORM_INPUTS)
    {
        CBTCPlatformInputsObjectCreated(object);
    }
}

/// @brief      This function is called whenever train object is created.
/// This will listens to change in PSDs All Fail To Close faults.
/// This will attach a callback which gets called at a rate of 20 Hz whenever there is a
/// change in state of PSDs All Fail To Close.
///
/// @param object               train object
void PSDFaultsAndEventsUnit::TrainObjectCreated(Comms::Object train_object)
{

    // Following code is from Crosrail and is commented out since this fault is not currently supported in Tel Aviv
    // Code commented out rather than deleted so that it is easy to add this fault in the future.
    assert(train_object.IsValid());
    assert(Core::GetClassID(train_object) == Train::ClassID::TRAIN);

    m_train_object = train_object;

    NumberListener cbtc_faults_num_listener;
    Sim::Number    number = train_object.Numbers().Get(Project::ValueName::Train::FLT_PLATFORM_SCREEN_DOOR_NOT_WORKING);
    train_object.Numbers().Store().Request(train_object.Numbers().Info().GetInfo(number.id), REQUEST_FREQUENCY);
    cbtc_faults_num_listener.AddCallback(number, MakeCallback(&PSDFaultsAndEventsUnit::CBTCFaultsOREventsStateChanged, this));
    m_psds_not_working_num_id = number.id;
    
    number = train_object.Numbers().Get(Project::ValueName::Train::FLT_PSD_ADCL_STATUS_NOT_AVAILABLE);
    train_object.Numbers().Store().Request(train_object.Numbers().Info().GetInfo(number.id), REQUEST_FREQUENCY);
    cbtc_faults_num_listener.AddCallback(number, MakeCallback(&PSDFaultsAndEventsUnit::CBTCFaultsOREventsStateChanged, this));
    m_psds_not_working_num_id = number.id;
    
    number = train_object.Numbers().Get(Project::ValueName::Train::FLT_PSD_STATUS_UNKNOWN); // for PSD Unkown fault
    train_object.Numbers().Store().Request(train_object.Numbers().Info().GetInfo(number.id), REQUEST_FREQUENCY);
    cbtc_faults_num_listener.AddCallback(number, MakeCallback(&PSDFaultsAndEventsUnit::CBTCFaultsOREventsStateChanged, this));
    m_psds_unknown_num_id = number.id;

    number = train_object.Numbers().Get(Project::ValueName::Train::FLT_ONE_PSD_BYPASSED_AT_STATION_IN_OPEN_CONDITION); // for PSD Bypassed fault
    train_object.Numbers().Store().Request(train_object.Numbers().Info().GetInfo(number.id), REQUEST_FREQUENCY);
    cbtc_faults_num_listener.AddCallback(number, MakeCallback(&PSDFaultsAndEventsUnit::CBTCFaultsOREventsStateChanged, this));
    m_psds_unknown_num_id = number.id;
    train_object.Numbers().Store().AddListener(cbtc_faults_num_listener);
    
}

/// @brief      This function is called whenever vehicle object is created.
///             This will listens to change in below PSD faults:
///             PSD_Forced_Open
///             PSD_Cannot_Open_Before_Station
///             PSD_Cannot_Open_In_Station
///             PSD_Cannot_Close
///             This will attach a callback which gets called at a rate of 20 Hz whenever there is a
///             change in state of above faults.
///
/// @param object               vehicle object
void PSDFaultsAndEventsUnit::VehicleObjectCreated(Comms::Object vehicle_object)
{
    /*
    -- Commented out since the following faults were supported in Crossrail but are not currently supported in Tel Aviv

    assert(vehicle_object.IsValid());
    assert(Core::GetClassID(vehicle_object) == Train::ClassID::VEHICLE);

    const std::lock_guard<std::mutex>  lock(m_mutex);
    // Attach a listener and a callback to [PSDs Forced Open - Close] State change.
    // Register for PSD faults.
    auto PSD_Forced_Open_cb                = [this](Sim::Number fault_state) {
    this->CBTCFaultsOREventsStateChanged(fault_state); }; auto PSD_Cannot_Open_Before_Station_cb = [this](Sim::Number
    fault_state) { this->CBTCFaultsOREventsStateChanged(fault_state); }; auto PSD_Cannot_Open_In_Station_cb     =
    [this](Sim::Number fault_state) { this->CBTCFaultsOREventsStateChanged(fault_state); }; auto PSD_Cannot_Close_cb =
    [this](Sim::Number fault_state) { this->CBTCFaultsOREventsStateChanged(fault_state); };

    // Listener for platform input properties.
    NumberListener cbtc_faults_num_listener;
    std::map<std::string, NumberCallback> numbers;
    using namespace Project::ValueName::Vehicle;
    numbers[FLT_PSD_FORCED_OPEN]                = PSD_Forced_Open_cb;
    numbers[FLT_PSD_CANNOT_CLOSE]               = PSD_Cannot_Close_cb;
    numbers[FLT_PSD_CANNOT_OPEN_IN_STATION]     = PSD_Cannot_Open_In_Station_cb;
    numbers[FLT_PSD_CANNOT_OPEN_BEFORE_STATION] = PSD_Cannot_Open_Before_Station_cb;

    AddNumberListeners(numbers, vehicle_object, cbtc_faults_num_listener);


    // Record ids required later on
    auto PSD_Forced_Open_code_num_id                = vehicle_object.Numbers().Get(FLT_PSD_FORCED_OPEN).id;
    auto PSD_Cannot_Close_code_num_id               = vehicle_object.Numbers().Get(FLT_PSD_CANNOT_CLOSE).id;
    auto PSD_Cannot_Open_In_Station_code_num_id     = vehicle_object.Numbers().Get(FLT_PSD_CANNOT_OPEN_IN_STATION).id;
    auto PSD_Cannot_Open_Before_Station_code_num_id =
    vehicle_object.Numbers().Get(FLT_PSD_CANNOT_OPEN_BEFORE_STATION).id;

    m_vision_platform_door_1_status_code_num_id  = vehicle_object.Numbers().Get(VISION_PLATFORM_DOOR_1_STATUS).id;
    m_vision_platform_door_3_status_code_num_id  = vehicle_object.Numbers().Get(VISION_PLATFORM_DOOR_3_STATUS).id;
    m_vision_platform_door_4_status_code_num_id  = vehicle_object.Numbers().Get(VISION_PLATFORM_DOOR_4_STATUS).id;
    m_vision_platform_door_2_status_code_num_id  = vehicle_object.Numbers().Get(VISION_PLATFORM_DOOR_2_STATUS).id;

    int vehicle_index                            =
    static_cast<int>(vehicle_object.Numbers().Get(Train::ValueName::Vehicle::INDEX).value);

    //create populate vision faults structure
    VisionFaults vision_faults(ENABLED, ENABLED, vehicle_object);
    m_vehicle_index_to_fault_info_map[vehicle_index].vision_faults = vision_faults;

    auto door_forced_open               =
    &(m_vehicle_index_to_fault_info_map[vehicle_index].input_structure.door_forced_open); auto psd_cannot_close =
    &(m_vehicle_index_to_fault_info_map[vehicle_index].input_structure.psd_cannot_close); auto
    psd_cannot_open_in_station     =
    &(m_vehicle_index_to_fault_info_map[vehicle_index].input_structure.psd_cannot_open_in_station); auto
    psd_cannot_open_before_station =
    &(m_vehicle_index_to_fault_info_map[vehicle_index].input_structure.psd_cannot_open_before_station);

    //Populate object to param map
    auto vehicle_object_id = vehicle_object.GetID();

    m_fault_id_to_fault_info_map[std::make_pair(vehicle_object_id, PSD_Forced_Open_code_num_id)]                =
    FaultVehicleIndexStructure(door_forced_open, vehicle_index);
    m_fault_id_to_fault_info_map[std::make_pair(vehicle_object_id, PSD_Cannot_Close_code_num_id)]               =
    FaultVehicleIndexStructure(psd_cannot_close, vehicle_index);
    m_fault_id_to_fault_info_map[std::make_pair(vehicle_object_id, PSD_Cannot_Open_In_Station_code_num_id)]     =
    FaultVehicleIndexStructure(psd_cannot_open_in_station, vehicle_index);
    m_fault_id_to_fault_info_map[std::make_pair(vehicle_object_id, PSD_Cannot_Open_Before_Station_code_num_id)] =
    FaultVehicleIndexStructure(psd_cannot_open_before_station, vehicle_index);
    */
}

/// @brief      This function is called whenever cbtc vehicle outputs object is created.
///             This will listens to change in below door related events:
///             Door_1_Inhibited
///             Door_3_Inhibited
///             Door_4_Inhibited
///             Door_2_Inhibited
///             This will attach a callback which gets called at a rate of 20 Hz whenever there is a
///             change in state of above events.
///
/// @param object               cbtc vehicle outputs object
void PSDFaultsAndEventsUnit::CBTCVehicleOutputsObjectCreated(Comms::Object cbtc_vehicle_outputs_object)
{
    /*  assert(cbtc_vehicle_outputs_object.IsValid());
      assert(Core::GetClassID(cbtc_vehicle_outputs_object) == Project::ClassID::CBTC_VEHICLE_OUTPUTS);

      const std::lock_guard<std::mutex>  lock(m_mutex);
      // Attach a listener and a callback to Door A-F Inhibited
      // Register for PSD faults.
      auto Door_1_Inhibited_cb = [this](Sim::Number door_inhibited) {
      this->CBTCFaultsOREventsStateChanged(door_inhibited); }; auto Door_3_Inhibited_cb = [this](Sim::Number
      door_inhibited) { this->CBTCFaultsOREventsStateChanged(door_inhibited); }; auto Door_4_Inhibited_cb =
      [this](Sim::Number door_inhibited) { this->CBTCFaultsOREventsStateChanged(door_inhibited); }; auto
      Door_2_Inhibited_cb = [this](Sim::Number door_inhibited) { this->CBTCFaultsOREventsStateChanged(door_inhibited);
      };

      // Listener for platform input properties.
      NumberListener cbtc_faults_num_listener;
      std::map<std::string, NumberCallback> numbers;
      using namespace Project::ValueName::CBTCVehicleOutputs;
      numbers[DOOR_1_INHIBITED] = Door_1_Inhibited_cb;
      numbers[DOOR_3_INHIBITED] = Door_3_Inhibited_cb;
      numbers[DOOR_4_INHIBITED] = Door_4_Inhibited_cb;
      numbers[DOOR_2_INHIBITED] = Door_2_Inhibited_cb;

      AddNumberListeners(numbers, cbtc_vehicle_outputs_object, cbtc_faults_num_listener);

      //input fault codes
      //Vehicle::CBTCVehicleOutputs [Door Mode & Control Unit to CBTC Faults and Events Unit] DM&C->F&E
      auto Door_1_Inhibited_code_num_id = cbtc_vehicle_outputs_object.Numbers().Get(DOOR_1_INHIBITED).id;
      auto Door_3_Inhibited_code_num_id = cbtc_vehicle_outputs_object.Numbers().Get(DOOR_3_INHIBITED).id;
      auto Door_4_Inhibited_code_num_id = cbtc_vehicle_outputs_object.Numbers().Get(DOOR_4_INHIBITED).id;
      auto Door_2_Inhibited_code_num_id = cbtc_vehicle_outputs_object.Numbers().Get(DOOR_2_INHIBITED).id;


      int vehicle_index =
      static_cast<int>(cbtc_vehicle_outputs_object.GetParent().Numbers().Get(Train::ValueName::Vehicle::INDEX).value);

      auto door_1_inhibited = &(m_vehicle_index_to_fault_info_map[vehicle_index].input_structure.door_1_inhibited);
      auto door_3_inhibited = &(m_vehicle_index_to_fault_info_map[vehicle_index].input_structure.door_3_inhibited);
      auto door_4_inhibited = &(m_vehicle_index_to_fault_info_map[vehicle_index].input_structure.door_4_inhibited);
      auto door_2_inhibited = &(m_vehicle_index_to_fault_info_map[vehicle_index].input_structure.door_2_inhibited);

      //Populate object to param map
      auto cbtc_vehicle_outputs_object_id = cbtc_vehicle_outputs_object.GetID();

      m_fault_id_to_fault_info_map[std::make_pair(cbtc_vehicle_outputs_object_id, Door_1_Inhibited_code_num_id)] =
      std::move(FaultVehicleIndexStructure(door_1_inhibited, vehicle_index));
      m_fault_id_to_fault_info_map[std::make_pair(cbtc_vehicle_outputs_object_id, Door_3_Inhibited_code_num_id)] =
      std::move(FaultVehicleIndexStructure(door_3_inhibited, vehicle_index));
      m_fault_id_to_fault_info_map[std::make_pair(cbtc_vehicle_outputs_object_id, Door_4_Inhibited_code_num_id)] =
      std::move(FaultVehicleIndexStructure(door_4_inhibited, vehicle_index));
      m_fault_id_to_fault_info_map[std::make_pair(cbtc_vehicle_outputs_object_id, Door_2_Inhibited_code_num_id)] =
      std::move(FaultVehicleIndexStructure(door_2_inhibited, vehicle_index));*/
}

/// @brief      This function is called whenever cbtc platform outputs object is created.
///             This will listens for changes the following events:
///                 PSD Door Status
///
/// @param cbtc_platform_outputs_object cbtc platform outputs object
void PSDFaultsAndEventsUnit::CBTCPlatformOutputsObjectCreated(Comms::Object cbtc_platform_outputs_object)
{
    assert(cbtc_platform_outputs_object.IsValid());
    assert(Core::GetClassID(cbtc_platform_outputs_object) == Project::ClassID::CBTC_PLATFORM_OUTPUTS);

    const std::lock_guard<std::mutex> lock(m_mutex);

    // Listener for CBTC train input properties.
    NumberListener                        cbtc_platform_outputs_num_listener;
    std::map<std::string, NumberCallback> numbers;
    numbers[Project::ValueName::CBTCPlatformOutputs::PSD_DOOR_STATUS] = [this](Sim::Number door_inhibited) {
        this->CBTCPlatformDoorStateChanged(door_inhibited);
    };
    AddNumberListeners(numbers, cbtc_platform_outputs_object, cbtc_platform_outputs_num_listener);

    cbtc_platform_outputs_object = cbtc_platform_outputs_object;
}

/// @brief      This function is called whenever cbtc platform inputs object is created.
///             This will store cbtc paltform inputs object and below ids which are used
///             whenever there is a change in below inhibited codes and fault states.
/// PSD_OPEN_FAULT
/// PSD_CLOSE_FAULT
/// LHS_SD_OPEN_INHIBIT_CODE
/// RHS_SD_OPEN_INHIBIT_CODE
/// LHS_SD_CLOSE_INHIBIT_CODE
/// RHS_SD_CLOSE_INHIBIT_CODE
/// FORCE_DOOR_SD_INHIBIT_CODE
///
/// @param object               cbtc paltform inputs object
void PSDFaultsAndEventsUnit::CBTCPlatformInputsObjectCreated(Comms::Object cbtc_platform_inputs_object)
{
    assert(cbtc_platform_inputs_object.IsValid());
    assert(Core::GetClassID(cbtc_platform_inputs_object) == Project::ClassID::CBTC_PLATFORM_INPUTS);

    // Record ids required later on
    using namespace Project::ValueName::CBTCPlatformInputs;
    m_psds_not_working_num_id              = cbtc_platform_inputs_object.Numbers().Get(PSD_CLOSE_FAULT).id;
    m_psds_unknown_num_id                  = cbtc_platform_inputs_object.Numbers().Get(PSD_NOT_WORKING).id;
    m_lhs_sd_open_inhibit_code_num_id      = cbtc_platform_inputs_object.Numbers().Get(LHS_SD_OPEN_INHIBIT_CODE).id;
    m_rhs_sd_open_inhibit_code_num_id      = cbtc_platform_inputs_object.Numbers().Get(RHS_SD_OPEN_INHIBIT_CODE).id;
    m_lhs_sd_close_inhibit_code_num_id     = cbtc_platform_inputs_object.Numbers().Get(LHS_SD_CLOSE_INHIBIT_CODE).id;
    m_rhs_sd_close_inhibit_code_num_id     = cbtc_platform_inputs_object.Numbers().Get(RHS_SD_CLOSE_INHIBIT_CODE).id;
    m_door_forced_open_inhibit_code_num_id = cbtc_platform_inputs_object.Numbers().Get(FORCE_DOOR_SD_INHIBIT_CODE).id;

    m_cbtc_platform_unit_object = cbtc_platform_inputs_object;
}

/// @brief      This function is called whenever registered faults and events state changed.
///             This will call those functions that computes new SDO Code and posts them.
///             There is a chance that the raw pointers (that are part of m_fault_id_to_fault_info_map are poining to
///             faults which are part of input structure and that are created on stack) would be dangling pointers if
///             they are used after input structure got deleted. This is very rare scenario but possible. This scenario
///             is possible if destructor and CBTCFaultsOREventsStateChanged functions got called in parallel. So in
///             order to resolve this issue, the local lock is taken and the raw pointers are made null pointers in the
///             destructor before input structure got destroyed and the same local lock is used before checking for the
///             pointer validity and usage in CBTCFaultsOREventsStateChanged function.
/// @param fault_or_event_state
void PSDFaultsAndEventsUnit::CBTCFaultsOREventsStateChanged(Sim::Number fault_or_event_state)
{
    const std::lock_guard<std::mutex> lock(m_mutex);
    TrainFaults                       train_faults(NO_FAULT, 0, 0, 0, 0, 0);
    if (true == static_cast<bool>(fault_or_event_state.value))
    {
        // change is only at the train level.
        // Compute and post updated SDO Fault Codes to Comms

        if (fault_or_event_state.id == m_train_object.Numbers().Info().GetID(Project::ValueName::Train::FLT_PLATFORM_SCREEN_DOOR_NOT_WORKING))
        {
            m_psd_not_working = (fault_or_event_state.value > 0.5);
            ComputeSDOCodeForATrain(m_vehicle_index_to_fault_info_map, m_psd_not_working, train_faults, m_psd_not_working);
            UpdateVisionPlatformDoorStatusValues();
            PostCBTCFaultsNEventsToComms(train_faults);
        }
        else if (fault_or_event_state.id == m_train_object.Numbers().Info().GetID(Project::ValueName::Train::FLT_PSD_ADCL_STATUS_NOT_AVAILABLE)) //Fault ADCL not available
        {
            m_psd_adcl_not_available = (fault_or_event_state.value > 0.5);
            ComputeSDOCodeForATrain(m_vehicle_index_to_fault_info_map, false, train_faults);
            UpdateVisionPlatformDoorStatusValues();
            PostCBTCFaultsNEventsToComms(train_faults);
        }
		else if (fault_or_event_state.id == m_train_object.Numbers().Info().GetID(Project::ValueName::Train::FLT_PSD_STATUS_UNKNOWN)) //Fault PSD status 
		{
			m_psd_unknown = (fault_or_event_state.value > 0.5);
			train_faults.psd_not_working_train = FAULT;
			PostCBTCFaultsNEventsToComms(train_faults);
		}
        else
        {
            //m_psd_unknown                      = (fault_or_event_state.value > 0.5);
            //train_faults.psd_not_working_train = FAULT;
            PostCBTCFaultsNEventsToComms(train_faults);
        }
    }
    else
    {
        if (fault_or_event_state.id == m_train_object.Numbers().Info().GetID(Project::ValueName::Train::FLT_PSD_ADCL_STATUS_NOT_AVAILABLE)) //Fault ADCL not available
        {
            m_psd_adcl_not_available = false;
        }
        ComputeSDOCodeForATrain(m_vehicle_index_to_fault_info_map, NO_FAULT, train_faults);
        UpdateVisionPlatformDoorStatusValues();
        PostCBTCFaultsNEventsToComms(train_faults);
    }
    /*if (m_psd_not_working == true)
    {
        // change is only at the train level.
        // Compute and post updated SDO Fault Codes to Comms
        ComputeSDOCodeForATrain(m_vehicle_index_to_fault_info_map, m_psd_not_working, train_faults, m_psd_not_working);
        UpdateVisionPlatformDoorStatusValues();
        PostCBTCFaultsNEventsToComms(train_faults);
    }*/
    /* Commented out since the following faults were supported in Crossrail but are not currently supported in Tel Aviv

    //update the input
    if(m_psds_all_fail_to_close_code_num_id == fault_or_event_state.id)
    {
        //change is only at the train level.
        //Compute and post updated SDO Fault Codes to Comms
        m_psd_all_fail_to_close = (fault_or_event_state.value > 0.5);
        ComputeSDOCodeForATrain(m_vehicle_index_to_fault_info_map, m_psd_all_fail_to_close, train_faults,
    m_psd_all_fail_to_open); UpdateVisionPlatformDoorStatusValues(); PostCBTCFaultsNEventsToComms(train_faults);
    }
    else if(m_psds_all_fail_to_open_code_num_id == fault_or_event_state.id)
    {
        //change is only at the train level.
        //Compute and post updated SDO Fault Codes to Comms
        m_psd_all_fail_to_open = (fault_or_event_state.value > 0.5);
        ComputeSDOCodeForATrain(m_vehicle_index_to_fault_info_map, m_psd_all_fail_to_close, train_faults,
    m_psd_all_fail_to_open); UpdateVisionPlatformDoorStatusValues(); PostCBTCFaultsNEventsToComms(train_faults);
    }
    else

    {
        auto fault_id_to_fault_info_itr = m_fault_id_to_fault_info_map.find(
          std::make_pair(fault_or_event_state.object_id, fault_or_event_state.id));
        if ((fault_id_to_fault_info_itr != m_fault_id_to_fault_info_map.end()) &&
    (fault_id_to_fault_info_itr->second.fault_address))
        {
            // change is at the vehicle level.

            // Compute and post updated SDO Fault Codes to Comms
            *(fault_id_to_fault_info_itr->second.fault_address) = fault_or_event_state.value;
            int vehicle_index                                   = fault_id_to_fault_info_itr->second.vehicle_index;
            ComputeSDOCodeForAVehicle(m_vehicle_index_to_fault_info_map[vehicle_index].input_structure,
                                      m_vehicle_index_to_fault_info_map[vehicle_index].output_structure,
                                      m_vehicle_index_to_fault_info_map[vehicle_index].vision_faults);
            ComputeSDOCodeForATrain(m_vehicle_index_to_fault_info_map, NO_FAULT, train_faults);
            UpdateVisionPlatformDoorStatusValues();
            PostCBTCFaultsNEventsToComms(train_faults);
        }
        else
        {
            // ideally will never occur...just in case.
            Trace::GetLogger().STAMP(Trace::ERR) << " PSDFaultsAndEventsUnit - Unknown fault " << Trace::EndLog();
        }
    }*/
}

/// @brief      This function will post updated platform door states
///
/// @param platform_door_state Comms number that gives the current state of the platform door
void PSDFaultsAndEventsUnit::CBTCPlatformDoorStateChanged(Sim::Number platform_door_state)
{
    const std::lock_guard<std::mutex> lock(m_mutex);

    m_platform_door_state = platform_door_state.value;
    if (m_platform_door_state != Project::TypeValue::PSDDoorStatus::UNAVAILABLE)
        m_platform_doors_present = true;
    else
        m_platform_doors_present = false;

    UpdateVisionPlatformDoorStatusValues();
}

/// @brief  This function updates the vision platform door status values
///
/// Platform doors are marked as being disabled when the platform door is not
/// in either the Open or Open Fault state
///
void PSDFaultsAndEventsUnit::UpdateVisionPlatformDoorStatusValues()
{
    // function to update the platform door status in vision
    auto update_platform_door_status = [this](Comms::Object vehicle_object, Sim::ValueID::ID id, bool value) {
        Sim::Number vision_platform_door_status;
        vision_platform_door_status.id    = id;
        vision_platform_door_status.value = value;
        OS::Lock<Comms::Gateway> lock(GetGateway());
        vehicle_object.Numbers().Store().Set(vision_platform_door_status);
    };

    // update vision with the state of the platform doors
    for (auto vehicle_index_to_fault_info : m_vehicle_index_to_fault_info_map)
    {
        // If we have a valid vehicle obect
        if (vehicle_index_to_fault_info.second.vision_faults.vehicle_object.IsValid())
        {
            if (!m_platform_doors_present)
            {
                // In vision enable the pasengers walking through platform doors when there are no doors on the platform
                update_platform_door_status(vehicle_index_to_fault_info.second.vision_faults.vehicle_object,
                                            m_vision_platform_door_1_status_code_num_id,
                                            ENABLED);
                update_platform_door_status(vehicle_index_to_fault_info.second.vision_faults.vehicle_object,
                                            m_vision_platform_door_3_status_code_num_id,
                                            ENABLED);
                update_platform_door_status(vehicle_index_to_fault_info.second.vision_faults.vehicle_object,
                                            m_vision_platform_door_4_status_code_num_id,
                                            ENABLED);
                update_platform_door_status(vehicle_index_to_fault_info.second.vision_faults.vehicle_object,
                                            m_vision_platform_door_2_status_code_num_id,
                                            ENABLED);
            }
            else if (m_platform_door_state != Project::TypeValue::PSDDoorStatus::PSD_OPENED)
            {
                // Disable pasengers walking through any Platform doors until the platform doors are fully open
                update_platform_door_status(vehicle_index_to_fault_info.second.vision_faults.vehicle_object,
                                            m_vision_platform_door_1_status_code_num_id,
                                            DISABLED);
                update_platform_door_status(vehicle_index_to_fault_info.second.vision_faults.vehicle_object,
                                            m_vision_platform_door_3_status_code_num_id,
                                            DISABLED);
                update_platform_door_status(vehicle_index_to_fault_info.second.vision_faults.vehicle_object,
                                            m_vision_platform_door_4_status_code_num_id,
                                            DISABLED);
                update_platform_door_status(vehicle_index_to_fault_info.second.vision_faults.vehicle_object,
                                            m_vision_platform_door_2_status_code_num_id,
                                            DISABLED);
            }
            else
            {
                // Now that the platform doors are fully open, only allow passenger to walk through the platform doors
                // that have successfully opened. Disable all platform doors that have a fault associated with them
                update_platform_door_status(vehicle_index_to_fault_info.second.vision_faults.vehicle_object,
                                            m_vision_platform_door_1_status_code_num_id,
                                            ENABLED);
                update_platform_door_status(vehicle_index_to_fault_info.second.vision_faults.vehicle_object,
                                            m_vision_platform_door_3_status_code_num_id,
                                            ENABLED);
                update_platform_door_status(vehicle_index_to_fault_info.second.vision_faults.vehicle_object,
                                            m_vision_platform_door_4_status_code_num_id,
                                            ENABLED);
                update_platform_door_status(vehicle_index_to_fault_info.second.vision_faults.vehicle_object,
                                            m_vision_platform_door_2_status_code_num_id,
                                            ENABLED);

                // Remaining door, which can be associated with a fault, to be enable/disable based on there status
                update_platform_door_status(vehicle_index_to_fault_info.second.vision_faults.vehicle_object,
                                            m_vision_platform_door_3_status_code_num_id,
                                            vehicle_index_to_fault_info.second.vision_faults.vision_platform_door_3_status);
                update_platform_door_status(vehicle_index_to_fault_info.second.vision_faults.vehicle_object,
                                            m_vision_platform_door_4_status_code_num_id,
                                            vehicle_index_to_fault_info.second.vision_faults.vision_platform_door_4_status);
            }
        }
    }
}

/// @brief      This function will post updated SDO codes
/// const std::lock_guard<std::mutex> lock(m_mutex); Implicitly taken as the lock is acquired by the caller.
/// @param fault_or_event_state
void PSDFaultsAndEventsUnit::PostCBTCFaultsNEventsToComms(const TrainFaults& train_faults)
{
    // Sim::Number psd_open_fault;
    Sim::Number psd_not_working;
    Sim::Number psd_close_fault;
    Sim::Number lhs_sd_open_inhibit;
    Sim::Number rhs_sd_open_inhibit;
    Sim::Number lhs_sd_close_inhibit;
    Sim::Number rhs_sd_close_inhibit;
    Sim::Number door_forced_open_inhibit;

    // psd_open_fault.id = m_psd_open_fault_code_num_id;
    psd_close_fault.id          = m_psds_not_working_num_id;
    psd_not_working.id          = m_psds_unknown_num_id;
    lhs_sd_open_inhibit.id      = m_lhs_sd_open_inhibit_code_num_id;
    rhs_sd_open_inhibit.id      = m_rhs_sd_open_inhibit_code_num_id;
    lhs_sd_close_inhibit.id     = m_lhs_sd_close_inhibit_code_num_id;
    rhs_sd_close_inhibit.id     = m_rhs_sd_close_inhibit_code_num_id;
    door_forced_open_inhibit.id = m_door_forced_open_inhibit_code_num_id;

    // psd_open_fault.value = train_faults.psd_open_fault_train;
    //psd_close_fault.value          = (m_psd_adcl_not_available ? 1.0 : 0.0);
    psd_not_working.value          = train_faults.psd_not_working_train;
    lhs_sd_open_inhibit.value      = train_faults.lhs_sd_open_inhibit_train;
    rhs_sd_open_inhibit.value      = train_faults.rhs_sd_open_inhibit_train;
    lhs_sd_close_inhibit.value     = train_faults.lhs_sd_close_inhibit_train;
    rhs_sd_close_inhibit.value     = train_faults.rhs_sd_close_inhibit_train;
    door_forced_open_inhibit.value = train_faults.door_forced_open_inhibit_train;

    // update CBTC Platfrom Unit with faults N Events via comms.

    if (m_cbtc_platform_unit_object.IsValid())
    {
        OS::Lock<Comms::Gateway> lock(GetGateway());
        m_cbtc_platform_unit_object.Numbers().Store().Set(psd_not_working);
        m_cbtc_platform_unit_object.Numbers().Store().Set(psd_close_fault);
        m_cbtc_platform_unit_object.Numbers().Store().Set(lhs_sd_open_inhibit);
        m_cbtc_platform_unit_object.Numbers().Store().Set(rhs_sd_open_inhibit);
        m_cbtc_platform_unit_object.Numbers().Store().Set(lhs_sd_close_inhibit);
        m_cbtc_platform_unit_object.Numbers().Store().Set(rhs_sd_close_inhibit);
        m_cbtc_platform_unit_object.Numbers().Store().Set(door_forced_open_inhibit);
    }
}
