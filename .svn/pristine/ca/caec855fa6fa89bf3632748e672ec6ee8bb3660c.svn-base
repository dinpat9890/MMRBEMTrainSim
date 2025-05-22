/*
 * PantographSystem_capi.cpp
 *
 * Code generation for model "PantographSystem".
 *
 * Model version              : 1.936
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
#include "PantographSystem_capi_host.h"
#define sizeof(s)                      ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el)              ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s)               (s)
#else                                  /* HOST_CAPI_BUILD */
#include "builtin_typeid_types.h"
#include "PantographSystem.h"
#include "PantographSystem_capi.h"
#include "PantographSystem_private.h"
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
  { 0, 20, TARGET_STRING(
    "PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle"),
    TARGET_STRING(""), 0, 4, 0, 0, 0 },

  { 1, 20, TARGET_STRING(
    "PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/OutputsPacking/Bus Assignment"),
    TARGET_STRING(""), 0, 4, 0, 0, 0 },

  {
    0, 0, (NULL), (NULL), 0, 0, 0, 0, 0
  }
};

static rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  { 2, TARGET_STRING("PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/PantographSystemVehicleOutputs"),
    TARGET_STRING("InitialOutput"), 4, 0, 0 },

  { 3, TARGET_STRING("PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/Unit Delay"),
    TARGET_STRING("InitialCondition"), 1, 0, 0 },

  { 4, TARGET_STRING("PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/Unit Delay1"),
    TARGET_STRING("InitialCondition"), 1, 0, 0 },

  { 5, TARGET_STRING("PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/Unit Delay2"),
    TARGET_STRING("InitialCondition"), 1, 0, 0 },

  { 6, TARGET_STRING("PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/Unit Delay3"),
    TARGET_STRING("InitialCondition"), 1, 0, 0 },

  { 7, TARGET_STRING("PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/FaultProcessingandVoltageDetection/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 8, TARGET_STRING("PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/FaultProcessingandVoltageDetection/Dummy"),
    TARGET_STRING("Gain"), 5, 0, 1 },

  { 9, TARGET_STRING("PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/FaultProcessingandVoltageDetection/Dummy1"),
    TARGET_STRING("Gain"), 5, 0, 1 },

  { 10, TARGET_STRING("PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/FaultProcessingandVoltageDetection/Dummy2"),
    TARGET_STRING("Gain"), 5, 0, 1 },

  { 11, TARGET_STRING("PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/OutputsPacking/Constant3"),
    TARGET_STRING("Value"), 4, 0, 0 },

  { 12, TARGET_STRING("PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/PantoActuationAndSwitches/Detect Decrease"),
    TARGET_STRING("vinit"), 0, 0, 0 },

  { 13, TARGET_STRING("PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/PantoActuationAndSwitches/SR Latch - Reset Priority"),
    TARGET_STRING("initial_condition"), 1, 0, 0 },

  { 14, TARGET_STRING("PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/PantoActuationAndSwitches/Constant"),
    TARGET_STRING("Value"), 1, 0, 0 },

  { 15, TARGET_STRING("PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/PantoActuationAndSwitches/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 16, TARGET_STRING("PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/PantoActuationAndSwitches/Constant2"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 17, TARGET_STRING("PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/PantoActuationAndSwitches/Constant3"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 18, TARGET_STRING("PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/PantoActuationAndSwitches/Constant5"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 19, TARGET_STRING("PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/PantoActuationAndSwitches/Unit Delay"),
    TARGET_STRING("InitialCondition"), 1, 0, 0 },

  { 20, TARGET_STRING("PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/PantoActuationAndSwitches/Discrete Dynamic Limited Integrator1/IC"),
    TARGET_STRING("Value"), 1, 0, 0 },

  { 21, TARGET_STRING("PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/PantoActuationAndSwitches/Discrete Dynamic Limited Integrator1/Unit Delay1"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 22, TARGET_STRING("PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/PantoActuationAndSwitches/Discrete Dynamic Limited Integrator1/Weighted Sample Time"),
    TARGET_STRING("WtEt"), 0, 0, 0 },

  { 23, TARGET_STRING("PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/PantoActuationAndSwitches/PantoActuation/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 24, TARGET_STRING("PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/PantoActuationAndSwitches/PantoActuation/OnlyGoesDOWN"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 25, TARGET_STRING("PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/PantoActuationAndSwitches/PantoActuation/Speed"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 26, TARGET_STRING("PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/PantoActuationAndSwitches/PantoSwitches/Compare To Constant1"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 27, TARGET_STRING("PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/PantoActuationAndSwitches/PantoSwitches/Compare To Constant2"),
    TARGET_STRING("const"), 0, 0, 0 },

  { 28, TARGET_STRING("PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/PantoActuationAndSwitches/PantoSwitches/Detect Decrease"),
    TARGET_STRING("vinit"), 0, 0, 0 },

  { 29, TARGET_STRING("PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/PantoActuationAndSwitches/PantoSwitches/Detect Increase"),
    TARGET_STRING("vinit"), 0, 0, 0 },

  { 30, TARGET_STRING("PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/PantoControlUnit/PantoDOWNCommand/SR Latch - Reset Priority1"),
    TARGET_STRING("initial_condition"), 1, 0, 0 },

  { 31, TARGET_STRING("PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/PantoControlUnit/PantoEMERCommand/SR Latch - Reset Priority2"),
    TARGET_STRING("initial_condition"), 1, 0, 0 },

  { 32, TARGET_STRING("PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/PantoControlUnit/PantoUPCommand/SR Latch - Reset Priority"),
    TARGET_STRING("initial_condition"), 1, 0, 0 },

  { 33, TARGET_STRING("PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/PantoSystemSupply/NoPantoSupply/Constant"),
    TARGET_STRING("Value"), 1, 0, 0 },

  { 34, TARGET_STRING("PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/PantoControlUnit/PantoCommandLogic/DOWN/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 35, TARGET_STRING("PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/PantoControlUnit/PantoCommandLogic/NoPantoCommand/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 36, TARGET_STRING("PantographSystem/PantographSystemPerVehicle/EnabledPantoVehicle/PantoControlUnit/PantoCommandLogic/UP/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

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
static void PantographSystem_InitializeDataAddr(void* dataAddr[],
  B_PantographSystem_c_T *localB)
{
  dataAddr[0] = (void*) (&localB->CoreSubsys[7].BusAssignment);
  dataAddr[1] = (void*) (&localB->CoreSubsys[7].BusAssignment);
  dataAddr[2] = (void*)
    (&PantographSystem_P.CoreSubsys.PantographSystemVehicleOutputs_Y0);
  dataAddr[3] = (void*)
    (&PantographSystem_P.CoreSubsys.UnitDelay_InitialCondition);
  dataAddr[4] = (void*)
    (&PantographSystem_P.CoreSubsys.UnitDelay1_InitialCondition_e);
  dataAddr[5] = (void*)
    (&PantographSystem_P.CoreSubsys.UnitDelay2_InitialCondition);
  dataAddr[6] = (void*)
    (&PantographSystem_P.CoreSubsys.UnitDelay3_InitialCondition);
  dataAddr[7] = (void*) (&PantographSystem_P.CoreSubsys.Constant_Value);
  dataAddr[8] = (void*) (&PantographSystem_P.CoreSubsys.Dummy_Gain);
  dataAddr[9] = (void*) (&PantographSystem_P.CoreSubsys.Dummy1_Gain);
  dataAddr[10] = (void*) (&PantographSystem_P.CoreSubsys.Dummy2_Gain);
  dataAddr[11] = (void*) (&PantographSystem_P.CoreSubsys.Constant3_Value);
  dataAddr[12] = (void*) (&PantographSystem_P.CoreSubsys.DetectDecrease_vinit);
  dataAddr[13] = (void*)
    (&PantographSystem_P.CoreSubsys.SRLatchResetPriority_initial_condition);
  dataAddr[14] = (void*) (&PantographSystem_P.CoreSubsys.Constant_Value_e);
  dataAddr[15] = (void*) (&PantographSystem_P.CoreSubsys.Constant1_Value);
  dataAddr[16] = (void*) (&PantographSystem_P.CoreSubsys.Constant2_Value);
  dataAddr[17] = (void*) (&PantographSystem_P.CoreSubsys.Constant3_Value_e);
  dataAddr[18] = (void*) (&PantographSystem_P.CoreSubsys.Constant5_Value);
  dataAddr[19] = (void*)
    (&PantographSystem_P.CoreSubsys.UnitDelay_InitialCondition_e);
  dataAddr[20] = (void*) (&PantographSystem_P.CoreSubsys.IC_Value);
  dataAddr[21] = (void*)
    (&PantographSystem_P.CoreSubsys.UnitDelay1_InitialCondition);
  dataAddr[22] = (void*) (&PantographSystem_P.CoreSubsys.WeightedSampleTime_WtEt);
  dataAddr[23] = (void*) (&PantographSystem_P.CoreSubsys.Constant_Value_g);
  dataAddr[24] = (void*) (&PantographSystem_P.CoreSubsys.OnlyGoesDOWN_Gain);
  dataAddr[25] = (void*) (&PantographSystem_P.CoreSubsys.Speed_Threshold);
  dataAddr[26] = (void*)
    (&PantographSystem_P.CoreSubsys.CompareToConstant1_const);
  dataAddr[27] = (void*)
    (&PantographSystem_P.CoreSubsys.CompareToConstant2_const);
  dataAddr[28] = (void*) (&PantographSystem_P.CoreSubsys.DetectDecrease_vinit_a);
  dataAddr[29] = (void*) (&PantographSystem_P.CoreSubsys.DetectIncrease_vinit);
  dataAddr[30] = (void*)
    (&PantographSystem_P.CoreSubsys.SRLatchResetPriority1_initial_condition);
  dataAddr[31] = (void*)
    (&PantographSystem_P.CoreSubsys.SRLatchResetPriority2_initial_condition);
  dataAddr[32] = (void*)
    (&PantographSystem_P.CoreSubsys.SRLatchResetPriority_initial_condition_h);
  dataAddr[33] = (void*) (&PantographSystem_P.CoreSubsys.Constant_Value_o);
  dataAddr[34] = (void*) (&PantographSystem_P.CoreSubsys.DOWN.Constant_Value);
  dataAddr[35] = (void*)
    (&PantographSystem_P.CoreSubsys.NoPantoCommand.Constant_Value);
  dataAddr[36] = (void*) (&PantographSystem_P.CoreSubsys.UP.Constant_Value);
}

#endif

/* Initialize Data Run-Time Dimension Buffer Address */
#ifndef HOST_CAPI_BUILD

static void PantographSystem_InitializeVarDimsAddr(int32_T* vardimsAddr[])
{
  vardimsAddr[0] = (NULL);
}

#endif

#ifndef HOST_CAPI_BUILD

/* Initialize logging function pointers */
static void PantographSystem_InitializeLoggingFunctions(RTWLoggingFcnPtr
  loggingPtrs[])
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
}

#endif

/* Data Type Map - use dataTypeMapIndex to access this structure */
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, *
   * isComplex, isPointer, enumStorageType */
  { "double", "real_T", 0, 0, sizeof(real_T), SS_DOUBLE, 0, 0, 0 },

  { "unsigned char", "boolean_T", 0, 0, sizeof(boolean_T), SS_BOOLEAN, 0, 0, 0 },

  { "struct", "BD_PantographSystem_Out_Vehicle_TCMS_Messages", 3, 1, sizeof
    (BD_PantographSystem_Out_Vehicle_TCMS_Messages), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_PantographSystem_Out_Vehicle_TCMS", 1, 4, sizeof
    (BD_PantographSystem_Out_Vehicle_TCMS), SS_STRUCT, 0, 0, 0 },

  { "struct", "BD_PantographSystem_Out_Vehicle", 10, 5, sizeof
    (BD_PantographSystem_Out_Vehicle), SS_STRUCT, 0, 0, 0 },

  { "unsigned char", "uint8_T", 0, 0, sizeof(uint8_T), SS_UINT8, 0, 0, 0 }
};

#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif

/* Structure Element Map - use elemMapIndex to access this structure */
static TARGET_CONST rtwCAPI_ElementMap rtElementMap[] = {
  /* elementName, elementOffset, dataTypeIndex, dimIndex, fxpIndex */
  { (NULL), 0, 0, 0, 0 },

  { "PantoADDFaultMessage", rt_offsetof
    (BD_PantographSystem_Out_Vehicle_TCMS_Messages, PantoADDFaultMessage), 1, 0,
    0 },

  { "PantoORDFaultMessage", rt_offsetof
    (BD_PantographSystem_Out_Vehicle_TCMS_Messages, PantoORDFaultMessage), 1, 0,
    0 },

  { "PantoRaiseFailureMessage", rt_offsetof
    (BD_PantographSystem_Out_Vehicle_TCMS_Messages, PantoRaiseFailureMessage), 1,
    0, 0 },

  { "Messages", rt_offsetof(BD_PantographSystem_Out_Vehicle_TCMS, Messages), 2,
    0, 0 },

  { "PantographPosition", rt_offsetof(BD_PantographSystem_Out_Vehicle,
    PantographPosition), 0, 0, 0 },

  { "PantoUpStatus", rt_offsetof(BD_PantographSystem_Out_Vehicle, PantoUpStatus),
    1, 0, 0 },

  { "PantoDownStatus", rt_offsetof(BD_PantographSystem_Out_Vehicle,
    PantoDownStatus), 1, 0, 0 },

  { "PantoIsolatedStatus", rt_offsetof(BD_PantographSystem_Out_Vehicle,
    PantoIsolatedStatus), 1, 0, 0 },

  { "PantoRising", rt_offsetof(BD_PantographSystem_Out_Vehicle, PantoRising), 1,
    0, 0 },

  { "PantoLowering", rt_offsetof(BD_PantographSystem_Out_Vehicle, PantoLowering),
    1, 0, 0 },

  { "DetectedLineVoltage", rt_offsetof(BD_PantographSystem_Out_Vehicle,
    DetectedLineVoltage), 0, 0, 0 },

  { "NoOverheadLineDetected", rt_offsetof(BD_PantographSystem_Out_Vehicle,
    NoOverheadLineDetected), 1, 0, 0 },

  { "PantographFault", rt_offsetof(BD_PantographSystem_Out_Vehicle,
    PantographFault), 1, 0, 0 },

  { "TCMS", rt_offsetof(BD_PantographSystem_Out_Vehicle, TCMS), 3, 0, 0 }
};

/* Dimension Map - use dimensionMapIndex to access elements of ths structure*/
static rtwCAPI_DimensionMap rtDimensionMap[] = {
  /* dataOrientation, dimArrayIndex, numDims, vardimsIndex */
  { rtwCAPI_SCALAR, 0, 2, 0 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static uint_T rtDimensionArray[] = {
  1,                                   /* 0 */
  1                                    /* 1 */
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
    (&rtcapiStoredFloats[1]), rtwCAPI_FIX_UNIFORM_SCALING, 8, -7, 0 }
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
  { rtBlockSignals, 2,
    (NULL), 0,
    (NULL), 0 },

  { rtBlockParameters, 35,
    rtModelParameters, 0 },

  { rtBlockStates, 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float",

  { 1883919948U,
    1601782835U,
    3255876523U,
    3315434077U },
  (NULL), 0,
  0
};

/* Function to get C API Model Mapping Static Info */
const rtwCAPI_ModelMappingStaticInfo*
  PantographSystem_GetCAPIStaticMap(void)
{
  return &mmiStatic;
}

/* Cache pointers into DataMapInfo substructure of RTModel */
#ifndef HOST_CAPI_BUILD

void PantographSystem_InitializeDataMapInfo(RT_MODEL_PantographSystem_T *const
  PantographSystem_M, B_PantographSystem_c_T *localB)
{
  /* Set C-API version */
  rtwCAPI_SetVersion(PantographSystem_M->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(PantographSystem_M->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(PantographSystem_M->DataMapInfo.mmi, (NULL));

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  PantographSystem_InitializeDataAddr
    (PantographSystem_M->DataMapInfo.dataAddress, localB);
  rtwCAPI_SetDataAddressMap(PantographSystem_M->DataMapInfo.mmi,
    PantographSystem_M->DataMapInfo.dataAddress);

  /* Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure */
  PantographSystem_InitializeVarDimsAddr
    (PantographSystem_M->DataMapInfo.vardimsAddress);
  rtwCAPI_SetVarDimsAddressMap(PantographSystem_M->DataMapInfo.mmi,
    PantographSystem_M->DataMapInfo.vardimsAddress);

  /* Set Instance specific path */
  rtwCAPI_SetPath(PantographSystem_M->DataMapInfo.mmi, (NULL));
  rtwCAPI_SetFullPath(PantographSystem_M->DataMapInfo.mmi, (NULL));

  /* Cache C-API logging function pointers into the Real-Time Model Data structure */
  PantographSystem_InitializeLoggingFunctions
    (PantographSystem_M->DataMapInfo.loggingPtrs);
  rtwCAPI_SetLoggingPtrs(PantographSystem_M->DataMapInfo.mmi,
    PantographSystem_M->DataMapInfo.loggingPtrs);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(PantographSystem_M->DataMapInfo.mmi, (NULL));

  /* Set reference to submodels */
  rtwCAPI_SetChildMMIArray(PantographSystem_M->DataMapInfo.mmi, (NULL));
  rtwCAPI_SetChildMMIArrayLen(PantographSystem_M->DataMapInfo.mmi, 0);
}

#else                                  /* HOST_CAPI_BUILD */
#ifdef __cplusplus

extern "C" {

#endif

  void PantographSystem_host_InitializeDataMapInfo
    (PantographSystem_host_DataMapInfo_T *dataMap, const char *path)
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

/* EOF: PantographSystem_capi.cpp */
