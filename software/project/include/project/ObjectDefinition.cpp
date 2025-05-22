///
/// @file       ObjectDefinition.cpp
///
/// @ingroup    CoreTrainSim
///
/// @author     CommsDataGenerator (Automatically generated, do not modify)
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2019
///

#include "Project/ObjectDefinition.h"

#include <SydacCommon/LexicalCast.h>
#include <SydacCommon/SydacExceptions.h>

#include <algorithm>
#include <cassert>
#include <functional>

using namespace Project;
using namespace std;
using namespace Sydac;

namespace
{
    /// Structure for holding information about a tag
    /// We wouldn't have to do this if the C++ compiler could handle uniform initialization

    struct TagInfo
    {
        // Just the name, for the moment
        string name;

        operator Sim::Tag() const { return Sim::Tag(name); }
    };

    /// Structure for holding information about an attribute

    struct IdentifierInfo
    {
        // The name of the identifier
        string name;

        // The attribute's default value, although this will presumably be overridden
        Sim::Identifier::Type default_value;

        operator Sim::Identifier() const { return Sim::Identifier(name, default_value); }
    };

    struct ConstantInfo
    {
        // The name of the constant
        string name;

        // The attribute's default value, although this will presumably be overridden
        Sim::Constant::Type default_value;

        operator Sim::Constant() const { return Sim::Constant(name, default_value); }
    };

    struct SpecificationInfo
    {
        // The name of the specification
        string name;

        // The attribute's default value, although this will presumably be overridden
        Sim::Specification::Type default_value;

        operator Sim::Specification() const { return Sim::Specification(name, default_value); }
    };

    /// Structure for holding static definition data.

    struct ClassInfo
    {
        int                           class_id;
        string                        name;
        size_t                        tags_size;
        const TagInfo                *tags;
        size_t                        identifiers_size;
        const IdentifierInfo         *identifiers;
        size_t                        constants_size;
        const ConstantInfo           *constants;
        size_t                        specifications_size;
        const SpecificationInfo      *specifications;
        size_t                        numbers_size;
        const Sim::Info<Sim::Number> *numbers;
        size_t                        raws_size;
        const Sim::Info<Sim::Raw>    *raws;
        size_t                        trays_size;
        const Sim::Info<Sim::Tray>   *trays;
    };
    const Sim::Info<Sim::Number> IODATA_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 108),
        Sim::Info<Sim::Number>("Creator ID", 0.5, 0),
    };
    const size_t IODATA_NUMBERS_SIZE = sizeof(IODATA_NUMBERS)/sizeof(IODATA_NUMBERS[0]);
    const TagInfo *IODATA_TAGS = 0;
    const size_t IODATA_TAGS_SIZE = 0;
    const IdentifierInfo *IODATA_IDENTIFIERS = 0;
    const size_t IODATA_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *IODATA_CONSTANTS = 0;
    const size_t IODATA_CONSTANTS_SIZE = 0;
    const SpecificationInfo *IODATA_SPECIFICATIONS = 0;
    const size_t IODATA_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *IODATA_RAWS = 0;
    const size_t IODATA_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *IODATA_TRAYS = 0;
    const size_t IODATA_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> HUB_INPUTS_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 105),
        Sim::Info<Sim::Number>("Creator ID", 0.5, 0),
    };
    const size_t HUB_INPUTS_NUMBERS_SIZE = sizeof(HUB_INPUTS_NUMBERS)/sizeof(HUB_INPUTS_NUMBERS[0]);
    const TagInfo *HUB_INPUTS_TAGS = 0;
    const size_t HUB_INPUTS_TAGS_SIZE = 0;
    const IdentifierInfo *HUB_INPUTS_IDENTIFIERS = 0;
    const size_t HUB_INPUTS_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *HUB_INPUTS_CONSTANTS = 0;
    const size_t HUB_INPUTS_CONSTANTS_SIZE = 0;
    const SpecificationInfo *HUB_INPUTS_SPECIFICATIONS = 0;
    const size_t HUB_INPUTS_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *HUB_INPUTS_RAWS = 0;
    const size_t HUB_INPUTS_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *HUB_INPUTS_TRAYS = 0;
    const size_t HUB_INPUTS_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> HUB_OUTPUTS_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 106),
        Sim::Info<Sim::Number>("Creator ID", 0.5, 0),
    };
    const size_t HUB_OUTPUTS_NUMBERS_SIZE = sizeof(HUB_OUTPUTS_NUMBERS)/sizeof(HUB_OUTPUTS_NUMBERS[0]);
    const TagInfo *HUB_OUTPUTS_TAGS = 0;
    const size_t HUB_OUTPUTS_TAGS_SIZE = 0;
    const IdentifierInfo *HUB_OUTPUTS_IDENTIFIERS = 0;
    const size_t HUB_OUTPUTS_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *HUB_OUTPUTS_CONSTANTS = 0;
    const size_t HUB_OUTPUTS_CONSTANTS_SIZE = 0;
    const SpecificationInfo *HUB_OUTPUTS_SPECIFICATIONS = 0;
    const size_t HUB_OUTPUTS_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *HUB_OUTPUTS_RAWS = 0;
    const size_t HUB_OUTPUTS_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *HUB_OUTPUTS_TRAYS = 0;
    const size_t HUB_OUTPUTS_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> HUB_VALUES_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 107),
        Sim::Info<Sim::Number>("Creator ID", 0.5, 0),
        Sim::Info<Sim::Number>("Active", 0.5, 0),
        Sim::Info<Sim::Number>("Mode", 0.5, 0),
        Sim::Info<Sim::Number>("Priority", 0.5, 0),
    };
    const size_t HUB_VALUES_NUMBERS_SIZE = sizeof(HUB_VALUES_NUMBERS)/sizeof(HUB_VALUES_NUMBERS[0]);
    const TagInfo *HUB_VALUES_TAGS = 0;
    const size_t HUB_VALUES_TAGS_SIZE = 0;
    const IdentifierInfo *HUB_VALUES_IDENTIFIERS = 0;
    const size_t HUB_VALUES_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *HUB_VALUES_CONSTANTS = 0;
    const size_t HUB_VALUES_CONSTANTS_SIZE = 0;
    const SpecificationInfo *HUB_VALUES_SPECIFICATIONS = 0;
    const size_t HUB_VALUES_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *HUB_VALUES_RAWS = 0;
    const size_t HUB_VALUES_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *HUB_VALUES_TRAYS = 0;
    const size_t HUB_VALUES_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> VEHICLE_INPUTS_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 101),
        Sim::Info<Sim::Number>("Class Inputs", 0.5, 0),
        Sim::Info<Sim::Number>("Head Lights Control", 0.5, 3),
        Sim::Info<Sim::Number>("Tail Lights Control", 0.5, 3),
        Sim::Info<Sim::Number>("Cab Interior Lights Control", 0.5, 0),
        Sim::Info<Sim::Number>("Pan Up Control", 0.5, 0),
        Sim::Info<Sim::Number>("Pan Down Control", 0.5, 0),
        Sim::Info<Sim::Number>("LHS Doors Release Control 1", 0.5, 0),
        Sim::Info<Sim::Number>("LHS Doors Release Control 2", 0.5, 0),
        Sim::Info<Sim::Number>("LHS Signal Buzzer Control", 0.5, 0),
        Sim::Info<Sim::Number>("Left Door Close Interlock Control", 0.5, 0),
        Sim::Info<Sim::Number>("TCMS Function Acknowledge Control", 0.5, 0),
        Sim::Info<Sim::Number>("Silence Alarm Control", 0.5, 0),
        Sim::Info<Sim::Number>("ATO Start Control", 0.5, 0),
        Sim::Info<Sim::Number>("AWS Reset Control", 0.5, 0),
        Sim::Info<Sim::Number>("Traction Sand Control", 0.5, 0),
        Sim::Info<Sim::Number>("DRA Control", 0.5, 0),
        Sim::Info<Sim::Number>("DS Emergency Brake Control", 0.5, 0),
        Sim::Info<Sim::Number>("Signalling Acknowledge", 0.5, 0),
        Sim::Info<Sim::Number>("ATO Stop Control", 0.5, 0),
        Sim::Info<Sim::Number>("Hazard Warning Control", 0.5, 0),
        Sim::Info<Sim::Number>("RHS Signal Buzzer Control", 0.5, 0),
        Sim::Info<Sim::Number>("Right Door Close Interlock Control", 0.5, 0),
        Sim::Info<Sim::Number>("RHS Doors Release Control 1", 0.5, 0),
        Sim::Info<Sim::Number>("RHS Doors Release Control 2", 0.5, 0),
        Sim::Info<Sim::Number>("Warning Horn Control", 0.5, 0),
        Sim::Info<Sim::Number>("Wiper Control", 0.5, 0),
        Sim::Info<Sim::Number>("Depot Whistle Control", 0.5, 0),
        Sim::Info<Sim::Number>("Handset PTT", 0.5, 0),
        Sim::Info<Sim::Number>("Handset Return Switch", 0.5, 0),
        Sim::Info<Sim::Number>("PA Control", 0.5, 0),
        Sim::Info<Sim::Number>("Cab To Cab Control", 0.5, 0),
        Sim::Info<Sim::Number>("PEA CFA Control", 0.5, 0),
        Sim::Info<Sim::Number>("GSMR Selection Control", 0.5, 0),
        Sim::Info<Sim::Number>("Vigilance Acknowledge", 0.5, 0),
        Sim::Info<Sim::Number>("NDS Emergency Brake Control", 0.5, 0),
        Sim::Info<Sim::Number>("Traction Brake Controller", 0.5, -80),
        Sim::Info<Sim::Number>("Passenger Emergency Alarm Override Control", 0.5, 0),
        Sim::Info<Sim::Number>("DSD Foot Pedal", 0.5, 0),
        Sim::Info<Sim::Number>("Master Control Keyswitch", 0.5, 0),
        Sim::Info<Sim::Number>("Master Control Switch", 0.5, 0),
        Sim::Info<Sim::Number>("Service Brake Demand Control", 0.5, 0),
        Sim::Info<Sim::Number>("Traction Demand Control", 0.5, 0),
        Sim::Info<Sim::Number>("Emergency Brake Release Control", 0.5, 0),
        Sim::Info<Sim::Number>("Crew LHS Control Keyswitch", 0.5, 0),
        Sim::Info<Sim::Number>("Crew LHS Signal Buzzer Control", 0.5, 0),
        Sim::Info<Sim::Number>("Crew Left Door Close Control", 0.5, 0),
        Sim::Info<Sim::Number>("TPWS Temporary Isolation Control", 0.5, 0),
        Sim::Info<Sim::Number>("TPWS AWS Isolation Control", 0.5, 0),
        Sim::Info<Sim::Number>("AWS Isolation Control", 0.5, 0),
        Sim::Info<Sim::Number>("PEA Brake Isolation Control", 0.5, 0),
        Sim::Info<Sim::Number>("Brake Continuity Isolation Control", 0.5, 0),
        Sim::Info<Sim::Number>("Door Traction Interlock Isolation Control", 0.5, 0),
        Sim::Info<Sim::Number>("DRA Isolation Control", 0.5, 0),
        Sim::Info<Sim::Number>("CBTC Isolation Control", 0.5, 0),
        Sim::Info<Sim::Number>("Front Bogie Suspension Deflate Control", 0.5, 0),
        Sim::Info<Sim::Number>("Vigilance DSD Isolation Control", 0.5, 0),
        Sim::Info<Sim::Number>("Remote Brake Release Control", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS TPWS AWS Isolation", 0.5, 0),
        Sim::Info<Sim::Number>("Holding Brake Inhibition", 0.5, 0),
        Sim::Info<Sim::Number>("ATP Balise Reader Isolation", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Reset Control", 0.5, 0),
        Sim::Info<Sim::Number>("MLP Isolation Control", 0.5, 0),
        Sim::Info<Sim::Number>("MCB Cab Lighting 1", 0.5, 1),
        Sim::Info<Sim::Number>("MCB TCMS 1", 0.5, 1),
        Sim::Info<Sim::Number>("MCB PIS Audio 1", 0.5, 1),
        Sim::Info<Sim::Number>("MCB Exterior Lights 1", 0.5, 1),
        Sim::Info<Sim::Number>("MCB Emergency Brake", 0.5, 1),
        Sim::Info<Sim::Number>("MCB Door Control", 0.5, 1),
        Sim::Info<Sim::Number>("MCB Cab Ventilation", 0.5, 1),
        Sim::Info<Sim::Number>("MCB Wash Wipe", 0.5, 1),
        Sim::Info<Sim::Number>("MCB Train Control 1", 0.5, 1),
        Sim::Info<Sim::Number>("SPARE", 0.5, 1),
        Sim::Info<Sim::Number>("MCB Demister", 0.5, 1),
        Sim::Info<Sim::Number>("MCB Cab Auxiliaries", 0.5, 1),
        Sim::Info<Sim::Number>("MCB Earth Leakage", 0.5, 1),
        Sim::Info<Sim::Number>("MCB Battery Permanent", 0.5, 1),
        Sim::Info<Sim::Number>("MCB Cab Lighting 2", 0.5, 1),
        Sim::Info<Sim::Number>("MCB TCMS 2", 0.5, 1),
        Sim::Info<Sim::Number>("MCB PIS Audio 2", 0.5, 1),
        Sim::Info<Sim::Number>("MCB Exterior Lights 2", 0.5, 1),
        Sim::Info<Sim::Number>("MCB Brake Continuity", 0.5, 1),
        Sim::Info<Sim::Number>("MCB Door Interlock", 0.5, 1),
        Sim::Info<Sim::Number>("MCB Radio", 0.5, 1),
        Sim::Info<Sim::Number>("MCB PEA Interlock", 0.5, 1),
        Sim::Info<Sim::Number>("MCB Train Control 2", 0.5, 1),
        Sim::Info<Sim::Number>("MCB Cab HVAC Control", 0.5, 1),
        Sim::Info<Sim::Number>("MCB Emergency Brake Recovery", 0.5, 1),
        Sim::Info<Sim::Number>("MCB Remote Brake Release", 0.5, 1),
        Sim::Info<Sim::Number>("MCB AWS TPWS", 0.5, 1),
        Sim::Info<Sim::Number>("MCB ETCS ATP", 0.5, 1),
        Sim::Info<Sim::Number>("MCB OTMR", 0.5, 1),
        Sim::Info<Sim::Number>("Auxiliaries On", 0.5, 0),
        Sim::Info<Sim::Number>("Auxiliaries Off", 0.5, 0),
        Sim::Info<Sim::Number>("PEA CFA Reset", 0.5, 0),
        Sim::Info<Sim::Number>("Crew RHS Control Keyswitch", 0.5, 0),
        Sim::Info<Sim::Number>("Crew RHS Signal Buzzer Control", 0.5, 0),
        Sim::Info<Sim::Number>("Crew Right Door Close Control", 0.5, 0),
        Sim::Info<Sim::Number>("CCTV Monitor Switchover", 0.5, 1),
        Sim::Info<Sim::Number>("Rescue Control", 0.5, 1),
        Sim::Info<Sim::Number>("Rescue Selector Valve", 0.5, 0),
        Sim::Info<Sim::Number>("Cpl Emergency Jumper Cable", 0.5, 0),
        Sim::Info<Sim::Number>("Cpl Rescue Hose Staubli To Schrader", 0.5, 0),
        Sim::Info<Sim::Number>("Cpl Rescue Hose Staubli To Glad Hands", 0.5, 0),
        Sim::Info<Sim::Number>("Cpl Rescue Hose", 0.5, 0),
        Sim::Info<Sim::Number>("Cpl Scharfenburg Type 10", 0.5, 0),
        Sim::Info<Sim::Number>("Cpl Dellner Type 12", 0.5, 0),
        Sim::Info<Sim::Number>("Cpl Hook Adapter", 0.5, 0),
        Sim::Info<Sim::Number>("Cpl Scharfenburg Type 10 Adapter", 0.5, 0),
        Sim::Info<Sim::Number>("Cpl Latch Adapter", 0.5, 0),
        Sim::Info<Sim::Number>("Cpl Tightlock Adapter", 0.5, 0),
        Sim::Info<Sim::Number>("Cpl Clevis", 0.5, 0),
        Sim::Info<Sim::Number>("Cpl Transition Joint", 0.5, 0),
        Sim::Info<Sim::Number>("Coupler Isolation Cock", 0.5, 1),
        Sim::Info<Sim::Number>("Rescue Hose Isolating Cock", 0.5, 0),
        Sim::Info<Sim::Number>("Manual Uncoupling Handle", 0.5, 0),
        Sim::Info<Sim::Number>("Rescue Jumper Socket DS", 0.5, 0),
        Sim::Info<Sim::Number>("Rescue Jumper Socket NDS", 0.5, 0),
        Sim::Info<Sim::Number>("Rescue Jumper Socket DS Autotrain", 0.5, 0),
        Sim::Info<Sim::Number>("Rescue Jumper Socket NDS Autotrain", 0.5, 0),
        Sim::Info<Sim::Number>("Door A Open Pushbutton Internal LHS", 0.5, 0),
        Sim::Info<Sim::Number>("Door A Open Pushbutton Internal RHS", 0.5, 0),
        Sim::Info<Sim::Number>("Door A Open Pushbutton External", 0.5, 0),
        Sim::Info<Sim::Number>("Door A Out Of Service Lock", 0.5, 0),
        Sim::Info<Sim::Number>("Door A Emergency Egress Device", 0.5, 0),
        Sim::Info<Sim::Number>("Door A Open And Close Widget", 0.5, 0),
        Sim::Info<Sim::Number>("Door A Emergency Access Device", 0.5, 0),
        Sim::Info<Sim::Number>("Door A Passenger Emergency Alarm", 0.5, 0),
        Sim::Info<Sim::Number>("Door B Open Pushbutton Internal LHS", 0.5, 0),
        Sim::Info<Sim::Number>("Door B Open Pushbutton Internal RHS", 0.5, 0),
        Sim::Info<Sim::Number>("Door B Open Pushbutton External", 0.5, 0),
        Sim::Info<Sim::Number>("Door B Out Of Service Lock", 0.5, 0),
        Sim::Info<Sim::Number>("Door B Emergency Egress Device", 0.5, 0),
        Sim::Info<Sim::Number>("Door B Open And Close Widget", 0.5, 0),
        Sim::Info<Sim::Number>("Door B Emergency Access Device", 0.5, 0),
        Sim::Info<Sim::Number>("Door C Open Pushbutton Internal LHS", 0.5, 0),
        Sim::Info<Sim::Number>("Door C Open Pushbutton Internal RHS", 0.5, 0),
        Sim::Info<Sim::Number>("Door C Open Pushbutton External", 0.5, 0),
        Sim::Info<Sim::Number>("Door C Out Of Service Lock", 0.5, 0),
        Sim::Info<Sim::Number>("Door C Emergency Egress Device", 0.5, 0),
        Sim::Info<Sim::Number>("Door C Open And Close Widget", 0.5, 0),
        Sim::Info<Sim::Number>("Door C Emergency Access Device", 0.5, 0),
        Sim::Info<Sim::Number>("Door C Passenger Emergency Alarm", 0.5, 0),
        Sim::Info<Sim::Number>("Door D Open Pushbutton Internal LHS", 0.5, 0),
        Sim::Info<Sim::Number>("Door D Open Pushbutton Internal RHS", 0.5, 0),
        Sim::Info<Sim::Number>("Door D Open Pushbutton External", 0.5, 0),
        Sim::Info<Sim::Number>("Door D Out Of Service Lock", 0.5, 0),
        Sim::Info<Sim::Number>("Door D Emergency Egress Device", 0.5, 0),
        Sim::Info<Sim::Number>("Door D Open And Close Widget", 0.5, 0),
        Sim::Info<Sim::Number>("Door D Emergency Access Device", 0.5, 0),
        Sim::Info<Sim::Number>("Door E Open Pushbutton Internal LHS", 0.5, 0),
        Sim::Info<Sim::Number>("Door E Open Pushbutton Internal RHS", 0.5, 0),
        Sim::Info<Sim::Number>("Door E Open Pushbutton External", 0.5, 0),
        Sim::Info<Sim::Number>("Door E Out Of Service Lock", 0.5, 0),
        Sim::Info<Sim::Number>("Door E Emergency Egress Device", 0.5, 0),
        Sim::Info<Sim::Number>("Door E Open And Close Widget", 0.5, 0),
        Sim::Info<Sim::Number>("Door E Emergency Access Device", 0.5, 0),
        Sim::Info<Sim::Number>("Door E Passenger Emergency Alarm", 0.5, 0),
        Sim::Info<Sim::Number>("Door F Open Pushbutton Internal LHS", 0.5, 0),
        Sim::Info<Sim::Number>("Door F Open Pushbutton Internal RHS", 0.5, 0),
        Sim::Info<Sim::Number>("Door F Open Pushbutton External", 0.5, 0),
        Sim::Info<Sim::Number>("Door F Out Of Service Lock", 0.5, 0),
        Sim::Info<Sim::Number>("Door F Emergency Egress Device", 0.5, 0),
        Sim::Info<Sim::Number>("Door F Open And Close Widget", 0.5, 0),
        Sim::Info<Sim::Number>("Door F Emergency Access Device", 0.5, 0),
        Sim::Info<Sim::Number>("Parking Brake Manual Release 1", 0.5, 0),
        Sim::Info<Sim::Number>("Parking Brake Manual Release 2", 0.5, 0),
        Sim::Info<Sim::Number>("ADD Isolated Valve", 0.5, 0),
        Sim::Info<Sim::Number>("Call For Aid 1", 0.5, 0),
        Sim::Info<Sim::Number>("Call For Aid 2", 0.5, 0),
        Sim::Info<Sim::Number>("Call For Aid 3", 0.5, 0),
        Sim::Info<Sim::Number>("Call For Aid 4", 0.5, 0),
        Sim::Info<Sim::Number>("PSD Enable Local Control", 0.5, 0),
        Sim::Info<Sim::Number>("PSD Operate Door", 0.5, 0),
        Sim::Info<Sim::Number>("SPT Push To Talk", 0.5, 0),
        Sim::Info<Sim::Number>("SPT Return Switch", 0.5, 1),
        Sim::Info<Sim::Number>("Train Ready To Start Button", 0.5, 1),
        Sim::Info<Sim::Number>("Target Velocity", 0.0010, 0),
        Sim::Info<Sim::Number>("Power CB", 0.5, 0),
        Sim::Info<Sim::Number>("Open Door L", 0.5, 0),
        Sim::Info<Sim::Number>("Open Door R", 0.5, 0),
        Sim::Info<Sim::Number>("Close Door R", 0.5, 0),
        Sim::Info<Sim::Number>("Close Door L", 0.5, 0),
        Sim::Info<Sim::Number>("Drive Next Station", 0.5, 0),
        Sim::Info<Sim::Number>("Auto Drive", 0.5, 0),
        Sim::Info<Sim::Number>("Horn Control", 0.5, 0),
        Sim::Info<Sim::Number>("Windscreen Wiper Control", 0.5, 0),
        Sim::Info<Sim::Number>("Power Brake Controller", 0.5, 14),
    };
    const size_t VEHICLE_INPUTS_NUMBERS_SIZE = sizeof(VEHICLE_INPUTS_NUMBERS)/sizeof(VEHICLE_INPUTS_NUMBERS[0]);
    const TagInfo *VEHICLE_INPUTS_TAGS = 0;
    const size_t VEHICLE_INPUTS_TAGS_SIZE = 0;
    const IdentifierInfo *VEHICLE_INPUTS_IDENTIFIERS = 0;
    const size_t VEHICLE_INPUTS_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *VEHICLE_INPUTS_CONSTANTS = 0;
    const size_t VEHICLE_INPUTS_CONSTANTS_SIZE = 0;
    const SpecificationInfo *VEHICLE_INPUTS_SPECIFICATIONS = 0;
    const size_t VEHICLE_INPUTS_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *VEHICLE_INPUTS_RAWS = 0;
    const size_t VEHICLE_INPUTS_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *VEHICLE_INPUTS_TRAYS = 0;
    const size_t VEHICLE_INPUTS_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> VEHICLE_INPUTS_VALUES_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 103),
        Sim::Info<Sim::Number>("Class Values", 0.5, 0),
        Sim::Info<Sim::Number>("Head Lights Control", 0.5, 0),
        Sim::Info<Sim::Number>("Tail Lights Control", 0.5, 0),
        Sim::Info<Sim::Number>("Cab Interior Lights Control", 0.5, 0),
        Sim::Info<Sim::Number>("Pan Up Control", 0.5, 0),
        Sim::Info<Sim::Number>("Pan Down Control", 0.5, 0),
        Sim::Info<Sim::Number>("LHS Doors Release Control 1", 0.5, 0),
        Sim::Info<Sim::Number>("LHS Doors Release Control 2", 0.5, 0),
        Sim::Info<Sim::Number>("LHS Signal Buzzer Control", 0.5, 0),
        Sim::Info<Sim::Number>("Left Door Close Interlock Control", 0.5, 0),
        Sim::Info<Sim::Number>("TCMS Function Acknowledge Control", 0.5, 0),
        Sim::Info<Sim::Number>("Silence Alarm Control", 0.5, 0),
        Sim::Info<Sim::Number>("ATO Start Control", 0.5, 0),
        Sim::Info<Sim::Number>("AWS Reset Control", 0.5, 0),
        Sim::Info<Sim::Number>("Traction Sand Control", 0.5, 0),
        Sim::Info<Sim::Number>("DRA Control", 0.5, 0),
        Sim::Info<Sim::Number>("DS Emergency Brake Control", 0.5, 0),
        Sim::Info<Sim::Number>("Signalling Acknowledge", 0.5, 0),
        Sim::Info<Sim::Number>("ATO Stop Control", 0.5, 0),
        Sim::Info<Sim::Number>("Hazard Warning Control", 0.5, 0),
        Sim::Info<Sim::Number>("RHS Signal Buzzer Control", 0.5, 0),
        Sim::Info<Sim::Number>("Right Door Close Interlock Control", 0.5, 0),
        Sim::Info<Sim::Number>("RHS Doors Release Control 1", 0.5, 0),
        Sim::Info<Sim::Number>("RHS Doors Release Control 2", 0.5, 0),
        Sim::Info<Sim::Number>("Warning Horn Control", 0.5, 0),
        Sim::Info<Sim::Number>("Wiper Control", 0.5, 0),
        Sim::Info<Sim::Number>("Depot Whistle Control", 0.5, 0),
        Sim::Info<Sim::Number>("Handset PTT", 0.5, 0),
        Sim::Info<Sim::Number>("Handset Return Switch", 0.5, 0),
        Sim::Info<Sim::Number>("PA Control", 0.5, 0),
        Sim::Info<Sim::Number>("Cab To Cab Control", 0.5, 0),
        Sim::Info<Sim::Number>("PEA CFA Control", 0.5, 0),
        Sim::Info<Sim::Number>("GSMR Selection Control", 0.5, 0),
        Sim::Info<Sim::Number>("Vigilance Acknowledge", 0.5, 0),
        Sim::Info<Sim::Number>("NDS Emergency Brake Control", 0.5, 0),
        Sim::Info<Sim::Number>("Traction Brake Controller", 0.5, 0),
        Sim::Info<Sim::Number>("Passenger Emergency Alarm Override Control", 0.5, 0),
        Sim::Info<Sim::Number>("DSD Foot Pedal", 0.5, 0),
        Sim::Info<Sim::Number>("Master Control Keyswitch", 0.5, 0),
        Sim::Info<Sim::Number>("Master Control Switch", 0.5, 0),
        Sim::Info<Sim::Number>("Service Brake Demand Control", 0.5, 0),
        Sim::Info<Sim::Number>("Traction Demand Control", 0.5, 0),
        Sim::Info<Sim::Number>("Emergency Brake Release Control", 0.5, 0),
        Sim::Info<Sim::Number>("Crew LHS Control Keyswitch", 0.5, 0),
        Sim::Info<Sim::Number>("Crew LHS Signal Buzzer Control", 0.5, 0),
        Sim::Info<Sim::Number>("Crew Left Door Close Control", 0.5, 0),
        Sim::Info<Sim::Number>("TPWS Temporary Isolation Control", 0.5, 0),
        Sim::Info<Sim::Number>("TPWS AWS Isolation Control", 0.5, 0),
        Sim::Info<Sim::Number>("AWS Isolation Control", 0.5, 0),
        Sim::Info<Sim::Number>("PEA Brake Isolation Control", 0.5, 0),
        Sim::Info<Sim::Number>("Brake Continuity Isolation Control", 0.5, 0),
        Sim::Info<Sim::Number>("Door Traction Interlock Isolation Control", 0.5, 0),
        Sim::Info<Sim::Number>("DRA Isolation Control", 0.5, 0),
        Sim::Info<Sim::Number>("CBTC Isolation Control", 0.5, 0),
        Sim::Info<Sim::Number>("Front Bogie Suspension Deflate Control", 0.5, 0),
        Sim::Info<Sim::Number>("Vigilance DSD Isolation Control", 0.5, 0),
        Sim::Info<Sim::Number>("Remote Brake Release Control", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS TPWS AWS Isolation", 0.5, 0),
        Sim::Info<Sim::Number>("Holding Brake Inhibition", 0.5, 0),
        Sim::Info<Sim::Number>("ATP Balise Reader Isolation", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Reset Control", 0.5, 0),
        Sim::Info<Sim::Number>("MLP Isolation Control", 0.5, 0),
        Sim::Info<Sim::Number>("MCB Cab Lighting 1", 0.5, 0),
        Sim::Info<Sim::Number>("PT MCB Cab Lighting 1 Trip", 0.5, 0),
        Sim::Info<Sim::Number>("MCB TCMS 1", 0.5, 0),
        Sim::Info<Sim::Number>("PT MCB TCMS 1 Trip", 0.5, 0),
        Sim::Info<Sim::Number>("MCB PIS Audio 1", 0.5, 0),
        Sim::Info<Sim::Number>("PT MCB PIS Audio 1 Trip", 0.5, 0),
        Sim::Info<Sim::Number>("MCB Exterior Lights 1", 0.5, 0),
        Sim::Info<Sim::Number>("PT MCB Exterior Lights 1 Trip", 0.5, 0),
        Sim::Info<Sim::Number>("MCB Emergency Brake", 0.5, 0),
        Sim::Info<Sim::Number>("PT MCB Emergency Brake Trip", 0.5, 0),
        Sim::Info<Sim::Number>("MCB Door Control", 0.5, 0),
        Sim::Info<Sim::Number>("PT MCB Door Control Trip", 0.5, 0),
        Sim::Info<Sim::Number>("MCB Cab Ventilation", 0.5, 0),
        Sim::Info<Sim::Number>("PT MCB Cab Ventilation Trip", 0.5, 0),
        Sim::Info<Sim::Number>("MCB Wash Wipe", 0.5, 0),
        Sim::Info<Sim::Number>("PT MCB Wash Wipe Trip", 0.5, 0),
        Sim::Info<Sim::Number>("MCB Train Control 1", 0.5, 0),
        Sim::Info<Sim::Number>("PT MCB Train Control 1 Trip", 0.5, 0),
        Sim::Info<Sim::Number>("SPARE", 0.5, 0),
        Sim::Info<Sim::Number>("PT SPARE Trip", 0.5, 0),
        Sim::Info<Sim::Number>("MCB Demister", 0.5, 0),
        Sim::Info<Sim::Number>("PT MCB Demister Trip", 0.5, 0),
        Sim::Info<Sim::Number>("MCB Cab Auxiliaries", 0.5, 0),
        Sim::Info<Sim::Number>("PT MCB Cab Auxiliaries Trip", 0.5, 0),
        Sim::Info<Sim::Number>("MCB Earth Leakage", 0.5, 0),
        Sim::Info<Sim::Number>("PT MCB Earth Leakage Trip", 0.5, 0),
        Sim::Info<Sim::Number>("MCB Battery Permanent", 0.5, 0),
        Sim::Info<Sim::Number>("PT MCB Battery Permanent Trip", 0.5, 0),
        Sim::Info<Sim::Number>("MCB Cab Lighting 2", 0.5, 0),
        Sim::Info<Sim::Number>("PT MCB Cab Lighting 2 Trip", 0.5, 0),
        Sim::Info<Sim::Number>("MCB TCMS 2", 0.5, 0),
        Sim::Info<Sim::Number>("PT MCB TCMS 2 Trip", 0.5, 0),
        Sim::Info<Sim::Number>("MCB PIS Audio 2", 0.5, 0),
        Sim::Info<Sim::Number>("PT MCB PIS Audio 2 Trip", 0.5, 0),
        Sim::Info<Sim::Number>("MCB Exterior Lights 2", 0.5, 0),
        Sim::Info<Sim::Number>("PT MCB Exterior Lights 2 Trip", 0.5, 0),
        Sim::Info<Sim::Number>("MCB Brake Continuity", 0.5, 0),
        Sim::Info<Sim::Number>("PT MCB Brake Continuity Trip", 0.5, 0),
        Sim::Info<Sim::Number>("MCB Door Interlock", 0.5, 0),
        Sim::Info<Sim::Number>("PT MCB Door Interlock Trip", 0.5, 0),
        Sim::Info<Sim::Number>("MCB Radio", 0.5, 0),
        Sim::Info<Sim::Number>("PT MCB Radio Trip", 0.5, 0),
        Sim::Info<Sim::Number>("MCB PEA Interlock", 0.5, 0),
        Sim::Info<Sim::Number>("PT MCB PEA Interlock Trip", 0.5, 0),
        Sim::Info<Sim::Number>("MCB Train Control 2", 0.5, 0),
        Sim::Info<Sim::Number>("PT MCB Train Control 2 Trip", 0.5, 0),
        Sim::Info<Sim::Number>("MCB Cab HVAC Control", 0.5, 0),
        Sim::Info<Sim::Number>("PT MCB Cab HVAC Control Trip", 0.5, 0),
        Sim::Info<Sim::Number>("MCB Emergency Brake Recovery", 0.5, 0),
        Sim::Info<Sim::Number>("PT MCB Emergency Brake Recovery Trip", 0.5, 0),
        Sim::Info<Sim::Number>("MCB Remote Brake Release", 0.5, 0),
        Sim::Info<Sim::Number>("PT MCB Remote Brake Release Trip", 0.5, 0),
        Sim::Info<Sim::Number>("MCB AWS TPWS", 0.5, 0),
        Sim::Info<Sim::Number>("PT MCB AWS TPWS Trip", 0.5, 0),
        Sim::Info<Sim::Number>("MCB ETCS ATP", 0.5, 0),
        Sim::Info<Sim::Number>("PT MCB ETCS ATP Trip", 0.5, 0),
        Sim::Info<Sim::Number>("MCB OTMR", 0.5, 0),
        Sim::Info<Sim::Number>("PT MCB OTMR Trip", 0.5, 0),
        Sim::Info<Sim::Number>("Auxiliaries On", 0.5, 0),
        Sim::Info<Sim::Number>("Auxiliaries Off", 0.5, 0),
        Sim::Info<Sim::Number>("PEA CFA Reset", 0.5, 0),
        Sim::Info<Sim::Number>("Crew RHS Control Keyswitch", 0.5, 0),
        Sim::Info<Sim::Number>("Crew RHS Signal Buzzer Control", 0.5, 0),
        Sim::Info<Sim::Number>("Crew Right Door Close Control", 0.5, 0),
        Sim::Info<Sim::Number>("CCTV Monitor Switchover", 0.5, 0),
        Sim::Info<Sim::Number>("Rescue Control", 0.5, 0),
        Sim::Info<Sim::Number>("Rescue Selector Valve", 0.5, 0),
        Sim::Info<Sim::Number>("Cpl Emergency Jumper Cable", 0.5, 0),
        Sim::Info<Sim::Number>("Cpl Rescue Hose Staubli To Schrader", 0.5, 0),
        Sim::Info<Sim::Number>("Cpl Rescue Hose Staubli To Glad Hands", 0.5, 0),
        Sim::Info<Sim::Number>("Cpl Rescue Hose", 0.5, 0),
        Sim::Info<Sim::Number>("Cpl Scharfenburg Type 10", 0.5, 0),
        Sim::Info<Sim::Number>("Cpl Dellner Type 12", 0.5, 0),
        Sim::Info<Sim::Number>("Cpl Hook Adapter", 0.5, 0),
        Sim::Info<Sim::Number>("Cpl Scharfenburg Type 10 Adapter", 0.5, 0),
        Sim::Info<Sim::Number>("Cpl Latch Adapter", 0.5, 0),
        Sim::Info<Sim::Number>("Cpl Tightlock Adapter", 0.5, 0),
        Sim::Info<Sim::Number>("Cpl Clevis", 0.5, 0),
        Sim::Info<Sim::Number>("Cpl Transition Joint", 0.5, 0),
        Sim::Info<Sim::Number>("Coupler Isolation Cock", 0.5, 0),
        Sim::Info<Sim::Number>("Rescue Hose Isolating Cock", 0.5, 0),
        Sim::Info<Sim::Number>("Manual Uncoupling Handle", 0.5, 0),
        Sim::Info<Sim::Number>("Rescue Jumper Socket DS", 0.5, 0),
        Sim::Info<Sim::Number>("Rescue Jumper Socket NDS", 0.5, 0),
        Sim::Info<Sim::Number>("Rescue Jumper Socket DS Autotrain", 0.5, 0),
        Sim::Info<Sim::Number>("Rescue Jumper Socket NDS Autotrain", 0.5, 0),
        Sim::Info<Sim::Number>("Door A Open Pushbutton Internal LHS", 0.5, 0),
        Sim::Info<Sim::Number>("Door A Open Pushbutton Internal RHS", 0.5, 0),
        Sim::Info<Sim::Number>("Door A Open Pushbutton External", 0.5, 0),
        Sim::Info<Sim::Number>("Door A Out Of Service Lock", 0.5, 0),
        Sim::Info<Sim::Number>("Door A Emergency Egress Device", 0.5, 0),
        Sim::Info<Sim::Number>("Door A Open And Close Widget", 0.5, 0),
        Sim::Info<Sim::Number>("Door A Emergency Access Device", 0.5, 0),
        Sim::Info<Sim::Number>("Door A Passenger Emergency Alarm", 0.5, 0),
        Sim::Info<Sim::Number>("Door B Open Pushbutton Internal LHS", 0.5, 0),
        Sim::Info<Sim::Number>("Door B Open Pushbutton Internal RHS", 0.5, 0),
        Sim::Info<Sim::Number>("Door B Open Pushbutton External", 0.5, 0),
        Sim::Info<Sim::Number>("Door B Out Of Service Lock", 0.5, 0),
        Sim::Info<Sim::Number>("Door B Emergency Egress Device", 0.5, 0),
        Sim::Info<Sim::Number>("Door B Open And Close Widget", 0.5, 0),
        Sim::Info<Sim::Number>("Door B Emergency Access Device", 0.5, 0),
        Sim::Info<Sim::Number>("Door C Open Pushbutton Internal LHS", 0.5, 0),
        Sim::Info<Sim::Number>("Door C Open Pushbutton Internal RHS", 0.5, 0),
        Sim::Info<Sim::Number>("Door C Open Pushbutton External", 0.5, 0),
        Sim::Info<Sim::Number>("Door C Out Of Service Lock", 0.5, 0),
        Sim::Info<Sim::Number>("Door C Emergency Egress Device", 0.5, 0),
        Sim::Info<Sim::Number>("Door C Open And Close Widget", 0.5, 0),
        Sim::Info<Sim::Number>("Door C Emergency Access Device", 0.5, 0),
        Sim::Info<Sim::Number>("Door C Passenger Emergency Alarm", 0.5, 0),
        Sim::Info<Sim::Number>("Door D Open Pushbutton Internal LHS", 0.5, 0),
        Sim::Info<Sim::Number>("Door D Open Pushbutton Internal RHS", 0.5, 0),
        Sim::Info<Sim::Number>("Door D Open Pushbutton External", 0.5, 0),
        Sim::Info<Sim::Number>("Door D Out Of Service Lock", 0.5, 0),
        Sim::Info<Sim::Number>("Door D Emergency Egress Device", 0.5, 0),
        Sim::Info<Sim::Number>("Door D Open And Close Widget", 0.5, 0),
        Sim::Info<Sim::Number>("Door D Emergency Access Device", 0.5, 0),
        Sim::Info<Sim::Number>("Door E Open Pushbutton Internal LHS", 0.5, 0),
        Sim::Info<Sim::Number>("Door E Open Pushbutton Internal RHS", 0.5, 0),
        Sim::Info<Sim::Number>("Door E Open Pushbutton External", 0.5, 0),
        Sim::Info<Sim::Number>("Door E Out Of Service Lock", 0.5, 0),
        Sim::Info<Sim::Number>("Door E Emergency Egress Device", 0.5, 0),
        Sim::Info<Sim::Number>("Door E Open And Close Widget", 0.5, 0),
        Sim::Info<Sim::Number>("Door E Emergency Access Device", 0.5, 0),
        Sim::Info<Sim::Number>("Door E Passenger Emergency Alarm", 0.5, 0),
        Sim::Info<Sim::Number>("Door F Open Pushbutton Internal LHS", 0.5, 0),
        Sim::Info<Sim::Number>("Door F Open Pushbutton Internal RHS", 0.5, 0),
        Sim::Info<Sim::Number>("Door F Open Pushbutton External", 0.5, 0),
        Sim::Info<Sim::Number>("Door F Out Of Service Lock", 0.5, 0),
        Sim::Info<Sim::Number>("Door F Emergency Egress Device", 0.5, 0),
        Sim::Info<Sim::Number>("Door F Open And Close Widget", 0.5, 0),
        Sim::Info<Sim::Number>("Door F Emergency Access Device", 0.5, 0),
        Sim::Info<Sim::Number>("Parking Brake Manual Release 1", 0.5, 0),
        Sim::Info<Sim::Number>("Parking Brake Manual Release 2", 0.5, 0),
        Sim::Info<Sim::Number>("ADD Isolated Valve", 0.5, 0),
        Sim::Info<Sim::Number>("Call For Aid 1", 0.5, 0),
        Sim::Info<Sim::Number>("Call For Aid 2", 0.5, 0),
        Sim::Info<Sim::Number>("Call For Aid 3", 0.5, 0),
        Sim::Info<Sim::Number>("Call For Aid 4", 0.5, 0),
        Sim::Info<Sim::Number>("PSD Enable Local Control", 0.5, 0),
        Sim::Info<Sim::Number>("PSD Operate Door", 0.5, 0),
        Sim::Info<Sim::Number>("SPT Push To Talk", 0.5, 0),
        Sim::Info<Sim::Number>("SPT Return Switch", 0.5, 0),
        Sim::Info<Sim::Number>("Train Ready To Start Button", 0.5, 0),
        Sim::Info<Sim::Number>("Target Velocity", 0.0010, 0),
        Sim::Info<Sim::Number>("Power CB", 0.5, 0),
        Sim::Info<Sim::Number>("Open Door L", 0.5, 0),
        Sim::Info<Sim::Number>("Open Door R", 0.5, 0),
        Sim::Info<Sim::Number>("Close Door R", 0.5, 0),
        Sim::Info<Sim::Number>("Close Door L", 0.5, 0),
        Sim::Info<Sim::Number>("Drive Next Station", 0.5, 0),
        Sim::Info<Sim::Number>("Auto Drive", 0.5, 0),
        Sim::Info<Sim::Number>("Horn Control", 0.5, 0),
        Sim::Info<Sim::Number>("Windscreen Wiper Control", 0.5, 0),
    };
    const size_t VEHICLE_INPUTS_VALUES_NUMBERS_SIZE = sizeof(VEHICLE_INPUTS_VALUES_NUMBERS)/sizeof(VEHICLE_INPUTS_VALUES_NUMBERS[0]);
    const TagInfo *VEHICLE_INPUTS_VALUES_TAGS = 0;
    const size_t VEHICLE_INPUTS_VALUES_TAGS_SIZE = 0;
    const IdentifierInfo *VEHICLE_INPUTS_VALUES_IDENTIFIERS = 0;
    const size_t VEHICLE_INPUTS_VALUES_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *VEHICLE_INPUTS_VALUES_CONSTANTS = 0;
    const size_t VEHICLE_INPUTS_VALUES_CONSTANTS_SIZE = 0;
    const SpecificationInfo *VEHICLE_INPUTS_VALUES_SPECIFICATIONS = 0;
    const size_t VEHICLE_INPUTS_VALUES_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *VEHICLE_INPUTS_VALUES_RAWS = 0;
    const size_t VEHICLE_INPUTS_VALUES_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *VEHICLE_INPUTS_VALUES_TRAYS = 0;
    const size_t VEHICLE_INPUTS_VALUES_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> VEHICLE_INPUTS_MODES_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 104),
        Sim::Info<Sim::Number>("Class Modes", 0.5, 0),
        Sim::Info<Sim::Number>("Head Lights Control", 0.5, 1),
        Sim::Info<Sim::Number>("Tail Lights Control", 0.5, 1),
        Sim::Info<Sim::Number>("Cab Interior Lights Control", 0.5, 1),
        Sim::Info<Sim::Number>("Pan Up Control", 0.5, 1),
        Sim::Info<Sim::Number>("Pan Down Control", 0.5, 1),
        Sim::Info<Sim::Number>("LHS Doors Release Control 1", 0.5, 1),
        Sim::Info<Sim::Number>("LHS Doors Release Control 2", 0.5, 1),
        Sim::Info<Sim::Number>("LHS Signal Buzzer Control", 0.5, 1),
        Sim::Info<Sim::Number>("Left Door Close Interlock Control", 0.5, 1),
        Sim::Info<Sim::Number>("TCMS Function Acknowledge Control", 0.5, 1),
        Sim::Info<Sim::Number>("Silence Alarm Control", 0.5, 1),
        Sim::Info<Sim::Number>("ATO Start Control", 0.5, 1),
        Sim::Info<Sim::Number>("AWS Reset Control", 0.5, 1),
        Sim::Info<Sim::Number>("Traction Sand Control", 0.5, 1),
        Sim::Info<Sim::Number>("DRA Control", 0.5, 1),
        Sim::Info<Sim::Number>("DS Emergency Brake Control", 0.5, 1),
        Sim::Info<Sim::Number>("Signalling Acknowledge", 0.5, 1),
        Sim::Info<Sim::Number>("ATO Stop Control", 0.5, 1),
        Sim::Info<Sim::Number>("Hazard Warning Control", 0.5, 1),
        Sim::Info<Sim::Number>("RHS Signal Buzzer Control", 0.5, 1),
        Sim::Info<Sim::Number>("Right Door Close Interlock Control", 0.5, 1),
        Sim::Info<Sim::Number>("RHS Doors Release Control 1", 0.5, 1),
        Sim::Info<Sim::Number>("RHS Doors Release Control 2", 0.5, 1),
        Sim::Info<Sim::Number>("Warning Horn Control", 0.5, 1),
        Sim::Info<Sim::Number>("Wiper Control", 0.5, 1),
        Sim::Info<Sim::Number>("Depot Whistle Control", 0.5, 1),
        Sim::Info<Sim::Number>("Handset PTT", 0.5, 1),
        Sim::Info<Sim::Number>("Handset Return Switch", 0.5, 1),
        Sim::Info<Sim::Number>("PA Control", 0.5, 1),
        Sim::Info<Sim::Number>("Cab To Cab Control", 0.5, 1),
        Sim::Info<Sim::Number>("PEA CFA Control", 0.5, 1),
        Sim::Info<Sim::Number>("GSMR Selection Control", 0.5, 1),
        Sim::Info<Sim::Number>("Vigilance Acknowledge", 0.5, 1),
        Sim::Info<Sim::Number>("NDS Emergency Brake Control", 0.5, 1),
        Sim::Info<Sim::Number>("Traction Brake Controller", 0.5, 1),
        Sim::Info<Sim::Number>("Passenger Emergency Alarm Override Control", 0.5, 1),
        Sim::Info<Sim::Number>("DSD Foot Pedal", 0.5, 1),
        Sim::Info<Sim::Number>("Master Control Keyswitch", 0.5, 1),
        Sim::Info<Sim::Number>("Master Control Switch", 0.5, 1),
        Sim::Info<Sim::Number>("Service Brake Demand Control", 0.5, 1),
        Sim::Info<Sim::Number>("Traction Demand Control", 0.5, 1),
        Sim::Info<Sim::Number>("Emergency Brake Release Control", 0.5, 1),
        Sim::Info<Sim::Number>("Crew LHS Control Keyswitch", 0.5, 1),
        Sim::Info<Sim::Number>("Crew LHS Signal Buzzer Control", 0.5, 1),
        Sim::Info<Sim::Number>("Crew Left Door Close Control", 0.5, 1),
        Sim::Info<Sim::Number>("TPWS Temporary Isolation Control", 0.5, 1),
        Sim::Info<Sim::Number>("TPWS AWS Isolation Control", 0.5, 1),
        Sim::Info<Sim::Number>("AWS Isolation Control", 0.5, 1),
        Sim::Info<Sim::Number>("PEA Brake Isolation Control", 0.5, 1),
        Sim::Info<Sim::Number>("Brake Continuity Isolation Control", 0.5, 1),
        Sim::Info<Sim::Number>("Door Traction Interlock Isolation Control", 0.5, 1),
        Sim::Info<Sim::Number>("DRA Isolation Control", 0.5, 1),
        Sim::Info<Sim::Number>("CBTC Isolation Control", 0.5, 1),
        Sim::Info<Sim::Number>("Front Bogie Suspension Deflate Control", 0.5, 1),
        Sim::Info<Sim::Number>("Vigilance DSD Isolation Control", 0.5, 1),
        Sim::Info<Sim::Number>("Remote Brake Release Control", 0.5, 1),
        Sim::Info<Sim::Number>("ETCS TPWS AWS Isolation", 0.5, 1),
        Sim::Info<Sim::Number>("Holding Brake Inhibition", 0.5, 1),
        Sim::Info<Sim::Number>("ATP Balise Reader Isolation", 0.5, 1),
        Sim::Info<Sim::Number>("ETCS Reset Control", 0.5, 1),
        Sim::Info<Sim::Number>("MLP Isolation Control", 0.5, 1),
        Sim::Info<Sim::Number>("MCB Cab Lighting 1", 0.5, 1),
        Sim::Info<Sim::Number>("PT MCB Cab Lighting 1 Trip", 0.5, 1),
        Sim::Info<Sim::Number>("MCB TCMS 1", 0.5, 1),
        Sim::Info<Sim::Number>("PT MCB TCMS 1 Trip", 0.5, 1),
        Sim::Info<Sim::Number>("MCB PIS Audio 1", 0.5, 1),
        Sim::Info<Sim::Number>("PT MCB PIS Audio 1 Trip", 0.5, 1),
        Sim::Info<Sim::Number>("MCB Exterior Lights 1", 0.5, 1),
        Sim::Info<Sim::Number>("PT MCB Exterior Lights 1 Trip", 0.5, 1),
        Sim::Info<Sim::Number>("MCB Emergency Brake", 0.5, 1),
        Sim::Info<Sim::Number>("PT MCB Emergency Brake Trip", 0.5, 1),
        Sim::Info<Sim::Number>("MCB Door Control", 0.5, 1),
        Sim::Info<Sim::Number>("PT MCB Door Control Trip", 0.5, 1),
        Sim::Info<Sim::Number>("MCB Cab Ventilation", 0.5, 1),
        Sim::Info<Sim::Number>("PT MCB Cab Ventilation Trip", 0.5, 1),
        Sim::Info<Sim::Number>("MCB Wash Wipe", 0.5, 1),
        Sim::Info<Sim::Number>("PT MCB Wash Wipe Trip", 0.5, 1),
        Sim::Info<Sim::Number>("MCB Train Control 1", 0.5, 1),
        Sim::Info<Sim::Number>("PT MCB Train Control 1 Trip", 0.5, 1),
        Sim::Info<Sim::Number>("SPARE", 0.5, 1),
        Sim::Info<Sim::Number>("PT SPARE Trip", 0.5, 1),
        Sim::Info<Sim::Number>("MCB Demister", 0.5, 1),
        Sim::Info<Sim::Number>("PT MCB Demister Trip", 0.5, 1),
        Sim::Info<Sim::Number>("MCB Cab Auxiliaries", 0.5, 1),
        Sim::Info<Sim::Number>("PT MCB Cab Auxiliaries Trip", 0.5, 1),
        Sim::Info<Sim::Number>("MCB Earth Leakage", 0.5, 1),
        Sim::Info<Sim::Number>("PT MCB Earth Leakage Trip", 0.5, 1),
        Sim::Info<Sim::Number>("MCB Battery Permanent", 0.5, 1),
        Sim::Info<Sim::Number>("PT MCB Battery Permanent Trip", 0.5, 1),
        Sim::Info<Sim::Number>("MCB Cab Lighting 2", 0.5, 1),
        Sim::Info<Sim::Number>("PT MCB Cab Lighting 2 Trip", 0.5, 1),
        Sim::Info<Sim::Number>("MCB TCMS 2", 0.5, 1),
        Sim::Info<Sim::Number>("PT MCB TCMS 2 Trip", 0.5, 1),
        Sim::Info<Sim::Number>("MCB PIS Audio 2", 0.5, 1),
        Sim::Info<Sim::Number>("PT MCB PIS Audio 2 Trip", 0.5, 1),
        Sim::Info<Sim::Number>("MCB Exterior Lights 2", 0.5, 1),
        Sim::Info<Sim::Number>("PT MCB Exterior Lights 2 Trip", 0.5, 1),
        Sim::Info<Sim::Number>("MCB Brake Continuity", 0.5, 1),
        Sim::Info<Sim::Number>("PT MCB Brake Continuity Trip", 0.5, 1),
        Sim::Info<Sim::Number>("MCB Door Interlock", 0.5, 1),
        Sim::Info<Sim::Number>("PT MCB Door Interlock Trip", 0.5, 1),
        Sim::Info<Sim::Number>("MCB Radio", 0.5, 1),
        Sim::Info<Sim::Number>("PT MCB Radio Trip", 0.5, 1),
        Sim::Info<Sim::Number>("MCB PEA Interlock", 0.5, 1),
        Sim::Info<Sim::Number>("PT MCB PEA Interlock Trip", 0.5, 1),
        Sim::Info<Sim::Number>("MCB Train Control 2", 0.5, 1),
        Sim::Info<Sim::Number>("PT MCB Train Control 2 Trip", 0.5, 1),
        Sim::Info<Sim::Number>("MCB Cab HVAC Control", 0.5, 1),
        Sim::Info<Sim::Number>("PT MCB Cab HVAC Control Trip", 0.5, 1),
        Sim::Info<Sim::Number>("MCB Emergency Brake Recovery", 0.5, 1),
        Sim::Info<Sim::Number>("PT MCB Emergency Brake Recovery Trip", 0.5, 1),
        Sim::Info<Sim::Number>("MCB Remote Brake Release", 0.5, 1),
        Sim::Info<Sim::Number>("PT MCB Remote Brake Release Trip", 0.5, 1),
        Sim::Info<Sim::Number>("MCB AWS TPWS", 0.5, 1),
        Sim::Info<Sim::Number>("PT MCB AWS TPWS Trip", 0.5, 1),
        Sim::Info<Sim::Number>("MCB ETCS ATP", 0.5, 1),
        Sim::Info<Sim::Number>("PT MCB ETCS ATP Trip", 0.5, 1),
        Sim::Info<Sim::Number>("MCB OTMR", 0.5, 1),
        Sim::Info<Sim::Number>("PT MCB OTMR Trip", 0.5, 1),
        Sim::Info<Sim::Number>("Auxiliaries On", 0.5, 1),
        Sim::Info<Sim::Number>("Auxiliaries Off", 0.5, 1),
        Sim::Info<Sim::Number>("PEA CFA Reset", 0.5, 1),
        Sim::Info<Sim::Number>("Crew RHS Control Keyswitch", 0.5, 1),
        Sim::Info<Sim::Number>("Crew RHS Signal Buzzer Control", 0.5, 1),
        Sim::Info<Sim::Number>("Crew Right Door Close Control", 0.5, 1),
        Sim::Info<Sim::Number>("CCTV Monitor Switchover", 0.5, 1),
        Sim::Info<Sim::Number>("Rescue Control", 0.5, 1),
        Sim::Info<Sim::Number>("Rescue Selector Valve", 0.5, 1),
        Sim::Info<Sim::Number>("Cpl Emergency Jumper Cable", 0.5, 1),
        Sim::Info<Sim::Number>("Cpl Rescue Hose Staubli To Schrader", 0.5, 1),
        Sim::Info<Sim::Number>("Cpl Rescue Hose Staubli To Glad Hands", 0.5, 1),
        Sim::Info<Sim::Number>("Cpl Rescue Hose", 0.5, 1),
        Sim::Info<Sim::Number>("Cpl Scharfenburg Type 10", 0.5, 1),
        Sim::Info<Sim::Number>("Cpl Dellner Type 12", 0.5, 1),
        Sim::Info<Sim::Number>("Cpl Hook Adapter", 0.5, 1),
        Sim::Info<Sim::Number>("Cpl Scharfenburg Type 10 Adapter", 0.5, 1),
        Sim::Info<Sim::Number>("Cpl Latch Adapter", 0.5, 1),
        Sim::Info<Sim::Number>("Cpl Tightlock Adapter", 0.5, 1),
        Sim::Info<Sim::Number>("Cpl Clevis", 0.5, 1),
        Sim::Info<Sim::Number>("Cpl Transition Joint", 0.5, 1),
        Sim::Info<Sim::Number>("Coupler Isolation Cock", 0.5, 1),
        Sim::Info<Sim::Number>("Rescue Hose Isolating Cock", 0.5, 1),
        Sim::Info<Sim::Number>("Manual Uncoupling Handle", 0.5, 1),
        Sim::Info<Sim::Number>("Rescue Jumper Socket DS", 0.5, 1),
        Sim::Info<Sim::Number>("Rescue Jumper Socket NDS", 0.5, 1),
        Sim::Info<Sim::Number>("Rescue Jumper Socket DS Autotrain", 0.5, 1),
        Sim::Info<Sim::Number>("Rescue Jumper Socket NDS Autotrain", 0.5, 1),
        Sim::Info<Sim::Number>("Door A Open Pushbutton Internal LHS", 0.5, 1),
        Sim::Info<Sim::Number>("Door A Open Pushbutton Internal RHS", 0.5, 1),
        Sim::Info<Sim::Number>("Door A Open Pushbutton External", 0.5, 1),
        Sim::Info<Sim::Number>("Door A Out Of Service Lock", 0.5, 1),
        Sim::Info<Sim::Number>("Door A Emergency Egress Device", 0.5, 1),
        Sim::Info<Sim::Number>("Door A Open And Close Widget", 0.5, 1),
        Sim::Info<Sim::Number>("Door A Emergency Access Device", 0.5, 1),
        Sim::Info<Sim::Number>("Door A Passenger Emergency Alarm", 0.5, 1),
        Sim::Info<Sim::Number>("Door B Open Pushbutton Internal LHS", 0.5, 1),
        Sim::Info<Sim::Number>("Door B Open Pushbutton Internal RHS", 0.5, 1),
        Sim::Info<Sim::Number>("Door B Open Pushbutton External", 0.5, 1),
        Sim::Info<Sim::Number>("Door B Out Of Service Lock", 0.5, 1),
        Sim::Info<Sim::Number>("Door B Emergency Egress Device", 0.5, 1),
        Sim::Info<Sim::Number>("Door B Open And Close Widget", 0.5, 1),
        Sim::Info<Sim::Number>("Door B Emergency Access Device", 0.5, 1),
        Sim::Info<Sim::Number>("Door C Open Pushbutton Internal LHS", 0.5, 1),
        Sim::Info<Sim::Number>("Door C Open Pushbutton Internal RHS", 0.5, 1),
        Sim::Info<Sim::Number>("Door C Open Pushbutton External", 0.5, 1),
        Sim::Info<Sim::Number>("Door C Out Of Service Lock", 0.5, 1),
        Sim::Info<Sim::Number>("Door C Emergency Egress Device", 0.5, 1),
        Sim::Info<Sim::Number>("Door C Open And Close Widget", 0.5, 1),
        Sim::Info<Sim::Number>("Door C Emergency Access Device", 0.5, 1),
        Sim::Info<Sim::Number>("Door C Passenger Emergency Alarm", 0.5, 1),
        Sim::Info<Sim::Number>("Door D Open Pushbutton Internal LHS", 0.5, 1),
        Sim::Info<Sim::Number>("Door D Open Pushbutton Internal RHS", 0.5, 1),
        Sim::Info<Sim::Number>("Door D Open Pushbutton External", 0.5, 1),
        Sim::Info<Sim::Number>("Door D Out Of Service Lock", 0.5, 1),
        Sim::Info<Sim::Number>("Door D Emergency Egress Device", 0.5, 1),
        Sim::Info<Sim::Number>("Door D Open And Close Widget", 0.5, 1),
        Sim::Info<Sim::Number>("Door D Emergency Access Device", 0.5, 1),
        Sim::Info<Sim::Number>("Door E Open Pushbutton Internal LHS", 0.5, 1),
        Sim::Info<Sim::Number>("Door E Open Pushbutton Internal RHS", 0.5, 1),
        Sim::Info<Sim::Number>("Door E Open Pushbutton External", 0.5, 1),
        Sim::Info<Sim::Number>("Door E Out Of Service Lock", 0.5, 1),
        Sim::Info<Sim::Number>("Door E Emergency Egress Device", 0.5, 1),
        Sim::Info<Sim::Number>("Door E Open And Close Widget", 0.5, 1),
        Sim::Info<Sim::Number>("Door E Emergency Access Device", 0.5, 1),
        Sim::Info<Sim::Number>("Door E Passenger Emergency Alarm", 0.5, 1),
        Sim::Info<Sim::Number>("Door F Open Pushbutton Internal LHS", 0.5, 1),
        Sim::Info<Sim::Number>("Door F Open Pushbutton Internal RHS", 0.5, 1),
        Sim::Info<Sim::Number>("Door F Open Pushbutton External", 0.5, 1),
        Sim::Info<Sim::Number>("Door F Out Of Service Lock", 0.5, 1),
        Sim::Info<Sim::Number>("Door F Emergency Egress Device", 0.5, 1),
        Sim::Info<Sim::Number>("Door F Open And Close Widget", 0.5, 1),
        Sim::Info<Sim::Number>("Door F Emergency Access Device", 0.5, 1),
        Sim::Info<Sim::Number>("Parking Brake Manual Release 1", 0.5, 1),
        Sim::Info<Sim::Number>("Parking Brake Manual Release 2", 0.5, 1),
        Sim::Info<Sim::Number>("ADD Isolated Valve", 0.5, 1),
        Sim::Info<Sim::Number>("Call For Aid 1", 0.5, 1),
        Sim::Info<Sim::Number>("Call For Aid 2", 0.5, 1),
        Sim::Info<Sim::Number>("Call For Aid 3", 0.5, 1),
        Sim::Info<Sim::Number>("Call For Aid 4", 0.5, 1),
        Sim::Info<Sim::Number>("PSD Enable Local Control", 0.5, 1),
        Sim::Info<Sim::Number>("PSD Operate Door", 0.5, 1),
        Sim::Info<Sim::Number>("SPT Push To Talk", 0.5, 1),
        Sim::Info<Sim::Number>("SPT Return Switch", 0.5, 1),
        Sim::Info<Sim::Number>("Train Ready To Start Button", 0.5, 1),
        Sim::Info<Sim::Number>("Target Velocity", 0.5, -1),
        Sim::Info<Sim::Number>("Power CB", 0.5, 0),
        Sim::Info<Sim::Number>("Open Door L", 0.5, 0),
        Sim::Info<Sim::Number>("Open Door R", 0.5, 0),
        Sim::Info<Sim::Number>("Close Door R", 0.5, 0),
        Sim::Info<Sim::Number>("Close Door L", 0.5, 0),
        Sim::Info<Sim::Number>("Drive Next Station", 0.5, 0),
        Sim::Info<Sim::Number>("Auto Drive", 0.5, 0),
        Sim::Info<Sim::Number>("Horn Control", 0.5, 0),
        Sim::Info<Sim::Number>("Windscreen Wiper Control", 0.5, 0),
    };
    const size_t VEHICLE_INPUTS_MODES_NUMBERS_SIZE = sizeof(VEHICLE_INPUTS_MODES_NUMBERS)/sizeof(VEHICLE_INPUTS_MODES_NUMBERS[0]);
    const TagInfo *VEHICLE_INPUTS_MODES_TAGS = 0;
    const size_t VEHICLE_INPUTS_MODES_TAGS_SIZE = 0;
    const IdentifierInfo *VEHICLE_INPUTS_MODES_IDENTIFIERS = 0;
    const size_t VEHICLE_INPUTS_MODES_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *VEHICLE_INPUTS_MODES_CONSTANTS = 0;
    const size_t VEHICLE_INPUTS_MODES_CONSTANTS_SIZE = 0;
    const SpecificationInfo *VEHICLE_INPUTS_MODES_SPECIFICATIONS = 0;
    const size_t VEHICLE_INPUTS_MODES_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *VEHICLE_INPUTS_MODES_RAWS = 0;
    const size_t VEHICLE_INPUTS_MODES_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *VEHICLE_INPUTS_MODES_TRAYS = 0;
    const size_t VEHICLE_INPUTS_MODES_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> VEHICLE_OUTPUTS_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 102),
        Sim::Info<Sim::Number>("Class Outputs", 0.5, 0),
        Sim::Info<Sim::Number>("GSMR Cab 0 PB", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab 0 PB Light", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab 1 PB", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab 1 PB Light", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab 2 PB", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab 2 PB Light", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab 3 PB", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab 3 PB Light", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab 4 PB", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab 4 PB Light", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab 5 PB", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab 5 PB Light", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab 6 PB", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab 6 PB Light", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab 7 PB", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab 7 PB Light", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab 8 PB", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab 8 PB Light", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab 9 PB", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab 9 PB Light", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab Accept PB", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab Accept PB Light", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab Call Signaller PB", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab Call Signaller PB Light", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab Cancel PB", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab Cancel PB Light", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab Decrease Brightness PB", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab Decrease Brightness PB Light", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab Down PB", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab Down PB Light", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab Emergency PB", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab Emergency PB Light", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab Increase Brightness PB", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab Increase Brightness PB Light", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 01 01", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 01 02", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 01 03", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 01 04", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 01 05", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 01 06", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 01 07", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 01 08", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 01 09", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 01 10", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 01 11", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 01 12", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 01 13", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 01 14", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 01 15", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 01 16", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 01 17", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 01 18", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 01 19", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 01 20", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 02 01", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 02 02", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 02 03", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 02 04", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 02 05", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 02 06", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 02 07", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 02 08", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 02 09", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 02 10", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 02 11", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 02 12", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 02 13", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 02 14", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 02 15", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 02 16", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 02 17", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 02 18", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 02 19", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 02 20", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 03 01", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 03 02", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 03 03", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 03 04", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 03 05", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 03 06", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 03 07", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 03 08", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 03 09", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 03 10", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 03 11", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 03 12", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 03 13", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 03 14", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 03 15", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 03 16", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 03 17", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 03 18", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 03 19", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 03 20", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 04 01", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 04 02", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 04 03", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 04 04", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 04 05", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 04 06", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 04 07", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 04 08", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 04 09", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 04 10", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 04 11", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 04 12", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 04 13", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 04 14", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 04 15", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 04 16", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 04 17", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 04 18", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 04 19", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab LCD 04 20", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab Menu PB", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab Menu PB Light", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab Phonebook PB", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab Phonebook PB Light", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab Reg Dereg PB", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab Reg Dereg PB Light", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab Standing At Signal PB", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab Standing At Signal PB Light", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab Stop Acknowledge PB", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab Stop Acknowledge PB Light", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab Test PB", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab Test PB Light", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab Up PB", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab Up PB Light", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab Urgent PB", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab Urgent PB Light", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Line Air Pressure Gauge", 0.5, 0),
        Sim::Info<Sim::Number>("Pan Up Light", 0.5, 0),
        Sim::Info<Sim::Number>("LHS Doors Release Light 1", 0.5, 0),
        Sim::Info<Sim::Number>("LHS Doors Release Light 2", 0.5, 0),
        Sim::Info<Sim::Number>("Left Door Close Interlock Light", 0.5, 0),
        Sim::Info<Sim::Number>("Brake Applied", 0.5, 0),
        Sim::Info<Sim::Number>("Silence Alarm Light", 0.5, 0),
        Sim::Info<Sim::Number>("ATO Start Light", 0.5, 0),
        Sim::Info<Sim::Number>("Traction Sand Light", 0.5, 0),
        Sim::Info<Sim::Number>("DRA Light", 0.5, 0),
        Sim::Info<Sim::Number>("Hazard Warning Light", 0.5, 0),
        Sim::Info<Sim::Number>("Right Door Close Interlock Light", 0.5, 0),
        Sim::Info<Sim::Number>("RHS Doors Release Light 1", 0.5, 0),
        Sim::Info<Sim::Number>("RHS Doors Release Light 2", 0.5, 0),
        Sim::Info<Sim::Number>("Wiper Blade", 0.1, 0),
        Sim::Info<Sim::Number>("PA Light", 0.5, 0),
        Sim::Info<Sim::Number>("Cab To Cab Light", 0.5, 0),
        Sim::Info<Sim::Number>("PEA CFA Light", 0.5, 0),
        Sim::Info<Sim::Number>("GSMR Selection Light", 0.5, 0),
        Sim::Info<Sim::Number>("MCB Cab Lighting 1 Trip", 0.5, 1),
        Sim::Info<Sim::Number>("MCB TCMS 1 Trip", 0.5, 1),
        Sim::Info<Sim::Number>("MCB PIS Audio 1 Trip", 0.5, 1),
        Sim::Info<Sim::Number>("MCB Exterior Lights 1 Trip", 0.5, 1),
        Sim::Info<Sim::Number>("MCB Emergency Brake Trip", 0.5, 1),
        Sim::Info<Sim::Number>("MCB Door Control Trip", 0.5, 1),
        Sim::Info<Sim::Number>("MCB Cab Ventilation Trip", 0.5, 1),
        Sim::Info<Sim::Number>("MCB Wash Wipe Trip", 0.5, 1),
        Sim::Info<Sim::Number>("MCB Train Control 1 Trip", 0.5, 1),
        Sim::Info<Sim::Number>("SPARE Trip", 0.5, 1),
        Sim::Info<Sim::Number>("MCB Demister Trip", 0.5, 1),
        Sim::Info<Sim::Number>("MCB Cab Auxiliaries Trip", 0.5, 1),
        Sim::Info<Sim::Number>("MCB Earth Leakage Trip", 0.5, 1),
        Sim::Info<Sim::Number>("MCB Battery Permanent Trip", 0.5, 1),
        Sim::Info<Sim::Number>("MCB Cab Lighting 2 Trip", 0.5, 1),
        Sim::Info<Sim::Number>("MCB TCMS 2 Trip", 0.5, 1),
        Sim::Info<Sim::Number>("MCB PIS Audio 2 Trip", 0.5, 1),
        Sim::Info<Sim::Number>("MCB Exterior Lights 2 Trip", 0.5, 1),
        Sim::Info<Sim::Number>("MCB Brake Continuity Trip", 0.5, 1),
        Sim::Info<Sim::Number>("MCB Door Interlock Trip", 0.5, 1),
        Sim::Info<Sim::Number>("MCB Radio Trip", 0.5, 1),
        Sim::Info<Sim::Number>("MCB PEA Interlock Trip", 0.5, 1),
        Sim::Info<Sim::Number>("MCB Train Control 2 Trip", 0.5, 1),
        Sim::Info<Sim::Number>("MCB Cab HVAC Control Trip", 0.5, 1),
        Sim::Info<Sim::Number>("MCB Emergency Brake Recovery Trip", 0.5, 1),
        Sim::Info<Sim::Number>("MCB Remote Brake Release Trip", 0.5, 1),
        Sim::Info<Sim::Number>("MCB AWS TPWS Trip", 0.5, 1),
        Sim::Info<Sim::Number>("MCB ETCS ATP Trip", 0.5, 1),
        Sim::Info<Sim::Number>("MCB OTMR Trip", 0.5, 1),
        Sim::Info<Sim::Number>("Autocoupler Electrical Head", 0.5, 0),
        Sim::Info<Sim::Number>("Autocoupler Mechanical Head", 0.5, 0),
        Sim::Info<Sim::Number>("Cpl Correct Mechanical Adapters Selected 1 End", 0.5, 0),
        Sim::Info<Sim::Number>("Cpl Correct Pneumatic Adapters Selected 1 End", 0.5, 0),
        Sim::Info<Sim::Number>("Cpl Correct Pneumatic Pressure Select 1 End", 0.5, 0),
        Sim::Info<Sim::Number>("Cpl External Coupling Available 1 End", 0.5, 0),
        Sim::Info<Sim::Number>("Cpl Emergency Jumper Cable Connection", 0.5, 0),
        Sim::Info<Sim::Number>("Door A LHS", 0.001, 0),
        Sim::Info<Sim::Number>("Door A RHS", 0.001, 0),
        Sim::Info<Sim::Number>("Door A Open Light Internal LHS", 0.5, 0),
        Sim::Info<Sim::Number>("Door A Open Light Internal RHS", 0.5, 0),
        Sim::Info<Sim::Number>("Door A Open Light External", 0.5, 0),
        Sim::Info<Sim::Number>("Door A Status Indicator LHS", 0.5, 0),
        Sim::Info<Sim::Number>("Door A Status Indicator RHS", 0.5, 0),
        Sim::Info<Sim::Number>("Door A Out Of Service Internal", 0.5, 0),
        Sim::Info<Sim::Number>("Door A Out Of Service External", 0.5, 0),
        Sim::Info<Sim::Number>("Door A Passenger Emergency Display", 0.5, 0),
        Sim::Info<Sim::Number>("Door B LHS", 0.001, 0),
        Sim::Info<Sim::Number>("Door B RHS", 0.001, 0),
        Sim::Info<Sim::Number>("Door B Open Light Internal LHS", 0.5, 0),
        Sim::Info<Sim::Number>("Door B Open Light Internal RHS", 0.5, 0),
        Sim::Info<Sim::Number>("Door B Open Light External", 0.5, 0),
        Sim::Info<Sim::Number>("Door B Status Indicator LHS", 0.5, 0),
        Sim::Info<Sim::Number>("Door B Status Indicator RHS", 0.5, 0),
        Sim::Info<Sim::Number>("Door B Out Of Service Internal", 0.5, 0),
        Sim::Info<Sim::Number>("Door B Out Of Service External", 0.5, 0),
        Sim::Info<Sim::Number>("Door C LHS", 0.001, 0),
        Sim::Info<Sim::Number>("Door C RHS", 0.001, 0),
        Sim::Info<Sim::Number>("Door C Open Light Internal LHS", 0.5, 0),
        Sim::Info<Sim::Number>("Door C Open Light Internal RHS", 0.5, 0),
        Sim::Info<Sim::Number>("Door C Open Light External", 0.5, 0),
        Sim::Info<Sim::Number>("Door C Status Indicator LHS", 0.5, 0),
        Sim::Info<Sim::Number>("Door C Status Indicator RHS", 0.5, 0),
        Sim::Info<Sim::Number>("Door C Out Of Service Internal", 0.5, 0),
        Sim::Info<Sim::Number>("Door C Out Of Service External", 0.5, 0),
        Sim::Info<Sim::Number>("Door C Passenger Emergency Display", 0.5, 0),
        Sim::Info<Sim::Number>("Door D LHS", 0.001, 0),
        Sim::Info<Sim::Number>("Door D RHS", 0.001, 0),
        Sim::Info<Sim::Number>("Door D Open Light Internal LHS", 0.5, 0),
        Sim::Info<Sim::Number>("Door D Open Light Internal RHS", 0.5, 0),
        Sim::Info<Sim::Number>("Door D Open Light External", 0.5, 0),
        Sim::Info<Sim::Number>("Door D Status Indicator LHS", 0.5, 0),
        Sim::Info<Sim::Number>("Door D Status Indicator RHS", 0.5, 0),
        Sim::Info<Sim::Number>("Door D Out Of Service Internal", 0.5, 0),
        Sim::Info<Sim::Number>("Door D Out Of Service External", 0.5, 0),
        Sim::Info<Sim::Number>("Door E LHS", 0.001, 0),
        Sim::Info<Sim::Number>("Door E RHS", 0.001, 0),
        Sim::Info<Sim::Number>("Door E Open Light Internal LHS", 0.5, 0),
        Sim::Info<Sim::Number>("Door E Open Light Internal RHS", 0.5, 0),
        Sim::Info<Sim::Number>("Door E Open Light External", 0.5, 0),
        Sim::Info<Sim::Number>("Door E Status Indicator LHS", 0.5, 0),
        Sim::Info<Sim::Number>("Door E Status Indicator RHS", 0.5, 0),
        Sim::Info<Sim::Number>("Door E Out Of Service Internal", 0.5, 0),
        Sim::Info<Sim::Number>("Door E Out Of Service External", 0.5, 0),
        Sim::Info<Sim::Number>("Door E Passenger Emergency Display", 0.5, 0),
        Sim::Info<Sim::Number>("Door F LHS", 0.001, 0),
        Sim::Info<Sim::Number>("Door F RHS", 0.001, 0),
        Sim::Info<Sim::Number>("Door F Open Light Internal LHS", 0.5, 0),
        Sim::Info<Sim::Number>("Door F Open Light Internal RHS", 0.5, 0),
        Sim::Info<Sim::Number>("Door F Open Light External", 0.5, 0),
        Sim::Info<Sim::Number>("Door F Status Indicator LHS", 0.5, 0),
        Sim::Info<Sim::Number>("Door F Status Indicator RHS", 0.5, 0),
        Sim::Info<Sim::Number>("Door F Out Of Service Internal", 0.5, 0),
        Sim::Info<Sim::Number>("Door F Out Of Service External", 0.5, 0),
        Sim::Info<Sim::Number>("Bodiside Indicator LHS", 0.5, 0),
        Sim::Info<Sim::Number>("Bodiside Indicator RHS", 0.5, 0),
        Sim::Info<Sim::Number>("Cab Lighting Unit LHS", 0.5, 0),
        Sim::Info<Sim::Number>("Cab Lighting Unit RHS", 0.5, 0),
        Sim::Info<Sim::Number>("Cab Lighting Unit Gangway", 0.5, 0),
        Sim::Info<Sim::Number>("Head Light Full LHS", 0.5, 0),
        Sim::Info<Sim::Number>("Head Light Dimmed LHS", 0.5, 0),
        Sim::Info<Sim::Number>("Marker Light LHS", 0.5, 0),
        Sim::Info<Sim::Number>("Tail Light LHS", 0.5, 0),
        Sim::Info<Sim::Number>("Marker Light Central", 0.5, 0),
        Sim::Info<Sim::Number>("Head Light Full RHS", 0.5, 0),
        Sim::Info<Sim::Number>("Head Light Dimmed RHS", 0.5, 0),
        Sim::Info<Sim::Number>("Marker Light RHS", 0.5, 0),
        Sim::Info<Sim::Number>("Tail Light RHS", 0.5, 0),
        Sim::Info<Sim::Number>("Pantograph", 0.001, 0),
        Sim::Info<Sim::Number>("Call For Aid 1 Display", 0.5, 0),
        Sim::Info<Sim::Number>("Call For Aid 2 Display", 0.5, 0),
        Sim::Info<Sim::Number>("Call For Aid 3 Display", 0.5, 0),
        Sim::Info<Sim::Number>("Call For Aid 4 Display", 0.5, 0),
        Sim::Info<Sim::Number>("TCMS Monitor Power Failure", 0.5, 0),
        Sim::Info<Sim::Number>("DMI Monitor Power Failure", 0.5, 0),
        Sim::Info<Sim::Number>("DOO Monitor Power Failure", 0.5, 0),
        Sim::Info<Sim::Number>("PSD Panel Enabled Light", 0.5, 0),
        Sim::Info<Sim::Number>("PSD Doors Closed Locked Light", 0.5, 0),
        Sim::Info<Sim::Number>("PSD Fault Light", 0.5, 0),
        Sim::Info<Sim::Number>("Speed", 0.0010, 0),
        Sim::Info<Sim::Number>("Oscillator", 0.0010, 0),
        Sim::Info<Sim::Number>("Platform Passed", 0.5, 0),
        Sim::Info<Sim::Number>("Speed kph", 0.0010, 0),
        Sim::Info<Sim::Number>("Power Light", 0.5, 0),
        Sim::Info<Sim::Number>("Door State L", 0.01, 0),
        Sim::Info<Sim::Number>("Door State R", 0.01, 0),
        Sim::Info<Sim::Number>("Target Door State L", 0.5, 0),
        Sim::Info<Sim::Number>("Target Door State R", 0.5, 0),
        Sim::Info<Sim::Number>("Auto Drive Status", 0.5, 0),
        Sim::Info<Sim::Number>("Windscreen Wiper", 0.001, 0),
    };
    const size_t VEHICLE_OUTPUTS_NUMBERS_SIZE = sizeof(VEHICLE_OUTPUTS_NUMBERS)/sizeof(VEHICLE_OUTPUTS_NUMBERS[0]);
    const TagInfo *VEHICLE_OUTPUTS_TAGS = 0;
    const size_t VEHICLE_OUTPUTS_TAGS_SIZE = 0;
    const IdentifierInfo *VEHICLE_OUTPUTS_IDENTIFIERS = 0;
    const size_t VEHICLE_OUTPUTS_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *VEHICLE_OUTPUTS_CONSTANTS = 0;
    const size_t VEHICLE_OUTPUTS_CONSTANTS_SIZE = 0;
    const SpecificationInfo *VEHICLE_OUTPUTS_SPECIFICATIONS = 0;
    const size_t VEHICLE_OUTPUTS_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *VEHICLE_OUTPUTS_RAWS = 0;
    const size_t VEHICLE_OUTPUTS_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *VEHICLE_OUTPUTS_TRAYS = 0;
    const size_t VEHICLE_OUTPUTS_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> SESSION_CONTROL_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 115),
        Sim::Info<Sim::Number>("Session State Request", 0.5, 0),
    };
    const size_t SESSION_CONTROL_NUMBERS_SIZE = sizeof(SESSION_CONTROL_NUMBERS)/sizeof(SESSION_CONTROL_NUMBERS[0]);
    const TagInfo *SESSION_CONTROL_TAGS = 0;
    const size_t SESSION_CONTROL_TAGS_SIZE = 0;
    const IdentifierInfo *SESSION_CONTROL_IDENTIFIERS = 0;
    const size_t SESSION_CONTROL_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *SESSION_CONTROL_CONSTANTS = 0;
    const size_t SESSION_CONTROL_CONSTANTS_SIZE = 0;
    const SpecificationInfo *SESSION_CONTROL_SPECIFICATIONS = 0;
    const size_t SESSION_CONTROL_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *SESSION_CONTROL_RAWS = 0;
    const size_t SESSION_CONTROL_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *SESSION_CONTROL_TRAYS = 0;
    const size_t SESSION_CONTROL_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> AUDIO_ENGINE_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 20),
        Sim::Info<Sim::Number>("Audio Engine ID", 0.5, 0.0),
        Sim::Info<Sim::Number>("Observer Heading", 0.01, 0.0),
        Sim::Info<Sim::Number>("Observer Pitch", 0.01, 0.0),
        Sim::Info<Sim::Number>("Observer Position X", 0.0010, 0.0),
        Sim::Info<Sim::Number>("Observer Position Y", 0.0010, 0.0),
        Sim::Info<Sim::Number>("Observer Position Z", 0.0010, 0.0),
        Sim::Info<Sim::Number>("Observer Roll", 0.01, 0.0),
        Sim::Info<Sim::Number>("Observer Velocity X", 1.0E-4, 0.0),
        Sim::Info<Sim::Number>("Observer Velocity Y", 1.0E-4, 0.0),
        Sim::Info<Sim::Number>("Observer Velocity Z", 1.0E-4, 0.0),
    };
    const size_t AUDIO_ENGINE_NUMBERS_SIZE = sizeof(AUDIO_ENGINE_NUMBERS)/sizeof(AUDIO_ENGINE_NUMBERS[0]);
    const TagInfo *AUDIO_ENGINE_TAGS = 0;
    const size_t AUDIO_ENGINE_TAGS_SIZE = 0;
    const IdentifierInfo *AUDIO_ENGINE_IDENTIFIERS = 0;
    const size_t AUDIO_ENGINE_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *AUDIO_ENGINE_CONSTANTS = 0;
    const size_t AUDIO_ENGINE_CONSTANTS_SIZE = 0;
    const SpecificationInfo *AUDIO_ENGINE_SPECIFICATIONS = 0;
    const size_t AUDIO_ENGINE_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *AUDIO_ENGINE_RAWS = 0;
    const size_t AUDIO_ENGINE_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *AUDIO_ENGINE_TRAYS = 0;
    const size_t AUDIO_ENGINE_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> AUDIO_OUTPUT_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 6),
        Sim::Info<Sim::Number>("Horn High", 0.5, 0),
        Sim::Info<Sim::Number>("Horn Low", 0.5, 0),
        Sim::Info<Sim::Number>("Brake Application", 0.5, 0),
        Sim::Info<Sim::Number>("Brake Release", 0.5, 0),
        Sim::Info<Sim::Number>("Traction DB Power", 0.5, 0),
        Sim::Info<Sim::Number>("Wheel Ang Vel", 0.1, 0),
        Sim::Info<Sim::Number>("Wheel Speed", 0.001, 0),
        Sim::Info<Sim::Number>("Traction Motor Pitch", 0.001, 0),
        Sim::Info<Sim::Number>("Traction Motor Volume", 0.001, 0),
        Sim::Info<Sim::Number>("AWS Caution Tone", 0.5, 0),
        Sim::Info<Sim::Number>("AWS Clear Tone", 0.5, 0),
        Sim::Info<Sim::Number>("TPWS Overspeed Alarm", 0.5, 0),
        Sim::Info<Sim::Number>("TPWS SPAD Alarm", 0.5, 0),
        Sim::Info<Sim::Number>("TPWS Self Test Complete", 0.5, 0),
        Sim::Info<Sim::Number>("TCMS Alarm", 0.5, 0),
        Sim::Info<Sim::Number>("Vigilance Alarm", 0.5, 0),
        Sim::Info<Sim::Number>("Passenger Emergency Alarm", 0.5, 0),
        Sim::Info<Sim::Number>("Signal Buzzer", 0.5, 0),
        Sim::Info<Sim::Number>("Depot Whistle", 0.5, 0),
        Sim::Info<Sim::Number>("Mechanical Couple", 0.5, 0),
        Sim::Info<Sim::Number>("Mechanical Uncouple", 0.5, 0),
        Sim::Info<Sim::Number>("Detonator Explode", 0.5, 0),
        Sim::Info<Sim::Number>("Flat Wheel", 0.5, 0),
        Sim::Info<Sim::Number>("Rough Track", 0.5, 0),
        Sim::Info<Sim::Number>("Wheel Slip", 0.5, 0),
        Sim::Info<Sim::Number>("Door Enabled Buzzer", 0.5, 0),
        Sim::Info<Sim::Number>("Door Close Buzzer", 0.5, 0),
        Sim::Info<Sim::Number>("CBTC Overspeed Alarm", 0.5, 0),
        Sim::Info<Sim::Number>("CBTC Warning Alarm", 0.5, 0),
        Sim::Info<Sim::Number>("CBTC PIM Alarm", 0.5, 0),
        Sim::Info<Sim::Number>("CBTC Level Acknowledge Alert", 0.5, 0),
        Sim::Info<Sim::Number>("CBTC Departure Request Alert", 0.5, 0),
        Sim::Info<Sim::Number>("Town Horn", 0.5, 0),
        Sim::Info<Sim::Number>("Country Horn", 0.5, 0),
    };
    const size_t AUDIO_OUTPUT_NUMBERS_SIZE = sizeof(AUDIO_OUTPUT_NUMBERS)/sizeof(AUDIO_OUTPUT_NUMBERS[0]);
    const TagInfo *AUDIO_OUTPUT_TAGS = 0;
    const size_t AUDIO_OUTPUT_TAGS_SIZE = 0;
    const IdentifierInfo *AUDIO_OUTPUT_IDENTIFIERS = 0;
    const size_t AUDIO_OUTPUT_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *AUDIO_OUTPUT_CONSTANTS = 0;
    const size_t AUDIO_OUTPUT_CONSTANTS_SIZE = 0;
    const SpecificationInfo *AUDIO_OUTPUT_SPECIFICATIONS = 0;
    const size_t AUDIO_OUTPUT_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *AUDIO_OUTPUT_RAWS = 0;
    const size_t AUDIO_OUTPUT_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *AUDIO_OUTPUT_TRAYS = 0;
    const size_t AUDIO_OUTPUT_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> AUTO_TRAIN_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 24),
        Sim::Info<Sim::Number>("Scenario Train ID", 0.5, 0.0),
        Sim::Info<Sim::Number>("Train ID", 0.5, 0.0),
        Sim::Info<Sim::Number>("Train Type", 0.5, 0.0),
        Sim::Info<Sim::Number>("Target Velocity", 0.0010, 0.0),
        Sim::Info<Sim::Number>("Auto Driver Enabled", 0.5, 1.0),
        Sim::Info<Sim::Number>("Auto Driver Observe Speed Limits", 0.5, 1.0),
        Sim::Info<Sim::Number>("Auto Driver Observe Other Vehicles", 0.5, 1.0),
        Sim::Info<Sim::Number>("Auto Driver Release Brakes", 0.5, 0.0),
        Sim::Info<Sim::Number>("Auto Driver Coupling", 0.5, 0.0),
        Sim::Info<Sim::Number>("Collision", 0.5, 0.0),
        Sim::Info<Sim::Number>("Derailment", 0.5, 0.0),
        Sim::Info<Sim::Number>("Frozen", 0.5, 0.0),
    };
    const size_t AUTO_TRAIN_NUMBERS_SIZE = sizeof(AUTO_TRAIN_NUMBERS)/sizeof(AUTO_TRAIN_NUMBERS[0]);
    const TagInfo AUTO_TRAIN_TAGS[] =
    {
        { "Auto Driver" },
        { "Train" },
        { "Collision Aggregator" },
        { "Derailment Aggregator" },
        { "Frozen Aggregator" },
    };
    const size_t AUTO_TRAIN_TAGS_SIZE = sizeof(AUTO_TRAIN_TAGS)/sizeof(AUTO_TRAIN_TAGS[0]);
    const IdentifierInfo *AUTO_TRAIN_IDENTIFIERS = 0;
    const size_t AUTO_TRAIN_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *AUTO_TRAIN_CONSTANTS = 0;
    const size_t AUTO_TRAIN_CONSTANTS_SIZE = 0;
    const SpecificationInfo *AUTO_TRAIN_SPECIFICATIONS = 0;
    const size_t AUTO_TRAIN_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *AUTO_TRAIN_RAWS = 0;
    const size_t AUTO_TRAIN_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *AUTO_TRAIN_TRAYS = 0;
    const size_t AUTO_TRAIN_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> AUTO_VEHICLE_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 25),
        Sim::Info<Sim::Number>("Length", 0.001, 20.0),
        Sim::Info<Sim::Number>("Width", 0.001, 2.0),
        Sim::Info<Sim::Number>("Height", 0.001, 5.0),
        Sim::Info<Sim::Number>("Mass", 1, 45000.0),
        Sim::Info<Sim::Number>("Orientation", 0.5, 1.0),
        Sim::Info<Sim::Number>("Index", 0.5, 0.0),
        Sim::Info<Sim::Number>("Position", 1.0E-5, 0.0),
        Sim::Info<Sim::Number>("Acceleration", 1.0E-5, 0.0),
        Sim::Info<Sim::Number>("Velocity", 1.0E-5, 0.0),
        Sim::Info<Sim::Number>("Gradient", 0.001, 0),
        Sim::Info<Sim::Number>("Radius", 0.5, 0),
        Sim::Info<Sim::Number>("Superelevation", 0.001, 0),
        Sim::Info<Sim::Number>("Throttle", 0.5, 0.0),
        Sim::Info<Sim::Number>("Brake", 0.5, 0.0),
        Sim::Info<Sim::Number>("Collision", 0.5, 0.0),
        Sim::Info<Sim::Number>("Collision Mass", 1.0, 0.0),
        Sim::Info<Sim::Number>("Collision Speed", 1.0E-5, 0.0),
        Sim::Info<Sim::Number>("Derailment", 0.5, 0.0),
        Sim::Info<Sim::Number>("Frozen", 0.5, 0.0),
        Sim::Info<Sim::Number>("Freeze", 0.5, 0.0),
        Sim::Info<Sim::Number>("Calling On Light", 0.5, 0.0),
        Sim::Info<Sim::Number>("Car Headlights", 0.5, 0.0),
        Sim::Info<Sim::Number>("Car Marker Lights", 0.5, 0.0),
        Sim::Info<Sim::Number>("Vehicle On Fire", 0.5, 0.0),
    };
    const size_t AUTO_VEHICLE_NUMBERS_SIZE = sizeof(AUTO_VEHICLE_NUMBERS)/sizeof(AUTO_VEHICLE_NUMBERS[0]);
    const TagInfo AUTO_VEHICLE_TAGS[] =
    {
        { "Vehicle" },
        { "Collision Summariser" },
        { "Core Model" },
    };
    const size_t AUTO_VEHICLE_TAGS_SIZE = sizeof(AUTO_VEHICLE_TAGS)/sizeof(AUTO_VEHICLE_TAGS[0]);
    const IdentifierInfo AUTO_VEHICLE_IDENTIFIERS[] =
    {
        { "Vehicle ID", 0 },
        { "Car ID", 0 },
    };
    const size_t AUTO_VEHICLE_IDENTIFIERS_SIZE = sizeof(AUTO_VEHICLE_IDENTIFIERS)/sizeof(AUTO_VEHICLE_IDENTIFIERS[0]);
    const ConstantInfo *AUTO_VEHICLE_CONSTANTS = 0;
    const size_t AUTO_VEHICLE_CONSTANTS_SIZE = 0;
    const SpecificationInfo *AUTO_VEHICLE_SPECIFICATIONS = 0;
    const size_t AUTO_VEHICLE_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *AUTO_VEHICLE_RAWS = 0;
    const size_t AUTO_VEHICLE_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *AUTO_VEHICLE_TRAYS = 0;
    const size_t AUTO_VEHICLE_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> ENVIRONMENT_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 19),
        Sim::Info<Sim::Number>("Fog Percentage", 0.5, 0.0),
        Sim::Info<Sim::Number>("Haze Percentage", 0.5, 0.0),
        Sim::Info<Sim::Number>("Rain Percentage", 0.5, 0.0),
        Sim::Info<Sim::Number>("Snow Percentage", 0.5, 0.0),
        Sim::Info<Sim::Number>("Sun Glare Percentage", 0.5, 0.0),
        Sim::Info<Sim::Number>("Tunnel Smoke Percentage", 0.5, 30.0),
        Sim::Info<Sim::Number>("Wind Direction Angle", 0.1, 0.0),
        Sim::Info<Sim::Number>("Wind Strength km/h", 0.1, 0.0),
        Sim::Info<Sim::Number>("Sun Brightness Percentage", 0.5, 100.0),
        Sim::Info<Sim::Number>("Cloud Density Percentage", 0.5, 0.0),
        Sim::Info<Sim::Number>("Lightning Percentage", 0.5, 0.0),
    };
    const size_t ENVIRONMENT_NUMBERS_SIZE = sizeof(ENVIRONMENT_NUMBERS)/sizeof(ENVIRONMENT_NUMBERS[0]);
    const TagInfo *ENVIRONMENT_TAGS = 0;
    const size_t ENVIRONMENT_TAGS_SIZE = 0;
    const IdentifierInfo *ENVIRONMENT_IDENTIFIERS = 0;
    const size_t ENVIRONMENT_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *ENVIRONMENT_CONSTANTS = 0;
    const size_t ENVIRONMENT_CONSTANTS_SIZE = 0;
    const SpecificationInfo *ENVIRONMENT_SPECIFICATIONS = 0;
    const size_t ENVIRONMENT_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *ENVIRONMENT_RAWS = 0;
    const size_t ENVIRONMENT_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *ENVIRONMENT_TRAYS = 0;
    const size_t ENVIRONMENT_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> FEATURE_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 12),
        Sim::Info<Sim::Number>("Feature ID", 0.5, 0.0),
        Sim::Info<Sim::Number>("Automatic State", 0.5, 0.0),
        Sim::Info<Sim::Number>("Initial State", 0.5, 0.0),
        Sim::Info<Sim::Number>("User State", 0.5, 0.0),
        Sim::Info<Sim::Number>("Bottom", 0.0010, 1.0),
        Sim::Info<Sim::Number>("Far Plane", 0.0010, 10000.0),
        Sim::Info<Sim::Number>("Horizontal Field of View", 0.01, 40.0),
        Sim::Info<Sim::Number>("Left", 0.0010, 0.0),
        Sim::Info<Sim::Number>("Near Plane", 0.0010, 100.0),
        Sim::Info<Sim::Number>("Right", 0.0010, 1.0),
        Sim::Info<Sim::Number>("State", 0.5, 0.0),
        Sim::Info<Sim::Number>("Top", 0.0010, 0.0),
        Sim::Info<Sim::Number>("Type", 0.5, 0.0),
        Sim::Info<Sim::Number>("Vertical Field of View", 0.01, 30.0),
        Sim::Info<Sim::Number>("Facing Segment ID", 0.5, 0.0),
        Sim::Info<Sim::Number>("Trailing Segment ID", 0.5, 0.0),
        Sim::Info<Sim::Number>("Branch Segment ID", 0.5, 0.0),
        Sim::Info<Sim::Number>("Colour Red", 0.001, 0.0),
        Sim::Info<Sim::Number>("Colour Green", 0.001, 0.0),
        Sim::Info<Sim::Number>("Colour Blue", 0.001, 0.0),
        Sim::Info<Sim::Number>("Radio Area Code", 0.5, 0.0),
        Sim::Info<Sim::Number>("Radio Area Code 2", 0.5, 0.0),
        Sim::Info<Sim::Number>("Radio System", 0.5, 0.0),
        Sim::Info<Sim::Number>("Radio System 2", 0.5, 0.0),
        Sim::Info<Sim::Number>("Length", 0.001, 0.0),
        Sim::Info<Sim::Number>("Bias", 0.001, 0.0),
        Sim::Info<Sim::Number>("Collider", 0.5, 0.0),
        Sim::Info<Sim::Number>("Derailer", 0.5, 0.0),
        Sim::Info<Sim::Number>("Mass", 1.0, 0.0),
    };
    const size_t FEATURE_NUMBERS_SIZE = sizeof(FEATURE_NUMBERS)/sizeof(FEATURE_NUMBERS[0]);
    const TagInfo *FEATURE_TAGS = 0;
    const size_t FEATURE_TAGS_SIZE = 0;
    const IdentifierInfo *FEATURE_IDENTIFIERS = 0;
    const size_t FEATURE_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *FEATURE_CONSTANTS = 0;
    const size_t FEATURE_CONSTANTS_SIZE = 0;
    const SpecificationInfo *FEATURE_SPECIFICATIONS = 0;
    const size_t FEATURE_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *FEATURE_RAWS = 0;
    const size_t FEATURE_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *FEATURE_TRAYS = 0;
    const size_t FEATURE_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> FEATURES_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 55),
    };
    const size_t FEATURES_NUMBERS_SIZE = sizeof(FEATURES_NUMBERS)/sizeof(FEATURES_NUMBERS[0]);
    const TagInfo *FEATURES_TAGS = 0;
    const size_t FEATURES_TAGS_SIZE = 0;
    const IdentifierInfo *FEATURES_IDENTIFIERS = 0;
    const size_t FEATURES_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *FEATURES_CONSTANTS = 0;
    const size_t FEATURES_CONSTANTS_SIZE = 0;
    const SpecificationInfo *FEATURES_SPECIFICATIONS = 0;
    const size_t FEATURES_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *FEATURES_RAWS = 0;
    const size_t FEATURES_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *FEATURES_TRAYS = 0;
    const size_t FEATURES_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> GMI_DATA_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 112),
        Sim::Info<Sim::Number>("GMI ID", 0.5, 0.0),
        Sim::Info<Sim::Number>("Car Index", 0.5, -1.0),
        Sim::Info<Sim::Number>("Screen ID", 0.5, -1.0),
    };
    const size_t GMI_DATA_NUMBERS_SIZE = sizeof(GMI_DATA_NUMBERS)/sizeof(GMI_DATA_NUMBERS[0]);
    const TagInfo *GMI_DATA_TAGS = 0;
    const size_t GMI_DATA_TAGS_SIZE = 0;
    const IdentifierInfo *GMI_DATA_IDENTIFIERS = 0;
    const size_t GMI_DATA_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *GMI_DATA_CONSTANTS = 0;
    const size_t GMI_DATA_CONSTANTS_SIZE = 0;
    const SpecificationInfo *GMI_DATA_SPECIFICATIONS = 0;
    const size_t GMI_DATA_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *GMI_DATA_RAWS = 0;
    const size_t GMI_DATA_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> GMI_DATA_TRAYS[] =
    {
        Sim::Info<Sim::Tray>("Screen Change Request"),
        Sim::Info<Sim::Tray>("Control Request"),
    };
    const size_t GMI_DATA_TRAYS_SIZE = sizeof(GMI_DATA_TRAYS)/sizeof(GMI_DATA_TRAYS[0]);
    const Sim::Info<Sim::Number> HUB_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 100),
        Sim::Info<Sim::Number>("Simulator ID", 0.5, 0.0),
        Sim::Info<Sim::Number>("Hub ID", 0.5, 0.0),
        Sim::Info<Sim::Number>("Location Type", 0.5, 0.0),
        Sim::Info<Sim::Number>("Scenario Train ID", 0.5, 0.0),
        Sim::Info<Sim::Number>("Vehicle Index", 0.5, 0.0),
        Sim::Info<Sim::Number>("x", 0.001, 0.0),
        Sim::Info<Sim::Number>("y", 0.001, 0.0),
        Sim::Info<Sim::Number>("z", 0.001, 0.0),
        Sim::Info<Sim::Number>("h", 0.001, 0.0),
        Sim::Info<Sim::Number>("p", 0.001, 0.0),
        Sim::Info<Sim::Number>("r", 0.001, 0.0),
        Sim::Info<Sim::Number>("Mode", 0.5, 0.0),
    };
    const size_t HUB_NUMBERS_SIZE = sizeof(HUB_NUMBERS)/sizeof(HUB_NUMBERS[0]);
    const TagInfo *HUB_TAGS = 0;
    const size_t HUB_TAGS_SIZE = 0;
    const IdentifierInfo *HUB_IDENTIFIERS = 0;
    const size_t HUB_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *HUB_CONSTANTS = 0;
    const size_t HUB_CONSTANTS_SIZE = 0;
    const SpecificationInfo *HUB_SPECIFICATIONS = 0;
    const size_t HUB_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *HUB_RAWS = 0;
    const size_t HUB_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *HUB_TRAYS = 0;
    const size_t HUB_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> GMI_POSITION_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 114),
        Sim::Info<Sim::Number>("Scenario Train ID", 0.5, 0.0),
        Sim::Info<Sim::Number>("Vehicle Index", 0.5, 0.0),
        Sim::Info<Sim::Number>("x", 0.001, 0.0),
        Sim::Info<Sim::Number>("y", 0.001, 0.0),
        Sim::Info<Sim::Number>("z", 0.001, 0.0),
        Sim::Info<Sim::Number>("h", 0.001, 0.0),
        Sim::Info<Sim::Number>("p", 0.001, 0.0),
        Sim::Info<Sim::Number>("r", 0.001, 0.0),
        Sim::Info<Sim::Number>("Inside Vehicle", 0.5, 0.0),
        Sim::Info<Sim::Number>("Screen", 0.5, 0.0),
        Sim::Info<Sim::Number>("Valid", 0.5, 0.0),
    };
    const size_t GMI_POSITION_NUMBERS_SIZE = sizeof(GMI_POSITION_NUMBERS)/sizeof(GMI_POSITION_NUMBERS[0]);
    const TagInfo *GMI_POSITION_TAGS = 0;
    const size_t GMI_POSITION_TAGS_SIZE = 0;
    const IdentifierInfo *GMI_POSITION_IDENTIFIERS = 0;
    const size_t GMI_POSITION_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *GMI_POSITION_CONSTANTS = 0;
    const size_t GMI_POSITION_CONSTANTS_SIZE = 0;
    const SpecificationInfo *GMI_POSITION_SPECIFICATIONS = 0;
    const size_t GMI_POSITION_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *GMI_POSITION_RAWS = 0;
    const size_t GMI_POSITION_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *GMI_POSITION_TRAYS = 0;
    const size_t GMI_POSITION_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> OBJECT_GEOMETRY_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 13),
        Sim::Info<Sim::Number>("Heading", 0.1, 0.0),
        Sim::Info<Sim::Number>("Pitch", 0.1, 0.0),
        Sim::Info<Sim::Number>("Position X", 1.0E-5, 0.0),
        Sim::Info<Sim::Number>("Position Y", 1.0E-5, 0.0),
        Sim::Info<Sim::Number>("Position Z", 1.0E-5, 0.0),
        Sim::Info<Sim::Number>("Roll", 0.1, 0.0),
        Sim::Info<Sim::Number>("Velocity X", 1.0E-5, 0.0),
        Sim::Info<Sim::Number>("Velocity Y", 1.0E-5, 0.0),
        Sim::Info<Sim::Number>("Velocity Z", 1.0E-5, 0.0),
    };
    const size_t OBJECT_GEOMETRY_NUMBERS_SIZE = sizeof(OBJECT_GEOMETRY_NUMBERS)/sizeof(OBJECT_GEOMETRY_NUMBERS[0]);
    const TagInfo *OBJECT_GEOMETRY_TAGS = 0;
    const size_t OBJECT_GEOMETRY_TAGS_SIZE = 0;
    const IdentifierInfo *OBJECT_GEOMETRY_IDENTIFIERS = 0;
    const size_t OBJECT_GEOMETRY_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *OBJECT_GEOMETRY_CONSTANTS = 0;
    const size_t OBJECT_GEOMETRY_CONSTANTS_SIZE = 0;
    const SpecificationInfo *OBJECT_GEOMETRY_SPECIFICATIONS = 0;
    const size_t OBJECT_GEOMETRY_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *OBJECT_GEOMETRY_RAWS = 0;
    const size_t OBJECT_GEOMETRY_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *OBJECT_GEOMETRY_TRAYS = 0;
    const size_t OBJECT_GEOMETRY_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> PERSPECTIVE_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 16),
        Sim::Info<Sim::Number>("Perspective ID", 0.5, -1.0),
        Sim::Info<Sim::Number>("Camera ID", 0.5, -1.0),
        Sim::Info<Sim::Number>("Far Plane", 0.0010, 10000.0),
        Sim::Info<Sim::Number>("Feature ID", 0.5, -1.0),
        Sim::Info<Sim::Number>("H", 0.0010, 0.0),
        Sim::Info<Sim::Number>("Horizontal Field of View", 0.0010, 60.0),
        Sim::Info<Sim::Number>("Near Plane", 0.0010, 100.0),
        Sim::Info<Sim::Number>("P", 0.0010, 0.0),
        Sim::Info<Sim::Number>("R", 0.0010, 0.0),
        Sim::Info<Sim::Number>("Scenario Train ID", 0.5, -1.0),
        Sim::Info<Sim::Number>("User ID", 0.5, -1.0),
        Sim::Info<Sim::Number>("Vehicle Index", 0.5, -1.0),
        Sim::Info<Sim::Number>("Vertical Field of View", 0.0010, 45.0),
        Sim::Info<Sim::Number>("X", 0.0010, 0.0),
        Sim::Info<Sim::Number>("Y", 0.0010, 0.0),
        Sim::Info<Sim::Number>("Z", 0.0010, 0.0),
        Sim::Info<Sim::Number>("Frustum X Offset", 0.0010, 0.0),
        Sim::Info<Sim::Number>("Frustum Y Offset", 0.0010, 0.0),
        Sim::Info<Sim::Number>("Focal Distance", 0.0010, 1.0),
        Sim::Info<Sim::Number>("Reflection Enabled", 0.5, 0.0),
        Sim::Info<Sim::Number>("Reflection X", 0.0010, 0.0),
        Sim::Info<Sim::Number>("Reflection Y", 0.0010, 0.0),
        Sim::Info<Sim::Number>("Reflection Z", 0.0010, 0.0),
        Sim::Info<Sim::Number>("Live3D Enabled", 0.5, 0.0),
        Sim::Info<Sim::Number>("Live3D Scale X", 0.0010, 1.0),
        Sim::Info<Sim::Number>("Live3D Scale Y", 0.0010, 1.0),
        Sim::Info<Sim::Number>("Live3D Scale Z", 0.0010, 1.0),
    };
    const size_t PERSPECTIVE_NUMBERS_SIZE = sizeof(PERSPECTIVE_NUMBERS)/sizeof(PERSPECTIVE_NUMBERS[0]);
    const TagInfo *PERSPECTIVE_TAGS = 0;
    const size_t PERSPECTIVE_TAGS_SIZE = 0;
    const IdentifierInfo *PERSPECTIVE_IDENTIFIERS = 0;
    const size_t PERSPECTIVE_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *PERSPECTIVE_CONSTANTS = 0;
    const size_t PERSPECTIVE_CONSTANTS_SIZE = 0;
    const SpecificationInfo *PERSPECTIVE_SPECIFICATIONS = 0;
    const size_t PERSPECTIVE_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *PERSPECTIVE_RAWS = 0;
    const size_t PERSPECTIVE_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *PERSPECTIVE_TRAYS = 0;
    const size_t PERSPECTIVE_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> PERSPECTIVES_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 26),
    };
    const size_t PERSPECTIVES_NUMBERS_SIZE = sizeof(PERSPECTIVES_NUMBERS)/sizeof(PERSPECTIVES_NUMBERS[0]);
    const TagInfo *PERSPECTIVES_TAGS = 0;
    const size_t PERSPECTIVES_TAGS_SIZE = 0;
    const IdentifierInfo *PERSPECTIVES_IDENTIFIERS = 0;
    const size_t PERSPECTIVES_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *PERSPECTIVES_CONSTANTS = 0;
    const size_t PERSPECTIVES_CONSTANTS_SIZE = 0;
    const SpecificationInfo *PERSPECTIVES_SPECIFICATIONS = 0;
    const size_t PERSPECTIVES_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *PERSPECTIVES_RAWS = 0;
    const size_t PERSPECTIVES_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *PERSPECTIVES_TRAYS = 0;
    const size_t PERSPECTIVES_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> PERSPECTIVE_PROPERTIES_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 119),
    };
    const size_t PERSPECTIVE_PROPERTIES_NUMBERS_SIZE = sizeof(PERSPECTIVE_PROPERTIES_NUMBERS)/sizeof(PERSPECTIVE_PROPERTIES_NUMBERS[0]);
    const TagInfo PERSPECTIVE_PROPERTIES_TAGS[] =
    {
        { "Perspective Properties" },
    };
    const size_t PERSPECTIVE_PROPERTIES_TAGS_SIZE = sizeof(PERSPECTIVE_PROPERTIES_TAGS)/sizeof(PERSPECTIVE_PROPERTIES_TAGS[0]);
    const IdentifierInfo *PERSPECTIVE_PROPERTIES_IDENTIFIERS = 0;
    const size_t PERSPECTIVE_PROPERTIES_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *PERSPECTIVE_PROPERTIES_CONSTANTS = 0;
    const size_t PERSPECTIVE_PROPERTIES_CONSTANTS_SIZE = 0;
    const SpecificationInfo *PERSPECTIVE_PROPERTIES_SPECIFICATIONS = 0;
    const size_t PERSPECTIVE_PROPERTIES_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *PERSPECTIVE_PROPERTIES_RAWS = 0;
    const size_t PERSPECTIVE_PROPERTIES_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *PERSPECTIVE_PROPERTIES_TRAYS = 0;
    const size_t PERSPECTIVE_PROPERTIES_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> PT_DATA_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 113),
        Sim::Info<Sim::Number>("PT ID", 0.5, 0.0),
        Sim::Info<Sim::Number>("View Hub ID", 0.5, 0.0),
        Sim::Info<Sim::Number>("View GMI ID", 0.5, 0.0),
        Sim::Info<Sim::Number>("Override", 0.5, 0.0),
    };
    const size_t PT_DATA_NUMBERS_SIZE = sizeof(PT_DATA_NUMBERS)/sizeof(PT_DATA_NUMBERS[0]);
    const TagInfo *PT_DATA_TAGS = 0;
    const size_t PT_DATA_TAGS_SIZE = 0;
    const IdentifierInfo *PT_DATA_IDENTIFIERS = 0;
    const size_t PT_DATA_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *PT_DATA_CONSTANTS = 0;
    const size_t PT_DATA_CONSTANTS_SIZE = 0;
    const SpecificationInfo *PT_DATA_SPECIFICATIONS = 0;
    const size_t PT_DATA_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *PT_DATA_RAWS = 0;
    const size_t PT_DATA_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *PT_DATA_TRAYS = 0;
    const size_t PT_DATA_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> RADIO_AREA_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 9),
        Sim::Info<Sim::Number>("Area Code ID", 0.5, 0.0),
        Sim::Info<Sim::Number>("Area Code Status", 0.5, 0.0),
        Sim::Info<Sim::Number>("Radio All Stop", 0.5, 0.0),
    };
    const size_t RADIO_AREA_NUMBERS_SIZE = sizeof(RADIO_AREA_NUMBERS)/sizeof(RADIO_AREA_NUMBERS[0]);
    const TagInfo *RADIO_AREA_TAGS = 0;
    const size_t RADIO_AREA_TAGS_SIZE = 0;
    const IdentifierInfo *RADIO_AREA_IDENTIFIERS = 0;
    const size_t RADIO_AREA_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *RADIO_AREA_CONSTANTS = 0;
    const size_t RADIO_AREA_CONSTANTS_SIZE = 0;
    const SpecificationInfo *RADIO_AREA_SPECIFICATIONS = 0;
    const size_t RADIO_AREA_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *RADIO_AREA_RAWS = 0;
    const size_t RADIO_AREA_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *RADIO_AREA_TRAYS = 0;
    const size_t RADIO_AREA_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> SCRIPTING_ENGINE_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 116),
    };
    const size_t SCRIPTING_ENGINE_NUMBERS_SIZE = sizeof(SCRIPTING_ENGINE_NUMBERS)/sizeof(SCRIPTING_ENGINE_NUMBERS[0]);
    const TagInfo *SCRIPTING_ENGINE_TAGS = 0;
    const size_t SCRIPTING_ENGINE_TAGS_SIZE = 0;
    const IdentifierInfo *SCRIPTING_ENGINE_IDENTIFIERS = 0;
    const size_t SCRIPTING_ENGINE_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *SCRIPTING_ENGINE_CONSTANTS = 0;
    const size_t SCRIPTING_ENGINE_CONSTANTS_SIZE = 0;
    const SpecificationInfo *SCRIPTING_ENGINE_SPECIFICATIONS = 0;
    const size_t SCRIPTING_ENGINE_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *SCRIPTING_ENGINE_RAWS = 0;
    const size_t SCRIPTING_ENGINE_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *SCRIPTING_ENGINE_TRAYS = 0;
    const size_t SCRIPTING_ENGINE_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> SCRIPTLET_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 117),
        Sim::Info<Sim::Number>("Active", 0.5, 1.0),
        Sim::Info<Sim::Number>("State", 0.5, 0.0),
    };
    const size_t SCRIPTLET_NUMBERS_SIZE = sizeof(SCRIPTLET_NUMBERS)/sizeof(SCRIPTLET_NUMBERS[0]);
    const TagInfo *SCRIPTLET_TAGS = 0;
    const size_t SCRIPTLET_TAGS_SIZE = 0;
    const IdentifierInfo *SCRIPTLET_IDENTIFIERS = 0;
    const size_t SCRIPTLET_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *SCRIPTLET_CONSTANTS = 0;
    const size_t SCRIPTLET_CONSTANTS_SIZE = 0;
    const SpecificationInfo *SCRIPTLET_SPECIFICATIONS = 0;
    const size_t SCRIPTLET_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> SCRIPTLET_RAWS[] =
    {
        Sim::Info<Sim::Raw>("Script"),
    };
    const size_t SCRIPTLET_RAWS_SIZE = sizeof(SCRIPTLET_RAWS)/sizeof(SCRIPTLET_RAWS[0]);
    const Sim::Info<Sim::Tray> *SCRIPTLET_TRAYS = 0;
    const size_t SCRIPTLET_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> SOUND_DATA_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 22),
        Sim::Info<Sim::Number>("Frequency", 0.001, 0.0),
        Sim::Info<Sim::Number>("Position X", 0.001, 0.0),
        Sim::Info<Sim::Number>("Position Y", 0.001, 0.0),
        Sim::Info<Sim::Number>("Position Z", 0.001, 0.0),
        Sim::Info<Sim::Number>("State", 0.5, 0.0),
        Sim::Info<Sim::Number>("Velocity X", 1.0E-4, 0.0),
        Sim::Info<Sim::Number>("Velocity Y", 1.0E-4, 0.0),
        Sim::Info<Sim::Number>("Velocity Z", 1.0E-4, 0.0),
        Sim::Info<Sim::Number>("Volume", 0.1, 0.0),
    };
    const size_t SOUND_DATA_NUMBERS_SIZE = sizeof(SOUND_DATA_NUMBERS)/sizeof(SOUND_DATA_NUMBERS[0]);
    const TagInfo *SOUND_DATA_TAGS = 0;
    const size_t SOUND_DATA_TAGS_SIZE = 0;
    const IdentifierInfo *SOUND_DATA_IDENTIFIERS = 0;
    const size_t SOUND_DATA_IDENTIFIERS_SIZE = 0;
    const ConstantInfo SOUND_DATA_CONSTANTS[] =
    {
        { "Observer Relative", 1 },
        { "Min Distance", 1 },
        { "Max Distance", 1000 },
    };
    const size_t SOUND_DATA_CONSTANTS_SIZE = sizeof(SOUND_DATA_CONSTANTS)/sizeof(SOUND_DATA_CONSTANTS[0]);
    const SpecificationInfo *SOUND_DATA_SPECIFICATIONS = 0;
    const size_t SOUND_DATA_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *SOUND_DATA_RAWS = 0;
    const size_t SOUND_DATA_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *SOUND_DATA_TRAYS = 0;
    const size_t SOUND_DATA_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> TRACK_ASSOCIATION_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 14),
        Sim::Info<Sim::Number>("Association ID", 0.5, 0.0),
        Sim::Info<Sim::Number>("Orientation", 0.5, 0.0),
        Sim::Info<Sim::Number>("Segment ID", 0.5, 0.0),
        Sim::Info<Sim::Number>("Segment Offset", 1.0E-5, 0.0),
    };
    const size_t TRACK_ASSOCIATION_NUMBERS_SIZE = sizeof(TRACK_ASSOCIATION_NUMBERS)/sizeof(TRACK_ASSOCIATION_NUMBERS[0]);
    const TagInfo *TRACK_ASSOCIATION_TAGS = 0;
    const size_t TRACK_ASSOCIATION_TAGS_SIZE = 0;
    const IdentifierInfo *TRACK_ASSOCIATION_IDENTIFIERS = 0;
    const size_t TRACK_ASSOCIATION_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *TRACK_ASSOCIATION_CONSTANTS = 0;
    const size_t TRACK_ASSOCIATION_CONSTANTS_SIZE = 0;
    const SpecificationInfo *TRACK_ASSOCIATION_SPECIFICATIONS = 0;
    const size_t TRACK_ASSOCIATION_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *TRACK_ASSOCIATION_RAWS = 0;
    const size_t TRACK_ASSOCIATION_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *TRACK_ASSOCIATION_TRAYS = 0;
    const size_t TRACK_ASSOCIATION_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> TRACK_POSITION_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 11),
        Sim::Info<Sim::Number>("From Alpha", 0.5, 0.0),
        Sim::Info<Sim::Number>("Segment ID", 0.5, 0.0),
        Sim::Info<Sim::Number>("Segment Offset", 1.0E-5, 0.0),
    };
    const size_t TRACK_POSITION_NUMBERS_SIZE = sizeof(TRACK_POSITION_NUMBERS)/sizeof(TRACK_POSITION_NUMBERS[0]);
    const TagInfo *TRACK_POSITION_TAGS = 0;
    const size_t TRACK_POSITION_TAGS_SIZE = 0;
    const IdentifierInfo *TRACK_POSITION_IDENTIFIERS = 0;
    const size_t TRACK_POSITION_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *TRACK_POSITION_CONSTANTS = 0;
    const size_t TRACK_POSITION_CONSTANTS_SIZE = 0;
    const SpecificationInfo *TRACK_POSITION_SPECIFICATIONS = 0;
    const size_t TRACK_POSITION_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *TRACK_POSITION_RAWS = 0;
    const size_t TRACK_POSITION_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *TRACK_POSITION_TRAYS = 0;
    const size_t TRACK_POSITION_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> BOGIE_POSITIONS_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 17),
        Sim::Info<Sim::Number>("1.Offset", 0.001, 0.0),
        Sim::Info<Sim::Number>("1.From Alpha", 0.5, 0.0),
        Sim::Info<Sim::Number>("1.Segment ID", 0.5, 0.0),
        Sim::Info<Sim::Number>("1.Segment Offset", 1.0E-5, 0.0),
        Sim::Info<Sim::Number>("2.Offset", 0.001, 0.0),
        Sim::Info<Sim::Number>("2.From Alpha", 0.5, 0.0),
        Sim::Info<Sim::Number>("2.Segment ID", 0.5, 0.0),
        Sim::Info<Sim::Number>("2.Segment Offset", 1.0E-5, 0.0),
    };
    const size_t BOGIE_POSITIONS_NUMBERS_SIZE = sizeof(BOGIE_POSITIONS_NUMBERS)/sizeof(BOGIE_POSITIONS_NUMBERS[0]);
    const TagInfo *BOGIE_POSITIONS_TAGS = 0;
    const size_t BOGIE_POSITIONS_TAGS_SIZE = 0;
    const IdentifierInfo *BOGIE_POSITIONS_IDENTIFIERS = 0;
    const size_t BOGIE_POSITIONS_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *BOGIE_POSITIONS_CONSTANTS = 0;
    const size_t BOGIE_POSITIONS_CONSTANTS_SIZE = 0;
    const SpecificationInfo *BOGIE_POSITIONS_SPECIFICATIONS = 0;
    const size_t BOGIE_POSITIONS_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *BOGIE_POSITIONS_RAWS = 0;
    const size_t BOGIE_POSITIONS_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *BOGIE_POSITIONS_TRAYS = 0;
    const size_t BOGIE_POSITIONS_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> WAVE_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 21),
        Sim::Info<Sim::Number>("Wave ID", 0.5, 0.0),
    };
    const size_t WAVE_NUMBERS_SIZE = sizeof(WAVE_NUMBERS)/sizeof(WAVE_NUMBERS[0]);
    const TagInfo *WAVE_TAGS = 0;
    const size_t WAVE_TAGS_SIZE = 0;
    const IdentifierInfo *WAVE_IDENTIFIERS = 0;
    const size_t WAVE_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *WAVE_CONSTANTS = 0;
    const size_t WAVE_CONSTANTS_SIZE = 0;
    const SpecificationInfo *WAVE_SPECIFICATIONS = 0;
    const size_t WAVE_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> WAVE_RAWS[] =
    {
        Sim::Info<Sim::Raw>("WaveData"),
    };
    const size_t WAVE_RAWS_SIZE = sizeof(WAVE_RAWS)/sizeof(WAVE_RAWS[0]);
    const Sim::Info<Sim::Tray> *WAVE_TRAYS = 0;
    const size_t WAVE_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> WORLD_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 1),
    };
    const size_t WORLD_NUMBERS_SIZE = sizeof(WORLD_NUMBERS)/sizeof(WORLD_NUMBERS[0]);
    const TagInfo *WORLD_TAGS = 0;
    const size_t WORLD_TAGS_SIZE = 0;
    const IdentifierInfo *WORLD_IDENTIFIERS = 0;
    const size_t WORLD_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *WORLD_CONSTANTS = 0;
    const size_t WORLD_CONSTANTS_SIZE = 0;
    const SpecificationInfo *WORLD_SPECIFICATIONS = 0;
    const size_t WORLD_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *WORLD_RAWS = 0;
    const size_t WORLD_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *WORLD_TRAYS = 0;
    const size_t WORLD_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> CANVAS_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 110),
        Sim::Info<Sim::Number>("Canvas ID", 0.5, 0.0),
    };
    const size_t CANVAS_NUMBERS_SIZE = sizeof(CANVAS_NUMBERS)/sizeof(CANVAS_NUMBERS[0]);
    const TagInfo *CANVAS_TAGS = 0;
    const size_t CANVAS_TAGS_SIZE = 0;
    const IdentifierInfo *CANVAS_IDENTIFIERS = 0;
    const size_t CANVAS_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *CANVAS_CONSTANTS = 0;
    const size_t CANVAS_CONSTANTS_SIZE = 0;
    const SpecificationInfo *CANVAS_SPECIFICATIONS = 0;
    const size_t CANVAS_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *CANVAS_RAWS = 0;
    const size_t CANVAS_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *CANVAS_TRAYS = 0;
    const size_t CANVAS_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> VIEW_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 109),
        Sim::Info<Sim::Number>("Position", 0.5, 0.0),
        Sim::Info<Sim::Number>("Perspective ID", 0.5, -1.0),
        Sim::Info<Sim::Number>("Automated Perspective ID", 0.5, -1.0),
        Sim::Info<Sim::Number>("User Perspective ID", 0.5, -1.0),
        Sim::Info<Sim::Number>("State", 0.5, 0.0),
        Sim::Info<Sim::Number>("Top", 1.0E-4, 1.0),
        Sim::Info<Sim::Number>("Left", 1.0E-4, 0.0),
        Sim::Info<Sim::Number>("Bottom", 1.0E-4, 0.0),
        Sim::Info<Sim::Number>("Right", 1.0E-4, 1.0),
        Sim::Info<Sim::Number>("Transition Time", 0.01, 0.0),
    };
    const size_t VIEW_NUMBERS_SIZE = sizeof(VIEW_NUMBERS)/sizeof(VIEW_NUMBERS[0]);
    const TagInfo *VIEW_TAGS = 0;
    const size_t VIEW_TAGS_SIZE = 0;
    const IdentifierInfo *VIEW_IDENTIFIERS = 0;
    const size_t VIEW_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *VIEW_CONSTANTS = 0;
    const size_t VIEW_CONSTANTS_SIZE = 0;
    const SpecificationInfo *VIEW_SPECIFICATIONS = 0;
    const size_t VIEW_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *VIEW_RAWS = 0;
    const size_t VIEW_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *VIEW_TRAYS = 0;
    const size_t VIEW_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> DISPLACEMENT_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 27),
        Sim::Info<Sim::Number>("X", 0.0010, 0.0),
        Sim::Info<Sim::Number>("Y", 0.0010, 0.0),
        Sim::Info<Sim::Number>("Z", 0.0010, 0.0),
        Sim::Info<Sim::Number>("H", 0.0010, 0.0),
        Sim::Info<Sim::Number>("P", 0.0010, 0.0),
        Sim::Info<Sim::Number>("R", 0.0010, 0.0),
    };
    const size_t DISPLACEMENT_NUMBERS_SIZE = sizeof(DISPLACEMENT_NUMBERS)/sizeof(DISPLACEMENT_NUMBERS[0]);
    const TagInfo *DISPLACEMENT_TAGS = 0;
    const size_t DISPLACEMENT_TAGS_SIZE = 0;
    const IdentifierInfo *DISPLACEMENT_IDENTIFIERS = 0;
    const size_t DISPLACEMENT_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *DISPLACEMENT_CONSTANTS = 0;
    const size_t DISPLACEMENT_CONSTANTS_SIZE = 0;
    const SpecificationInfo *DISPLACEMENT_SPECIFICATIONS = 0;
    const size_t DISPLACEMENT_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *DISPLACEMENT_RAWS = 0;
    const size_t DISPLACEMENT_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *DISPLACEMENT_TRAYS = 0;
    const size_t DISPLACEMENT_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> VISION_ENGINE_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 111),
        Sim::Info<Sim::Number>("Vision Engine ID", 0.5, 0.0),
        Sim::Info<Sim::Number>("Canvas ID", 0.5, -1.0),
        Sim::Info<Sim::Number>("User Canvas ID", 0.5, -1.0),
        Sim::Info<Sim::Number>("Automated Canvas ID", 0.5, -1.0),
    };
    const size_t VISION_ENGINE_NUMBERS_SIZE = sizeof(VISION_ENGINE_NUMBERS)/sizeof(VISION_ENGINE_NUMBERS[0]);
    const TagInfo *VISION_ENGINE_TAGS = 0;
    const size_t VISION_ENGINE_TAGS_SIZE = 0;
    const IdentifierInfo *VISION_ENGINE_IDENTIFIERS = 0;
    const size_t VISION_ENGINE_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *VISION_ENGINE_CONSTANTS = 0;
    const size_t VISION_ENGINE_CONSTANTS_SIZE = 0;
    const SpecificationInfo *VISION_ENGINE_SPECIFICATIONS = 0;
    const size_t VISION_ENGINE_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *VISION_ENGINE_RAWS = 0;
    const size_t VISION_ENGINE_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *VISION_ENGINE_TRAYS = 0;
    const size_t VISION_ENGINE_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> FEATURE_ANIMATION_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 15),
        Sim::Info<Sim::Number>("Animation Position", 0.01, 0.0),
        Sim::Info<Sim::Number>("Animation Velocity", 0.01, 0.0),
    };
    const size_t FEATURE_ANIMATION_NUMBERS_SIZE = sizeof(FEATURE_ANIMATION_NUMBERS)/sizeof(FEATURE_ANIMATION_NUMBERS[0]);
    const TagInfo *FEATURE_ANIMATION_TAGS = 0;
    const size_t FEATURE_ANIMATION_TAGS_SIZE = 0;
    const IdentifierInfo *FEATURE_ANIMATION_IDENTIFIERS = 0;
    const size_t FEATURE_ANIMATION_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *FEATURE_ANIMATION_CONSTANTS = 0;
    const size_t FEATURE_ANIMATION_CONSTANTS_SIZE = 0;
    const SpecificationInfo *FEATURE_ANIMATION_SPECIFICATIONS = 0;
    const size_t FEATURE_ANIMATION_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *FEATURE_ANIMATION_RAWS = 0;
    const size_t FEATURE_ANIMATION_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *FEATURE_ANIMATION_TRAYS = 0;
    const size_t FEATURE_ANIMATION_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> PLATFORM_PASSENGER_ANIMATION_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 30),
        Sim::Info<Sim::Number>("State", 0.5, 0.0),
        Sim::Info<Sim::Number>("Scenario Train ID", 0.5, 0.0),
    };
    const size_t PLATFORM_PASSENGER_ANIMATION_NUMBERS_SIZE = sizeof(PLATFORM_PASSENGER_ANIMATION_NUMBERS)/sizeof(PLATFORM_PASSENGER_ANIMATION_NUMBERS[0]);
    const TagInfo *PLATFORM_PASSENGER_ANIMATION_TAGS = 0;
    const size_t PLATFORM_PASSENGER_ANIMATION_TAGS_SIZE = 0;
    const IdentifierInfo *PLATFORM_PASSENGER_ANIMATION_IDENTIFIERS = 0;
    const size_t PLATFORM_PASSENGER_ANIMATION_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *PLATFORM_PASSENGER_ANIMATION_CONSTANTS = 0;
    const size_t PLATFORM_PASSENGER_ANIMATION_CONSTANTS_SIZE = 0;
    const SpecificationInfo *PLATFORM_PASSENGER_ANIMATION_SPECIFICATIONS = 0;
    const size_t PLATFORM_PASSENGER_ANIMATION_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *PLATFORM_PASSENGER_ANIMATION_RAWS = 0;
    const size_t PLATFORM_PASSENGER_ANIMATION_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *PLATFORM_PASSENGER_ANIMATION_TRAYS = 0;
    const size_t PLATFORM_PASSENGER_ANIMATION_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> SPEED_LIMIT_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 28),
        Sim::Info<Sim::Number>("Speed Limit", 0.01, 0.0),
        Sim::Info<Sim::Number>("Max Allowable Speed", 0.01, 0.0),
        Sim::Info<Sim::Number>("Requested Profile Direction", 0.5, 0.0),
        Sim::Info<Sim::Number>("Profile Direction", 0.5, 0.0),
    };
    const size_t SPEED_LIMIT_NUMBERS_SIZE = sizeof(SPEED_LIMIT_NUMBERS)/sizeof(SPEED_LIMIT_NUMBERS[0]);
    const TagInfo *SPEED_LIMIT_TAGS = 0;
    const size_t SPEED_LIMIT_TAGS_SIZE = 0;
    const IdentifierInfo *SPEED_LIMIT_IDENTIFIERS = 0;
    const size_t SPEED_LIMIT_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *SPEED_LIMIT_CONSTANTS = 0;
    const size_t SPEED_LIMIT_CONSTANTS_SIZE = 0;
    const SpecificationInfo *SPEED_LIMIT_SPECIFICATIONS = 0;
    const size_t SPEED_LIMIT_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> SPEED_LIMIT_RAWS[] =
    {
        Sim::Info<Sim::Raw>("Speed Limit Profile"),
    };
    const size_t SPEED_LIMIT_RAWS_SIZE = sizeof(SPEED_LIMIT_RAWS)/sizeof(SPEED_LIMIT_RAWS[0]);
    const Sim::Info<Sim::Tray> *SPEED_LIMIT_TRAYS = 0;
    const size_t SPEED_LIMIT_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> IDEAL_TRAIN_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 200),
    };
    const size_t IDEAL_TRAIN_NUMBERS_SIZE = sizeof(IDEAL_TRAIN_NUMBERS)/sizeof(IDEAL_TRAIN_NUMBERS[0]);
    const TagInfo *IDEAL_TRAIN_TAGS = 0;
    const size_t IDEAL_TRAIN_TAGS_SIZE = 0;
    const IdentifierInfo *IDEAL_TRAIN_IDENTIFIERS = 0;
    const size_t IDEAL_TRAIN_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *IDEAL_TRAIN_CONSTANTS = 0;
    const size_t IDEAL_TRAIN_CONSTANTS_SIZE = 0;
    const SpecificationInfo *IDEAL_TRAIN_SPECIFICATIONS = 0;
    const size_t IDEAL_TRAIN_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *IDEAL_TRAIN_RAWS = 0;
    const size_t IDEAL_TRAIN_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *IDEAL_TRAIN_TRAYS = 0;
    const size_t IDEAL_TRAIN_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> COUPLING_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 40),
        Sim::Info<Sim::Number>("End", 0.5, 0.0),
        Sim::Info<Sim::Number>("Other Vehicle ID", 0.5, -1.0),
        Sim::Info<Sim::Number>("Other Vehicle End", 0.5, 0.0),
        Sim::Info<Sim::Number>("Other Vehicle Orientation", 0.5, 0.0),
        Sim::Info<Sim::Number>("Available", 0.5, 0.0),
        Sim::Info<Sim::Number>("Coupled", 0.5, 0.0),
        Sim::Info<Sim::Number>("Separation", 1.0E-5, 0.0),
        Sim::Info<Sim::Number>("Separation Rate", 1.0E-5, 0.0),
        Sim::Info<Sim::Number>("Our Coupling Position", 1.0E-5, 0.0),
        Sim::Info<Sim::Number>("Other Coupling Position", 1.0E-5, 0.0),
        Sim::Info<Sim::Number>("Coupling Separation", 1.0E-5, 0.0),
        Sim::Info<Sim::Number>("Interfacing", 0.5, 0.0),
        Sim::Info<Sim::Number>("Coupled Chain Length", 0.5, 1.0),
    };
    const size_t COUPLING_NUMBERS_SIZE = sizeof(COUPLING_NUMBERS)/sizeof(COUPLING_NUMBERS[0]);
    const TagInfo *COUPLING_TAGS = 0;
    const size_t COUPLING_TAGS_SIZE = 0;
    const IdentifierInfo *COUPLING_IDENTIFIERS = 0;
    const size_t COUPLING_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *COUPLING_CONSTANTS = 0;
    const size_t COUPLING_CONSTANTS_SIZE = 0;
    const SpecificationInfo *COUPLING_SPECIFICATIONS = 0;
    const size_t COUPLING_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *COUPLING_RAWS = 0;
    const size_t COUPLING_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *COUPLING_TRAYS = 0;
    const size_t COUPLING_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> COUPLING_INPUTS_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 41),
        Sim::Info<Sim::Number>("Coupler Type", 0.5, 0),
        Sim::Info<Sim::Number>("Ready To Couple", 0.5, 0),
        Sim::Info<Sim::Number>("Mechanically Coupled", 0.5, 0),
        Sim::Info<Sim::Number>("Coupler Brake Demand", 0.5, 0),
        Sim::Info<Sim::Number>("Electrically Coupled", 0.5, 0),
        Sim::Info<Sim::Number>("Pneumatically Coupled", 0.5, 0),
        Sim::Info<Sim::Number>("Pneumatic Coupler Pressure", 0.5, 0),
        Sim::Info<Sim::Number>("Electrical Coupler Type", 0.5, 0),
        Sim::Info<Sim::Number>("Pneumatic Coupler Type", 0.5, 0),
        Sim::Info<Sim::Number>("Rescue Power Supply", 0.5, 0),
        Sim::Info<Sim::Number>("Signal", 0.01, 0),
    };
    const size_t COUPLING_INPUTS_NUMBERS_SIZE = sizeof(COUPLING_INPUTS_NUMBERS)/sizeof(COUPLING_INPUTS_NUMBERS[0]);
    const TagInfo *COUPLING_INPUTS_TAGS = 0;
    const size_t COUPLING_INPUTS_TAGS_SIZE = 0;
    const IdentifierInfo *COUPLING_INPUTS_IDENTIFIERS = 0;
    const size_t COUPLING_INPUTS_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *COUPLING_INPUTS_CONSTANTS = 0;
    const size_t COUPLING_INPUTS_CONSTANTS_SIZE = 0;
    const SpecificationInfo *COUPLING_INPUTS_SPECIFICATIONS = 0;
    const size_t COUPLING_INPUTS_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *COUPLING_INPUTS_RAWS = 0;
    const size_t COUPLING_INPUTS_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *COUPLING_INPUTS_TRAYS = 0;
    const size_t COUPLING_INPUTS_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> COUPLING_OUTPUTS_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 42),
        Sim::Info<Sim::Number>("Coupler Type", 0.5, 0),
        Sim::Info<Sim::Number>("Ready To Couple", 0.5, 0),
        Sim::Info<Sim::Number>("Mechanically Coupled", 0.5, 0),
        Sim::Info<Sim::Number>("Coupler Brake Demand", 0.5, 0),
        Sim::Info<Sim::Number>("Electrically Coupled", 0.5, 0),
        Sim::Info<Sim::Number>("Pneumatically Coupled", 0.5, 0),
        Sim::Info<Sim::Number>("Pneumatic Coupler Pressure", 0.5, 0),
        Sim::Info<Sim::Number>("Electrical Coupler Type", 0.5, 0),
        Sim::Info<Sim::Number>("Pneumatic Coupler Type", 0.5, 0),
        Sim::Info<Sim::Number>("Rescue Power Supply", 0.5, 0),
        Sim::Info<Sim::Number>("Signal", 0.01, 0),
    };
    const size_t COUPLING_OUTPUTS_NUMBERS_SIZE = sizeof(COUPLING_OUTPUTS_NUMBERS)/sizeof(COUPLING_OUTPUTS_NUMBERS[0]);
    const TagInfo *COUPLING_OUTPUTS_TAGS = 0;
    const size_t COUPLING_OUTPUTS_TAGS_SIZE = 0;
    const IdentifierInfo *COUPLING_OUTPUTS_IDENTIFIERS = 0;
    const size_t COUPLING_OUTPUTS_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *COUPLING_OUTPUTS_CONSTANTS = 0;
    const size_t COUPLING_OUTPUTS_CONSTANTS_SIZE = 0;
    const SpecificationInfo *COUPLING_OUTPUTS_SPECIFICATIONS = 0;
    const size_t COUPLING_OUTPUTS_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *COUPLING_OUTPUTS_RAWS = 0;
    const size_t COUPLING_OUTPUTS_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *COUPLING_OUTPUTS_TRAYS = 0;
    const size_t COUPLING_OUTPUTS_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> MIMIC_INPUTS_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 43),
        Sim::Info<Sim::Number>("Time", 1.0E-4, 0.0),
        Sim::Info<Sim::Number>("Mass", 1.0, 45000.0),
        Sim::Info<Sim::Number>("Position", 1.0E-5, 0.0),
        Sim::Info<Sim::Number>("Velocity", 1.0E-5, 0.0),
        Sim::Info<Sim::Number>("Acceleration", 1.0E-5, 0.0),
        Sim::Info<Sim::Number>("Gradient", 0.001, 0.0),
        Sim::Info<Sim::Number>("Radius", 1.0, 0.0),
        Sim::Info<Sim::Number>("Tractive Force", 10.0, 0.0),
        Sim::Info<Sim::Number>("Braking Force", 10.0, 0.0),
        Sim::Info<Sim::Number>("Other Coupler Force", 10.0, 0.0),
        Sim::Info<Sim::Number>("Other Coupler Force Rate", 10.0, 0.0),
    };
    const size_t MIMIC_INPUTS_NUMBERS_SIZE = sizeof(MIMIC_INPUTS_NUMBERS)/sizeof(MIMIC_INPUTS_NUMBERS[0]);
    const TagInfo MIMIC_INPUTS_TAGS[] =
    {
        { "Mimic Info" },
        { "Inputs" },
    };
    const size_t MIMIC_INPUTS_TAGS_SIZE = sizeof(MIMIC_INPUTS_TAGS)/sizeof(MIMIC_INPUTS_TAGS[0]);
    const IdentifierInfo *MIMIC_INPUTS_IDENTIFIERS = 0;
    const size_t MIMIC_INPUTS_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *MIMIC_INPUTS_CONSTANTS = 0;
    const size_t MIMIC_INPUTS_CONSTANTS_SIZE = 0;
    const SpecificationInfo *MIMIC_INPUTS_SPECIFICATIONS = 0;
    const size_t MIMIC_INPUTS_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *MIMIC_INPUTS_RAWS = 0;
    const size_t MIMIC_INPUTS_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *MIMIC_INPUTS_TRAYS = 0;
    const size_t MIMIC_INPUTS_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> MIMIC_OUTPUTS_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 44),
        Sim::Info<Sim::Number>("Time", 1.0E-4, 0.0),
        Sim::Info<Sim::Number>("Mass", 1.0, 45000.0),
        Sim::Info<Sim::Number>("Position", 1.0E-5, 0.0),
        Sim::Info<Sim::Number>("Velocity", 1.0E-5, 0.0),
        Sim::Info<Sim::Number>("Acceleration", 1.0E-5, 0.0),
        Sim::Info<Sim::Number>("Gradient", 0.001, 0.0),
        Sim::Info<Sim::Number>("Radius", 1.0, 0.0),
        Sim::Info<Sim::Number>("Tractive Force", 10.0, 0.0),
        Sim::Info<Sim::Number>("Braking Force", 10.0, 0.0),
        Sim::Info<Sim::Number>("Other Coupler Force", 10.0, 0.0),
        Sim::Info<Sim::Number>("Other Coupler Force Rate", 10.0, 0.0),
    };
    const size_t MIMIC_OUTPUTS_NUMBERS_SIZE = sizeof(MIMIC_OUTPUTS_NUMBERS)/sizeof(MIMIC_OUTPUTS_NUMBERS[0]);
    const TagInfo MIMIC_OUTPUTS_TAGS[] =
    {
        { "Mimic Info" },
        { "Outputs" },
    };
    const size_t MIMIC_OUTPUTS_TAGS_SIZE = sizeof(MIMIC_OUTPUTS_TAGS)/sizeof(MIMIC_OUTPUTS_TAGS[0]);
    const IdentifierInfo *MIMIC_OUTPUTS_IDENTIFIERS = 0;
    const size_t MIMIC_OUTPUTS_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *MIMIC_OUTPUTS_CONSTANTS = 0;
    const size_t MIMIC_OUTPUTS_CONSTANTS_SIZE = 0;
    const SpecificationInfo *MIMIC_OUTPUTS_SPECIFICATIONS = 0;
    const size_t MIMIC_OUTPUTS_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *MIMIC_OUTPUTS_RAWS = 0;
    const size_t MIMIC_OUTPUTS_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *MIMIC_OUTPUTS_TRAYS = 0;
    const size_t MIMIC_OUTPUTS_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> MULTIMEDIA_DISPLAY_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 118),
        Sim::Info<Sim::Number>("Multimedia ID", 0.5, 0.0),
    };
    const size_t MULTIMEDIA_DISPLAY_NUMBERS_SIZE = sizeof(MULTIMEDIA_DISPLAY_NUMBERS)/sizeof(MULTIMEDIA_DISPLAY_NUMBERS[0]);
    const TagInfo *MULTIMEDIA_DISPLAY_TAGS = 0;
    const size_t MULTIMEDIA_DISPLAY_TAGS_SIZE = 0;
    const IdentifierInfo *MULTIMEDIA_DISPLAY_IDENTIFIERS = 0;
    const size_t MULTIMEDIA_DISPLAY_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *MULTIMEDIA_DISPLAY_CONSTANTS = 0;
    const size_t MULTIMEDIA_DISPLAY_CONSTANTS_SIZE = 0;
    const SpecificationInfo *MULTIMEDIA_DISPLAY_SPECIFICATIONS = 0;
    const size_t MULTIMEDIA_DISPLAY_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *MULTIMEDIA_DISPLAY_RAWS = 0;
    const size_t MULTIMEDIA_DISPLAY_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *MULTIMEDIA_DISPLAY_TRAYS = 0;
    const size_t MULTIMEDIA_DISPLAY_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> COLLISION_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 45),
        Sim::Info<Sim::Number>("State", 0.5, 0.0),
        Sim::Info<Sim::Number>("Mass", 1.0, 0.0),
        Sim::Info<Sim::Number>("x", 1.0E-5, 0.0),
        Sim::Info<Sim::Number>("y", 1.0E-5, 0.0),
        Sim::Info<Sim::Number>("z", 1.0E-5, 0.0),
        Sim::Info<Sim::Number>("vx", 1.0E-5, 0.0),
        Sim::Info<Sim::Number>("vy", 1.0E-5, 0.0),
        Sim::Info<Sim::Number>("vz", 1.0E-5, 0.0),
        Sim::Info<Sim::Number>("Fx", 1.0E-5, 0.0),
        Sim::Info<Sim::Number>("Fy", 1.0E-5, 0.0),
        Sim::Info<Sim::Number>("Fz", 1.0E-5, 0.0),
        Sim::Info<Sim::Number>("Separation", 1.0E-5, 0.0),
        Sim::Info<Sim::Number>("Separation Rate", 1.0E-5, 0.0),
    };
    const size_t COLLISION_NUMBERS_SIZE = sizeof(COLLISION_NUMBERS)/sizeof(COLLISION_NUMBERS[0]);
    const TagInfo COLLISION_TAGS[] =
    {
        { "Collision" },
    };
    const size_t COLLISION_TAGS_SIZE = sizeof(COLLISION_TAGS)/sizeof(COLLISION_TAGS[0]);
    const IdentifierInfo COLLISION_IDENTIFIERS[] =
    {
        { "Collision ID",  },
        { "Feature ID",  },
        { "Vehicle ID",  },
        { "Object ID",  },
    };
    const size_t COLLISION_IDENTIFIERS_SIZE = sizeof(COLLISION_IDENTIFIERS)/sizeof(COLLISION_IDENTIFIERS[0]);
    const ConstantInfo *COLLISION_CONSTANTS = 0;
    const size_t COLLISION_CONSTANTS_SIZE = 0;
    const SpecificationInfo *COLLISION_SPECIFICATIONS = 0;
    const size_t COLLISION_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *COLLISION_RAWS = 0;
    const size_t COLLISION_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *COLLISION_TRAYS = 0;
    const size_t COLLISION_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> ETCS_ONBOARD_INPUTS_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 150),
        Sim::Info<Sim::Number>("Last Detected Balise", 0.5, 0),
        Sim::Info<Sim::Number>("Scenario Setup SOM", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Track Ahead Ack", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Mode Acknowledged", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Level Acknowledged", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Driver Requested Level", 0.5, -1),
        Sim::Info<Sim::Number>("ETCS Driver Requested NTC Level", 0.5, -1),
        Sim::Info<Sim::Number>("ETCS Message Acknowledged", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Message Neg Acknowledged", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS EOA Override Request", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Adhesion Input", 0.5, -1),
        Sim::Info<Sim::Number>("ETCS SR Distance", 0.1, 0),
        Sim::Info<Sim::Number>("ETCS SR Speed", 0.1, 0),
        Sim::Info<Sim::Number>("ETCS SR Data Entry Screen Active", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS SR Data Confirmation", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Start Of Mission Request", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Radio Network Id Request", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS RBC Id", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS RBC Phone Number", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS RBC Data Complete", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS RBC Contact", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS System Failure", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Brake Intervention Acknowledged", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Enable Tunnel Stopping Areas", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Request Shunting", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Request Radio Networks", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Register Network ID", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Contact RBC Phone Number", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Panel A B Toggle Status", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Validate Train Data", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Train Data Status", 0.5, 0),
        Sim::Info<Sim::Number>("Drive Id", 0.5, 0),
    };
    const size_t ETCS_ONBOARD_INPUTS_NUMBERS_SIZE = sizeof(ETCS_ONBOARD_INPUTS_NUMBERS)/sizeof(ETCS_ONBOARD_INPUTS_NUMBERS[0]);
    const TagInfo *ETCS_ONBOARD_INPUTS_TAGS = 0;
    const size_t ETCS_ONBOARD_INPUTS_TAGS_SIZE = 0;
    const IdentifierInfo *ETCS_ONBOARD_INPUTS_IDENTIFIERS = 0;
    const size_t ETCS_ONBOARD_INPUTS_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *ETCS_ONBOARD_INPUTS_CONSTANTS = 0;
    const size_t ETCS_ONBOARD_INPUTS_CONSTANTS_SIZE = 0;
    const SpecificationInfo *ETCS_ONBOARD_INPUTS_SPECIFICATIONS = 0;
    const size_t ETCS_ONBOARD_INPUTS_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> ETCS_ONBOARD_INPUTS_RAWS[] =
    {
        Sim::Info<Sim::Raw>("ETCS Train Data"),
    };
    const size_t ETCS_ONBOARD_INPUTS_RAWS_SIZE = sizeof(ETCS_ONBOARD_INPUTS_RAWS)/sizeof(ETCS_ONBOARD_INPUTS_RAWS[0]);
    const Sim::Info<Sim::Tray> ETCS_ONBOARD_INPUTS_TRAYS[] =
    {
        Sim::Info<Sim::Tray>("TrackSide Messages"),
    };
    const size_t ETCS_ONBOARD_INPUTS_TRAYS_SIZE = sizeof(ETCS_ONBOARD_INPUTS_TRAYS)/sizeof(ETCS_ONBOARD_INPUTS_TRAYS[0]);
    const Sim::Info<Sim::Number> ETCS_ONBOARD_OUTPUTS_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 151),
        Sim::Info<Sim::Number>("ETCS Current Mode", 0.5, -1),
        Sim::Info<Sim::Number>("ETCS Mode Ack Requested", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Current Level", 0.5, -1),
        Sim::Info<Sim::Number>("ETCS NTC Level", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS NTC Level Requested", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Level Requested", 0.5, -1),
        Sim::Info<Sim::Number>("ETCS Level Ack Requested", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Speed Status", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Release Speed", 0.1, 0),
        Sim::Info<Sim::Number>("ETCS Target Speed", 0.1, 0),
        Sim::Info<Sim::Number>("ETCS Permitted Speed", 0.1, 0),
        Sim::Info<Sim::Number>("ETCS Current Speed", 0.1, 0),
        Sim::Info<Sim::Number>("ETCS Intervention Speed", 0.1, 0),
        Sim::Info<Sim::Number>("ETCS Monitoring Mode", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Limited Supervised Speed", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Distance to Target Speed", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Indication marker distance", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Brake Intervention", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Brake Intervention Ack Requested", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Train Geographical Position", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Reversing Permitted", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Track Ahead Info", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Override State", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Adhesion Available", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS SR Speed Available", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Train Integrity Available", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Tunnel Stopping", 0.5, -1),
        Sim::Info<Sim::Number>("ETCS Tunnel Stopping Remaining Distance", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Radio Connection", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Train Position", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS SR Distance", 0.1, 0),
        Sim::Info<Sim::Number>("ETCS SR Speed", 0.1, 0),
        Sim::Info<Sim::Number>("Emergency Stop Active", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Registered Network", 0.1, 0),
        Sim::Info<Sim::Number>("ETCS RBC Data", 0.1, 0),
        Sim::Info<Sim::Number>("ETCS Train Data Ack", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Connect Hour Glass State", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Start of Mission Completed", 0.5, 0),
    };
    const size_t ETCS_ONBOARD_OUTPUTS_NUMBERS_SIZE = sizeof(ETCS_ONBOARD_OUTPUTS_NUMBERS)/sizeof(ETCS_ONBOARD_OUTPUTS_NUMBERS[0]);
    const TagInfo *ETCS_ONBOARD_OUTPUTS_TAGS = 0;
    const size_t ETCS_ONBOARD_OUTPUTS_TAGS_SIZE = 0;
    const IdentifierInfo *ETCS_ONBOARD_OUTPUTS_IDENTIFIERS = 0;
    const size_t ETCS_ONBOARD_OUTPUTS_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *ETCS_ONBOARD_OUTPUTS_CONSTANTS = 0;
    const size_t ETCS_ONBOARD_OUTPUTS_CONSTANTS_SIZE = 0;
    const SpecificationInfo *ETCS_ONBOARD_OUTPUTS_SPECIFICATIONS = 0;
    const size_t ETCS_ONBOARD_OUTPUTS_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> ETCS_ONBOARD_OUTPUTS_RAWS[] =
    {
        Sim::Info<Sim::Raw>("ETCS Gradients And Speed Discontinuities"),
        Sim::Info<Sim::Raw>("ETCS Order Announcements"),
        Sim::Info<Sim::Raw>("ETCS Messages"),
        Sim::Info<Sim::Raw>("ETCS Available Levels"),
        Sim::Info<Sim::Raw>("ETCS Allowed Radio Networks"),
    };
    const size_t ETCS_ONBOARD_OUTPUTS_RAWS_SIZE = sizeof(ETCS_ONBOARD_OUTPUTS_RAWS)/sizeof(ETCS_ONBOARD_OUTPUTS_RAWS[0]);
    const Sim::Info<Sim::Tray> *ETCS_ONBOARD_OUTPUTS_TRAYS = 0;
    const size_t ETCS_ONBOARD_OUTPUTS_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> ETCS_VEHICLE_INPUTS_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 160),
        Sim::Info<Sim::Number>("In ETCS Level 0 Region", 0.5, 0),
        Sim::Info<Sim::Number>("In ETCS Level 1 Region", 0.5, 0),
        Sim::Info<Sim::Number>("In ETCS Level 2 Region", 0.5, 0),
        Sim::Info<Sim::Number>("Traction Cutoff Order", 0.5, 1),
        Sim::Info<Sim::Number>("Service Brake Order", 0.5, 0),
        Sim::Info<Sim::Number>("Emergency Brake Order", 0.5, 1),
        Sim::Info<Sim::Number>("Level NTC", 0.5, -1),
        Sim::Info<Sim::Number>("STM A State Order", 0.5, 0),
        Sim::Info<Sim::Number>("STM B State Order", 0.5, 0),
        Sim::Info<Sim::Number>("STM A Brake Release Command", 0.5, 0),
        Sim::Info<Sim::Number>("STM B Brake Release Command", 0.5, 0),
        Sim::Info<Sim::Number>("Audio Overspeed Alarm", 0.5, 0),
        Sim::Info<Sim::Number>("Audio Warning Alarm", 0.5, 0),
        Sim::Info<Sim::Number>("Audio Sinfo Alert", 0.5, 0),
        Sim::Info<Sim::Number>("Audio End Of Intervention Alert", 0.5, 0),
        Sim::Info<Sim::Number>("Audio ATP Down Alarm", 0.5, 0),
    };
    const size_t ETCS_VEHICLE_INPUTS_NUMBERS_SIZE = sizeof(ETCS_VEHICLE_INPUTS_NUMBERS)/sizeof(ETCS_VEHICLE_INPUTS_NUMBERS[0]);
    const TagInfo *ETCS_VEHICLE_INPUTS_TAGS = 0;
    const size_t ETCS_VEHICLE_INPUTS_TAGS_SIZE = 0;
    const IdentifierInfo *ETCS_VEHICLE_INPUTS_IDENTIFIERS = 0;
    const size_t ETCS_VEHICLE_INPUTS_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *ETCS_VEHICLE_INPUTS_CONSTANTS = 0;
    const size_t ETCS_VEHICLE_INPUTS_CONSTANTS_SIZE = 0;
    const SpecificationInfo *ETCS_VEHICLE_INPUTS_SPECIFICATIONS = 0;
    const size_t ETCS_VEHICLE_INPUTS_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *ETCS_VEHICLE_INPUTS_RAWS = 0;
    const size_t ETCS_VEHICLE_INPUTS_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *ETCS_VEHICLE_INPUTS_TRAYS = 0;
    const size_t ETCS_VEHICLE_INPUTS_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> ETCS_VEHICLE_OUTPUTS_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 161),
        Sim::Info<Sim::Number>("In ETCS Level 0 Region", 0.5, -1),
        Sim::Info<Sim::Number>("In ETCS Level 1 Region", 0.5, -1),
        Sim::Info<Sim::Number>("In ETCS Level 2 Region", 0.5, -1),
        Sim::Info<Sim::Number>("Cabin Activation", 0.5, 0),
        Sim::Info<Sim::Number>("Direction", 0.5, 0),
        Sim::Info<Sim::Number>("Power Supply", 0.5, 0),
        Sim::Info<Sim::Number>("Emergency Brake Feedback", 0.5, 0),
        Sim::Info<Sim::Number>("Brake Applied Feedback", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Isolation", 0.5, 0),
        Sim::Info<Sim::Number>("STM A Isolation", 0.5, 0),
        Sim::Info<Sim::Number>("STM B Isolation", 0.5, 0),
        Sim::Info<Sim::Number>("STM A State Report", 0.5, 0),
        Sim::Info<Sim::Number>("STM B State Report", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Reset", 0.5, 0),
        Sim::Info<Sim::Number>("In STM A Region", 0.5, -1),
        Sim::Info<Sim::Number>("In STM B Region", 0.5, -1),
        Sim::Info<Sim::Number>("Enable Sleeping Mode", 0.5, 0),
        Sim::Info<Sim::Number>("Autofill SOM Auto Reverse", 0.5, 0),
        Sim::Info<Sim::Number>("Cab Reactivation SOM Required", 0.5, 0),
        Sim::Info<Sim::Number>("STM A Emergency Brake Command", 0.5, 0),
        Sim::Info<Sim::Number>("STM B Emergency Brake Command", 0.5, 0),
    };
    const size_t ETCS_VEHICLE_OUTPUTS_NUMBERS_SIZE = sizeof(ETCS_VEHICLE_OUTPUTS_NUMBERS)/sizeof(ETCS_VEHICLE_OUTPUTS_NUMBERS[0]);
    const TagInfo *ETCS_VEHICLE_OUTPUTS_TAGS = 0;
    const size_t ETCS_VEHICLE_OUTPUTS_TAGS_SIZE = 0;
    const IdentifierInfo *ETCS_VEHICLE_OUTPUTS_IDENTIFIERS = 0;
    const size_t ETCS_VEHICLE_OUTPUTS_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *ETCS_VEHICLE_OUTPUTS_CONSTANTS = 0;
    const size_t ETCS_VEHICLE_OUTPUTS_CONSTANTS_SIZE = 0;
    const SpecificationInfo *ETCS_VEHICLE_OUTPUTS_SPECIFICATIONS = 0;
    const size_t ETCS_VEHICLE_OUTPUTS_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *ETCS_VEHICLE_OUTPUTS_RAWS = 0;
    const size_t ETCS_VEHICLE_OUTPUTS_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *ETCS_VEHICLE_OUTPUTS_TRAYS = 0;
    const size_t ETCS_VEHICLE_OUTPUTS_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> GSMR_AREAS_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 204),
    };
    const size_t GSMR_AREAS_NUMBERS_SIZE = sizeof(GSMR_AREAS_NUMBERS)/sizeof(GSMR_AREAS_NUMBERS[0]);
    const TagInfo *GSMR_AREAS_TAGS = 0;
    const size_t GSMR_AREAS_TAGS_SIZE = 0;
    const IdentifierInfo *GSMR_AREAS_IDENTIFIERS = 0;
    const size_t GSMR_AREAS_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *GSMR_AREAS_CONSTANTS = 0;
    const size_t GSMR_AREAS_CONSTANTS_SIZE = 0;
    const SpecificationInfo *GSMR_AREAS_SPECIFICATIONS = 0;
    const size_t GSMR_AREAS_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *GSMR_AREAS_RAWS = 0;
    const size_t GSMR_AREAS_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *GSMR_AREAS_TRAYS = 0;
    const size_t GSMR_AREAS_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> GSMR_AREA_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 203),
        Sim::Info<Sim::Number>("Instance", 0.5, 0.0),
        Sim::Info<Sim::Number>("Area Code", 0.5, 0.0),
        Sim::Info<Sim::Number>("Status OK", 0.5, 0.0),
    };
    const size_t GSMR_AREA_NUMBERS_SIZE = sizeof(GSMR_AREA_NUMBERS)/sizeof(GSMR_AREA_NUMBERS[0]);
    const TagInfo *GSMR_AREA_TAGS = 0;
    const size_t GSMR_AREA_TAGS_SIZE = 0;
    const IdentifierInfo *GSMR_AREA_IDENTIFIERS = 0;
    const size_t GSMR_AREA_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *GSMR_AREA_CONSTANTS = 0;
    const size_t GSMR_AREA_CONSTANTS_SIZE = 0;
    const SpecificationInfo *GSMR_AREA_SPECIFICATIONS = 0;
    const size_t GSMR_AREA_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> GSMR_AREA_RAWS[] =
    {
        Sim::Info<Sim::Raw>("Auto Trains In Area"),
        Sim::Info<Sim::Raw>("Name"),
        Sim::Info<Sim::Raw>("Signallers Controlling Area"),
        Sim::Info<Sim::Raw>("Trains In Area"),
    };
    const size_t GSMR_AREA_RAWS_SIZE = sizeof(GSMR_AREA_RAWS)/sizeof(GSMR_AREA_RAWS[0]);
    const Sim::Info<Sim::Tray> *GSMR_AREA_TRAYS = 0;
    const size_t GSMR_AREA_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> GSMR_CAB_INPUTS_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 213),
    };
    const size_t GSMR_CAB_INPUTS_NUMBERS_SIZE = sizeof(GSMR_CAB_INPUTS_NUMBERS)/sizeof(GSMR_CAB_INPUTS_NUMBERS[0]);
    const TagInfo *GSMR_CAB_INPUTS_TAGS = 0;
    const size_t GSMR_CAB_INPUTS_TAGS_SIZE = 0;
    const IdentifierInfo *GSMR_CAB_INPUTS_IDENTIFIERS = 0;
    const size_t GSMR_CAB_INPUTS_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *GSMR_CAB_INPUTS_CONSTANTS = 0;
    const size_t GSMR_CAB_INPUTS_CONSTANTS_SIZE = 0;
    const SpecificationInfo *GSMR_CAB_INPUTS_SPECIFICATIONS = 0;
    const size_t GSMR_CAB_INPUTS_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> GSMR_CAB_INPUTS_RAWS[] =
    {
        Sim::Info<Sim::Raw>("Request Auto Registration"),
    };
    const size_t GSMR_CAB_INPUTS_RAWS_SIZE = sizeof(GSMR_CAB_INPUTS_RAWS)/sizeof(GSMR_CAB_INPUTS_RAWS[0]);
    const Sim::Info<Sim::Tray> *GSMR_CAB_INPUTS_TRAYS = 0;
    const size_t GSMR_CAB_INPUTS_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> GSMR_CAB_OUTPUTS_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 211),
    };
    const size_t GSMR_CAB_OUTPUTS_NUMBERS_SIZE = sizeof(GSMR_CAB_OUTPUTS_NUMBERS)/sizeof(GSMR_CAB_OUTPUTS_NUMBERS[0]);
    const TagInfo *GSMR_CAB_OUTPUTS_TAGS = 0;
    const size_t GSMR_CAB_OUTPUTS_TAGS_SIZE = 0;
    const IdentifierInfo *GSMR_CAB_OUTPUTS_IDENTIFIERS = 0;
    const size_t GSMR_CAB_OUTPUTS_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *GSMR_CAB_OUTPUTS_CONSTANTS = 0;
    const size_t GSMR_CAB_OUTPUTS_CONSTANTS_SIZE = 0;
    const SpecificationInfo *GSMR_CAB_OUTPUTS_SPECIFICATIONS = 0;
    const size_t GSMR_CAB_OUTPUTS_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *GSMR_CAB_OUTPUTS_RAWS = 0;
    const size_t GSMR_CAB_OUTPUTS_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *GSMR_CAB_OUTPUTS_TRAYS = 0;
    const size_t GSMR_CAB_OUTPUTS_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> GSMR_CAB_STATE_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 212),
        Sim::Info<Sim::Number>("GSMR Cab Handset Speaker Volume", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab Speaker Volume", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Cab Standing at Signal", 0.5, 0.0),
        Sim::Info<Sim::Number>("Logged In Role", 0.5, 0.0),
        Sim::Info<Sim::Number>("Multiparty Call Id", 0.5, 0.0),
        Sim::Info<Sim::Number>("PA Registered", 0.5, 0.0),
        Sim::Info<Sim::Number>("SCC Contact FT", 0.5, 0.0),
        Sim::Info<Sim::Number>("SCC Contact Signaller", 0.5, 0.0),
        Sim::Info<Sim::Number>("SCC PreRecorded Broadcast", 0.5, 0.0),
        Sim::Info<Sim::Number>("SCC Wait", 0.5, 0.0),
        Sim::Info<Sim::Number>("Shunting Area ID", 0.5, 0.0),
        Sim::Info<Sim::Number>("Shunting Team ID", 0.5, 0.0),
        Sim::Info<Sim::Number>("Sound", 0.5, 0.0),
        Sim::Info<Sim::Number>("Sound Continuous", 0.5, 0.0),
        Sim::Info<Sim::Number>("Transferred Call Id", 0.5, 0.0),
        Sim::Info<Sim::Number>("Broadcast Acknowledge", 0.5, 0.0),
        Sim::Info<Sim::Number>("PA Call Active", 0.5, 0.0),
    };
    const size_t GSMR_CAB_STATE_NUMBERS_SIZE = sizeof(GSMR_CAB_STATE_NUMBERS)/sizeof(GSMR_CAB_STATE_NUMBERS[0]);
    const TagInfo *GSMR_CAB_STATE_TAGS = 0;
    const size_t GSMR_CAB_STATE_TAGS_SIZE = 0;
    const IdentifierInfo *GSMR_CAB_STATE_IDENTIFIERS = 0;
    const size_t GSMR_CAB_STATE_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *GSMR_CAB_STATE_CONSTANTS = 0;
    const size_t GSMR_CAB_STATE_CONSTANTS_SIZE = 0;
    const SpecificationInfo *GSMR_CAB_STATE_SPECIFICATIONS = 0;
    const size_t GSMR_CAB_STATE_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *GSMR_CAB_STATE_RAWS = 0;
    const size_t GSMR_CAB_STATE_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *GSMR_CAB_STATE_TRAYS = 0;
    const size_t GSMR_CAB_STATE_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> GSMR_CALLS_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 205),
    };
    const size_t GSMR_CALLS_NUMBERS_SIZE = sizeof(GSMR_CALLS_NUMBERS)/sizeof(GSMR_CALLS_NUMBERS[0]);
    const TagInfo *GSMR_CALLS_TAGS = 0;
    const size_t GSMR_CALLS_TAGS_SIZE = 0;
    const IdentifierInfo *GSMR_CALLS_IDENTIFIERS = 0;
    const size_t GSMR_CALLS_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *GSMR_CALLS_CONSTANTS = 0;
    const size_t GSMR_CALLS_CONSTANTS_SIZE = 0;
    const SpecificationInfo *GSMR_CALLS_SPECIFICATIONS = 0;
    const size_t GSMR_CALLS_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *GSMR_CALLS_RAWS = 0;
    const size_t GSMR_CALLS_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *GSMR_CALLS_TRAYS = 0;
    const size_t GSMR_CALLS_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> GSMR_CALL_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 214),
        Sim::Info<Sim::Number>("Instance", 0.5, 0.0),
        Sim::Info<Sim::Number>("Call Mode", 0.5, 0.0),
        Sim::Info<Sim::Number>("Call Request ID", 0.5, 0.0),
        Sim::Info<Sim::Number>("Call State", 0.5, 0.0),
        Sim::Info<Sim::Number>("Call Type", 0.5, 0.0),
        Sim::Info<Sim::Number>("Initiator ID", 0.5, 0.0),
        Sim::Info<Sim::Number>("Priority", 0.5, 0.0),
        Sim::Info<Sim::Number>("Responding Client ID", 0.5, 0.0),
    };
    const size_t GSMR_CALL_NUMBERS_SIZE = sizeof(GSMR_CALL_NUMBERS)/sizeof(GSMR_CALL_NUMBERS[0]);
    const TagInfo *GSMR_CALL_TAGS = 0;
    const size_t GSMR_CALL_TAGS_SIZE = 0;
    const IdentifierInfo *GSMR_CALL_IDENTIFIERS = 0;
    const size_t GSMR_CALL_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *GSMR_CALL_CONSTANTS = 0;
    const size_t GSMR_CALL_CONSTANTS_SIZE = 0;
    const SpecificationInfo *GSMR_CALL_SPECIFICATIONS = 0;
    const size_t GSMR_CALL_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> GSMR_CALL_RAWS[] =
    {
        Sim::Info<Sim::Raw>("Destination"),
        Sim::Info<Sim::Raw>("Source"),
    };
    const size_t GSMR_CALL_RAWS_SIZE = sizeof(GSMR_CALL_RAWS)/sizeof(GSMR_CALL_RAWS[0]);
    const Sim::Info<Sim::Tray> *GSMR_CALL_TRAYS = 0;
    const size_t GSMR_CALL_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> GSMR_REQUESTS_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 208),
    };
    const size_t GSMR_REQUESTS_NUMBERS_SIZE = sizeof(GSMR_REQUESTS_NUMBERS)/sizeof(GSMR_REQUESTS_NUMBERS[0]);
    const TagInfo *GSMR_REQUESTS_TAGS = 0;
    const size_t GSMR_REQUESTS_TAGS_SIZE = 0;
    const IdentifierInfo *GSMR_REQUESTS_IDENTIFIERS = 0;
    const size_t GSMR_REQUESTS_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *GSMR_REQUESTS_CONSTANTS = 0;
    const size_t GSMR_REQUESTS_CONSTANTS_SIZE = 0;
    const SpecificationInfo *GSMR_REQUESTS_SPECIFICATIONS = 0;
    const size_t GSMR_REQUESTS_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *GSMR_REQUESTS_RAWS = 0;
    const size_t GSMR_REQUESTS_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *GSMR_REQUESTS_TRAYS = 0;
    const size_t GSMR_REQUESTS_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> GSMR_AREA_CONTROL_REQUEST_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 210),
        Sim::Info<Sim::Number>("Instance", 0.5, 0.0),
        Sim::Info<Sim::Number>("Area Code", 0.5, 0.0),
        Sim::Info<Sim::Number>("Initiator ID", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request State", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Type", 0.5, 0.0),
    };
    const size_t GSMR_AREA_CONTROL_REQUEST_NUMBERS_SIZE = sizeof(GSMR_AREA_CONTROL_REQUEST_NUMBERS)/sizeof(GSMR_AREA_CONTROL_REQUEST_NUMBERS[0]);
    const TagInfo *GSMR_AREA_CONTROL_REQUEST_TAGS = 0;
    const size_t GSMR_AREA_CONTROL_REQUEST_TAGS_SIZE = 0;
    const IdentifierInfo *GSMR_AREA_CONTROL_REQUEST_IDENTIFIERS = 0;
    const size_t GSMR_AREA_CONTROL_REQUEST_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *GSMR_AREA_CONTROL_REQUEST_CONSTANTS = 0;
    const size_t GSMR_AREA_CONTROL_REQUEST_CONSTANTS_SIZE = 0;
    const SpecificationInfo *GSMR_AREA_CONTROL_REQUEST_SPECIFICATIONS = 0;
    const size_t GSMR_AREA_CONTROL_REQUEST_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *GSMR_AREA_CONTROL_REQUEST_RAWS = 0;
    const size_t GSMR_AREA_CONTROL_REQUEST_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *GSMR_AREA_CONTROL_REQUEST_TRAYS = 0;
    const size_t GSMR_AREA_CONTROL_REQUEST_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> GSMR_CALL_REQUEST_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 201),
        Sim::Info<Sim::Number>("Instance", 0.5, 0.0),
        Sim::Info<Sim::Number>("Call Type", 0.5, 0.0),
        Sim::Info<Sim::Number>("Initiator ID", 0.5, 0.0),
        Sim::Info<Sim::Number>("Priority", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request State", 0.5, 0.0),
    };
    const size_t GSMR_CALL_REQUEST_NUMBERS_SIZE = sizeof(GSMR_CALL_REQUEST_NUMBERS)/sizeof(GSMR_CALL_REQUEST_NUMBERS[0]);
    const TagInfo *GSMR_CALL_REQUEST_TAGS = 0;
    const size_t GSMR_CALL_REQUEST_TAGS_SIZE = 0;
    const IdentifierInfo *GSMR_CALL_REQUEST_IDENTIFIERS = 0;
    const size_t GSMR_CALL_REQUEST_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *GSMR_CALL_REQUEST_CONSTANTS = 0;
    const size_t GSMR_CALL_REQUEST_CONSTANTS_SIZE = 0;
    const SpecificationInfo *GSMR_CALL_REQUEST_SPECIFICATIONS = 0;
    const size_t GSMR_CALL_REQUEST_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> GSMR_CALL_REQUEST_RAWS[] =
    {
        Sim::Info<Sim::Raw>("Destination"),
        Sim::Info<Sim::Raw>("Source"),
    };
    const size_t GSMR_CALL_REQUEST_RAWS_SIZE = sizeof(GSMR_CALL_REQUEST_RAWS)/sizeof(GSMR_CALL_REQUEST_RAWS[0]);
    const Sim::Info<Sim::Tray> *GSMR_CALL_REQUEST_TRAYS = 0;
    const size_t GSMR_CALL_REQUEST_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> GSMR_CALL_UPDATE_REQUEST_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 202),
        Sim::Info<Sim::Number>("Instance", 0.5, 0.0),
        Sim::Info<Sim::Number>("GSMR Call ID", 0.5, 0.0),
        Sim::Info<Sim::Number>("Requested Call State", 0.5, 0.0),
        Sim::Info<Sim::Number>("Requesting Client ID", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request State", 0.5, 0.0),
    };
    const size_t GSMR_CALL_UPDATE_REQUEST_NUMBERS_SIZE = sizeof(GSMR_CALL_UPDATE_REQUEST_NUMBERS)/sizeof(GSMR_CALL_UPDATE_REQUEST_NUMBERS[0]);
    const TagInfo *GSMR_CALL_UPDATE_REQUEST_TAGS = 0;
    const size_t GSMR_CALL_UPDATE_REQUEST_TAGS_SIZE = 0;
    const IdentifierInfo *GSMR_CALL_UPDATE_REQUEST_IDENTIFIERS = 0;
    const size_t GSMR_CALL_UPDATE_REQUEST_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *GSMR_CALL_UPDATE_REQUEST_CONSTANTS = 0;
    const size_t GSMR_CALL_UPDATE_REQUEST_CONSTANTS_SIZE = 0;
    const SpecificationInfo *GSMR_CALL_UPDATE_REQUEST_SPECIFICATIONS = 0;
    const size_t GSMR_CALL_UPDATE_REQUEST_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *GSMR_CALL_UPDATE_REQUEST_RAWS = 0;
    const size_t GSMR_CALL_UPDATE_REQUEST_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *GSMR_CALL_UPDATE_REQUEST_TRAYS = 0;
    const size_t GSMR_CALL_UPDATE_REQUEST_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> GSMR_SMS_REQUEST_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 209),
        Sim::Info<Sim::Number>("Instance", 0.5, 0.0),
        Sim::Info<Sim::Number>("Initiator ID", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request State", 0.5, 0.0),
    };
    const size_t GSMR_SMS_REQUEST_NUMBERS_SIZE = sizeof(GSMR_SMS_REQUEST_NUMBERS)/sizeof(GSMR_SMS_REQUEST_NUMBERS[0]);
    const TagInfo *GSMR_SMS_REQUEST_TAGS = 0;
    const size_t GSMR_SMS_REQUEST_TAGS_SIZE = 0;
    const IdentifierInfo *GSMR_SMS_REQUEST_IDENTIFIERS = 0;
    const size_t GSMR_SMS_REQUEST_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *GSMR_SMS_REQUEST_CONSTANTS = 0;
    const size_t GSMR_SMS_REQUEST_CONSTANTS_SIZE = 0;
    const SpecificationInfo *GSMR_SMS_REQUEST_SPECIFICATIONS = 0;
    const size_t GSMR_SMS_REQUEST_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> GSMR_SMS_REQUEST_RAWS[] =
    {
        Sim::Info<Sim::Raw>("Content"),
        Sim::Info<Sim::Raw>("Source"),
        Sim::Info<Sim::Raw>("Destination"),
    };
    const size_t GSMR_SMS_REQUEST_RAWS_SIZE = sizeof(GSMR_SMS_REQUEST_RAWS)/sizeof(GSMR_SMS_REQUEST_RAWS[0]);
    const Sim::Info<Sim::Tray> *GSMR_SMS_REQUEST_TRAYS = 0;
    const size_t GSMR_SMS_REQUEST_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> GSMR_CLIENT_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 206),
        Sim::Info<Sim::Number>("Instance", 0.5, 0.0),
        Sim::Info<Sim::Number>("Active Call ID", 0.5, 0.0),
        Sim::Info<Sim::Number>("Client Is Ready", 0.5, 0.0),
        Sim::Info<Sim::Number>("Client State", 0.5, 0.0),
        Sim::Info<Sim::Number>("Connected Microphone", 0.5, 0.0),
        Sim::Info<Sim::Number>("Connected Speaker", 0.5, 0.0),
        Sim::Info<Sim::Number>("Connection State", 0.5, 0.0),
        Sim::Info<Sim::Number>("Default Client", 0.5, 0.0),
        Sim::Info<Sim::Number>("Hub", 0.5, 0.0),
        Sim::Info<Sim::Number>("PTT State", 0.5, 0.0),
        Sim::Info<Sim::Number>("Registered On Network", 0.5, 0.0),
        Sim::Info<Sim::Number>("Role UID", 0.5, 0.0),
        Sim::Info<Sim::Number>("Type", 0.5, 0.0),
    };
    const size_t GSMR_CLIENT_NUMBERS_SIZE = sizeof(GSMR_CLIENT_NUMBERS)/sizeof(GSMR_CLIENT_NUMBERS[0]);
    const TagInfo *GSMR_CLIENT_TAGS = 0;
    const size_t GSMR_CLIENT_TAGS_SIZE = 0;
    const IdentifierInfo *GSMR_CLIENT_IDENTIFIERS = 0;
    const size_t GSMR_CLIENT_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *GSMR_CLIENT_CONSTANTS = 0;
    const size_t GSMR_CLIENT_CONSTANTS_SIZE = 0;
    const SpecificationInfo *GSMR_CLIENT_SPECIFICATIONS = 0;
    const size_t GSMR_CLIENT_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> GSMR_CLIENT_RAWS[] =
    {
        Sim::Info<Sim::Raw>("Call List"),
        Sim::Info<Sim::Raw>("Name"),
        Sim::Info<Sim::Raw>("PSTN Number"),
    };
    const size_t GSMR_CLIENT_RAWS_SIZE = sizeof(GSMR_CLIENT_RAWS)/sizeof(GSMR_CLIENT_RAWS[0]);
    const Sim::Info<Sim::Tray> GSMR_CLIENT_TRAYS[] =
    {
        Sim::Info<Sim::Tray>("SMS List"),
    };
    const size_t GSMR_CLIENT_TRAYS_SIZE = sizeof(GSMR_CLIENT_TRAYS)/sizeof(GSMR_CLIENT_TRAYS[0]);
    const Sim::Info<Sim::Number> GSMR_NETWORK_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 207),
    };
    const size_t GSMR_NETWORK_NUMBERS_SIZE = sizeof(GSMR_NETWORK_NUMBERS)/sizeof(GSMR_NETWORK_NUMBERS[0]);
    const TagInfo *GSMR_NETWORK_TAGS = 0;
    const size_t GSMR_NETWORK_TAGS_SIZE = 0;
    const IdentifierInfo *GSMR_NETWORK_IDENTIFIERS = 0;
    const size_t GSMR_NETWORK_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *GSMR_NETWORK_CONSTANTS = 0;
    const size_t GSMR_NETWORK_CONSTANTS_SIZE = 0;
    const SpecificationInfo *GSMR_NETWORK_SPECIFICATIONS = 0;
    const size_t GSMR_NETWORK_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *GSMR_NETWORK_RAWS = 0;
    const size_t GSMR_NETWORK_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *GSMR_NETWORK_TRAYS = 0;
    const size_t GSMR_NETWORK_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> REFERENCE_TRAIN_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 1001),
        Sim::Info<Sim::Number>("Speed", 0.1, -1),
    };
    const size_t REFERENCE_TRAIN_NUMBERS_SIZE = sizeof(REFERENCE_TRAIN_NUMBERS)/sizeof(REFERENCE_TRAIN_NUMBERS[0]);
    const TagInfo *REFERENCE_TRAIN_TAGS = 0;
    const size_t REFERENCE_TRAIN_TAGS_SIZE = 0;
    const IdentifierInfo *REFERENCE_TRAIN_IDENTIFIERS = 0;
    const size_t REFERENCE_TRAIN_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *REFERENCE_TRAIN_CONSTANTS = 0;
    const size_t REFERENCE_TRAIN_CONSTANTS_SIZE = 0;
    const SpecificationInfo *REFERENCE_TRAIN_SPECIFICATIONS = 0;
    const size_t REFERENCE_TRAIN_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *REFERENCE_TRAIN_RAWS = 0;
    const size_t REFERENCE_TRAIN_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *REFERENCE_TRAIN_TRAYS = 0;
    const size_t REFERENCE_TRAIN_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> IDU_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 401),
    };
    const size_t IDU_NUMBERS_SIZE = sizeof(IDU_NUMBERS)/sizeof(IDU_NUMBERS[0]);
    const TagInfo *IDU_TAGS = 0;
    const size_t IDU_TAGS_SIZE = 0;
    const IdentifierInfo *IDU_IDENTIFIERS = 0;
    const size_t IDU_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *IDU_CONSTANTS = 0;
    const size_t IDU_CONSTANTS_SIZE = 0;
    const SpecificationInfo *IDU_SPECIFICATIONS = 0;
    const size_t IDU_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *IDU_RAWS = 0;
    const size_t IDU_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *IDU_TRAYS = 0;
    const size_t IDU_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> IDU_OUTPUTS_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 402),
        Sim::Info<Sim::Number>("Class Outputs", 0.5, 0.0),
        Sim::Info<Sim::Number>("Class Outputs", 0.5, 0.0),
        Sim::Info<Sim::Number>("Next Station Skipped", 0.5, 0.0),
        Sim::Info<Sim::Number>("Trip Running Status", 0.5, 0.0),
        Sim::Info<Sim::Number>("Screen ID", 0.5, 0.0),
        Sim::Info<Sim::Number>("Current Screen - Selected Vehicle", 0.5, 0.0),
        Sim::Info<Sim::Number>("Train Speed Above 1 Kph", 0.5, 0.0),
        Sim::Info<Sim::Number>("Train At Station", 0.5, 0.0),
        Sim::Info<Sim::Number>("At Station Status Station Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Safety System Status", 0.5, 0.0),
        Sim::Info<Sim::Number>("Front Pantograph Status", 0.5, 0.0),
        Sim::Info<Sim::Number>("Rear Pantograph Status", 0.5, 0.0),
        Sim::Info<Sim::Number>("Stopped Indicator", 0.5, -1),
        Sim::Info<Sim::Number>("Inhibit Indicator", 0.5, 0.0),
        Sim::Info<Sim::Number>("Left Head Light Indicator", 0.5, 0.0),
        Sim::Info<Sim::Number>("Left Marker Light Indicator", 0.5, 0.0),
        Sim::Info<Sim::Number>("Left Tail Light Indicator", 0.5, 0.0),
        Sim::Info<Sim::Number>("Right Head Light Indicator", 0.5, 0.0),
        Sim::Info<Sim::Number>("Right Marker Light Indicator", 0.5, 0.0),
        Sim::Info<Sim::Number>("Right Tail Light Indicator", 0.5, 0.0),
        Sim::Info<Sim::Number>("DOO Right View Already Displayed", 0.5, 0.0),
        Sim::Info<Sim::Number>("DOO Left View Already Displayed", 0.5, 0.0),
        Sim::Info<Sim::Number>("Clear Train On", 0.5, 0.0),
        Sim::Info<Sim::Number>("DOO View State", 0.5, 0.0),
        Sim::Info<Sim::Number>("OTMR Health Status", 0.5, 1.0),
        Sim::Info<Sim::Number>("Obstruction Flash State", 0.5, 0.0),
        Sim::Info<Sim::Number>("Event List Start Index", 0.5, 0.0),
        Sim::Info<Sim::Number>("Event List Selected Record", 0.5, 0.0),
        Sim::Info<Sim::Number>("Continue Event", 0.5, 0.0),
        Sim::Info<Sim::Number>("Active Event Present", 0.5, 0.0),
        Sim::Info<Sim::Number>("Event List Previous Button Status", 0.5, 0.0),
        Sim::Info<Sim::Number>("Event List Next Button Status", 0.5, 0.0),
        Sim::Info<Sim::Number>("Event List Previous Page Button Status", 0.5, 0.0),
        Sim::Info<Sim::Number>("Event List Next Page Button Status", 0.5, 0.0),
        Sim::Info<Sim::Number>("TBC Percentage", 0.5, 0.0),
        Sim::Info<Sim::Number>("Demist off", 0.5, 0.0),
        Sim::Info<Sim::Number>("Close Dumpers", 0.5, 0.0),
        Sim::Info<Sim::Number>("Line Current Limit", 0.5, 0.0),
        Sim::Info<Sim::Number>("Restrict Mode", 0.5, 0.0),
        Sim::Info<Sim::Number>("Depot Speed Set", 0.5, 0.0),
        Sim::Info<Sim::Number>("Wash AVIS", 0.5, 0.0),
        Sim::Info<Sim::Number>("Inhibit Regen", 0.5, 0.0),
        Sim::Info<Sim::Number>("Mute PIS", 0.5, 0.0),
        Sim::Info<Sim::Number>("Disable PIS", 0.5, 0.0),
        Sim::Info<Sim::Number>("Vehicle Over Run", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Pop-up State", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon Lights State", 0.5, 1.0),
        Sim::Info<Sim::Number>("Defect List Start Index", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect List Selected Index", 0.5, 0.0),
        Sim::Info<Sim::Number>("Message List Start Index", 0.5, 0.0),
        Sim::Info<Sim::Number>("Message Type", 0.5, 0.0),
        Sim::Info<Sim::Number>("Message To Be Played", 0.5, 0.0),
        Sim::Info<Sim::Number>("Inhibit Door Screen Pop-up State", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Inhibited Front Half", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Inhibited Rear Half", 0.5, 0.0),
        Sim::Info<Sim::Number>("Gangway Door Location", 0.5, 0.0),
        Sim::Info<Sim::Number>("Inhibit Doors Screen Selected Vehicle", 0.5, -1),
        Sim::Info<Sim::Number>("Start Seq Camera State", 0.5, 0.0),
        Sim::Info<Sim::Number>("Camera Popup State", 0.5, 0.0),
        Sim::Info<Sim::Number>("Selected Camera Index", 0.5, 0.0),
        Sim::Info<Sim::Number>("Camera Popup Selected Camera Index", 0.5, 0.0),
        Sim::Info<Sim::Number>("Expanded View Event Type", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon Screen Selected Car Index", 0.5, -1),
        Sim::Info<Sim::Number>("Simple Selected Car Index", 0.5, -1),
        Sim::Info<Sim::Number>("Camera Area To Show", 0.5, 0.0),
        Sim::Info<Sim::Number>("Expanded View State", 0.5, 0.0),
        Sim::Info<Sim::Number>("Flash State", 0.5, 0.0),
        Sim::Info<Sim::Number>("DMI Login Status", 0.5, 0.0),
        Sim::Info<Sim::Number>("Station List Selected Index", 0.5, 0.0),
        Sim::Info<Sim::Number>("Station List Up Button Status", 0.5, 0.0),
        Sim::Info<Sim::Number>("Station List Down Button Status", 0.5, 0.0),
        Sim::Info<Sim::Number>("Outside CCTV Type", 0.5, 0.0),
        Sim::Info<Sim::Number>("Outside CCTV Screen Selected Car Index", 0.5, -1),
        Sim::Info<Sim::Number>("Defect Selected Fault Area", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Select Cars Whole Train Status", 0.5, 0.0),
        Sim::Info<Sim::Number>("Keypad Type", 0.5, 0.0),
        Sim::Info<Sim::Number>("Smoke Alarm Being Reset", 0.5, 0.0),
        Sim::Info<Sim::Number>("SIG Redundancy Screen Swap", 0.5, 0.0),
        Sim::Info<Sim::Number>("SIG Redundancy Active Screen", 0.5, 0.0),
        Sim::Info<Sim::Number>("DMI Screen Button State", 0.5, 0.0),
        Sim::Info<Sim::Number>("Switch Screen Button State", 0.5, 0.0),
    };
    const size_t IDU_OUTPUTS_NUMBERS_SIZE = sizeof(IDU_OUTPUTS_NUMBERS)/sizeof(IDU_OUTPUTS_NUMBERS[0]);
    const TagInfo *IDU_OUTPUTS_TAGS = 0;
    const size_t IDU_OUTPUTS_TAGS_SIZE = 0;
    const IdentifierInfo *IDU_OUTPUTS_IDENTIFIERS = 0;
    const size_t IDU_OUTPUTS_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *IDU_OUTPUTS_CONSTANTS = 0;
    const size_t IDU_OUTPUTS_CONSTANTS_SIZE = 0;
    const SpecificationInfo *IDU_OUTPUTS_SPECIFICATIONS = 0;
    const size_t IDU_OUTPUTS_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> IDU_OUTPUTS_RAWS[] =
    {
        Sim::Info<Sim::Raw>("Train Configuration Data"),
        Sim::Info<Sim::Raw>("Line Voltage"),
        Sim::Info<Sim::Raw>("Destination Station"),
        Sim::Info<Sim::Raw>("Next Station"),
        Sim::Info<Sim::Raw>("Door A Status"),
        Sim::Info<Sim::Raw>("Door B Status"),
        Sim::Info<Sim::Raw>("Door C Status"),
        Sim::Info<Sim::Raw>("Door D Status"),
        Sim::Info<Sim::Raw>("Door E Status"),
        Sim::Info<Sim::Raw>("Door F Status"),
        Sim::Info<Sim::Raw>("Door Cab A Status"),
        Sim::Info<Sim::Raw>("Door Cab B Status"),
        Sim::Info<Sim::Raw>("Door Door to Saloon Status"),
        Sim::Info<Sim::Raw>("Front Vehicle Light Status"),
        Sim::Info<Sim::Raw>("Rear Vehicle Light Status"),
        Sim::Info<Sim::Raw>("Door A Inhibited Status"),
        Sim::Info<Sim::Raw>("Door B Inhibited Status"),
        Sim::Info<Sim::Raw>("Door C Inhibited Status"),
        Sim::Info<Sim::Raw>("Door D Inhibited Status"),
        Sim::Info<Sim::Raw>("Door E Inhibited Status"),
        Sim::Info<Sim::Raw>("Door F Inhibited Status"),
        Sim::Info<Sim::Raw>("Active Event List"),
        Sim::Info<Sim::Raw>("Driver Active Event List"),
        Sim::Info<Sim::Raw>("Unacknowledged Cat A Event List"),
        Sim::Info<Sim::Raw>("Unacknowledged Cat B Event List"),
        Sim::Info<Sim::Raw>("Unacknowledged Event "),
        Sim::Info<Sim::Raw>("PEA State"),
        Sim::Info<Sim::Raw>("CFA State"),
        Sim::Info<Sim::Raw>("Door Egress State"),
        Sim::Info<Sim::Raw>("Door Interlock Lost State"),
        Sim::Info<Sim::Raw>("Smoke State"),
        Sim::Info<Sim::Raw>("Train Certificate Valid Until"),
        Sim::Info<Sim::Raw>("Station List"),
        Sim::Info<Sim::Raw>("Defect Log List"),
        Sim::Info<Sim::Raw>("Defect Screen New Defect"),
        Sim::Info<Sim::Raw>("Defect Selected Cars"),
        Sim::Info<Sim::Raw>("Additional Defect Information"),
        Sim::Info<Sim::Raw>("Current Active Event For Redundancy Mode"),
    };
    const size_t IDU_OUTPUTS_RAWS_SIZE = sizeof(IDU_OUTPUTS_RAWS)/sizeof(IDU_OUTPUTS_RAWS[0]);
    const Sim::Info<Sim::Tray> *IDU_OUTPUTS_TRAYS = 0;
    const size_t IDU_OUTPUTS_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> IDU_INPUTS_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 403),
        Sim::Info<Sim::Number>("Class Inputs", 0.5, 0.0),
        Sim::Info<Sim::Number>("Class Inputs", 0.5, 0.0),
        Sim::Info<Sim::Number>("Active Events - Acknowledge Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Active Events - Present Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Acknowledge Event", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Screen Change", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Dark Screen", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Remove Dark Screen", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Skip Station", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request MSG List Next Page", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request MSG List Prev Page", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request MSG List Selected Id", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Open Doors", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Platform CCTV Left View", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Platform CCTV Right View", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Clear Train", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request DOO East Bound View", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request DOO West Bound View", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Toggle Demist", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Toggle Close Dampers", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Event List Next Page", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Event List Prev Page", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Event List Next Record", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Event List Prev Record", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Event List Selected Record", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Restrict Mode", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Depot Speed Set", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Wash_AVIS", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Inhibit Regen", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Mute PIS", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Disable PIS", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Vehicle Over_Run", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Switch Screen", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Toggle Saloon Lights", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Defect List Next Page", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Defect List Prev Page", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Defect List Selected Index", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Priority Message", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Manual Message", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Forward Facing", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Pantograph", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Inhibit Door A", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Inhibit Door B", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Inhibit Door C", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Inhibit Door D", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Inhibit Door E", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Inhibit Door F", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Inhibit Door Front Half", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Inhibit Door Rear Half", 0.5, 0.0),
        Sim::Info<Sim::Number>("Inhibit Doors Screen Selected Vehicle", 0.5, -1),
        Sim::Info<Sim::Number>("Request Start Sequence Camera", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Select Camera", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Camera 1 Selected", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Camera 2 Selected", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Camera 3 Selected", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Camera 4 Selected", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Saloon CCTV", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request PEA Event", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request CFA Event", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon Screen Selected Car Index", 0.5, -1),
        Sim::Info<Sim::Number>("Request Saloon CCTV Driving or Station Button Pressed", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Saloon CCTV To Main Menu Screen", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Expanded View State", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Select PEA1", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Select PEA2", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Select PEA3", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Select CFA1", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Select CFA2", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Select CFA3", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Select CFA4", 0.5, 0.0),
        Sim::Info<Sim::Number>("Add Station Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Station List Up Arrow Pressed", 0.5, 0.0),
        Sim::Info<Sim::Number>("Station List Down Arrow Pressed", 0.5, 0.0),
        Sim::Info<Sim::Number>("Station List Selected Index", 0.5, 0.0),
        Sim::Info<Sim::Number>("Skip Station Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Selected Fault Area Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Select Cars Whole Train Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Select Cars Next Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Select Equipment Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Screen Select Defect Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Keypad Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Keypad Type Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Review Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect New Confirm Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("View Certificate Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("View Certificate Screen - Control Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("View Certificate Screen - Station Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("View Certificate Screen - Active Events Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Select Fault Area Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Select Fault Area Screen - Control Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Select Fault Area Screen - Station Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Select Fault Area Screen - Back Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Select Fault Area Screen - Cab Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Select Fault Area Screen - Saloon Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Select Fault Area Screen - Exterior Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Select Fault Area Screen - Unit Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Station Screen - OpenButton", 0.5, 0.0),
        Sim::Info<Sim::Number>("Station Screen - left View Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Station Screen - Right View Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Station Screen - Clear Train Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Station Screen - Active Event Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Station Screen - Skip Station Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Station Screen - DrivingPanel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Station Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Station Screen - Control Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Station Screen - DMI Screen Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Power Down Screen - Power Down Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("View Defect Screen - Open Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("View Defect Screen - Up Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("View Defect Screen - Down Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("View Defect Screen - Log Defect Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("View Defect Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("View Defect Screen - Control Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("View Defect Screen - Station Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Screen - Inhibit Regen.Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Screen - Close Dampers Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Screen - Mute PIS Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Screen - Demist Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Screen - Switch Screen Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Screen - Lights Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Screen - Disable PIS Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Screen - Vehicle overrun Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Screen - Restrict Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Screen - Deport Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Screen - Wash AVIS Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Screen - Skip Station Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Screen - DrivingPanel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Screen - Active Event Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Confirmation Screen - Active Event Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Confirmation Screen - Skip Station Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Confirmation Screen - Driving Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Confirmation Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Confirmation Screen - Cancel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Confirmation Screen - Confirm Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Confirmation Screen - Cancel Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Confirmation Screen - Confirm Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Add Stations Screen - Active Events Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Add Stations Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Add Stations Screen - Control Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Add Stations Screen - Station Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Add Stations Screen - Up Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Add Stations Screen - Down Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Add Stations Screen - Add Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Inhibit Doors Screen - Active Events Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Inhibit Doors Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Inhibit Doors Screen - Control Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Inhibit Doors Screen - Skip Station Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Inhibit Doors Screen - Rear Half Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Inhibit Doors Screen - Front Half Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Inhibit Doors Screen - Inhibit Door A Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Inhibit Doors Screen - Inhibit Door B Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Inhibit Doors Screen - Inhibit Door C Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Inhibit Doors Screen - Inhibit Door D Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Inhibit Doors Screen - Inhibit Door E Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Inhibit Doors Screen - Inhibit Door F Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Menu Screen - View Cert.Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Menu Screen - Defect Log Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Menu Screen - Saloon Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Menu Screen - Forward Facing Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Menu Screen - Panto graph Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Menu Screen - CCTV Playback Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Menu Screen - Inhibit Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Menu Screen - Priority Msg.Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Menu Screen - Manual Msg.Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Menu Screen - Add Station Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Menu Screen - Skip Station Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Menu Screen - Driving Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Menu Screen - Control Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Menu Screen - Active Event Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Menu Screen - Alarm Reset Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Message Screen Screen - Active Events Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Message Screen Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Message Screen Screen - Control Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Message Screen Screen - Station Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Message Screen Screen - Play Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Message Screen Screen - Up Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Message Screen Screen - Down Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Outside CCTV Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Outside CCTV Screen - Station Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Outside CCTV Screen - Active Events Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Outside CCTV Screen - Select Camera Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Outside CCTV Screen - Start Seq Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Outside CCTV Screen - Selected Car Index", 0.5, -1),
        Sim::Info<Sim::Number>("Extended Event Screen - Back Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Extended Event Screen - Station Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Extended Event Screen - Control Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Extended Event Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Extended Event Screen - Selected Vehicle", 0.5, 0.0),
        Sim::Info<Sim::Number>("Active Event List Screen - DoubleUp Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Active Event List Screen - DoubleDown Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Active Event List Screen - Up Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Active Event List Screen - Down Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Active Event List Screen - Open Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Active Event List Screen - Station Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Active Event List Screen - Control Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Active Event List Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Active Event List Screen - Selected Vehicle", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driver Screen - Station Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driver Screen - Control Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driver Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driver Screen - Event Marker Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driver Screen - Demist Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driver Screen - Close Dampers Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driver Screen - Skip Station Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driver Screen - DMI Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driver Screen - Ack Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driver Screen - CCTV Event Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request DMI Screen", 0.5, 0.0),
        Sim::Info<Sim::Number>("Extended Defect Screen - Back Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Extended Defect Screen - Station Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Extended Defect Screen - Control Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Extended Defect Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Extended Defect Screen - ActiveEvents Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("DOO Confirmation Screen - Cancel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("DOO Confirmation Screen - West Bound Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("DOO Confirmation Screen - East Bound Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("DOO Confirmation Screen - Driving Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("DOO Confirmation Screen - Control Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("DOO Confirmation Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("DOO Confirmation Screen - DMI Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("DOO Confirmation Screen - Active Events Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("DOO Confirmation Screen - Skip Station Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("DOO Confirmation Screen - Cancel Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - Back Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - Station Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - Control Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - ActiveEvents Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - CCTV Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - Doors Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - HVAC Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - Glazing Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - PIS Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - Lighting Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - Access Panels Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - Floor Trim Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - Seats Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - Desk Controls Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - HMI Controls Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - TBC MCS Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - Wash Wipe Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - Radio Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - Handset Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - Other Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - Roof Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - Under Frame Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - Brakes Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - Traction Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - Wheels Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - DOO Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - Back Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - Station Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - Control Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - ActiveEvents Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - Drafts Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - Dirty Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - Dust Ingress Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - Too Cold Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - Noisy Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - Water Ingress Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - Too Hot Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - Smell Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - Graffiti Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - Damage Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - Loose Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - Faulty Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - Stiff Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - Wrong Position Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - Poor Perform Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - Rough Riding Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Select Cars Screen - Next Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Select Cars Screen - Back Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Select Cars Screen - Station Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Select Cars Screen - Control Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Select Cars Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Select Cars Screen - Selected Vehicle", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Select Cars Screen - Whole Train Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon CCTV Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon CCTV Screen - Station Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon CCTV Screen - Active Events Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon CCTV Screen - Select Camera Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon CCTV Screen - Select Alarm Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon CCTV Screen - Start Seq Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon CCTV Screen - Camera 1 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon CCTV Screen - Camera 2 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon CCTV Screen - Camera 3 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon CCTV Screen - Camera 4 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon CCTV Screen - PEA Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon CCTV Screen - CFA Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon CCTV Screen - PEA1 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon CCTV Screen - PEA2 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon CCTV Screen - PEA3 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon CCTV Screen - CFA1 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon CCTV Screen - CFA2 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon CCTV Screen - CFA3 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon CCTV Screen - CFA4 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driving Saloon CCTV Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driving Saloon CCTV Screen - Station Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driving Saloon CCTV Screen - Active Events Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driving Saloon CCTV Screen - Select Camera Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driving Saloon CCTV Screen - Start Seq Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driving Saloon CCTV Screen - Camera 1 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driving Saloon CCTV Screen - Camera 2 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driving Saloon CCTV Screen - Camera 3 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driving Saloon CCTV Screen - Camera 4 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driving Saloon CCTV Screen - PEA Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driving Saloon CCTV Screen - CFA Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Review Defect Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Back Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Station Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Control Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Zero Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - One Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Two Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Three Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Four Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Five Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Six Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Seven Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Eight Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Nine Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - A Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - B Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - C Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - D Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - E Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - F Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - G Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - H Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - I Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - J Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - K Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - L Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - M Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - N Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - O Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - P Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Q Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - R Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - S Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - T Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - U Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - V Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - W Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - X Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Y Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Z Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Dot Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Del Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Numric Key Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Space Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Alphanumeric Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Confirmation Screen - Back Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Confirmation Screen - Selected Vehicle", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Confirmation Screen - Defect Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Smoke Alarm reset Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Smoke Alarm reset Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Smoke Alarm reset Screen - Active Events Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Smoke Alarm reset Screen - Station Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Smoke Alarm reset Screen - Control Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Smoke Alarm reset Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Smoke Alarm reset Screen - CCTC Event Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Smoke Alarm reset Cancel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Smoke Alarm reset Confirm Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Smoke Alarm reset Cancel Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Smoke Alarm reset Confirm Request", 0.5, 0.0),
    };
    const size_t IDU_INPUTS_NUMBERS_SIZE = sizeof(IDU_INPUTS_NUMBERS)/sizeof(IDU_INPUTS_NUMBERS[0]);
    const TagInfo *IDU_INPUTS_TAGS = 0;
    const size_t IDU_INPUTS_TAGS_SIZE = 0;
    const IdentifierInfo *IDU_INPUTS_IDENTIFIERS = 0;
    const size_t IDU_INPUTS_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *IDU_INPUTS_CONSTANTS = 0;
    const size_t IDU_INPUTS_CONSTANTS_SIZE = 0;
    const SpecificationInfo *IDU_INPUTS_SPECIFICATIONS = 0;
    const size_t IDU_INPUTS_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *IDU_INPUTS_RAWS = 0;
    const size_t IDU_INPUTS_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *IDU_INPUTS_TRAYS = 0;
    const size_t IDU_INPUTS_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> IDU_INPUTS_VALUES_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 404),
        Sim::Info<Sim::Number>("Class Values", 0.5, 0.0),
        Sim::Info<Sim::Number>("Class Values", 0.5, 0.0),
        Sim::Info<Sim::Number>("Active Events - Acknowledge Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Active Events - Present Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Acknowledge Event", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Screen Change", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Dark Screen", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Remove Dark Screen", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Skip Station", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request MSG List Next Page", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request MSG List Prev Page", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request MSG List Selected Id", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Open Doors", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Platform CCTV Left View", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Platform CCTV Right View", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Clear Train", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request DOO East Bound View", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request DOO West Bound View", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Toggle Demist", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Toggle Close Dampers", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Event List Next Page", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Event List Prev Page", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Event List Next Record", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Event List Prev Record", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Event List Selected Record", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Restrict Mode", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Depot Speed Set", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Wash_AVIS", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Inhibit Regen", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Mute PIS", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Disable PIS", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Vehicle Over_Run", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Switch Screen", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Toggle Saloon Lights", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Defect List Next Page", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Defect List Prev Page", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Defect List Selected Index", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Priority Message", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Manual Message", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Forward Facing", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Pantograph", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Inhibit Door A", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Inhibit Door B", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Inhibit Door C", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Inhibit Door D", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Inhibit Door E", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Inhibit Door F", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Inhibit Door Front Half", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Inhibit Door Rear Half", 0.5, 0.0),
        Sim::Info<Sim::Number>("Inhibit Doors Screen Selected Vehicle", 0.5, -1),
        Sim::Info<Sim::Number>("Request Start Sequence Camera", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Select Camera", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Camera 1 Selected", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Camera 2 Selected", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Camera 3 Selected", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Camera 4 Selected", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Saloon CCTV", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request PEA Event", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request CFA Event", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon Screen Selected Car Index", 0.5, -1),
        Sim::Info<Sim::Number>("Request Saloon CCTV Driving or Station Button Pressed", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Saloon CCTV To Main Menu Screen", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Expanded View State", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Select PEA1", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Select PEA2", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Select PEA3", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Select CFA1", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Select CFA2", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Select CFA3", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Select CFA4", 0.5, 0.0),
        Sim::Info<Sim::Number>("Add Station Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Station List Up Arrow Pressed", 0.5, 0.0),
        Sim::Info<Sim::Number>("Station List Down Arrow Pressed", 0.5, 0.0),
        Sim::Info<Sim::Number>("Station List Selected Index", 0.5, 0.0),
        Sim::Info<Sim::Number>("Skip Station Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Selected Fault Area Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Select Cars Whole Train Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Select Cars Next Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Select Equipment Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Screen Select Defect Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Keypad Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Keypad Type Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Review Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect New Confirm Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("View Certificate Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("View Certificate Screen - Control Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("View Certificate Screen - Station Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("View Certificate Screen - Active Events Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Select Fault Area Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Select Fault Area Screen - Control Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Select Fault Area Screen - Station Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Select Fault Area Screen - Back Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Select Fault Area Screen - Cab Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Select Fault Area Screen - Saloon Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Select Fault Area Screen - Exterior Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Select Fault Area Screen - Unit Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Station Screen - OpenButton", 0.5, 0.0),
        Sim::Info<Sim::Number>("Station Screen - left View Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Station Screen - Right View Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Station Screen - Clear Train Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Station Screen - Active Event Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Station Screen - Skip Station Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Station Screen - DrivingPanel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Station Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Station Screen - Control Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Station Screen - DMI Screen Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Power Down Screen - Power Down Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("View Defect Screen - Open Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("View Defect Screen - Up Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("View Defect Screen - Down Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("View Defect Screen - Log Defect Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("View Defect Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("View Defect Screen - Control Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("View Defect Screen - Station Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Screen - Inhibit Regen.Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Screen - Close Dampers Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Screen - Mute PIS Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Screen - Demist Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Screen - Switch Screen Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Screen - Lights Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Screen - Disable PIS Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Screen - Vehicle overrun Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Screen - Restrict Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Screen - Deport Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Screen - Wash AVIS Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Screen - Skip Station Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Screen - DrivingPanel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Screen - Active Event Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Confirmation Screen - Active Event Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Confirmation Screen - Skip Station Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Confirmation Screen - Driving Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Confirmation Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Confirmation Screen - Cancel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Confirmation Screen - Confirm Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Confirmation Screen - Cancel Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Confirmation Screen - Confirm Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Add Stations Screen - Active Events Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Add Stations Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Add Stations Screen - Control Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Add Stations Screen - Station Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Add Stations Screen - Up Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Add Stations Screen - Down Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Add Stations Screen - Add Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Inhibit Doors Screen - Active Events Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Inhibit Doors Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Inhibit Doors Screen - Control Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Inhibit Doors Screen - Skip Station Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Inhibit Doors Screen - Rear Half Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Inhibit Doors Screen - Front Half Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Inhibit Doors Screen - Inhibit Door A Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Inhibit Doors Screen - Inhibit Door B Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Inhibit Doors Screen - Inhibit Door C Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Inhibit Doors Screen - Inhibit Door D Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Inhibit Doors Screen - Inhibit Door E Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Inhibit Doors Screen - Inhibit Door F Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Menu Screen - View Cert.Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Menu Screen - Defect Log Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Menu Screen - Saloon Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Menu Screen - Forward Facing Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Menu Screen - Panto graph Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Menu Screen - CCTV Playback Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Menu Screen - Inhibit Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Menu Screen - Priority Msg.Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Menu Screen - Manual Msg.Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Menu Screen - Add Station Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Menu Screen - Skip Station Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Menu Screen - Driving Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Menu Screen - Control Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Menu Screen - Active Event Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Menu Screen - Alarm Reset Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Message Screen Screen - Active Events Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Message Screen Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Message Screen Screen - Control Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Message Screen Screen - Station Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Message Screen Screen - Play Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Message Screen Screen - Up Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Message Screen Screen - Down Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Outside CCTV Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Outside CCTV Screen - Station Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Outside CCTV Screen - Active Events Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Outside CCTV Screen - Select Camera Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Outside CCTV Screen - Start Seq Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Outside CCTV Screen - Selected Car Index", 0.5, -1),
        Sim::Info<Sim::Number>("Extended Event Screen - Back Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Extended Event Screen - Station Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Extended Event Screen - Control Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Extended Event Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Extended Event Screen - Selected Vehicle", 0.5, 0.0),
        Sim::Info<Sim::Number>("Active Event List Screen - DoubleUp Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Active Event List Screen - DoubleDown Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Active Event List Screen - Up Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Active Event List Screen - Down Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Active Event List Screen - Open Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Active Event List Screen - Station Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Active Event List Screen - Control Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Active Event List Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Active Event List Screen - Selected Vehicle", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driver Screen - Station Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driver Screen - Control Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driver Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driver Screen - Event Marker Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driver Screen - Demist Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driver Screen - Close Dampers Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driver Screen - Skip Station Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driver Screen - DMI Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driver Screen - Ack Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driver Screen - CCTV Event Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request DMI Screen", 0.5, 0.0),
        Sim::Info<Sim::Number>("Extended Defect Screen - Back Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Extended Defect Screen - Station Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Extended Defect Screen - Control Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Extended Defect Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Extended Defect Screen - ActiveEvents Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("DOO Confirmation Screen - Cancel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("DOO Confirmation Screen - West Bound Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("DOO Confirmation Screen - East Bound Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("DOO Confirmation Screen - Driving Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("DOO Confirmation Screen - Control Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("DOO Confirmation Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("DOO Confirmation Screen - DMI Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("DOO Confirmation Screen - Active Events Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("DOO Confirmation Screen - Skip Station Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("DOO Confirmation Screen - Cancel Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - Back Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - Station Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - Control Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - ActiveEvents Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - CCTV Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - Doors Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - HVAC Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - Glazing Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - PIS Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - Lighting Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - Access Panels Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - Floor Trim Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - Seats Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - Desk Controls Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - HMI Controls Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - TBC MCS Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - Wash Wipe Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - Radio Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - Handset Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - Other Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - Roof Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - Under Frame Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - Brakes Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - Traction Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - Wheels Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - DOO Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - Back Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - Station Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - Control Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - ActiveEvents Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - Drafts Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - Dirty Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - Dust Ingress Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - Too Cold Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - Noisy Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - Water Ingress Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - Too Hot Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - Smell Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - Graffiti Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - Damage Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - Loose Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - Faulty Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - Stiff Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - Wrong Position Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - Poor Perform Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - Rough Riding Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Select Cars Screen - Next Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Select Cars Screen - Back Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Select Cars Screen - Station Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Select Cars Screen - Control Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Select Cars Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Select Cars Screen - Selected Vehicle", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Select Cars Screen - Whole Train Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon CCTV Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon CCTV Screen - Station Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon CCTV Screen - Active Events Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon CCTV Screen - Select Camera Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon CCTV Screen - Select Alarm Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon CCTV Screen - Start Seq Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon CCTV Screen - Camera 1 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon CCTV Screen - Camera 2 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon CCTV Screen - Camera 3 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon CCTV Screen - Camera 4 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon CCTV Screen - PEA Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon CCTV Screen - CFA Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon CCTV Screen - PEA1 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon CCTV Screen - PEA2 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon CCTV Screen - PEA3 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon CCTV Screen - CFA1 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon CCTV Screen - CFA2 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon CCTV Screen - CFA3 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon CCTV Screen - CFA4 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driving Saloon CCTV Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driving Saloon CCTV Screen - Station Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driving Saloon CCTV Screen - Active Events Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driving Saloon CCTV Screen - Select Camera Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driving Saloon CCTV Screen - Start Seq Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driving Saloon CCTV Screen - Camera 1 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driving Saloon CCTV Screen - Camera 2 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driving Saloon CCTV Screen - Camera 3 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driving Saloon CCTV Screen - Camera 4 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driving Saloon CCTV Screen - PEA Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driving Saloon CCTV Screen - CFA Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Review Defect Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Back Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Station Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Control Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Zero Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - One Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Two Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Three Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Four Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Five Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Six Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Seven Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Eight Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Nine Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - A Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - B Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - C Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - D Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - E Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - F Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - G Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - H Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - I Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - J Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - K Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - L Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - M Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - N Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - O Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - P Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Q Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - R Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - S Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - T Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - U Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - V Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - W Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - X Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Y Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Z Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Dot Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Del Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Numric Key Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Space Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Alphanumeric Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Confirmation Screen - Back Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Confirmation Screen - Selected Vehicle", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Confirmation Screen - Defect Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Smoke Alarm reset Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Smoke Alarm reset Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Smoke Alarm reset Screen - Active Events Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Smoke Alarm reset Screen - Station Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Smoke Alarm reset Screen - Control Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Smoke Alarm reset Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Smoke Alarm reset Screen - CCTC Event Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Smoke Alarm reset Cancel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Smoke Alarm reset Confirm Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Smoke Alarm reset Cancel Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Smoke Alarm reset Confirm Request", 0.5, 0.0),
    };
    const size_t IDU_INPUTS_VALUES_NUMBERS_SIZE = sizeof(IDU_INPUTS_VALUES_NUMBERS)/sizeof(IDU_INPUTS_VALUES_NUMBERS[0]);
    const TagInfo *IDU_INPUTS_VALUES_TAGS = 0;
    const size_t IDU_INPUTS_VALUES_TAGS_SIZE = 0;
    const IdentifierInfo *IDU_INPUTS_VALUES_IDENTIFIERS = 0;
    const size_t IDU_INPUTS_VALUES_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *IDU_INPUTS_VALUES_CONSTANTS = 0;
    const size_t IDU_INPUTS_VALUES_CONSTANTS_SIZE = 0;
    const SpecificationInfo *IDU_INPUTS_VALUES_SPECIFICATIONS = 0;
    const size_t IDU_INPUTS_VALUES_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *IDU_INPUTS_VALUES_RAWS = 0;
    const size_t IDU_INPUTS_VALUES_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *IDU_INPUTS_VALUES_TRAYS = 0;
    const size_t IDU_INPUTS_VALUES_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> IDU_INPUTS_MODES_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 405),
        Sim::Info<Sim::Number>("Class Modes", 0.5, 0.0),
        Sim::Info<Sim::Number>("Class Modes", 0.5, 0.0),
        Sim::Info<Sim::Number>("Active Events - Acknowledge Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Active Events - Present Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Acknowledge Event", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Screen Change", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Dark Screen", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Remove Dark Screen", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Skip Station", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request MSG List Next Page", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request MSG List Prev Page", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request MSG List Selected Id", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Open Doors", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Platform CCTV Left View", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Platform CCTV Right View", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Clear Train", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request DOO East Bound View", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request DOO West Bound View", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Toggle Demist", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Toggle Close Dampers", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Event List Selected Record", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Event List Next Page", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Event List Prev Page", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Event List Next Record", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Event List Prev Record", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Restrict Mode", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Depot Speed Set", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Wash_AVIS", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Inhibit Regen", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Mute PIS", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Disable PIS", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Vehicle Over_Run", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Switch Screen", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Toggle Saloon Lights", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Defect List Next Page", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Defect List Prev Page", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Defect List Selected Index", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Priority Message", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Manual Message", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Forward Facing", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Pantograph", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Inhibit Door A", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Inhibit Door B", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Inhibit Door C", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Inhibit Door D", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Inhibit Door E", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Inhibit Door F", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Inhibit Door Front Half", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Inhibit Door Rear Half", 0.5, 0.0),
        Sim::Info<Sim::Number>("Inhibit Doors Screen Selected Vehicle", 0.5, -1),
        Sim::Info<Sim::Number>("Request Start Sequence Camera", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Select Camera", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Camera 1 Selected", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Camera 2 Selected", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Camera 3 Selected", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Camera 4 Selected", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Saloon CCTV", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request PEA Event", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request CFA Event", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon Screen Selected Car Index", 0.5, -1),
        Sim::Info<Sim::Number>("Request Saloon CCTV Driving or Station Button Pressed", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Saloon CCTV To Main Menu Screen", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Expanded View State", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Select PEA1", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Select PEA2", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Select PEA3", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Select CFA1", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Select CFA2", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Select CFA3", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Select CFA4", 0.5, 0.0),
        Sim::Info<Sim::Number>("Add Station Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Skip Station Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Station List Up Arrow Pressed", 0.5, 0.0),
        Sim::Info<Sim::Number>("Station List Down Arrow Pressed", 0.5, 0.0),
        Sim::Info<Sim::Number>("Station List Selected Index", 0.5, 0.0),
        Sim::Info<Sim::Number>("Selected Fault Area Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Select Cars Whole Train Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Select Cars Next Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Select Equipment Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Screen Select Defect Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Keypad Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Keypad Type Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Review Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect New Confirm Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("View Certificate Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("View Certificate Screen - Control Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("View Certificate Screen - Station Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("View Certificate Screen - Active Events Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Select Fault Area Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Select Fault Area Screen - Control Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Select Fault Area Screen - Station Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Select Fault Area Screen - Back Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Select Fault Area Screen - Cab Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Select Fault Area Screen - Saloon Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Select Fault Area Screen - Exterior Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Select Fault Area Screen - Unit Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Station Screen - OpenButton", 0.5, 0.0),
        Sim::Info<Sim::Number>("Station Screen - left View Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Station Screen - Right View Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Station Screen - Clear Train Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Station Screen - Active Event Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Station Screen - Skip Station Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Station Screen - DrivingPanel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Station Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Station Screen - Control Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Station Screen - DMI Screen Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Power Down Screen - Power Down Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("View Defect Screen - Open Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("View Defect Screen - Up Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("View Defect Screen - Down Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("View Defect Screen - Log Defect Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("View Defect Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("View Defect Screen - Control Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("View Defect Screen - Station Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Screen - Inhibit Regen.Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Screen - Close Dampers Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Screen - Mute PIS Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Screen - Demist Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Screen - Switch Screen Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Screen - Lights Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Screen - Disable PIS Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Screen - Vehicle overrun Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Screen - Restrict Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Screen - Deport Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Screen - Wash AVIS Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Screen - Skip Station Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Screen - DrivingPanel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Screen - Active Event Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Confirmation Screen - Active Event Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Confirmation Screen - Skip Station Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Confirmation Screen - Driving Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Confirmation Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Confirmation Screen - Cancel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Confirmation Screen - Confirm Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Confirmation Screen - Cancel Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Control Panel Confirmation Screen - Confirm Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Add Stations Screen - Active Events Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Add Stations Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Add Stations Screen - Control Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Add Stations Screen - Station Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Add Stations Screen - Up Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Add Stations Screen - Down Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Add Stations Screen - Add Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Inhibit Doors Screen - Active Events Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Inhibit Doors Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Inhibit Doors Screen - Control Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Inhibit Doors Screen - Skip Station Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Inhibit Doors Screen - Rear Half Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Inhibit Doors Screen - Front Half Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Inhibit Doors Screen - Inhibit Door A Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Inhibit Doors Screen - Inhibit Door B Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Inhibit Doors Screen - Inhibit Door C Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Inhibit Doors Screen - Inhibit Door D Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Inhibit Doors Screen - Inhibit Door E Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Inhibit Doors Screen - Inhibit Door F Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Menu Screen - View Cert.Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Menu Screen - Defect Log Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Menu Screen - Saloon Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Menu Screen - Forward Facing Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Menu Screen - Panto graph Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Menu Screen - CCTV Playback Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Menu Screen - Inhibit Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Menu Screen - Priority Msg.Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Menu Screen - Manual Msg.Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Menu Screen - Add Station Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Menu Screen - Skip Station Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Menu Screen - Driving Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Menu Screen - Control Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Menu Screen - Active Event Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Menu Screen - Alarm Reset Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Message Screen Screen - Active Events Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Message Screen Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Message Screen Screen - Control Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Message Screen Screen - Station Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Message Screen Screen - Play Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Message Screen Screen - Up Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Message Screen Screen - Down Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Outside CCTV Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Outside CCTV Screen - Station Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Outside CCTV Screen - Active Events Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Outside CCTV Screen - Select Camera Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Outside CCTV Screen - Start Seq Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Outside CCTV Screen - Selected Car Index", 0.5, -1),
        Sim::Info<Sim::Number>("Extended Event Screen - Back Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Extended Event Screen - Station Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Extended Event Screen - Control Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Extended Event Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Extended Event Screen - Selected Vehicle", 0.5, 0.0),
        Sim::Info<Sim::Number>("Active Event List Screen - DoubleUp Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Active Event List Screen - DoubleDown Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Active Event List Screen - Up Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Active Event List Screen - Down Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Active Event List Screen - Open Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Active Event List Screen - Station Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Active Event List Screen - Control Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Active Event List Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Active Event List Screen - Selected Vehicle", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driver Screen - Station Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driver Screen - Control Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driver Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driver Screen - Event Marker Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driver Screen - Demist Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driver Screen - Close Dampers Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driver Screen - Skip Station Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driver Screen - DMI Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driver Screen - Ack Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driver Screen - CCTV Event Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request DMI Screen", 0.5, 0.0),
        Sim::Info<Sim::Number>("Extended Defect Screen - Back Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Extended Defect Screen - Station Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Extended Defect Screen - Control Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Extended Defect Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Extended Defect Screen - ActiveEvents Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("DOO Confirmation Screen - Cancel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("DOO Confirmation Screen - West Bound Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("DOO Confirmation Screen - East Bound Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("DOO Confirmation Screen - Driving Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("DOO Confirmation Screen - Control Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("DOO Confirmation Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("DOO Confirmation Screen - DMI Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("DOO Confirmation Screen - Active Events Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("DOO Confirmation Screen - Skip Station Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("DOO Confirmation Screen - Cancel Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - Back Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - Station Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - Control Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - ActiveEvents Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - CCTV Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - Doors Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - HVAC Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - Glazing Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - PIS Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - Lighting Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - Access Panels Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - Floor Trim Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - Seats Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - Desk Controls Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - HMI Controls Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - TBC MCS Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - Wash Wipe Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - Radio Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - Handset Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - Other Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - Roof Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - Under Frame Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - Brakes Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - Traction Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - Wheels Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Equipment Screen - DOO Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - Back Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - Station Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - Control Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - ActiveEvents Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - Drafts Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - Dirty Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - Dust Ingress Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - Too Cold Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - Noisy Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - Water Ingress Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - Too Hot Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - Smell Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - Graffiti Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - Damage Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - Loose Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - Faulty Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - Stiff Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - Wrong Position Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - Poor Perform Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Select Defect Screen - Rough Riding Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Select Cars Screen - Next Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Select Cars Screen - Back Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Select Cars Screen - Station Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Select Cars Screen - Control Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Select Cars Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Select Cars Screen - Selected Vehicle", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Select Cars Screen - Whole Train Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon CCTV Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon CCTV Screen - Station Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon CCTV Screen - Active Events Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon CCTV Screen - Select Camera Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon CCTV Screen - Select Alarm Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon CCTV Screen - Start Seq Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon CCTV Screen - Camera 1 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon CCTV Screen - Camera 2 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon CCTV Screen - Camera 3 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon CCTV Screen - Camera 4 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon CCTV Screen - PEA Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon CCTV Screen - CFA Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon CCTV Screen - PEA1 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon CCTV Screen - PEA2 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon CCTV Screen - PEA3 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon CCTV Screen - CFA1 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon CCTV Screen - CFA2 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon CCTV Screen - CFA3 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Saloon CCTV Screen - CFA4 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driving Saloon CCTV Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driving Saloon CCTV Screen - Station Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driving Saloon CCTV Screen - Active Events Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driving Saloon CCTV Screen - Select Camera Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driving Saloon CCTV Screen - Start Seq Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driving Saloon CCTV Screen - Camera 1 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driving Saloon CCTV Screen - Camera 2 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driving Saloon CCTV Screen - Camera 3 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driving Saloon CCTV Screen - Camera 4 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driving Saloon CCTV Screen - PEA Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Driving Saloon CCTV Screen - CFA Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Review Defect Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Back Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Station Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Control Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Zero Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - One Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Two Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Three Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Four Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Five Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Six Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Seven Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Eight Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Nine Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - A Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - B Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - C Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - D Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - E Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - F Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - G Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - H Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - I Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - J Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - K Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - L Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - M Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - N Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - O Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - P Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Q Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - R Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - S Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - T Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - U Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - V Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - W Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - X Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Y Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Z Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Dot Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Del Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Numric Key Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Space Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Enter Defect Screen - Alphanumeric Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Confirmation Screen - Back Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Confirmation Screen - Selected Vehicle", 0.5, 0.0),
        Sim::Info<Sim::Number>("Defect Confirmation Screen - Defect Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Smoke Alarm reset Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Smoke Alarm reset Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Smoke Alarm reset Screen - Active Events Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Smoke Alarm reset Screen - Station Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Smoke Alarm reset Screen - Control Panel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Smoke Alarm reset Screen - Main Menu Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Smoke Alarm reset Screen - CCTC Event Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Smoke Alarm reset Cancel Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Smoke Alarm reset Confirm Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Smoke Alarm reset Cancel Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Smoke Alarm reset Confirm Request", 0.5, 0.0),
    };
    const size_t IDU_INPUTS_MODES_NUMBERS_SIZE = sizeof(IDU_INPUTS_MODES_NUMBERS)/sizeof(IDU_INPUTS_MODES_NUMBERS[0]);
    const TagInfo *IDU_INPUTS_MODES_TAGS = 0;
    const size_t IDU_INPUTS_MODES_TAGS_SIZE = 0;
    const IdentifierInfo *IDU_INPUTS_MODES_IDENTIFIERS = 0;
    const size_t IDU_INPUTS_MODES_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *IDU_INPUTS_MODES_CONSTANTS = 0;
    const size_t IDU_INPUTS_MODES_CONSTANTS_SIZE = 0;
    const SpecificationInfo *IDU_INPUTS_MODES_SPECIFICATIONS = 0;
    const size_t IDU_INPUTS_MODES_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *IDU_INPUTS_MODES_RAWS = 0;
    const size_t IDU_INPUTS_MODES_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *IDU_INPUTS_MODES_TRAYS = 0;
    const size_t IDU_INPUTS_MODES_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> IDU_VEHICLE_INPUTS_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 406),
        Sim::Info<Sim::Number>("Toggle Demist", 0.5, 0),
        Sim::Info<Sim::Number>("Toggle Close Dampers", 0.5, 0),
        Sim::Info<Sim::Number>("Fault Alarm Active", 0.5, 0),
        Sim::Info<Sim::Number>("Request Toggle Restrict Mode", 0.5, 0),
        Sim::Info<Sim::Number>("Request Toggle Depot Speed Set", 0.5, 0),
        Sim::Info<Sim::Number>("Request Toggle Wash AVIS", 0.5, 0),
        Sim::Info<Sim::Number>("Request Toggle Inhibit Regen", 0.5, 0),
        Sim::Info<Sim::Number>("Request Toggle Vehicle Over Run", 0.5, 0),
        Sim::Info<Sim::Number>("Request Inhibit Door A", 0.5, 0),
        Sim::Info<Sim::Number>("Request Inhibit Door B", 0.5, 0),
        Sim::Info<Sim::Number>("Request Inhibit Door C", 0.5, 0),
        Sim::Info<Sim::Number>("Request Inhibit Door D", 0.5, 0),
        Sim::Info<Sim::Number>("Request Inhibit Door E", 0.5, 0),
        Sim::Info<Sim::Number>("Request Inhibit Door F", 0.5, 0),
        Sim::Info<Sim::Number>("Open Doors", 0.5, 0),
        Sim::Info<Sim::Number>("Toggle Clear Train", 0.5, 0),
        Sim::Info<Sim::Number>("Merge DMI To TCMS Request", 0.5, 0),
    };
    const size_t IDU_VEHICLE_INPUTS_NUMBERS_SIZE = sizeof(IDU_VEHICLE_INPUTS_NUMBERS)/sizeof(IDU_VEHICLE_INPUTS_NUMBERS[0]);
    const TagInfo *IDU_VEHICLE_INPUTS_TAGS = 0;
    const size_t IDU_VEHICLE_INPUTS_TAGS_SIZE = 0;
    const IdentifierInfo *IDU_VEHICLE_INPUTS_IDENTIFIERS = 0;
    const size_t IDU_VEHICLE_INPUTS_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *IDU_VEHICLE_INPUTS_CONSTANTS = 0;
    const size_t IDU_VEHICLE_INPUTS_CONSTANTS_SIZE = 0;
    const SpecificationInfo *IDU_VEHICLE_INPUTS_SPECIFICATIONS = 0;
    const size_t IDU_VEHICLE_INPUTS_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *IDU_VEHICLE_INPUTS_RAWS = 0;
    const size_t IDU_VEHICLE_INPUTS_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *IDU_VEHICLE_INPUTS_TRAYS = 0;
    const size_t IDU_VEHICLE_INPUTS_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> IDU_VEHICLE_OUTPUTS_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 407),
        Sim::Info<Sim::Number>("ADD Activation", 0.5, 0),
        Sim::Info<Sim::Number>("SIG Redundancy State", 0.5, 0),
        Sim::Info<Sim::Number>("Merge DMI To TCMS State", 0.5, 0),
        Sim::Info<Sim::Number>("ATO Active", 0.5, 0),
        Sim::Info<Sim::Number>("TCMS HMI Power", 0.5, 0),
        Sim::Info<Sim::Number>("VCU Failure", 0.5, 0),
        Sim::Info<Sim::Number>("This Cab Active", 0.5, 0),
        Sim::Info<Sim::Number>("HMI Cab Display Status", 0.5, 0),
        Sim::Info<Sim::Number>("Train Speed Above 1 Kph", 0.5, 0),
        Sim::Info<Sim::Number>("Acknowledge PB", 0.5, 0),
        Sim::Info<Sim::Number>("Silence Alarm PB", 0.5, 0),
        Sim::Info<Sim::Number>("MCS In Secure", 0.5, 0),
        Sim::Info<Sim::Number>("MCS Key Switch On", 0.5, 0),
        Sim::Info<Sim::Number>("Display Powering Down Screen", 0.5, 0),
        Sim::Info<Sim::Number>("TBC Percentage", 0.5, 0),
        Sim::Info<Sim::Number>("Demist State", 0.5, 0),
        Sim::Info<Sim::Number>("Dumpers State", 0.5, 0),
        Sim::Info<Sim::Number>("Clear Train State", 0.5, 0),
        Sim::Info<Sim::Number>("Line Current Limit", 0.5, 0),
        Sim::Info<Sim::Number>("Safety System Isolated", 0.5, 0),
        Sim::Info<Sim::Number>("Pantograph Status", 0.5, 0),
        Sim::Info<Sim::Number>("LCB Status", 0.5, 0),
        Sim::Info<Sim::Number>("Line Voltage", 0.5, 0),
        Sim::Info<Sim::Number>("AC Mode", 0.5, 0),
        Sim::Info<Sim::Number>("DC Mode", 0.5, 0),
        Sim::Info<Sim::Number>("Door A Status", 0.5, 0),
        Sim::Info<Sim::Number>("Door B Status", 0.5, 0),
        Sim::Info<Sim::Number>("Door C Status", 0.5, 0),
        Sim::Info<Sim::Number>("Door D Status", 0.5, 0),
        Sim::Info<Sim::Number>("Door E Status", 0.5, 0),
        Sim::Info<Sim::Number>("Door F Status", 0.5, 0),
        Sim::Info<Sim::Number>("Door Cab A Status", 0.5, 0),
        Sim::Info<Sim::Number>("Door Cab B Status", 0.5, 0),
        Sim::Info<Sim::Number>("Door Cab To Saloon Status", 0.5, 0),
        Sim::Info<Sim::Number>("Head Light Left", 0.5, 0),
        Sim::Info<Sim::Number>("Head Light Right", 0.5, 0),
        Sim::Info<Sim::Number>("Tail Light Left", 0.5, 0),
        Sim::Info<Sim::Number>("Tail Light Right", 0.5, 0),
        Sim::Info<Sim::Number>("Marker Light Left", 0.5, 0),
        Sim::Info<Sim::Number>("Marker Light Right", 0.5, 0),
        Sim::Info<Sim::Number>("Marker Light Centre", 0.5, 0),
        Sim::Info<Sim::Number>("OTMR Healthy Status", 0.5, 0),
        Sim::Info<Sim::Number>("Restrict Mode", 0.5, 0),
        Sim::Info<Sim::Number>("Depot Speed Set", 0.5, 0),
        Sim::Info<Sim::Number>("Wash AVIS", 0.5, 0),
        Sim::Info<Sim::Number>("Inhibit Regen", 0.5, 0),
        Sim::Info<Sim::Number>("Vehicle Over Run", 0.5, 0),
        Sim::Info<Sim::Number>("Door A Inhibited", 0.5, 0),
        Sim::Info<Sim::Number>("Door B Inhibited", 0.5, 0),
        Sim::Info<Sim::Number>("Door C Inhibited", 0.5, 0),
        Sim::Info<Sim::Number>("Door D Inhibited", 0.5, 0),
        Sim::Info<Sim::Number>("Door E Inhibited", 0.5, 0),
        Sim::Info<Sim::Number>("Door F Inhibited", 0.5, 0),
        Sim::Info<Sim::Number>("PEA 1 Status", 0.5, 0),
        Sim::Info<Sim::Number>("PEA 2 Status", 0.5, 0),
        Sim::Info<Sim::Number>("PEA 3 Status", 0.5, 0),
        Sim::Info<Sim::Number>("CFA 1 Status", 0.5, 0),
        Sim::Info<Sim::Number>("CFA 2 Status", 0.5, 0),
        Sim::Info<Sim::Number>("CFA 3 Status", 0.5, 0),
        Sim::Info<Sim::Number>("CFA 4 Status", 0.5, 0),
        Sim::Info<Sim::Number>("Saloon Smoke Detector 1", 0.5, 0),
        Sim::Info<Sim::Number>("Saloon Smoke Detector 2", 0.5, 0),
        Sim::Info<Sim::Number>("Interend Cabinet Smoke Detector", 0.5, 0),
        Sim::Info<Sim::Number>("Egress Handle Door A", 0.5, 0),
        Sim::Info<Sim::Number>("Egress Handle Door B", 0.5, 0),
        Sim::Info<Sim::Number>("Egress Handle Door C", 0.5, 0),
        Sim::Info<Sim::Number>("Egress Handle Door D", 0.5, 0),
        Sim::Info<Sim::Number>("Egress Handle Door E", 0.5, 0),
        Sim::Info<Sim::Number>("Egress Handle Door F", 0.5, 0),
        Sim::Info<Sim::Number>("Door Interlock Lost Door A", 0.5, 0),
        Sim::Info<Sim::Number>("Door Interlock Lost Door B", 0.5, 0),
        Sim::Info<Sim::Number>("Door Interlock Lost Door C", 0.5, 0),
        Sim::Info<Sim::Number>("Door Interlock Lost Door D", 0.5, 0),
        Sim::Info<Sim::Number>("Door Interlock Lost Door E", 0.5, 0),
        Sim::Info<Sim::Number>("Door Interlock Lost Door F", 0.5, 0),
    };
    const size_t IDU_VEHICLE_OUTPUTS_NUMBERS_SIZE = sizeof(IDU_VEHICLE_OUTPUTS_NUMBERS)/sizeof(IDU_VEHICLE_OUTPUTS_NUMBERS[0]);
    const TagInfo *IDU_VEHICLE_OUTPUTS_TAGS = 0;
    const size_t IDU_VEHICLE_OUTPUTS_TAGS_SIZE = 0;
    const IdentifierInfo *IDU_VEHICLE_OUTPUTS_IDENTIFIERS = 0;
    const size_t IDU_VEHICLE_OUTPUTS_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *IDU_VEHICLE_OUTPUTS_CONSTANTS = 0;
    const size_t IDU_VEHICLE_OUTPUTS_CONSTANTS_SIZE = 0;
    const SpecificationInfo *IDU_VEHICLE_OUTPUTS_SPECIFICATIONS = 0;
    const size_t IDU_VEHICLE_OUTPUTS_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *IDU_VEHICLE_OUTPUTS_RAWS = 0;
    const size_t IDU_VEHICLE_OUTPUTS_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *IDU_VEHICLE_OUTPUTS_TRAYS = 0;
    const size_t IDU_VEHICLE_OUTPUTS_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> TCMS_FAULTS_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 410),
    };
    const size_t TCMS_FAULTS_NUMBERS_SIZE = sizeof(TCMS_FAULTS_NUMBERS)/sizeof(TCMS_FAULTS_NUMBERS[0]);
    const TagInfo *TCMS_FAULTS_TAGS = 0;
    const size_t TCMS_FAULTS_TAGS_SIZE = 0;
    const IdentifierInfo *TCMS_FAULTS_IDENTIFIERS = 0;
    const size_t TCMS_FAULTS_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *TCMS_FAULTS_CONSTANTS = 0;
    const size_t TCMS_FAULTS_CONSTANTS_SIZE = 0;
    const SpecificationInfo *TCMS_FAULTS_SPECIFICATIONS = 0;
    const size_t TCMS_FAULTS_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *TCMS_FAULTS_RAWS = 0;
    const size_t TCMS_FAULTS_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *TCMS_FAULTS_TRAYS = 0;
    const size_t TCMS_FAULTS_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> TCMS_FAULT_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 411),
        Sim::Info<Sim::Number>("Index", 0.5, 0.0),
        Sim::Info<Sim::Number>("Fault Id", 0.5, 0.0),
        Sim::Info<Sim::Number>("Fault Status", 0.5, 0.0),
    };
    const size_t TCMS_FAULT_NUMBERS_SIZE = sizeof(TCMS_FAULT_NUMBERS)/sizeof(TCMS_FAULT_NUMBERS[0]);
    const TagInfo *TCMS_FAULT_TAGS = 0;
    const size_t TCMS_FAULT_TAGS_SIZE = 0;
    const IdentifierInfo *TCMS_FAULT_IDENTIFIERS = 0;
    const size_t TCMS_FAULT_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *TCMS_FAULT_CONSTANTS = 0;
    const size_t TCMS_FAULT_CONSTANTS_SIZE = 0;
    const SpecificationInfo *TCMS_FAULT_SPECIFICATIONS = 0;
    const size_t TCMS_FAULT_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *TCMS_FAULT_RAWS = 0;
    const size_t TCMS_FAULT_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *TCMS_FAULT_TRAYS = 0;
    const size_t TCMS_FAULT_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> TRN_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 430),
    };
    const size_t TRN_NUMBERS_SIZE = sizeof(TRN_NUMBERS)/sizeof(TRN_NUMBERS[0]);
    const TagInfo *TRN_TAGS = 0;
    const size_t TRN_TAGS_SIZE = 0;
    const IdentifierInfo *TRN_IDENTIFIERS = 0;
    const size_t TRN_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *TRN_CONSTANTS = 0;
    const size_t TRN_CONSTANTS_SIZE = 0;
    const SpecificationInfo *TRN_SPECIFICATIONS = 0;
    const size_t TRN_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> TRN_RAWS[] =
    {
        Sim::Info<Sim::Raw>("Expected TRN"),
        Sim::Info<Sim::Raw>("TRN"),
    };
    const size_t TRN_RAWS_SIZE = sizeof(TRN_RAWS)/sizeof(TRN_RAWS[0]);
    const Sim::Info<Sim::Tray> *TRN_TRAYS = 0;
    const size_t TRN_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> IDU_CCTV_INPUTS_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 414),
        Sim::Info<Sim::Number>("Class Inputs", 0.5, 0.0),
    };
    const size_t IDU_CCTV_INPUTS_NUMBERS_SIZE = sizeof(IDU_CCTV_INPUTS_NUMBERS)/sizeof(IDU_CCTV_INPUTS_NUMBERS[0]);
    const TagInfo *IDU_CCTV_INPUTS_TAGS = 0;
    const size_t IDU_CCTV_INPUTS_TAGS_SIZE = 0;
    const IdentifierInfo *IDU_CCTV_INPUTS_IDENTIFIERS = 0;
    const size_t IDU_CCTV_INPUTS_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *IDU_CCTV_INPUTS_CONSTANTS = 0;
    const size_t IDU_CCTV_INPUTS_CONSTANTS_SIZE = 0;
    const SpecificationInfo *IDU_CCTV_INPUTS_SPECIFICATIONS = 0;
    const size_t IDU_CCTV_INPUTS_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> IDU_CCTV_INPUTS_RAWS[] =
    {
        Sim::Info<Sim::Raw>("CCTV Camera Raw"),
    };
    const size_t IDU_CCTV_INPUTS_RAWS_SIZE = sizeof(IDU_CCTV_INPUTS_RAWS)/sizeof(IDU_CCTV_INPUTS_RAWS[0]);
    const Sim::Info<Sim::Tray> *IDU_CCTV_INPUTS_TRAYS = 0;
    const size_t IDU_CCTV_INPUTS_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> IDU_CCTV_OUTPUTS_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 415),
        Sim::Info<Sim::Number>("Class Outputs", 0.5, 0.0),
        Sim::Info<Sim::Number>("Vehicle Index", 0.5, 0.0),
        Sim::Info<Sim::Number>("Camera Index", 0.5, 0.0),
    };
    const size_t IDU_CCTV_OUTPUTS_NUMBERS_SIZE = sizeof(IDU_CCTV_OUTPUTS_NUMBERS)/sizeof(IDU_CCTV_OUTPUTS_NUMBERS[0]);
    const TagInfo *IDU_CCTV_OUTPUTS_TAGS = 0;
    const size_t IDU_CCTV_OUTPUTS_TAGS_SIZE = 0;
    const IdentifierInfo *IDU_CCTV_OUTPUTS_IDENTIFIERS = 0;
    const size_t IDU_CCTV_OUTPUTS_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *IDU_CCTV_OUTPUTS_CONSTANTS = 0;
    const size_t IDU_CCTV_OUTPUTS_CONSTANTS_SIZE = 0;
    const SpecificationInfo *IDU_CCTV_OUTPUTS_SPECIFICATIONS = 0;
    const size_t IDU_CCTV_OUTPUTS_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *IDU_CCTV_OUTPUTS_RAWS = 0;
    const size_t IDU_CCTV_OUTPUTS_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *IDU_CCTV_OUTPUTS_TRAYS = 0;
    const size_t IDU_CCTV_OUTPUTS_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> DOO_INPUTS_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 416),
        Sim::Info<Sim::Number>("Class Inputs", 0.5, 0.0),
        Sim::Info<Sim::Number>("Status", 0.5, 0.0),
        Sim::Info<Sim::Number>("Left View", 0.5, 0.0),
        Sim::Info<Sim::Number>("Right View", 0.5, 0.0),
    };
    const size_t DOO_INPUTS_NUMBERS_SIZE = sizeof(DOO_INPUTS_NUMBERS)/sizeof(DOO_INPUTS_NUMBERS[0]);
    const TagInfo *DOO_INPUTS_TAGS = 0;
    const size_t DOO_INPUTS_TAGS_SIZE = 0;
    const IdentifierInfo *DOO_INPUTS_IDENTIFIERS = 0;
    const size_t DOO_INPUTS_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *DOO_INPUTS_CONSTANTS = 0;
    const size_t DOO_INPUTS_CONSTANTS_SIZE = 0;
    const SpecificationInfo *DOO_INPUTS_SPECIFICATIONS = 0;
    const size_t DOO_INPUTS_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *DOO_INPUTS_RAWS = 0;
    const size_t DOO_INPUTS_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *DOO_INPUTS_TRAYS = 0;
    const size_t DOO_INPUTS_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> DOO_OUTPUTS_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 417),
        Sim::Info<Sim::Number>("DOO Right View Already Displayed", 0.5, 0.0),
        Sim::Info<Sim::Number>("DOO Left View Already Displayed", 0.5, 0.0),
    };
    const size_t DOO_OUTPUTS_NUMBERS_SIZE = sizeof(DOO_OUTPUTS_NUMBERS)/sizeof(DOO_OUTPUTS_NUMBERS[0]);
    const TagInfo *DOO_OUTPUTS_TAGS = 0;
    const size_t DOO_OUTPUTS_TAGS_SIZE = 0;
    const IdentifierInfo *DOO_OUTPUTS_IDENTIFIERS = 0;
    const size_t DOO_OUTPUTS_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *DOO_OUTPUTS_CONSTANTS = 0;
    const size_t DOO_OUTPUTS_CONSTANTS_SIZE = 0;
    const SpecificationInfo *DOO_OUTPUTS_SPECIFICATIONS = 0;
    const size_t DOO_OUTPUTS_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *DOO_OUTPUTS_RAWS = 0;
    const size_t DOO_OUTPUTS_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *DOO_OUTPUTS_TRAYS = 0;
    const size_t DOO_OUTPUTS_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> PIS_INPUTS_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 418),
        Sim::Info<Sim::Number>("Active", 0.5, 1.0),
        Sim::Info<Sim::Number>("Mute", 0.5, 0.0),
    };
    const size_t PIS_INPUTS_NUMBERS_SIZE = sizeof(PIS_INPUTS_NUMBERS)/sizeof(PIS_INPUTS_NUMBERS[0]);
    const TagInfo *PIS_INPUTS_TAGS = 0;
    const size_t PIS_INPUTS_TAGS_SIZE = 0;
    const IdentifierInfo *PIS_INPUTS_IDENTIFIERS = 0;
    const size_t PIS_INPUTS_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *PIS_INPUTS_CONSTANTS = 0;
    const size_t PIS_INPUTS_CONSTANTS_SIZE = 0;
    const SpecificationInfo *PIS_INPUTS_SPECIFICATIONS = 0;
    const size_t PIS_INPUTS_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *PIS_INPUTS_RAWS = 0;
    const size_t PIS_INPUTS_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *PIS_INPUTS_TRAYS = 0;
    const size_t PIS_INPUTS_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> PIS_OUTPUTS_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 419),
        Sim::Info<Sim::Number>("Active", 0.5, 1.0),
        Sim::Info<Sim::Number>("Mute", 0.5, 0.0),
    };
    const size_t PIS_OUTPUTS_NUMBERS_SIZE = sizeof(PIS_OUTPUTS_NUMBERS)/sizeof(PIS_OUTPUTS_NUMBERS[0]);
    const TagInfo *PIS_OUTPUTS_TAGS = 0;
    const size_t PIS_OUTPUTS_TAGS_SIZE = 0;
    const IdentifierInfo *PIS_OUTPUTS_IDENTIFIERS = 0;
    const size_t PIS_OUTPUTS_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *PIS_OUTPUTS_CONSTANTS = 0;
    const size_t PIS_OUTPUTS_CONSTANTS_SIZE = 0;
    const SpecificationInfo *PIS_OUTPUTS_SPECIFICATIONS = 0;
    const size_t PIS_OUTPUTS_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *PIS_OUTPUTS_RAWS = 0;
    const size_t PIS_OUTPUTS_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *PIS_OUTPUTS_TRAYS = 0;
    const size_t PIS_OUTPUTS_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> DMI_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 422),
    };
    const size_t DMI_NUMBERS_SIZE = sizeof(DMI_NUMBERS)/sizeof(DMI_NUMBERS[0]);
    const TagInfo *DMI_TAGS = 0;
    const size_t DMI_TAGS_SIZE = 0;
    const IdentifierInfo *DMI_IDENTIFIERS = 0;
    const size_t DMI_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *DMI_CONSTANTS = 0;
    const size_t DMI_CONSTANTS_SIZE = 0;
    const SpecificationInfo *DMI_SPECIFICATIONS = 0;
    const size_t DMI_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *DMI_RAWS = 0;
    const size_t DMI_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *DMI_TRAYS = 0;
    const size_t DMI_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> DMI_OUTPUTS_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 420),
        Sim::Info<Sim::Number>("Class Outputs", 0.5, 0.0),
        Sim::Info<Sim::Number>("Class Outputs", 0.5, 0.0),
        Sim::Info<Sim::Number>("Screen ID", 0.5, 0.0),
        Sim::Info<Sim::Number>("Brake Release Indicator", 0.5, 0.0),
        Sim::Info<Sim::Number>("Train Stop Override Indicator", 0.5, 0.0),
        Sim::Info<Sim::Number>("AWS Brake Indicator", 0.5, 0.0),
        Sim::Info<Sim::Number>("OSS Indicator", 0.5, 0.0),
        Sim::Info<Sim::Number>("SPAD Indicator", 0.5, 0.0),
        Sim::Info<Sim::Number>("Level NTC Indicator", 0.5, 0.0),
        Sim::Info<Sim::Number>("Temporary Isolation Fault Indicator", 0.5, 0.0),
        Sim::Info<Sim::Number>("AWS Isolation Fault Indicator", 0.5, 0.0),
        Sim::Info<Sim::Number>("AWS Visual Indicator", 0.5, 0.0),
        Sim::Info<Sim::Number>("Normal Non Active Indicator", 0.5, 0.0),
        Sim::Info<Sim::Number>("TCMS Button Available", 0.5, 0.0),
        Sim::Info<Sim::Number>("Safe Signaling Screen Active", 0.5, 0.0),
        Sim::Info<Sim::Number>("Train Speed Above 1 KM", 0.5, 0.0),
        Sim::Info<Sim::Number>("CBTC Left Door Status", 0.5, 0.0),
        Sim::Info<Sim::Number>("CBTC Right Door Status", 0.5, 0.0),
        Sim::Info<Sim::Number>("CBTC Mission Control Status", 0.5, 0.0),
        Sim::Info<Sim::Number>("CBTC Current Mode", 0.5, 0.0),
        Sim::Info<Sim::Number>("CBTC Reversal Indicator", 0.5, 0.0),
        Sim::Info<Sim::Number>("CBTC Stopping Accuracy", 0.5, 0.0),
        Sim::Info<Sim::Number>("CBTC PSDS State", 0.5, 0.0),
        Sim::Info<Sim::Number>("CBTC Target Dwell Time", 0.5, 0.0),
        Sim::Info<Sim::Number>("CBTC Errors", 0.5, 0.0),
        Sim::Info<Sim::Number>("CBTC Door Mode Status", 0.5, 0.0),
        Sim::Info<Sim::Number>("CBTC Delocalised", 0.5, 0.0),
        Sim::Info<Sim::Number>("Target Speed Bar Required", 0.5, 0.0),
        Sim::Info<Sim::Number>("Recommended Speed Bar Required", 0.5, 0.0),
        Sim::Info<Sim::Number>("Intervention Speed Bar Required", 0.5, 0.0),
        Sim::Info<Sim::Number>("Current Speed", 0.1, 0.0),
        Sim::Info<Sim::Number>("CBTC Target Speed", 0.1, 0.0),
        Sim::Info<Sim::Number>("CBTC Recommended Speed", 0.1, 0.0),
        Sim::Info<Sim::Number>("CBTC Intervention Speed", 0.1, 0.0),
        Sim::Info<Sim::Number>("CBTC Indication Speed", 0.1, 0.0),
        Sim::Info<Sim::Number>("CBTC Monitoring Mode", 0.5, 0.0),
        Sim::Info<Sim::Number>("Distance To Target", 0.1, 0.0),
        Sim::Info<Sim::Number>("Speed Status", 0.5, 0.0),
        Sim::Info<Sim::Number>("Release Speed", 0.5, 0.0),
        Sim::Info<Sim::Number>("Date Time", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Geographical Position", 0.5, -1),
        Sim::Info<Sim::Number>("Current ERTMS ETCS mode", 0.5, 0.0),
        Sim::Info<Sim::Number>("Current ERTMS ETCS level", 0.5, 0.0),
        Sim::Info<Sim::Number>("Is Start Button Enabled", 0.5, 0.0),
        Sim::Info<Sim::Number>("Is Driver ID Button Enabled", 0.5, 0.0),
        Sim::Info<Sim::Number>("Is Train Data Button Enabled", 0.5, 0.0),
        Sim::Info<Sim::Number>("Is Level Button Enabled", 0.5, 0.0),
        Sim::Info<Sim::Number>("Is TRN Button Enabled", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Window Close Button State", 0.5, 1.0),
        Sim::Info<Sim::Number>("Main Window Shunting Button State", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Window Non Leading Button State", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Window Maintain Shunting Button State", 0.5, 0.0),
        Sim::Info<Sim::Number>("Is StartUp On", 0.5, 0.0),
        Sim::Info<Sim::Number>("Is StartUp Sequence Completed", 0.5, 0.0),
        Sim::Info<Sim::Number>("Start Of Mission Complete", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Start Of Mission Completed", 0.5, 0.0),
        Sim::Info<Sim::Number>("Is DriverId Valid", 0.5, 0.0),
        Sim::Info<Sim::Number>("Is TRN Valid", 0.5, 0.0),
        Sim::Info<Sim::Number>("Is Level Valid", 0.5, 0.0),
        Sim::Info<Sim::Number>("Is Train Data Validation Successful", 0.5, 0.0),
        Sim::Info<Sim::Number>("DriverID Screen States", 0.5, 1.0),
        Sim::Info<Sim::Number>("TRN Screen States", 0.5, 1.0),
        Sim::Info<Sim::Number>("Passenger Service TRN Screen States", 0.5, 1.0),
        Sim::Info<Sim::Number>("Configured level", 0.5, 0.0),
        Sim::Info<Sim::Number>("Emergency service", 0.5, 0.0),
        Sim::Info<Sim::Number>("Train Data Screen Confirm Button State", 0.5, 0.0),
        Sim::Info<Sim::Number>("Level Screen CBTC Button State", 0.5, 0.0),
        Sim::Info<Sim::Number>("Level Screen TPWS Button State", 0.5, 0.0),
        Sim::Info<Sim::Number>("Level Screen CBTC SA Button State", 0.5, 0.0),
        Sim::Info<Sim::Number>("Das Recommended Speed", 0.5, 0.0),
        Sim::Info<Sim::Number>("Das Coast Indicator", 0.5, 0.0),
        Sim::Info<Sim::Number>("Das Manual Suppressed", 0.5, 0.0),
        Sim::Info<Sim::Number>("Das Auto Suppressed", 0.5, 0.0),
        Sim::Info<Sim::Number>("Speedometer Failure", 0.5, 0.0),
        Sim::Info<Sim::Number>("Touchscreen Failure", 0.5, 0.0),
        Sim::Info<Sim::Number>("SIG Redundancy Screen Swap", 0.5, 0.0),
        Sim::Info<Sim::Number>("Safety System Status", 0.5, 0.0),
        Sim::Info<Sim::Number>("Front Pantograph Status", 0.5, 0.0),
        Sim::Info<Sim::Number>("Rear Pantograph Status", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request TCMS Screen", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Active Event Acknowledge", 0.5, 0.0),
        Sim::Info<Sim::Number>("Flash State", 0.5, 0.0),
        Sim::Info<Sim::Number>("CBTC Door Supervision Request State", 0.5, 0.0),
        Sim::Info<Sim::Number>("CBTC Left Door Request State", 0.5, 0.0),
        Sim::Info<Sim::Number>("CBTC Both Door Request State", 0.5, 0.0),
        Sim::Info<Sim::Number>("CBTC Right Door Request State", 0.5, 0.0),
        Sim::Info<Sim::Number>("Highest Available CBTC Mode", 0.5, 0.0),
        Sim::Info<Sim::Number>("First Text Message Index", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Message Acknowledged", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Message Negative Acknowledged", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Cabin Activation", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS First Transition Requested", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Current Mode", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Mode Ack Requested", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Current Level", 0.5, 1),
        Sim::Info<Sim::Number>("ETCS NTC Level", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS NTC Level Requested", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Level Requested", 0.5, -1),
        Sim::Info<Sim::Number>("ETCS Level Ack Requested", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Speed Status", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Release Speed", 0.1, 0),
        Sim::Info<Sim::Number>("ETCS Target Speed", 0.1, 0),
        Sim::Info<Sim::Number>("ETCS Permitted Speed", 0.1, 0),
        Sim::Info<Sim::Number>("ETCS Intervention Speed", 0.1, 0),
        Sim::Info<Sim::Number>("ETCS Monitoring Mode", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Limited Supervised Speed", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Distance to Target Speed", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Indication marker distance", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Brake Intervention", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Brake Intervention Ack Requested", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Train Geographical Position", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Reversing Permitted", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Track Ahead Info", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Override State", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Adhesion Available", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS SR Speed Available", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Train Integrity Available", 0.5, 0),
        Sim::Info<Sim::Number>("Level Screen LEVEL 0 Button State", 0.5, 0),
        Sim::Info<Sim::Number>("Level Screen LEVEL 1 Button State", 0.5, 0),
        Sim::Info<Sim::Number>("Level Screen LEVEL 2 Button State", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Tunnel Stopping", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Tunnel Stopping Remaining Distance", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Radio Connection", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Train Position", 0.5, 1),
        Sim::Info<Sim::Number>("ETCS Current Zooming Scale", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Hide Show Button State", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Adhesion Button Enabled", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS SR Speed Distance Button Enabled", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Train Integrity Button Enabled", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Data View Current Page", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS SR Screen Speed Input Field States", 0.5, 1.0),
        Sim::Info<Sim::Number>("ETCS SR Screen Distance Input Field States", 0.5, 1.0),
        Sim::Info<Sim::Number>("ETCS Hour Glass Current State", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Connect Hour Glass State", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Tunnel Stopping Toggle Status", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS RBC Data", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS RBC Data Screen RBC ID Input Field States", 0.5, 1.0),
        Sim::Info<Sim::Number>("ETCS RBC Data Screen RBC Phone Input Field States", 0.5, 1.0),
        Sim::Info<Sim::Number>("ETCS Panel A B Toggle Status", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Emergency Stop Active", 0.5, 0.0),
        Sim::Info<Sim::Number>("Scenario Setup SOM State", 0.5, 0.0),
        Sim::Info<Sim::Number>("Operational Non Active Display", 0.5, 0.0),
    };
    const size_t DMI_OUTPUTS_NUMBERS_SIZE = sizeof(DMI_OUTPUTS_NUMBERS)/sizeof(DMI_OUTPUTS_NUMBERS[0]);
    const TagInfo *DMI_OUTPUTS_TAGS = 0;
    const size_t DMI_OUTPUTS_TAGS_SIZE = 0;
    const IdentifierInfo *DMI_OUTPUTS_IDENTIFIERS = 0;
    const size_t DMI_OUTPUTS_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *DMI_OUTPUTS_CONSTANTS = 0;
    const size_t DMI_OUTPUTS_CONSTANTS_SIZE = 0;
    const SpecificationInfo *DMI_OUTPUTS_SPECIFICATIONS = 0;
    const size_t DMI_OUTPUTS_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> DMI_OUTPUTS_RAWS[] =
    {
        Sim::Info<Sim::Raw>("Driver ID"),
        Sim::Info<Sim::Raw>("Train Number"),
        Sim::Info<Sim::Raw>("Train Number 7 Digit"),
        Sim::Info<Sim::Raw>("Keypad Type Text"),
        Sim::Info<Sim::Raw>("TRN Keypad Type Text"),
        Sim::Info<Sim::Raw>("Passenger Service TRN Keypad Type Text"),
        Sim::Info<Sim::Raw>("TrainData Screen Input Field Text"),
        Sim::Info<Sim::Raw>("TrainData Validation Screen Input Field Text"),
        Sim::Info<Sim::Raw>("Level Screen Input Field Text"),
        Sim::Info<Sim::Raw>("Current Active Event"),
        Sim::Info<Sim::Raw>("Line Voltage"),
        Sim::Info<Sim::Raw>("Door Mode Screen Input Field Text"),
        Sim::Info<Sim::Raw>("CBTC Mode Menu Screen Input Field Text"),
        Sim::Info<Sim::Raw>("CBTC Validation Screen Acknowledgement Text"),
        Sim::Info<Sim::Raw>("Text Message List"),
        Sim::Info<Sim::Raw>("ETCS Text Message List"),
        Sim::Info<Sim::Raw>("ETCS Gradients Speed Discontinuity and Marker"),
        Sim::Info<Sim::Raw>("ETCS Order Announcements"),
        Sim::Info<Sim::Raw>("ETCS Adhesion Screen Input Field Text"),
        Sim::Info<Sim::Raw>("ETCS Data View"),
        Sim::Info<Sim::Raw>("ETCS SR Speed Distance Screen Speed Input Field Text"),
        Sim::Info<Sim::Raw>("ETCS SR Speed Distance Screen Distance Input Field Text"),
        Sim::Info<Sim::Raw>("ETCS SR Speed Distance Screen Speed Text"),
        Sim::Info<Sim::Raw>("ETCS SR Speed Distance Screen Distance Text"),
        Sim::Info<Sim::Raw>("ETCS Remove VBC Screen Input Field Text"),
        Sim::Info<Sim::Raw>("ETCS Set VBC Screen Input Field Text"),
        Sim::Info<Sim::Raw>("ETCS VBC Screen VBC Code"),
        Sim::Info<Sim::Raw>("ETCS Remove VBC Validation Input Field Text"),
        Sim::Info<Sim::Raw>("ETCS Set VBC Validation Input Field Text"),
        Sim::Info<Sim::Raw>("ETCS Allowed Radio Networks"),
        Sim::Info<Sim::Raw>("ETCS Radio Network ID Screen Input Field Text"),
        Sim::Info<Sim::Raw>("ETCS RBC Data Screen RBC ID Input Field Text"),
        Sim::Info<Sim::Raw>("ETCS RBC Data Screen RBC Phone Input Field Text"),
    };
    const size_t DMI_OUTPUTS_RAWS_SIZE = sizeof(DMI_OUTPUTS_RAWS)/sizeof(DMI_OUTPUTS_RAWS[0]);
    const Sim::Info<Sim::Tray> *DMI_OUTPUTS_TRAYS = 0;
    const size_t DMI_OUTPUTS_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> DMI_INPUTS_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 421),
        Sim::Info<Sim::Number>("Class Inputs", 0.5, 0.0),
        Sim::Info<Sim::Number>("Class Inputs", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Screen Change", 0.5, -1),
        Sim::Info<Sim::Number>("Default Window Screen - Main Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Default Window Screen - Override Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Default Window Screen - Dataview Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Default Window Screen - Spec Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Default Window Screen - Setting Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Default Window Screen - TCMS Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Geographical Position Label Request", 0.5, -1),
        Sim::Info<Sim::Number>("Request Default Window Screen TCMS Button Pressed", 0.5, 0.0),
        Sim::Info<Sim::Number>("TPWS Default Window Screen - SPAD Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("TPWS Default Window Screen - OSS Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("TPWS Default Window Screen - AWS Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("TPWS Default Window Screen - TSO Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("TPWS Default Window Screen - BR Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request TPWS Default Window Screen SPAD Button Pressed", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request TPWS Default Window Screen OSS Button Pressed", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request TPWS Default Window Screen AWS Button Pressed", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request TPWS Default Window Screen TSO Button Pressed", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request TPWS Default Window Screen BR Button Pressed", 0.5, 0.0),
        Sim::Info<Sim::Number>("CBTC Default Window Screen - CBTC Mode Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("CBTC Default Window Screen - Doors Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Reversal Operation Indicator Pressed", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Window Screen - Start Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Window Screen - DriverID Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Window Screen - TrainData Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Window Screen - Level Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Window Screen - Train Running Number Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Window Screen - Shunting Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Window Screen - Non Leading Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Window Screen - Maintain Shunting Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Window Screen - Close Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Window Screen - Blank Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Window Screen - Request Close Button Pressed", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Window Screen - Request Shunting Button Pressed", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Start Button Pressed", 0.5, 0.0),
        Sim::Info<Sim::Number>("DriverId Screen - Setting Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("DriverId Screen - Train Running Number Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("DriverId Screen - Close Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("DriverId Screen Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("TrainData Screen - Close Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("TrainData Screen - Type1 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("TrainData Screen - Type2 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("TrainData Screen - Type3 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("TrainData Screen - Confirm Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("TrainData Screen Input Field Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Type Button Pressed", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Yes Button Pressed", 0.5, 0.0),
        Sim::Info<Sim::Number>("TrainData Validation Screen - Type1 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("TrainData Validation Screen - Type2 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("TrainData Validation Screen - Type3 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("TrainData Validation Screen - Yes Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("TrainData Validation Screen - No Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("TrainData Validation Screen - Enter data Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("TrainData Validation Screen - Confirm Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("TrainData Validation Screen Input Field Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request TrainData Validation Yes Button Pressed", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request TrainData Validation No Button Pressed", 0.5, 0.0),
        Sim::Info<Sim::Number>("Level Screen - Close Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Level Screen - Level1 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Level Screen - Level2 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Level Screen - Level0 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Level Screen - TPWS Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Level Screen - CBTC Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Level Screen - CBTC SA Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Level Screen Button Pressed", 0.5, -1),
        Sim::Info<Sim::Number>("Request NTC Level Screen Button Pressed", 0.5, 0),
        Sim::Info<Sim::Number>("Request CBTC SA Level Screen Button Pressed", 0.5, 0),
        Sim::Info<Sim::Number>("Level Screen - Close Button Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Keypad - Button 0", 0.5, 0.0),
        Sim::Info<Sim::Number>("Keypad - Button 1", 0.5, 0.0),
        Sim::Info<Sim::Number>("Keypad - Button 2", 0.5, 0.0),
        Sim::Info<Sim::Number>("Keypad - Button 3", 0.5, 0.0),
        Sim::Info<Sim::Number>("Keypad - Button 4", 0.5, 0.0),
        Sim::Info<Sim::Number>("Keypad - Button 5", 0.5, 0.0),
        Sim::Info<Sim::Number>("Keypad - Button 6", 0.5, 0.0),
        Sim::Info<Sim::Number>("Keypad - Button 7", 0.5, 0.0),
        Sim::Info<Sim::Number>("Keypad - Button 8", 0.5, 0.0),
        Sim::Info<Sim::Number>("Keypad - Button 9", 0.5, 0.0),
        Sim::Info<Sim::Number>("Keypad - Button Delete", 0.5, 0.0),
        Sim::Info<Sim::Number>("Keypad - Button Input Mode", 0.5, 0.0),
        Sim::Info<Sim::Number>("Keypad - Button Dot", 0.5, 0.0),
        Sim::Info<Sim::Number>("Keypad - Button Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("TRN Screen - Close Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("TRN Screen Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("TRN Screen - Close Button Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Passenger Service TRN Screen - Close Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Passenger Service TRN Screen Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Passenger Service TRN Screen - NA Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Passenger Service TRN Screen - Close Button Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("SETTING Screen - Language Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("SETTING Screen - Volume Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("SETTING Screen - Brightness Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("SETTING Screen - Version Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("SETTING Screen - SetVBC Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("SETTING Screen - RemoveVBC Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("SETTING Screen - Switch Screen Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("SETTING Screen - Switch Screen Button Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("SETTING Screen - Close Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("SETTING Screen - Close Button Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Text Message - Up Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Text Message - Down Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request First Text Message Index ", 0.5, -1),
        Sim::Info<Sim::Number>("Text Message Acknowledged", 0.5, 0.0),
        Sim::Info<Sim::Number>("Text Message - Ack Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Text Message - Nack Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Ack Nack", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Mode Screen - Close Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Mode Screen - Close Button Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Mode Screen Change Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Mode Screen - Button MOMC", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Mode Screen - Button AOAC", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Mode Screen - Button AOMC", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Mode Screen - Button MOAC", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Mode Screen - Button Door Supervision", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Mode Screen - Button Cancel Door Supervision", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Mode Screen - Button Enforce Door Release Left", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Mode Screen - Button Cancel Enforce Door Release Left", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Mode Screen - Button Enforce Door Release Both", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Mode Screen - Button Cancel Enforce Door Release Both", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Mode Screen - Button Enforce Door Release Right", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Mode Screen - Button Cancel Enforce Door Release Right", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Mode Screen - Door Mode Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Mode Screen - Door Supervision Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Mode Screen - Left Door State Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Mode Screen - Both Door State Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Mode Screen - Right Door State Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("CBTC Mode Menu Screen - AM Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("CBTC Mode Menu Screen - PM Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("CBTC Mode Menu Screen - SA Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("CBTC Mode Menu Screen - Close Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("CBTC Mode Menu Screen Change Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("CBTC Mode Menu Screen - CBTC Mode Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("CBTC Mode Menu Screen - Close Button Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Scale Up", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Scale Down", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Hide Show Button Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Track Ahead Ack", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Mode Acknowledged", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Level Acknowledged", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Driver Requested Level", 0.5, -1),
        Sim::Info<Sim::Number>("ETCS Driver Requested NTC Level", 0.5, -1),
        Sim::Info<Sim::Number>("ETCS EOA Override Button", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS EOA Override Request", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Adhesion Input", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS SR Distance", 0.1, 0),
        Sim::Info<Sim::Number>("ETCS SR Speed", 0.1, 0),
        Sim::Info<Sim::Number>("ETCS Special Screen - Train Integrity Button", 0.1, 0),
        Sim::Info<Sim::Number>("ETCS Special Screen - Close Button", 0.1, 0),
        Sim::Info<Sim::Number>("ETCS Special Screen - Close Button Request", 0.1, 0),
        Sim::Info<Sim::Number>("ETCS Tunnel Stopping Area Toggled Status Requested", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Start Of Mission Request", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Brake Intervention Acknowledged", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Adhesion Screen - Close Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Adhesion Screen - Non Slippery Rail Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Adhesion Screen - Slippery Rail Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Adhesion Screen Input Field Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request ETCS Adhesion Screen Button Pressed", 0.5, -1),
        Sim::Info<Sim::Number>("ETCS Adhesion Screen - Close Button Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Data View Screen - Close Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Data View Screen - Prev Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Data View Screen - Next Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Data View Screen - Current Page Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS SR Screen Speed Input Field Request", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS SR Screen Distance Input Field Request", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS SR Screen Confirm Button Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS SR Screen Confirm Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Remove VBC Screen Confirm Button Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Remove VBC Screen Confirm Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Remove VBC Screen Close Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Remove VBC Validation Screen Yes Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Remove VBC Validation Screen No Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Remove VBC Validation Yes Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Remove VBC Validation No Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Remove VBC Validation Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Set VBC Screen Confirm Button Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Set VBC Screen Confirm Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Set VBC Screen Close Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Set VBC Validation Screen Yes Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Set VBC Validation Screen No Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Set VBC Validation Yes Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Set VBC Validation No Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Set VBC Validation Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS RBC Screen - Contact Last RBC Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS RBC Screen - User Short Number Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS RBC Screen - Enter RBC Data Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS RBC Screen - Radio Network ID Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS RBC Screen - Close Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS RBC Screen Contact Last RBC Button Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS RBC Screen User Short Number Button Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS RBC Screen Enter RBC Data Button Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS RBC Screen Radio Network ID Button Pressed Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS RBC Screen Radio Network ID Button Released Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Radio Network ID Screen - Close Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Radio Network ID Screen Input Field Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Radio Network ID Screen Button Pressed Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS RBC Data Screen - ID Input Field Request", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS RBC Data Screen - Phone Input Field Request", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS RBC Data Screen - Confirm Button Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS RBC Data Screen - Confirm Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS RBC Data Screen - Close Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS System Version Screen - Close Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS System Version Screen - Close Button Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Panel A B Toggle Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Reset Screen - Setting Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Active Event - Acknowledge Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Active Event Acknowledge", 0.5, 0.0),
    };
    const size_t DMI_INPUTS_NUMBERS_SIZE = sizeof(DMI_INPUTS_NUMBERS)/sizeof(DMI_INPUTS_NUMBERS[0]);
    const TagInfo *DMI_INPUTS_TAGS = 0;
    const size_t DMI_INPUTS_TAGS_SIZE = 0;
    const IdentifierInfo *DMI_INPUTS_IDENTIFIERS = 0;
    const size_t DMI_INPUTS_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *DMI_INPUTS_CONSTANTS = 0;
    const size_t DMI_INPUTS_CONSTANTS_SIZE = 0;
    const SpecificationInfo *DMI_INPUTS_SPECIFICATIONS = 0;
    const size_t DMI_INPUTS_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *DMI_INPUTS_RAWS = 0;
    const size_t DMI_INPUTS_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *DMI_INPUTS_TRAYS = 0;
    const size_t DMI_INPUTS_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> DMI_INPUTS_VALUES_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 423),
        Sim::Info<Sim::Number>("Class Values", 0.5, 0.0),
        Sim::Info<Sim::Number>("Class Values", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Screen Change", 0.5, -1),
        Sim::Info<Sim::Number>("Default Window Screen - Main Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Default Window Screen - Override Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Default Window Screen - Dataview Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Default Window Screen - Spec Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Default Window Screen - Setting Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Default Window Screen - TCMS Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Default Window Screen TCMS Button Pressed", 0.5, 0.0),
        Sim::Info<Sim::Number>("TPWS Default Window Screen - SPAD Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("TPWS Default Window Screen - OSS Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("TPWS Default Window Screen - AWS Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("TPWS Default Window Screen - TSO Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("TPWS Default Window Screen - BR Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request TPWS Default Window Screen SPAD Button Pressed", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request TPWS Default Window Screen OSS Button Pressed", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request TPWS Default Window Screen AWS Button Pressed", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request TPWS Default Window Screen TSO Button Pressed", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request TPWS Default Window Screen BR Button Pressed", 0.5, 0.0),
        Sim::Info<Sim::Number>("CBTC Default Window Screen - CBTC Mode Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("CBTC Default Window Screen - Doors Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Reversal Operation Indicator Pressed", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Window Screen - Start Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Window Screen - DriverID Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Window Screen - TrainData Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Window Screen - Level Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Window Screen - Train Running Number Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Window Screen - Shunting Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Window Screen - Non Leading Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Window Screen - Maintain Shunting Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Window Screen - Close Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Window Screen - Blank Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Window Screen - Request Close Button Pressed", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Window Screen - Request Shunting Button Pressed", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Start Button Pressed", 0.5, 0.0),
        Sim::Info<Sim::Number>("DriverId Screen - Setting Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("DriverId Screen - Train Running Number Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("DriverId Screen - Close Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("DriverId Screen Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("TrainData Screen - Close Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("TrainData Screen - Type1 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("TrainData Screen - Type2 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("TrainData Screen - Type3 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("TrainData Screen - Confirm Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("TrainData Screen Input Field Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Type Button Pressed", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Yes Button Pressed", 0.5, 0.0),
        Sim::Info<Sim::Number>("TrainData Validation Screen - Type1 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("TrainData Validation Screen - Type2 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("TrainData Validation Screen - Type3 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("TrainData Validation Screen - Yes Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("TrainData Validation Screen - No Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("TrainData Validation Screen - Enter data Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("TrainData Validation Screen - Confirm Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("TrainData Validation Screen Input Field Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request TrainData Validation Yes Button Pressed", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request TrainData Validation No Button Pressed", 0.5, 0.0),
        Sim::Info<Sim::Number>("Level Screen - Close Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Level Screen - Level1 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Level Screen - Level2 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Level Screen - Level0 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Level Screen - TPWS Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Level Screen - CBTC Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Level Screen - CBTC SA Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Level Screen Button Pressed", 0.5, -1),
        Sim::Info<Sim::Number>("Request NTC Level Screen Button Pressed", 0.5, 0),
        Sim::Info<Sim::Number>("Request CBTC SA Level Screen Button Pressed", 0.5, 0),
        Sim::Info<Sim::Number>("Level Screen - Close Button Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("TRN Screen - Close Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("TRN Screen Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("TRN Screen - Close Button Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Passenger Service TRN Screen - Close Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Passenger Service TRN Screen Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Passenger Service TRN Screen - NA Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Passenger Service TRN Screen - Close Button Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Keypad - Button 0", 0.5, 0.0),
        Sim::Info<Sim::Number>("Keypad - Button 1", 0.5, 0.0),
        Sim::Info<Sim::Number>("Keypad - Button 2", 0.5, 0.0),
        Sim::Info<Sim::Number>("Keypad - Button 3", 0.5, 0.0),
        Sim::Info<Sim::Number>("Keypad - Button 4", 0.5, 0.0),
        Sim::Info<Sim::Number>("Keypad - Button 5", 0.5, 0.0),
        Sim::Info<Sim::Number>("Keypad - Button 6", 0.5, 0.0),
        Sim::Info<Sim::Number>("Keypad - Button 7", 0.5, 0.0),
        Sim::Info<Sim::Number>("Keypad - Button 8", 0.5, 0.0),
        Sim::Info<Sim::Number>("Keypad - Button 9", 0.5, 0.0),
        Sim::Info<Sim::Number>("Keypad - Button Delete", 0.5, 0.0),
        Sim::Info<Sim::Number>("Keypad - Button Input Mode", 0.5, 0.0),
        Sim::Info<Sim::Number>("Keypad - Button Dot", 0.5, 0.0),
        Sim::Info<Sim::Number>("Keypad - Button Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("SETTING Screen - Language Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("SETTING Screen - Volume Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("SETTING Screen - Brightness Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("SETTING Screen - Version Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("SETTING Screen - SetVBC Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("SETTING Screen - RemoveVBC Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("SETTING Screen - Switch Screen Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("SETTING Screen - Switch Screen Button Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("SETTING Screen - Close Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("SETTING Screen - Close Button Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Text Message - Up Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Text Message - Down Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request First Text Message Index ", 0.5, -1),
        Sim::Info<Sim::Number>("Text Message Acknowledged", 0.5, 0.0),
        Sim::Info<Sim::Number>("Text Message - Ack Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Text Message - Nack Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Ack Nack", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Mode Screen - Close Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Mode Screen - Close Button Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Mode Screen Change Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Mode Screen - Button MOMC", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Mode Screen - Button AOAC", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Mode Screen - Button AOMC", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Mode Screen - Button MOAC", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Mode Screen - Button Door Supervision", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Mode Screen - Button Cancel Door Supervision", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Mode Screen - Button Enforce Door Release Left", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Mode Screen - Button Cancel Enforce Door Release Left", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Mode Screen - Button Enforce Door Release Both", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Mode Screen - Button Cancel Enforce Door Release Both", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Mode Screen - Button Enforce Door Release Right", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Mode Screen - Button Cancel Enforce Door Release Right", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Mode Screen - Door Mode Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Mode Screen - Door Supervision Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Mode Screen - Left Door State Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Mode Screen - Both Door State Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Mode Screen - Right Door State Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("CBTC Mode Menu Screen - AM Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("CBTC Mode Menu Screen - PM Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("CBTC Mode Menu Screen - SA Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("CBTC Mode Menu Screen - Close Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("CBTC Mode Menu Screen Change Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("CBTC Mode Menu Screen - CBTC Mode Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("CBTC Mode Menu Screen - Close Button Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Scale Up", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Scale Down", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Hide Show Button Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Track Ahead Ack", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Mode Acknowledged", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Level Acknowledged", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Driver Requested Level", 0.5, -1),
        Sim::Info<Sim::Number>("ETCS Driver Requested NTC Level", 0.5, -1),
        Sim::Info<Sim::Number>("ETCS EOA Override Button", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS EOA Override Request", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Adhesion Input", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS SR Distance", 0.1, 0),
        Sim::Info<Sim::Number>("ETCS SR Speed", 0.1, 0),
        Sim::Info<Sim::Number>("ETCS Special Screen - Train Integrity Button", 0.1, 0),
        Sim::Info<Sim::Number>("ETCS Special Screen - Close Button", 0.1, 0),
        Sim::Info<Sim::Number>("ETCS Special Screen - Close Button Request", 0.1, 0),
        Sim::Info<Sim::Number>("ETCS Tunnel Stopping Area Toggled Status Requested", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Start Of Mission Request", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Brake Intervention Acknowledged", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Geographical Position Label Request", 0.5, -1),
        Sim::Info<Sim::Number>("ETCS Adhesion Screen - Close Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Adhesion Screen - Non Slippery Rail Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Adhesion Screen - Slippery Rail Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Adhesion Screen Input Field Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request ETCS Adhesion Screen Button Pressed", 0.5, -1),
        Sim::Info<Sim::Number>("ETCS Adhesion Screen - Close Button Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Data View Screen - Close Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Data View Screen - Prev Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Data View Screen - Next Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Data View Screen - Current Page Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS SR Screen Speed Input Field Request", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS SR Screen Distance Input Field Request", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS SR Screen Confirm Button Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS SR Screen Confirm Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Remove VBC Screen Confirm Button Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Remove VBC Screen Confirm Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Remove VBC Screen Close Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Remove VBC Validation Screen Yes Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Remove VBC Validation Screen No Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Remove VBC Validation Yes Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Remove VBC Validation No Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Remove VBC Validation Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Set VBC Screen Confirm Button Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Set VBC Screen Confirm Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Set VBC Screen Close Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Set VBC Validation Screen Yes Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Set VBC Validation Screen No Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Set VBC Validation Yes Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Set VBC Validation No Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Set VBC Validation Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS RBC Screen - Contact Last RBC Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS RBC Screen - User Short Number Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS RBC Screen - Enter RBC Data Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS RBC Screen - Radio Network ID Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS RBC Screen - Close Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS RBC Screen Contact Last RBC Button Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS RBC Screen User Short Number Button Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS RBC Screen Enter RBC Data Button Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS RBC Screen Radio Network ID Button Pressed Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS RBC Screen Radio Network ID Button Released Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Radio Network ID Screen - Close Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Radio Network ID Screen Input Field Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Radio Network ID Screen Button Pressed Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS RBC Data Screen - ID Input Field Request", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS RBC Data Screen - Phone Input Field Request", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS RBC Data Screen - Confirm Button Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS RBC Data Screen - Confirm Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS RBC Data Screen - Close Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS System Version Screen - Close Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS System Version Screen - Close Button Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Panel A B Toggle Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Reset Screen - Setting Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Active Event - Acknowledge Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Active Event Acknowledge", 0.5, 0.0),
    };
    const size_t DMI_INPUTS_VALUES_NUMBERS_SIZE = sizeof(DMI_INPUTS_VALUES_NUMBERS)/sizeof(DMI_INPUTS_VALUES_NUMBERS[0]);
    const TagInfo *DMI_INPUTS_VALUES_TAGS = 0;
    const size_t DMI_INPUTS_VALUES_TAGS_SIZE = 0;
    const IdentifierInfo *DMI_INPUTS_VALUES_IDENTIFIERS = 0;
    const size_t DMI_INPUTS_VALUES_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *DMI_INPUTS_VALUES_CONSTANTS = 0;
    const size_t DMI_INPUTS_VALUES_CONSTANTS_SIZE = 0;
    const SpecificationInfo *DMI_INPUTS_VALUES_SPECIFICATIONS = 0;
    const size_t DMI_INPUTS_VALUES_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *DMI_INPUTS_VALUES_RAWS = 0;
    const size_t DMI_INPUTS_VALUES_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *DMI_INPUTS_VALUES_TRAYS = 0;
    const size_t DMI_INPUTS_VALUES_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> DMI_INPUTS_MODES_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 424),
        Sim::Info<Sim::Number>("Class Modes", 0.5, 0.0),
        Sim::Info<Sim::Number>("Class Modes", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Screen Change", 0.5, -1),
        Sim::Info<Sim::Number>("Default Window Screen - Main Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Default Window Screen - Override Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Default Window Screen - Dataview Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Default Window Screen - Spec Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Default Window Screen - Setting Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Default Window Screen - TCMS Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Default Window Screen TCMS Button Pressed", 0.5, 0.0),
        Sim::Info<Sim::Number>("TPWS Default Window Screen - SPAD Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("TPWS Default Window Screen - OSS Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("TPWS Default Window Screen - AWS Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("TPWS Default Window Screen - TSO Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("TPWS Default Window Screen - BR Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request TPWS Default Window Screen SPAD Button Pressed", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request TPWS Default Window Screen OSS Button Pressed", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request TPWS Default Window Screen AWS Button Pressed", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request TPWS Default Window Screen TSO Button Pressed", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request TPWS Default Window Screen BR Button Pressed", 0.5, 0.0),
        Sim::Info<Sim::Number>("CBTC Default Window Screen - CBTC Mode Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("CBTC Default Window Screen - Doors Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Reversal Operation Indicator Pressed", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Window Screen - Start Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Window Screen - DriverID Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Window Screen - TrainData Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Window Screen - Level Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Window Screen - Train Running Number Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Window Screen - Shunting Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Window Screen - Non Leading Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Window Screen - Maintain Shunting Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Window Screen - Close Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Window Screen - Blank Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Window Screen - Request Close Button Pressed", 0.5, 0.0),
        Sim::Info<Sim::Number>("Main Window Screen - Request Shunting Button Pressed", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Start Button Pressed", 0.5, 0.0),
        Sim::Info<Sim::Number>("DriverId Screen - Setting Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("DriverId Screen - Train Running Number Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("DriverId Screen - Close Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("DriverId Screen Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("TrainData Screen - Close Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("TrainData Screen - Type1 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("TrainData Screen - Type2 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("TrainData Screen - Type3 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("TrainData Screen - Confirm Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("TrainData Screen Input Field Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Type Button Pressed", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Yes Button Pressed", 0.5, 0.0),
        Sim::Info<Sim::Number>("TrainData Validation Screen - Type1 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("TrainData Validation Screen - Type2 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("TrainData Validation Screen - Type3 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("TrainData Validation Screen - Yes Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("TrainData Validation Screen - No Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("TrainData Validation Screen - Enter data Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("TrainData Validation Screen - Confirm Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("TrainData Validation Screen Input Field Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request TrainData Validation Yes Button Pressed", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request TrainData Validation No Button Pressed", 0.5, 0.0),
        Sim::Info<Sim::Number>("Level Screen - Close Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Level Screen - Level1 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Level Screen - Level2 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Level Screen - Level0 Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Level Screen - TPWS Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Level Screen - CBTC Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Level Screen - CBTC SA Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Level Screen Button Pressed", 0.5, -1),
        Sim::Info<Sim::Number>("Request NTC Level Screen Button Pressed", 0.5, 0),
        Sim::Info<Sim::Number>("Request CBTC SA Level Screen Button Pressed", 0.5, 0),
        Sim::Info<Sim::Number>("Level Screen - Close Button Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("TRN Screen - Close Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("TRN Screen Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("TRN Screen - Close Button Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Passenger Service TRN Screen - Close Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Passenger Service TRN Screen Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Passenger Service TRN Screen - NA Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Passenger Service TRN Screen - Close Button Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Keypad - Button 0", 0.5, 0.0),
        Sim::Info<Sim::Number>("Keypad - Button 1", 0.5, 0.0),
        Sim::Info<Sim::Number>("Keypad - Button 2", 0.5, 0.0),
        Sim::Info<Sim::Number>("Keypad - Button 3", 0.5, 0.0),
        Sim::Info<Sim::Number>("Keypad - Button 4", 0.5, 0.0),
        Sim::Info<Sim::Number>("Keypad - Button 5", 0.5, 0.0),
        Sim::Info<Sim::Number>("Keypad - Button 6", 0.5, 0.0),
        Sim::Info<Sim::Number>("Keypad - Button 7", 0.5, 0.0),
        Sim::Info<Sim::Number>("Keypad - Button 8", 0.5, 0.0),
        Sim::Info<Sim::Number>("Keypad - Button 9", 0.5, 0.0),
        Sim::Info<Sim::Number>("Keypad - Button Delete", 0.5, 0.0),
        Sim::Info<Sim::Number>("Keypad - Button Input Mode", 0.5, 0.0),
        Sim::Info<Sim::Number>("Keypad - Button Dot", 0.5, 0.0),
        Sim::Info<Sim::Number>("Keypad - Button Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("SETTING Screen - Language Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("SETTING Screen - Volume Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("SETTING Screen - Brightness Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("SETTING Screen - Version Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("SETTING Screen - SetVBC Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("SETTING Screen - RemoveVBC Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("SETTING Screen - Switch Screen Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("SETTING Screen - Switch Screen Button Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("SETTING Screen - Close Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("SETTING Screen - Close Button Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Text Message - Up Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Text Message - Down Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request First Text Message Index ", 0.5, -1),
        Sim::Info<Sim::Number>("Text Message Acknowledged", 0.5, 0.0),
        Sim::Info<Sim::Number>("Text Message - Ack Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Text Message - Nack Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Ack Nack", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Mode Screen - Close Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Mode Screen - Close Button Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Mode Screen Change Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Mode Screen - Button MOMC", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Mode Screen - Button AOAC", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Mode Screen - Button AOMC", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Mode Screen - Button MOAC", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Mode Screen - Button Door Supervision", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Mode Screen - Button Cancel Door Supervision", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Mode Screen - Button Enforce Door Release Left", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Mode Screen - Button Cancel Enforce Door Release Left", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Mode Screen - Button Enforce Door Release Both", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Mode Screen - Button Cancel Enforce Door Release Both", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Mode Screen - Button Enforce Door Release Right", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Mode Screen - Button Cancel Enforce Door Release Right", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Mode Screen - Door Mode Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Mode Screen - Door Supervision Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Mode Screen - Left Door State Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Mode Screen - Both Door State Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Door Mode Screen - Right Door State Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("CBTC Mode Menu Screen - AM Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("CBTC Mode Menu Screen - PM Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("CBTC Mode Menu Screen - SA Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("CBTC Mode Menu Screen - Close Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("CBTC Mode Menu Screen Change Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("CBTC Mode Menu Screen - CBTC Mode Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("CBTC Mode Menu Screen - Close Button Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Scale Up", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Scale Down", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Hide Show Button Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Track Ahead Ack", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Mode Acknowledged", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Level Acknowledged", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Driver Requested Level", 0.5, -1),
        Sim::Info<Sim::Number>("ETCS Driver Requested NTC Level", 0.5, -1),
        Sim::Info<Sim::Number>("ETCS EOA Override Button", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS EOA Override Request", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Adhesion Input", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS SR Distance", 0.1, 0),
        Sim::Info<Sim::Number>("ETCS SR Speed", 0.1, 0),
        Sim::Info<Sim::Number>("ETCS Special Screen - Train Integrity Button", 0.1, 0),
        Sim::Info<Sim::Number>("ETCS Special Screen - Close Button", 0.1, 0),
        Sim::Info<Sim::Number>("ETCS Special Screen - Close Button Request", 0.1, 0),
        Sim::Info<Sim::Number>("ETCS Tunnel Stopping Area Toggled Status Requested", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Start Of Mission Request", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Brake Intervention Acknowledged", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Geographical Position Label Request", 0.5, -1),
        Sim::Info<Sim::Number>("ETCS Adhesion Screen - Close Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Adhesion Screen - Non Slippery Rail Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Adhesion Screen - Slippery Rail Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Adhesion Screen Input Field Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request ETCS Adhesion Screen Button Pressed", 0.5, -1),
        Sim::Info<Sim::Number>("ETCS Adhesion Screen - Close Button Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Data View Screen - Close Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Data View Screen - Prev Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Data View Screen - Next Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Data View Screen - Current Page Request", 0.5, -1),
        Sim::Info<Sim::Number>("ETCS SR Screen Speed Input Field Request", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS SR Screen Distance Input Field Request", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS SR Screen Confirm Button Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS SR Screen Confirm Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Remove VBC Screen Confirm Button Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Remove VBC Screen Confirm Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Remove VBC Screen Close Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Remove VBC Validation Screen Yes Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Remove VBC Validation Screen No Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Remove VBC Validation Yes Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Remove VBC Validation No Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Remove VBC Validation Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Set VBC Screen Confirm Button Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Set VBC Screen Confirm Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Set VBC Screen Close Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Set VBC Validation Screen Yes Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Set VBC Validation Screen No Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Set VBC Validation Yes Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Set VBC Validation No Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Set VBC Validation Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS RBC Screen - Contact Last RBC Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS RBC Screen - User Short Number Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS RBC Screen - Enter RBC Data Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS RBC Screen - Radio Network ID Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS RBC Screen - Close Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS RBC Screen Contact Last RBC Button Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS RBC Screen User Short Number Button Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS RBC Screen Enter RBC Data Button Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS RBC Screen Radio Network ID Button Pressed Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS RBC Screen Radio Network ID Button Released Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Radio Network ID Screen - Close Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Radio Network ID Screen Input Field Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Radio Network ID Screen Button Pressed Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS RBC Data Screen - ID Input Field Request", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS RBC Data Screen - Phone Input Field Request", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS RBC Data Screen - Confirm Button Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS RBC Data Screen - Confirm Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS RBC Data Screen - Close Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS System Version Screen - Close Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS System Version Screen - Close Button Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Panel A B Toggle Request", 0.5, 0.0),
        Sim::Info<Sim::Number>("ETCS Reset Screen - Setting Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Active Event - Acknowledge Button", 0.5, 0.0),
        Sim::Info<Sim::Number>("Request Active Event Acknowledge", 0.5, 0.0),
    };
    const size_t DMI_INPUTS_MODES_NUMBERS_SIZE = sizeof(DMI_INPUTS_MODES_NUMBERS)/sizeof(DMI_INPUTS_MODES_NUMBERS[0]);
    const TagInfo *DMI_INPUTS_MODES_TAGS = 0;
    const size_t DMI_INPUTS_MODES_TAGS_SIZE = 0;
    const IdentifierInfo *DMI_INPUTS_MODES_IDENTIFIERS = 0;
    const size_t DMI_INPUTS_MODES_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *DMI_INPUTS_MODES_CONSTANTS = 0;
    const size_t DMI_INPUTS_MODES_CONSTANTS_SIZE = 0;
    const SpecificationInfo *DMI_INPUTS_MODES_SPECIFICATIONS = 0;
    const size_t DMI_INPUTS_MODES_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *DMI_INPUTS_MODES_RAWS = 0;
    const size_t DMI_INPUTS_MODES_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *DMI_INPUTS_MODES_TRAYS = 0;
    const size_t DMI_INPUTS_MODES_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> DMI_VEHICLE_INPUTS_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 425),
        Sim::Info<Sim::Number>("Merge TCMS To DMI Request", 0.5, 0),
        Sim::Info<Sim::Number>("Request Text Area Acknowledgement", 0.5, 0),
        Sim::Info<Sim::Number>("CBTC Ack Message On Display", 0.5, 1),
        Sim::Info<Sim::Number>("Train Type", 0.5, 1),
        Sim::Info<Sim::Number>("Start Of Mission Complete", 0.5, 0),
        Sim::Info<Sim::Number>("TPWS SPAD Button", 0.5, 0),
        Sim::Info<Sim::Number>("TPWS Overspeed Button", 0.5, 0),
        Sim::Info<Sim::Number>("TPWS AWS Button", 0.5, 0),
        Sim::Info<Sim::Number>("TPWS Train Stop Override Button", 0.5, 0),
        Sim::Info<Sim::Number>("TPWS Brake Release", 0.5, 0),
        Sim::Info<Sim::Number>("Request CBTC Door Mode", 0.5, 0),
        Sim::Info<Sim::Number>("Request CBTC Door Supervision", 0.5, 0),
        Sim::Info<Sim::Number>("Request CBTC Enforce Left Door Release State", 0.5, 0),
        Sim::Info<Sim::Number>("Request CBTC Enforce Right Door Release State", 0.5, 0),
        Sim::Info<Sim::Number>("Request CBTC Enforce Both Door Release State", 0.5, 0),
        Sim::Info<Sim::Number>("New Driver ID", 0.5, 0),
        Sim::Info<Sim::Number>("Planned ECS Move", 0.5, 0),
        Sim::Info<Sim::Number>("Request CBTC Mode", 0.5, 0),
        Sim::Info<Sim::Number>("Request CBTC Reversal", 0.5, 0),
        Sim::Info<Sim::Number>("CBTC Previous Mode", 0.5, 0),
        Sim::Info<Sim::Number>("CBTC Previous AR Mode", 0.5, 0),
    };
    const size_t DMI_VEHICLE_INPUTS_NUMBERS_SIZE = sizeof(DMI_VEHICLE_INPUTS_NUMBERS)/sizeof(DMI_VEHICLE_INPUTS_NUMBERS[0]);
    const TagInfo *DMI_VEHICLE_INPUTS_TAGS = 0;
    const size_t DMI_VEHICLE_INPUTS_TAGS_SIZE = 0;
    const IdentifierInfo *DMI_VEHICLE_INPUTS_IDENTIFIERS = 0;
    const size_t DMI_VEHICLE_INPUTS_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *DMI_VEHICLE_INPUTS_CONSTANTS = 0;
    const size_t DMI_VEHICLE_INPUTS_CONSTANTS_SIZE = 0;
    const SpecificationInfo *DMI_VEHICLE_INPUTS_SPECIFICATIONS = 0;
    const size_t DMI_VEHICLE_INPUTS_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *DMI_VEHICLE_INPUTS_RAWS = 0;
    const size_t DMI_VEHICLE_INPUTS_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *DMI_VEHICLE_INPUTS_TRAYS = 0;
    const size_t DMI_VEHICLE_INPUTS_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> DMI_VEHICLE_OUTPUTS_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 426),
        Sim::Info<Sim::Number>("Speedometer Failure", 0.5, 0),
        Sim::Info<Sim::Number>("SIG Redundancy State", 0.5, 0),
        Sim::Info<Sim::Number>("DMI Touch Screen Failure", 0.5, 0),
        Sim::Info<Sim::Number>("Train Speed Above 1 Kph", 0.5, 0),
        Sim::Info<Sim::Number>("Signalling Acknowledge PB", 0.5, 0),
        Sim::Info<Sim::Number>("DMI Power", 0.5, 0),
        Sim::Info<Sim::Number>("Cab Active", 0.5, 0),
        Sim::Info<Sim::Number>("DMI Cab Display Status", 0.5, 0),
        Sim::Info<Sim::Number>("MCS Position", 0.5, -1),
        Sim::Info<Sim::Number>("TPWS SPAD Light", 0.5, 0),
        Sim::Info<Sim::Number>("TPWS Overspeed Light", 0.5, 0),
        Sim::Info<Sim::Number>("TPWS AWS Light", 0.5, 0),
        Sim::Info<Sim::Number>("TPWS Brake Release Light", 0.5, 0),
        Sim::Info<Sim::Number>("Temporary Isolation Fault Indicator", 0.5, 0),
        Sim::Info<Sim::Number>("AWS Warning Display", 0.5, 0),
        Sim::Info<Sim::Number>("TPWS Train Stop Override Light", 0.5, 0),
        Sim::Info<Sim::Number>("TPWS SPAD Emergency Brake Demand", 0.5, 0),
        Sim::Info<Sim::Number>("TPWS OSS Emergency Brake Demand", 0.5, 0),
        Sim::Info<Sim::Number>("TPWS AWS Emergency Brake Demand", 0.5, 0),
        Sim::Info<Sim::Number>("TPWS Brake Release Action Allowed", 0.5, 0),
        Sim::Info<Sim::Number>("Emergency Brake Applied", 0.5, 0),
        Sim::Info<Sim::Number>("AWS Isolation", 0.5, 0),
        Sim::Info<Sim::Number>("TPWS Temporary Isolation", 0.5, 0),
        Sim::Info<Sim::Number>("AWS Fault", 0.5, 0),
        Sim::Info<Sim::Number>("TPWS Fault", 0.5, 0),
        Sim::Info<Sim::Number>("Brake Test In Progress", 0.5, 0),
        Sim::Info<Sim::Number>("Das Recommended Speed", 0.5, 0),
        Sim::Info<Sim::Number>("Das Coast Indicator", 0.5, 0),
        Sim::Info<Sim::Number>("Das Manual Suppressed", 0.5, 0),
        Sim::Info<Sim::Number>("Das Auto Suppressed", 0.5, 1),
        Sim::Info<Sim::Number>("CBTC Monitoring Mode", 0.5, 0),
        Sim::Info<Sim::Number>("CBTC Indication Speed", 0.01, 0),
        Sim::Info<Sim::Number>("CBTC Recommended Speed", 0.01, 0),
        Sim::Info<Sim::Number>("CBTC Warning Speed", 0.01, 0),
        Sim::Info<Sim::Number>("CBTC Intervention Speed", 0.01, 0),
        Sim::Info<Sim::Number>("CBTC Emergency Brake Speed", 0.01, 0),
        Sim::Info<Sim::Number>("CBTC Target Index", 0.5, 0),
        Sim::Info<Sim::Number>("CBTC Target Speed", 0.01, 0),
        Sim::Info<Sim::Number>("CBTC Target Distance", 0.1, 0),
        Sim::Info<Sim::Number>("CBTC Left Door Status", 0.5, 0),
        Sim::Info<Sim::Number>("CBTC Right Door Status", 0.5, 0),
        Sim::Info<Sim::Number>("CBTC Mission Control Status", 0.5, 0),
        Sim::Info<Sim::Number>("CBTC Current Mode", 0.5, 0),
        Sim::Info<Sim::Number>("CBTC Reversal Indication", 0.5, 0),
        Sim::Info<Sim::Number>("CBTC Stopping Accuracy", 0.5, 0),
        Sim::Info<Sim::Number>("CBTC PSDS State", 0.5, 0),
        Sim::Info<Sim::Number>("CBTC PSD Fault Active Debug", 0.5, 0),
        Sim::Info<Sim::Number>("CBTC Target Dwell Time", 0.5, 0),
        Sim::Info<Sim::Number>("CBTC Radio Errors", 0.5, 0),
        Sim::Info<Sim::Number>("CBTC Door Mode Status", 0.5, 0),
        Sim::Info<Sim::Number>("CBTC Delocalised", 0.5, 1),
        Sim::Info<Sim::Number>("CBTC Departure Request", 0.5, 0),
        Sim::Info<Sim::Number>("CBTC Door Supervision Request State", 0.5, 0),
        Sim::Info<Sim::Number>("CBTC Highest Available Mode", 0.5, 0),
        Sim::Info<Sim::Number>("CBTC Message ID", 0.5, 0),
        Sim::Info<Sim::Number>("Auto Power On Signalling State", 0.5, 0),
        Sim::Info<Sim::Number>("CBTC In Region", 0.5, 0),
        Sim::Info<Sim::Number>("CBTC Emergency Brake Active", 0.5, 0),
        Sim::Info<Sim::Number>("CBTC Auto Reverse In Progress", 0.5, 0),
        Sim::Info<Sim::Number>("CBTC Auto Reverse Finished", 0.5, 0),
        Sim::Info<Sim::Number>("CBTC Enforce Left Door Release State", 0.5, 0),
        Sim::Info<Sim::Number>("CBTC Enforce Right Door Release State", 0.5, 0),
        Sim::Info<Sim::Number>("CBTC Enforce Both Door Release State", 0.5, 0),
        Sim::Info<Sim::Number>("CBTC Standalone Available", 0.5, 0),
        Sim::Info<Sim::Number>("CBTC ATO Active", 0.5, 0),
    };
    const size_t DMI_VEHICLE_OUTPUTS_NUMBERS_SIZE = sizeof(DMI_VEHICLE_OUTPUTS_NUMBERS)/sizeof(DMI_VEHICLE_OUTPUTS_NUMBERS[0]);
    const TagInfo *DMI_VEHICLE_OUTPUTS_TAGS = 0;
    const size_t DMI_VEHICLE_OUTPUTS_TAGS_SIZE = 0;
    const IdentifierInfo *DMI_VEHICLE_OUTPUTS_IDENTIFIERS = 0;
    const size_t DMI_VEHICLE_OUTPUTS_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *DMI_VEHICLE_OUTPUTS_CONSTANTS = 0;
    const size_t DMI_VEHICLE_OUTPUTS_CONSTANTS_SIZE = 0;
    const SpecificationInfo *DMI_VEHICLE_OUTPUTS_SPECIFICATIONS = 0;
    const size_t DMI_VEHICLE_OUTPUTS_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *DMI_VEHICLE_OUTPUTS_RAWS = 0;
    const size_t DMI_VEHICLE_OUTPUTS_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *DMI_VEHICLE_OUTPUTS_TRAYS = 0;
    const size_t DMI_VEHICLE_OUTPUTS_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> DOO_VEHICLE_OUTPUTS_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 427),
        Sim::Info<Sim::Number>("CCTV Monitor Switchover", 0.5, 1),
        Sim::Info<Sim::Number>("Cab Active", 0.5, 0),
        Sim::Info<Sim::Number>("DOO Control Power Supply", 0.5, 0),
        Sim::Info<Sim::Number>("LHS Monitor Power Supply", 0.5, 0),
        Sim::Info<Sim::Number>("RHS Monitor Power Supply", 0.5, 0),
        Sim::Info<Sim::Number>("LHS Doors Release", 0.5, 0),
        Sim::Info<Sim::Number>("RHS Doors Release", 0.5, 0),
    };
    const size_t DOO_VEHICLE_OUTPUTS_NUMBERS_SIZE = sizeof(DOO_VEHICLE_OUTPUTS_NUMBERS)/sizeof(DOO_VEHICLE_OUTPUTS_NUMBERS[0]);
    const TagInfo *DOO_VEHICLE_OUTPUTS_TAGS = 0;
    const size_t DOO_VEHICLE_OUTPUTS_TAGS_SIZE = 0;
    const IdentifierInfo *DOO_VEHICLE_OUTPUTS_IDENTIFIERS = 0;
    const size_t DOO_VEHICLE_OUTPUTS_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *DOO_VEHICLE_OUTPUTS_CONSTANTS = 0;
    const size_t DOO_VEHICLE_OUTPUTS_CONSTANTS_SIZE = 0;
    const SpecificationInfo *DOO_VEHICLE_OUTPUTS_SPECIFICATIONS = 0;
    const size_t DOO_VEHICLE_OUTPUTS_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *DOO_VEHICLE_OUTPUTS_RAWS = 0;
    const size_t DOO_VEHICLE_OUTPUTS_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *DOO_VEHICLE_OUTPUTS_TRAYS = 0;
    const size_t DOO_VEHICLE_OUTPUTS_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> CBTC_TRAIN_INPUTS_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 1002),
        Sim::Info<Sim::Number>("In CBTC Region", 0.5, -1),
        Sim::Info<Sim::Number>("CTC Mode Active", 0.5, 0),
        Sim::Info<Sim::Number>("Train Docked", 0.5, 0),
        Sim::Info<Sim::Number>("Max Dwell Time", 0.5, 0),
        Sim::Info<Sim::Number>("Platform Door State", 0.5, 0),
        Sim::Info<Sim::Number>("Hold At Station", 0.5, 0),
        Sim::Info<Sim::Number>("Platform Nearby", 0.5, 0),
        Sim::Info<Sim::Number>("Platform Doors Present", 0.5, 0),
        Sim::Info<Sim::Number>("PSD Panel Enabled", 0.5, 0),
        Sim::Info<Sim::Number>("PSD Doors Closed Locked", 0.5, 1),
        Sim::Info<Sim::Number>("PSD Fault", 0.5, 0),
        Sim::Info<Sim::Number>("PSD Open Delay", 0.01, 1.2),
        Sim::Info<Sim::Number>("PSD Close Delay", 0.01, 1.7),
        Sim::Info<Sim::Number>("Mission Control Status", 0.5, 0),
        Sim::Info<Sim::Number>("Stopping Accuracy", 0.5, 0),
        Sim::Info<Sim::Number>("LMA Ahead OSP Distance", 0.1, -1),
        Sim::Info<Sim::Number>("LMA Ahead POP Distance", 0.1, -1),
        Sim::Info<Sim::Number>("LMA Ahead Type", 0.1, -1),
        Sim::Info<Sim::Number>("LMA Behind OSP Distance", 0.1, -1),
        Sim::Info<Sim::Number>("LMA Behind POP Distance", 0.1, -1),
        Sim::Info<Sim::Number>("LMA Behind Type", 0.1, -1),
        Sim::Info<Sim::Number>("LMA POS OSP Distance", 0.1, -1),
        Sim::Info<Sim::Number>("LMA POS POP Distance", 0.1, -1),
        Sim::Info<Sim::Number>("LMA POS Type", 0.1, -1),
        Sim::Info<Sim::Number>("Available AR Mode", 0.5, 0),
        Sim::Info<Sim::Number>("Speed Profile Direction", 0.5, 0),
        Sim::Info<Sim::Number>("Onsight Mode Available", 0.5, 0),
        Sim::Info<Sim::Number>("Balise PM Transition", 0.5, 0),
        Sim::Info<Sim::Number>("Balise Position Report", 0.5, 0),
        Sim::Info<Sim::Number>("Balise ATO Inhibit", 0.5, 0),
        Sim::Info<Sim::Number>("CBTC Traction P", 0.05, 50),
        Sim::Info<Sim::Number>("CBTC Traction I", 0.05, 0.1),
        Sim::Info<Sim::Number>("CBTC Traction D", 0.05, 0),
        Sim::Info<Sim::Number>("CBTC Brake P", 0.05, 40),
        Sim::Info<Sim::Number>("CBTC Brake I", 0.05, 2),
        Sim::Info<Sim::Number>("CBTC Brake D", 0.05, 0),
    };
    const size_t CBTC_TRAIN_INPUTS_NUMBERS_SIZE = sizeof(CBTC_TRAIN_INPUTS_NUMBERS)/sizeof(CBTC_TRAIN_INPUTS_NUMBERS[0]);
    const TagInfo *CBTC_TRAIN_INPUTS_TAGS = 0;
    const size_t CBTC_TRAIN_INPUTS_TAGS_SIZE = 0;
    const IdentifierInfo *CBTC_TRAIN_INPUTS_IDENTIFIERS = 0;
    const size_t CBTC_TRAIN_INPUTS_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *CBTC_TRAIN_INPUTS_CONSTANTS = 0;
    const size_t CBTC_TRAIN_INPUTS_CONSTANTS_SIZE = 0;
    const SpecificationInfo *CBTC_TRAIN_INPUTS_SPECIFICATIONS = 0;
    const size_t CBTC_TRAIN_INPUTS_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *CBTC_TRAIN_INPUTS_RAWS = 0;
    const size_t CBTC_TRAIN_INPUTS_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *CBTC_TRAIN_INPUTS_TRAYS = 0;
    const size_t CBTC_TRAIN_INPUTS_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> ATP_PROFILE_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 1005),
        Sim::Info<Sim::Number>("Index", 0.5, 0.0),
        Sim::Info<Sim::Number>("ATP Speed", 0.5, 0.0),
        Sim::Info<Sim::Number>("ATP Distance", 0.5, 0.0),
    };
    const size_t ATP_PROFILE_NUMBERS_SIZE = sizeof(ATP_PROFILE_NUMBERS)/sizeof(ATP_PROFILE_NUMBERS[0]);
    const TagInfo *ATP_PROFILE_TAGS = 0;
    const size_t ATP_PROFILE_TAGS_SIZE = 0;
    const IdentifierInfo *ATP_PROFILE_IDENTIFIERS = 0;
    const size_t ATP_PROFILE_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *ATP_PROFILE_CONSTANTS = 0;
    const size_t ATP_PROFILE_CONSTANTS_SIZE = 0;
    const SpecificationInfo *ATP_PROFILE_SPECIFICATIONS = 0;
    const size_t ATP_PROFILE_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *ATP_PROFILE_RAWS = 0;
    const size_t ATP_PROFILE_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *ATP_PROFILE_TRAYS = 0;
    const size_t ATP_PROFILE_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> CBTC_TRAIN_OUTPUTS_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 1003),
        Sim::Info<Sim::Number>("Train Type", 0.5, 0),
        Sim::Info<Sim::Number>("CBTC Mode", 0.5, 0),
        Sim::Info<Sim::Number>("Auto Reverse Mode", 0.5, 0),
        Sim::Info<Sim::Number>("Train Localised", 0.5, 0),
        Sim::Info<Sim::Number>("Train Doors Closed And Locked", 0.5, 0),
        Sim::Info<Sim::Number>("PSD Open Request", 0.5, 0),
        Sim::Info<Sim::Number>("PSD Close Request", 0.5, 0),
        Sim::Info<Sim::Number>("Passenger Door Pairs Per Vehicle", 0.5, 0),
    };
    const size_t CBTC_TRAIN_OUTPUTS_NUMBERS_SIZE = sizeof(CBTC_TRAIN_OUTPUTS_NUMBERS)/sizeof(CBTC_TRAIN_OUTPUTS_NUMBERS[0]);
    const TagInfo *CBTC_TRAIN_OUTPUTS_TAGS = 0;
    const size_t CBTC_TRAIN_OUTPUTS_TAGS_SIZE = 0;
    const IdentifierInfo *CBTC_TRAIN_OUTPUTS_IDENTIFIERS = 0;
    const size_t CBTC_TRAIN_OUTPUTS_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *CBTC_TRAIN_OUTPUTS_CONSTANTS = 0;
    const size_t CBTC_TRAIN_OUTPUTS_CONSTANTS_SIZE = 0;
    const SpecificationInfo *CBTC_TRAIN_OUTPUTS_SPECIFICATIONS = 0;
    const size_t CBTC_TRAIN_OUTPUTS_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *CBTC_TRAIN_OUTPUTS_RAWS = 0;
    const size_t CBTC_TRAIN_OUTPUTS_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *CBTC_TRAIN_OUTPUTS_TRAYS = 0;
    const size_t CBTC_TRAIN_OUTPUTS_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> CBTC_VEHICLE_OUTPUTS_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 1004),
        Sim::Info<Sim::Number>("Door A Inhibited", 0.5, 0),
        Sim::Info<Sim::Number>("Door B Inhibited", 0.5, 0),
        Sim::Info<Sim::Number>("Door C Inhibited", 0.5, 0),
        Sim::Info<Sim::Number>("Door D Inhibited", 0.5, 0),
        Sim::Info<Sim::Number>("Door E Inhibited", 0.5, 0),
        Sim::Info<Sim::Number>("Door F Inhibited", 0.5, 0),
        Sim::Info<Sim::Number>("Orientation", 0.5, 0),
    };
    const size_t CBTC_VEHICLE_OUTPUTS_NUMBERS_SIZE = sizeof(CBTC_VEHICLE_OUTPUTS_NUMBERS)/sizeof(CBTC_VEHICLE_OUTPUTS_NUMBERS[0]);
    const TagInfo *CBTC_VEHICLE_OUTPUTS_TAGS = 0;
    const size_t CBTC_VEHICLE_OUTPUTS_TAGS_SIZE = 0;
    const IdentifierInfo *CBTC_VEHICLE_OUTPUTS_IDENTIFIERS = 0;
    const size_t CBTC_VEHICLE_OUTPUTS_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *CBTC_VEHICLE_OUTPUTS_CONSTANTS = 0;
    const size_t CBTC_VEHICLE_OUTPUTS_CONSTANTS_SIZE = 0;
    const SpecificationInfo *CBTC_VEHICLE_OUTPUTS_SPECIFICATIONS = 0;
    const size_t CBTC_VEHICLE_OUTPUTS_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *CBTC_VEHICLE_OUTPUTS_RAWS = 0;
    const size_t CBTC_VEHICLE_OUTPUTS_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *CBTC_VEHICLE_OUTPUTS_TRAYS = 0;
    const size_t CBTC_VEHICLE_OUTPUTS_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> MODEL_DEBUG_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 1000),
        Sim::Info<Sim::Number>("Tractive Effort", 0.5, 0),
        Sim::Info<Sim::Number>("Dynamic Braking Effort", 0.5, 0),
        Sim::Info<Sim::Number>("Moving Force", 0.5, 0),
        Sim::Info<Sim::Number>("Rail Reaction Force", 0.5, 0),
        Sim::Info<Sim::Number>("Drag Force", 0.5, 0),
        Sim::Info<Sim::Number>("Gravitational Force", 0.5, 0),
        Sim::Info<Sim::Number>("Wheel Driving Force", 0.5, 0),
        Sim::Info<Sim::Number>("Wheel Force Transmitted", 0.5, 0),
        Sim::Info<Sim::Number>("Wheel Braking Force", 0.5, 0),
        Sim::Info<Sim::Number>("Wheel Lateral Friction Force", 0.5, 0),
        Sim::Info<Sim::Number>("Wheel Skid", 0.5, 0),
        Sim::Info<Sim::Number>("Wheel Spin", 0.5, 0),
        Sim::Info<Sim::Number>("ELEC Cab Occupied 1", 0.5, 0),
        Sim::Info<Sim::Number>("ELEC TPWS Brake Release", 0.5, 0),
        Sim::Info<Sim::Number>("ELEC CBTC Brake Release", 0.5, 0),
        Sim::Info<Sim::Number>("ELEC ETCS Brake Release", 0.5, 0),
        Sim::Info<Sim::Number>("ELEC Passenger Alarm Vehicle", 0.5, 0),
        Sim::Info<Sim::Number>("ELEC Passenger Alarm Train", 0.5, 0),
        Sim::Info<Sim::Number>("ELEC Passenger Alarm Brake Release", 0.5, 0),
        Sim::Info<Sim::Number>("ELEC Passenger Alarm Brake Release Timer", 0.5, 0),
        Sim::Info<Sim::Number>("ELEC In Out Station", 0.5, 0),
        Sim::Info<Sim::Number>("ELEC Auto Reversal", 0.5, 0),
        Sim::Info<Sim::Number>("ELEC Door Interlock 1", 0.5, 0),
        Sim::Info<Sim::Number>("ELEC Other Cab Active", 0.5, 0),
        Sim::Info<Sim::Number>("ELEC CBTC Brake Holding", 0.5, 0),
        Sim::Info<Sim::Number>("ELEC CBTC ATO Active", 0.5, 0),
        Sim::Info<Sim::Number>("ELEC CBTC Data Available", 0.5, 0),
        Sim::Info<Sim::Number>("ELEC CBTC ATP Active", 0.5, 0),
        Sim::Info<Sim::Number>("ELEC CBTC Traction Permit", 0.5, 0),
        Sim::Info<Sim::Number>("ELEC ETCS Full Service Brake", 0.5, 0),
        Sim::Info<Sim::Number>("ELEC CBTC Full Service Brake", 0.5, 0),
        Sim::Info<Sim::Number>("ELEC Emergency Brake 1", 0.5, 0),
        Sim::Info<Sim::Number>("ELEC Brake Continuity", 0.5, 0),
        Sim::Info<Sim::Number>("ELEC Emergency Brake Release 1", 0.5, 0),
        Sim::Info<Sim::Number>("ELEC BCU Emergency Brake", 0.5, 0),
        Sim::Info<Sim::Number>("ELEC Trainwire Powering", 0.5, 0),
        Sim::Info<Sim::Number>("ELEC Trainwire Braking", 0.5, 0),
        Sim::Info<Sim::Number>("ELEC Trainwire Forward", 0.5, 0),
        Sim::Info<Sim::Number>("ELEC Trainwire Reverse", 0.5, 0),
        Sim::Info<Sim::Number>("ELEC Door Release Left CBTC", 0.5, 0),
        Sim::Info<Sim::Number>("ELEC Door Release Right CBTC", 0.5, 0),
        Sim::Info<Sim::Number>("ELEC Release Enable Left CBTC", 0.5, 0),
        Sim::Info<Sim::Number>("ELEC Release Enable Right CBTC", 0.5, 0),
        Sim::Info<Sim::Number>("ELEC Door Release Left", 0.5, 0),
        Sim::Info<Sim::Number>("ELEC Door Release Right", 0.5, 0),
        Sim::Info<Sim::Number>("ELEC Door Close Left", 0.5, 0),
        Sim::Info<Sim::Number>("ELEC Door Close Right", 0.5, 0),
        Sim::Info<Sim::Number>("ELEC Trainwire CBTC Protection Active", 0.5, 0),
        Sim::Info<Sim::Number>("ELEC Trainwire Door Release Right", 0.5, 0),
        Sim::Info<Sim::Number>("ELEC Trainwire Door Release Left", 0.5, 0),
        Sim::Info<Sim::Number>("ELEC Release Inhibit Left CBTC", 0.5, 0),
        Sim::Info<Sim::Number>("ELEC Release Inhibit Right CBTC", 0.5, 0),
        Sim::Info<Sim::Number>("CBTC Previous Mode From Model", 0.5, 0),
        Sim::Info<Sim::Number>("CBTC Auto Power On Active AR", 0.5, 0),
        Sim::Info<Sim::Number>("CBTC Valid DMI Previous AR Mode", 0.5, 0),
        Sim::Info<Sim::Number>("CBTC DMI Previous CBTC Mode", 0.5, 0),
        Sim::Info<Sim::Number>("CBTC Stateflow Message ID", 0.5, 0),
        Sim::Info<Sim::Number>("CBTC Stateflow CBTC Mode", 0.5, 0),
        Sim::Info<Sim::Number>("CBTC Stateflow In Ctc", 0.5, 0),
        Sim::Info<Sim::Number>("CBTC Stateflow CBTC Mode Ar", 0.5, 0),
        Sim::Info<Sim::Number>("CBTC Stateflow Autodrive Cond Met", 0.5, 0),
        Sim::Info<Sim::Number>("CBTC Stateflow Autodrive Enabled", 0.5, 0),
        Sim::Info<Sim::Number>("CBTC Levelmode Auto Reverse In Progress", 0.5, 0),
        Sim::Info<Sim::Number>("CBTC Levelmode Auto Reverse Finished", 0.5, 0),
        Sim::Info<Sim::Number>("CBTC ATO AR Cbtc Active", 0.5, 0),
        Sim::Info<Sim::Number>("CBTC ATO Cbtc Active", 0.5, 0),
        Sim::Info<Sim::Number>("CBTC ATO Demand", 0.5, 0),
        Sim::Info<Sim::Number>("CBTC ATO Start Light", 0.5, 0),
        Sim::Info<Sim::Number>("TCMS Pan Down", 0.5, 0),
        Sim::Info<Sim::Number>("TCMS Train Power Mode", 0.5, 0),
        Sim::Info<Sim::Number>("TCMS Trip Battery Relay", 0.5, 0),
        Sim::Info<Sim::Number>("TCMS Trip Battery System", 0.5, 0),
        Sim::Info<Sim::Number>("TCMS Pan Ready To Raised", 0.5, 0),
        Sim::Info<Sim::Number>("TCMS Active Cab Holdover", 0.5, 0),
        Sim::Info<Sim::Number>("ELEC TCMS Line Volatge", 0.5, 0),
        Sim::Info<Sim::Number>("ELEC TCMS Pan Status", 0.5, 0),
        Sim::Info<Sim::Number>("TCMS Remote Brake Release Enabled", 0.5, 0),
        Sim::Info<Sim::Number>("External Coupling", 0.5, 0),
        Sim::Info<Sim::Number>("AWS State", 0.5, 0),
        Sim::Info<Sim::Number>("TPWS State", 0.5, 0),
        Sim::Info<Sim::Number>("TPWS Indicator State", 0.5, 0),
        Sim::Info<Sim::Number>("APC Reset Fault At Entry", 0.5, 0),
        Sim::Info<Sim::Number>("APC Reset Fault At Exit", 0.5, 0),
        Sim::Info<Sim::Number>("APC VCB Close", 0.5, 0),
        Sim::Info<Sim::Number>("Head Mimic Acceleration", 0.0001, 0),
        Sim::Info<Sim::Number>("Head Mimic Acceleration Error", 0.0001, 0),
        Sim::Info<Sim::Number>("Head Mimic Velocity", 0.0001, 0),
        Sim::Info<Sim::Number>("Head Mimic Velocity Error", 0.0001, 0),
        Sim::Info<Sim::Number>("Head Mimic Position", 0.0001, 0),
        Sim::Info<Sim::Number>("Head Mimic Position Error", 0.0001, 0),
        Sim::Info<Sim::Number>("Head Mimic Total Mimic Force", 0.5, 0),
        Sim::Info<Sim::Number>("Head Mimic Drag Force", 0.5, 0),
        Sim::Info<Sim::Number>("Head Mimic Stopping Force", 0.5, 0),
        Sim::Info<Sim::Number>("Head Mimic Gravitational Force", 0.5, 0),
        Sim::Info<Sim::Number>("Head Mimic Couplers Force", 0.5, 0),
        Sim::Info<Sim::Number>("Head Mimic Motive Force", 0.5, 0),
    };
    const size_t MODEL_DEBUG_NUMBERS_SIZE = sizeof(MODEL_DEBUG_NUMBERS)/sizeof(MODEL_DEBUG_NUMBERS[0]);
    const TagInfo *MODEL_DEBUG_TAGS = 0;
    const size_t MODEL_DEBUG_TAGS_SIZE = 0;
    const IdentifierInfo *MODEL_DEBUG_IDENTIFIERS = 0;
    const size_t MODEL_DEBUG_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *MODEL_DEBUG_CONSTANTS = 0;
    const size_t MODEL_DEBUG_CONSTANTS_SIZE = 0;
    const SpecificationInfo *MODEL_DEBUG_SPECIFICATIONS = 0;
    const size_t MODEL_DEBUG_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *MODEL_DEBUG_RAWS = 0;
    const size_t MODEL_DEBUG_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *MODEL_DEBUG_TRAYS = 0;
    const size_t MODEL_DEBUG_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> CBTC_PLATFORM_INPUTS_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 801),
        Sim::Info<Sim::Number>("Manual PSD Open Request", 0.5, 0),
        Sim::Info<Sim::Number>("Manual PSD Close Request", 0.5, 0),
        Sim::Info<Sim::Number>("Local PSD Control Enabled", 0.5, 0),
        Sim::Info<Sim::Number>("LHS SD Open Inhibit Code", 0.5, 0),
        Sim::Info<Sim::Number>("LHS SD Close Inhibit Code", 0.5, 0),
        Sim::Info<Sim::Number>("RHS SD Open Inhibit Code", 0.5, 0),
        Sim::Info<Sim::Number>("RHS SD Close Inhibit Code", 0.5, 0),
        Sim::Info<Sim::Number>("Forced Door SD Inhibit Code", 0.5, 0),
        Sim::Info<Sim::Number>("PSD Open Fault", 0.5, 0),
        Sim::Info<Sim::Number>("PSD Close Fault", 0.5, 0),
        Sim::Info<Sim::Number>("Train Door Close Fault", 0.5, 0),
    };
    const size_t CBTC_PLATFORM_INPUTS_NUMBERS_SIZE = sizeof(CBTC_PLATFORM_INPUTS_NUMBERS)/sizeof(CBTC_PLATFORM_INPUTS_NUMBERS[0]);
    const TagInfo *CBTC_PLATFORM_INPUTS_TAGS = 0;
    const size_t CBTC_PLATFORM_INPUTS_TAGS_SIZE = 0;
    const IdentifierInfo *CBTC_PLATFORM_INPUTS_IDENTIFIERS = 0;
    const size_t CBTC_PLATFORM_INPUTS_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *CBTC_PLATFORM_INPUTS_CONSTANTS = 0;
    const size_t CBTC_PLATFORM_INPUTS_CONSTANTS_SIZE = 0;
    const SpecificationInfo *CBTC_PLATFORM_INPUTS_SPECIFICATIONS = 0;
    const size_t CBTC_PLATFORM_INPUTS_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *CBTC_PLATFORM_INPUTS_RAWS = 0;
    const size_t CBTC_PLATFORM_INPUTS_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *CBTC_PLATFORM_INPUTS_TRAYS = 0;
    const size_t CBTC_PLATFORM_INPUTS_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> LMA_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 802),
        Sim::Info<Sim::Number>("LMA Ahead OSP", 0.5, 0),
        Sim::Info<Sim::Number>("LMA Ahead POP", 0.5, 0),
        Sim::Info<Sim::Number>("LMA Ahead Type", 0.5, 0),
        Sim::Info<Sim::Number>("LMA Behind OSP", 0.5, 0),
        Sim::Info<Sim::Number>("LMA Behind POP", 0.5, 0),
        Sim::Info<Sim::Number>("LMA Behind Type", 0.5, 0),
        Sim::Info<Sim::Number>("LMA POS OSP", 0.5, 0),
        Sim::Info<Sim::Number>("LMA POS POP", 0.5, 0),
        Sim::Info<Sim::Number>("LMA POS Type", 0.5, 0),
        Sim::Info<Sim::Number>("Available AR Mode", 0.5, 0),
        Sim::Info<Sim::Number>("Selected AR Mode", 0.5, 0),
        Sim::Info<Sim::Number>("Onsight Mode Available", 0.5, 0),
        Sim::Info<Sim::Number>("ETCS Level 1 MA", 0.5, -1),
        Sim::Info<Sim::Number>("ETCS Level 2 MA", 0.5, -1),
    };
    const size_t LMA_NUMBERS_SIZE = sizeof(LMA_NUMBERS)/sizeof(LMA_NUMBERS[0]);
    const TagInfo *LMA_TAGS = 0;
    const size_t LMA_TAGS_SIZE = 0;
    const IdentifierInfo *LMA_IDENTIFIERS = 0;
    const size_t LMA_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *LMA_CONSTANTS = 0;
    const size_t LMA_CONSTANTS_SIZE = 0;
    const SpecificationInfo *LMA_SPECIFICATIONS = 0;
    const size_t LMA_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> LMA_RAWS[] =
    {
        Sim::Info<Sim::Raw>("ETCS Level 1 Section Ids"),
        Sim::Info<Sim::Raw>("ETCS Level 2 Section Ids"),
    };
    const size_t LMA_RAWS_SIZE = sizeof(LMA_RAWS)/sizeof(LMA_RAWS[0]);
    const Sim::Info<Sim::Tray> *LMA_TRAYS = 0;
    const size_t LMA_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> CBTC_SPEED_LIMIT_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 803),
        Sim::Info<Sim::Number>("Requested Profile Direction", 0.5, 0.0),
        Sim::Info<Sim::Number>("Profile Direction", 0.5, 0.0),
    };
    const size_t CBTC_SPEED_LIMIT_NUMBERS_SIZE = sizeof(CBTC_SPEED_LIMIT_NUMBERS)/sizeof(CBTC_SPEED_LIMIT_NUMBERS[0]);
    const TagInfo *CBTC_SPEED_LIMIT_TAGS = 0;
    const size_t CBTC_SPEED_LIMIT_TAGS_SIZE = 0;
    const IdentifierInfo *CBTC_SPEED_LIMIT_IDENTIFIERS = 0;
    const size_t CBTC_SPEED_LIMIT_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *CBTC_SPEED_LIMIT_CONSTANTS = 0;
    const size_t CBTC_SPEED_LIMIT_CONSTANTS_SIZE = 0;
    const SpecificationInfo *CBTC_SPEED_LIMIT_SPECIFICATIONS = 0;
    const size_t CBTC_SPEED_LIMIT_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> CBTC_SPEED_LIMIT_RAWS[] =
    {
        Sim::Info<Sim::Raw>("CBTC Speed Limit Profile"),
    };
    const size_t CBTC_SPEED_LIMIT_RAWS_SIZE = sizeof(CBTC_SPEED_LIMIT_RAWS)/sizeof(CBTC_SPEED_LIMIT_RAWS[0]);
    const Sim::Info<Sim::Tray> *CBTC_SPEED_LIMIT_TRAYS = 0;
    const size_t CBTC_SPEED_LIMIT_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> DUAL_CAB_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 10000),
        Sim::Info<Sim::Number>("State", 0.5, 0),
        Sim::Info<Sim::Number>("Classroom State", 0.5, 0),
    };
    const size_t DUAL_CAB_NUMBERS_SIZE = sizeof(DUAL_CAB_NUMBERS)/sizeof(DUAL_CAB_NUMBERS[0]);
    const TagInfo *DUAL_CAB_TAGS = 0;
    const size_t DUAL_CAB_TAGS_SIZE = 0;
    const IdentifierInfo *DUAL_CAB_IDENTIFIERS = 0;
    const size_t DUAL_CAB_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *DUAL_CAB_CONSTANTS = 0;
    const size_t DUAL_CAB_CONSTANTS_SIZE = 0;
    const SpecificationInfo *DUAL_CAB_SPECIFICATIONS = 0;
    const size_t DUAL_CAB_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *DUAL_CAB_RAWS = 0;
    const size_t DUAL_CAB_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *DUAL_CAB_TRAYS = 0;
    const size_t DUAL_CAB_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> DUAL_CAB_CONTROL_INPUTS_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 10001),
        Sim::Info<Sim::Number>("Cab Id", 0.5, 0),
        Sim::Info<Sim::Number>("Standalone Cab 1", 0.5, 0),
        Sim::Info<Sim::Number>("Standalone Cab 2", 0.5, 0),
        Sim::Info<Sim::Number>("Dual Cab 1", 0.5, 0),
        Sim::Info<Sim::Number>("Dual Cab 2", 0.5, 0),
        Sim::Info<Sim::Number>("Cab 1 Intercom Volume", 0.5, 0),
        Sim::Info<Sim::Number>("Cab 2 Intercom Volume", 0.5, 0),
        Sim::Info<Sim::Number>("Cab 1 Intercom", 0.5, 0),
        Sim::Info<Sim::Number>("Cab 2 Intercom", 0.5, 0),
        Sim::Info<Sim::Number>("Session Control Connect", 0.5, 0),
    };
    const size_t DUAL_CAB_CONTROL_INPUTS_NUMBERS_SIZE = sizeof(DUAL_CAB_CONTROL_INPUTS_NUMBERS)/sizeof(DUAL_CAB_CONTROL_INPUTS_NUMBERS[0]);
    const TagInfo *DUAL_CAB_CONTROL_INPUTS_TAGS = 0;
    const size_t DUAL_CAB_CONTROL_INPUTS_TAGS_SIZE = 0;
    const IdentifierInfo *DUAL_CAB_CONTROL_INPUTS_IDENTIFIERS = 0;
    const size_t DUAL_CAB_CONTROL_INPUTS_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *DUAL_CAB_CONTROL_INPUTS_CONSTANTS = 0;
    const size_t DUAL_CAB_CONTROL_INPUTS_CONSTANTS_SIZE = 0;
    const SpecificationInfo *DUAL_CAB_CONTROL_INPUTS_SPECIFICATIONS = 0;
    const size_t DUAL_CAB_CONTROL_INPUTS_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *DUAL_CAB_CONTROL_INPUTS_RAWS = 0;
    const size_t DUAL_CAB_CONTROL_INPUTS_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *DUAL_CAB_CONTROL_INPUTS_TRAYS = 0;
    const size_t DUAL_CAB_CONTROL_INPUTS_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> ETCS_RBC_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 2001),
        Sim::Info<Sim::Number>("Trigger SR Authorisation", 0.5, 0),
        Sim::Info<Sim::Number>("Trigger Movement Authority", 0.5, 0),
        Sim::Info<Sim::Number>("Trigger Mode Change", 0.5, 0),
        Sim::Info<Sim::Number>("Trigger Level One MA", 0.5, 0),
        Sim::Info<Sim::Number>("Disable Periodic Timer", 0.5, 0),
    };
    const size_t ETCS_RBC_NUMBERS_SIZE = sizeof(ETCS_RBC_NUMBERS)/sizeof(ETCS_RBC_NUMBERS[0]);
    const TagInfo *ETCS_RBC_TAGS = 0;
    const size_t ETCS_RBC_TAGS_SIZE = 0;
    const IdentifierInfo *ETCS_RBC_IDENTIFIERS = 0;
    const size_t ETCS_RBC_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *ETCS_RBC_CONSTANTS = 0;
    const size_t ETCS_RBC_CONSTANTS_SIZE = 0;
    const SpecificationInfo *ETCS_RBC_SPECIFICATIONS = 0;
    const size_t ETCS_RBC_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *ETCS_RBC_RAWS = 0;
    const size_t ETCS_RBC_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *ETCS_RBC_TRAYS = 0;
    const size_t ETCS_RBC_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> TRACK_EVENTS_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 2002),
    };
    const size_t TRACK_EVENTS_NUMBERS_SIZE = sizeof(TRACK_EVENTS_NUMBERS)/sizeof(TRACK_EVENTS_NUMBERS[0]);
    const TagInfo *TRACK_EVENTS_TAGS = 0;
    const size_t TRACK_EVENTS_TAGS_SIZE = 0;
    const IdentifierInfo *TRACK_EVENTS_IDENTIFIERS = 0;
    const size_t TRACK_EVENTS_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *TRACK_EVENTS_CONSTANTS = 0;
    const size_t TRACK_EVENTS_CONSTANTS_SIZE = 0;
    const SpecificationInfo *TRACK_EVENTS_SPECIFICATIONS = 0;
    const size_t TRACK_EVENTS_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> TRACK_EVENTS_RAWS[] =
    {
        Sim::Info<Sim::Raw>("Event Profile"),
    };
    const size_t TRACK_EVENTS_RAWS_SIZE = sizeof(TRACK_EVENTS_RAWS)/sizeof(TRACK_EVENTS_RAWS[0]);
    const Sim::Info<Sim::Tray> *TRACK_EVENTS_TRAYS = 0;
    const size_t TRACK_EVENTS_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> ETCS_TEXT_MESSAGES_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 2003),
    };
    const size_t ETCS_TEXT_MESSAGES_NUMBERS_SIZE = sizeof(ETCS_TEXT_MESSAGES_NUMBERS)/sizeof(ETCS_TEXT_MESSAGES_NUMBERS[0]);
    const TagInfo *ETCS_TEXT_MESSAGES_TAGS = 0;
    const size_t ETCS_TEXT_MESSAGES_TAGS_SIZE = 0;
    const IdentifierInfo *ETCS_TEXT_MESSAGES_IDENTIFIERS = 0;
    const size_t ETCS_TEXT_MESSAGES_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *ETCS_TEXT_MESSAGES_CONSTANTS = 0;
    const size_t ETCS_TEXT_MESSAGES_CONSTANTS_SIZE = 0;
    const SpecificationInfo *ETCS_TEXT_MESSAGES_SPECIFICATIONS = 0;
    const size_t ETCS_TEXT_MESSAGES_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> ETCS_TEXT_MESSAGES_RAWS[] =
    {
        Sim::Info<Sim::Raw>("Message"),
    };
    const size_t ETCS_TEXT_MESSAGES_RAWS_SIZE = sizeof(ETCS_TEXT_MESSAGES_RAWS)/sizeof(ETCS_TEXT_MESSAGES_RAWS[0]);
    const Sim::Info<Sim::Tray> *ETCS_TEXT_MESSAGES_TRAYS = 0;
    const size_t ETCS_TEXT_MESSAGES_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> GRADIENT_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 2004),
    };
    const size_t GRADIENT_NUMBERS_SIZE = sizeof(GRADIENT_NUMBERS)/sizeof(GRADIENT_NUMBERS[0]);
    const TagInfo *GRADIENT_TAGS = 0;
    const size_t GRADIENT_TAGS_SIZE = 0;
    const IdentifierInfo *GRADIENT_IDENTIFIERS = 0;
    const size_t GRADIENT_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *GRADIENT_CONSTANTS = 0;
    const size_t GRADIENT_CONSTANTS_SIZE = 0;
    const SpecificationInfo *GRADIENT_SPECIFICATIONS = 0;
    const size_t GRADIENT_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> GRADIENT_RAWS[] =
    {
        Sim::Info<Sim::Raw>("Gradient Profile"),
    };
    const size_t GRADIENT_RAWS_SIZE = sizeof(GRADIENT_RAWS)/sizeof(GRADIENT_RAWS[0]);
    const Sim::Info<Sim::Tray> *GRADIENT_TRAYS = 0;
    const size_t GRADIENT_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> INTERCOM_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 701),
    };
    const size_t INTERCOM_NUMBERS_SIZE = sizeof(INTERCOM_NUMBERS)/sizeof(INTERCOM_NUMBERS[0]);
    const TagInfo INTERCOM_TAGS[] =
    {
        { "Intercom" },
    };
    const size_t INTERCOM_TAGS_SIZE = sizeof(INTERCOM_TAGS)/sizeof(INTERCOM_TAGS[0]);
    const IdentifierInfo *INTERCOM_IDENTIFIERS = 0;
    const size_t INTERCOM_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *INTERCOM_CONSTANTS = 0;
    const size_t INTERCOM_CONSTANTS_SIZE = 0;
    const SpecificationInfo *INTERCOM_SPECIFICATIONS = 0;
    const size_t INTERCOM_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *INTERCOM_RAWS = 0;
    const size_t INTERCOM_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *INTERCOM_TRAYS = 0;
    const size_t INTERCOM_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> INTERCOM_INPUTS_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 702),
        Sim::Info<Sim::Number>("Power Supply", 0.5, 0),
        Sim::Info<Sim::Number>("Cab Active", 0.5, 0),
        Sim::Info<Sim::Number>("HU Radio Button", 0.5, 0),
        Sim::Info<Sim::Number>("HU Cab To Cab Button", 0.5, 0),
        Sim::Info<Sim::Number>("HU PA Button", 0.5, 0),
        Sim::Info<Sim::Number>("HU PEA CFA Button", 0.5, 0),
        Sim::Info<Sim::Number>("HU PTT", 0.5, 0),
        Sim::Info<Sim::Number>("HU Return Switch", 0.5, 0),
        Sim::Info<Sim::Number>("PEA Override Button", 0.5, 0),
        Sim::Info<Sim::Number>("PEA CFA Reset Switch", 0.5, 0),
        Sim::Info<Sim::Number>("PEA 1", 0.5, 0),
        Sim::Info<Sim::Number>("PEA 2", 0.5, 0),
        Sim::Info<Sim::Number>("PEA 3", 0.5, 0),
        Sim::Info<Sim::Number>("CFA 1", 0.5, 0),
        Sim::Info<Sim::Number>("CFA 2", 0.5, 0),
        Sim::Info<Sim::Number>("CFA 3", 0.5, 0),
        Sim::Info<Sim::Number>("CFA 4", 0.5, 0),
        Sim::Info<Sim::Number>("Request Select PEA_1", 0.5, 0),
        Sim::Info<Sim::Number>("Request Select PEA_2", 0.5, 0),
        Sim::Info<Sim::Number>("Request Select PEA_3", 0.5, 0),
        Sim::Info<Sim::Number>("Request Select CFA_1", 0.5, 0),
        Sim::Info<Sim::Number>("Request Select CFA_2", 0.5, 0),
        Sim::Info<Sim::Number>("Request Select CFA_3", 0.5, 0),
        Sim::Info<Sim::Number>("Request Select CFA_4", 0.5, 0),
    };
    const size_t INTERCOM_INPUTS_NUMBERS_SIZE = sizeof(INTERCOM_INPUTS_NUMBERS)/sizeof(INTERCOM_INPUTS_NUMBERS[0]);
    const TagInfo INTERCOM_INPUTS_TAGS[] =
    {
        { "Intercom Inputs" },
    };
    const size_t INTERCOM_INPUTS_TAGS_SIZE = sizeof(INTERCOM_INPUTS_TAGS)/sizeof(INTERCOM_INPUTS_TAGS[0]);
    const IdentifierInfo *INTERCOM_INPUTS_IDENTIFIERS = 0;
    const size_t INTERCOM_INPUTS_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *INTERCOM_INPUTS_CONSTANTS = 0;
    const size_t INTERCOM_INPUTS_CONSTANTS_SIZE = 0;
    const SpecificationInfo *INTERCOM_INPUTS_SPECIFICATIONS = 0;
    const size_t INTERCOM_INPUTS_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *INTERCOM_INPUTS_RAWS = 0;
    const size_t INTERCOM_INPUTS_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *INTERCOM_INPUTS_TRAYS = 0;
    const size_t INTERCOM_INPUTS_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> INTERCOM_OUTPUTS_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 703),
        Sim::Info<Sim::Number>("GSMR Handset Return State", 0.5, 1),
        Sim::Info<Sim::Number>("GSMR PTT State", 0.5, 0),
        Sim::Info<Sim::Number>("Handset Connection", 0.5, 0),
        Sim::Info<Sim::Number>("Handset Function", 0.5, 0),
        Sim::Info<Sim::Number>("Handset Function State", 0.5, 0),
        Sim::Info<Sim::Number>("Cab Audible Alarm", 0.5, 0),
        Sim::Info<Sim::Number>("Cab To Cab Alarm", 0.5, 0),
        Sim::Info<Sim::Number>("CFA Alarm", 0.5, 0),
        Sim::Info<Sim::Number>("Radio Button LED", 0.5, 0),
        Sim::Info<Sim::Number>("Cab To Cab Button LED", 0.5, 0),
        Sim::Info<Sim::Number>("PA Button LED", 0.5, 0),
        Sim::Info<Sim::Number>("PEA CFA Button LED", 0.5, 0),
        Sim::Info<Sim::Number>("PEA 1 Instruction Panel", 0.5, 0),
        Sim::Info<Sim::Number>("PEA 2 Instruction Panel", 0.5, 0),
        Sim::Info<Sim::Number>("PEA 3 Instruction Panel", 0.5, 0),
        Sim::Info<Sim::Number>("CFA 1 Instruction Panel", 0.5, 0),
        Sim::Info<Sim::Number>("CFA 2 Instruction Panel", 0.5, 0),
        Sim::Info<Sim::Number>("CFA 3 Instruction Panel", 0.5, 0),
        Sim::Info<Sim::Number>("CFA 4 Instruction Panel", 0.5, 0),
        Sim::Info<Sim::Number>("PEA 1 Audible Tone", 0.5, 0),
        Sim::Info<Sim::Number>("PEA 2 Audible Tone", 0.5, 0),
        Sim::Info<Sim::Number>("PEA 3 Audible Tone", 0.5, 0),
        Sim::Info<Sim::Number>("CFA 1 Audible Tone", 0.5, 0),
        Sim::Info<Sim::Number>("CFA 2 Audible Tone", 0.5, 0),
        Sim::Info<Sim::Number>("CFA 3 Audible Tone", 0.5, 0),
        Sim::Info<Sim::Number>("CFA 4 Audible Tone", 0.5, 0),
        Sim::Info<Sim::Number>("Handset Hook State", 0.5, 1),
        Sim::Info<Sim::Number>("PEA 1 Operated Status", 0.5, 0),
        Sim::Info<Sim::Number>("PEA 1 Acknowledged Status", 0.5, 0),
        Sim::Info<Sim::Number>("PEA 1 Selected Status", 0.5, 0),
        Sim::Info<Sim::Number>("PEA 1 Serviced Status", 0.5, 0),
        Sim::Info<Sim::Number>("PEA 2 Operated Status", 0.5, 0),
        Sim::Info<Sim::Number>("PEA 2 Acknowledged Status", 0.5, 0),
        Sim::Info<Sim::Number>("PEA 2 Selected Status", 0.5, 0),
        Sim::Info<Sim::Number>("PEA 2 Serviced Status", 0.5, 0),
        Sim::Info<Sim::Number>("PEA 3 Operated Status", 0.5, 0),
        Sim::Info<Sim::Number>("PEA 3 Acknowledged Status", 0.5, 0),
        Sim::Info<Sim::Number>("PEA 3 Selected Status", 0.5, 0),
        Sim::Info<Sim::Number>("PEA 3 Serviced Status", 0.5, 0),
        Sim::Info<Sim::Number>("CFA 1 Operated Status", 0.5, 0),
        Sim::Info<Sim::Number>("CFA 1 Acknowledged Status", 0.5, 0),
        Sim::Info<Sim::Number>("CFA 1 Selected Status", 0.5, 0),
        Sim::Info<Sim::Number>("CFA 1 Serviced Status", 0.5, 0),
        Sim::Info<Sim::Number>("CFA 2 Operated Status", 0.5, 0),
        Sim::Info<Sim::Number>("CFA 2 Acknowledged Status", 0.5, 0),
        Sim::Info<Sim::Number>("CFA 2 Selected Status", 0.5, 0),
        Sim::Info<Sim::Number>("CFA 2 Serviced Status", 0.5, 0),
        Sim::Info<Sim::Number>("CFA 3 Operated Status", 0.5, 0),
        Sim::Info<Sim::Number>("CFA 3 Acknowledged Status", 0.5, 0),
        Sim::Info<Sim::Number>("CFA 3 Selected Status", 0.5, 0),
        Sim::Info<Sim::Number>("CFA 3 Serviced Status", 0.5, 0),
        Sim::Info<Sim::Number>("CFA 4 Operated Status", 0.5, 0),
        Sim::Info<Sim::Number>("CFA 4 Acknowledged Status", 0.5, 0),
        Sim::Info<Sim::Number>("CFA 4 Selected Status", 0.5, 0),
        Sim::Info<Sim::Number>("CFA 4 Serviced Status", 0.5, 0),
    };
    const size_t INTERCOM_OUTPUTS_NUMBERS_SIZE = sizeof(INTERCOM_OUTPUTS_NUMBERS)/sizeof(INTERCOM_OUTPUTS_NUMBERS[0]);
    const TagInfo INTERCOM_OUTPUTS_TAGS[] =
    {
        { "Intercom Outputs" },
    };
    const size_t INTERCOM_OUTPUTS_TAGS_SIZE = sizeof(INTERCOM_OUTPUTS_TAGS)/sizeof(INTERCOM_OUTPUTS_TAGS[0]);
    const IdentifierInfo *INTERCOM_OUTPUTS_IDENTIFIERS = 0;
    const size_t INTERCOM_OUTPUTS_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *INTERCOM_OUTPUTS_CONSTANTS = 0;
    const size_t INTERCOM_OUTPUTS_CONSTANTS_SIZE = 0;
    const SpecificationInfo *INTERCOM_OUTPUTS_SPECIFICATIONS = 0;
    const size_t INTERCOM_OUTPUTS_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *INTERCOM_OUTPUTS_RAWS = 0;
    const size_t INTERCOM_OUTPUTS_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *INTERCOM_OUTPUTS_TRAYS = 0;
    const size_t INTERCOM_OUTPUTS_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> INTERCOM_VEHICLE_INPUTS_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 704),
        Sim::Info<Sim::Number>("Radio Button LED", 0.5, 0),
        Sim::Info<Sim::Number>("Cab To Cab Button LED", 0.5, 0),
        Sim::Info<Sim::Number>("PA Button LED", 0.5, 0),
        Sim::Info<Sim::Number>("PEA CFA Button LED", 0.5, 0),
        Sim::Info<Sim::Number>("PEA 1 Instruction Panel", 0.5, 0),
        Sim::Info<Sim::Number>("PEA 2 Instruction Panel", 0.5, 0),
        Sim::Info<Sim::Number>("PEA 3 Instruction Panel", 0.5, 0),
        Sim::Info<Sim::Number>("CFA 1 Instruction Panel", 0.5, 0),
        Sim::Info<Sim::Number>("CFA 2 Instruction Panel", 0.5, 0),
        Sim::Info<Sim::Number>("CFA 3 Instruction Panel", 0.5, 0),
        Sim::Info<Sim::Number>("CFA 4 Instruction Panel", 0.5, 0),
    };
    const size_t INTERCOM_VEHICLE_INPUTS_NUMBERS_SIZE = sizeof(INTERCOM_VEHICLE_INPUTS_NUMBERS)/sizeof(INTERCOM_VEHICLE_INPUTS_NUMBERS[0]);
    const TagInfo *INTERCOM_VEHICLE_INPUTS_TAGS = 0;
    const size_t INTERCOM_VEHICLE_INPUTS_TAGS_SIZE = 0;
    const IdentifierInfo *INTERCOM_VEHICLE_INPUTS_IDENTIFIERS = 0;
    const size_t INTERCOM_VEHICLE_INPUTS_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *INTERCOM_VEHICLE_INPUTS_CONSTANTS = 0;
    const size_t INTERCOM_VEHICLE_INPUTS_CONSTANTS_SIZE = 0;
    const SpecificationInfo *INTERCOM_VEHICLE_INPUTS_SPECIFICATIONS = 0;
    const size_t INTERCOM_VEHICLE_INPUTS_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *INTERCOM_VEHICLE_INPUTS_RAWS = 0;
    const size_t INTERCOM_VEHICLE_INPUTS_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *INTERCOM_VEHICLE_INPUTS_TRAYS = 0;
    const size_t INTERCOM_VEHICLE_INPUTS_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> INTERCOM_VEHICLE_OUTPUTS_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 705),
        Sim::Info<Sim::Number>("PEA CFA Reset", 0.5, 0),
        Sim::Info<Sim::Number>("Cab Active", 0.5, 0),
        Sim::Info<Sim::Number>("Power Supply", 0.5, 0),
        Sim::Info<Sim::Number>("HU Radio Button", 0.5, 0),
        Sim::Info<Sim::Number>("HU Cab To Cab Button", 0.5, 0),
        Sim::Info<Sim::Number>("HU PA Button", 0.5, 0),
        Sim::Info<Sim::Number>("HU PEA CFA Button", 0.5, 0),
        Sim::Info<Sim::Number>("HU PTT", 0.5, 0),
        Sim::Info<Sim::Number>("HU Return Switch", 0.5, 0),
        Sim::Info<Sim::Number>("PEA 1", 0.5, 0),
        Sim::Info<Sim::Number>("PEA 2", 0.5, 0),
        Sim::Info<Sim::Number>("PEA 3", 0.5, 0),
        Sim::Info<Sim::Number>("CFA 1", 0.5, 0),
        Sim::Info<Sim::Number>("CFA 2", 0.5, 0),
        Sim::Info<Sim::Number>("CFA 3", 0.5, 0),
        Sim::Info<Sim::Number>("CFA 4", 0.5, 0),
    };
    const size_t INTERCOM_VEHICLE_OUTPUTS_NUMBERS_SIZE = sizeof(INTERCOM_VEHICLE_OUTPUTS_NUMBERS)/sizeof(INTERCOM_VEHICLE_OUTPUTS_NUMBERS[0]);
    const TagInfo *INTERCOM_VEHICLE_OUTPUTS_TAGS = 0;
    const size_t INTERCOM_VEHICLE_OUTPUTS_TAGS_SIZE = 0;
    const IdentifierInfo *INTERCOM_VEHICLE_OUTPUTS_IDENTIFIERS = 0;
    const size_t INTERCOM_VEHICLE_OUTPUTS_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *INTERCOM_VEHICLE_OUTPUTS_CONSTANTS = 0;
    const size_t INTERCOM_VEHICLE_OUTPUTS_CONSTANTS_SIZE = 0;
    const SpecificationInfo *INTERCOM_VEHICLE_OUTPUTS_SPECIFICATIONS = 0;
    const size_t INTERCOM_VEHICLE_OUTPUTS_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *INTERCOM_VEHICLE_OUTPUTS_RAWS = 0;
    const size_t INTERCOM_VEHICLE_OUTPUTS_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *INTERCOM_VEHICLE_OUTPUTS_TRAYS = 0;
    const size_t INTERCOM_VEHICLE_OUTPUTS_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> PIS_AUDIO_CONTROLLER_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 601),
    };
    const size_t PIS_AUDIO_CONTROLLER_NUMBERS_SIZE = sizeof(PIS_AUDIO_CONTROLLER_NUMBERS)/sizeof(PIS_AUDIO_CONTROLLER_NUMBERS[0]);
    const TagInfo *PIS_AUDIO_CONTROLLER_TAGS = 0;
    const size_t PIS_AUDIO_CONTROLLER_TAGS_SIZE = 0;
    const IdentifierInfo *PIS_AUDIO_CONTROLLER_IDENTIFIERS = 0;
    const size_t PIS_AUDIO_CONTROLLER_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *PIS_AUDIO_CONTROLLER_CONSTANTS = 0;
    const size_t PIS_AUDIO_CONTROLLER_CONSTANTS_SIZE = 0;
    const SpecificationInfo *PIS_AUDIO_CONTROLLER_SPECIFICATIONS = 0;
    const size_t PIS_AUDIO_CONTROLLER_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *PIS_AUDIO_CONTROLLER_RAWS = 0;
    const size_t PIS_AUDIO_CONTROLLER_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *PIS_AUDIO_CONTROLLER_TRAYS = 0;
    const size_t PIS_AUDIO_CONTROLLER_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> PIS_AUDIO_CONTROLLER_STATUS_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 602),
        Sim::Info<Sim::Number>("Enabled", 0.5, 1),
        Sim::Info<Sim::Number>("Volume", 0.1, 0),
        Sim::Info<Sim::Number>("Announcement", 0.5, -1),
    };
    const size_t PIS_AUDIO_CONTROLLER_STATUS_NUMBERS_SIZE = sizeof(PIS_AUDIO_CONTROLLER_STATUS_NUMBERS)/sizeof(PIS_AUDIO_CONTROLLER_STATUS_NUMBERS[0]);
    const TagInfo *PIS_AUDIO_CONTROLLER_STATUS_TAGS = 0;
    const size_t PIS_AUDIO_CONTROLLER_STATUS_TAGS_SIZE = 0;
    const IdentifierInfo *PIS_AUDIO_CONTROLLER_STATUS_IDENTIFIERS = 0;
    const size_t PIS_AUDIO_CONTROLLER_STATUS_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *PIS_AUDIO_CONTROLLER_STATUS_CONSTANTS = 0;
    const size_t PIS_AUDIO_CONTROLLER_STATUS_CONSTANTS_SIZE = 0;
    const SpecificationInfo *PIS_AUDIO_CONTROLLER_STATUS_SPECIFICATIONS = 0;
    const size_t PIS_AUDIO_CONTROLLER_STATUS_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *PIS_AUDIO_CONTROLLER_STATUS_RAWS = 0;
    const size_t PIS_AUDIO_CONTROLLER_STATUS_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *PIS_AUDIO_CONTROLLER_STATUS_TRAYS = 0;
    const size_t PIS_AUDIO_CONTROLLER_STATUS_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> PIS_AUDIO_CONTROLLER_MESSAGE_QUEUE_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 603),
        Sim::Info<Sim::Number>("StatusRequired", 0.5, 0),
    };
    const size_t PIS_AUDIO_CONTROLLER_MESSAGE_QUEUE_NUMBERS_SIZE = sizeof(PIS_AUDIO_CONTROLLER_MESSAGE_QUEUE_NUMBERS)/sizeof(PIS_AUDIO_CONTROLLER_MESSAGE_QUEUE_NUMBERS[0]);
    const TagInfo *PIS_AUDIO_CONTROLLER_MESSAGE_QUEUE_TAGS = 0;
    const size_t PIS_AUDIO_CONTROLLER_MESSAGE_QUEUE_TAGS_SIZE = 0;
    const IdentifierInfo *PIS_AUDIO_CONTROLLER_MESSAGE_QUEUE_IDENTIFIERS = 0;
    const size_t PIS_AUDIO_CONTROLLER_MESSAGE_QUEUE_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *PIS_AUDIO_CONTROLLER_MESSAGE_QUEUE_CONSTANTS = 0;
    const size_t PIS_AUDIO_CONTROLLER_MESSAGE_QUEUE_CONSTANTS_SIZE = 0;
    const SpecificationInfo PIS_AUDIO_CONTROLLER_MESSAGE_QUEUE_SPECIFICATIONS[] =
    {
        { "Owner",  },
    };
    const size_t PIS_AUDIO_CONTROLLER_MESSAGE_QUEUE_SPECIFICATIONS_SIZE = sizeof(PIS_AUDIO_CONTROLLER_MESSAGE_QUEUE_SPECIFICATIONS)/sizeof(PIS_AUDIO_CONTROLLER_MESSAGE_QUEUE_SPECIFICATIONS[0]);
    const Sim::Info<Sim::Raw> *PIS_AUDIO_CONTROLLER_MESSAGE_QUEUE_RAWS = 0;
    const size_t PIS_AUDIO_CONTROLLER_MESSAGE_QUEUE_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> PIS_AUDIO_CONTROLLER_MESSAGE_QUEUE_TRAYS[] =
    {
        Sim::Info<Sim::Tray>("Source"),
        Sim::Info<Sim::Tray>("Status"),
    };
    const size_t PIS_AUDIO_CONTROLLER_MESSAGE_QUEUE_TRAYS_SIZE = sizeof(PIS_AUDIO_CONTROLLER_MESSAGE_QUEUE_TRAYS)/sizeof(PIS_AUDIO_CONTROLLER_MESSAGE_QUEUE_TRAYS[0]);
    const Sim::Info<Sim::Number> SCHEDULE_TRACKING_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 501),
    };
    const size_t SCHEDULE_TRACKING_NUMBERS_SIZE = sizeof(SCHEDULE_TRACKING_NUMBERS)/sizeof(SCHEDULE_TRACKING_NUMBERS[0]);
    const TagInfo SCHEDULE_TRACKING_TAGS[] =
    {
        { "Schedule Tracking" },
    };
    const size_t SCHEDULE_TRACKING_TAGS_SIZE = sizeof(SCHEDULE_TRACKING_TAGS)/sizeof(SCHEDULE_TRACKING_TAGS[0]);
    const IdentifierInfo *SCHEDULE_TRACKING_IDENTIFIERS = 0;
    const size_t SCHEDULE_TRACKING_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *SCHEDULE_TRACKING_CONSTANTS = 0;
    const size_t SCHEDULE_TRACKING_CONSTANTS_SIZE = 0;
    const SpecificationInfo *SCHEDULE_TRACKING_SPECIFICATIONS = 0;
    const size_t SCHEDULE_TRACKING_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> *SCHEDULE_TRACKING_RAWS = 0;
    const size_t SCHEDULE_TRACKING_RAWS_SIZE = 0;
    const Sim::Info<Sim::Tray> *SCHEDULE_TRACKING_TRAYS = 0;
    const size_t SCHEDULE_TRACKING_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> STU_INPUTS_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 502),
    };
    const size_t STU_INPUTS_NUMBERS_SIZE = sizeof(STU_INPUTS_NUMBERS)/sizeof(STU_INPUTS_NUMBERS[0]);
    const TagInfo STU_INPUTS_TAGS[] =
    {
        { "STUInputs" },
    };
    const size_t STU_INPUTS_TAGS_SIZE = sizeof(STU_INPUTS_TAGS)/sizeof(STU_INPUTS_TAGS[0]);
    const IdentifierInfo *STU_INPUTS_IDENTIFIERS = 0;
    const size_t STU_INPUTS_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *STU_INPUTS_CONSTANTS = 0;
    const size_t STU_INPUTS_CONSTANTS_SIZE = 0;
    const SpecificationInfo *STU_INPUTS_SPECIFICATIONS = 0;
    const size_t STU_INPUTS_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> STU_INPUTS_RAWS[] =
    {
        Sim::Info<Sim::Raw>("Route"),
    };
    const size_t STU_INPUTS_RAWS_SIZE = sizeof(STU_INPUTS_RAWS)/sizeof(STU_INPUTS_RAWS[0]);
    const Sim::Info<Sim::Tray> *STU_INPUTS_TRAYS = 0;
    const size_t STU_INPUTS_TRAYS_SIZE = 0;
    const Sim::Info<Sim::Number> STU_OUTPUTS_NUMBERS[] =
    {
        Sim::Info<Sim::Number>("Class", 0.5, 503),
        Sim::Info<Sim::Number>("Next Stopping Station Distance", 0.001, 0),
        Sim::Info<Sim::Number>("ETA Next Stopping Station", 0.001, 0),
        Sim::Info<Sim::Number>("Next Station Distance", 0.001, 0),
        Sim::Info<Sim::Number>("ETA Next Station", 0.001, 0),
        Sim::Info<Sim::Number>("Previous Station Distance", 0.001, 0),
        Sim::Info<Sim::Number>("Next Station Arrival Time", 0.001, 0),
        Sim::Info<Sim::Number>("Next Station Departure Time", 0.001, 0),
    };
    const size_t STU_OUTPUTS_NUMBERS_SIZE = sizeof(STU_OUTPUTS_NUMBERS)/sizeof(STU_OUTPUTS_NUMBERS[0]);
    const TagInfo STU_OUTPUTS_TAGS[] =
    {
        { "STUOutputs" },
    };
    const size_t STU_OUTPUTS_TAGS_SIZE = sizeof(STU_OUTPUTS_TAGS)/sizeof(STU_OUTPUTS_TAGS[0]);
    const IdentifierInfo *STU_OUTPUTS_IDENTIFIERS = 0;
    const size_t STU_OUTPUTS_IDENTIFIERS_SIZE = 0;
    const ConstantInfo *STU_OUTPUTS_CONSTANTS = 0;
    const size_t STU_OUTPUTS_CONSTANTS_SIZE = 0;
    const SpecificationInfo *STU_OUTPUTS_SPECIFICATIONS = 0;
    const size_t STU_OUTPUTS_SPECIFICATIONS_SIZE = 0;
    const Sim::Info<Sim::Raw> STU_OUTPUTS_RAWS[] =
    {
        Sim::Info<Sim::Raw>("Next Stopping Station"),
        Sim::Info<Sim::Raw>("Next Station"),
        Sim::Info<Sim::Raw>("Previous Station"),
        Sim::Info<Sim::Raw>("Route"),
        Sim::Info<Sim::Raw>("Route Profile"),
    };
    const size_t STU_OUTPUTS_RAWS_SIZE = sizeof(STU_OUTPUTS_RAWS)/sizeof(STU_OUTPUTS_RAWS[0]);
    const Sim::Info<Sim::Tray> *STU_OUTPUTS_TRAYS = 0;
    const size_t STU_OUTPUTS_TRAYS_SIZE = 0;
    const ClassInfo CLASS_INFO[] =
{
        {
            108, "IOData",
            IODATA_TAGS_SIZE, IODATA_TAGS,
            IODATA_IDENTIFIERS_SIZE, IODATA_IDENTIFIERS,
            IODATA_CONSTANTS_SIZE, IODATA_CONSTANTS,
            IODATA_SPECIFICATIONS_SIZE, IODATA_SPECIFICATIONS,
            IODATA_NUMBERS_SIZE, IODATA_NUMBERS,
            IODATA_RAWS_SIZE, IODATA_RAWS,
            IODATA_TRAYS_SIZE, IODATA_TRAYS
        },
        {
            105, "HubInputs",
            HUB_INPUTS_TAGS_SIZE, HUB_INPUTS_TAGS,
            HUB_INPUTS_IDENTIFIERS_SIZE, HUB_INPUTS_IDENTIFIERS,
            HUB_INPUTS_CONSTANTS_SIZE, HUB_INPUTS_CONSTANTS,
            HUB_INPUTS_SPECIFICATIONS_SIZE, HUB_INPUTS_SPECIFICATIONS,
            HUB_INPUTS_NUMBERS_SIZE, HUB_INPUTS_NUMBERS,
            HUB_INPUTS_RAWS_SIZE, HUB_INPUTS_RAWS,
            HUB_INPUTS_TRAYS_SIZE, HUB_INPUTS_TRAYS
        },
        {
            106, "HubOutputs",
            HUB_OUTPUTS_TAGS_SIZE, HUB_OUTPUTS_TAGS,
            HUB_OUTPUTS_IDENTIFIERS_SIZE, HUB_OUTPUTS_IDENTIFIERS,
            HUB_OUTPUTS_CONSTANTS_SIZE, HUB_OUTPUTS_CONSTANTS,
            HUB_OUTPUTS_SPECIFICATIONS_SIZE, HUB_OUTPUTS_SPECIFICATIONS,
            HUB_OUTPUTS_NUMBERS_SIZE, HUB_OUTPUTS_NUMBERS,
            HUB_OUTPUTS_RAWS_SIZE, HUB_OUTPUTS_RAWS,
            HUB_OUTPUTS_TRAYS_SIZE, HUB_OUTPUTS_TRAYS
        },
        {
            107, "HubValues",
            HUB_VALUES_TAGS_SIZE, HUB_VALUES_TAGS,
            HUB_VALUES_IDENTIFIERS_SIZE, HUB_VALUES_IDENTIFIERS,
            HUB_VALUES_CONSTANTS_SIZE, HUB_VALUES_CONSTANTS,
            HUB_VALUES_SPECIFICATIONS_SIZE, HUB_VALUES_SPECIFICATIONS,
            HUB_VALUES_NUMBERS_SIZE, HUB_VALUES_NUMBERS,
            HUB_VALUES_RAWS_SIZE, HUB_VALUES_RAWS,
            HUB_VALUES_TRAYS_SIZE, HUB_VALUES_TRAYS
        },
        {
            101, "VehicleInputs",
            VEHICLE_INPUTS_TAGS_SIZE, VEHICLE_INPUTS_TAGS,
            VEHICLE_INPUTS_IDENTIFIERS_SIZE, VEHICLE_INPUTS_IDENTIFIERS,
            VEHICLE_INPUTS_CONSTANTS_SIZE, VEHICLE_INPUTS_CONSTANTS,
            VEHICLE_INPUTS_SPECIFICATIONS_SIZE, VEHICLE_INPUTS_SPECIFICATIONS,
            VEHICLE_INPUTS_NUMBERS_SIZE, VEHICLE_INPUTS_NUMBERS,
            VEHICLE_INPUTS_RAWS_SIZE, VEHICLE_INPUTS_RAWS,
            VEHICLE_INPUTS_TRAYS_SIZE, VEHICLE_INPUTS_TRAYS
        },
        {
            103, "VehicleInputsValues",
            VEHICLE_INPUTS_VALUES_TAGS_SIZE, VEHICLE_INPUTS_VALUES_TAGS,
            VEHICLE_INPUTS_VALUES_IDENTIFIERS_SIZE, VEHICLE_INPUTS_VALUES_IDENTIFIERS,
            VEHICLE_INPUTS_VALUES_CONSTANTS_SIZE, VEHICLE_INPUTS_VALUES_CONSTANTS,
            VEHICLE_INPUTS_VALUES_SPECIFICATIONS_SIZE, VEHICLE_INPUTS_VALUES_SPECIFICATIONS,
            VEHICLE_INPUTS_VALUES_NUMBERS_SIZE, VEHICLE_INPUTS_VALUES_NUMBERS,
            VEHICLE_INPUTS_VALUES_RAWS_SIZE, VEHICLE_INPUTS_VALUES_RAWS,
            VEHICLE_INPUTS_VALUES_TRAYS_SIZE, VEHICLE_INPUTS_VALUES_TRAYS
        },
        {
            104, "VehicleInputsModes",
            VEHICLE_INPUTS_MODES_TAGS_SIZE, VEHICLE_INPUTS_MODES_TAGS,
            VEHICLE_INPUTS_MODES_IDENTIFIERS_SIZE, VEHICLE_INPUTS_MODES_IDENTIFIERS,
            VEHICLE_INPUTS_MODES_CONSTANTS_SIZE, VEHICLE_INPUTS_MODES_CONSTANTS,
            VEHICLE_INPUTS_MODES_SPECIFICATIONS_SIZE, VEHICLE_INPUTS_MODES_SPECIFICATIONS,
            VEHICLE_INPUTS_MODES_NUMBERS_SIZE, VEHICLE_INPUTS_MODES_NUMBERS,
            VEHICLE_INPUTS_MODES_RAWS_SIZE, VEHICLE_INPUTS_MODES_RAWS,
            VEHICLE_INPUTS_MODES_TRAYS_SIZE, VEHICLE_INPUTS_MODES_TRAYS
        },
        {
            102, "VehicleOutputs",
            VEHICLE_OUTPUTS_TAGS_SIZE, VEHICLE_OUTPUTS_TAGS,
            VEHICLE_OUTPUTS_IDENTIFIERS_SIZE, VEHICLE_OUTPUTS_IDENTIFIERS,
            VEHICLE_OUTPUTS_CONSTANTS_SIZE, VEHICLE_OUTPUTS_CONSTANTS,
            VEHICLE_OUTPUTS_SPECIFICATIONS_SIZE, VEHICLE_OUTPUTS_SPECIFICATIONS,
            VEHICLE_OUTPUTS_NUMBERS_SIZE, VEHICLE_OUTPUTS_NUMBERS,
            VEHICLE_OUTPUTS_RAWS_SIZE, VEHICLE_OUTPUTS_RAWS,
            VEHICLE_OUTPUTS_TRAYS_SIZE, VEHICLE_OUTPUTS_TRAYS
        },
        {
            115, "SessionControl",
            SESSION_CONTROL_TAGS_SIZE, SESSION_CONTROL_TAGS,
            SESSION_CONTROL_IDENTIFIERS_SIZE, SESSION_CONTROL_IDENTIFIERS,
            SESSION_CONTROL_CONSTANTS_SIZE, SESSION_CONTROL_CONSTANTS,
            SESSION_CONTROL_SPECIFICATIONS_SIZE, SESSION_CONTROL_SPECIFICATIONS,
            SESSION_CONTROL_NUMBERS_SIZE, SESSION_CONTROL_NUMBERS,
            SESSION_CONTROL_RAWS_SIZE, SESSION_CONTROL_RAWS,
            SESSION_CONTROL_TRAYS_SIZE, SESSION_CONTROL_TRAYS
        },
        {
            20, "AudioEngine",
            AUDIO_ENGINE_TAGS_SIZE, AUDIO_ENGINE_TAGS,
            AUDIO_ENGINE_IDENTIFIERS_SIZE, AUDIO_ENGINE_IDENTIFIERS,
            AUDIO_ENGINE_CONSTANTS_SIZE, AUDIO_ENGINE_CONSTANTS,
            AUDIO_ENGINE_SPECIFICATIONS_SIZE, AUDIO_ENGINE_SPECIFICATIONS,
            AUDIO_ENGINE_NUMBERS_SIZE, AUDIO_ENGINE_NUMBERS,
            AUDIO_ENGINE_RAWS_SIZE, AUDIO_ENGINE_RAWS,
            AUDIO_ENGINE_TRAYS_SIZE, AUDIO_ENGINE_TRAYS
        },
        {
            6, "AudioOutput",
            AUDIO_OUTPUT_TAGS_SIZE, AUDIO_OUTPUT_TAGS,
            AUDIO_OUTPUT_IDENTIFIERS_SIZE, AUDIO_OUTPUT_IDENTIFIERS,
            AUDIO_OUTPUT_CONSTANTS_SIZE, AUDIO_OUTPUT_CONSTANTS,
            AUDIO_OUTPUT_SPECIFICATIONS_SIZE, AUDIO_OUTPUT_SPECIFICATIONS,
            AUDIO_OUTPUT_NUMBERS_SIZE, AUDIO_OUTPUT_NUMBERS,
            AUDIO_OUTPUT_RAWS_SIZE, AUDIO_OUTPUT_RAWS,
            AUDIO_OUTPUT_TRAYS_SIZE, AUDIO_OUTPUT_TRAYS
        },
        {
            24, "AutoTrain",
            AUTO_TRAIN_TAGS_SIZE, AUTO_TRAIN_TAGS,
            AUTO_TRAIN_IDENTIFIERS_SIZE, AUTO_TRAIN_IDENTIFIERS,
            AUTO_TRAIN_CONSTANTS_SIZE, AUTO_TRAIN_CONSTANTS,
            AUTO_TRAIN_SPECIFICATIONS_SIZE, AUTO_TRAIN_SPECIFICATIONS,
            AUTO_TRAIN_NUMBERS_SIZE, AUTO_TRAIN_NUMBERS,
            AUTO_TRAIN_RAWS_SIZE, AUTO_TRAIN_RAWS,
            AUTO_TRAIN_TRAYS_SIZE, AUTO_TRAIN_TRAYS
        },
        {
            25, "AutoVehicle",
            AUTO_VEHICLE_TAGS_SIZE, AUTO_VEHICLE_TAGS,
            AUTO_VEHICLE_IDENTIFIERS_SIZE, AUTO_VEHICLE_IDENTIFIERS,
            AUTO_VEHICLE_CONSTANTS_SIZE, AUTO_VEHICLE_CONSTANTS,
            AUTO_VEHICLE_SPECIFICATIONS_SIZE, AUTO_VEHICLE_SPECIFICATIONS,
            AUTO_VEHICLE_NUMBERS_SIZE, AUTO_VEHICLE_NUMBERS,
            AUTO_VEHICLE_RAWS_SIZE, AUTO_VEHICLE_RAWS,
            AUTO_VEHICLE_TRAYS_SIZE, AUTO_VEHICLE_TRAYS
        },
        {
            19, "Environment",
            ENVIRONMENT_TAGS_SIZE, ENVIRONMENT_TAGS,
            ENVIRONMENT_IDENTIFIERS_SIZE, ENVIRONMENT_IDENTIFIERS,
            ENVIRONMENT_CONSTANTS_SIZE, ENVIRONMENT_CONSTANTS,
            ENVIRONMENT_SPECIFICATIONS_SIZE, ENVIRONMENT_SPECIFICATIONS,
            ENVIRONMENT_NUMBERS_SIZE, ENVIRONMENT_NUMBERS,
            ENVIRONMENT_RAWS_SIZE, ENVIRONMENT_RAWS,
            ENVIRONMENT_TRAYS_SIZE, ENVIRONMENT_TRAYS
        },
        {
            12, "Feature",
            FEATURE_TAGS_SIZE, FEATURE_TAGS,
            FEATURE_IDENTIFIERS_SIZE, FEATURE_IDENTIFIERS,
            FEATURE_CONSTANTS_SIZE, FEATURE_CONSTANTS,
            FEATURE_SPECIFICATIONS_SIZE, FEATURE_SPECIFICATIONS,
            FEATURE_NUMBERS_SIZE, FEATURE_NUMBERS,
            FEATURE_RAWS_SIZE, FEATURE_RAWS,
            FEATURE_TRAYS_SIZE, FEATURE_TRAYS
        },
        {
            55, "Features",
            FEATURES_TAGS_SIZE, FEATURES_TAGS,
            FEATURES_IDENTIFIERS_SIZE, FEATURES_IDENTIFIERS,
            FEATURES_CONSTANTS_SIZE, FEATURES_CONSTANTS,
            FEATURES_SPECIFICATIONS_SIZE, FEATURES_SPECIFICATIONS,
            FEATURES_NUMBERS_SIZE, FEATURES_NUMBERS,
            FEATURES_RAWS_SIZE, FEATURES_RAWS,
            FEATURES_TRAYS_SIZE, FEATURES_TRAYS
        },
        {
            112, "GMIData",
            GMI_DATA_TAGS_SIZE, GMI_DATA_TAGS,
            GMI_DATA_IDENTIFIERS_SIZE, GMI_DATA_IDENTIFIERS,
            GMI_DATA_CONSTANTS_SIZE, GMI_DATA_CONSTANTS,
            GMI_DATA_SPECIFICATIONS_SIZE, GMI_DATA_SPECIFICATIONS,
            GMI_DATA_NUMBERS_SIZE, GMI_DATA_NUMBERS,
            GMI_DATA_RAWS_SIZE, GMI_DATA_RAWS,
            GMI_DATA_TRAYS_SIZE, GMI_DATA_TRAYS
        },
        {
            100, "Hub",
            HUB_TAGS_SIZE, HUB_TAGS,
            HUB_IDENTIFIERS_SIZE, HUB_IDENTIFIERS,
            HUB_CONSTANTS_SIZE, HUB_CONSTANTS,
            HUB_SPECIFICATIONS_SIZE, HUB_SPECIFICATIONS,
            HUB_NUMBERS_SIZE, HUB_NUMBERS,
            HUB_RAWS_SIZE, HUB_RAWS,
            HUB_TRAYS_SIZE, HUB_TRAYS
        },
        {
            114, "GMIPosition",
            GMI_POSITION_TAGS_SIZE, GMI_POSITION_TAGS,
            GMI_POSITION_IDENTIFIERS_SIZE, GMI_POSITION_IDENTIFIERS,
            GMI_POSITION_CONSTANTS_SIZE, GMI_POSITION_CONSTANTS,
            GMI_POSITION_SPECIFICATIONS_SIZE, GMI_POSITION_SPECIFICATIONS,
            GMI_POSITION_NUMBERS_SIZE, GMI_POSITION_NUMBERS,
            GMI_POSITION_RAWS_SIZE, GMI_POSITION_RAWS,
            GMI_POSITION_TRAYS_SIZE, GMI_POSITION_TRAYS
        },
        {
            13, "ObjectGeometry",
            OBJECT_GEOMETRY_TAGS_SIZE, OBJECT_GEOMETRY_TAGS,
            OBJECT_GEOMETRY_IDENTIFIERS_SIZE, OBJECT_GEOMETRY_IDENTIFIERS,
            OBJECT_GEOMETRY_CONSTANTS_SIZE, OBJECT_GEOMETRY_CONSTANTS,
            OBJECT_GEOMETRY_SPECIFICATIONS_SIZE, OBJECT_GEOMETRY_SPECIFICATIONS,
            OBJECT_GEOMETRY_NUMBERS_SIZE, OBJECT_GEOMETRY_NUMBERS,
            OBJECT_GEOMETRY_RAWS_SIZE, OBJECT_GEOMETRY_RAWS,
            OBJECT_GEOMETRY_TRAYS_SIZE, OBJECT_GEOMETRY_TRAYS
        },
        {
            16, "Perspective",
            PERSPECTIVE_TAGS_SIZE, PERSPECTIVE_TAGS,
            PERSPECTIVE_IDENTIFIERS_SIZE, PERSPECTIVE_IDENTIFIERS,
            PERSPECTIVE_CONSTANTS_SIZE, PERSPECTIVE_CONSTANTS,
            PERSPECTIVE_SPECIFICATIONS_SIZE, PERSPECTIVE_SPECIFICATIONS,
            PERSPECTIVE_NUMBERS_SIZE, PERSPECTIVE_NUMBERS,
            PERSPECTIVE_RAWS_SIZE, PERSPECTIVE_RAWS,
            PERSPECTIVE_TRAYS_SIZE, PERSPECTIVE_TRAYS
        },
        {
            26, "Perspectives",
            PERSPECTIVES_TAGS_SIZE, PERSPECTIVES_TAGS,
            PERSPECTIVES_IDENTIFIERS_SIZE, PERSPECTIVES_IDENTIFIERS,
            PERSPECTIVES_CONSTANTS_SIZE, PERSPECTIVES_CONSTANTS,
            PERSPECTIVES_SPECIFICATIONS_SIZE, PERSPECTIVES_SPECIFICATIONS,
            PERSPECTIVES_NUMBERS_SIZE, PERSPECTIVES_NUMBERS,
            PERSPECTIVES_RAWS_SIZE, PERSPECTIVES_RAWS,
            PERSPECTIVES_TRAYS_SIZE, PERSPECTIVES_TRAYS
        },
        {
            119, "PerspectiveProperties",
            PERSPECTIVE_PROPERTIES_TAGS_SIZE, PERSPECTIVE_PROPERTIES_TAGS,
            PERSPECTIVE_PROPERTIES_IDENTIFIERS_SIZE, PERSPECTIVE_PROPERTIES_IDENTIFIERS,
            PERSPECTIVE_PROPERTIES_CONSTANTS_SIZE, PERSPECTIVE_PROPERTIES_CONSTANTS,
            PERSPECTIVE_PROPERTIES_SPECIFICATIONS_SIZE, PERSPECTIVE_PROPERTIES_SPECIFICATIONS,
            PERSPECTIVE_PROPERTIES_NUMBERS_SIZE, PERSPECTIVE_PROPERTIES_NUMBERS,
            PERSPECTIVE_PROPERTIES_RAWS_SIZE, PERSPECTIVE_PROPERTIES_RAWS,
            PERSPECTIVE_PROPERTIES_TRAYS_SIZE, PERSPECTIVE_PROPERTIES_TRAYS
        },
        {
            113, "PTData",
            PT_DATA_TAGS_SIZE, PT_DATA_TAGS,
            PT_DATA_IDENTIFIERS_SIZE, PT_DATA_IDENTIFIERS,
            PT_DATA_CONSTANTS_SIZE, PT_DATA_CONSTANTS,
            PT_DATA_SPECIFICATIONS_SIZE, PT_DATA_SPECIFICATIONS,
            PT_DATA_NUMBERS_SIZE, PT_DATA_NUMBERS,
            PT_DATA_RAWS_SIZE, PT_DATA_RAWS,
            PT_DATA_TRAYS_SIZE, PT_DATA_TRAYS
        },
        {
            9, "RadioArea",
            RADIO_AREA_TAGS_SIZE, RADIO_AREA_TAGS,
            RADIO_AREA_IDENTIFIERS_SIZE, RADIO_AREA_IDENTIFIERS,
            RADIO_AREA_CONSTANTS_SIZE, RADIO_AREA_CONSTANTS,
            RADIO_AREA_SPECIFICATIONS_SIZE, RADIO_AREA_SPECIFICATIONS,
            RADIO_AREA_NUMBERS_SIZE, RADIO_AREA_NUMBERS,
            RADIO_AREA_RAWS_SIZE, RADIO_AREA_RAWS,
            RADIO_AREA_TRAYS_SIZE, RADIO_AREA_TRAYS
        },
        {
            116, "ScriptingEngine",
            SCRIPTING_ENGINE_TAGS_SIZE, SCRIPTING_ENGINE_TAGS,
            SCRIPTING_ENGINE_IDENTIFIERS_SIZE, SCRIPTING_ENGINE_IDENTIFIERS,
            SCRIPTING_ENGINE_CONSTANTS_SIZE, SCRIPTING_ENGINE_CONSTANTS,
            SCRIPTING_ENGINE_SPECIFICATIONS_SIZE, SCRIPTING_ENGINE_SPECIFICATIONS,
            SCRIPTING_ENGINE_NUMBERS_SIZE, SCRIPTING_ENGINE_NUMBERS,
            SCRIPTING_ENGINE_RAWS_SIZE, SCRIPTING_ENGINE_RAWS,
            SCRIPTING_ENGINE_TRAYS_SIZE, SCRIPTING_ENGINE_TRAYS
        },
        {
            117, "Scriptlet",
            SCRIPTLET_TAGS_SIZE, SCRIPTLET_TAGS,
            SCRIPTLET_IDENTIFIERS_SIZE, SCRIPTLET_IDENTIFIERS,
            SCRIPTLET_CONSTANTS_SIZE, SCRIPTLET_CONSTANTS,
            SCRIPTLET_SPECIFICATIONS_SIZE, SCRIPTLET_SPECIFICATIONS,
            SCRIPTLET_NUMBERS_SIZE, SCRIPTLET_NUMBERS,
            SCRIPTLET_RAWS_SIZE, SCRIPTLET_RAWS,
            SCRIPTLET_TRAYS_SIZE, SCRIPTLET_TRAYS
        },
        {
            22, "SoundData",
            SOUND_DATA_TAGS_SIZE, SOUND_DATA_TAGS,
            SOUND_DATA_IDENTIFIERS_SIZE, SOUND_DATA_IDENTIFIERS,
            SOUND_DATA_CONSTANTS_SIZE, SOUND_DATA_CONSTANTS,
            SOUND_DATA_SPECIFICATIONS_SIZE, SOUND_DATA_SPECIFICATIONS,
            SOUND_DATA_NUMBERS_SIZE, SOUND_DATA_NUMBERS,
            SOUND_DATA_RAWS_SIZE, SOUND_DATA_RAWS,
            SOUND_DATA_TRAYS_SIZE, SOUND_DATA_TRAYS
        },
        {
            14, "TrackAssociation",
            TRACK_ASSOCIATION_TAGS_SIZE, TRACK_ASSOCIATION_TAGS,
            TRACK_ASSOCIATION_IDENTIFIERS_SIZE, TRACK_ASSOCIATION_IDENTIFIERS,
            TRACK_ASSOCIATION_CONSTANTS_SIZE, TRACK_ASSOCIATION_CONSTANTS,
            TRACK_ASSOCIATION_SPECIFICATIONS_SIZE, TRACK_ASSOCIATION_SPECIFICATIONS,
            TRACK_ASSOCIATION_NUMBERS_SIZE, TRACK_ASSOCIATION_NUMBERS,
            TRACK_ASSOCIATION_RAWS_SIZE, TRACK_ASSOCIATION_RAWS,
            TRACK_ASSOCIATION_TRAYS_SIZE, TRACK_ASSOCIATION_TRAYS
        },
        {
            11, "TrackPosition",
            TRACK_POSITION_TAGS_SIZE, TRACK_POSITION_TAGS,
            TRACK_POSITION_IDENTIFIERS_SIZE, TRACK_POSITION_IDENTIFIERS,
            TRACK_POSITION_CONSTANTS_SIZE, TRACK_POSITION_CONSTANTS,
            TRACK_POSITION_SPECIFICATIONS_SIZE, TRACK_POSITION_SPECIFICATIONS,
            TRACK_POSITION_NUMBERS_SIZE, TRACK_POSITION_NUMBERS,
            TRACK_POSITION_RAWS_SIZE, TRACK_POSITION_RAWS,
            TRACK_POSITION_TRAYS_SIZE, TRACK_POSITION_TRAYS
        },
        {
            17, "BogiePositions",
            BOGIE_POSITIONS_TAGS_SIZE, BOGIE_POSITIONS_TAGS,
            BOGIE_POSITIONS_IDENTIFIERS_SIZE, BOGIE_POSITIONS_IDENTIFIERS,
            BOGIE_POSITIONS_CONSTANTS_SIZE, BOGIE_POSITIONS_CONSTANTS,
            BOGIE_POSITIONS_SPECIFICATIONS_SIZE, BOGIE_POSITIONS_SPECIFICATIONS,
            BOGIE_POSITIONS_NUMBERS_SIZE, BOGIE_POSITIONS_NUMBERS,
            BOGIE_POSITIONS_RAWS_SIZE, BOGIE_POSITIONS_RAWS,
            BOGIE_POSITIONS_TRAYS_SIZE, BOGIE_POSITIONS_TRAYS
        },
        {
            21, "Wave",
            WAVE_TAGS_SIZE, WAVE_TAGS,
            WAVE_IDENTIFIERS_SIZE, WAVE_IDENTIFIERS,
            WAVE_CONSTANTS_SIZE, WAVE_CONSTANTS,
            WAVE_SPECIFICATIONS_SIZE, WAVE_SPECIFICATIONS,
            WAVE_NUMBERS_SIZE, WAVE_NUMBERS,
            WAVE_RAWS_SIZE, WAVE_RAWS,
            WAVE_TRAYS_SIZE, WAVE_TRAYS
        },
        {
            1, "World",
            WORLD_TAGS_SIZE, WORLD_TAGS,
            WORLD_IDENTIFIERS_SIZE, WORLD_IDENTIFIERS,
            WORLD_CONSTANTS_SIZE, WORLD_CONSTANTS,
            WORLD_SPECIFICATIONS_SIZE, WORLD_SPECIFICATIONS,
            WORLD_NUMBERS_SIZE, WORLD_NUMBERS,
            WORLD_RAWS_SIZE, WORLD_RAWS,
            WORLD_TRAYS_SIZE, WORLD_TRAYS
        },
        {
            110, "Canvas",
            CANVAS_TAGS_SIZE, CANVAS_TAGS,
            CANVAS_IDENTIFIERS_SIZE, CANVAS_IDENTIFIERS,
            CANVAS_CONSTANTS_SIZE, CANVAS_CONSTANTS,
            CANVAS_SPECIFICATIONS_SIZE, CANVAS_SPECIFICATIONS,
            CANVAS_NUMBERS_SIZE, CANVAS_NUMBERS,
            CANVAS_RAWS_SIZE, CANVAS_RAWS,
            CANVAS_TRAYS_SIZE, CANVAS_TRAYS
        },
        {
            109, "View",
            VIEW_TAGS_SIZE, VIEW_TAGS,
            VIEW_IDENTIFIERS_SIZE, VIEW_IDENTIFIERS,
            VIEW_CONSTANTS_SIZE, VIEW_CONSTANTS,
            VIEW_SPECIFICATIONS_SIZE, VIEW_SPECIFICATIONS,
            VIEW_NUMBERS_SIZE, VIEW_NUMBERS,
            VIEW_RAWS_SIZE, VIEW_RAWS,
            VIEW_TRAYS_SIZE, VIEW_TRAYS
        },
        {
            27, "Displacement",
            DISPLACEMENT_TAGS_SIZE, DISPLACEMENT_TAGS,
            DISPLACEMENT_IDENTIFIERS_SIZE, DISPLACEMENT_IDENTIFIERS,
            DISPLACEMENT_CONSTANTS_SIZE, DISPLACEMENT_CONSTANTS,
            DISPLACEMENT_SPECIFICATIONS_SIZE, DISPLACEMENT_SPECIFICATIONS,
            DISPLACEMENT_NUMBERS_SIZE, DISPLACEMENT_NUMBERS,
            DISPLACEMENT_RAWS_SIZE, DISPLACEMENT_RAWS,
            DISPLACEMENT_TRAYS_SIZE, DISPLACEMENT_TRAYS
        },
        {
            111, "VisionEngine",
            VISION_ENGINE_TAGS_SIZE, VISION_ENGINE_TAGS,
            VISION_ENGINE_IDENTIFIERS_SIZE, VISION_ENGINE_IDENTIFIERS,
            VISION_ENGINE_CONSTANTS_SIZE, VISION_ENGINE_CONSTANTS,
            VISION_ENGINE_SPECIFICATIONS_SIZE, VISION_ENGINE_SPECIFICATIONS,
            VISION_ENGINE_NUMBERS_SIZE, VISION_ENGINE_NUMBERS,
            VISION_ENGINE_RAWS_SIZE, VISION_ENGINE_RAWS,
            VISION_ENGINE_TRAYS_SIZE, VISION_ENGINE_TRAYS
        },
        {
            15, "FeatureAnimation",
            FEATURE_ANIMATION_TAGS_SIZE, FEATURE_ANIMATION_TAGS,
            FEATURE_ANIMATION_IDENTIFIERS_SIZE, FEATURE_ANIMATION_IDENTIFIERS,
            FEATURE_ANIMATION_CONSTANTS_SIZE, FEATURE_ANIMATION_CONSTANTS,
            FEATURE_ANIMATION_SPECIFICATIONS_SIZE, FEATURE_ANIMATION_SPECIFICATIONS,
            FEATURE_ANIMATION_NUMBERS_SIZE, FEATURE_ANIMATION_NUMBERS,
            FEATURE_ANIMATION_RAWS_SIZE, FEATURE_ANIMATION_RAWS,
            FEATURE_ANIMATION_TRAYS_SIZE, FEATURE_ANIMATION_TRAYS
        },
        {
            30, "PlatformPassengerAnimation",
            PLATFORM_PASSENGER_ANIMATION_TAGS_SIZE, PLATFORM_PASSENGER_ANIMATION_TAGS,
            PLATFORM_PASSENGER_ANIMATION_IDENTIFIERS_SIZE, PLATFORM_PASSENGER_ANIMATION_IDENTIFIERS,
            PLATFORM_PASSENGER_ANIMATION_CONSTANTS_SIZE, PLATFORM_PASSENGER_ANIMATION_CONSTANTS,
            PLATFORM_PASSENGER_ANIMATION_SPECIFICATIONS_SIZE, PLATFORM_PASSENGER_ANIMATION_SPECIFICATIONS,
            PLATFORM_PASSENGER_ANIMATION_NUMBERS_SIZE, PLATFORM_PASSENGER_ANIMATION_NUMBERS,
            PLATFORM_PASSENGER_ANIMATION_RAWS_SIZE, PLATFORM_PASSENGER_ANIMATION_RAWS,
            PLATFORM_PASSENGER_ANIMATION_TRAYS_SIZE, PLATFORM_PASSENGER_ANIMATION_TRAYS
        },
        {
            28, "SpeedLimit",
            SPEED_LIMIT_TAGS_SIZE, SPEED_LIMIT_TAGS,
            SPEED_LIMIT_IDENTIFIERS_SIZE, SPEED_LIMIT_IDENTIFIERS,
            SPEED_LIMIT_CONSTANTS_SIZE, SPEED_LIMIT_CONSTANTS,
            SPEED_LIMIT_SPECIFICATIONS_SIZE, SPEED_LIMIT_SPECIFICATIONS,
            SPEED_LIMIT_NUMBERS_SIZE, SPEED_LIMIT_NUMBERS,
            SPEED_LIMIT_RAWS_SIZE, SPEED_LIMIT_RAWS,
            SPEED_LIMIT_TRAYS_SIZE, SPEED_LIMIT_TRAYS
        },
        {
            200, "IdealTrain",
            IDEAL_TRAIN_TAGS_SIZE, IDEAL_TRAIN_TAGS,
            IDEAL_TRAIN_IDENTIFIERS_SIZE, IDEAL_TRAIN_IDENTIFIERS,
            IDEAL_TRAIN_CONSTANTS_SIZE, IDEAL_TRAIN_CONSTANTS,
            IDEAL_TRAIN_SPECIFICATIONS_SIZE, IDEAL_TRAIN_SPECIFICATIONS,
            IDEAL_TRAIN_NUMBERS_SIZE, IDEAL_TRAIN_NUMBERS,
            IDEAL_TRAIN_RAWS_SIZE, IDEAL_TRAIN_RAWS,
            IDEAL_TRAIN_TRAYS_SIZE, IDEAL_TRAIN_TRAYS
        },
        {
            40, "Coupling",
            COUPLING_TAGS_SIZE, COUPLING_TAGS,
            COUPLING_IDENTIFIERS_SIZE, COUPLING_IDENTIFIERS,
            COUPLING_CONSTANTS_SIZE, COUPLING_CONSTANTS,
            COUPLING_SPECIFICATIONS_SIZE, COUPLING_SPECIFICATIONS,
            COUPLING_NUMBERS_SIZE, COUPLING_NUMBERS,
            COUPLING_RAWS_SIZE, COUPLING_RAWS,
            COUPLING_TRAYS_SIZE, COUPLING_TRAYS
        },
        {
            41, "CouplingInputs",
            COUPLING_INPUTS_TAGS_SIZE, COUPLING_INPUTS_TAGS,
            COUPLING_INPUTS_IDENTIFIERS_SIZE, COUPLING_INPUTS_IDENTIFIERS,
            COUPLING_INPUTS_CONSTANTS_SIZE, COUPLING_INPUTS_CONSTANTS,
            COUPLING_INPUTS_SPECIFICATIONS_SIZE, COUPLING_INPUTS_SPECIFICATIONS,
            COUPLING_INPUTS_NUMBERS_SIZE, COUPLING_INPUTS_NUMBERS,
            COUPLING_INPUTS_RAWS_SIZE, COUPLING_INPUTS_RAWS,
            COUPLING_INPUTS_TRAYS_SIZE, COUPLING_INPUTS_TRAYS
        },
        {
            42, "CouplingOutputs",
            COUPLING_OUTPUTS_TAGS_SIZE, COUPLING_OUTPUTS_TAGS,
            COUPLING_OUTPUTS_IDENTIFIERS_SIZE, COUPLING_OUTPUTS_IDENTIFIERS,
            COUPLING_OUTPUTS_CONSTANTS_SIZE, COUPLING_OUTPUTS_CONSTANTS,
            COUPLING_OUTPUTS_SPECIFICATIONS_SIZE, COUPLING_OUTPUTS_SPECIFICATIONS,
            COUPLING_OUTPUTS_NUMBERS_SIZE, COUPLING_OUTPUTS_NUMBERS,
            COUPLING_OUTPUTS_RAWS_SIZE, COUPLING_OUTPUTS_RAWS,
            COUPLING_OUTPUTS_TRAYS_SIZE, COUPLING_OUTPUTS_TRAYS
        },
        {
            43, "MimicInputs",
            MIMIC_INPUTS_TAGS_SIZE, MIMIC_INPUTS_TAGS,
            MIMIC_INPUTS_IDENTIFIERS_SIZE, MIMIC_INPUTS_IDENTIFIERS,
            MIMIC_INPUTS_CONSTANTS_SIZE, MIMIC_INPUTS_CONSTANTS,
            MIMIC_INPUTS_SPECIFICATIONS_SIZE, MIMIC_INPUTS_SPECIFICATIONS,
            MIMIC_INPUTS_NUMBERS_SIZE, MIMIC_INPUTS_NUMBERS,
            MIMIC_INPUTS_RAWS_SIZE, MIMIC_INPUTS_RAWS,
            MIMIC_INPUTS_TRAYS_SIZE, MIMIC_INPUTS_TRAYS
        },
        {
            44, "MimicOutputs",
            MIMIC_OUTPUTS_TAGS_SIZE, MIMIC_OUTPUTS_TAGS,
            MIMIC_OUTPUTS_IDENTIFIERS_SIZE, MIMIC_OUTPUTS_IDENTIFIERS,
            MIMIC_OUTPUTS_CONSTANTS_SIZE, MIMIC_OUTPUTS_CONSTANTS,
            MIMIC_OUTPUTS_SPECIFICATIONS_SIZE, MIMIC_OUTPUTS_SPECIFICATIONS,
            MIMIC_OUTPUTS_NUMBERS_SIZE, MIMIC_OUTPUTS_NUMBERS,
            MIMIC_OUTPUTS_RAWS_SIZE, MIMIC_OUTPUTS_RAWS,
            MIMIC_OUTPUTS_TRAYS_SIZE, MIMIC_OUTPUTS_TRAYS
        },
        {
            118, "MultimediaDisplay",
            MULTIMEDIA_DISPLAY_TAGS_SIZE, MULTIMEDIA_DISPLAY_TAGS,
            MULTIMEDIA_DISPLAY_IDENTIFIERS_SIZE, MULTIMEDIA_DISPLAY_IDENTIFIERS,
            MULTIMEDIA_DISPLAY_CONSTANTS_SIZE, MULTIMEDIA_DISPLAY_CONSTANTS,
            MULTIMEDIA_DISPLAY_SPECIFICATIONS_SIZE, MULTIMEDIA_DISPLAY_SPECIFICATIONS,
            MULTIMEDIA_DISPLAY_NUMBERS_SIZE, MULTIMEDIA_DISPLAY_NUMBERS,
            MULTIMEDIA_DISPLAY_RAWS_SIZE, MULTIMEDIA_DISPLAY_RAWS,
            MULTIMEDIA_DISPLAY_TRAYS_SIZE, MULTIMEDIA_DISPLAY_TRAYS
        },
        {
            45, "Collision",
            COLLISION_TAGS_SIZE, COLLISION_TAGS,
            COLLISION_IDENTIFIERS_SIZE, COLLISION_IDENTIFIERS,
            COLLISION_CONSTANTS_SIZE, COLLISION_CONSTANTS,
            COLLISION_SPECIFICATIONS_SIZE, COLLISION_SPECIFICATIONS,
            COLLISION_NUMBERS_SIZE, COLLISION_NUMBERS,
            COLLISION_RAWS_SIZE, COLLISION_RAWS,
            COLLISION_TRAYS_SIZE, COLLISION_TRAYS
        },
        {
            150, "ETCS OnBoard Inputs",
            ETCS_ONBOARD_INPUTS_TAGS_SIZE, ETCS_ONBOARD_INPUTS_TAGS,
            ETCS_ONBOARD_INPUTS_IDENTIFIERS_SIZE, ETCS_ONBOARD_INPUTS_IDENTIFIERS,
            ETCS_ONBOARD_INPUTS_CONSTANTS_SIZE, ETCS_ONBOARD_INPUTS_CONSTANTS,
            ETCS_ONBOARD_INPUTS_SPECIFICATIONS_SIZE, ETCS_ONBOARD_INPUTS_SPECIFICATIONS,
            ETCS_ONBOARD_INPUTS_NUMBERS_SIZE, ETCS_ONBOARD_INPUTS_NUMBERS,
            ETCS_ONBOARD_INPUTS_RAWS_SIZE, ETCS_ONBOARD_INPUTS_RAWS,
            ETCS_ONBOARD_INPUTS_TRAYS_SIZE, ETCS_ONBOARD_INPUTS_TRAYS
        },
        {
            151, "ETCS OnBoard Outputs",
            ETCS_ONBOARD_OUTPUTS_TAGS_SIZE, ETCS_ONBOARD_OUTPUTS_TAGS,
            ETCS_ONBOARD_OUTPUTS_IDENTIFIERS_SIZE, ETCS_ONBOARD_OUTPUTS_IDENTIFIERS,
            ETCS_ONBOARD_OUTPUTS_CONSTANTS_SIZE, ETCS_ONBOARD_OUTPUTS_CONSTANTS,
            ETCS_ONBOARD_OUTPUTS_SPECIFICATIONS_SIZE, ETCS_ONBOARD_OUTPUTS_SPECIFICATIONS,
            ETCS_ONBOARD_OUTPUTS_NUMBERS_SIZE, ETCS_ONBOARD_OUTPUTS_NUMBERS,
            ETCS_ONBOARD_OUTPUTS_RAWS_SIZE, ETCS_ONBOARD_OUTPUTS_RAWS,
            ETCS_ONBOARD_OUTPUTS_TRAYS_SIZE, ETCS_ONBOARD_OUTPUTS_TRAYS
        },
        {
            160, "ETCSVehicleInputs",
            ETCS_VEHICLE_INPUTS_TAGS_SIZE, ETCS_VEHICLE_INPUTS_TAGS,
            ETCS_VEHICLE_INPUTS_IDENTIFIERS_SIZE, ETCS_VEHICLE_INPUTS_IDENTIFIERS,
            ETCS_VEHICLE_INPUTS_CONSTANTS_SIZE, ETCS_VEHICLE_INPUTS_CONSTANTS,
            ETCS_VEHICLE_INPUTS_SPECIFICATIONS_SIZE, ETCS_VEHICLE_INPUTS_SPECIFICATIONS,
            ETCS_VEHICLE_INPUTS_NUMBERS_SIZE, ETCS_VEHICLE_INPUTS_NUMBERS,
            ETCS_VEHICLE_INPUTS_RAWS_SIZE, ETCS_VEHICLE_INPUTS_RAWS,
            ETCS_VEHICLE_INPUTS_TRAYS_SIZE, ETCS_VEHICLE_INPUTS_TRAYS
        },
        {
            161, "ETCSVehicleOutputs",
            ETCS_VEHICLE_OUTPUTS_TAGS_SIZE, ETCS_VEHICLE_OUTPUTS_TAGS,
            ETCS_VEHICLE_OUTPUTS_IDENTIFIERS_SIZE, ETCS_VEHICLE_OUTPUTS_IDENTIFIERS,
            ETCS_VEHICLE_OUTPUTS_CONSTANTS_SIZE, ETCS_VEHICLE_OUTPUTS_CONSTANTS,
            ETCS_VEHICLE_OUTPUTS_SPECIFICATIONS_SIZE, ETCS_VEHICLE_OUTPUTS_SPECIFICATIONS,
            ETCS_VEHICLE_OUTPUTS_NUMBERS_SIZE, ETCS_VEHICLE_OUTPUTS_NUMBERS,
            ETCS_VEHICLE_OUTPUTS_RAWS_SIZE, ETCS_VEHICLE_OUTPUTS_RAWS,
            ETCS_VEHICLE_OUTPUTS_TRAYS_SIZE, ETCS_VEHICLE_OUTPUTS_TRAYS
        },
        {
            204, "GSMRAreas",
            GSMR_AREAS_TAGS_SIZE, GSMR_AREAS_TAGS,
            GSMR_AREAS_IDENTIFIERS_SIZE, GSMR_AREAS_IDENTIFIERS,
            GSMR_AREAS_CONSTANTS_SIZE, GSMR_AREAS_CONSTANTS,
            GSMR_AREAS_SPECIFICATIONS_SIZE, GSMR_AREAS_SPECIFICATIONS,
            GSMR_AREAS_NUMBERS_SIZE, GSMR_AREAS_NUMBERS,
            GSMR_AREAS_RAWS_SIZE, GSMR_AREAS_RAWS,
            GSMR_AREAS_TRAYS_SIZE, GSMR_AREAS_TRAYS
        },
        {
            203, "GSMRArea",
            GSMR_AREA_TAGS_SIZE, GSMR_AREA_TAGS,
            GSMR_AREA_IDENTIFIERS_SIZE, GSMR_AREA_IDENTIFIERS,
            GSMR_AREA_CONSTANTS_SIZE, GSMR_AREA_CONSTANTS,
            GSMR_AREA_SPECIFICATIONS_SIZE, GSMR_AREA_SPECIFICATIONS,
            GSMR_AREA_NUMBERS_SIZE, GSMR_AREA_NUMBERS,
            GSMR_AREA_RAWS_SIZE, GSMR_AREA_RAWS,
            GSMR_AREA_TRAYS_SIZE, GSMR_AREA_TRAYS
        },
        {
            213, "GSMRCabInputs",
            GSMR_CAB_INPUTS_TAGS_SIZE, GSMR_CAB_INPUTS_TAGS,
            GSMR_CAB_INPUTS_IDENTIFIERS_SIZE, GSMR_CAB_INPUTS_IDENTIFIERS,
            GSMR_CAB_INPUTS_CONSTANTS_SIZE, GSMR_CAB_INPUTS_CONSTANTS,
            GSMR_CAB_INPUTS_SPECIFICATIONS_SIZE, GSMR_CAB_INPUTS_SPECIFICATIONS,
            GSMR_CAB_INPUTS_NUMBERS_SIZE, GSMR_CAB_INPUTS_NUMBERS,
            GSMR_CAB_INPUTS_RAWS_SIZE, GSMR_CAB_INPUTS_RAWS,
            GSMR_CAB_INPUTS_TRAYS_SIZE, GSMR_CAB_INPUTS_TRAYS
        },
        {
            211, "GSMRCabOutputs",
            GSMR_CAB_OUTPUTS_TAGS_SIZE, GSMR_CAB_OUTPUTS_TAGS,
            GSMR_CAB_OUTPUTS_IDENTIFIERS_SIZE, GSMR_CAB_OUTPUTS_IDENTIFIERS,
            GSMR_CAB_OUTPUTS_CONSTANTS_SIZE, GSMR_CAB_OUTPUTS_CONSTANTS,
            GSMR_CAB_OUTPUTS_SPECIFICATIONS_SIZE, GSMR_CAB_OUTPUTS_SPECIFICATIONS,
            GSMR_CAB_OUTPUTS_NUMBERS_SIZE, GSMR_CAB_OUTPUTS_NUMBERS,
            GSMR_CAB_OUTPUTS_RAWS_SIZE, GSMR_CAB_OUTPUTS_RAWS,
            GSMR_CAB_OUTPUTS_TRAYS_SIZE, GSMR_CAB_OUTPUTS_TRAYS
        },
        {
            212, "GSMRCabState",
            GSMR_CAB_STATE_TAGS_SIZE, GSMR_CAB_STATE_TAGS,
            GSMR_CAB_STATE_IDENTIFIERS_SIZE, GSMR_CAB_STATE_IDENTIFIERS,
            GSMR_CAB_STATE_CONSTANTS_SIZE, GSMR_CAB_STATE_CONSTANTS,
            GSMR_CAB_STATE_SPECIFICATIONS_SIZE, GSMR_CAB_STATE_SPECIFICATIONS,
            GSMR_CAB_STATE_NUMBERS_SIZE, GSMR_CAB_STATE_NUMBERS,
            GSMR_CAB_STATE_RAWS_SIZE, GSMR_CAB_STATE_RAWS,
            GSMR_CAB_STATE_TRAYS_SIZE, GSMR_CAB_STATE_TRAYS
        },
        {
            205, "GSMRCalls",
            GSMR_CALLS_TAGS_SIZE, GSMR_CALLS_TAGS,
            GSMR_CALLS_IDENTIFIERS_SIZE, GSMR_CALLS_IDENTIFIERS,
            GSMR_CALLS_CONSTANTS_SIZE, GSMR_CALLS_CONSTANTS,
            GSMR_CALLS_SPECIFICATIONS_SIZE, GSMR_CALLS_SPECIFICATIONS,
            GSMR_CALLS_NUMBERS_SIZE, GSMR_CALLS_NUMBERS,
            GSMR_CALLS_RAWS_SIZE, GSMR_CALLS_RAWS,
            GSMR_CALLS_TRAYS_SIZE, GSMR_CALLS_TRAYS
        },
        {
            214, "GSMRCall",
            GSMR_CALL_TAGS_SIZE, GSMR_CALL_TAGS,
            GSMR_CALL_IDENTIFIERS_SIZE, GSMR_CALL_IDENTIFIERS,
            GSMR_CALL_CONSTANTS_SIZE, GSMR_CALL_CONSTANTS,
            GSMR_CALL_SPECIFICATIONS_SIZE, GSMR_CALL_SPECIFICATIONS,
            GSMR_CALL_NUMBERS_SIZE, GSMR_CALL_NUMBERS,
            GSMR_CALL_RAWS_SIZE, GSMR_CALL_RAWS,
            GSMR_CALL_TRAYS_SIZE, GSMR_CALL_TRAYS
        },
        {
            208, "GSMRRequests",
            GSMR_REQUESTS_TAGS_SIZE, GSMR_REQUESTS_TAGS,
            GSMR_REQUESTS_IDENTIFIERS_SIZE, GSMR_REQUESTS_IDENTIFIERS,
            GSMR_REQUESTS_CONSTANTS_SIZE, GSMR_REQUESTS_CONSTANTS,
            GSMR_REQUESTS_SPECIFICATIONS_SIZE, GSMR_REQUESTS_SPECIFICATIONS,
            GSMR_REQUESTS_NUMBERS_SIZE, GSMR_REQUESTS_NUMBERS,
            GSMR_REQUESTS_RAWS_SIZE, GSMR_REQUESTS_RAWS,
            GSMR_REQUESTS_TRAYS_SIZE, GSMR_REQUESTS_TRAYS
        },
        {
            210, "GSMRAreaControlRequest",
            GSMR_AREA_CONTROL_REQUEST_TAGS_SIZE, GSMR_AREA_CONTROL_REQUEST_TAGS,
            GSMR_AREA_CONTROL_REQUEST_IDENTIFIERS_SIZE, GSMR_AREA_CONTROL_REQUEST_IDENTIFIERS,
            GSMR_AREA_CONTROL_REQUEST_CONSTANTS_SIZE, GSMR_AREA_CONTROL_REQUEST_CONSTANTS,
            GSMR_AREA_CONTROL_REQUEST_SPECIFICATIONS_SIZE, GSMR_AREA_CONTROL_REQUEST_SPECIFICATIONS,
            GSMR_AREA_CONTROL_REQUEST_NUMBERS_SIZE, GSMR_AREA_CONTROL_REQUEST_NUMBERS,
            GSMR_AREA_CONTROL_REQUEST_RAWS_SIZE, GSMR_AREA_CONTROL_REQUEST_RAWS,
            GSMR_AREA_CONTROL_REQUEST_TRAYS_SIZE, GSMR_AREA_CONTROL_REQUEST_TRAYS
        },
        {
            201, "GSMRCallRequest",
            GSMR_CALL_REQUEST_TAGS_SIZE, GSMR_CALL_REQUEST_TAGS,
            GSMR_CALL_REQUEST_IDENTIFIERS_SIZE, GSMR_CALL_REQUEST_IDENTIFIERS,
            GSMR_CALL_REQUEST_CONSTANTS_SIZE, GSMR_CALL_REQUEST_CONSTANTS,
            GSMR_CALL_REQUEST_SPECIFICATIONS_SIZE, GSMR_CALL_REQUEST_SPECIFICATIONS,
            GSMR_CALL_REQUEST_NUMBERS_SIZE, GSMR_CALL_REQUEST_NUMBERS,
            GSMR_CALL_REQUEST_RAWS_SIZE, GSMR_CALL_REQUEST_RAWS,
            GSMR_CALL_REQUEST_TRAYS_SIZE, GSMR_CALL_REQUEST_TRAYS
        },
        {
            202, "GSMRCallUpdateRequest",
            GSMR_CALL_UPDATE_REQUEST_TAGS_SIZE, GSMR_CALL_UPDATE_REQUEST_TAGS,
            GSMR_CALL_UPDATE_REQUEST_IDENTIFIERS_SIZE, GSMR_CALL_UPDATE_REQUEST_IDENTIFIERS,
            GSMR_CALL_UPDATE_REQUEST_CONSTANTS_SIZE, GSMR_CALL_UPDATE_REQUEST_CONSTANTS,
            GSMR_CALL_UPDATE_REQUEST_SPECIFICATIONS_SIZE, GSMR_CALL_UPDATE_REQUEST_SPECIFICATIONS,
            GSMR_CALL_UPDATE_REQUEST_NUMBERS_SIZE, GSMR_CALL_UPDATE_REQUEST_NUMBERS,
            GSMR_CALL_UPDATE_REQUEST_RAWS_SIZE, GSMR_CALL_UPDATE_REQUEST_RAWS,
            GSMR_CALL_UPDATE_REQUEST_TRAYS_SIZE, GSMR_CALL_UPDATE_REQUEST_TRAYS
        },
        {
            209, "GSMRSMSRequest",
            GSMR_SMS_REQUEST_TAGS_SIZE, GSMR_SMS_REQUEST_TAGS,
            GSMR_SMS_REQUEST_IDENTIFIERS_SIZE, GSMR_SMS_REQUEST_IDENTIFIERS,
            GSMR_SMS_REQUEST_CONSTANTS_SIZE, GSMR_SMS_REQUEST_CONSTANTS,
            GSMR_SMS_REQUEST_SPECIFICATIONS_SIZE, GSMR_SMS_REQUEST_SPECIFICATIONS,
            GSMR_SMS_REQUEST_NUMBERS_SIZE, GSMR_SMS_REQUEST_NUMBERS,
            GSMR_SMS_REQUEST_RAWS_SIZE, GSMR_SMS_REQUEST_RAWS,
            GSMR_SMS_REQUEST_TRAYS_SIZE, GSMR_SMS_REQUEST_TRAYS
        },
        {
            206, "GSMRClient",
            GSMR_CLIENT_TAGS_SIZE, GSMR_CLIENT_TAGS,
            GSMR_CLIENT_IDENTIFIERS_SIZE, GSMR_CLIENT_IDENTIFIERS,
            GSMR_CLIENT_CONSTANTS_SIZE, GSMR_CLIENT_CONSTANTS,
            GSMR_CLIENT_SPECIFICATIONS_SIZE, GSMR_CLIENT_SPECIFICATIONS,
            GSMR_CLIENT_NUMBERS_SIZE, GSMR_CLIENT_NUMBERS,
            GSMR_CLIENT_RAWS_SIZE, GSMR_CLIENT_RAWS,
            GSMR_CLIENT_TRAYS_SIZE, GSMR_CLIENT_TRAYS
        },
        {
            207, "GSMRNetwork",
            GSMR_NETWORK_TAGS_SIZE, GSMR_NETWORK_TAGS,
            GSMR_NETWORK_IDENTIFIERS_SIZE, GSMR_NETWORK_IDENTIFIERS,
            GSMR_NETWORK_CONSTANTS_SIZE, GSMR_NETWORK_CONSTANTS,
            GSMR_NETWORK_SPECIFICATIONS_SIZE, GSMR_NETWORK_SPECIFICATIONS,
            GSMR_NETWORK_NUMBERS_SIZE, GSMR_NETWORK_NUMBERS,
            GSMR_NETWORK_RAWS_SIZE, GSMR_NETWORK_RAWS,
            GSMR_NETWORK_TRAYS_SIZE, GSMR_NETWORK_TRAYS
        },
        {
            1001, "ReferenceTrain",
            REFERENCE_TRAIN_TAGS_SIZE, REFERENCE_TRAIN_TAGS,
            REFERENCE_TRAIN_IDENTIFIERS_SIZE, REFERENCE_TRAIN_IDENTIFIERS,
            REFERENCE_TRAIN_CONSTANTS_SIZE, REFERENCE_TRAIN_CONSTANTS,
            REFERENCE_TRAIN_SPECIFICATIONS_SIZE, REFERENCE_TRAIN_SPECIFICATIONS,
            REFERENCE_TRAIN_NUMBERS_SIZE, REFERENCE_TRAIN_NUMBERS,
            REFERENCE_TRAIN_RAWS_SIZE, REFERENCE_TRAIN_RAWS,
            REFERENCE_TRAIN_TRAYS_SIZE, REFERENCE_TRAIN_TRAYS
        },
        {
            401, "IDU",
            IDU_TAGS_SIZE, IDU_TAGS,
            IDU_IDENTIFIERS_SIZE, IDU_IDENTIFIERS,
            IDU_CONSTANTS_SIZE, IDU_CONSTANTS,
            IDU_SPECIFICATIONS_SIZE, IDU_SPECIFICATIONS,
            IDU_NUMBERS_SIZE, IDU_NUMBERS,
            IDU_RAWS_SIZE, IDU_RAWS,
            IDU_TRAYS_SIZE, IDU_TRAYS
        },
        {
            402, "IDUOutputs",
            IDU_OUTPUTS_TAGS_SIZE, IDU_OUTPUTS_TAGS,
            IDU_OUTPUTS_IDENTIFIERS_SIZE, IDU_OUTPUTS_IDENTIFIERS,
            IDU_OUTPUTS_CONSTANTS_SIZE, IDU_OUTPUTS_CONSTANTS,
            IDU_OUTPUTS_SPECIFICATIONS_SIZE, IDU_OUTPUTS_SPECIFICATIONS,
            IDU_OUTPUTS_NUMBERS_SIZE, IDU_OUTPUTS_NUMBERS,
            IDU_OUTPUTS_RAWS_SIZE, IDU_OUTPUTS_RAWS,
            IDU_OUTPUTS_TRAYS_SIZE, IDU_OUTPUTS_TRAYS
        },
        {
            403, "IDUInputs",
            IDU_INPUTS_TAGS_SIZE, IDU_INPUTS_TAGS,
            IDU_INPUTS_IDENTIFIERS_SIZE, IDU_INPUTS_IDENTIFIERS,
            IDU_INPUTS_CONSTANTS_SIZE, IDU_INPUTS_CONSTANTS,
            IDU_INPUTS_SPECIFICATIONS_SIZE, IDU_INPUTS_SPECIFICATIONS,
            IDU_INPUTS_NUMBERS_SIZE, IDU_INPUTS_NUMBERS,
            IDU_INPUTS_RAWS_SIZE, IDU_INPUTS_RAWS,
            IDU_INPUTS_TRAYS_SIZE, IDU_INPUTS_TRAYS
        },
        {
            404, "IDUInputsValues",
            IDU_INPUTS_VALUES_TAGS_SIZE, IDU_INPUTS_VALUES_TAGS,
            IDU_INPUTS_VALUES_IDENTIFIERS_SIZE, IDU_INPUTS_VALUES_IDENTIFIERS,
            IDU_INPUTS_VALUES_CONSTANTS_SIZE, IDU_INPUTS_VALUES_CONSTANTS,
            IDU_INPUTS_VALUES_SPECIFICATIONS_SIZE, IDU_INPUTS_VALUES_SPECIFICATIONS,
            IDU_INPUTS_VALUES_NUMBERS_SIZE, IDU_INPUTS_VALUES_NUMBERS,
            IDU_INPUTS_VALUES_RAWS_SIZE, IDU_INPUTS_VALUES_RAWS,
            IDU_INPUTS_VALUES_TRAYS_SIZE, IDU_INPUTS_VALUES_TRAYS
        },
        {
            405, "IDUInputsModes",
            IDU_INPUTS_MODES_TAGS_SIZE, IDU_INPUTS_MODES_TAGS,
            IDU_INPUTS_MODES_IDENTIFIERS_SIZE, IDU_INPUTS_MODES_IDENTIFIERS,
            IDU_INPUTS_MODES_CONSTANTS_SIZE, IDU_INPUTS_MODES_CONSTANTS,
            IDU_INPUTS_MODES_SPECIFICATIONS_SIZE, IDU_INPUTS_MODES_SPECIFICATIONS,
            IDU_INPUTS_MODES_NUMBERS_SIZE, IDU_INPUTS_MODES_NUMBERS,
            IDU_INPUTS_MODES_RAWS_SIZE, IDU_INPUTS_MODES_RAWS,
            IDU_INPUTS_MODES_TRAYS_SIZE, IDU_INPUTS_MODES_TRAYS
        },
        {
            406, "IDUVehicleInputs",
            IDU_VEHICLE_INPUTS_TAGS_SIZE, IDU_VEHICLE_INPUTS_TAGS,
            IDU_VEHICLE_INPUTS_IDENTIFIERS_SIZE, IDU_VEHICLE_INPUTS_IDENTIFIERS,
            IDU_VEHICLE_INPUTS_CONSTANTS_SIZE, IDU_VEHICLE_INPUTS_CONSTANTS,
            IDU_VEHICLE_INPUTS_SPECIFICATIONS_SIZE, IDU_VEHICLE_INPUTS_SPECIFICATIONS,
            IDU_VEHICLE_INPUTS_NUMBERS_SIZE, IDU_VEHICLE_INPUTS_NUMBERS,
            IDU_VEHICLE_INPUTS_RAWS_SIZE, IDU_VEHICLE_INPUTS_RAWS,
            IDU_VEHICLE_INPUTS_TRAYS_SIZE, IDU_VEHICLE_INPUTS_TRAYS
        },
        {
            407, "IDUVehicleOutputs",
            IDU_VEHICLE_OUTPUTS_TAGS_SIZE, IDU_VEHICLE_OUTPUTS_TAGS,
            IDU_VEHICLE_OUTPUTS_IDENTIFIERS_SIZE, IDU_VEHICLE_OUTPUTS_IDENTIFIERS,
            IDU_VEHICLE_OUTPUTS_CONSTANTS_SIZE, IDU_VEHICLE_OUTPUTS_CONSTANTS,
            IDU_VEHICLE_OUTPUTS_SPECIFICATIONS_SIZE, IDU_VEHICLE_OUTPUTS_SPECIFICATIONS,
            IDU_VEHICLE_OUTPUTS_NUMBERS_SIZE, IDU_VEHICLE_OUTPUTS_NUMBERS,
            IDU_VEHICLE_OUTPUTS_RAWS_SIZE, IDU_VEHICLE_OUTPUTS_RAWS,
            IDU_VEHICLE_OUTPUTS_TRAYS_SIZE, IDU_VEHICLE_OUTPUTS_TRAYS
        },
        {
            410, "TCMS Faults",
            TCMS_FAULTS_TAGS_SIZE, TCMS_FAULTS_TAGS,
            TCMS_FAULTS_IDENTIFIERS_SIZE, TCMS_FAULTS_IDENTIFIERS,
            TCMS_FAULTS_CONSTANTS_SIZE, TCMS_FAULTS_CONSTANTS,
            TCMS_FAULTS_SPECIFICATIONS_SIZE, TCMS_FAULTS_SPECIFICATIONS,
            TCMS_FAULTS_NUMBERS_SIZE, TCMS_FAULTS_NUMBERS,
            TCMS_FAULTS_RAWS_SIZE, TCMS_FAULTS_RAWS,
            TCMS_FAULTS_TRAYS_SIZE, TCMS_FAULTS_TRAYS
        },
        {
            411, "TCMS Fault",
            TCMS_FAULT_TAGS_SIZE, TCMS_FAULT_TAGS,
            TCMS_FAULT_IDENTIFIERS_SIZE, TCMS_FAULT_IDENTIFIERS,
            TCMS_FAULT_CONSTANTS_SIZE, TCMS_FAULT_CONSTANTS,
            TCMS_FAULT_SPECIFICATIONS_SIZE, TCMS_FAULT_SPECIFICATIONS,
            TCMS_FAULT_NUMBERS_SIZE, TCMS_FAULT_NUMBERS,
            TCMS_FAULT_RAWS_SIZE, TCMS_FAULT_RAWS,
            TCMS_FAULT_TRAYS_SIZE, TCMS_FAULT_TRAYS
        },
        {
            430, "TRN",
            TRN_TAGS_SIZE, TRN_TAGS,
            TRN_IDENTIFIERS_SIZE, TRN_IDENTIFIERS,
            TRN_CONSTANTS_SIZE, TRN_CONSTANTS,
            TRN_SPECIFICATIONS_SIZE, TRN_SPECIFICATIONS,
            TRN_NUMBERS_SIZE, TRN_NUMBERS,
            TRN_RAWS_SIZE, TRN_RAWS,
            TRN_TRAYS_SIZE, TRN_TRAYS
        },
        {
            414, "IDUCCTVInputs",
            IDU_CCTV_INPUTS_TAGS_SIZE, IDU_CCTV_INPUTS_TAGS,
            IDU_CCTV_INPUTS_IDENTIFIERS_SIZE, IDU_CCTV_INPUTS_IDENTIFIERS,
            IDU_CCTV_INPUTS_CONSTANTS_SIZE, IDU_CCTV_INPUTS_CONSTANTS,
            IDU_CCTV_INPUTS_SPECIFICATIONS_SIZE, IDU_CCTV_INPUTS_SPECIFICATIONS,
            IDU_CCTV_INPUTS_NUMBERS_SIZE, IDU_CCTV_INPUTS_NUMBERS,
            IDU_CCTV_INPUTS_RAWS_SIZE, IDU_CCTV_INPUTS_RAWS,
            IDU_CCTV_INPUTS_TRAYS_SIZE, IDU_CCTV_INPUTS_TRAYS
        },
        {
            415, "IDUCCTVOutputs",
            IDU_CCTV_OUTPUTS_TAGS_SIZE, IDU_CCTV_OUTPUTS_TAGS,
            IDU_CCTV_OUTPUTS_IDENTIFIERS_SIZE, IDU_CCTV_OUTPUTS_IDENTIFIERS,
            IDU_CCTV_OUTPUTS_CONSTANTS_SIZE, IDU_CCTV_OUTPUTS_CONSTANTS,
            IDU_CCTV_OUTPUTS_SPECIFICATIONS_SIZE, IDU_CCTV_OUTPUTS_SPECIFICATIONS,
            IDU_CCTV_OUTPUTS_NUMBERS_SIZE, IDU_CCTV_OUTPUTS_NUMBERS,
            IDU_CCTV_OUTPUTS_RAWS_SIZE, IDU_CCTV_OUTPUTS_RAWS,
            IDU_CCTV_OUTPUTS_TRAYS_SIZE, IDU_CCTV_OUTPUTS_TRAYS
        },
        {
            416, "DOOInputs",
            DOO_INPUTS_TAGS_SIZE, DOO_INPUTS_TAGS,
            DOO_INPUTS_IDENTIFIERS_SIZE, DOO_INPUTS_IDENTIFIERS,
            DOO_INPUTS_CONSTANTS_SIZE, DOO_INPUTS_CONSTANTS,
            DOO_INPUTS_SPECIFICATIONS_SIZE, DOO_INPUTS_SPECIFICATIONS,
            DOO_INPUTS_NUMBERS_SIZE, DOO_INPUTS_NUMBERS,
            DOO_INPUTS_RAWS_SIZE, DOO_INPUTS_RAWS,
            DOO_INPUTS_TRAYS_SIZE, DOO_INPUTS_TRAYS
        },
        {
            417, "DOOOutputs",
            DOO_OUTPUTS_TAGS_SIZE, DOO_OUTPUTS_TAGS,
            DOO_OUTPUTS_IDENTIFIERS_SIZE, DOO_OUTPUTS_IDENTIFIERS,
            DOO_OUTPUTS_CONSTANTS_SIZE, DOO_OUTPUTS_CONSTANTS,
            DOO_OUTPUTS_SPECIFICATIONS_SIZE, DOO_OUTPUTS_SPECIFICATIONS,
            DOO_OUTPUTS_NUMBERS_SIZE, DOO_OUTPUTS_NUMBERS,
            DOO_OUTPUTS_RAWS_SIZE, DOO_OUTPUTS_RAWS,
            DOO_OUTPUTS_TRAYS_SIZE, DOO_OUTPUTS_TRAYS
        },
        {
            418, "PISInputs",
            PIS_INPUTS_TAGS_SIZE, PIS_INPUTS_TAGS,
            PIS_INPUTS_IDENTIFIERS_SIZE, PIS_INPUTS_IDENTIFIERS,
            PIS_INPUTS_CONSTANTS_SIZE, PIS_INPUTS_CONSTANTS,
            PIS_INPUTS_SPECIFICATIONS_SIZE, PIS_INPUTS_SPECIFICATIONS,
            PIS_INPUTS_NUMBERS_SIZE, PIS_INPUTS_NUMBERS,
            PIS_INPUTS_RAWS_SIZE, PIS_INPUTS_RAWS,
            PIS_INPUTS_TRAYS_SIZE, PIS_INPUTS_TRAYS
        },
        {
            419, "PISOutputs",
            PIS_OUTPUTS_TAGS_SIZE, PIS_OUTPUTS_TAGS,
            PIS_OUTPUTS_IDENTIFIERS_SIZE, PIS_OUTPUTS_IDENTIFIERS,
            PIS_OUTPUTS_CONSTANTS_SIZE, PIS_OUTPUTS_CONSTANTS,
            PIS_OUTPUTS_SPECIFICATIONS_SIZE, PIS_OUTPUTS_SPECIFICATIONS,
            PIS_OUTPUTS_NUMBERS_SIZE, PIS_OUTPUTS_NUMBERS,
            PIS_OUTPUTS_RAWS_SIZE, PIS_OUTPUTS_RAWS,
            PIS_OUTPUTS_TRAYS_SIZE, PIS_OUTPUTS_TRAYS
        },
        {
            422, "DMI",
            DMI_TAGS_SIZE, DMI_TAGS,
            DMI_IDENTIFIERS_SIZE, DMI_IDENTIFIERS,
            DMI_CONSTANTS_SIZE, DMI_CONSTANTS,
            DMI_SPECIFICATIONS_SIZE, DMI_SPECIFICATIONS,
            DMI_NUMBERS_SIZE, DMI_NUMBERS,
            DMI_RAWS_SIZE, DMI_RAWS,
            DMI_TRAYS_SIZE, DMI_TRAYS
        },
        {
            420, "DMIOutputs",
            DMI_OUTPUTS_TAGS_SIZE, DMI_OUTPUTS_TAGS,
            DMI_OUTPUTS_IDENTIFIERS_SIZE, DMI_OUTPUTS_IDENTIFIERS,
            DMI_OUTPUTS_CONSTANTS_SIZE, DMI_OUTPUTS_CONSTANTS,
            DMI_OUTPUTS_SPECIFICATIONS_SIZE, DMI_OUTPUTS_SPECIFICATIONS,
            DMI_OUTPUTS_NUMBERS_SIZE, DMI_OUTPUTS_NUMBERS,
            DMI_OUTPUTS_RAWS_SIZE, DMI_OUTPUTS_RAWS,
            DMI_OUTPUTS_TRAYS_SIZE, DMI_OUTPUTS_TRAYS
        },
        {
            421, "DMIInputs",
            DMI_INPUTS_TAGS_SIZE, DMI_INPUTS_TAGS,
            DMI_INPUTS_IDENTIFIERS_SIZE, DMI_INPUTS_IDENTIFIERS,
            DMI_INPUTS_CONSTANTS_SIZE, DMI_INPUTS_CONSTANTS,
            DMI_INPUTS_SPECIFICATIONS_SIZE, DMI_INPUTS_SPECIFICATIONS,
            DMI_INPUTS_NUMBERS_SIZE, DMI_INPUTS_NUMBERS,
            DMI_INPUTS_RAWS_SIZE, DMI_INPUTS_RAWS,
            DMI_INPUTS_TRAYS_SIZE, DMI_INPUTS_TRAYS
        },
        {
            423, "DMIInputsValues",
            DMI_INPUTS_VALUES_TAGS_SIZE, DMI_INPUTS_VALUES_TAGS,
            DMI_INPUTS_VALUES_IDENTIFIERS_SIZE, DMI_INPUTS_VALUES_IDENTIFIERS,
            DMI_INPUTS_VALUES_CONSTANTS_SIZE, DMI_INPUTS_VALUES_CONSTANTS,
            DMI_INPUTS_VALUES_SPECIFICATIONS_SIZE, DMI_INPUTS_VALUES_SPECIFICATIONS,
            DMI_INPUTS_VALUES_NUMBERS_SIZE, DMI_INPUTS_VALUES_NUMBERS,
            DMI_INPUTS_VALUES_RAWS_SIZE, DMI_INPUTS_VALUES_RAWS,
            DMI_INPUTS_VALUES_TRAYS_SIZE, DMI_INPUTS_VALUES_TRAYS
        },
        {
            424, "DMIInputsModes",
            DMI_INPUTS_MODES_TAGS_SIZE, DMI_INPUTS_MODES_TAGS,
            DMI_INPUTS_MODES_IDENTIFIERS_SIZE, DMI_INPUTS_MODES_IDENTIFIERS,
            DMI_INPUTS_MODES_CONSTANTS_SIZE, DMI_INPUTS_MODES_CONSTANTS,
            DMI_INPUTS_MODES_SPECIFICATIONS_SIZE, DMI_INPUTS_MODES_SPECIFICATIONS,
            DMI_INPUTS_MODES_NUMBERS_SIZE, DMI_INPUTS_MODES_NUMBERS,
            DMI_INPUTS_MODES_RAWS_SIZE, DMI_INPUTS_MODES_RAWS,
            DMI_INPUTS_MODES_TRAYS_SIZE, DMI_INPUTS_MODES_TRAYS
        },
        {
            425, "DMIVehicleInputs",
            DMI_VEHICLE_INPUTS_TAGS_SIZE, DMI_VEHICLE_INPUTS_TAGS,
            DMI_VEHICLE_INPUTS_IDENTIFIERS_SIZE, DMI_VEHICLE_INPUTS_IDENTIFIERS,
            DMI_VEHICLE_INPUTS_CONSTANTS_SIZE, DMI_VEHICLE_INPUTS_CONSTANTS,
            DMI_VEHICLE_INPUTS_SPECIFICATIONS_SIZE, DMI_VEHICLE_INPUTS_SPECIFICATIONS,
            DMI_VEHICLE_INPUTS_NUMBERS_SIZE, DMI_VEHICLE_INPUTS_NUMBERS,
            DMI_VEHICLE_INPUTS_RAWS_SIZE, DMI_VEHICLE_INPUTS_RAWS,
            DMI_VEHICLE_INPUTS_TRAYS_SIZE, DMI_VEHICLE_INPUTS_TRAYS
        },
        {
            426, "DMIVehicleOutputs",
            DMI_VEHICLE_OUTPUTS_TAGS_SIZE, DMI_VEHICLE_OUTPUTS_TAGS,
            DMI_VEHICLE_OUTPUTS_IDENTIFIERS_SIZE, DMI_VEHICLE_OUTPUTS_IDENTIFIERS,
            DMI_VEHICLE_OUTPUTS_CONSTANTS_SIZE, DMI_VEHICLE_OUTPUTS_CONSTANTS,
            DMI_VEHICLE_OUTPUTS_SPECIFICATIONS_SIZE, DMI_VEHICLE_OUTPUTS_SPECIFICATIONS,
            DMI_VEHICLE_OUTPUTS_NUMBERS_SIZE, DMI_VEHICLE_OUTPUTS_NUMBERS,
            DMI_VEHICLE_OUTPUTS_RAWS_SIZE, DMI_VEHICLE_OUTPUTS_RAWS,
            DMI_VEHICLE_OUTPUTS_TRAYS_SIZE, DMI_VEHICLE_OUTPUTS_TRAYS
        },
        {
            427, "DOOVehicleOutputs",
            DOO_VEHICLE_OUTPUTS_TAGS_SIZE, DOO_VEHICLE_OUTPUTS_TAGS,
            DOO_VEHICLE_OUTPUTS_IDENTIFIERS_SIZE, DOO_VEHICLE_OUTPUTS_IDENTIFIERS,
            DOO_VEHICLE_OUTPUTS_CONSTANTS_SIZE, DOO_VEHICLE_OUTPUTS_CONSTANTS,
            DOO_VEHICLE_OUTPUTS_SPECIFICATIONS_SIZE, DOO_VEHICLE_OUTPUTS_SPECIFICATIONS,
            DOO_VEHICLE_OUTPUTS_NUMBERS_SIZE, DOO_VEHICLE_OUTPUTS_NUMBERS,
            DOO_VEHICLE_OUTPUTS_RAWS_SIZE, DOO_VEHICLE_OUTPUTS_RAWS,
            DOO_VEHICLE_OUTPUTS_TRAYS_SIZE, DOO_VEHICLE_OUTPUTS_TRAYS
        },
        {
            1002, "CBTCTrainInputs",
            CBTC_TRAIN_INPUTS_TAGS_SIZE, CBTC_TRAIN_INPUTS_TAGS,
            CBTC_TRAIN_INPUTS_IDENTIFIERS_SIZE, CBTC_TRAIN_INPUTS_IDENTIFIERS,
            CBTC_TRAIN_INPUTS_CONSTANTS_SIZE, CBTC_TRAIN_INPUTS_CONSTANTS,
            CBTC_TRAIN_INPUTS_SPECIFICATIONS_SIZE, CBTC_TRAIN_INPUTS_SPECIFICATIONS,
            CBTC_TRAIN_INPUTS_NUMBERS_SIZE, CBTC_TRAIN_INPUTS_NUMBERS,
            CBTC_TRAIN_INPUTS_RAWS_SIZE, CBTC_TRAIN_INPUTS_RAWS,
            CBTC_TRAIN_INPUTS_TRAYS_SIZE, CBTC_TRAIN_INPUTS_TRAYS
        },
        {
            1005, "ATPProfile",
            ATP_PROFILE_TAGS_SIZE, ATP_PROFILE_TAGS,
            ATP_PROFILE_IDENTIFIERS_SIZE, ATP_PROFILE_IDENTIFIERS,
            ATP_PROFILE_CONSTANTS_SIZE, ATP_PROFILE_CONSTANTS,
            ATP_PROFILE_SPECIFICATIONS_SIZE, ATP_PROFILE_SPECIFICATIONS,
            ATP_PROFILE_NUMBERS_SIZE, ATP_PROFILE_NUMBERS,
            ATP_PROFILE_RAWS_SIZE, ATP_PROFILE_RAWS,
            ATP_PROFILE_TRAYS_SIZE, ATP_PROFILE_TRAYS
        },
        {
            1003, "CBTCTrainOutputs",
            CBTC_TRAIN_OUTPUTS_TAGS_SIZE, CBTC_TRAIN_OUTPUTS_TAGS,
            CBTC_TRAIN_OUTPUTS_IDENTIFIERS_SIZE, CBTC_TRAIN_OUTPUTS_IDENTIFIERS,
            CBTC_TRAIN_OUTPUTS_CONSTANTS_SIZE, CBTC_TRAIN_OUTPUTS_CONSTANTS,
            CBTC_TRAIN_OUTPUTS_SPECIFICATIONS_SIZE, CBTC_TRAIN_OUTPUTS_SPECIFICATIONS,
            CBTC_TRAIN_OUTPUTS_NUMBERS_SIZE, CBTC_TRAIN_OUTPUTS_NUMBERS,
            CBTC_TRAIN_OUTPUTS_RAWS_SIZE, CBTC_TRAIN_OUTPUTS_RAWS,
            CBTC_TRAIN_OUTPUTS_TRAYS_SIZE, CBTC_TRAIN_OUTPUTS_TRAYS
        },
        {
            1004, "CBTCVehicleOutputs",
            CBTC_VEHICLE_OUTPUTS_TAGS_SIZE, CBTC_VEHICLE_OUTPUTS_TAGS,
            CBTC_VEHICLE_OUTPUTS_IDENTIFIERS_SIZE, CBTC_VEHICLE_OUTPUTS_IDENTIFIERS,
            CBTC_VEHICLE_OUTPUTS_CONSTANTS_SIZE, CBTC_VEHICLE_OUTPUTS_CONSTANTS,
            CBTC_VEHICLE_OUTPUTS_SPECIFICATIONS_SIZE, CBTC_VEHICLE_OUTPUTS_SPECIFICATIONS,
            CBTC_VEHICLE_OUTPUTS_NUMBERS_SIZE, CBTC_VEHICLE_OUTPUTS_NUMBERS,
            CBTC_VEHICLE_OUTPUTS_RAWS_SIZE, CBTC_VEHICLE_OUTPUTS_RAWS,
            CBTC_VEHICLE_OUTPUTS_TRAYS_SIZE, CBTC_VEHICLE_OUTPUTS_TRAYS
        },
        {
            1000, "ModelDebug",
            MODEL_DEBUG_TAGS_SIZE, MODEL_DEBUG_TAGS,
            MODEL_DEBUG_IDENTIFIERS_SIZE, MODEL_DEBUG_IDENTIFIERS,
            MODEL_DEBUG_CONSTANTS_SIZE, MODEL_DEBUG_CONSTANTS,
            MODEL_DEBUG_SPECIFICATIONS_SIZE, MODEL_DEBUG_SPECIFICATIONS,
            MODEL_DEBUG_NUMBERS_SIZE, MODEL_DEBUG_NUMBERS,
            MODEL_DEBUG_RAWS_SIZE, MODEL_DEBUG_RAWS,
            MODEL_DEBUG_TRAYS_SIZE, MODEL_DEBUG_TRAYS
        },
        {
            801, "CBTC Platform Inputs",
            CBTC_PLATFORM_INPUTS_TAGS_SIZE, CBTC_PLATFORM_INPUTS_TAGS,
            CBTC_PLATFORM_INPUTS_IDENTIFIERS_SIZE, CBTC_PLATFORM_INPUTS_IDENTIFIERS,
            CBTC_PLATFORM_INPUTS_CONSTANTS_SIZE, CBTC_PLATFORM_INPUTS_CONSTANTS,
            CBTC_PLATFORM_INPUTS_SPECIFICATIONS_SIZE, CBTC_PLATFORM_INPUTS_SPECIFICATIONS,
            CBTC_PLATFORM_INPUTS_NUMBERS_SIZE, CBTC_PLATFORM_INPUTS_NUMBERS,
            CBTC_PLATFORM_INPUTS_RAWS_SIZE, CBTC_PLATFORM_INPUTS_RAWS,
            CBTC_PLATFORM_INPUTS_TRAYS_SIZE, CBTC_PLATFORM_INPUTS_TRAYS
        },
        {
            802, "LMA",
            LMA_TAGS_SIZE, LMA_TAGS,
            LMA_IDENTIFIERS_SIZE, LMA_IDENTIFIERS,
            LMA_CONSTANTS_SIZE, LMA_CONSTANTS,
            LMA_SPECIFICATIONS_SIZE, LMA_SPECIFICATIONS,
            LMA_NUMBERS_SIZE, LMA_NUMBERS,
            LMA_RAWS_SIZE, LMA_RAWS,
            LMA_TRAYS_SIZE, LMA_TRAYS
        },
        {
            803, "CBTC Speed Limit",
            CBTC_SPEED_LIMIT_TAGS_SIZE, CBTC_SPEED_LIMIT_TAGS,
            CBTC_SPEED_LIMIT_IDENTIFIERS_SIZE, CBTC_SPEED_LIMIT_IDENTIFIERS,
            CBTC_SPEED_LIMIT_CONSTANTS_SIZE, CBTC_SPEED_LIMIT_CONSTANTS,
            CBTC_SPEED_LIMIT_SPECIFICATIONS_SIZE, CBTC_SPEED_LIMIT_SPECIFICATIONS,
            CBTC_SPEED_LIMIT_NUMBERS_SIZE, CBTC_SPEED_LIMIT_NUMBERS,
            CBTC_SPEED_LIMIT_RAWS_SIZE, CBTC_SPEED_LIMIT_RAWS,
            CBTC_SPEED_LIMIT_TRAYS_SIZE, CBTC_SPEED_LIMIT_TRAYS
        },
        {
            10000, "DualCab",
            DUAL_CAB_TAGS_SIZE, DUAL_CAB_TAGS,
            DUAL_CAB_IDENTIFIERS_SIZE, DUAL_CAB_IDENTIFIERS,
            DUAL_CAB_CONSTANTS_SIZE, DUAL_CAB_CONSTANTS,
            DUAL_CAB_SPECIFICATIONS_SIZE, DUAL_CAB_SPECIFICATIONS,
            DUAL_CAB_NUMBERS_SIZE, DUAL_CAB_NUMBERS,
            DUAL_CAB_RAWS_SIZE, DUAL_CAB_RAWS,
            DUAL_CAB_TRAYS_SIZE, DUAL_CAB_TRAYS
        },
        {
            10001, "DualCabControlInputs",
            DUAL_CAB_CONTROL_INPUTS_TAGS_SIZE, DUAL_CAB_CONTROL_INPUTS_TAGS,
            DUAL_CAB_CONTROL_INPUTS_IDENTIFIERS_SIZE, DUAL_CAB_CONTROL_INPUTS_IDENTIFIERS,
            DUAL_CAB_CONTROL_INPUTS_CONSTANTS_SIZE, DUAL_CAB_CONTROL_INPUTS_CONSTANTS,
            DUAL_CAB_CONTROL_INPUTS_SPECIFICATIONS_SIZE, DUAL_CAB_CONTROL_INPUTS_SPECIFICATIONS,
            DUAL_CAB_CONTROL_INPUTS_NUMBERS_SIZE, DUAL_CAB_CONTROL_INPUTS_NUMBERS,
            DUAL_CAB_CONTROL_INPUTS_RAWS_SIZE, DUAL_CAB_CONTROL_INPUTS_RAWS,
            DUAL_CAB_CONTROL_INPUTS_TRAYS_SIZE, DUAL_CAB_CONTROL_INPUTS_TRAYS
        },
        {
            2001, "ETCS RBC",
            ETCS_RBC_TAGS_SIZE, ETCS_RBC_TAGS,
            ETCS_RBC_IDENTIFIERS_SIZE, ETCS_RBC_IDENTIFIERS,
            ETCS_RBC_CONSTANTS_SIZE, ETCS_RBC_CONSTANTS,
            ETCS_RBC_SPECIFICATIONS_SIZE, ETCS_RBC_SPECIFICATIONS,
            ETCS_RBC_NUMBERS_SIZE, ETCS_RBC_NUMBERS,
            ETCS_RBC_RAWS_SIZE, ETCS_RBC_RAWS,
            ETCS_RBC_TRAYS_SIZE, ETCS_RBC_TRAYS
        },
        {
            2002, "Track Events",
            TRACK_EVENTS_TAGS_SIZE, TRACK_EVENTS_TAGS,
            TRACK_EVENTS_IDENTIFIERS_SIZE, TRACK_EVENTS_IDENTIFIERS,
            TRACK_EVENTS_CONSTANTS_SIZE, TRACK_EVENTS_CONSTANTS,
            TRACK_EVENTS_SPECIFICATIONS_SIZE, TRACK_EVENTS_SPECIFICATIONS,
            TRACK_EVENTS_NUMBERS_SIZE, TRACK_EVENTS_NUMBERS,
            TRACK_EVENTS_RAWS_SIZE, TRACK_EVENTS_RAWS,
            TRACK_EVENTS_TRAYS_SIZE, TRACK_EVENTS_TRAYS
        },
        {
            2003, "ETCS Text Messages",
            ETCS_TEXT_MESSAGES_TAGS_SIZE, ETCS_TEXT_MESSAGES_TAGS,
            ETCS_TEXT_MESSAGES_IDENTIFIERS_SIZE, ETCS_TEXT_MESSAGES_IDENTIFIERS,
            ETCS_TEXT_MESSAGES_CONSTANTS_SIZE, ETCS_TEXT_MESSAGES_CONSTANTS,
            ETCS_TEXT_MESSAGES_SPECIFICATIONS_SIZE, ETCS_TEXT_MESSAGES_SPECIFICATIONS,
            ETCS_TEXT_MESSAGES_NUMBERS_SIZE, ETCS_TEXT_MESSAGES_NUMBERS,
            ETCS_TEXT_MESSAGES_RAWS_SIZE, ETCS_TEXT_MESSAGES_RAWS,
            ETCS_TEXT_MESSAGES_TRAYS_SIZE, ETCS_TEXT_MESSAGES_TRAYS
        },
        {
            2004, "Gradient",
            GRADIENT_TAGS_SIZE, GRADIENT_TAGS,
            GRADIENT_IDENTIFIERS_SIZE, GRADIENT_IDENTIFIERS,
            GRADIENT_CONSTANTS_SIZE, GRADIENT_CONSTANTS,
            GRADIENT_SPECIFICATIONS_SIZE, GRADIENT_SPECIFICATIONS,
            GRADIENT_NUMBERS_SIZE, GRADIENT_NUMBERS,
            GRADIENT_RAWS_SIZE, GRADIENT_RAWS,
            GRADIENT_TRAYS_SIZE, GRADIENT_TRAYS
        },
        {
            701, "Intercom",
            INTERCOM_TAGS_SIZE, INTERCOM_TAGS,
            INTERCOM_IDENTIFIERS_SIZE, INTERCOM_IDENTIFIERS,
            INTERCOM_CONSTANTS_SIZE, INTERCOM_CONSTANTS,
            INTERCOM_SPECIFICATIONS_SIZE, INTERCOM_SPECIFICATIONS,
            INTERCOM_NUMBERS_SIZE, INTERCOM_NUMBERS,
            INTERCOM_RAWS_SIZE, INTERCOM_RAWS,
            INTERCOM_TRAYS_SIZE, INTERCOM_TRAYS
        },
        {
            702, "IntercomInputs",
            INTERCOM_INPUTS_TAGS_SIZE, INTERCOM_INPUTS_TAGS,
            INTERCOM_INPUTS_IDENTIFIERS_SIZE, INTERCOM_INPUTS_IDENTIFIERS,
            INTERCOM_INPUTS_CONSTANTS_SIZE, INTERCOM_INPUTS_CONSTANTS,
            INTERCOM_INPUTS_SPECIFICATIONS_SIZE, INTERCOM_INPUTS_SPECIFICATIONS,
            INTERCOM_INPUTS_NUMBERS_SIZE, INTERCOM_INPUTS_NUMBERS,
            INTERCOM_INPUTS_RAWS_SIZE, INTERCOM_INPUTS_RAWS,
            INTERCOM_INPUTS_TRAYS_SIZE, INTERCOM_INPUTS_TRAYS
        },
        {
            703, "IntercomOutputs",
            INTERCOM_OUTPUTS_TAGS_SIZE, INTERCOM_OUTPUTS_TAGS,
            INTERCOM_OUTPUTS_IDENTIFIERS_SIZE, INTERCOM_OUTPUTS_IDENTIFIERS,
            INTERCOM_OUTPUTS_CONSTANTS_SIZE, INTERCOM_OUTPUTS_CONSTANTS,
            INTERCOM_OUTPUTS_SPECIFICATIONS_SIZE, INTERCOM_OUTPUTS_SPECIFICATIONS,
            INTERCOM_OUTPUTS_NUMBERS_SIZE, INTERCOM_OUTPUTS_NUMBERS,
            INTERCOM_OUTPUTS_RAWS_SIZE, INTERCOM_OUTPUTS_RAWS,
            INTERCOM_OUTPUTS_TRAYS_SIZE, INTERCOM_OUTPUTS_TRAYS
        },
        {
            704, "IntercomVehicleInputs",
            INTERCOM_VEHICLE_INPUTS_TAGS_SIZE, INTERCOM_VEHICLE_INPUTS_TAGS,
            INTERCOM_VEHICLE_INPUTS_IDENTIFIERS_SIZE, INTERCOM_VEHICLE_INPUTS_IDENTIFIERS,
            INTERCOM_VEHICLE_INPUTS_CONSTANTS_SIZE, INTERCOM_VEHICLE_INPUTS_CONSTANTS,
            INTERCOM_VEHICLE_INPUTS_SPECIFICATIONS_SIZE, INTERCOM_VEHICLE_INPUTS_SPECIFICATIONS,
            INTERCOM_VEHICLE_INPUTS_NUMBERS_SIZE, INTERCOM_VEHICLE_INPUTS_NUMBERS,
            INTERCOM_VEHICLE_INPUTS_RAWS_SIZE, INTERCOM_VEHICLE_INPUTS_RAWS,
            INTERCOM_VEHICLE_INPUTS_TRAYS_SIZE, INTERCOM_VEHICLE_INPUTS_TRAYS
        },
        {
            705, "IntercomVehicleOutputs",
            INTERCOM_VEHICLE_OUTPUTS_TAGS_SIZE, INTERCOM_VEHICLE_OUTPUTS_TAGS,
            INTERCOM_VEHICLE_OUTPUTS_IDENTIFIERS_SIZE, INTERCOM_VEHICLE_OUTPUTS_IDENTIFIERS,
            INTERCOM_VEHICLE_OUTPUTS_CONSTANTS_SIZE, INTERCOM_VEHICLE_OUTPUTS_CONSTANTS,
            INTERCOM_VEHICLE_OUTPUTS_SPECIFICATIONS_SIZE, INTERCOM_VEHICLE_OUTPUTS_SPECIFICATIONS,
            INTERCOM_VEHICLE_OUTPUTS_NUMBERS_SIZE, INTERCOM_VEHICLE_OUTPUTS_NUMBERS,
            INTERCOM_VEHICLE_OUTPUTS_RAWS_SIZE, INTERCOM_VEHICLE_OUTPUTS_RAWS,
            INTERCOM_VEHICLE_OUTPUTS_TRAYS_SIZE, INTERCOM_VEHICLE_OUTPUTS_TRAYS
        },
        {
            601, "PISAudioController",
            PIS_AUDIO_CONTROLLER_TAGS_SIZE, PIS_AUDIO_CONTROLLER_TAGS,
            PIS_AUDIO_CONTROLLER_IDENTIFIERS_SIZE, PIS_AUDIO_CONTROLLER_IDENTIFIERS,
            PIS_AUDIO_CONTROLLER_CONSTANTS_SIZE, PIS_AUDIO_CONTROLLER_CONSTANTS,
            PIS_AUDIO_CONTROLLER_SPECIFICATIONS_SIZE, PIS_AUDIO_CONTROLLER_SPECIFICATIONS,
            PIS_AUDIO_CONTROLLER_NUMBERS_SIZE, PIS_AUDIO_CONTROLLER_NUMBERS,
            PIS_AUDIO_CONTROLLER_RAWS_SIZE, PIS_AUDIO_CONTROLLER_RAWS,
            PIS_AUDIO_CONTROLLER_TRAYS_SIZE, PIS_AUDIO_CONTROLLER_TRAYS
        },
        {
            602, "PISAudioControllerStatus",
            PIS_AUDIO_CONTROLLER_STATUS_TAGS_SIZE, PIS_AUDIO_CONTROLLER_STATUS_TAGS,
            PIS_AUDIO_CONTROLLER_STATUS_IDENTIFIERS_SIZE, PIS_AUDIO_CONTROLLER_STATUS_IDENTIFIERS,
            PIS_AUDIO_CONTROLLER_STATUS_CONSTANTS_SIZE, PIS_AUDIO_CONTROLLER_STATUS_CONSTANTS,
            PIS_AUDIO_CONTROLLER_STATUS_SPECIFICATIONS_SIZE, PIS_AUDIO_CONTROLLER_STATUS_SPECIFICATIONS,
            PIS_AUDIO_CONTROLLER_STATUS_NUMBERS_SIZE, PIS_AUDIO_CONTROLLER_STATUS_NUMBERS,
            PIS_AUDIO_CONTROLLER_STATUS_RAWS_SIZE, PIS_AUDIO_CONTROLLER_STATUS_RAWS,
            PIS_AUDIO_CONTROLLER_STATUS_TRAYS_SIZE, PIS_AUDIO_CONTROLLER_STATUS_TRAYS
        },
        {
            603, "PISAudioControllerMessageQueue",
            PIS_AUDIO_CONTROLLER_MESSAGE_QUEUE_TAGS_SIZE, PIS_AUDIO_CONTROLLER_MESSAGE_QUEUE_TAGS,
            PIS_AUDIO_CONTROLLER_MESSAGE_QUEUE_IDENTIFIERS_SIZE, PIS_AUDIO_CONTROLLER_MESSAGE_QUEUE_IDENTIFIERS,
            PIS_AUDIO_CONTROLLER_MESSAGE_QUEUE_CONSTANTS_SIZE, PIS_AUDIO_CONTROLLER_MESSAGE_QUEUE_CONSTANTS,
            PIS_AUDIO_CONTROLLER_MESSAGE_QUEUE_SPECIFICATIONS_SIZE, PIS_AUDIO_CONTROLLER_MESSAGE_QUEUE_SPECIFICATIONS,
            PIS_AUDIO_CONTROLLER_MESSAGE_QUEUE_NUMBERS_SIZE, PIS_AUDIO_CONTROLLER_MESSAGE_QUEUE_NUMBERS,
            PIS_AUDIO_CONTROLLER_MESSAGE_QUEUE_RAWS_SIZE, PIS_AUDIO_CONTROLLER_MESSAGE_QUEUE_RAWS,
            PIS_AUDIO_CONTROLLER_MESSAGE_QUEUE_TRAYS_SIZE, PIS_AUDIO_CONTROLLER_MESSAGE_QUEUE_TRAYS
        },
        {
            501, "Schedule Tracking",
            SCHEDULE_TRACKING_TAGS_SIZE, SCHEDULE_TRACKING_TAGS,
            SCHEDULE_TRACKING_IDENTIFIERS_SIZE, SCHEDULE_TRACKING_IDENTIFIERS,
            SCHEDULE_TRACKING_CONSTANTS_SIZE, SCHEDULE_TRACKING_CONSTANTS,
            SCHEDULE_TRACKING_SPECIFICATIONS_SIZE, SCHEDULE_TRACKING_SPECIFICATIONS,
            SCHEDULE_TRACKING_NUMBERS_SIZE, SCHEDULE_TRACKING_NUMBERS,
            SCHEDULE_TRACKING_RAWS_SIZE, SCHEDULE_TRACKING_RAWS,
            SCHEDULE_TRACKING_TRAYS_SIZE, SCHEDULE_TRACKING_TRAYS
        },
        {
            502, "STUInputs",
            STU_INPUTS_TAGS_SIZE, STU_INPUTS_TAGS,
            STU_INPUTS_IDENTIFIERS_SIZE, STU_INPUTS_IDENTIFIERS,
            STU_INPUTS_CONSTANTS_SIZE, STU_INPUTS_CONSTANTS,
            STU_INPUTS_SPECIFICATIONS_SIZE, STU_INPUTS_SPECIFICATIONS,
            STU_INPUTS_NUMBERS_SIZE, STU_INPUTS_NUMBERS,
            STU_INPUTS_RAWS_SIZE, STU_INPUTS_RAWS,
            STU_INPUTS_TRAYS_SIZE, STU_INPUTS_TRAYS
        },
        {
            503, "STUOutputs",
            STU_OUTPUTS_TAGS_SIZE, STU_OUTPUTS_TAGS,
            STU_OUTPUTS_IDENTIFIERS_SIZE, STU_OUTPUTS_IDENTIFIERS,
            STU_OUTPUTS_CONSTANTS_SIZE, STU_OUTPUTS_CONSTANTS,
            STU_OUTPUTS_SPECIFICATIONS_SIZE, STU_OUTPUTS_SPECIFICATIONS,
            STU_OUTPUTS_NUMBERS_SIZE, STU_OUTPUTS_NUMBERS,
            STU_OUTPUTS_RAWS_SIZE, STU_OUTPUTS_RAWS,
            STU_OUTPUTS_TRAYS_SIZE, STU_OUTPUTS_TRAYS
        },
    };

    const size_t CLASS_INFO_SIZE = sizeof(CLASS_INFO)/sizeof(CLASS_INFO[0]); 
};


namespace Project
{
    /// Retrieves sufficient data to create an ObjectDefinition
    ///
    /// @param class_id The class ID of the object definition to retrieve.
    ///
    /// @return An ObjectDefinition with the numbers, raws and trays filled out.

    Sim::ObjectDefinition GetObjectDefinition(int class_id)
    {
        // Find the class with this id in our ClassInfo
        const ClassInfo *pci = find_if(CLASS_INFO, CLASS_INFO + CLASS_INFO_SIZE, tr1::bind(equal_to<int>(), class_id, tr1::bind(&ClassInfo::class_id, tr1::placeholders::_1)));
        if(pci == CLASS_INFO + CLASS_INFO_SIZE)
            throw InvalidParameterException(FLSTAMP) << "Class ID " << class_id << " not found";

        Sim::ObjectDefinition obj_def;
        obj_def.name = pci->name;

        obj_def.tags.reserve(pci->tags_size);
        obj_def.identifiers.reserve(pci->identifiers_size);
        obj_def.constants.reserve(pci->constants_size);
        obj_def.specifications.reserve(pci->specifications_size);
        obj_def.number_info.reserve(pci->numbers_size);
        obj_def.raw_info.reserve(pci->raws_size);
        obj_def.tray_info.reserve(pci->trays_size);
        copy(pci->tags,           pci->tags + pci->tags_size,                     back_inserter(obj_def.tags));
        copy(pci->identifiers,    pci->identifiers + pci->identifiers_size,       back_inserter(obj_def.identifiers));
        copy(pci->constants,      pci->constants + pci->constants_size,           back_inserter(obj_def.constants));
        copy(pci->specifications, pci->specifications + pci->specifications_size, back_inserter(obj_def.specifications));
        copy(pci->numbers,        pci->numbers + pci->numbers_size,               back_inserter(obj_def.number_info));
        copy(pci->raws,           pci->raws + pci->raws_size,                     back_inserter(obj_def.raw_info));
        copy(pci->trays,          pci->trays + pci->trays_size,                   back_inserter(obj_def.tray_info));

        return obj_def;
    }
};
