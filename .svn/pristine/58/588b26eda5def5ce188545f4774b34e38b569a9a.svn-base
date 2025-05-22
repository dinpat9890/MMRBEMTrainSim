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

import java.util.List;

import org.springframework.stereotype.Service;

import com.sydac.foundation.IModelListener;
import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.backend.comms.CommsBinding;
import com.sydac.mmrbem.tcms.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.tcms.backend.logic.SharedDataModel;
import com.sydac.mmrbem.tcms.backend.logic.SharedDataModel.Change;
import com.sydac.mmrbem.tcms.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.IPAPISVehicleOutputsOperatingScreenProperties;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.IPISBEOutputsOperatingScreenProperties;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.IPISBEOutputsProperties;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsOperatingScreenProperties;
import com.sydac.mmrbem.tcms.common.data.VehicleDetailModel;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsOperatingScreenProperties;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;
import com.sydac.mmrbem.tcms.common.state.TCMSModeEnum;
import com.sydac.mmrbem.tcms.common.utils.XMLParser;

/**
 * This handler class is used for Operating Screen change handling.
 * 
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class, SharedDataModel.class })
public class OperatingScreenChangeHandler extends AbstractFunctionalLogic
{
  private SharedDataModel sharedModel;

  private XMLParser xmlParser;

  private List<VehicleDetailModel> vehicleDetailModelList;

  public OperatingScreenChangeHandler(CommsBinding commsBinding, SharedDataModel aSharedModel)
  {
    super(commsBinding, ITCMSVehicleOutputsOperatingScreenProperties.class,
        IPISBEOutputsOperatingScreenProperties.class, IPAPISVehicleOutputsOperatingScreenProperties.class);
    this.sharedModel = aSharedModel;
    xmlParser = new XMLParser();
  }

  IModelListener trainConfigListener = (arg0, arg1) -> {
    vehicleDetailModelList = sharedModel.getVehicleDetailModelList();
  };

  @Override
  public void attachListeners()
  {
    super.attachListeners();
    sharedModel.addModelListener(trainConfigListener, Change.TRAIN_CONFIGURED, true);
  }

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
    if (sharedModel.getCurrentActiveCabId() == vehicleIndex)
    {
      if (ITCMSVehicleOutputsOperatingScreenProperties.BATTERY_VOLTAGE_DM.equals(key))
      {
        setApplicationOutputsProperty(IAppOutputsOperatingScreenProperties.BATTERY_VOLTAGE,
            (Integer)newValue);
        // Setting default train number
        setApplicationOutputsProperty(IAppOutputsOperatingScreenProperties.TRAIN_NUMBER,
            TCMSConstants.TRAIN_NUMBER);
      }
      else if (ITCMSVehicleOutputsOperatingScreenProperties.TBC_POSITION.equals(key))
      {
        setApplicationOutputsProperty(IAppOutputsOperatingScreenProperties.NOTCH_VALUE, (Integer)newValue);
      }
      else if (ITCMSVehicleOutputsOperatingScreenProperties.RESCUE_MODE.equals(key))
      {
        setApplicationOutputsProperty(IAppOutputsOperatingScreenProperties.RESCUE_MODE, (Integer)newValue);
      }
      else if (ITCMSVehicleOutputsOperatingScreenProperties.JOG_MODE.equals(key))
      {
        setApplicationOutputsProperty(IAppOutputsOperatingScreenProperties.JOG_MODE, (Integer)newValue);
      }
      else if (ITCMSVehicleOutputsOperatingScreenProperties.ENABLE_TO_RUN.equals(key))
      {
        setApplicationOutputsProperty(IAppOutputsOperatingScreenProperties.ENABLE_TO_RUN, (Integer)newValue);
      }
      else if (ITCMSVehicleOutputsOperatingScreenProperties.ATC_BYPASS_MODE.equals(key))
      {
        setApplicationOutputsProperty(IAppOutputsOperatingScreenProperties.ATC_BYPASS, (Integer)newValue);
      }
      else if (ITCMSVehicleOutputsOperatingScreenProperties.SHORE_SUPPLY.equals(key))
      {
        setApplicationOutputsProperty(IAppOutputsOperatingScreenProperties.SHORE_SUPPLY, (Integer)newValue);
      }
      else if (ITCMSVehicleOutputsOperatingScreenProperties.COUPLED.equals(key))
      {
        setApplicationOutputsProperty(IAppOutputsOperatingScreenProperties.COUPLED, (Integer)newValue);
      }
      else if (ITCMSVehicleOutputsOperatingScreenProperties.ODOMETER.equals(key))
      {
        double odometer = sharedModel.getOdometerInKm((Double)newValue);
        setApplicationOutputsProperty(IAppOutputsOperatingScreenProperties.ODOMETER, odometer);
      }
      else if (ITCMSVehicleOutputsOperatingScreenProperties.TOTAL_WEIGHT.equals(key))
      {
        int totalWeight = sharedModel.getWeightInTon((Integer)newValue);
        setApplicationOutputsProperty(IAppOutputsOperatingScreenProperties.TOTAL_WEIGHT,
            (Integer)totalWeight);
      }
      else if (ITCMSVehicleOutputsOperatingScreenProperties.TBC_FEEDBACK.equals(key))
      {
        setApplicationOutputsProperty(IAppOutputsOperatingScreenProperties.TCMS_TBC_FEEDBACK,
            (Integer)newValue);
      }
    }
    if (ITCMSVehicleOutputsOperatingScreenProperties.LINE_VOLTAGE.equals(key))
    {
      double lineVoltage = sharedModel.getVoltagetInKV((Double)newValue);
      updateLineVoltageForTCar(lineVoltage, vehicleIndex);
    }
  }

  @Override
  public <T> void papisVehicleOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue,
      int vehicleIndex)
  {
    if (IPAPISVehicleOutputsOperatingScreenProperties.DOOR_OPEN.equals(key))
    {
      if ((Integer)newValue > 0)
      {
        setApplicationOutputsProperty(IAppOutputsOperatingScreenProperties.DOOR_OPEN_SIDE,
            (ApplicationConstants.DOOR_OPEN).getBytes());
      }
      else
      {
        setApplicationOutputsProperty(IAppOutputsOperatingScreenProperties.DOOR_OPEN_SIDE,
            (ApplicationConstants.STATION_DETAIL_NO_DATA).getBytes());
      }
    }
    else if (IPAPISVehicleOutputsOperatingScreenProperties.DOOR_CLOSE.equals(key))
    {
      if ((Integer)newValue > 0)
      {
        setApplicationOutputsProperty(IAppOutputsOperatingScreenProperties.DOOR_OPEN_SIDE,
            (ApplicationConstants.DOOR_CLOSE).getBytes());
      }
      else
      {
        setApplicationOutputsProperty(IAppOutputsOperatingScreenProperties.DOOR_OPEN_SIDE,
            (ApplicationConstants.STATION_DETAIL_NO_DATA).getBytes());
      }
    }
  }

  @Override
  public <T> void pisBeOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {
    if (IPISBEOutputsOperatingScreenProperties.SELECTED_START_STATION_ID.equals(key))
    {
      if ((Integer)newValue > 0)
      {
        setApplicationOutputsProperty(IAppOutputsOperatingScreenProperties.START_STATION,
            xmlParser.getStationName((Integer)newValue).getBytes());
        sharedModel.setStartStationId((Integer)newValue);
      }
      else
      {
        setApplicationOutputsProperty(IAppOutputsOperatingScreenProperties.START_STATION,
            (ApplicationConstants.STATION_DETAIL_NO_DATA).getBytes());
        sharedModel.setCurrentStationId(0);
      }
    }
    else if (IPISBEOutputsOperatingScreenProperties.SELECTED_CURRENT_STATION_ID.equals(key))
    {
      if ((Integer)newValue > 0)
      {
        setApplicationOutputsProperty(IAppOutputsOperatingScreenProperties.CURRENT_STATION,
            xmlParser.getStationName((Integer)newValue).getBytes());
        sharedModel.setCurrentStationId((Integer)newValue);
      }
      else
      {
        setApplicationOutputsProperty(IAppOutputsOperatingScreenProperties.CURRENT_STATION,
            (ApplicationConstants.STATION_DETAIL_NO_DATA).getBytes());
        sharedModel.setCurrentStationId(0);
      }
    }
    else if (IPISBEOutputsOperatingScreenProperties.SELECTED_NEXT_STATION_ID.equals(key))
    {
      if ((Integer)newValue > 0)
      {
        setApplicationOutputsProperty(IAppOutputsOperatingScreenProperties.NEXT_STATION,
            xmlParser.getStationName((Integer)newValue).getBytes());
        sharedModel.setNextStationId((Integer)newValue);
      }
      else
      {
        setApplicationOutputsProperty(IAppOutputsOperatingScreenProperties.NEXT_STATION,
            (ApplicationConstants.STATION_DETAIL_NO_DATA).getBytes());
        sharedModel.setNextStationId(0);
      }
    }
    else if (IPISBEOutputsOperatingScreenProperties.SELECTED_TERMINAL_STATION_ID.equals(key))
    {
      if ((Integer)newValue > 0)
      {
        setApplicationOutputsProperty(IAppOutputsOperatingScreenProperties.DESTINATION_STATION,
            xmlParser.getStationName((Integer)newValue).getBytes());
        sharedModel.setTerminalStationId((Integer)newValue);
      }
      else
      {
        setApplicationOutputsProperty(IAppOutputsOperatingScreenProperties.DESTINATION_STATION,
            (ApplicationConstants.STATION_DETAIL_NO_DATA).getBytes());
        sharedModel.setTerminalStationId(0);
      }
    }
    else if (IPISBEOutputsOperatingScreenProperties.SELECTED_ROUTE_ID.equals(key))
    {
      if ((Integer)newValue == -1 || (Integer)newValue > 6)
      {
        setApplicationOutputsProperty(IAppOutputsOperatingScreenProperties.LINE_DIRECTION_DETAIL,
            (ApplicationConstants.NO_LINE).getBytes());
      }
      else
      {
        setApplicationOutputsProperty(IAppOutputsOperatingScreenProperties.LINE_DIRECTION_DETAIL,
            (xmlParser.getRouteCode((Integer)newValue - 1)).getBytes());
      }
      sharedModel.setRouteId((Integer)newValue);
    }
    else if (IPISBEOutputsOperatingScreenProperties.SELECTED_MODE.equals(key) && (Integer)newValue > 0)
    {
      setApplicationOutputsProperty(IAppOutputsOperatingScreenProperties.TCMS_MODE,
          (TCMSModeEnum.valueOf((Integer)newValue).getModeName()).getBytes());
    }
  }

  private void updateLineVoltageForTCar(Double lineVoltage, int vehicleIndex)
  {
    String carClassCode = vehicleDetailModelList != null
        ? vehicleDetailModelList.get(vehicleIndex).getCarClassCode()
        : ApplicationConstants.BLANK;
    if (TCMSConstants.T_CAR.equals(carClassCode))
    {
      setApplicationOutputsProperty(IAppOutputsOperatingScreenProperties.LINE_VOLTAGE, lineVoltage);
    }
  }
}
