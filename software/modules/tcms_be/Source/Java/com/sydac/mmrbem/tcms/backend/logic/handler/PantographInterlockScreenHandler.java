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
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsPantographInterlockScreenProperties;
import com.sydac.mmrbem.tcms.common.data.Entry;
import com.sydac.mmrbem.tcms.common.data.PantoInterlockStatusDO;
import com.sydac.mmrbem.tcms.common.data.VehicleDetailModel;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsPantographInterlockScreenProperties;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.PantographInterlockData.PantoState;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;

/**
 * This handler class is used for handling Speed Limit Interlock Screen data
 * 
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class, SharedDataModel.class })
public class PantographInterlockScreenHandler extends AbstractFunctionalLogic
{
  private SharedDataModel sharedModel;

  private List<VehicleDetailModel> vehicleDetailModelList;

  private List<Entry<PantoInterlockStatusDO>> pantoStatusDetails = new ArrayList<>();

  /**
   * Listener to update vehicleDetailModelList
   */
  IModelListener trainConfigListener = (arg0, arg1) -> {
    vehicleDetailModelList = sharedModel.getVehicleDetailModelList();

    // Write the initial state of Air Conditioning status
    if (!vehicleDetailModelList.isEmpty())
    {
      setPantoStatusData();
    }
  };

  protected PantographInterlockScreenHandler(CommsBinding commsBinding, SharedDataModel aSharedModel)
  {
    super(commsBinding, ITCMSVehicleOutputsPantographInterlockScreenProperties.class);
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
    if (ITCMSVehicleOutputsPantographInterlockScreenProperties.EGS_OPERATED_ACPM.equals(key))
    {
      PantoInterlockStatusDO vehiclePantoDetailDO = getPantoDetailsForCarIndex(pantoStatusDetails,
          vehicleIndex);
      vehiclePantoDetailDO.setAcpmState((Integer)newValue);
      setPantoDetails(pantoStatusDetails, vehiclePantoDetailDO, vehicleIndex);

    }
    else if (ITCMSVehicleOutputsPantographInterlockScreenProperties.EGS_OPERATED_OSPM.equals(key))
    {
      PantoInterlockStatusDO vehiclePantoDetailDO = getPantoDetailsForCarIndex(pantoStatusDetails,
          vehicleIndex);
      vehiclePantoDetailDO.setOcpmState((Integer)newValue);
      setPantoDetails(pantoStatusDetails, vehiclePantoDetailDO, vehicleIndex);
    }

  }

  private void setPantoDetails(List<Entry<PantoInterlockStatusDO>> pantoStatusDetailsList,
      PantoInterlockStatusDO vehiclePantoDetailDO, int carIndex)
  {
    if (pantoStatusDetailsList.stream().anyMatch(entry -> entry.getIndex() == carIndex))
    {
      pantoStatusDetailsList.stream().filter(entry -> entry.getIndex() == carIndex)
          .forEach(entry -> entry.setData(vehiclePantoDetailDO));
    }
    else
    {
      pantoStatusDetailsList.add(new Entry<>(carIndex, vehiclePantoDetailDO));
      Collections.sort(pantoStatusDetailsList);
    }

    // Set Panto status data in COMMS
    setPantoStatusData();

  }

  private void setPantoStatusData()
  {
    setApplicationOutputsProperty(IAppOutputsPantographInterlockScreenProperties.PANTO_STATUS,
        getRawForPantoStatus(pantoStatusDetails));

  }

  private byte[] getRawForPantoStatus(List<Entry<PantoInterlockStatusDO>> pantoStatusDetails)
  {
    TCMSProto.PantographInterlockData.Builder builder = TCMSProto.PantographInterlockData.newBuilder();
    TCMSProto.PantographInterlockData.PantographInterlockStatus.Builder vehicleBuilder = TCMSProto.PantographInterlockData.PantographInterlockStatus
        .newBuilder();

    for (int index = 0; index < pantoStatusDetails.size(); index++)
    {
      int carIndex = pantoStatusDetails.get(index).getIndex();
      vehicleBuilder.setCarIndex(carIndex);
      PantoInterlockStatusDO pantoInterlockDetailDO = pantoStatusDetails.get(index).getData();
      String carClassCode = vehicleDetailModelList != null
          ? vehicleDetailModelList.get(carIndex).getCarClassCode()
          : ApplicationConstants.BLANK;
      if (TCMSConstants.T_CAR.equals(carClassCode))
      {

        vehicleBuilder
            .setAcpmState(pantoInterlockDetailDO.getAcpmState() == PantoState.OPEN_VALUE ? PantoState.OPEN
                : PantoState.CLOSED);
        vehicleBuilder
            .setOcpmState(pantoInterlockDetailDO.getOcpmState() == PantoState.OPEN_VALUE ? PantoState.OPEN
                : PantoState.CLOSED);
      }
      else
      {
        vehicleBuilder.setAcpmState(PantoState.CLOSED);
        vehicleBuilder.setOcpmState(PantoState.CLOSED);
      }
      builder.addPantographInterlockStatus(vehicleBuilder);
    }
    return builder.build().toByteArray();
  }

  /**
   * Gets the existing VehiclePantoInterlockStatusDO for the car index or
   * creates new from then given list.
   *
   * @param airConditioningDetails
   *          List of {@link PantoInterlockStatusDO}
   * @param carIndex
   *          the car index
   * @return {@link PantoInterlockStatusDO} for given car index
   */
  private PantoInterlockStatusDO getPantoDetailsForCarIndex(List<Entry<PantoInterlockStatusDO>> pantoDetails,
      int carIndex)
  {
    return pantoDetails.stream().filter(entry -> entry.getIndex() == carIndex).findFirst().map(Entry::getData)
        .orElse(new PantoInterlockStatusDO());
  }

}
