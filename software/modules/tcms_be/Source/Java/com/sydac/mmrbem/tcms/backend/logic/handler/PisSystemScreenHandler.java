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

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.sydac.foundation.IPropertySetter;
import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.backend.app.io.models.IOhpOutputsModel;
import com.sydac.mmrbem.tcms.backend.comms.CommsBinding;
import com.sydac.mmrbem.tcms.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.tcms.backend.logic.SharedDataModel;
import com.sydac.mmrbem.tcms.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.IIntercomInputsProperties;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.IOhpOutputsProperties;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.IPAPISVehicleOutputsProperties;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.IPISBEInputsProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppInputsPISScreenProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppInputsProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsPISScreenProperties;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.VehiclePecuList;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;

/**
 * This handler class is used for handling PIS system Screen (PC or PECU)
 * 
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class, SharedDataModel.class })
public class PisSystemScreenHandler extends AbstractFunctionalLogic
{
  @Autowired
  SharedDataModel sharedDataModel;

  private IOhpOutputsModel OhpOutputsModel;

  private CommsBinding commsBinding;

  private VehiclePecuList vehiclePecuList;

  private int lastVehicleIndex = 0;

  protected PisSystemScreenHandler(CommsBinding commsBinding, SharedDataModel sharedDataModel)
  {
    super(commsBinding, IOhpOutputsProperties.class, IAppInputsProperties.class,IPISBEInputsProperties.class,
        IPAPISVehicleOutputsProperties.class);
    this.sharedDataModel = sharedDataModel;
    this.commsBinding = commsBinding;
    // initalizeOhpOutputModel();
  }

  @Override
  public <T> void ohpOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int ohpIndex)
  {
    initalizeOhpOutputModel();
    if (IOhpOutputsProperties.VEHICLE_ID.equals(key))
    {
      setApplicationOutputsProperty(IAppOutputsPISScreenProperties.PECU_CALL_VEHICLE_INDEX,
          (Integer)newValue);
    }
    else if (IOhpOutputsProperties.OHP_ID.equals(key))
    {
      setApplicationOutputsProperty(IAppOutputsPISScreenProperties.PECU_CALL_INDEX, (Integer)newValue);
    }
    else if (IOhpOutputsProperties.STATUS.equals(key))
    {
      setApplicationOutputsProperty(IAppOutputsPISScreenProperties.PECU_CALL_STATUS, (Integer)newValue);
    }
    else if (IOhpOutputsProperties.ISOLATION_DEISOLATION_LIST.equals(key))
    {
      setApplicationOutputsProperty(IAppOutputsPISScreenProperties.TCMS_ISOLATION_DEISOLATION_LIST,
          (byte[])newValue);
    }
  }

  @Override
  public <T> void papisVehicleOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue,
      int vehicleIndex)
  {
   
    initalizeOhpOutputModel();
//    if (IPAPISVehicleOutputsProperties.PECU_ALARM_ACTIVE.equals(key))
//    {
//      System.out.println("PECU_ALARM_ACTIVE " + (Integer)newValue);
//      checkTotalVehicle();
//      if (vehicleIndex == 0)
//      {
//        setApplicationOutputsProperty(IAppOutputsPISScreenProperties.PABR_STATUS_DM1, (Integer)newValue);
//      }
//      else if (vehicleIndex == lastVehicleIndex)
//      {
//        setApplicationOutputsProperty(IAppOutputsPISScreenProperties.PABR_STATUS_DM2, (Integer)newValue);
//      }
//    }
  }

  private void checkTotalVehicle()
  {
    lastVehicleIndex = (this.sharedDataModel.getTotalCar() == 6) ? 5 : 7;
  }

  @Override
  public <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {
    IPropertySetter propertySetter = getPISBEInputsSetter(vehicleIndex);
    if (key.equals(IAppInputsPISScreenProperties.PECU_RESET_REQ_BUTTON))
    {

      IPropertySetter onInputSetter = getOhpOutputHandler();

      if (onInputSetter != null)
      {
        if ((Integer)newValue == TCMSConstants.ACTIVE)
        {
          setInputData(onInputSetter, IIntercomInputsProperties.CAB_CANCEL_BUTTON,
              ApplicationConstants.SET_VALUE);
        }
        else
        {
          setInputData(onInputSetter, IIntercomInputsProperties.CAB_CANCEL_BUTTON,
              ApplicationConstants.RESET_VALUE);
        }
      }
    }else  if (IAppInputsPISScreenProperties.PABR_BYPASS_REQ_BUTTON.equals(key)
        && (Integer)newValue > -1)
    {

      setInputData(propertySetter, IPISBEInputsProperties.PABR_STATUS,
          (Integer)newValue);
    }
  }

  private void initalizeOhpOutputModel()
  {

    if (this.OhpOutputsModel == null)
    {

      this.OhpOutputsModel = (IOhpOutputsModel)commsBinding.getOhpOutputsModel();

    }
  }

}
