/*
 * ==================================================================
 * (C)Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.backend.logic.handler;

import java.util.HashMap;
import java.util.Map;

import org.springframework.stereotype.Service;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.backend.comms.CommsBinding;
import com.sydac.mmrbem.tcms.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.tcms.backend.logic.SharedDataModel;
import com.sydac.mmrbem.tcms.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.handlers.ITCMSVehicleInputsHVCommandHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppInputsHVLeftTCarCommandScreenProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppInputsHVMiddleTCarCommandScreenProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppInputsHVRightTCarCommandScreenProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppInputsHighVoltageSystemCommandScreenProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppInputsProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsHighVolatageSystemCommandsScreenProperties;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.HVSelectedCarIndexList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.HVSelectedCarIndexList.SelectedCarIndex;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;

/**
 * This handler class is used for High Voltage System Command screen handling.
 * 
 */

@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class, SharedDataModel.class })
public class HVSystemCommandScreenHandler extends AbstractFunctionalLogic
{
  private ITCMSVehicleInputsHVCommandHandler vehicleInputsHandler;

  private Map<Integer, Integer> pantoSelectedMap = new HashMap<>();

  private SharedDataModel sharedDataModel;

  private int pantoSelected = 0;

  private int pantoGreenState = 0;

  private int isolateCiVal = 0;

  private int isolatePantoVal = 0;

  private int isolateVcbVal = 0;

  private int isolateAps1Val = 0;

  private int isolateAps2Val = 0;

  protected HVSystemCommandScreenHandler(CommsBinding commsBinding, SharedDataModel aShareDataModel)
  {
    super(commsBinding, IAppInputsProperties.class, ITCMSVehicleOutputsProperties.class);
    sharedDataModel = aShareDataModel;
    initalizeVehicleInputHandler();
  }

  private void resetInputCommands()
  {
    for (int carIndex = 0; carIndex < sharedDataModel.getTotalCar(); carIndex++)
    {
      vehicleInputsHandler = (ITCMSVehicleInputsHVCommandHandler)getTCMSVehicleInputsSetter(carIndex);
      vehicleInputsHandler.setTcmsIsolateAps1(ApplicationConstants.RESET_VALUE);
      vehicleInputsHandler.setTcmsIsolateAps2(ApplicationConstants.RESET_VALUE);
      vehicleInputsHandler.setTcmsIsolateCi(ApplicationConstants.RESET_VALUE);
      vehicleInputsHandler.setTcmsIsolatePanto(ApplicationConstants.RESET_VALUE);
      vehicleInputsHandler.setTcmsIsolateVcb(ApplicationConstants.RESET_VALUE);
    }
  }

  private void initializeMap()
  {
    for (int i = 0; i < sharedDataModel.getTotalCar(); i++)
    {
      pantoSelectedMap.put(i, 0);
    }
  }

  @Override
  public <T> void tcmsVehicleOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue,
      int vehicleIndex)
  {
    if (key.equals(ITCMSVehicleOutputsProperties.HMI_POWER) && Boolean.TRUE.equals(newValue))
    {
      initializeMap();
    }
    else if (ITCMSVehicleOutputsProperties.POWER_OFF_PRESSED.equals(key) && Boolean.TRUE.equals(newValue))
    {
      resetInputCommands();
    }
  }

  @Override
  public <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {
    if (getActiveVehicleIndex() == vehicleIndex)
    {
      if (key.equals(IAppInputsHighVoltageSystemCommandScreenProperties.PANTO_SELECTED_REQ_CAR)
          && (Integer)newValue > -1)
      {
        
      
        if (pantoSelectedMap.get(newValue) == 0)
        {
          pantoSelectedMap.put((Integer)newValue, 1);
        }
        else
        {
          pantoSelectedMap.put((Integer)newValue, 0);
        }
        checkPantoRiseSelectionEnabled();
        
      
      }
      else if (key.equals(IAppInputsHighVoltageSystemCommandScreenProperties.RISE_SELECTED_PANTO_REQ))
      {
        pantoRiseSelectedReq((Integer)newValue);
        pantoGreenState = (Integer)newValue;
        
    
        checkPantoRiseSelectionEnabled();

      }
      else if (key.equals(IAppInputsHighVoltageSystemCommandScreenProperties.PANTO_LOWER_REQ_CAR))
      {
        pantoLowerReq((Integer)newValue);
      }
      else if (key.equals(IAppInputsHighVoltageSystemCommandScreenProperties.LOWER_ALL_PANTO_REQ))
      {
       
       
        
        setApplicationOutputsProperty(
            IAppOutputsHighVolatageSystemCommandsScreenProperties.HV_PANTO_LOW_ALL_CAR_STATE, (Integer)newValue);
        if ((Integer)newValue == 1)
        {
          pantoLowerReq(sharedDataModel.getTotalCar());
        }
        else
        {
          pantoLowerReq(-1);
        }
        
       setApplicationOutputsProperty(
           IAppOutputsHighVolatageSystemCommandsScreenProperties.HV_PANTO_RIGHT_BUTTON_STATE, 0);
        setApplicationOutputsProperty(
           IAppOutputsHighVolatageSystemCommandsScreenProperties.HV_PANTO_LEFT_BUTTON_STATE, 0);
        
        setApplicationOutputsProperty(
            IAppOutputsHighVolatageSystemCommandsScreenProperties.HV_PANTO_MIDDLE_BUTTON_STATE, 0);
     }
      else if (key.equals(IAppInputsHighVoltageSystemCommandScreenProperties.OPEN_VCB_REQ))
      {
        vcbOpenReq((Integer)newValue);
      }
      else if (key.equals(IAppInputsHighVoltageSystemCommandScreenProperties.CLOSE_VCB_REQ))
      {
        vcbCloseReq((Integer)newValue);
      }
      else if (key.equals(IAppInputsHighVoltageSystemCommandScreenProperties.REQ_CTRL_VCB_NS)
          && (Integer)newValue > -1)
      {
        reqCtrlVcbNs((Integer)newValue);
      }
      else if (key.equals(IAppInputsHighVoltageSystemCommandScreenProperties.ISOLATE_CI_REQ))
      {
        isolateCiVal = (Integer)newValue;
      }
      else if (key.equals(IAppInputsHighVoltageSystemCommandScreenProperties.ISOLATE_CI_REQ_CAR)
          && (Integer)newValue > -1)
      {
        isolateCiReq((Integer)newValue);
      }
      else if (key.equals(IAppInputsHighVoltageSystemCommandScreenProperties.ISOLATE_PANTO_REQ))
      {
        isolatePantoVal = (Integer)newValue;
      }
      else if (key.equals(IAppInputsHighVoltageSystemCommandScreenProperties.ISOLATE_PANTO_REQ_CAR)
          && (Integer)newValue > -1)
      {
        isolatePantoReq((Integer)newValue);
      }
      else if (key.equals(IAppInputsHighVoltageSystemCommandScreenProperties.ISOLATE_VCB_REQ))
      {
        isolateVcbVal = (Integer)newValue;
      }
      else if (key.equals(IAppInputsHighVoltageSystemCommandScreenProperties.ISOLATE_VCB_REQ_CAR)
          && (Integer)newValue > -1)
      {
        isolateVcbReq((Integer)newValue);
      }
      else if (key.equals(IAppInputsHighVoltageSystemCommandScreenProperties.ISOLATE_APS1_REQ))
      {
        isolateAps1Val = (Integer)newValue;
      }
      else if (key.equals(IAppInputsHighVoltageSystemCommandScreenProperties.ISOLATE_APS1_REQ_CAR)
          && (Integer)newValue > -1)
      {
        isolateAps1Req((Integer)newValue);
      }
      else if (key.equals(IAppInputsHighVoltageSystemCommandScreenProperties.ISOLATE_APS2_REQ))
      {
        isolateAps2Val = (Integer)newValue;
      }
      else if (key.equals(IAppInputsHighVoltageSystemCommandScreenProperties.ISOLATE_APS2_REQ_CAR)
          && (Integer)newValue > -1)
      {
        isolateAps2Req((Integer)newValue);
      }
      else if (key.equals(IAppInputsHighVoltageSystemCommandScreenProperties.PANTO_RESET_REQ_CAR))
      {
        pantoResetReq((Integer)newValue);
      }
      else if (key.equals(IAppInputsHighVoltageSystemCommandScreenProperties.VCB_RESET_REQ_CAR))
      {
        vcbResetReq((Integer)newValue);
      }
      else if (key.equals(IAppInputsHVLeftTCarCommandScreenProperties.PANTO_BUTTON_LEFT_REQ)
          && (Integer)newValue > -1)
      {
     
        setApplicationOutputsProperty(
           IAppOutputsHighVolatageSystemCommandsScreenProperties.HV_PANTO_LEFT_BUTTON_STATE, (Integer)newValue);
        
     }
      else if (key.equals(IAppInputsHVRightTCarCommandScreenProperties.PANTO_BUTTON_RIGHT_REQ)
          && (Integer)newValue > -1)
      {
        setApplicationOutputsProperty(
            IAppOutputsHighVolatageSystemCommandsScreenProperties.HV_PANTO_RIGHT_BUTTON_STATE, (Integer)newValue);
        
      }else if (key.equals(IAppInputsHVMiddleTCarCommandScreenProperties.PANTO_BUTTON_MIDDLE_REQ)
          && (Integer)newValue > -1)
      {
        setApplicationOutputsProperty(
            IAppOutputsHighVolatageSystemCommandsScreenProperties.HV_PANTO_MIDDLE_BUTTON_STATE, (Integer)newValue);
        
      }else if (key.equals(IAppInputsHVLeftTCarCommandScreenProperties.PANTO_LOW_BUTTON_LEFT_REQ)
          && (Integer)newValue > -1)
      {
        setApplicationOutputsProperty(
            IAppOutputsHighVolatageSystemCommandsScreenProperties.HV_PANTO_LEFT_BUTTON_STATE, 0);
        setApplicationOutputsProperty(
            IAppOutputsHighVolatageSystemCommandsScreenProperties.HV_PANTO_LOW_LEFT_BUTTON_STATE, (Integer)newValue);
        
      }else if (key.equals(IAppInputsHVMiddleTCarCommandScreenProperties.PANTO_LOW_BUTTON_MIDDLE_REQ)
          && (Integer)newValue > -1)
      {
        setApplicationOutputsProperty(
            IAppOutputsHighVolatageSystemCommandsScreenProperties.HV_PANTO_LOW_MIDDLE_BUTTON_STATE, (Integer)newValue);
        
      }else if (key.equals(IAppInputsHVRightTCarCommandScreenProperties.PANTO_LOW_BUTTON_RIGHT_REQ)
          && (Integer)newValue > -1)
      {
        setApplicationOutputsProperty(
            IAppOutputsHighVolatageSystemCommandsScreenProperties.HV_PANTO_RIGHT_BUTTON_STATE, 0);
        setApplicationOutputsProperty(
            IAppOutputsHighVolatageSystemCommandsScreenProperties.HV_PANTO_LOW_RIGHT_BUTTON_STATE, (Integer)newValue);
        
      }else if (key.equals(IAppInputsHVLeftTCarCommandScreenProperties.PANTO_RESET_BUTTON_LEFT_REQ)
          && (Integer)newValue > -1)
      {
        setApplicationOutputsProperty(
            IAppOutputsHighVolatageSystemCommandsScreenProperties.HV_PANTO_LEFT_RESET_BUTTON_STATE, (Integer)newValue);
        
      }else if (key.equals(IAppInputsHVRightTCarCommandScreenProperties.PANTO_RESET_BUTTON_RIGHT_REQ)
          && (Integer)newValue > -1)
      {
        setApplicationOutputsProperty(
            IAppOutputsHighVolatageSystemCommandsScreenProperties.HV_PANTO_RIGHT_RESET_BUTTON_STATE, (Integer)newValue);
        
      }else if (key.equals(IAppInputsHVMiddleTCarCommandScreenProperties.PANTO_RESET_BUTTON_MIDDLE_REQ)
          && (Integer)newValue > -1)
      {
        setApplicationOutputsProperty(
            IAppOutputsHighVolatageSystemCommandsScreenProperties.HV_PANTO_MIDDLE_RESET_BUTTON_STATE, (Integer)newValue);
        
      }else if (key.equals(IAppInputsHVMiddleTCarCommandScreenProperties.VCB_RESET_BUTTON_MIDDLE_REQ)
          && (Integer)newValue > -1)
      {
        setApplicationOutputsProperty(
            IAppOutputsHighVolatageSystemCommandsScreenProperties.VCB_RESET_BUTTON_MIDDLE_STATE, (Integer)newValue);
        
      }else if (key.equals(IAppInputsHVMiddleTCarCommandScreenProperties.ISOLATE_MIDDLE_VCB_REQ)
          && (Integer)newValue > -1)
      {
        setApplicationOutputsProperty(
            IAppOutputsHighVolatageSystemCommandsScreenProperties.ISOLATE_MIDDLE_VCB_STATE, (Integer)newValue);
        
      }else if (key.equals(IAppInputsHVMiddleTCarCommandScreenProperties.ISOLATE_APS3_REQUEST)
          && (Integer)newValue > -1)
      {
        setApplicationOutputsProperty(
            IAppOutputsHighVolatageSystemCommandsScreenProperties.ISOLATE_APS3_STATE, (Integer)newValue);
        
      }else if (key.equals(IAppInputsHVMiddleTCarCommandScreenProperties.ISOLATE_APS4_REQUEST)
          && (Integer)newValue > -1)
      {
        setApplicationOutputsProperty(
            IAppOutputsHighVolatageSystemCommandsScreenProperties.ISOLATE_APS4_STATE, (Integer)newValue);
        
      }else if (key.equals(IAppInputsHVLeftTCarCommandScreenProperties.ISOLATE_LEFT_VCB_REQ)
          && (Integer)newValue > -1)
      {
        setApplicationOutputsProperty(
            IAppOutputsHighVolatageSystemCommandsScreenProperties.ISOLATE_LEFT_VCB_STATE, (Integer)newValue);
        
      }else if (key.equals(IAppInputsHVLeftTCarCommandScreenProperties.ISOLATE_APS2_REQUEST)
          && (Integer)newValue > -1)
      {
        setApplicationOutputsProperty(
            IAppOutputsHighVolatageSystemCommandsScreenProperties.ISOLATE_APS2_STATE, (Integer)newValue);
        
      }else if (key.equals(IAppInputsHVLeftTCarCommandScreenProperties.ISOLATE_APS1_REQUEST)
          && (Integer)newValue > -1)
      {
        setApplicationOutputsProperty(
            IAppOutputsHighVolatageSystemCommandsScreenProperties.ISOLATE_APS1_STATE, (Integer)newValue);
        
      }else if (key.equals(IAppInputsHVLeftTCarCommandScreenProperties.VCB_RESET_BUTTON_LEFT_REQ)
          && (Integer)newValue > -1)
      {
        setApplicationOutputsProperty(
            IAppOutputsHighVolatageSystemCommandsScreenProperties.VCB_RESET_BUTTON_LEFT_STATE, (Integer)newValue);
        
      }
      
      else if (key.equals(IAppInputsHVRightTCarCommandScreenProperties.ISOLATE_APS5_REQUEST)
          && (Integer)newValue > -1)
      {
        setApplicationOutputsProperty(
            IAppOutputsHighVolatageSystemCommandsScreenProperties.ISOLATE_APS5_STATE, (Integer)newValue);
        
      }else if (key.equals(IAppInputsHVRightTCarCommandScreenProperties.ISOLATE_APS6_REQUEST)
          && (Integer)newValue > -1)
      {
        setApplicationOutputsProperty(
            IAppOutputsHighVolatageSystemCommandsScreenProperties.ISOLATE_APS6_STATE, (Integer)newValue);
        
      }else if (key.equals(IAppInputsHVRightTCarCommandScreenProperties.VCB_RESET_BUTTON_RIGHT_REQ)
          && (Integer)newValue > -1)
      {
        setApplicationOutputsProperty(
            IAppOutputsHighVolatageSystemCommandsScreenProperties.VCB_RESET_BUTTON_RIGHT_STATE, (Integer)newValue);
        
      }else if (key.equals(IAppInputsHVRightTCarCommandScreenProperties.ISOLATE_RIGHT_VCB_REQ)
          && (Integer)newValue > -1)
      {
        setApplicationOutputsProperty(
            IAppOutputsHighVolatageSystemCommandsScreenProperties.ISOLATE_RIGHT_VCB_STATE, (Integer)newValue);
        
      }else if (key.equals(IAppInputsHVRightTCarCommandScreenProperties.REQ_VCB_DECLINE_BUTTON)
          && (Integer)newValue > -1)
      {
        setApplicationOutputsProperty(
            IAppOutputsHighVolatageSystemCommandsScreenProperties.VCB_DECLINE_BUTTON_STATE, (Integer)newValue);
        
      }else if (key.equals(IAppInputsHVRightTCarCommandScreenProperties.REQ_VCB_CONFIRM_BUTTON)
          && (Integer)newValue > -1)
      {
        setApplicationOutputsProperty(
            IAppOutputsHighVolatageSystemCommandsScreenProperties.VCB_CONFIRM_BUTTON_STATE, (Integer)newValue);
        
      }else if (key.equals(IAppInputsHighVoltageSystemCommandScreenProperties.ISOLATE_CI_FRONT_CAR_REQ)
          && (Integer)newValue > -1)
      {
        setApplicationOutputsProperty(
            IAppOutputsHighVolatageSystemCommandsScreenProperties.ISOLATE_CI_FRONT_CAR_STATE, (Integer)newValue);
        
      }else if (key.equals(IAppInputsHighVoltageSystemCommandScreenProperties.ISOLATE_CI_REAR_CAR_REQ)
          && (Integer)newValue > -1)
      {
        setApplicationOutputsProperty(
            IAppOutputsHighVolatageSystemCommandsScreenProperties.ISOLATE_CI_REAR_CAR_STATE, (Integer)newValue);
        
      }else if (key.equals(IAppInputsHighVoltageSystemCommandScreenProperties.ISOLATE_CI_M1_REQ)
          && (Integer)newValue > -1)
      {
        setApplicationOutputsProperty(
            IAppOutputsHighVolatageSystemCommandsScreenProperties.ISOLATE_CI_M1_STATE, (Integer)newValue);
        
      }else if (key.equals(IAppInputsHighVoltageSystemCommandScreenProperties.ISOLATE_CI_M2_REQ)
          && (Integer)newValue > -1)
      {
        setApplicationOutputsProperty(
            IAppOutputsHighVolatageSystemCommandsScreenProperties.ISOLATE_CI_M2_STATE, (Integer)newValue);
        
      }else if (key.equals(IAppInputsHighVoltageSystemCommandScreenProperties.ISOLATE_CI_M3_REQ)
          && (Integer)newValue > -1)
      {
        setApplicationOutputsProperty(
            IAppOutputsHighVolatageSystemCommandsScreenProperties.ISOLATE_CI_M3_STATE, (Integer)newValue);
        
      }
    }

  }

  private void pantoResetReq(int carIndex)
  {
   
    if (carIndex == -1)
    {
      for (int carInd = 0; carInd < sharedDataModel.getTotalCar(); carInd++)
      {
        if (vehicleInputsHandler != null)
        {
          vehicleInputsHandler = (ITCMSVehicleInputsHVCommandHandler)getTCMSVehicleInputsSetter(carInd);
          vehicleInputsHandler.setTcmsPantoResetReq(0);
        }
      }
    }
    else
    {
      vehicleInputsHandler = (ITCMSVehicleInputsHVCommandHandler)getTCMSVehicleInputsSetter(carIndex);
      vehicleInputsHandler.setTcmsPantoResetReq(1);
    }
  }

  private void vcbResetReq(int carIndex)
  {
    if (carIndex == -1)
    {
      for (int carInd = 0; carInd < sharedDataModel.getTotalCar(); carInd++)
      {
        if (vehicleInputsHandler != null)
        {
          vehicleInputsHandler = (ITCMSVehicleInputsHVCommandHandler)getTCMSVehicleInputsSetter(carInd);
          vehicleInputsHandler.setTcmsVcbResetReq(0);
        }
      }
    }
    else
    {
      vehicleInputsHandler = (ITCMSVehicleInputsHVCommandHandler)getTCMSVehicleInputsSetter(carIndex);
      vehicleInputsHandler.setTcmsVcbResetReq(1);
    }
  }

  private void isolateCiReq(int carIndex)
  {
    if (vehicleInputsHandler != null)
    {
      vehicleInputsHandler = (ITCMSVehicleInputsHVCommandHandler)getTCMSVehicleInputsSetter(carIndex);
      vehicleInputsHandler.setTcmsIsolateCi(isolateCiVal);
    }
  }

  private void isolatePantoReq(int carIndex)
  {
    if (vehicleInputsHandler != null)
    {
      vehicleInputsHandler = (ITCMSVehicleInputsHVCommandHandler)getTCMSVehicleInputsSetter(carIndex);
      vehicleInputsHandler.setTcmsIsolatePanto(isolatePantoVal);
    }
  }

  private void isolateVcbReq(int carIndex)
  {
    if (vehicleInputsHandler != null)
    {
      vehicleInputsHandler = (ITCMSVehicleInputsHVCommandHandler)getTCMSVehicleInputsSetter(carIndex);
      vehicleInputsHandler.setTcmsIsolateVcb(isolateVcbVal);
    }
  }

  private void isolateAps1Req(int carIndex)
  {
    if (vehicleInputsHandler != null)
    {
      vehicleInputsHandler = (ITCMSVehicleInputsHVCommandHandler)getTCMSVehicleInputsSetter(carIndex);
      vehicleInputsHandler.setTcmsIsolateAps1(isolateAps1Val);
    }
  }

  private void isolateAps2Req(int carIndex)
  {
    if (vehicleInputsHandler != null)
    {
      vehicleInputsHandler = (ITCMSVehicleInputsHVCommandHandler)getTCMSVehicleInputsSetter(carIndex);
      vehicleInputsHandler.setTcmsIsolateAps2(isolateAps2Val);
    }
  }

  private void checkPantoRiseSelectionEnabled()
  {
    if (pantoGreenState == 2)
    {
      setApplicationOutputsProperty(IAppOutputsHighVolatageSystemCommandsScreenProperties.RISE_SELECTED_PANTO,
          pantoGreenState);
      pantoGreenState = 0;
    }
    else
    {
      pantoSelected = 0;
      pantoSelectedMap.forEach((k, v) -> {
        if (v == 1)
        {
          pantoSelected = 1;
        }
      });
      setApplicationOutputsProperty(IAppOutputsHighVolatageSystemCommandsScreenProperties.RISE_SELECTED_PANTO,
          pantoSelected);
    }
  }

  private void vcbOpenReq(int reqValue)
  {
    reqValue = reqValue == 1 ? 1 : 0;
    for (int carInd = 0; carInd < sharedDataModel.getTotalCar(); carInd++)
    {
      if (vehicleInputsHandler != null)
      {
        vehicleInputsHandler = (ITCMSVehicleInputsHVCommandHandler)getTCMSVehicleInputsSetter(carInd);
        vehicleInputsHandler.setTcmsVcbOpenReq(reqValue);
      }
    }
  }

  private void vcbCloseReq(int reqValue)
  {
    reqValue = reqValue == 1 ? 1 : 0;
    for (int carInd = 0; carInd < sharedDataModel.getTotalCar(); carInd++)
    {
      if (vehicleInputsHandler != null)
      {
        vehicleInputsHandler = (ITCMSVehicleInputsHVCommandHandler)getTCMSVehicleInputsSetter(carInd);
        vehicleInputsHandler.setTcmsVcbCloseReq(reqValue);
      }
    }
  }

  private void reqCtrlVcbNs(int reqValue)
  {
    setApplicationOutputsProperty(IAppOutputsHighVolatageSystemCommandsScreenProperties.REQ_VCB_NS_STATUS,
        reqValue);
    for (int carInd = 0; carInd < sharedDataModel.getTotalCar(); carInd++)
    {
      if (vehicleInputsHandler != null)
      {
        vehicleInputsHandler = (ITCMSVehicleInputsHVCommandHandler)getTCMSVehicleInputsSetter(carInd);
        vehicleInputsHandler.setTcmsReqCtrlVcbNs(reqValue);
      }
    }
  }

  private void pantoLowerReq(Integer carIndex)
  {
    pantoSelectedMap.clear();
    if (carIndex == -1)
    {
     
      for (int carInd = 0; carInd < sharedDataModel.getTotalCar(); carInd++)
      {
        if (vehicleInputsHandler != null)
        {
          vehicleInputsHandler = (ITCMSVehicleInputsHVCommandHandler)getTCMSVehicleInputsSetter(carInd);
          vehicleInputsHandler.setTcmsPantoLowerReq(0);
          pantoSelectedMap.put(carInd, 0);
        }
      }
    }
    else if (carIndex < sharedDataModel.getTotalCar())
    {
   
      if (vehicleInputsHandler != null)
      {
        vehicleInputsHandler = (ITCMSVehicleInputsHVCommandHandler)getTCMSVehicleInputsSetter(carIndex);
        vehicleInputsHandler.setTcmsPantoLowerReq(1);
      }
    }
    else
    {
     
      for (int carInd = 0; carInd < sharedDataModel.getTotalCar(); carInd++)
      {
        if (vehicleInputsHandler != null)
        {
          vehicleInputsHandler = (ITCMSVehicleInputsHVCommandHandler)getTCMSVehicleInputsSetter(carInd);
          vehicleInputsHandler.setTcmsPantoLowerReq(1);
          pantoSelectedMap.put(carInd, 0);
        }
      }
    }
    
  
  }

  private void pantoRiseSelectedReq(Integer req)
  {
    if (req == 1)
    {
      pantoSelectedMap.forEach((carIndex, value) -> {
        vehicleInputsHandler = (ITCMSVehicleInputsHVCommandHandler)getTCMSVehicleInputsSetter(carIndex);
        vehicleInputsHandler.setTcmsPantoRiseReq(value);
      });
    }
    else
    {
      pantoSelectedMap.forEach((carIndex, value) -> {
        vehicleInputsHandler = (ITCMSVehicleInputsHVCommandHandler)getTCMSVehicleInputsSetter(carIndex);
        vehicleInputsHandler.setTcmsPantoRiseReq(0);
      });
    }
    
  
  }

  private void initalizeVehicleInputHandler()
  {
    if (vehicleInputsHandler == null)
    {
      vehicleInputsHandler = (ITCMSVehicleInputsHVCommandHandler)getTCMSVehicleInputsSetter(
          getActiveVehicleIndex());
    }
  }

  @Override
  public void attachListeners()
  {
    super.attachListeners();

    initalizeVehicleInputHandler();
  }

 
 

}