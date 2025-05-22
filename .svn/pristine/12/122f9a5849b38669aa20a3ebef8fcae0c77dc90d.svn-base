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
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsEBLoopInterlockScreenProperties;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsOperatingScreenProperties;
import com.sydac.mmrbem.tcms.common.data.EBInterlockStatusDO;
import com.sydac.mmrbem.tcms.common.data.Entry;
import com.sydac.mmrbem.tcms.common.data.VehicleDetailModel;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsEBLoopInterlockScreenProperties;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.EbInterlockData.EbState;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;

/**
 * This handler class is used for handling EB Loop Interlock Screen data
 * 
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class, SharedDataModel.class })
public class EmergencyBrakeInterlockScreenHandler extends AbstractFunctionalLogic
{
  private SharedDataModel sharedModel;

  private List<VehicleDetailModel> vehicleDetailModelList;

  private List<Entry<EBInterlockStatusDO>> ebStatusDetails = new ArrayList<>();

  /**
   * Listener to update vehicleDetailModelList
   */
  IModelListener trainConfigListener = (arg0, arg1) -> {
    vehicleDetailModelList = sharedModel.getVehicleDetailModelList();

    // Write the initial state of VCB status
    if (!vehicleDetailModelList.isEmpty())
    {
      setEmergencyBrakeStatusData();
    }
  };

  protected EmergencyBrakeInterlockScreenHandler(CommsBinding commsBinding, SharedDataModel aSharedModel)
  {
    super(commsBinding, ITCMSVehicleOutputsEBLoopInterlockScreenProperties.class,
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
    if (ITCMSVehicleOutputsEBLoopInterlockScreenProperties.EB_BY_CC.equals(key))
    {
      EBInterlockStatusDO vehicleEBDetailDO = getEbDetailsForCarIndex(ebStatusDetails, vehicleIndex);
      vehicleEBDetailDO.setEbByCcState((Integer)newValue);
      setEbInterlockDetails(ebStatusDetails, vehicleEBDetailDO, vehicleIndex);
    }
    else if (ITCMSVehicleOutputsEBLoopInterlockScreenProperties.EB_DUE_TO_PUSH_BUTTON.equals(key))
    {
      EBInterlockStatusDO vehicleEBDetailDO = getEbDetailsForCarIndex(ebStatusDetails, vehicleIndex);
      vehicleEBDetailDO.setEbByPushButtonState((Integer)newValue);
      setEbInterlockDetails(ebStatusDetails, vehicleEBDetailDO, vehicleIndex);
    }
    else if (ITCMSVehicleOutputsEBLoopInterlockScreenProperties.EB_DUE_TO_DEADMAN.equals(key))
    {
      EBInterlockStatusDO vehicleEBDetailDO = getEbDetailsForCarIndex(ebStatusDetails, vehicleIndex);
      vehicleEBDetailDO.setEbByDeadmanState((Integer)newValue);
      setEbInterlockDetails(ebStatusDetails, vehicleEBDetailDO, vehicleIndex);
    }
    else if (ITCMSVehicleOutputsEBLoopInterlockScreenProperties.EB_FOR_NON_CAB_ENABLED.equals(key))
    {
      EBInterlockStatusDO vehicleEBDetailDO = getEbDetailsForCarIndex(ebStatusDetails, vehicleIndex);
      vehicleEBDetailDO.setEbByNonCabEnabledState((Integer)newValue);
      setEbInterlockDetails(ebStatusDetails, vehicleEBDetailDO, vehicleIndex);
    }
    else if (ITCMSVehicleOutputsEBLoopInterlockScreenProperties.EB_FOR_NON_DIRECTION_SELECTED.equals(key))
    {
      EBInterlockStatusDO vehicleEBDetailDO = getEbDetailsForCarIndex(ebStatusDetails, vehicleIndex);
      vehicleEBDetailDO.setEbByNonDirectionSelectedState((Integer)newValue);
      setEbInterlockDetails(ebStatusDetails, vehicleEBDetailDO, vehicleIndex);
    }
    else if (ITCMSVehicleOutputsEBLoopInterlockScreenProperties.EB_BY_MC.equals(key))
    {
      EBInterlockStatusDO vehicleEBDetailDO = getEbDetailsForCarIndex(ebStatusDetails, vehicleIndex);
      vehicleEBDetailDO.setEbByMcState((Integer)newValue);
      setEbInterlockDetails(ebStatusDetails, vehicleEBDetailDO, vehicleIndex);
    }
    else if (ITCMSVehicleOutputsEBLoopInterlockScreenProperties.EB_BY_BRAKE_LOOP.equals(key))
    {
      EBInterlockStatusDO vehicleEBDetailDO = getEbDetailsForCarIndex(ebStatusDetails, vehicleIndex);
      vehicleEBDetailDO.setEbByBrakeLoopState((Integer)newValue);
      setEbInterlockDetails(ebStatusDetails, vehicleEBDetailDO, vehicleIndex);
    }
    else if (ITCMSVehicleOutputsEBLoopInterlockScreenProperties.EB_DUE_TO_ATC_ZERO_SPEED.equals(key))
    {
      EBInterlockStatusDO vehicleEBDetailDO = getEbDetailsForCarIndex(ebStatusDetails, vehicleIndex);
      vehicleEBDetailDO.setEbByAtcZeroSpeedState((Integer)newValue);
      setEbInterlockDetails(ebStatusDetails, vehicleEBDetailDO, vehicleIndex);
    }
    else if (ITCMSVehicleOutputsOperatingScreenProperties.TBC_POSITION.equals(key)
        && vehicleIndex == sharedModel.getCurrentActiveCabId())
    {
      EBInterlockStatusDO vehicleEBDetailDO = getEbDetailsForCarIndex(ebStatusDetails, vehicleIndex);
      vehicleEBDetailDO.setMasterControllerInFSBState((Integer)newValue);
      setEbInterlockDetails(ebStatusDetails, vehicleEBDetailDO, vehicleIndex);
    }
  }

  private void setEbInterlockDetails(List<Entry<EBInterlockStatusDO>> ebStatusDetailsList,
      EBInterlockStatusDO vehicleEBDetailDO, int carIndex)
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

    // Set EB status data in COMMS
    setEmergencyBrakeStatusData();
  }

  private void setEmergencyBrakeStatusData()
  {
    setApplicationOutputsProperty(IAppOutputsEBLoopInterlockScreenProperties.EB_INTERLOCK_STATUS,
        getRawForEbStatus(ebStatusDetails));
  }

  private byte[] getRawForEbStatus(List<Entry<EBInterlockStatusDO>> ebStatusDetails)
  {
    TCMSProto.EbInterlockData.Builder builder = TCMSProto.EbInterlockData.newBuilder();
    TCMSProto.EbInterlockData.EbInterlockStatus.Builder vehicleBuilder = TCMSProto.EbInterlockData.EbInterlockStatus
        .newBuilder();
    for (int index = 0; index < ebStatusDetails.size(); index++)
    {
      int carIndex = ebStatusDetails.get(index).getIndex();
      vehicleBuilder.setCarIndex(carIndex);
      EBInterlockStatusDO ebDetailDO = ebStatusDetails.get(index).getData();
      String carClassCode = vehicleDetailModelList != null
          ? vehicleDetailModelList.get(carIndex).getCarClassCode()
          : ApplicationConstants.BLANK;

      if (TCMSConstants.DM_CAR.equals(carClassCode))
      {
        vehicleBuilder
            .setEbByCc(ebDetailDO.getEbByCcState() == EbState.OPEN_VALUE ? EbState.OPEN : EbState.CLOSED);

        vehicleBuilder.setEbByNonCabEnabled(
            ebDetailDO.getEbByNonCabEnabledState() == EbState.OPEN_VALUE ? EbState.OPEN : EbState.CLOSED);

        vehicleBuilder.setEbByNonDirectionSelected(
            ebDetailDO.getEbByNonDirectionSelectedState() == EbState.OPEN_VALUE ? EbState.OPEN
                : EbState.CLOSED);
        vehicleBuilder
            .setEbByMc(ebDetailDO.getEbByMcState() == EbState.OPEN_VALUE ? EbState.OPEN : EbState.CLOSED);
        vehicleBuilder.setEbByBrakeLoop(
            ebDetailDO.getEbByBrakeLoopState() == EbState.OPEN_VALUE ? EbState.OPEN : EbState.CLOSED);
        vehicleBuilder.setEbByAtcZeroSpeed(
            ebDetailDO.getEbByAtcZeroSpeedState() == EbState.OPEN_VALUE ? EbState.OPEN : EbState.CLOSED);

        vehicleBuilder.setEbByPushButton(
            ebDetailDO.getEbByPushButtonState() == EbState.OPEN_VALUE ? EbState.OPEN : EbState.CLOSED);
        vehicleBuilder.setEbByDeadman(
            ebDetailDO.getEbByDeadmanState() == EbState.OPEN_VALUE ? EbState.OPEN : EbState.CLOSED);

        if (carIndex == sharedModel.getCurrentActiveCabId())
        {
          int fsbValue = -100;
          vehicleBuilder.setMasterControllerInFSB(
              ebDetailDO.getMasterControllerInFSBState() == fsbValue ? EbState.OPEN : EbState.CLOSED);
        }
      }
      else
      {
        vehicleBuilder.setEbByCc(EbState.OPEN);
        vehicleBuilder.setEbByNonCabEnabled(EbState.OPEN);
        vehicleBuilder.setEbByNonDirectionSelected(EbState.OPEN);
        vehicleBuilder.setEbByMc(EbState.OPEN);
        vehicleBuilder.setEbByBrakeLoop(EbState.OPEN);
        vehicleBuilder.setEbByAtcZeroSpeed(EbState.OPEN);
        vehicleBuilder.setEbByPushButton(EbState.OPEN);
        vehicleBuilder.setEbByDeadman(EbState.OPEN);
        vehicleBuilder.setMasterControllerInFSB(EbState.CLOSED);
      }
      builder.addEbInterlockStatus(vehicleBuilder);
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
  private EBInterlockStatusDO getEbDetailsForCarIndex(List<Entry<EBInterlockStatusDO>> pantoDetails,
      int carIndex)
  {
    return pantoDetails.stream().filter(entry -> entry.getIndex() == carIndex).findFirst().map(Entry::getData)
        .orElse(new EBInterlockStatusDO());
  }
}
