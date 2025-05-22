/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
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
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsVCBInterlockScreenProperties;
import com.sydac.mmrbem.tcms.common.data.Entry;
import com.sydac.mmrbem.tcms.common.data.VCBInterlockStatusDO;
import com.sydac.mmrbem.tcms.common.data.VehicleDetailModel;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsVCBInterlockScreenProperties;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.VcbInterlockData.VcbState;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;

/**
 * This handler class is used for handling VCB Interlock Screen data
 * 
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class, SharedDataModel.class })
public class VCBInterlockScreenHandler extends AbstractFunctionalLogic
{
  private SharedDataModel sharedModel;

  private List<VehicleDetailModel> vehicleDetailModelList;

  private List<Entry<VCBInterlockStatusDO>> vcbStatusDetails = new ArrayList<>();

  /**
   * Listener to update vehicleDetailModelList
   */
  IModelListener trainConfigListener = (arg0, arg1) -> {
    vehicleDetailModelList = sharedModel.getVehicleDetailModelList();

    // Write the initial state of VCB status
    if (!vehicleDetailModelList.isEmpty())
    {
      setVcbStatusData();
    }
  };

  protected VCBInterlockScreenHandler(CommsBinding commsBinding, SharedDataModel aSharedModel)
  {
    super(commsBinding, ITCMSVehicleOutputsVCBInterlockScreenProperties.class);
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
    if (ITCMSVehicleOutputsVCBInterlockScreenProperties.TRANSFORMER_OIL_TEMPERATURE.equals(key))
    {
      VCBInterlockStatusDO vehicleVcbDetailDO = getVcbDetailsForCarIndex(vcbStatusDetails, vehicleIndex);
      vehicleVcbDetailDO.setTransformerOilTempState((Integer)newValue);
      setVCBInterlockDetails(vcbStatusDetails, vehicleVcbDetailDO, vehicleIndex);

    }
    else if (ITCMSVehicleOutputsVCBInterlockScreenProperties.VCB_OPENED_BY_AC_OVER_CURRENT.equals(key))
    {
      VCBInterlockStatusDO vehicleVcbDetailDO = getVcbDetailsForCarIndex(vcbStatusDetails, vehicleIndex);
      vehicleVcbDetailDO.setVcbOpenedByAcState((Integer)newValue);
      setVCBInterlockDetails(vcbStatusDetails, vehicleVcbDetailDO, vehicleIndex);
    }
    else if (ITCMSVehicleOutputsVCBInterlockScreenProperties.VCB_OPENED_BY_MTR_PROTECTION.equals(key))
    {
      VCBInterlockStatusDO vehicleVcbDetailDO = getVcbDetailsForCarIndex(vcbStatusDetails, vehicleIndex);
      vehicleVcbDetailDO.setVcbOpenedByMtrState((Integer)newValue);
      setVCBInterlockDetails(vcbStatusDetails, vehicleVcbDetailDO, vehicleIndex);
    }
    else if (ITCMSVehicleOutputsVCBInterlockScreenProperties.VCB_OPENED_BY_IC_M.equals(key))
    {
      VCBInterlockStatusDO vehicleVcbDetailDO = getVcbDetailsForCarIndex(vcbStatusDetails, vehicleIndex);
      vehicleVcbDetailDO.setVcbOpenedByIcMState((Integer)newValue);
      setVCBInterlockDetails(vcbStatusDetails, vehicleVcbDetailDO, vehicleIndex);
    }
    else if (ITCMSVehicleOutputsVCBInterlockScreenProperties.VCB_OPENED_BY_IC_DM.equals(key))
    {
      VCBInterlockStatusDO vehicleVcbDetailDO = getVcbDetailsForCarIndex(vcbStatusDetails, vehicleIndex);
      vehicleVcbDetailDO.setVcbOpenedByIcDmState((Integer)newValue);
      setVCBInterlockDetails(vcbStatusDetails, vehicleVcbDetailDO, vehicleIndex);
    }
    else if (ITCMSVehicleOutputsVCBInterlockScreenProperties.VCB_OPENED_BY_APS.equals(key))
    {
      VCBInterlockStatusDO vehicleVcbDetailDO = getVcbDetailsForCarIndex(vcbStatusDetails, vehicleIndex);
      vehicleVcbDetailDO.setVcbOpenedByAps((Integer)newValue);
      setVCBInterlockDetails(vcbStatusDetails, vehicleVcbDetailDO, vehicleIndex);
    }
    else if (ITCMSVehicleOutputsVCBInterlockScreenProperties.NO_LINE_VOLTAGE.equals(key))
    {
      VCBInterlockStatusDO vehicleVcbDetailDO = getVcbDetailsForCarIndex(vcbStatusDetails, vehicleIndex);
      vehicleVcbDetailDO.setNoLineVoltageState((Integer)newValue);
      setVCBInterlockDetails(vcbStatusDetails, vehicleVcbDetailDO, vehicleIndex);
    }
    else if (ITCMSVehicleOutputsVCBInterlockScreenProperties.APS_K_AK_CONTACTOR.equals(key))
    {
      VCBInterlockStatusDO vehicleVcbDetailDO = getVcbDetailsForCarIndex(vcbStatusDetails, vehicleIndex);
      vehicleVcbDetailDO.setApsKAkState((Integer)newValue);
      setVCBInterlockDetails(vcbStatusDetails, vehicleVcbDetailDO, vehicleIndex);
    }
    else if (ITCMSVehicleOutputsVCBInterlockScreenProperties.CI_K_AK_CONTACTOR.equals(key))
    {
      VCBInterlockStatusDO vehicleVcbDetailDO = getVcbDetailsForCarIndex(vcbStatusDetails, vehicleIndex);
      vehicleVcbDetailDO.setCiKAkState((Integer)newValue);
      setVCBInterlockDetails(vcbStatusDetails, vehicleVcbDetailDO, vehicleIndex);
    }

  }

  private void setVCBInterlockDetails(List<Entry<VCBInterlockStatusDO>> vcbStatusDetailsList,
      VCBInterlockStatusDO vehicleVcbDetailDO, int carIndex)
  {
    if (vcbStatusDetailsList.stream().anyMatch(entry -> entry.getIndex() == carIndex))
    {
      vcbStatusDetailsList.stream().filter(entry -> entry.getIndex() == carIndex)
          .forEach(entry -> entry.setData(vehicleVcbDetailDO));
    }
    else
    {
      vcbStatusDetailsList.add(new Entry<>(carIndex, vehicleVcbDetailDO));
      Collections.sort(vcbStatusDetailsList);
    }

    // Set VCB status data in COMMS
    setVcbStatusData();

  }

  private void setVcbStatusData()
  {
    setApplicationOutputsProperty(IAppOutputsVCBInterlockScreenProperties.VCB_INTERLOCK_STATUS,
        getRawForVcbStatus(vcbStatusDetails));

  }

  private byte[] getRawForVcbStatus(List<Entry<VCBInterlockStatusDO>> vcbStatusDetails)
  {
    TCMSProto.VcbInterlockData.Builder builder = TCMSProto.VcbInterlockData.newBuilder();
    TCMSProto.VcbInterlockData.VcbInterlockStatus.Builder vehicleBuilder = TCMSProto.VcbInterlockData.VcbInterlockStatus
        .newBuilder();

    for (int index = 0; index < vcbStatusDetails.size(); index++)
    {
      int carIndex = vcbStatusDetails.get(index).getIndex();
      vehicleBuilder.setCarIndex(carIndex);
      VCBInterlockStatusDO vcbDetailDO = vcbStatusDetails.get(index).getData();
      String carClassCode = vehicleDetailModelList != null
          ? vehicleDetailModelList.get(carIndex).getCarClassCode()
          : ApplicationConstants.BLANK;

      if (TCMSConstants.T_CAR.equals(carClassCode))
      {

        vehicleBuilder.setVcbTransformerTempState(
            vcbDetailDO.getTransformerOilTempState() == VcbState.OPEN_VALUE ? VcbState.OPEN
                : VcbState.CLOSED);

        vehicleBuilder.setVcbByAcState(
            vcbDetailDO.getVcbOpenedByAcState() == VcbState.OPEN_VALUE ? VcbState.OPEN : VcbState.CLOSED);

        vehicleBuilder.setVcbByMtrState(
            vcbDetailDO.getVcbOpenedByMtrState() == VcbState.OPEN_VALUE ? VcbState.OPEN : VcbState.CLOSED);
        if (index == ApplicationConstants.T5_SIX_CAR_CONFIG
            && sharedModel.getTotalCar() == ApplicationConstants.SIX_CAR_CONFIG)
        {
          updateVcbIcMAndIcDmState(vehicleBuilder, vcbDetailDO);
        }
        else if (index == ApplicationConstants.T4_EIGHT_CAR_CONFIG
            && sharedModel.getTotalCar() == ApplicationConstants.EIGHT_CAR_CONFIG)
        {
          vehicleBuilder.setVcbByIcDmState(
              vcbDetailDO.getVcbOpenedByIcMState() == VcbState.OPEN_VALUE ? VcbState.OPEN : VcbState.CLOSED);
          vehicleBuilder.setVcbByIcMState(
              vcbDetailDO.getVcbOpenedByIcMState() == VcbState.OPEN_VALUE ? VcbState.OPEN : VcbState.CLOSED);
        }
        else if (index == ApplicationConstants.T7_EIGHT_CAR_CONFIG
            && sharedModel.getTotalCar() == ApplicationConstants.EIGHT_CAR_CONFIG)
        {
          updateVcbIcMAndIcDmState(vehicleBuilder, vcbDetailDO);
        }
        else if (index == ApplicationConstants.T2_EIGHT_AND_SIX_CAR_CONFIG)
        {
          vehicleBuilder.setVcbByIcDmState(
              vcbDetailDO.getVcbOpenedByIcDmState() == VcbState.OPEN_VALUE ? VcbState.OPEN : VcbState.CLOSED);
          vehicleBuilder.setVcbByIcMState(
              vcbDetailDO.getVcbOpenedByIcMState() == VcbState.OPEN_VALUE ? VcbState.OPEN : VcbState.CLOSED);
        }

        vehicleBuilder.setVcbByApsState(
            vcbDetailDO.getVcbOpenedByAps() == VcbState.OPEN_VALUE ? VcbState.OPEN : VcbState.CLOSED);

        vehicleBuilder.setVcbNoLineVoltageState(
            vcbDetailDO.getNoLineVoltageState() == VcbState.OPEN_VALUE ? VcbState.OPEN : VcbState.CLOSED);

        vehicleBuilder.setVcbByApsAkState(
            vcbDetailDO.getApsKAkState() == VcbState.OPEN_VALUE ? VcbState.OPEN : VcbState.CLOSED);

        vehicleBuilder.setVcbByCiAkState(
            vcbDetailDO.getCiKAkState() == VcbState.OPEN_VALUE ? VcbState.OPEN : VcbState.CLOSED);
      }
      else
      {
        vehicleBuilder.setVcbTransformerTempState(VcbState.CLOSED);
        vehicleBuilder.setVcbByAcState(VcbState.CLOSED);
        vehicleBuilder.setVcbByMtrState(VcbState.CLOSED);
        vehicleBuilder.setVcbByIcMState(VcbState.CLOSED);
        vehicleBuilder.setVcbByIcDmState(VcbState.CLOSED);
        vehicleBuilder.setVcbByApsState(VcbState.CLOSED);
        vehicleBuilder.setVcbNoLineVoltageState(VcbState.CLOSED);
        vehicleBuilder.setVcbByApsAkState(VcbState.CLOSED);
        vehicleBuilder.setVcbByCiAkState(VcbState.CLOSED);
      }
      builder.addVcbInterlockStatus(vehicleBuilder);
    }
    return builder.build().toByteArray();
  }

  private void updateVcbIcMAndIcDmState(TCMSProto.VcbInterlockData.VcbInterlockStatus.Builder vehicleBuilder,
      VCBInterlockStatusDO vcbDetailDO)
  {
    vehicleBuilder.setVcbByIcDmState(
        vcbDetailDO.getVcbOpenedByIcMState() == VcbState.OPEN_VALUE ? VcbState.OPEN : VcbState.CLOSED);
    vehicleBuilder.setVcbByIcMState(
        vcbDetailDO.getVcbOpenedByIcDmState() == VcbState.OPEN_VALUE ? VcbState.OPEN : VcbState.CLOSED);
  }

  /**
   * Gets the existing VCBInterlockStatusDO for the car index or creates new
   * from then given list.
   *
   * @param VCBInterlockStatus
   *          List of {@link VCBInterlockStatusDO}
   * @param carIndex
   *          the car index
   * @return {@link VCBInterlockStatusDO} for given car index
   */
  private VCBInterlockStatusDO getVcbDetailsForCarIndex(List<Entry<VCBInterlockStatusDO>> pantoDetails,
      int carIndex)
  {
    return pantoDetails.stream().filter(entry -> entry.getIndex() == carIndex).findFirst().map(Entry::getData)
        .orElse(new VCBInterlockStatusDO());
  }

}
