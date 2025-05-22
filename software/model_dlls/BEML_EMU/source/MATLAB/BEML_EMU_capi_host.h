#ifndef RTW_HEADER_BEML_EMU_cap_host_h_
#define RTW_HEADER_BEML_EMU_cap_host_h_
#ifdef HOST_CAPI_BUILD
#include "rtw_capi.h"
#include "rtw_modelmap.h"
#include "TrainBrakes_capi_host.h"
#include "CouplingSystem_capi_host.h"
#include "DoorSystem_capi_host.h"
#include "TrainDynamics_capi_host.h"
#include "ElectricalSystem_capi_host.h"
#include "PantographSystem_capi_host.h"
#include "PneumaticsSystem_capi_host.h"
#include "TCMSSystem_capi_host.h"
#include "TractionSystem_capi_host.h"
#include "IOControls_capi_host.h"

typedef struct {
  rtwCAPI_ModelMappingInfo mmi;
  rtwCAPI_ModelMappingInfo *childMMI[10];
  TrainBrakes_host_DataMapInfo_T child0;
  CouplingSystem_host_DataMapInfo_T child1;
  DoorSystem_host_DataMapInfo_T child2;
  TrainDynamics_host_DataMapInfo_T child3;
  ElectricalSystem_host_DataMapInfo_T child4;
  PantographSystem_host_DataMapInfo_T child5;
  PneumaticsSystem_host_DataMapInfo_T child6;
  TCMSSystem_host_DataMapInfo_T child7;
  TractionSystem_host_DataMapInfo_T child8;
  IOControls_host_DataMapInfo_T child9;
} BEML_EMU_host_DataMapInfo_T;

#ifdef __cplusplus

extern "C" {

#endif

  void BEML_EMU_host_InitializeDataMapInfo(BEML_EMU_host_DataMapInfo_T *dataMap,
    const char *path);

#ifdef __cplusplus

}
#endif
#endif                                 /* HOST_CAPI_BUILD */
#endif                                 /* RTW_HEADER_BEML_EMU_cap_host_h_ */

/* EOF: BEML_EMU_capi_host.h */
