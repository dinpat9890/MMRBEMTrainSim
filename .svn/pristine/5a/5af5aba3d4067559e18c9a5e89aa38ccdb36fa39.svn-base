///
/// @file       PSDFaultsAndEventsUnit.h
///
///Unit will handle faults from Door Unit as well as scc.
/// The faults that this unit handles are:
///Signals or events from the Train Door Unit to this unit:
///Vehicle::CBTCVehicleOutputs: For all Vehicles.
///
///                             Door 1 Inhibited.
///                             Door 2 Inhibited.
///                             Door 3 Inhibited.
///                             Door 4 Inhibited.
///
///Signals or events from the SCC unit:
///Train:
///                             PSDs All Fail To Close
///Train::vehicle
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


#ifndef PSD_FAULTS_AND_EVENTS_UNIT_H
#define PSD_FAULTS_AND_EVENTS_UNIT_H


#include "sim_comms\Unit.h"
#include "core_types\SessionData.h"
#include "common\DataAccess.h"
#include "common\Properties.h"
#include "world_api\TrainPathWatcher.h"
#include "sim_common\Listener.h"


#include <cstddef>
#include <string>
#include <mutex>
#include <list>

#include <train_data_access/TrainDataAccess.h>
#include <train_data_access/TrainDataAccessTypes.h>

namespace
{
    const bool DISABLED = 0;
    const bool ENABLED = 1;

    const bool NO_FAULT = 0;
    const bool FAULT = 1;

    const int ORIENTATION_1_2 = 1;
    const int ORIENTATION_2_1 = 2;

    const int REQUEST_FREQUENCY = 20;
    const int NO_OF_DOOR_PAIRS_PER_VEHICLE = 2;
    const long int SD_CODE_FOR_ALL_PSD_FAIL_TO_CLOSE = 134217727; //777777777(8-octal)
    const long int SD_CODE_FOR_ALL_PSD_FAIL_TO_OPEN  = 134217727; //777777777(8-octal)

    struct TrainFaults
    {
        bool psd_not_working_train;
        long int lhs_sd_open_inhibit_train;
        long int rhs_sd_open_inhibit_train;
        long int lhs_sd_close_inhibit_train;
        long int rhs_sd_close_inhibit_train;
        long int door_forced_open_inhibit_train;

        TrainFaults(bool psd_not_working_train, 
            long int lhs_sd_open_inhibit_train, 
            long int rhs_sd_open_inhibit_train, 
            long int lhs_sd_close_inhibit_train, 
            long int rhs_sd_close_inhibit_train, 
            long int door_forced_open_inhibit_train)
          : psd_not_working_train(psd_not_working_train),
            lhs_sd_open_inhibit_train(lhs_sd_open_inhibit_train),
            rhs_sd_open_inhibit_train(rhs_sd_open_inhibit_train),
            lhs_sd_close_inhibit_train(lhs_sd_close_inhibit_train),
            rhs_sd_close_inhibit_train(rhs_sd_close_inhibit_train),
            door_forced_open_inhibit_train(door_forced_open_inhibit_train)  {}

        void Reset()
        {
            psd_not_working_train = NO_FAULT;
            lhs_sd_open_inhibit_train = 0;
            rhs_sd_open_inhibit_train = 0;
            lhs_sd_close_inhibit_train = 0;
            rhs_sd_close_inhibit_train = 0;
            door_forced_open_inhibit_train = 0;
        }
    };

    struct InputStructure
    {
        std::string car_class_code;
        bool door_1_inhibited;
        bool door_3_inhibited;
        bool door_4_inhibited;
        bool door_2_inhibited;
        bool psd_not_working;
        bool door_forced_open;
        bool psd_cannot_open_in_station;
        bool psd_cannot_open_before_station;
        int orientation;

        InputStructure(){}
        InputStructure(int Orientation, 
            std::string vehicle_car_class_code,
            bool door_1_inhibited = NO_FAULT,
            bool door_3_inhibited = NO_FAULT,
            bool door_4_inhibited = NO_FAULT,
            bool door_2_inhibited = NO_FAULT,
            bool psd_not_working = NO_FAULT,
            bool door_forced_open = NO_FAULT,
            bool psd_cannot_open_in_station = NO_FAULT,
            bool psd_cannot_open_before_station = NO_FAULT):
            door_1_inhibited(door_1_inhibited), 
            door_3_inhibited(door_3_inhibited), 
            door_4_inhibited(door_4_inhibited),
            door_2_inhibited(door_2_inhibited),
            psd_not_working(psd_not_working), 
            door_forced_open(door_forced_open),
            psd_cannot_open_in_station(psd_cannot_open_in_station),
            psd_cannot_open_before_station(psd_cannot_open_before_station),
            orientation(Orientation),
            car_class_code(vehicle_car_class_code){}
    };

    struct OutputStructure
    {
        int lhs_sd_open_inhibit_vehicle;
        int rhs_sd_open_inhibit_vehicle;
        int lhs_sd_close_inhibit_vehicle;
        int rhs_sd_close_inhibit_vehicle;
        int door_forced_open_inhibit_vehicle;
        bool psd_not_working_vehicle;
        //bool psd_open_fault_vehicle;

        OutputStructure():
        lhs_sd_open_inhibit_vehicle(0),
        rhs_sd_open_inhibit_vehicle(0),
        lhs_sd_close_inhibit_vehicle(0),
        rhs_sd_close_inhibit_vehicle(0),
        door_forced_open_inhibit_vehicle(0),
        psd_not_working_vehicle(NO_FAULT){}
       // psd_open_fault_vehicle(NO_FAULT){}
    };

    struct VisionFaults
    {
        bool vision_platform_door_3_status;
        bool vision_platform_door_4_status;
        Comms::Object vehicle_object;

        VisionFaults(bool vision_platform_door_3_status = ENABLED, 
                    bool vision_platform_door_4_status = ENABLED, 
                    Comms::Object vehicle_object = Comms::Object())
                  : vision_platform_door_3_status(vision_platform_door_3_status),
                    vision_platform_door_4_status(vision_platform_door_4_status),
                    vehicle_object(vehicle_object){}
    };

    struct VehicleFaultsInfoStructure
    {
        InputStructure input_structure;
        OutputStructure output_structure;
        VisionFaults vision_faults;
        VehicleFaultsInfoStructure(){}
        VehicleFaultsInfoStructure(InputStructure input_structure, 
            OutputStructure output_structure,
            VisionFaults vision_faults):
            input_structure(input_structure),
            output_structure(output_structure),
            vision_faults(vision_faults){}
    };
    typedef std::map<int, VehicleFaultsInfoStructure> VehicleIndexToFaultInfoMap;
    struct FaultVehicleIndexStructure
    {
        bool* fault_address;
        int vehicle_index;
        FaultVehicleIndexStructure(){}
        FaultVehicleIndexStructure(bool* fault_address,int vehicle_index)
        :fault_address(fault_address),
        vehicle_index(vehicle_index){}
    };

    typedef std::function<void(Sim::Number number)>  NumberCallback;
    typedef Sim::Listener<Sim::Number, Sim::NoQueueing, Sim::IndividualCallbacks<Sim::Number>>  NumberListener;
    typedef std::map<std::string, NumberCallback> number_to_cb_map;
    /// @brief Adds listener and callback to faults.
    /// 
    /// @param property_map     faults which we are interested in state change.
    /// @param object           Comms object which you are intersted in the state change.
    /// @param num_listener     faults listener.
    /// @param request_freq     the frequency at which we get callbacks.
    void AddNumberListeners(number_to_cb_map property_map, Comms::Object &object, NumberListener &num_listener, int request_freq = REQUEST_FREQUENCY)
    {
        for (auto &auto_property : property_map)
        {
            auto  property_name = auto_property.first;
            auto number_cb = auto_property.second;

            Sim::Number property_number = object.Numbers().Get(property_name);
            num_listener.AddCallback(property_number, number_cb);

            Sim::NumberInfo number_info = object.Numbers().Info().GetInfo(property_number.id);
            object.Numbers().Store().Request(number_info, request_freq);
        }

        object.Numbers().Store().AddListener(num_listener);
    }

/// @brief      This function will compute SDO code for a vehicle
/// const std::lock_guard<std::mutex> lock(m_mutex); Implicitly taken as the lock is acquired by the caller.
/// @param in input_structure
/// @param out output_structure
/// @param out.vision_faults
    void ComputeSDOCodeForAVehicle(const InputStructure &input_structure, 
    OutputStructure &output_structure, VisionFaults &vision_faults)
{
    int door_sd_left_open_inhibited  = 0;
    int door_sd_right_open_inhibited = 0;
    if( input_structure.orientation == ORIENTATION_1_2)
    {
        if(input_structure.door_1_inhibited)
            door_sd_right_open_inhibited |= 1;

        if(input_structure.door_3_inhibited)
            door_sd_right_open_inhibited |= 2;

        if(input_structure.door_4_inhibited)
            door_sd_left_open_inhibited |= 2;

        if(input_structure.door_2_inhibited)
            door_sd_left_open_inhibited |= 1;
    }

    if( input_structure.orientation == ORIENTATION_2_1)
    {
        if(input_structure.door_1_inhibited)
            door_sd_left_open_inhibited |= 2;

        if(input_structure.door_3_inhibited)
            door_sd_left_open_inhibited |= 1;

        if(input_structure.door_4_inhibited)
            door_sd_right_open_inhibited |= 1;

        if(input_structure.door_2_inhibited)
            door_sd_right_open_inhibited |= 2;
    }

    int psd_cannot_open_in_station_left_open_inhibited = 0;
    int psd_cannot_open_in_station_right_open_inhibited = 0;
    if(input_structure.psd_cannot_open_in_station)
    {
        psd_cannot_open_in_station_left_open_inhibited |= 2;
        psd_cannot_open_in_station_right_open_inhibited |= 2;
    }

    int psd_cannot_open_before_station_left_open_inhibited = 0;
    int psd_cannot_open_before_station_right_open_inhibited = 0;
    if(input_structure.psd_cannot_open_before_station)
    {
        psd_cannot_open_before_station_left_open_inhibited |= 2;
        psd_cannot_open_before_station_right_open_inhibited |= 2;
    }

    if(input_structure.psd_cannot_open_in_station || 
        input_structure.psd_cannot_open_before_station)
    {
        vision_faults.vision_platform_door_3_status = DISABLED;
        vision_faults.vision_platform_door_4_status = DISABLED;
    }
    else
    {
        vision_faults.vision_platform_door_3_status = ENABLED;
        vision_faults.vision_platform_door_4_status = ENABLED;
    }

    int psd_cannot_close_left_close_inhibited = 0;
    int psd_cannot_close_right_close_inhibited = 0;
    if(input_structure.psd_not_working)
    {
        psd_cannot_close_left_close_inhibited |= 2;
        psd_cannot_close_right_close_inhibited |= 2;
    }

    output_structure.door_forced_open_inhibit_vehicle = input_structure.door_forced_open ? 2 : 0;

    output_structure.psd_not_working_vehicle = input_structure.psd_not_working ? FAULT : NO_FAULT;

    /*output_structure.psd_open_fault_vehicle = (input_structure.psd_cannot_open_in_station || 
                                       input_structure.psd_cannot_open_before_station || 
                                       input_structure.door_forced_open) ? FAULT : NO_FAULT;*/

    output_structure.lhs_sd_open_inhibit_vehicle = door_sd_left_open_inhibited | 
                                psd_cannot_open_in_station_left_open_inhibited | 
                            psd_cannot_open_before_station_left_open_inhibited;

    output_structure.rhs_sd_open_inhibit_vehicle = door_sd_right_open_inhibited | 
                                psd_cannot_open_in_station_right_open_inhibited | 
                            psd_cannot_open_before_station_right_open_inhibited;

    output_structure.lhs_sd_close_inhibit_vehicle = door_sd_left_open_inhibited | 
                                          psd_cannot_close_left_close_inhibited;

    output_structure.rhs_sd_close_inhibit_vehicle = door_sd_right_open_inhibited |
                                          psd_cannot_close_right_close_inhibited;
}

/// @brief      This function will compute SDO code for a train
/// const std::lock_guard<std::mutex> lock(m_mutex); Implicitly taken as the lock is acquired by the caller.
/// @param in vehicle_index_to_fault_info_map       vehicle index to fault information for all vehicles.
/// @param in psd_all_fail_close                    fault state
/// @param out.train_faults                         SDO inhibited code and faults for below faults:
///                                                 psd open fault
///                                                 psd close fault
///                                                 lhs sd open inhibit
///                                                 rhs sd open inhibit
///                                                 lhs sd close inhibit
///                                                 rhs sd close inhibit
///                                                 door forced open inhibit
/// @param in psd_all_fail_to_open                  open fault state, default is false
void ComputeSDOCodeForATrain(const VehicleIndexToFaultInfoMap &vehicle_index_to_fault_info_map, 
                             const bool psd_all_fail_close, TrainFaults &train_faults, const bool psd_all_fail_to_open = false)
{
    //Reset all train faults.
    train_faults.Reset();

    int vehicle_index = 0;
    for(auto vehicle_index_to_fault_info: vehicle_index_to_fault_info_map)
    {
        // TBD - Need to limit the vehicles that are include since vehicles with doors are limited to vehicle class types "F1" and "F2"

        // ASSUMPTION: the vehicle_index_to_fault_info_map is a map so the vehicles are processed in order
        if ((vehicle_index_to_fault_info.second.input_structure.car_class_code == "F1") ||
            (vehicle_index_to_fault_info.second.input_structure.car_class_code == "F2"))
        {
            train_faults.psd_not_working_train |= vehicle_index_to_fault_info.second.output_structure.psd_not_working_vehicle;
            train_faults.lhs_sd_open_inhibit_train |= ((vehicle_index_to_fault_info.second.output_structure.lhs_sd_open_inhibit_vehicle) << (NO_OF_DOOR_PAIRS_PER_VEHICLE * vehicle_index));
            train_faults.rhs_sd_open_inhibit_train |= ((vehicle_index_to_fault_info.second.output_structure.rhs_sd_open_inhibit_vehicle) << (NO_OF_DOOR_PAIRS_PER_VEHICLE * vehicle_index));
            train_faults.lhs_sd_close_inhibit_train |= ((vehicle_index_to_fault_info.second.output_structure.lhs_sd_close_inhibit_vehicle) << (NO_OF_DOOR_PAIRS_PER_VEHICLE * vehicle_index));
            train_faults.rhs_sd_close_inhibit_train |= ((vehicle_index_to_fault_info.second.output_structure.rhs_sd_close_inhibit_vehicle) << (NO_OF_DOOR_PAIRS_PER_VEHICLE * vehicle_index));
            train_faults.door_forced_open_inhibit_train |= ((vehicle_index_to_fault_info.second.output_structure.door_forced_open_inhibit_vehicle) << (NO_OF_DOOR_PAIRS_PER_VEHICLE * vehicle_index));

            vehicle_index++;
        }
    }

    if(psd_all_fail_close)
    {
        train_faults.lhs_sd_close_inhibit_train = SD_CODE_FOR_ALL_PSD_FAIL_TO_CLOSE;
        train_faults.rhs_sd_close_inhibit_train = SD_CODE_FOR_ALL_PSD_FAIL_TO_CLOSE;
        train_faults.psd_not_working_train      = FAULT;
    }

    /*if(psd_all_fail_to_open)
    {
        train_faults.lhs_sd_open_inhibit_train = SD_CODE_FOR_ALL_PSD_FAIL_TO_OPEN;
        train_faults.rhs_sd_open_inhibit_train = SD_CODE_FOR_ALL_PSD_FAIL_TO_OPEN;
        train_faults.psd_open_fault_train      = FAULT;
    }*/
}

}//end of namespace

/// @brief      PSDFaultsAndEventsUnit will handle events from Door Unit as well PSD fautls from scc
class PSDFaultsAndEventsUnit : public Comms::SessionUnit
{
public:
    PSDFaultsAndEventsUnit(Comms::Gateway           &gateway,
		                   Common::Data::DataAccess &data_access,
                           int                       scenario_train_id);
    ~PSDFaultsAndEventsUnit();

    std::string GetName() const override { return "PSD Faults And Events Unit"; }

private:
    void PopulateInternalStructures(Common::Data::DataAccess &data_access,
                                    int scenario_train_id);
    void CommsObjectCreated(Comms::Object comms_object);
    void TrainObjectCreated(Comms::Object train_object);
    void VehicleObjectCreated(Comms::Object vehicle_object);
    void CBTCVehicleOutputsObjectCreated(Comms::Object cbtc_vehicle_outputs_object);
    void CBTCPlatformOutputsObjectCreated(Comms::Object cbtc_platform_outputs_object);
    void CBTCPlatformInputsObjectCreated(Comms::Object cbtc_platform_inputs_object);
    void PostCBTCFaultsNEventsToComms(const TrainFaults& train_faults);
    void UpdateVisionPlatformDoorStatusValues();

    // Callbacks
    void CBTCFaultsOREventsStateChanged(Sim::Number fault_or_event_state);
    void CBTCPlatformDoorStateChanged(Sim::Number platform_door_state);

    //local mutex
    std::mutex m_mutex;

    //comms object
    Comms::Object m_cbtc_platform_unit_object;
    Comms::Object cbtc_platform_outputs_object;
    Comms::Object cbtc_platform_inputs_object;
    Comms::Object m_train_object;
    //required maps
    std::map<std::pair<Sim::ValueID::ObjectID, Sim::ValueID::ID>, FaultVehicleIndexStructure> m_fault_id_to_fault_info_map;
    std::map<int, VehicleFaultsInfoStructure> m_vehicle_index_to_fault_info_map;

    // Platform door information about the next station
    double m_platform_door_state;
    bool   m_platform_doors_present;

    //input fault codes 
    //Train SCC Events to CBTC Faults and Events Unit  SCC-Events->TM-F&E
    Sim::ValueID::ID m_psds_not_working_num_id;
    Sim::ValueID::ID m_psds_unknown_num_id;
   // Sim::ValueID::ID m_psds_all_fail_to_open_code_num_id;
    NumberListener cbtc_faults_num_listener;
    // psd all open/close fault state
    bool m_psd_not_working;
    bool m_psd_unknown = false;
    //bool m_psd_all_fail_to_close;
	bool m_psd_adcl_not_available; 

    //output fault codes
    //Train::CBTCPlatformInputs [CBTC Faults and Events Unit to Platform Unit] (F&E->Plat)
    Sim::ValueID::ID m_psd_open_fault_code_num_id;
    Sim::ValueID::ID m_psd_close_fault_code_num_id;
    Sim::ValueID::ID m_lhs_sd_open_inhibit_code_num_id;
    Sim::ValueID::ID m_rhs_sd_open_inhibit_code_num_id;
    Sim::ValueID::ID m_lhs_sd_close_inhibit_code_num_id;
    Sim::ValueID::ID m_rhs_sd_close_inhibit_code_num_id;
    Sim::ValueID::ID m_door_forced_open_inhibit_code_num_id;

    //Train::Vehicles [CBTC Faults and Events Unit to Vision] TM-F&E->Vision
    Sim::ValueID::ID m_vision_platform_door_1_status_code_num_id;
    Sim::ValueID::ID m_vision_platform_door_3_status_code_num_id;
    Sim::ValueID::ID m_vision_platform_door_4_status_code_num_id;
    Sim::ValueID::ID m_vision_platform_door_2_status_code_num_id;
};

#endif //PSD_FAULTS_AND_EVENTS_UNIT_H
