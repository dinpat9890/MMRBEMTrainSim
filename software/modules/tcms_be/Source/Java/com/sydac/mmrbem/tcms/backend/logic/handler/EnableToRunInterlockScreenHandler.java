/*
 * ==================================================================
 * (C)Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.backend.logic.handler;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

import org.springframework.stereotype.Service;

import com.sydac.foundation.IModelListener;
import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.backend.comms.CommsBinding;
import com.sydac.mmrbem.tcms.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.tcms.backend.logic.SharedDataModel;
import com.sydac.mmrbem.tcms.backend.logic.SharedDataModel.Change;
import com.sydac.mmrbem.tcms.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsEnableToRunInterlockScreenProperties;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsOperatingScreenProperties;
import com.sydac.mmrbem.tcms.common.data.EBInterlockStatusDO;
import com.sydac.mmrbem.tcms.common.data.EnableToRunInterlockStatusDO;
import com.sydac.mmrbem.tcms.common.data.Entry;
import com.sydac.mmrbem.tcms.common.data.VehicleDetailModel;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsEnableToRunScreenProperties;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.EnableToRunList.ERState;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;

/**
 * This handler class is used for handling Enable To Run Interlock Screen data
 * 
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class, SharedDataModel.class })
public class EnableToRunInterlockScreenHandler extends AbstractFunctionalLogic
{
  private SharedDataModel sharedModel;

  private List<VehicleDetailModel> vehicleDetailModelList;

  private List<Entry<EnableToRunInterlockStatusDO>> erStatusDetails = new ArrayList<>();

  /**
   * Listener to update vehicleDetailModelList
   */
  IModelListener trainConfigListener = (arg0, arg1) -> {
    vehicleDetailModelList = sharedModel.getVehicleDetailModelList();

    // Write the initial state of VCB status
    if (!vehicleDetailModelList.isEmpty())
    {
      setEnableToRunStatus();
    }
  };

  protected EnableToRunInterlockScreenHandler(CommsBinding commsBinding, SharedDataModel aSharedModel)
  {
    super(commsBinding, ITCMSVehicleOutputsEnableToRunInterlockScreenProperties.class,
        ITCMSVehicleOutputsOperatingScreenProperties.class);
    sharedModel = aSharedModel;
  }

  /**
   * Attach listeners.
   */
  @Override
  public void attachListeners()
  {
    super.attachListeners();
    sharedModel.addModelListener(trainConfigListener, Change.TRAIN_CONFIGURED, true);
  }

  /**
   * Detach listeners.
   */
  @Override
  public void detachListeners()
  {
    super.detachListeners();
    sharedModel.removeModelListener(trainConfigListener, Change.TRAIN_CONFIGURED);
  }

  @Override
  public <T> void tcmsVehicleOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue,
      int vehicleIndex)
  {
  
    if (ITCMSVehicleOutputsEnableToRunInterlockScreenProperties.HIGH_VOLTAGE_MISSING.equals(key))
    {
      EnableToRunInterlockStatusDO vehicleEBDetailDO = getErDetailsForCarIndex(erStatusDetails, vehicleIndex);
      vehicleEBDetailDO.setErHighVolatgeMissingState((Integer)newValue);
      setEnableToRunInterlockDetails(erStatusDetails, vehicleEBDetailDO, vehicleIndex);
    }
    else if (ITCMSVehicleOutputsEnableToRunInterlockScreenProperties.CAB_NOT_ENABLED.equals(key))
    {
      EnableToRunInterlockStatusDO vehicleEBDetailDO = getErDetailsForCarIndex(erStatusDetails, vehicleIndex);
      vehicleEBDetailDO.setErCabNotEnabledState((Integer)newValue);
      setEnableToRunInterlockDetails(erStatusDetails, vehicleEBDetailDO, vehicleIndex);
    }
    else if (ITCMSVehicleOutputsEnableToRunInterlockScreenProperties.DRIVING_MODE_NOT_OK.equals(key))
    {
      EnableToRunInterlockStatusDO vehicleEBDetailDO = getErDetailsForCarIndex(erStatusDetails, vehicleIndex);
      vehicleEBDetailDO.setErDrivingModeNotOkState((Integer)newValue);
      setEnableToRunInterlockDetails(erStatusDetails, vehicleEBDetailDO, vehicleIndex);
    }
    else if (ITCMSVehicleOutputsEnableToRunInterlockScreenProperties.TRAIN_DIRECTION_MISSING.equals(key))
    {
      EnableToRunInterlockStatusDO vehicleEBDetailDO = getErDetailsForCarIndex(erStatusDetails, vehicleIndex);
      vehicleEBDetailDO.setErTrainDirectionMissingState((Integer)newValue);
      setEnableToRunInterlockDetails(erStatusDetails, vehicleEBDetailDO, vehicleIndex);
    }
    else if (ITCMSVehicleOutputsEnableToRunInterlockScreenProperties.ATC_STATUS_NOT_OK.equals(key))
    {
      EnableToRunInterlockStatusDO vehicleEBDetailDO = getErDetailsForCarIndex(erStatusDetails, vehicleIndex);
      vehicleEBDetailDO.setErAtcStatusState((Integer)newValue);
      setEnableToRunInterlockDetails(erStatusDetails, vehicleEBDetailDO, vehicleIndex);
    }
    else if (ITCMSVehicleOutputsEnableToRunInterlockScreenProperties.TRAIN_READY_NOT_OK.equals(key))
    {
      EnableToRunInterlockStatusDO vehicleEBDetailDO = getErDetailsForCarIndex(erStatusDetails, vehicleIndex);
      vehicleEBDetailDO.setErTrainReadyState((Integer)newValue);
      setEnableToRunInterlockDetails(erStatusDetails, vehicleEBDetailDO, vehicleIndex);
    }
    else if (ITCMSVehicleOutputsEnableToRunInterlockScreenProperties.TOO_MANY_R_PRESSURE_CUTOUT.equals(key))
    {
      EnableToRunInterlockStatusDO vehicleEBDetailDO = getErDetailsForCarIndex(erStatusDetails, vehicleIndex);
      vehicleEBDetailDO.setErManyRPressureState((Integer)newValue);
      setEnableToRunInterlockDetails(erStatusDetails, vehicleEBDetailDO, vehicleIndex);
    }
    else if (ITCMSVehicleOutputsEnableToRunInterlockScreenProperties.TOO_MANY_EPIC_CUTOUT.equals(key))
    {
      EnableToRunInterlockStatusDO vehicleEBDetailDO = getErDetailsForCarIndex(erStatusDetails, vehicleIndex);
      vehicleEBDetailDO.setErManyEpicCutoutState((Integer)newValue);
      setEnableToRunInterlockDetails(erStatusDetails, vehicleEBDetailDO, vehicleIndex);
    }
    else if (ITCMSVehicleOutputsEnableToRunInterlockScreenProperties.TOO_MANY_BOGIE_ISOLATED.equals(key)
        && vehicleIndex == sharedModel.getCurrentActiveCabId())
    {
      EnableToRunInterlockStatusDO vehicleEBDetailDO = getErDetailsForCarIndex(erStatusDetails, vehicleIndex);
      vehicleEBDetailDO.setErManyBogieIsolatedState((Integer)newValue);
      setEnableToRunInterlockDetails(erStatusDetails, vehicleEBDetailDO, vehicleIndex);
    }
    else if (ITCMSVehicleOutputsEnableToRunInterlockScreenProperties.ZVRD_NOT_ACTIVE.equals(key)
       )
    {
      EnableToRunInterlockStatusDO vehicleEBDetailDO = getErDetailsForCarIndex(erStatusDetails, vehicleIndex);
      vehicleEBDetailDO.setErZvrdState((Integer)newValue);
      setEnableToRunInterlockDetails(erStatusDetails, vehicleEBDetailDO, vehicleIndex);
    }else if (ITCMSVehicleOutputsEnableToRunInterlockScreenProperties.MOTORING_TL_DEENERGIZED.equals(key)
        && vehicleIndex == sharedModel.getCurrentActiveCabId())
    {
      EnableToRunInterlockStatusDO vehicleEBDetailDO = getErDetailsForCarIndex(erStatusDetails, vehicleIndex);
      vehicleEBDetailDO.setErMotoringTlState((Integer)newValue);
      setEnableToRunInterlockDetails(erStatusDetails, vehicleEBDetailDO, vehicleIndex);
    }else if (ITCMSVehicleOutputsEnableToRunInterlockScreenProperties.BRAKE_LOOP_OPEN_TL.equals(key)
        && vehicleIndex == sharedModel.getCurrentActiveCabId())
    {
      EnableToRunInterlockStatusDO vehicleEBDetailDO = getErDetailsForCarIndex(erStatusDetails, vehicleIndex);
      vehicleEBDetailDO.setErBrakeLoopTlState((Integer)newValue);
      setEnableToRunInterlockDetails(erStatusDetails, vehicleEBDetailDO, vehicleIndex);
    }else if (ITCMSVehicleOutputsEnableToRunInterlockScreenProperties.PARKING_BRAKE_ACTIVE_TL.equals(key)
        && vehicleIndex == sharedModel.getCurrentActiveCabId())
    {
      EnableToRunInterlockStatusDO vehicleEBDetailDO = getErDetailsForCarIndex(erStatusDetails, vehicleIndex);
      vehicleEBDetailDO.setErParkingBrakeTlState((Integer)newValue);
      setEnableToRunInterlockDetails(erStatusDetails, vehicleEBDetailDO, vehicleIndex);
    }else if (ITCMSVehicleOutputsEnableToRunInterlockScreenProperties.DOOR_LOOP_OPEN_TL.equals(key)
        && vehicleIndex == sharedModel.getCurrentActiveCabId())
    {
      EnableToRunInterlockStatusDO vehicleEBDetailDO = getErDetailsForCarIndex(erStatusDetails, vehicleIndex);
      vehicleEBDetailDO.setErDoorLoopOpenTlState((Integer)newValue);
      setEnableToRunInterlockDetails(erStatusDetails, vehicleEBDetailDO, vehicleIndex);
    }
  }

  private void setEnableToRunInterlockDetails(List<Entry<EnableToRunInterlockStatusDO>> ebStatusDetailsList,
      EnableToRunInterlockStatusDO vehicleEBDetailDO, int carIndex)
  {
    if (ebStatusDetailsList.stream().anyMatch(entry -> entry.getIndex() == carIndex))
    {
      ebStatusDetailsList.stream().filter(entry -> entry.getIndex() == carIndex)
          .forEach(entry -> entry.setData(vehicleEBDetailDO));
    }
    else
    {
      ebStatusDetailsList.add(new Entry<>(carIndex, vehicleEBDetailDO));
      Collections.sort(ebStatusDetailsList);
    }

    // Set Enable to run status data in COMMS
    setEnableToRunStatus();
  }

  private void setEnableToRunStatus()
  {
    setApplicationOutputsProperty(IAppOutputsEnableToRunScreenProperties.ENABLE_RUN_INTERLOCK_STATUS,
        getRawForErStatus(erStatusDetails));
  }

  private byte[] getRawForErStatus(List<Entry<EnableToRunInterlockStatusDO>> ebStatusDetails)
  {
    TCMSProto.EnableToRunList.Builder builder = TCMSProto.EnableToRunList.newBuilder();
    TCMSProto.EnableToRunList.EnableToRunStatus.Builder vehicleBuilder = TCMSProto.EnableToRunList.EnableToRunStatus
        .newBuilder();
    for (int index = 0; index < ebStatusDetails.size(); index++)
    {
      int carIndex = ebStatusDetails.get(index).getIndex();
      vehicleBuilder.setCarIndex(carIndex);
      EnableToRunInterlockStatusDO ebDetailDO = ebStatusDetails.get(index).getData();
      String carClassCode = vehicleDetailModelList != null
          ? vehicleDetailModelList.get(carIndex).getCarClassCode()
          : ApplicationConstants.BLANK;

      if (TCMSConstants.DM_CAR.equals(carClassCode))
      {
        vehicleBuilder.setErHighVolatgeMissing(
            ebDetailDO.getErHighVolatgeMissingState() == ERState.ACTIVE_VALUE ? ERState.ACTIVE
                : ERState.NOT_ACTIVE);

        vehicleBuilder
            .setErCabNotEnabled(ebDetailDO.getErCabNotEnabledState() == ERState.ACTIVE_VALUE ? ERState.ACTIVE
                : ERState.NOT_ACTIVE);

        vehicleBuilder.setErDrivingModeNotOk(
            ebDetailDO.getErDrivingModeNotOkState() == ERState.ACTIVE_VALUE ? ERState.ACTIVE
                : ERState.NOT_ACTIVE);
        vehicleBuilder.setErTrainDirectionMissing(
            ebDetailDO.getErTrainDirectionMissingState() == ERState.ACTIVE_VALUE ? ERState.ACTIVE
                : ERState.NOT_ACTIVE);
        vehicleBuilder.setErAtcStatus(
            ebDetailDO.getErAtcStatusState() == ERState.ACTIVE_VALUE ? ERState.ACTIVE : ERState.NOT_ACTIVE);
        vehicleBuilder.setErTrainReady(
            ebDetailDO.getErTrainReadyState() == ERState.ACTIVE_VALUE ? ERState.ACTIVE : ERState.NOT_ACTIVE);

        vehicleBuilder
            .setErManyRPressure(ebDetailDO.getErManyRPressureState() == ERState.ACTIVE_VALUE ? ERState.ACTIVE
                : ERState.NOT_ACTIVE);
        vehicleBuilder.setErManyEpicCutout(
            ebDetailDO.getErManyEpicCutoutState() == ERState.ACTIVE_VALUE ? ERState.ACTIVE
                : ERState.NOT_ACTIVE);

        vehicleBuilder.setErManyBogieIsolated(
            ebDetailDO.getErManyBogieIsolatedState() == ERState.ACTIVE_VALUE ? ERState.ACTIVE
                : ERState.NOT_ACTIVE);
        
        vehicleBuilder.setErMotoringTl(
            ebDetailDO.getErMotoringTlState() == ERState.ACTIVE_VALUE ? ERState.ACTIVE
                : ERState.NOT_ACTIVE);
        
        
        vehicleBuilder.setErBrakeLoopTl(
            ebDetailDO.getErBrakeLoopTlState() == ERState.ACTIVE_VALUE ? ERState.ACTIVE
                : ERState.NOT_ACTIVE);
        
        vehicleBuilder.setErParkingBrakeTl(
            ebDetailDO.getErParkingBrakeTlState() == ERState.ACTIVE_VALUE ? ERState.ACTIVE
                : ERState.NOT_ACTIVE);
        
        vehicleBuilder.setErDoorLoopOpenTl(
            ebDetailDO.getErDoorLoopOpenTlState() == ERState.ACTIVE_VALUE ? ERState.ACTIVE
                : ERState.NOT_ACTIVE);
        vehicleBuilder.setErZvrdNotActive(
            ebDetailDO.getErZvrdState() == ERState.ACTIVE_VALUE ? ERState.ACTIVE
                : ERState.NOT_ACTIVE);

      }
      else
      {
        
        vehicleBuilder.setErHighVolatgeMissing(ERState.ACTIVE);
        vehicleBuilder.setErCabNotEnabled(ERState.ACTIVE);
        vehicleBuilder.setErDrivingModeNotOk(ERState.ACTIVE);
        vehicleBuilder.setErTrainDirectionMissing(ERState.ACTIVE);
        vehicleBuilder.setErAtcStatus(ERState.ACTIVE);
        vehicleBuilder.setErTrainReady(ERState.ACTIVE);
        vehicleBuilder.setErManyRPressure(ERState.ACTIVE);
        vehicleBuilder.setErManyEpicCutout(ERState.ACTIVE);
        vehicleBuilder.setErManyBogieIsolated(ERState.ACTIVE);
        vehicleBuilder.setErMotoringTl(ERState.ACTIVE);
        vehicleBuilder.setErBrakeLoopTl(ERState.ACTIVE);
        vehicleBuilder.setErParkingBrakeTl(ERState.ACTIVE);
        vehicleBuilder.setErDoorLoopOpenTl(ERState.ACTIVE);
        vehicleBuilder.setErZvrdNotActive(ERState.ACTIVE);
      }
      builder.addEnableToRunStatus(vehicleBuilder);
    }
    return builder.build().toByteArray();
  }

  /**
   * Gets the existing VCBInterlockStatusDO for the car index or creates new
   * from then given list.
   *
   * @param EBInterlockStatus
   *          List of {@link EBInterlockStatusDO}
   * @param carIndex
   *          the car index
   * @return {@link EBInterlockStatusDO} for given car index
   */
  private EnableToRunInterlockStatusDO getErDetailsForCarIndex(
      List<Entry<EnableToRunInterlockStatusDO>> pantoDetails, int carIndex)
  {
    return pantoDetails.stream().filter(entry -> entry.getIndex() == carIndex).findFirst().map(Entry::getData)
        .orElse(new EnableToRunInterlockStatusDO());
  }
}
