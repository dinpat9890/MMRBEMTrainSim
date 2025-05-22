/*
 * DoorSystem_capi.cpp
 *
 * Code generation for model "DoorSystem".
 *
 * Model version              : 1.2208
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "DoorSystem_capi_host.h"
#define sizeof(s)                      ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el)              ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s)               (s)
#else                                  /* HOST_CAPI_BUILD */
#include "builtin_typeid_types.h"
#include "DoorSystem.h"
#include "DoorSystem_capi.h"
#include "DoorSystem_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               (NULL)
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif                                 /* HOST_CAPI_BUILD */

/* Block output signal information */
static rtwCAPI_Signals rtBlockSignals[] = {
  /* addrMapIndex, sysNum, blockPath,
   * signalName, portNumber, dataTypeIndex, dimIndex, fxpIndex, sTimeIndex
   */
  { 0, 86, TARGET_STRING("DoorSystem/Unit Delay"),
    TARGET_STRING(""), 0, 1, 1, 0, 0 },

  { 1, 79, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles"),
    TARGET_STRING(""), 0, 11, 0, 0, 0 },

  { 2, 79, TARGET_STRING(
    "DoorSystem/DoorSystemPerCar/EnabledVehicles/ProcessFaultsAndOverrides/Bus Assignment"),
    TARGET_STRING(""), 0, 17, 0, 0, 0 },

  { 3, 79, TARGET_STRING(
    "DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Bus Creator1"),
    TARGET_STRING(""), 0, 11, 0, 0, 0 },

  { 4, 48, TARGET_STRING(
    "DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic"),
    TARGET_STRING(""), 0, 9, 3, 0, 0 },

  { 5, 49, TARGET_STRING(
    "DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic"),
    TARGET_STRING(""), 1, 0, 0, 0, 0 },

  { 6, 77, TARGET_STRING(
    "DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/TimerOnDelay NoInit1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 7, 78, TARGET_STRING(
    "DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/TimerOnDelay NoInit2"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 8, 48, TARGET_STRING(
    "DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem"),
    TARGET_STRING(""), 0, 9, 3, 0, 0 },

  { 9, 49, TARGET_STRING(
    "DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/AND"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 10, 58, TARGET_STRING(
    "DoorSystem/DoorSystemPerCar/EnabledVehicles/ProcessFaultsAndOverrides/For Each Subsystem/AutoOpen/LeadingEdgePulse"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 11, 55, TARGET_STRING(
    "DoorSystem/DoorSystemPerCar/EnabledVehicles/ProcessFaultsAndOverrides/For Each Subsystem/AutoOpen/TrailingEdgePulse"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 12, 72, TARGET_STRING(
    "DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/EmergencyDoorPositionHack/TimerOffDelay NoInit"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 13, 74, TARGET_STRING(
    "DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/EmergencyDoorPositionHack/TimerOffDelay NoInit1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 14, 76, TARGET_STRING(
    "DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/EmergencyDoorPositionHack/TimerOffDelay NoInit2"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 15, 58, TARGET_STRING(
    "DoorSystem/DoorSystemPerCar/EnabledVehicles/ProcessFaultsAndOverrides/For Each Subsystem/AutoOpen/LeadingEdgePulse/TimerOffDelay NoInit"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 16, 55, TARGET_STRING(
    "DoorSystem/DoorSystemPerCar/EnabledVehicles/ProcessFaultsAndOverrides/For Each Subsystem/AutoOpen/TrailingEdgePulse/TimerOffDelay NoInit"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 17, 72, TARGET_STRING(
    "DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/EmergencyDoorPositionHack/TimerOffDelay NoInit/Logical Operator1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 18, 74, TARGET_STRING(
    "DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/EmergencyDoorPositionHack/TimerOffDelay NoInit1/Logical Operator1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 19, 76, TARGET_STRING(
    "DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/EmergencyDoorPositionHack/TimerOffDelay NoInit2/Logical Operator1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 20, 77, TARGET_STRING(
    "DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/TimerOnDelay NoInit1/Compare To Zero/Compare"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 21, 78, TARGET_STRING(
    "DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/TimerOnDelay NoInit2/Compare To Zero/Compare"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 22, 58, TARGET_STRING(
    "DoorSystem/DoorSystemPerCar/EnabledVehicles/ProcessFaultsAndOverrides/For Each Subsystem/AutoOpen/LeadingEdgePulse/TimerOffDelay NoInit/Logical Operator1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 23, 55, TARGET_STRING(
    "DoorSystem/DoorSystemPerCar/EnabledVehicles/ProcessFaultsAndOverrides/For Each Subsystem/AutoOpen/TrailingEdgePulse/TimerOffDelay NoInit/Logical Operator1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 24, 7, TARGET_STRING(
    "DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/MotorCommandLogic/DoorCloseDelay"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 25, 5, TARGET_STRING(
    "DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/MotorCommandLogic/DoorOpenDelay"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 26, 1, TARGET_STRING(
    "DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/Obstacle Detection Functionality/Chart"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 27, 1, TARGET_STRING(
    "DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/Obstacle Detection Functionality/Chart"),
    TARGET_STRING(""), 1, 0, 0, 0, 0 },

  { 28, 1, TARGET_STRING(
    "DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/Obstacle Detection Functionality/Chart"),
    TARGET_STRING(""), 2, 0, 0, 0, 0 },

  { 29, 1, TARGET_STRING(
    "DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/Obstacle Detection Functionality/Chart"),
    TARGET_STRING(""), 4, 0, 0, 0, 0 },

  { 30, 1, TARGET_STRING(
    "DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/Obstacle Detection Functionality/Chart"),
    TARGET_STRING(""), 5, 0, 0, 0, 0 },

  { 31, 23, TARGET_STRING(
    "DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUAudioLogic/DCUOnAudio/LeadingEdgePulseTunable"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 32, 26, TARGET_STRING(
    "DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUAudioLogic/DCUOnAudio/LeadingEdgePulseTunable1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 33, 23, TARGET_STRING(
    "DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUAudioLogic/DCUOnAudio/LeadingEdgePulseTunable/TimerOffDelay NoInitTunable"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 34, 26, TARGET_STRING(
    "DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUAudioLogic/DCUOnAudio/LeadingEdgePulseTunable1/TimerOffDelay NoInitTunable"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 35, 7, TARGET_STRING(
    "DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/MotorCommandLogic/DoorCloseDelay/Compare To Zero/Compare"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 36, 5, TARGET_STRING(
    "DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/MotorCommandLogic/DoorOpenDelay/Compare To Zero/Compare"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 37, 23, TARGET_STRING(
    "DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUAudioLogic/DCUOnAudio/LeadingEdgePulseTunable/TimerOffDelay NoInitTunable/Logical Operator1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 38, 26, TARGET_STRING(
    "DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUAudioLogic/DCUOnAudio/LeadingEdgePulseTunable1/TimerOffDelay NoInitTunable/Logical Operator1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  {
    0, 0, (NULL), (NULL), 0, 0, 0, 0, 0
  }
};

static rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  { 39, TARGET_STRING("DoorSystem/Unit Delay"),
    TARGET_STRING("InitialCondition"), 1, 0, 0 },

  { 40, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorSystemVehicleOut"),
    TARGET_STRING("InitialOutput"), 11, 0, 0 },

  { 41, TARGET_STRING("DoorSystem/TrainInterlock/MakeArrayOfBuses/Constant"),
    TARGET_STRING("Value"), 1, 0, 0 },

  { 42, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/Constant"),
    TARGET_STRING("Value"), 4, 4, 0 },

  { 43, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Constant"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 44, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Constant1"),
    TARGET_STRING("Value"), 10, 0, 0 },

  { 45, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/ProcessFaultsAndOverrides/For Each Subsystem/Switch"),
    TARGET_STRING("Threshold"), 4, 0, 0 },

  { 46, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/Compare To Constant"),
    TARGET_STRING("const"), 4, 0, 0 },

  { 47, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/Detect Increase"),
    TARGET_STRING("vinit"), 0, 0, 0 },

  { 48, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/Detect Increase1"),
    TARGET_STRING("vinit"), 0, 0, 0 },

  { 49, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/Detect Increase2"),
    TARGET_STRING("vinit"), 0, 0, 0 },

  { 50, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/Detect Increase3"),
    TARGET_STRING("vinit"), 0, 0, 0 },

  { 51, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/Detect Increase4"),
    TARGET_STRING("vinit"), 0, 0, 0 },

  { 52, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/Detect Increase5"),
    TARGET_STRING("vinit"), 0, 0, 0 },

  { 53, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/SR Latch - Reset Priority"),
    TARGET_STRING("initial_condition"), 0, 0, 0 },

  { 54, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/SR Latch - Reset Priority1"),
    TARGET_STRING("initial_condition"), 0, 0, 0 },

  { 55, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/SR Latch - Reset Priority2"),
    TARGET_STRING("initial_condition"), 0, 0, 0 },

  { 56, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/SR Latch - Reset Priority3"),
    TARGET_STRING("initial_condition"), 0, 0, 0 },

  { 57, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/TimerOnDelay NoInit1"),
    TARGET_STRING("UpperSaturationLimit"), 4, 0, 0 },

  { 58, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/TimerOnDelay NoInit2"),
    TARGET_STRING("UpperSaturationLimit"), 4, 0, 0 },

  { 59, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/Constant"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 60, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/Constant1"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 61, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/Unit Delay"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 62, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/Unit Delay1"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 63, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorOut"),
    TARGET_STRING("InitialOutput"), 9, 0, 0 },

  { 64, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/Interlock"),
    TARGET_STRING("InitialOutput"), 0, 0, 0 },

  { 65, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/EmergencyDoorPositionHack/Detect Decrease"),
    TARGET_STRING("vinit"), 4, 0, 0 },

  { 66, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/EmergencyDoorPositionHack/Detect Increase1"),
    TARGET_STRING("vinit"), 4, 0, 0 },

  { 67, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/EmergencyDoorPositionHack/Detect Increase2"),
    TARGET_STRING("vinit"), 4, 0, 0 },

  { 68, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/EmergencyDoorPositionHack/Detect Increase3"),
    TARGET_STRING("vinit"), 0, 0, 0 },

  { 69, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/EmergencyDoorPositionHack/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 70, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/EmergencyDoorPositionHack/Constant1"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 71, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/EmergencyDoorPositionHack/Constant2"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 72, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/EmergencyDoorPositionHack/Constant4"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 73, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/EmergencyDoorPositionHack/Constant5"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 74, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/EmergencyDoorPositionHack/Constant6"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 75, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/EmergencyDoorPositionHack/Constant7"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 76, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/EmergencyDoorPositionHack/Unit Delay"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 77, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/TimerOnDelay NoInit1/Timer"),
    TARGET_STRING("gainval"), 4, 0, 0 },

  { 78, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/TimerOnDelay NoInit1/Timer"),
    TARGET_STRING("InitialCondition"), 4, 0, 0 },

  { 79, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/TimerOnDelay NoInit1/Timer"),
    TARGET_STRING("LowerSaturationLimit"), 4, 0, 0 },

  { 80, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/TimerOnDelay NoInit2/Timer"),
    TARGET_STRING("gainval"), 4, 0, 0 },

  { 81, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/TimerOnDelay NoInit2/Timer"),
    TARGET_STRING("InitialCondition"), 4, 0, 0 },

  { 82, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/TimerOnDelay NoInit2/Timer"),
    TARGET_STRING("LowerSaturationLimit"), 4, 0, 0 },

  { 83, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/Compare To Constant2"),
    TARGET_STRING("const"), 4, 0, 0 },

  { 84, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/Compare To Constant3"),
    TARGET_STRING("const"), 4, 0, 0 },

  { 85, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/Unit Delay"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 86, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/Unit Delay1"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 87, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/Unit Delay2"),
    TARGET_STRING("InitialCondition"), 4, 0, 0 },

  { 88, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/Unit Delay3"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 89, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/ProcessFaultsAndOverrides/For Each Subsystem/AutoOpen/LeadingEdgePulse/Detect Increase"),
    TARGET_STRING("vinit"), 0, 0, 0 },

  { 90, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/ProcessFaultsAndOverrides/For Each Subsystem/AutoOpen/TrailingEdgePulse/Detect Decrease"),
    TARGET_STRING("vinit"), 0, 0, 0 },

  { 91, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/EmergencyDoorPositionHack/Discrete Dynamic Limited Integrator1/IC"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 92, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/EmergencyDoorPositionHack/Discrete Dynamic Limited Integrator1/Unit Delay1"),
    TARGET_STRING("InitialCondition"), 4, 0, 0 },

  { 93, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/EmergencyDoorPositionHack/Discrete Dynamic Limited Integrator1/Weighted Sample Time"),
    TARGET_STRING("WtEt"), 4, 0, 0 },

  { 94, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/EmergencyDoorPositionHack/TimerOffDelay NoInit/Initialise"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 95, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/EmergencyDoorPositionHack/TimerOffDelay NoInit/OffTime"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 96, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/EmergencyDoorPositionHack/TimerOffDelay NoInit/Discrete-Time Integrator"),
    TARGET_STRING("gainval"), 4, 0, 0 },

  { 97, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/EmergencyDoorPositionHack/TimerOffDelay NoInit/Discrete-Time Integrator"),
    TARGET_STRING("UpperSaturationLimit"), 4, 0, 0 },

  { 98, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/EmergencyDoorPositionHack/TimerOffDelay NoInit/Discrete-Time Integrator"),
    TARGET_STRING("LowerSaturationLimit"), 4, 0, 0 },

  { 99, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/EmergencyDoorPositionHack/TimerOffDelay NoInit/Gain"),
    TARGET_STRING("Gain"), 4, 0, 0 },

  { 100, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/EmergencyDoorPositionHack/TimerOffDelay NoInit/IC"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 101, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/EmergencyDoorPositionHack/TimerOffDelay NoInit1/Initialise"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 102, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/EmergencyDoorPositionHack/TimerOffDelay NoInit1/OffTime"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 103, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/EmergencyDoorPositionHack/TimerOffDelay NoInit1/Discrete-Time Integrator"),
    TARGET_STRING("gainval"), 4, 0, 0 },

  { 104, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/EmergencyDoorPositionHack/TimerOffDelay NoInit1/Discrete-Time Integrator"),
    TARGET_STRING("UpperSaturationLimit"), 4, 0, 0 },

  { 105, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/EmergencyDoorPositionHack/TimerOffDelay NoInit1/Discrete-Time Integrator"),
    TARGET_STRING("LowerSaturationLimit"), 4, 0, 0 },

  { 106, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/EmergencyDoorPositionHack/TimerOffDelay NoInit1/Gain"),
    TARGET_STRING("Gain"), 4, 0, 0 },

  { 107, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/EmergencyDoorPositionHack/TimerOffDelay NoInit1/IC"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 108, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/EmergencyDoorPositionHack/TimerOffDelay NoInit2/Initialise"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 109, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/EmergencyDoorPositionHack/TimerOffDelay NoInit2/OffTime"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 110, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/EmergencyDoorPositionHack/TimerOffDelay NoInit2/Discrete-Time Integrator"),
    TARGET_STRING("gainval"), 4, 0, 0 },

  { 111, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/EmergencyDoorPositionHack/TimerOffDelay NoInit2/Discrete-Time Integrator"),
    TARGET_STRING("UpperSaturationLimit"), 4, 0, 0 },

  { 112, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/EmergencyDoorPositionHack/TimerOffDelay NoInit2/Discrete-Time Integrator"),
    TARGET_STRING("LowerSaturationLimit"), 4, 0, 0 },

  { 113, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/EmergencyDoorPositionHack/TimerOffDelay NoInit2/Gain"),
    TARGET_STRING("Gain"), 4, 0, 0 },

  { 114, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/EmergencyDoorPositionHack/TimerOffDelay NoInit2/IC"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 115, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/TimerOnDelay NoInit1/Compare To Zero/Constant"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 116, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/TimerOnDelay NoInit2/Compare To Zero/Constant"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 117, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorActuationAndSwitches/Detect Increase"),
    TARGET_STRING("vinit"), 4, 0, 0 },

  { 118, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorActuationAndSwitches/Detect Increase1"),
    TARGET_STRING("vinit"), 0, 0, 0 },

  { 119, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorActuationAndSwitches/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 120, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorActuationAndSwitches/Constant1"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 121, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorActuationAndSwitches/Constant2"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 122, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorActuationAndSwitches/Constant3"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 123, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorActuationAndSwitches/Constant4"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 124, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorActuationAndSwitches/Constant5"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 125, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorActuationAndSwitches/Unit Delay"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 126, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/Obstacle Detection Functionality"),
    TARGET_STRING("PauseBeforeOpeningAttempt"), 4, 0, 0 },

  { 127, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/Obstacle Detection Functionality"),
    TARGET_STRING("PauseBeforeClosingAttempt"), 4, 0, 0 },

  { 128, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/Obstacle Detection Functionality"),
    TARGET_STRING("MoveAwayFromObstacle"), 4, 0, 0 },

  { 129, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/Obstacle Detection Functionality"),
    TARGET_STRING("NumOfClosingAttempts"), 4, 0, 0 },

  { 130, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/Obstacle Detection Functionality"),
    TARGET_STRING("NumOfOpeningAttempts"), 4, 0, 0 },

  { 131, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/ProcessFaultsAndOverrides/For Each Subsystem/AutoOpen/LeadingEdgePulse/TimerOffDelay NoInit/Initialise"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 132, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/ProcessFaultsAndOverrides/For Each Subsystem/AutoOpen/LeadingEdgePulse/TimerOffDelay NoInit/OffTime"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 133, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/ProcessFaultsAndOverrides/For Each Subsystem/AutoOpen/LeadingEdgePulse/TimerOffDelay NoInit/Discrete-Time Integrator"),
    TARGET_STRING("gainval"), 4, 0, 0 },

  { 134, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/ProcessFaultsAndOverrides/For Each Subsystem/AutoOpen/LeadingEdgePulse/TimerOffDelay NoInit/Discrete-Time Integrator"),
    TARGET_STRING("UpperSaturationLimit"), 4, 0, 0 },

  { 135, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/ProcessFaultsAndOverrides/For Each Subsystem/AutoOpen/LeadingEdgePulse/TimerOffDelay NoInit/Discrete-Time Integrator"),
    TARGET_STRING("LowerSaturationLimit"), 4, 0, 0 },

  { 136, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/ProcessFaultsAndOverrides/For Each Subsystem/AutoOpen/LeadingEdgePulse/TimerOffDelay NoInit/Gain"),
    TARGET_STRING("Gain"), 4, 0, 0 },

  { 137, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/ProcessFaultsAndOverrides/For Each Subsystem/AutoOpen/LeadingEdgePulse/TimerOffDelay NoInit/IC"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 138, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/ProcessFaultsAndOverrides/For Each Subsystem/AutoOpen/TrailingEdgePulse/TimerOffDelay NoInit/Initialise"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 139, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/ProcessFaultsAndOverrides/For Each Subsystem/AutoOpen/TrailingEdgePulse/TimerOffDelay NoInit/OffTime"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 140, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/ProcessFaultsAndOverrides/For Each Subsystem/AutoOpen/TrailingEdgePulse/TimerOffDelay NoInit/Discrete-Time Integrator"),
    TARGET_STRING("gainval"), 4, 0, 0 },

  { 141, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/ProcessFaultsAndOverrides/For Each Subsystem/AutoOpen/TrailingEdgePulse/TimerOffDelay NoInit/Discrete-Time Integrator"),
    TARGET_STRING("UpperSaturationLimit"), 4, 0, 0 },

  { 142, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/ProcessFaultsAndOverrides/For Each Subsystem/AutoOpen/TrailingEdgePulse/TimerOffDelay NoInit/Discrete-Time Integrator"),
    TARGET_STRING("LowerSaturationLimit"), 4, 0, 0 },

  { 143, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/ProcessFaultsAndOverrides/For Each Subsystem/AutoOpen/TrailingEdgePulse/TimerOffDelay NoInit/Gain"),
    TARGET_STRING("Gain"), 4, 0, 0 },

  { 144, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/ProcessFaultsAndOverrides/For Each Subsystem/AutoOpen/TrailingEdgePulse/TimerOffDelay NoInit/IC"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 145, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/EmergencyDoorPositionHack/TimerOffDelay NoInit/Count to 0/Constant"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 146, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/EmergencyDoorPositionHack/TimerOffDelay NoInit1/Count to 0/Constant"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 147, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/VehiclePacking/Ramp_EmergencyDoor_Operation/EmergencyDoorPositionHack/TimerOffDelay NoInit2/Count to 0/Constant"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 148, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorActuationAndSwitches/Discrete Dynamic Limited Integrator1/IC"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 149, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorActuationAndSwitches/Discrete Dynamic Limited Integrator1/Unit Delay1"),
    TARGET_STRING("InitialCondition"), 4, 0, 0 },

  { 150, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorActuationAndSwitches/Discrete Dynamic Limited Integrator1/Weighted Sample Time"),
    TARGET_STRING("WtEt"), 4, 0, 0 },

  { 151, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorActuationAndSwitches/DoorSwitches/Compare To Constant1"),
    TARGET_STRING("const"), 4, 0, 0 },

  { 152, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorActuationAndSwitches/DoorSwitches/Compare To Constant2"),
    TARGET_STRING("const"), 4, 0, 0 },

  { 153, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorActuationAndSwitches/Manual Control/Constant7"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 154, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorActuationAndSwitches/Manual Control/Speed"),
    TARGET_STRING("Threshold"), 4, 0, 0 },

  { 155, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorActuationAndSwitches/Motor Control/Constant7"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 156, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorActuationAndSwitches/Motor Control/Speed"),
    TARGET_STRING("Threshold"), 4, 0, 0 },

  { 157, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DoorEmergencyRelease/Detect Increase"),
    TARGET_STRING("vinit"), 0, 0, 0 },

  { 158, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DoorEmergencyRelease/Detect Increase1"),
    TARGET_STRING("vinit"), 0, 0, 0 },

  { 159, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DoorEmergencyRelease/SR Latch - Reset Priority"),
    TARGET_STRING("initial_condition"), 0, 0, 0 },

  { 160, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DoorIsolation/SR Latch - Reset Priority"),
    TARGET_STRING("initial_condition"), 0, 0, 0 },

  { 161, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/NormalDoorOpenCloseCommands/Detect Decrease"),
    TARGET_STRING("vinit"), 0, 0, 0 },

  { 162, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/NormalDoorOpenCloseCommands/Detect Increase"),
    TARGET_STRING("vinit"), 0, 0, 0 },

  { 163, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/NormalDoorOpenCloseCommands/MotorCloseLatch"),
    TARGET_STRING("initial_condition"), 0, 0, 0 },

  { 164, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/NormalDoorOpenCloseCommands/MotorOpenLatch"),
    TARGET_STRING("initial_condition"), 0, 0, 0 },

  { 165, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorOutputsPack/DoorAudioOutputs/Detect Decrease"),
    TARGET_STRING("vinit"), 4, 0, 0 },

  { 166, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorOutputsPack/DoorAudioOutputs/Detect Increase"),
    TARGET_STRING("vinit"), 4, 0, 0 },

  { 167, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorOutputsPack/DoorAudioOutputs/Constant"),
    TARGET_STRING("Value"), 6, 0, 0 },

  { 168, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorOutputsPack/DoorElectricalOutputs/Constant"),
    TARGET_STRING("Value"), 3, 0, 0 },

  { 169, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorOutputsPack/DoorOutputControlStates/Constant"),
    TARGET_STRING("Value"), 5, 0, 0 },

  { 170, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorOutputsPack/DoorTCMSOutputs/Constant"),
    TARGET_STRING("Value"), 8, 0, 0 },

  { 171, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/ProcessFaultsAndOverrides/For Each Subsystem/AutoOpen/LeadingEdgePulse/TimerOffDelay NoInit/Count to 0/Constant"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 172, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/ProcessFaultsAndOverrides/For Each Subsystem/AutoOpen/TrailingEdgePulse/TimerOffDelay NoInit/Count to 0/Constant"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 173, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorActuationAndSwitches/Motor Control/FailToClose/Constant"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 174, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorActuationAndSwitches/Motor Control/FailToClose/Constant1"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 175, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUAudioLogic/DCUOffAudio/Constant"),
    TARGET_STRING("Value"), 18, 0, 0 },

  { 176, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUIndicatorsLogic/DCUOffIndicators/Constant"),
    TARGET_STRING("Value"), 19, 0, 0 },

  { 177, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUIndicatorsLogic/DCUOnIndicators1/Detect Decrease"),
    TARGET_STRING("vinit"), 0, 0, 0 },

  { 178, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUIndicatorsLogic/DCUOnIndicators1/Detect Increase"),
    TARGET_STRING("vinit"), 0, 0, 0 },

  { 179, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUIndicatorsLogic/DCUOnIndicators1/Detect Increase1"),
    TARGET_STRING("vinit"), 0, 0, 0 },

  { 180, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUIndicatorsLogic/DCUOnIndicators1/SR Latch - Reset Priority"),
    TARGET_STRING("initial_condition"), 0, 0, 0 },

  { 181, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUIndicatorsLogic/DCUOnIndicators1/SR Latch - Reset Priority1"),
    TARGET_STRING("initial_condition"), 0, 0, 0 },

  { 182, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUIndicatorsLogic/DCUOnIndicators1/SR Latch - Reset Priority2"),
    TARGET_STRING("initial_condition"), 0, 0, 0 },

  { 183, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUIndicatorsLogic/DCUOnIndicators1/Messages"),
    TARGET_STRING("Value"), 7, 0, 0 },

  { 184, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUIndicatorsLogic/DCUOnIndicators1/RedON"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 185, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUIndicatorsLogic/DCUOnIndicators1/YellowFlashing"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 186, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUIndicatorsLogic/DCUOnIndicators1/YellowON"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 187, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DoorEmergencyRelease/Compare To Zero/Constant"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 188, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DoorIsolation/Compare To Zero1/Constant"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 189, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/MotorCommandLogic/DoorClose/Constant"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 190, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/MotorCommandLogic/DoorCloseDelay/Timer"),
    TARGET_STRING("gainval"), 4, 0, 0 },

  { 191, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/MotorCommandLogic/DoorCloseDelay/Timer"),
    TARGET_STRING("InitialCondition"), 4, 0, 0 },

  { 192, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/MotorCommandLogic/DoorCloseDelay/Timer"),
    TARGET_STRING("LowerSaturationLimit"), 4, 0, 0 },

  { 193, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/MotorCommandLogic/DoorOpen/Constant"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 194, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/MotorCommandLogic/DoorOpenDelay/Timer"),
    TARGET_STRING("gainval"), 4, 0, 0 },

  { 195, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/MotorCommandLogic/DoorOpenDelay/Timer"),
    TARGET_STRING("InitialCondition"), 4, 0, 0 },

  { 196, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/MotorCommandLogic/DoorOpenDelay/Timer"),
    TARGET_STRING("LowerSaturationLimit"), 4, 0, 0 },

  { 197, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/MotorCommandLogic/NoMotorCommand/Constant"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 198, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/MotorCommandLogic/Obstruction/Gain1"),
    TARGET_STRING("Gain"), 20, 0, 1 },

  { 199, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/Obstacle Detection Functionality/ObstacleDetection/Compare To Constant1"),
    TARGET_STRING("const"), 4, 0, 0 },

  { 200, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/Obstacle Detection Functionality/ObstacleDetection/Compare To Constant4"),
    TARGET_STRING("const"), 4, 0, 0 },

  { 201, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/Obstacle Detection Functionality/ObstacleDetection/Detect Decrease"),
    TARGET_STRING("vinit"), 4, 0, 0 },

  { 202, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/Obstacle Detection Functionality/ObstacleDetection/Detect Decrease1"),
    TARGET_STRING("vinit"), 4, 0, 0 },

  { 203, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/Obstacle Detection Functionality/ObstacleDetection/Detect Increase"),
    TARGET_STRING("vinit"), 4, 0, 0 },

  { 204, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/Obstacle Detection Functionality/ObstacleDetection/Detect Increase1"),
    TARGET_STRING("vinit"), 4, 0, 0 },

  { 205, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/Obstacle Detection Functionality/ObstacleDetection/SR Latch - Set Priority1"),
    TARGET_STRING("initial_condition"), 0, 0, 0 },

  { 206, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/Obstacle Detection Functionality/ObstacleDetection/SR Latch - Set Priority2"),
    TARGET_STRING("initial_condition"), 0, 0, 0 },

  { 207, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorOutputsPack/DoorAudioOutputs/Compare To Zero/Constant"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 208, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorOutputsPack/DoorAudioOutputs/Compare To Zero1/Constant"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 209, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUAudioLogic/DCUOnAudio/LeadingEdgePulseTunable/Detect Increase"),
    TARGET_STRING("vinit"), 0, 0, 0 },

  { 210, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUAudioLogic/DCUOnAudio/LeadingEdgePulseTunable1/Detect Increase"),
    TARGET_STRING("vinit"), 0, 0, 0 },

  { 211, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUIndicatorsLogic/DCUOnIndicators1/Compare To Zero/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 212, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/MotorCommandLogic/DoorCloseDelay/Compare To Zero/Constant"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 213, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/MotorCommandLogic/DoorOpenDelay/Compare To Zero/Constant"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 214, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUAudioLogic/DCUOnAudio/LeadingEdgePulseTunable/TimerOffDelay NoInitTunable/Initialise"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 215, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUAudioLogic/DCUOnAudio/LeadingEdgePulseTunable/TimerOffDelay NoInitTunable/Discrete-Time Integrator"),
    TARGET_STRING("gainval"), 4, 0, 0 },

  { 216, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUAudioLogic/DCUOnAudio/LeadingEdgePulseTunable/TimerOffDelay NoInitTunable/Discrete-Time Integrator"),
    TARGET_STRING("LowerSaturationLimit"), 4, 0, 0 },

  { 217, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUAudioLogic/DCUOnAudio/LeadingEdgePulseTunable/TimerOffDelay NoInitTunable/Gain"),
    TARGET_STRING("Gain"), 4, 0, 0 },

  { 218, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUAudioLogic/DCUOnAudio/LeadingEdgePulseTunable/TimerOffDelay NoInitTunable/IC"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 219, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUAudioLogic/DCUOnAudio/LeadingEdgePulseTunable1/TimerOffDelay NoInitTunable/Initialise"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 220, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUAudioLogic/DCUOnAudio/LeadingEdgePulseTunable1/TimerOffDelay NoInitTunable/Discrete-Time Integrator"),
    TARGET_STRING("gainval"), 4, 0, 0 },

  { 221, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUAudioLogic/DCUOnAudio/LeadingEdgePulseTunable1/TimerOffDelay NoInitTunable/Discrete-Time Integrator"),
    TARGET_STRING("LowerSaturationLimit"), 4, 0, 0 },

  { 222, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUAudioLogic/DCUOnAudio/LeadingEdgePulseTunable1/TimerOffDelay NoInitTunable/Gain"),
    TARGET_STRING("Gain"), 4, 0, 0 },

  { 223, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUAudioLogic/DCUOnAudio/LeadingEdgePulseTunable1/TimerOffDelay NoInitTunable/IC"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 224, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUIndicatorsLogic/DCUOnIndicators1/DoorPBLightLogic/If Action Subsystem/Constant"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 225, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUIndicatorsLogic/DCUOnIndicators1/DoorPBLightLogic/If Action Subsystem/Constant1"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 226, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUIndicatorsLogic/DCUOnIndicators1/DoorPBLightLogic/If Action Subsystem1/Constant"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 227, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUIndicatorsLogic/DCUOnIndicators1/DoorPBLightLogic/If Action Subsystem1/Constant1"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 228, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUIndicatorsLogic/DCUOnIndicators1/DoorPBLightLogic/If Action Subsystem2/Constant"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 229, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUIndicatorsLogic/DCUOnIndicators1/DoorPBLightLogic/If Action Subsystem2/Constant1"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 230, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUIndicatorsLogic/DCUOnIndicators1/DoorPBLightLogic/If Action Subsystem3/Constant"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 231, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUIndicatorsLogic/DCUOnIndicators1/DoorPBLightLogic/If Action Subsystem3/Constant1"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 232, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUIndicatorsLogic/DCUOnIndicators1/DoorPBLightLogic/If Action Subsystem4/Constant"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 233, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUIndicatorsLogic/DCUOnIndicators1/DoorPBLightLogic/If Action Subsystem4/Constant1"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 234, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUAudioLogic/DCUOnAudio/LeadingEdgePulseTunable/TimerOffDelay NoInitTunable/Count to 0/Constant"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 235, TARGET_STRING("DoorSystem/DoorSystemPerCar/EnabledVehicles/DoorControlAlarmsPhysical/ForEachDoor/DoorLogic/DoorSystem/DoorControlUnit/DCUAudioLogic/DCUOnAudio/LeadingEdgePulseTunable1/TimerOffDelay NoInitTunable/Count to 0/Constant"),
    TARGET_STRING("Value"), 4, 0, 0 },

  {
    0, (NULL), (NULL), 0, 0, 0
  }
};

/* Block states information */
static rtwCAPI_States rtBlockStates[] = {
  /* addrMapIndex, contStateStartIndex, blockPath,
   * stateName, pathAlias, dWorkIndex, dataTypeIndex, dimIndex,
   * fixPtIdx, sTimeIndex, isContinuous, hierInfoIdx, flatElemIdx
   */
  {
    0, -1, (NULL), (NULL), (NULL), 0, 0, 0, 0, 0, 0, -1, 0
  }
};

/* Tunable variable parameters */
static rtwCAPI_ModelParameters rtModelParameters[] = {
  /* addrMapIndex, varName, dataTypeIndex, dimIndex, fixPtIndex */
  { 0, (NULL), 0, 0, 0 }
};

#ifndef HOST_CAPI_BUILD

/* Initialize Data Address */
static void DoorSystem_InitializeDataAddr(void* dataAddr[], B_DoorSystem_c_T
  *localB)
{
  dataAddr[0] = (void*) (&localB->UnitDelay[0]);
  dataAddr[1] = (void*) (&localB->CoreSubsys[7].BusCreator1);
  dataAddr[2] = (void*) (&localB->CoreSubsys[7].BusAssignment);
  dataAddr[3] = (void*) (&localB->CoreSubsys[7].BusCreator1);
  dataAddr[4] = (void*) (&localB->CoreSubsys[7].CoreSubsys[7].
    ImpAsg_InsertedFor_DoorOut_at_inport_0[0]);
  dataAddr[5] = (void*) (&localB->CoreSubsys[7].CoreSubsys[7].AND);
  dataAddr[6] = (void*) (&localB->CoreSubsys[7].TimerOnDelayNoInit1.Compare);
  dataAddr[7] = (void*) (&localB->CoreSubsys[7].TimerOnDelayNoInit2.Compare);
  dataAddr[8] = (void*) (&localB->CoreSubsys[7].CoreSubsys[7].
    ImpAsg_InsertedFor_DoorOut_at_inport_0[0]);
  dataAddr[9] = (void*) (&localB->CoreSubsys[7].CoreSubsys[7].AND);
  dataAddr[10] = (void*) (&localB->CoreSubsys[7].CoreSubsys_pn[7].
    TimerOffDelayNoInit_n.LogicalOperator1);
  dataAddr[11] = (void*) (&localB->CoreSubsys[7].CoreSubsys_pn[7].
    TimerOffDelayNoInit.LogicalOperator1);
  dataAddr[12] = (void*) (&localB->CoreSubsys[7].
    TimerOffDelayNoInit.LogicalOperator1);
  dataAddr[13] = (void*) (&localB->CoreSubsys[7].
    TimerOffDelayNoInit1.LogicalOperator1);
  dataAddr[14] = (void*) (&localB->CoreSubsys[7].
    TimerOffDelayNoInit2.LogicalOperator1);
  dataAddr[15] = (void*) (&localB->CoreSubsys[7].CoreSubsys_pn[7].
    TimerOffDelayNoInit_n.LogicalOperator1);
  dataAddr[16] = (void*) (&localB->CoreSubsys[7].CoreSubsys_pn[7].
    TimerOffDelayNoInit.LogicalOperator1);
  dataAddr[17] = (void*) (&localB->CoreSubsys[7].
    TimerOffDelayNoInit.LogicalOperator1);
  dataAddr[18] = (void*) (&localB->CoreSubsys[7].
    TimerOffDelayNoInit1.LogicalOperator1);
  dataAddr[19] = (void*) (&localB->CoreSubsys[7].
    TimerOffDelayNoInit2.LogicalOperator1);
  dataAddr[20] = (void*) (&localB->CoreSubsys[7].TimerOnDelayNoInit1.Compare);
  dataAddr[21] = (void*) (&localB->CoreSubsys[7].TimerOnDelayNoInit2.Compare);
  dataAddr[22] = (void*) (&localB->CoreSubsys[7].CoreSubsys_pn[7].
    TimerOffDelayNoInit_n.LogicalOperator1);
  dataAddr[23] = (void*) (&localB->CoreSubsys[7].CoreSubsys_pn[7].
    TimerOffDelayNoInit.LogicalOperator1);
  dataAddr[24] = (void*) (&localB->CoreSubsys[7].CoreSubsys[7].CoreSubsys[1].
    DoorCloseDelay.Compare);
  dataAddr[25] = (void*) (&localB->CoreSubsys[7].CoreSubsys[7].CoreSubsys[1].
    DoorOpenDelay.Compare);
  dataAddr[26] = (void*) (&localB->CoreSubsys[7].CoreSubsys[7].CoreSubsys[1].
    OpenCMD);
  dataAddr[27] = (void*) (&localB->CoreSubsys[7].CoreSubsys[7].CoreSubsys[1].
    CloseCMD);
  dataAddr[28] = (void*) (&localB->CoreSubsys[7].CoreSubsys[7].CoreSubsys[1].
    ResetOtherCommands);
  dataAddr[29] = (void*) (&localB->CoreSubsys[7].CoreSubsys[7].CoreSubsys[1].
    MaxOpenAttempts);
  dataAddr[30] = (void*) (&localB->CoreSubsys[7].CoreSubsys[7].CoreSubsys[1].
    MaxCloseAttempts);
  dataAddr[31] = (void*) (&localB->CoreSubsys[7].CoreSubsys[7].CoreSubsys[1].
    LeadingEdgePulseTunable.LogicalOperator1);
  dataAddr[32] = (void*) (&localB->CoreSubsys[7].CoreSubsys[7].CoreSubsys[1].
    LeadingEdgePulseTunable1.LogicalOperator1);
  dataAddr[33] = (void*) (&localB->CoreSubsys[7].CoreSubsys[7].CoreSubsys[1].
    LeadingEdgePulseTunable.LogicalOperator1);
  dataAddr[34] = (void*) (&localB->CoreSubsys[7].CoreSubsys[7].CoreSubsys[1].
    LeadingEdgePulseTunable1.LogicalOperator1);
  dataAddr[35] = (void*) (&localB->CoreSubsys[7].CoreSubsys[7].CoreSubsys[1].
    DoorCloseDelay.Compare);
  dataAddr[36] = (void*) (&localB->CoreSubsys[7].CoreSubsys[7].CoreSubsys[1].
    DoorOpenDelay.Compare);
  dataAddr[37] = (void*) (&localB->CoreSubsys[7].CoreSubsys[7].CoreSubsys[1].
    LeadingEdgePulseTunable.LogicalOperator1);
  dataAddr[38] = (void*) (&localB->CoreSubsys[7].CoreSubsys[7].CoreSubsys[1].
    LeadingEdgePulseTunable1.LogicalOperator1);
  dataAddr[39] = (void*) (&DoorSystem_P.UnitDelay_InitialCondition);
  dataAddr[40] = (void*) (&DoorSystem_P.CoreSubsys.DoorSystemVehicleOut_Y0);
  dataAddr[41] = (void*) (&DoorSystem_P.CoreSubsys_pn.Constant_Value);
  dataAddr[42] = (void*) (&DoorSystem_P.CoreSubsys.Constant_Value_o[0]);
  dataAddr[43] = (void*) (&DoorSystem_P.CoreSubsys.Constant_Value);
  dataAddr[44] = (void*) (&DoorSystem_P.CoreSubsys.Constant1_Value);
  dataAddr[45] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys_pn.Switch_Threshold);
  dataAddr[46] = (void*) (&DoorSystem_P.CoreSubsys.CompareToConstant_const);
  dataAddr[47] = (void*) (&DoorSystem_P.CoreSubsys.DetectIncrease_vinit);
  dataAddr[48] = (void*) (&DoorSystem_P.CoreSubsys.DetectIncrease1_vinit_n);
  dataAddr[49] = (void*) (&DoorSystem_P.CoreSubsys.DetectIncrease2_vinit_a);
  dataAddr[50] = (void*) (&DoorSystem_P.CoreSubsys.DetectIncrease3_vinit_d);
  dataAddr[51] = (void*) (&DoorSystem_P.CoreSubsys.DetectIncrease4_vinit);
  dataAddr[52] = (void*) (&DoorSystem_P.CoreSubsys.DetectIncrease5_vinit);
  dataAddr[53] = (void*)
    (&DoorSystem_P.CoreSubsys.SRLatchResetPriority_initial_condition);
  dataAddr[54] = (void*)
    (&DoorSystem_P.CoreSubsys.SRLatchResetPriority1_initial_condition);
  dataAddr[55] = (void*)
    (&DoorSystem_P.CoreSubsys.SRLatchResetPriority2_initial_condition);
  dataAddr[56] = (void*)
    (&DoorSystem_P.CoreSubsys.SRLatchResetPriority3_initial_condition);
  dataAddr[57] = (void*)
    (&DoorSystem_P.CoreSubsys.TimerOnDelayNoInit1_UpperSaturationLimit);
  dataAddr[58] = (void*)
    (&DoorSystem_P.CoreSubsys.TimerOnDelayNoInit2_UpperSaturationLimit);
  dataAddr[59] = (void*) (&DoorSystem_P.CoreSubsys.Constant_Value_g);
  dataAddr[60] = (void*) (&DoorSystem_P.CoreSubsys.Constant1_Value_nk);
  dataAddr[61] = (void*) (&DoorSystem_P.CoreSubsys.UnitDelay_InitialCondition_e);
  dataAddr[62] = (void*) (&DoorSystem_P.CoreSubsys.UnitDelay1_InitialCondition_i);
  dataAddr[63] = (void*) (&DoorSystem_P.CoreSubsys.CoreSubsys.DoorOut_Y0);
  dataAddr[64] = (void*) (&DoorSystem_P.CoreSubsys.CoreSubsys.Interlock_Y0);
  dataAddr[65] = (void*) (&DoorSystem_P.CoreSubsys.DetectDecrease_vinit);
  dataAddr[66] = (void*) (&DoorSystem_P.CoreSubsys.DetectIncrease1_vinit);
  dataAddr[67] = (void*) (&DoorSystem_P.CoreSubsys.DetectIncrease2_vinit);
  dataAddr[68] = (void*) (&DoorSystem_P.CoreSubsys.DetectIncrease3_vinit);
  dataAddr[69] = (void*) (&DoorSystem_P.CoreSubsys.Constant_Value_c);
  dataAddr[70] = (void*) (&DoorSystem_P.CoreSubsys.Constant1_Value_n);
  dataAddr[71] = (void*) (&DoorSystem_P.CoreSubsys.Constant2_Value);
  dataAddr[72] = (void*) (&DoorSystem_P.CoreSubsys.Constant4_Value);
  dataAddr[73] = (void*) (&DoorSystem_P.CoreSubsys.Constant5_Value);
  dataAddr[74] = (void*) (&DoorSystem_P.CoreSubsys.Constant6_Value);
  dataAddr[75] = (void*) (&DoorSystem_P.CoreSubsys.Constant7_Value);
  dataAddr[76] = (void*) (&DoorSystem_P.CoreSubsys.UnitDelay_InitialCondition);
  dataAddr[77] = (void*)
    (&DoorSystem_P.CoreSubsys.TimerOnDelayNoInit1.Timer_gainval);
  dataAddr[78] = (void*) (&DoorSystem_P.CoreSubsys.TimerOnDelayNoInit1.Timer_IC);
  dataAddr[79] = (void*)
    (&DoorSystem_P.CoreSubsys.TimerOnDelayNoInit1.Timer_LowerSat);
  dataAddr[80] = (void*)
    (&DoorSystem_P.CoreSubsys.TimerOnDelayNoInit2.Timer_gainval);
  dataAddr[81] = (void*) (&DoorSystem_P.CoreSubsys.TimerOnDelayNoInit2.Timer_IC);
  dataAddr[82] = (void*)
    (&DoorSystem_P.CoreSubsys.TimerOnDelayNoInit2.Timer_LowerSat);
  dataAddr[83] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.CompareToConstant2_const);
  dataAddr[84] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.CompareToConstant3_const);
  dataAddr[85] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.UnitDelay_InitialCondition_k);
  dataAddr[86] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.UnitDelay1_InitialCondition_f);
  dataAddr[87] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.UnitDelay2_InitialCondition);
  dataAddr[88] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.UnitDelay3_InitialCondition);
  dataAddr[89] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys_pn.DetectIncrease_vinit);
  dataAddr[90] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys_pn.DetectDecrease_vinit);
  dataAddr[91] = (void*) (&DoorSystem_P.CoreSubsys.IC_Value);
  dataAddr[92] = (void*) (&DoorSystem_P.CoreSubsys.UnitDelay1_InitialCondition);
  dataAddr[93] = (void*) (&DoorSystem_P.CoreSubsys.WeightedSampleTime_WtEt);
  dataAddr[94] = (void*)
    (&DoorSystem_P.CoreSubsys.TimerOffDelayNoInit.Initialise_Value);
  dataAddr[95] = (void*)
    (&DoorSystem_P.CoreSubsys.TimerOffDelayNoInit.OffTime_Value);
  dataAddr[96] = (void*)
    (&DoorSystem_P.CoreSubsys.TimerOffDelayNoInit.DiscreteTimeIntegrator_gainval);
  dataAddr[97] = (void*)
    (&DoorSystem_P.CoreSubsys.TimerOffDelayNoInit.DiscreteTimeIntegrator_UpperSat);
  dataAddr[98] = (void*)
    (&DoorSystem_P.CoreSubsys.TimerOffDelayNoInit.DiscreteTimeIntegrator_LowerSat);
  dataAddr[99] = (void*) (&DoorSystem_P.CoreSubsys.TimerOffDelayNoInit.Gain_Gain);
  dataAddr[100] = (void*) (&DoorSystem_P.CoreSubsys.TimerOffDelayNoInit.IC_Value);
  dataAddr[101] = (void*)
    (&DoorSystem_P.CoreSubsys.TimerOffDelayNoInit1.Initialise_Value);
  dataAddr[102] = (void*)
    (&DoorSystem_P.CoreSubsys.TimerOffDelayNoInit1.OffTime_Value);
  dataAddr[103] = (void*)
    (&DoorSystem_P.CoreSubsys.TimerOffDelayNoInit1.DiscreteTimeIntegrator_gainval);
  dataAddr[104] = (void*)
    (&DoorSystem_P.CoreSubsys.TimerOffDelayNoInit1.DiscreteTimeIntegrator_UpperSat);
  dataAddr[105] = (void*)
    (&DoorSystem_P.CoreSubsys.TimerOffDelayNoInit1.DiscreteTimeIntegrator_LowerSat);
  dataAddr[106] = (void*)
    (&DoorSystem_P.CoreSubsys.TimerOffDelayNoInit1.Gain_Gain);
  dataAddr[107] = (void*)
    (&DoorSystem_P.CoreSubsys.TimerOffDelayNoInit1.IC_Value);
  dataAddr[108] = (void*)
    (&DoorSystem_P.CoreSubsys.TimerOffDelayNoInit2.Initialise_Value);
  dataAddr[109] = (void*)
    (&DoorSystem_P.CoreSubsys.TimerOffDelayNoInit2.OffTime_Value);
  dataAddr[110] = (void*)
    (&DoorSystem_P.CoreSubsys.TimerOffDelayNoInit2.DiscreteTimeIntegrator_gainval);
  dataAddr[111] = (void*)
    (&DoorSystem_P.CoreSubsys.TimerOffDelayNoInit2.DiscreteTimeIntegrator_UpperSat);
  dataAddr[112] = (void*)
    (&DoorSystem_P.CoreSubsys.TimerOffDelayNoInit2.DiscreteTimeIntegrator_LowerSat);
  dataAddr[113] = (void*)
    (&DoorSystem_P.CoreSubsys.TimerOffDelayNoInit2.Gain_Gain);
  dataAddr[114] = (void*)
    (&DoorSystem_P.CoreSubsys.TimerOffDelayNoInit2.IC_Value);
  dataAddr[115] = (void*)
    (&DoorSystem_P.CoreSubsys.TimerOnDelayNoInit1.Constant_Value);
  dataAddr[116] = (void*)
    (&DoorSystem_P.CoreSubsys.TimerOnDelayNoInit2.Constant_Value);
  dataAddr[117] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.DetectIncrease_vinit);
  dataAddr[118] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.DetectIncrease1_vinit_m);
  dataAddr[119] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant_Value_i4);
  dataAddr[120] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant1_Value_h);
  dataAddr[121] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant2_Value);
  dataAddr[122] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant3_Value);
  dataAddr[123] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant4_Value);
  dataAddr[124] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant5_Value);
  dataAddr[125] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.UnitDelay_InitialCondition);
  dataAddr[126] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.ObstacleDetectionFunctionality_PauseBeforeOpeningAttempt);
  dataAddr[127] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.ObstacleDetectionFunctionality_PauseBeforeClosingAttempt);
  dataAddr[128] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.ObstacleDetectionFunctionality_MoveAwayFromObstacle);
  dataAddr[129] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.ObstacleDetectionFunctionality_NumOfClosingAttempts);
  dataAddr[130] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.ObstacleDetectionFunctionality_NumOfOpeningAttempts);
  dataAddr[131] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys_pn.TimerOffDelayNoInit_n.Initialise_Value);
  dataAddr[132] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys_pn.TimerOffDelayNoInit_n.OffTime_Value);
  dataAddr[133] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys_pn.TimerOffDelayNoInit_n.DiscreteTimeIntegrator_gainval);
  dataAddr[134] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys_pn.TimerOffDelayNoInit_n.DiscreteTimeIntegrator_UpperSat);
  dataAddr[135] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys_pn.TimerOffDelayNoInit_n.DiscreteTimeIntegrator_LowerSat);
  dataAddr[136] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys_pn.TimerOffDelayNoInit_n.Gain_Gain);
  dataAddr[137] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys_pn.TimerOffDelayNoInit_n.IC_Value);
  dataAddr[138] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys_pn.TimerOffDelayNoInit.Initialise_Value);
  dataAddr[139] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys_pn.TimerOffDelayNoInit.OffTime_Value);
  dataAddr[140] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys_pn.TimerOffDelayNoInit.DiscreteTimeIntegrator_gainval);
  dataAddr[141] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys_pn.TimerOffDelayNoInit.DiscreteTimeIntegrator_UpperSat);
  dataAddr[142] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys_pn.TimerOffDelayNoInit.DiscreteTimeIntegrator_LowerSat);
  dataAddr[143] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys_pn.TimerOffDelayNoInit.Gain_Gain);
  dataAddr[144] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys_pn.TimerOffDelayNoInit.IC_Value);
  dataAddr[145] = (void*)
    (&DoorSystem_P.CoreSubsys.TimerOffDelayNoInit.Constant_Value);
  dataAddr[146] = (void*)
    (&DoorSystem_P.CoreSubsys.TimerOffDelayNoInit1.Constant_Value);
  dataAddr[147] = (void*)
    (&DoorSystem_P.CoreSubsys.TimerOffDelayNoInit2.Constant_Value);
  dataAddr[148] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.IC_Value);
  dataAddr[149] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.UnitDelay1_InitialCondition);
  dataAddr[150] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.WeightedSampleTime_WtEt);
  dataAddr[151] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.CompareToConstant1_const_k);
  dataAddr[152] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.CompareToConstant2_const_i);
  dataAddr[153] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant7_Value_d);
  dataAddr[154] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Speed_Threshold);
  dataAddr[155] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant7_Value);
  dataAddr[156] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Speed_Threshold_h);
  dataAddr[157] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.DetectIncrease_vinit_g);
  dataAddr[158] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.DetectIncrease1_vinit_i5);
  dataAddr[159] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.SRLatchResetPriority_initial_condition_m);
  dataAddr[160] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.SRLatchResetPriority_initial_condition_k);
  dataAddr[161] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.DetectDecrease_vinit_b);
  dataAddr[162] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.DetectIncrease_vinit_dn);
  dataAddr[163] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.MotorCloseLatch_initial_condition);
  dataAddr[164] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.MotorOpenLatch_initial_condition);
  dataAddr[165] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.DetectDecrease_vinit_i);
  dataAddr[166] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.DetectIncrease_vinit_o);
  dataAddr[167] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant_Value_c);
  dataAddr[168] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant_Value_co);
  dataAddr[169] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant_Value_d);
  dataAddr[170] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant_Value_ca);
  dataAddr[171] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys_pn.TimerOffDelayNoInit_n.Constant_Value);
  dataAddr[172] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys_pn.TimerOffDelayNoInit.Constant_Value);
  dataAddr[173] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant_Value_j);
  dataAddr[174] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant1_Value_b);
  dataAddr[175] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant_Value_m);
  dataAddr[176] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant_Value);
  dataAddr[177] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.DetectDecrease_vinit_f);
  dataAddr[178] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.DetectIncrease_vinit_d);
  dataAddr[179] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.DetectIncrease1_vinit_i);
  dataAddr[180] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.SRLatchResetPriority_initial_condition);
  dataAddr[181] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.SRLatchResetPriority1_initial_condition);
  dataAddr[182] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.SRLatchResetPriority2_initial_condition);
  dataAddr[183] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Messages_Value);
  dataAddr[184] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.RedON_Value);
  dataAddr[185] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.YellowFlashing_Value);
  dataAddr[186] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.YellowON_Value);
  dataAddr[187] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant_Value_b);
  dataAddr[188] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant_Value_l);
  dataAddr[189] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.DoorClose.Constant_Value);
  dataAddr[190] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.DoorCloseDelay.Timer_gainval);
  dataAddr[191] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.DoorCloseDelay.Timer_IC);
  dataAddr[192] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.DoorCloseDelay.Timer_LowerSat);
  dataAddr[193] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.DoorOpen.Constant_Value);
  dataAddr[194] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.DoorOpenDelay.Timer_gainval);
  dataAddr[195] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.DoorOpenDelay.Timer_IC);
  dataAddr[196] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.DoorOpenDelay.Timer_LowerSat);
  dataAddr[197] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.NoMotorCommand.Constant_Value);
  dataAddr[198] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Gain1_Gain);
  dataAddr[199] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.CompareToConstant1_const);
  dataAddr[200] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.CompareToConstant4_const);
  dataAddr[201] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.DetectDecrease_vinit);
  dataAddr[202] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.DetectDecrease1_vinit);
  dataAddr[203] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.DetectIncrease_vinit_p);
  dataAddr[204] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.DetectIncrease1_vinit);
  dataAddr[205] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.SRLatchSetPriority1_initial_condition);
  dataAddr[206] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.SRLatchSetPriority2_initial_condition);
  dataAddr[207] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant_Value_i);
  dataAddr[208] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant_Value_a);
  dataAddr[209] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.LeadingEdgePulseTunable.DetectIncrease_vinit);
  dataAddr[210] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.LeadingEdgePulseTunable1.DetectIncrease_vinit);
  dataAddr[211] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant_Value_e);
  dataAddr[212] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.DoorCloseDelay.Constant_Value);
  dataAddr[213] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.DoorOpenDelay.Constant_Value);
  dataAddr[214] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.LeadingEdgePulseTunable.Initialise_Value);
  dataAddr[215] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.LeadingEdgePulseTunable.DiscreteTimeIntegrator_gainval);
  dataAddr[216] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.LeadingEdgePulseTunable.DiscreteTimeIntegrator_LowerSat);
  dataAddr[217] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.LeadingEdgePulseTunable.Gain_Gain);
  dataAddr[218] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.LeadingEdgePulseTunable.IC_Value);
  dataAddr[219] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.LeadingEdgePulseTunable1.Initialise_Value);
  dataAddr[220] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.LeadingEdgePulseTunable1.DiscreteTimeIntegrator_gainval);
  dataAddr[221] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.LeadingEdgePulseTunable1.DiscreteTimeIntegrator_LowerSat);
  dataAddr[222] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.LeadingEdgePulseTunable1.Gain_Gain);
  dataAddr[223] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.LeadingEdgePulseTunable1.IC_Value);
  dataAddr[224] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant_Value_g);
  dataAddr[225] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.Constant1_Value);
  dataAddr[226] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.IfActionSubsystem1.Constant_Value);
  dataAddr[227] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.IfActionSubsystem1.Constant1_Value);
  dataAddr[228] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.IfActionSubsystem2.Constant_Value);
  dataAddr[229] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.IfActionSubsystem2.Constant1_Value);
  dataAddr[230] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.IfActionSubsystem3.Constant_Value);
  dataAddr[231] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.IfActionSubsystem3.Constant1_Value);
  dataAddr[232] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.IfActionSubsystem4.Constant_Value);
  dataAddr[233] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.IfActionSubsystem4.Constant1_Value);
  dataAddr[234] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.LeadingEdgePulseTunable.Constant_Value);
  dataAddr[235] = (void*)
    (&DoorSystem_P.CoreSubsys.CoreSubsys.CoreSubsys.LeadingEdgePulseTunable1.Constant_Value);
}

#endif

/* Initialize Data Run-Time Dimension Buffer Address */
#ifndef HOST_CAPI_BUILD

static void DoorSystem_InitializeVarDimsAddr(int32_T* vardimsAddr[])
{
  vardimsAddr[0] = (NULL);
}

#endif

#ifndef HOST_CAPI_BUILD

/* Initialize logging function pointers */
static void DoorSystem_InitializeLoggingFunctions(RTWLoggingFcnPtr loggingPtrs[])
{
  loggingPtrs[0] = (NULL);
  loggingPtrs[1] = (NULL);
  loggingPtrs[2] = (NULL);
  loggingPtrs[3] = (NULL);
  loggingPtrs[4] = (NULL);
  loggingPtrs[5] = (NULL);
  loggingPtrs[6] = (NULL);
  loggingPtrs[7] = (NULL);
  loggingPtrs[8] = (NULL);
  loggingPtrs[9] = (NULL);
  loggingPtrs[10] = (NULL);
  loggingPtrs[11] = (NULL);
  loggingPtrs[12] = (NULL);
  loggingPtrs[13] = (NULL);
  loggingPtrs[14] = (NULL);
  loggingPtrs[15] = (NULL);
  loggingPtrs[16] = (NULL);
  loggingPtrs[17] = (NULL);
  loggingPtrs[18] = (NULL);
  loggingPtrs[19] = (NULL);
  loggingPtrs[20] = (NULL);
  loggingPtrs[21] = (NULL);
  loggingPtrs[22] = (NULL);
  loggingPtrs[23] = (NULL);
  loggingPtrs[24] = (NULL);
  loggingPtrs[25] = (NULL);
  loggingPtrs[26] = (NULL);
  loggingPtrs[27] = (NULL);
  loggingPtrs[28] = (NULL);
  loggingPtrs[29] = (NULL);
  loggingPtrs[30] = (NULL);
  loggingPtrs[31] = (NULL);
  loggingPtrs[32] = (NULL);
  loggingPtrs[33] = (NULL);
  loggingPtrs[34] = (NULL);
  loggingPtrs[35] = (NULL);
  loggingPtrs[36] = (NULL);
  loggingPtrs[37] = (NULL);
  loggingPtrs[38] = (NULL);
  loggingPtrs[39] = (NULL);
  loggingPtrs[40] = (NULL);
  loggingPtrs[41] = (NULL);
  loggingPtrs[42] = (NULL);
  loggingPtrs[43] = (NULL);
  loggingPtrs[44] = (NULL);
  loggingPtrs[45] = (NULL);
  loggingPtrs[46] = (NULL);
  loggingPtrs[47] = (NULL);
  loggingPtrs[48] = (NULL);
  loggingPtrs[49] = (NULL);
  loggingPtrs[50] = (NULL);
  loggingPtrs[51] = (NULL);
  loggingPtrs[52] = (NULL);
  loggingPtrs[53] = (NULL);
  loggingPtrs[54] = (NULL);
  loggingPtrs[55] = (NULL);
  loggingPtrs[56] = (NULL);
  loggingPtrs[57] = (NULL);
  loggingPtrs[58] = (NULL);
  loggingPtrs[59] = (NULL);
  loggingPtrs[60] = (NULL);
  loggingPtrs[61] = (NULL);
  loggingPtrs[62] = (NULL);
  loggingPtrs[63] = (NULL);
  loggingPtrs[64] = (NULL);
  loggingPtrs[65] = (NULL);
  loggingPtrs[66] = (NULL);
  loggingPtrs[67] = (NULL);
  loggingPtrs[68] = (NULL);
  loggingPtrs[69] = (NULL);
  loggingPtrs[70] = (NULL);
  loggingPtrs[71] = (NULL);
  loggingPtrs[72] = (NULL);
  loggingPtrs[73] = (NULL);
  loggingPtrs[74] = (NULL);
  loggingPtrs[75] = (NULL);
  loggingPtrs[76] = (NULL);
  loggingPtrs[77] = (NULL);
  loggingPtrs[78] = (NULL);
  loggingPtrs[79] = (NULL);
  loggingPtrs[80] = (NULL);
  loggingPtrs[81] = (NULL);
  loggingPtrs[82] = (NULL);
  loggingPtrs[83] = (NULL);
  loggingPtrs[84] = (NULL);
  loggingPtrs[85] = (NULL);
  loggingPtrs[86] = (NULL);
  loggingPtrs[87] = (NULL);
  loggingPtrs[88] = (NULL);
  loggingPtrs[89] = (NULL);
  loggingPtrs[90] = (NULL);
  loggingPtrs[91] = (NULL);
  loggingPtrs[92] = (NULL);
  loggingPtrs[93] = (NULL);
  loggingPtrs[94] = (NULL);
  loggingPtrs[95] = (NULL);
  loggingPtrs[96] = (NULL);
  loggingPtrs[97] = (NULL);
  loggingPtrs[98] = (NULL);
  loggingPtrs[99] = (NULL);
  loggingPtrs[100] = (NULL);
  loggingPtrs[101] = (NULL);
  loggingPtrs[102] = (NULL);
  loggingPtrs[103] = (NULL);
  loggingPtrs[104] = (NULL);
  loggingPtrs[105] = (NULL);
  loggingPtrs[106] = (NULL);
  loggingPtrs[107] = (NULL);
  loggingPtrs[108] = (NULL);
  loggingPtrs[109] = (NULL);
  loggingPtrs[110] = (NULL);
  loggingPtrs[111] = (NULL);
  loggingPtrs[112] = (NULL);
  loggingPtrs[113] = (NULL);
  loggingPtrs[114] = (NULL);
  loggingPtrs[115] = (NULL);
  loggingPtrs[116] = (NULL);
  loggingPtrs[117] = (NULL);
  loggingPtrs[118] = (NULL);
  loggingPtrs[119] = (NULL);
  loggingPtrs[120] = (NULL);
  loggingPtrs[121] = (NULL);
  loggingPtrs[122] = (NULL);
  loggingPtrs[123] = (NULL);
  loggingPtrs[124] = (NULL);
  loggingPtrs[125] = (NULL);
  loggingPtrs[126] = (NULL);
  loggingPtrs[127] = (NULL);
  loggingPtrs[128] = (NULL);
  loggingPtrs[129] = (NULL);
  loggingPtrs[130] = (NULL);
  loggingPtrs[131] = (NULL);
  loggingPtrs[132] = (NULL);
  loggingPtrs[133] = (NULL);
  loggingPtrs[134] = (NULL);
  loggingPtrs[135] = (NULL);
  loggingPtrs[136] = (NULL);
  loggingPtrs[137] = (NULL);
  loggingPtrs[138] = (NULL);
  loggingPtrs[139] = (NULL);
  loggingPtrs[140] = (NULL);
  loggingPtrs[141] = (NULL);
  loggingPtrs[142] = (NULL);
  loggingPtrs[143] = (NULL);
  loggingPtrs[144] = (NULL);
  loggingPtrs[145] = (NULL);
  loggingPtrs[146] = (NULL);
  loggingPtrs[147] = (NULL);
  loggingPtrs[148] = (NULL);
  loggingPtrs[149] = (NULL);
  loggingPtrs[150] = (NULL);
  loggingPtrs[151] = (NULL);
  loggingPtrs[152] = (NULL);
  loggingPtrs[153] = (NULL);
  loggingPtrs[154] = (NULL);
  loggingPtrs[155] = (NULL);
  loggingPtrs[156] = (NULL);
  loggingPtrs[157] = (NULL);
  loggingPtrs[158] = (NULL);
  loggingPtrs[159] = (NULL);
  loggingPtrs[160] = (NULL);
  loggingPtrs[161] = (NULL);
  loggingPtrs[162] = (NULL);
  loggingPtrs[163] = (NULL);
  loggingPtrs[164] = (NULL);
  loggingPtrs[165] = (NULL);
  loggingPtrs[166] = (NULL);
  loggingPtrs[167] = (NULL);
  loggingPtrs[168] = (NULL);
  loggingPtrs[169] = (NULL);
  loggingPtrs[170] = (NULL);
  loggingPtrs[171] = (NULL);
  loggingPtrs[172] = (NULL);
  loggingPtrs[173] = (NULL);
  loggingPtrs[174] = (NULL);
  loggingPtrs[175] = (NULL);
  loggingPtrs[176] = (NULL);
  loggingPtrs[177] = (NULL);
  loggingPtrs[178] = (NULL);
  loggingPtrs[179] = (NULL);
  loggingPtrs[180] = (NULL);
  loggingPtrs[181] = (NULL);
  loggingPtrs[182] = (NULL);
  loggingPtrs[183] = (NULL);
  loggingPtrs[184] = (NULL);
  loggingPtrs[185] = (NULL);
  loggingPtrs[186] = (NULL);
  loggingPtrs[187] = (NULL);
  loggingPtrs[188] = (NULL);
  loggingPtrs[189] = (NULL);
  loggingPtrs[190] = (NULL);
  loggingPtrs[191] = (NULL);
  loggingPtrs[192] = (NULL);
  loggingPtrs[193] = (NULL);
  loggingPtrs[194] = (NULL);
  loggingPtrs[195] = (NULL);
  loggingPtrs[196] = (NULL);
  loggingPtrs[197] = (NULL);
  loggingPtrs[198] = (NULL);
  loggingPtrs[199] = (NULL);
  loggingPtrs[200] = (NULL);
  loggingPtrs[201] = (NULL);
  loggingPtrs[202] = (NULL);
  loggingPtrs[203] = (NULL);
  loggingPtrs[204] = (NULL);
  loggingPtrs[205] = (NULL);
  loggingPtrs[206] = (NULL);
  loggingPtrs[207] = (NULL);
  loggingPtrs[208] = (NULL);
  loggingPtrs[209] = (NULL);
  loggingPtrs[210] = (NULL);
  loggingPtrs[211] = (NULL);
  loggingPtrs[212] = (NULL);
  loggingPtrs[213] = (NULL);
  loggingPtrs[214] = (NULL);
  loggingPtrs[215] = (NULL);
  loggingPtrs[216] = (NULL);
  loggingPtrs[217] = (NULL);
  loggingPtrs[218] = (NULL);
  loggingPtrs[219] = (NULL);
  loggingPtrs[220] = (NULL);
  loggingPtrs[221] = (NULL);
  loggingPtrs[222] = (NULL);
  loggingPtrs[223] = (NULL);
  loggingPtrs[224] = (NULL);
  loggingPtrs[225] = (NULL);
  loggingPtrs[226] = (NULL);
  loggingPtrs[227] = (NULL);
  loggingPtrs[228] = (NULL);
  loggingPtrs[229] = (NULL);
  loggingPtrs[230] = (NULL);
  loggingPtrs[231] = (NULL);
  loggingPtrs[232] = (NULL);
  loggingPtrs[233] = (NULL);
  loggingPtrs[234] = (NULL);
  loggingPtrs[235] = (NULL);
}

#endif

/* Data Type Map - use dataTypeMapIndex to access this structure */
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, *
   * isComplex, isPointer, enumStorageType */
  { "unsigned char", "boolean_T", 0, 0, sizeof(boolean_T), SS_BOOLEAN, 0, 0, 0 },

  { "struct", "BD_DoorSystem_In_Vehicle_TrainWires", 3, 1, sizeof
    (BD_DoorSystem_In_Vehicle_TrainWires), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_DoorSystem_Out_Vehicle_ElectricalSignals", 6, 4, sizeof
    (BD_DoorSystem_Out_Vehicle_ElectricalSignals), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_DoorSystem_Out_Door_ElectricalSignals", 2, 10, sizeof
    (BD_DoorSystem_Out_Door_ElectricalSignals), SS_STRUCT, 0, 0, 0 },

  { "double", "real_T", 0, 0, sizeof(real_T), SS_DOUBLE, 0, 0, 0 },

  { "struct", "BD_DoorSystem_Out_Door_OutputControlStates", 3, 12, sizeof
    (BD_DoorSystem_Out_Door_OutputControlStates), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_DoorSystem_Out_Door_Audio", 7, 15, sizeof
    (BD_DoorSystem_Out_Door_Audio), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_DoorSystem_Out_Door_TCMS_Messages", 15, 22, sizeof
    (BD_DoorSystem_Out_Door_TCMS_Messages), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_DoorSystem_Out_Door_TCMS", 12, 37, sizeof
    (BD_DoorSystem_Out_Door_TCMS), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_DoorSystem_Out_Door", 4, 49, sizeof(BD_DoorSystem_Out_Door),
    SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_DoorSystem_Out_Emergency_Door", 7, 53, sizeof
    (BD_DoorSystem_Out_Emergency_Door), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_DoorSystem_Out_Vehicle", 3, 60, sizeof
    (BD_DoorSystem_Out_Vehicle), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_DoorSystem_Cfg_Door", 2, 63, sizeof(BD_DoorSystem_Cfg_Door),
    SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_DoorSystem_In_Door_InputControlStates", 5, 65, sizeof
    (BD_DoorSystem_In_Door_InputControlStates), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_DoorSystem_In_Door_ElectricalSignals", 8, 70, sizeof
    (BD_DoorSystem_In_Door_ElectricalSignals), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_DoorSystem_In_Door_Faults", 18, 78, sizeof
    (BD_DoorSystem_In_Door_Faults), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_DoorSystem_In_Door", 4, 96, sizeof(BD_DoorSystem_In_Door),
    SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_DoorSystem_In_Vehicle", 1, 100, sizeof
    (BD_DoorSystem_In_Vehicle), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_DoorSystem_Int_DoorControlAudio", 5, 101, sizeof
    (BD_DoorSystem_Int_DoorControlAudio), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_DoorSystem_Int_DoorControlIndicators", 6, 106, sizeof
    (BD_DoorSystem_Int_DoorControlIndicators), SS_STRUCT, 0, 0, 0 },

  { "signed char", "int8_T", 0, 0, sizeof(int8_T), SS_INT8, 0, 0, 0 }
};

#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif

/* Structure Element Map - use elemMapIndex to access this structure */
static TARGET_CONST rtwCAPI_ElementMap rtElementMap[] = {
  /* elementName, elementOffset, dataTypeIndex, dimIndex, fxpIndex */
  { (NULL), 0, 0, 0, 0 },

  { "TrainDoorInterlockOk", rt_offsetof(BD_DoorSystem_In_Vehicle_TrainWires,
    TrainDoorInterlockOk), 0, 0, 0 },

  { "TrainLeftDoorInterlockOk", rt_offsetof(BD_DoorSystem_In_Vehicle_TrainWires,
    TrainLeftDoorInterlockOk), 0, 0, 0 },

  { "TrainRightDoorInterlockOk", rt_offsetof(BD_DoorSystem_In_Vehicle_TrainWires,
    TrainRightDoorInterlockOk), 0, 0, 0 },

  { "TrainDoorInterlockOk", rt_offsetof
    (BD_DoorSystem_Out_Vehicle_ElectricalSignals, TrainDoorInterlockOk), 0, 0, 0
  },

  { "VehicleDoorInterlockOk", rt_offsetof
    (BD_DoorSystem_Out_Vehicle_ElectricalSignals, VehicleDoorInterlockOk), 0, 0,
    0 },

  { "TrainLeftDoorInterlockOk", rt_offsetof
    (BD_DoorSystem_Out_Vehicle_ElectricalSignals, TrainLeftDoorInterlockOk), 0,
    0, 0 },

  { "TrainRightDoorInterlockOk", rt_offsetof
    (BD_DoorSystem_Out_Vehicle_ElectricalSignals, TrainRightDoorInterlockOk), 0,
    0, 0 },

  { "VehicleLeftDoorInterlockOk", rt_offsetof
    (BD_DoorSystem_Out_Vehicle_ElectricalSignals, VehicleLeftDoorInterlockOk), 0,
    0, 0 },

  { "VehicleRightDoorInterlockOk", rt_offsetof
    (BD_DoorSystem_Out_Vehicle_ElectricalSignals, VehicleRightDoorInterlockOk),
    0, 0, 0 },

  { "DoorCloseInterlock", rt_offsetof(BD_DoorSystem_Out_Door_ElectricalSignals,
    DoorCloseInterlock), 0, 0, 0 },

  { "DoorClosed", rt_offsetof(BD_DoorSystem_Out_Door_ElectricalSignals,
    DoorClosed), 0, 0, 0 },

  { "DoorPosition", rt_offsetof(BD_DoorSystem_Out_Door_OutputControlStates,
    DoorPosition), 4, 0, 0 },

  { "DoorOutsideLamp", rt_offsetof(BD_DoorSystem_Out_Door_OutputControlStates,
    DoorOutsideLamp), 4, 0, 0 },

  { "DoorInsideLamp", rt_offsetof(BD_DoorSystem_Out_Door_OutputControlStates,
    DoorInsideLamp), 4, 0, 0 },

  { "DoorOpeningAuthorised", rt_offsetof(BD_DoorSystem_Out_Door_Audio,
    DoorOpeningAuthorised), 4, 0, 0 },

  { "DoorOpeningAlarm", rt_offsetof(BD_DoorSystem_Out_Door_Audio,
    DoorOpeningAlarm), 4, 0, 0 },

  { "DoorClosingAlarm", rt_offsetof(BD_DoorSystem_Out_Door_Audio,
    DoorClosingAlarm), 4, 0, 0 },

  { "DoorEmergencyReleased", rt_offsetof(BD_DoorSystem_Out_Door_Audio,
    DoorEmergencyReleased), 4, 0, 0 },

  { "DoorIsolated", rt_offsetof(BD_DoorSystem_Out_Door_Audio, DoorIsolated), 4,
    0, 0 },

  { "DoorClosing", rt_offsetof(BD_DoorSystem_Out_Door_Audio, DoorClosing), 4, 0,
    0 },

  { "DoorOpening", rt_offsetof(BD_DoorSystem_Out_Door_Audio, DoorOpening), 4, 0,
    0 },

  { "DoorOpenObstacleDetected", rt_offsetof(BD_DoorSystem_Out_Door_TCMS_Messages,
    DoorOpenObstacleDetected), 0, 0, 0 },

  { "DoorCloseObstacleDetected", rt_offsetof
    (BD_DoorSystem_Out_Door_TCMS_Messages, DoorCloseObstacleDetected), 0, 0, 0 },

  { "DoorFailedToLock", rt_offsetof(BD_DoorSystem_Out_Door_TCMS_Messages,
    DoorFailedToLock), 0, 0, 0 },

  { "DoorFailedToUnlock", rt_offsetof(BD_DoorSystem_Out_Door_TCMS_Messages,
    DoorFailedToUnlock), 0, 0, 0 },

  { "DoorMotorFailure", rt_offsetof(BD_DoorSystem_Out_Door_TCMS_Messages,
    DoorMotorFailure), 0, 0, 0 },

  { "DoorMajorFault", rt_offsetof(BD_DoorSystem_Out_Door_TCMS_Messages,
    DoorMajorFault), 0, 0, 0 },

  { "DCSRFailure", rt_offsetof(BD_DoorSystem_Out_Door_TCMS_Messages, DCSRFailure),
    0, 0, 0 },

  { "DCSLFailure", rt_offsetof(BD_DoorSystem_Out_Door_TCMS_Messages, DCSLFailure),
    0, 0, 0 },

  { "DLSRFailure", rt_offsetof(BD_DoorSystem_Out_Door_TCMS_Messages, DLSRFailure),
    0, 0, 0 },

  { "DLSLFailure", rt_offsetof(BD_DoorSystem_Out_Door_TCMS_Messages, DLSLFailure),
    0, 0, 0 },

  { "DCUFailure", rt_offsetof(BD_DoorSystem_Out_Door_TCMS_Messages, DCUFailure),
    0, 0, 0 },

  { "DoorUnexpectedUnlocking", rt_offsetof(BD_DoorSystem_Out_Door_TCMS_Messages,
    DoorUnexpectedUnlocking), 0, 0, 0 },

  { "DoorIsolatedWire", rt_offsetof(BD_DoorSystem_Out_Door_TCMS_Messages,
    DoorIsolatedWire), 0, 0, 0 },

  { "DoorEmergencyHandleWire", rt_offsetof(BD_DoorSystem_Out_Door_TCMS_Messages,
    DoorEmergencyHandleWire), 0, 0, 0 },

  { "UnexpectedDoorOpeningDetectedByCC", rt_offsetof
    (BD_DoorSystem_Out_Door_TCMS_Messages, UnexpectedDoorOpeningDetectedByCC), 0,
    0, 0 },

  { "DoorClosedStatus", rt_offsetof(BD_DoorSystem_Out_Door_TCMS,
    DoorClosedStatus), 0, 0, 0 },

  { "DoorOpenStatus", rt_offsetof(BD_DoorSystem_Out_Door_TCMS, DoorOpenStatus),
    0, 0, 0 },

  { "DoorReleasedAuthorisedToOpenStatus", rt_offsetof
    (BD_DoorSystem_Out_Door_TCMS, DoorReleasedAuthorisedToOpenStatus), 0, 0, 0 },

  { "DoorEmergencyReleasedStatus", rt_offsetof(BD_DoorSystem_Out_Door_TCMS,
    DoorEmergencyReleasedStatus), 0, 0, 0 },

  { "DoorIsolatedStatus", rt_offsetof(BD_DoorSystem_Out_Door_TCMS,
    DoorIsolatedStatus), 0, 0, 0 },

  { "DoorFaultStatus", rt_offsetof(BD_DoorSystem_Out_Door_TCMS, DoorFaultStatus),
    0, 0, 0 },

  { "DoorObstacleDetected", rt_offsetof(BD_DoorSystem_Out_Door_TCMS,
    DoorObstacleDetected), 0, 0, 0 },

  { "DoorObstacleUnableToClose", rt_offsetof(BD_DoorSystem_Out_Door_TCMS,
    DoorObstacleUnableToClose), 0, 0, 0 },

  { "DoorLockedStatus", rt_offsetof(BD_DoorSystem_Out_Door_TCMS,
    DoorLockedStatus), 0, 0, 0 },

  { "DoorOpenPBLight", rt_offsetof(BD_DoorSystem_Out_Door_TCMS, DoorOpenPBLight),
    0, 0, 0 },

  { "DoorClosedPBLight", rt_offsetof(BD_DoorSystem_Out_Door_TCMS,
    DoorClosedPBLight), 0, 0, 0 },

  { "Messages", rt_offsetof(BD_DoorSystem_Out_Door_TCMS, Messages), 7, 0, 0 },

  { "ElectricalSignals", rt_offsetof(BD_DoorSystem_Out_Door, ElectricalSignals),
    3, 0, 0 },

  { "OutputControlStates", rt_offsetof(BD_DoorSystem_Out_Door,
    OutputControlStates), 5, 0, 0 },

  { "Audio", rt_offsetof(BD_DoorSystem_Out_Door, Audio), 6, 0, 0 },

  { "TCMS", rt_offsetof(BD_DoorSystem_Out_Door, TCMS), 8, 0, 0 },

  { "Ramp", rt_offsetof(BD_DoorSystem_Out_Emergency_Door, Ramp), 4, 0, 0 },

  { "EmergencyDoorOpen", rt_offsetof(BD_DoorSystem_Out_Emergency_Door,
    EmergencyDoorOpen), 4, 0, 0 },

  { "EmergencyDoorLocked", rt_offsetof(BD_DoorSystem_Out_Emergency_Door,
    EmergencyDoorLocked), 0, 0, 0 },

  { "GasSpringLocked", rt_offsetof(BD_DoorSystem_Out_Emergency_Door,
    GasSpringLocked), 4, 0, 0 },

  { "RampSupportDown", rt_offsetof(BD_DoorSystem_Out_Emergency_Door,
    RampSupportDown), 4, 0, 0 },

  { "LockingLeverUnlockAuth", rt_offsetof(BD_DoorSystem_Out_Emergency_Door,
    LockingLeverUnlockAuth), 4, 0, 0 },

  { "EmerDoorOpenFaultMessage", rt_offsetof(BD_DoorSystem_Out_Emergency_Door,
    EmerDoorOpenFaultMessage), 0, 0, 0 },

  { "VehicleElectrical", rt_offsetof(BD_DoorSystem_Out_Vehicle,
    VehicleElectrical), 2, 0, 0 },

  { "Doors", rt_offsetof(BD_DoorSystem_Out_Vehicle, Doors), 9, 2, 0 },

  { "EmergencyDoor", rt_offsetof(BD_DoorSystem_Out_Vehicle, EmergencyDoor), 10,
    0, 0 },

  { "isLeft", rt_offsetof(BD_DoorSystem_Cfg_Door, isLeft), 4, 0, 0 },

  { "NumberOfDoors", rt_offsetof(BD_DoorSystem_Cfg_Door, NumberOfDoors), 4, 0, 0
  },

  { "LocalDoorOpenPB", rt_offsetof(BD_DoorSystem_In_Door_InputControlStates,
    LocalDoorOpenPB), 4, 0, 0 },

  { "OpenCloseWidget", rt_offsetof(BD_DoorSystem_In_Door_InputControlStates,
    OpenCloseWidget), 4, 0, 0 },

  { "EmergencyAccessDevice", rt_offsetof
    (BD_DoorSystem_In_Door_InputControlStates, EmergencyAccessDevice), 4, 0, 0 },

  { "EmergencyEgressDevice", rt_offsetof
    (BD_DoorSystem_In_Door_InputControlStates, EmergencyEgressDevice), 4, 0, 0 },

  { "LocalDoorIsolationLock", rt_offsetof
    (BD_DoorSystem_In_Door_InputControlStates, LocalDoorIsolationLock), 4, 0, 0
  },

  { "DoorControlPower", rt_offsetof(BD_DoorSystem_In_Door_ElectricalSignals,
    DoorControlPower), 0, 0, 0 },

  { "DoorMotorPower", rt_offsetof(BD_DoorSystem_In_Door_ElectricalSignals,
    DoorMotorPower), 0, 0, 0 },

  { "DoorEnable", rt_offsetof(BD_DoorSystem_In_Door_ElectricalSignals,
    DoorEnable), 0, 0, 0 },

  { "DoorRelease", rt_offsetof(BD_DoorSystem_In_Door_ElectricalSignals,
    DoorRelease), 0, 0, 0 },

  { "DoorOpen", rt_offsetof(BD_DoorSystem_In_Door_ElectricalSignals, DoorOpen),
    0, 0, 0 },

  { "DoorClose", rt_offsetof(BD_DoorSystem_In_Door_ElectricalSignals, DoorClose),
    0, 0, 0 },

  { "DoorEmergencyRelease", rt_offsetof(BD_DoorSystem_In_Door_ElectricalSignals,
    DoorEmergencyRelease), 0, 0, 0 },

  { "DoorIsolation", rt_offsetof(BD_DoorSystem_In_Door_ElectricalSignals,
    DoorIsolation), 0, 0, 0 },

  { "ObjectObstructingDoorWhileClosing", rt_offsetof
    (BD_DoorSystem_In_Door_Faults, ObjectObstructingDoorWhileClosing), 4, 0, 0 },

  { "ObjectObstructingDoorWhileOpening", rt_offsetof
    (BD_DoorSystem_In_Door_Faults, ObjectObstructingDoorWhileOpening), 4, 0, 0 },

  { "DoorFailToClose", rt_offsetof(BD_DoorSystem_In_Door_Faults, DoorFailToClose),
    4, 0, 0 },

  { "DoorFailToOpen", rt_offsetof(BD_DoorSystem_In_Door_Faults, DoorFailToOpen),
    4, 0, 0 },

  { "DoorMotorCircuitFailure", rt_offsetof(BD_DoorSystem_In_Door_Faults,
    DoorMotorCircuitFailure), 4, 0, 0 },

  { "DoorFailedToLock", rt_offsetof(BD_DoorSystem_In_Door_Faults,
    DoorFailedToLock), 4, 0, 0 },

  { "DoorFailedToUnlock", rt_offsetof(BD_DoorSystem_In_Door_Faults,
    DoorFailedToUnlock), 4, 0, 0 },

  { "DoorUnexpectedUnlocking", rt_offsetof(BD_DoorSystem_In_Door_Faults,
    DoorUnexpectedUnlocking), 4, 0, 0 },

  { "DoorDCUFailure", rt_offsetof(BD_DoorSystem_In_Door_Faults, DoorDCUFailure),
    4, 0, 0 },

  { "DCSRFailure", rt_offsetof(BD_DoorSystem_In_Door_Faults, DCSRFailure), 4, 0,
    0 },

  { "DCSLFailure", rt_offsetof(BD_DoorSystem_In_Door_Faults, DCSLFailure), 4, 0,
    0 },

  { "DLSRFailure", rt_offsetof(BD_DoorSystem_In_Door_Faults, DLSRFailure), 4, 0,
    0 },

  { "DLSLFailure", rt_offsetof(BD_DoorSystem_In_Door_Faults, DLSLFailure), 4, 0,
    0 },

  { "DoorMajorFault", rt_offsetof(BD_DoorSystem_In_Door_Faults, DoorMajorFault),
    4, 0, 0 },

  { "DoorUnauthorisedOpen", rt_offsetof(BD_DoorSystem_In_Door_Faults,
    DoorUnauthorisedOpen), 4, 0, 0 },

  { "UnexpectedDoorOpeningDetectedByCC", rt_offsetof
    (BD_DoorSystem_In_Door_Faults, UnexpectedDoorOpeningDetectedByCC), 4, 0, 0 },

  { "EmergencyDoorMechanicalUnlocked", rt_offsetof(BD_DoorSystem_In_Door_Faults,
    EmergencyDoorMechanicalUnlocked), 4, 0, 0 },

  { "DoorEmergencyHandleActivation", rt_offsetof(BD_DoorSystem_In_Door_Faults,
    DoorEmergencyHandleActivation), 4, 0, 0 },

  { "Config", rt_offsetof(BD_DoorSystem_In_Door, Config), 12, 0, 0 },

  { "InputControlStates", rt_offsetof(BD_DoorSystem_In_Door, InputControlStates),
    13, 0, 0 },

  { "ElectricalSignals", rt_offsetof(BD_DoorSystem_In_Door, ElectricalSignals),
    14, 0, 0 },

  { "Faults", rt_offsetof(BD_DoorSystem_In_Door, Faults), 15, 0, 0 },

  { "Doors", rt_offsetof(BD_DoorSystem_In_Vehicle, Doors), 16, 1, 0 },

  { "DoorOpeningAuthorised", rt_offsetof(BD_DoorSystem_Int_DoorControlAudio,
    DoorOpeningAuthorised), 4, 0, 0 },

  { "DoorOpeningAlarm", rt_offsetof(BD_DoorSystem_Int_DoorControlAudio,
    DoorOpeningAlarm), 4, 0, 0 },

  { "DoorClosingAlarm", rt_offsetof(BD_DoorSystem_Int_DoorControlAudio,
    DoorClosingAlarm), 4, 0, 0 },

  { "DoorEmergencyReleased", rt_offsetof(BD_DoorSystem_Int_DoorControlAudio,
    DoorEmergencyReleased), 4, 0, 0 },

  { "DoorIsolated", rt_offsetof(BD_DoorSystem_Int_DoorControlAudio, DoorIsolated),
    4, 0, 0 },

  { "DoorOutsideLamp", rt_offsetof(BD_DoorSystem_Int_DoorControlIndicators,
    DoorOutsideLamp), 4, 0, 0 },

  { "DoorInsideLamp", rt_offsetof(BD_DoorSystem_Int_DoorControlIndicators,
    DoorInsideLamp), 4, 0, 0 },

  { "DoorOpenPBLight", rt_offsetof(BD_DoorSystem_Int_DoorControlIndicators,
    DoorOpenPBLight), 4, 0, 0 },

  { "DoorClosePBLight", rt_offsetof(BD_DoorSystem_Int_DoorControlIndicators,
    DoorClosePBLight), 4, 0, 0 },

  { "DoorsFaulty", rt_offsetof(BD_DoorSystem_Int_DoorControlIndicators,
    DoorsFaulty), 0, 0, 0 },

  { "DCUTCMSMessages", rt_offsetof(BD_DoorSystem_Int_DoorControlIndicators,
    DCUTCMSMessages), 7, 0, 0 }
};

/* Dimension Map - use dimensionMapIndex to access elements of ths structure*/
static rtwCAPI_DimensionMap rtDimensionMap[] = {
  /* dataOrientation, dimArrayIndex, numDims, vardimsIndex */
  { rtwCAPI_SCALAR, 0, 2, 0 },

  { rtwCAPI_VECTOR, 2, 2, 0 },

  { rtwCAPI_VECTOR, 4, 2, 0 },

  { rtwCAPI_VECTOR, 6, 2, 0 },

  { rtwCAPI_VECTOR, 8, 2, 0 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static uint_T rtDimensionArray[] = {
  1,                                   /* 0 */
  1,                                   /* 1 */
  8,                                   /* 2 */
  1,                                   /* 3 */
  16,                                  /* 4 */
  1,                                   /* 5 */
  2,                                   /* 6 */
  1,                                   /* 7 */
  1,                                   /* 8 */
  8                                    /* 9 */
};

/* C-API stores floating point values in an array. The elements of this  *
 * are unique. This ensures that values which are shared across the model*
 * are stored in the most efficient way. These values are referenced by  *
 *           - rtwCAPI_FixPtMap.fracSlopePtr,                            *
 *           - rtwCAPI_FixPtMap.biasPtr,                                 *
 *           - rtwCAPI_SampleTimeMap.samplePeriodPtr,                    *
 *           - rtwCAPI_SampleTimeMap.sampleOffsetPtr                     */
static const real_T rtcapiStoredFloats[] = {
  0.05, 0.0, 1.0
};

/* Fixed Point Map */
static rtwCAPI_FixPtMap rtFixPtMap[] = {
  /* fracSlopePtr, biasPtr, scaleType, wordLength, exponent, isSigned */
  { (NULL), (NULL), rtwCAPI_FIX_RESERVED, 0, 0, 0 },

  { static_cast<const void *>(&rtcapiStoredFloats[2]), static_cast<const void *>
    (&rtcapiStoredFloats[1]), rtwCAPI_FIX_UNIFORM_SCALING, 8, -7, 1 }
};

/* Sample Time Map - use sTimeIndex to access elements of ths structure */
static rtwCAPI_SampleTimeMap rtSampleTimeMap[] = {
  /* samplePeriodPtr, sampleOffsetPtr, tid, samplingMode */
  { static_cast<const void *>(&rtcapiStoredFloats[0]), static_cast<const void *>
    (&rtcapiStoredFloats[1]), 0, 0 }
};

static rtwCAPI_ModelMappingStaticInfo mmiStatic = {
  /* Signals:{signals, numSignals,
   *           rootInputs, numRootInputs,
   *           rootOutputs, numRootOutputs},
   * Params: {blockParameters, numBlockParameters,
   *          modelParameters, numModelParameters},
   * States: {states, numStates},
   * Maps:   {dataTypeMap, dimensionMap, fixPtMap,
   *          elementMap, sampleTimeMap, dimensionArray},
   * TargetType: targetType
   */
  { rtBlockSignals, 39,
    (NULL), 0,
    (NULL), 0 },

  { rtBlockParameters, 197,
    rtModelParameters, 0 },

  { rtBlockStates, 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float",

  { 4229140647U,
    4282927299U,
    2943203723U,
    3427087672U },
  (NULL), 0,
  0
};

/* Function to get C API Model Mapping Static Info */
const rtwCAPI_ModelMappingStaticInfo*
  DoorSystem_GetCAPIStaticMap(void)
{
  return &mmiStatic;
}

/* Cache pointers into DataMapInfo substructure of RTModel */
#ifndef HOST_CAPI_BUILD

void DoorSystem_InitializeDataMapInfo(RT_MODEL_DoorSystem_T *const DoorSystem_M,
  B_DoorSystem_c_T *localB)
{
  /* Set C-API version */
  rtwCAPI_SetVersion(DoorSystem_M->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(DoorSystem_M->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(DoorSystem_M->DataMapInfo.mmi, (NULL));

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  DoorSystem_InitializeDataAddr(DoorSystem_M->DataMapInfo.dataAddress, localB);
  rtwCAPI_SetDataAddressMap(DoorSystem_M->DataMapInfo.mmi,
    DoorSystem_M->DataMapInfo.dataAddress);

  /* Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure */
  DoorSystem_InitializeVarDimsAddr(DoorSystem_M->DataMapInfo.vardimsAddress);
  rtwCAPI_SetVarDimsAddressMap(DoorSystem_M->DataMapInfo.mmi,
    DoorSystem_M->DataMapInfo.vardimsAddress);

  /* Set Instance specific path */
  rtwCAPI_SetPath(DoorSystem_M->DataMapInfo.mmi, (NULL));
  rtwCAPI_SetFullPath(DoorSystem_M->DataMapInfo.mmi, (NULL));

  /* Cache C-API logging function pointers into the Real-Time Model Data structure */
  DoorSystem_InitializeLoggingFunctions(DoorSystem_M->DataMapInfo.loggingPtrs);
  rtwCAPI_SetLoggingPtrs(DoorSystem_M->DataMapInfo.mmi,
    DoorSystem_M->DataMapInfo.loggingPtrs);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(DoorSystem_M->DataMapInfo.mmi, (NULL));

  /* Set reference to submodels */
  rtwCAPI_SetChildMMIArray(DoorSystem_M->DataMapInfo.mmi, (NULL));
  rtwCAPI_SetChildMMIArrayLen(DoorSystem_M->DataMapInfo.mmi, 0);
}

#else                                  /* HOST_CAPI_BUILD */
#ifdef __cplusplus

extern "C" {

#endif

  void DoorSystem_host_InitializeDataMapInfo(DoorSystem_host_DataMapInfo_T
    *dataMap, const char *path)
  {
    /* Set C-API version */
    rtwCAPI_SetVersion(dataMap->mmi, 1);

    /* Cache static C-API data into the Real-time Model Data structure */
    rtwCAPI_SetStaticMap(dataMap->mmi, &mmiStatic);

    /* host data address map is NULL */
    rtwCAPI_SetDataAddressMap(dataMap->mmi, NULL);

    /* host vardims address map is NULL */
    rtwCAPI_SetVarDimsAddressMap(dataMap->mmi, NULL);

    /* Set Instance specific path */
    rtwCAPI_SetPath(dataMap->mmi, path);
    rtwCAPI_SetFullPath(dataMap->mmi, NULL);

    /* Set reference to submodels */
    rtwCAPI_SetChildMMIArray(dataMap->mmi, (NULL));
    rtwCAPI_SetChildMMIArrayLen(dataMap->mmi, 0);
  }

#ifdef __cplusplus

}
#endif
#endif                                 /* HOST_CAPI_BUILD */

/* EOF: DoorSystem_capi.cpp */
