/*
 * ==================================================================
 *
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *
 * ==================================================================
 */
package com.sydac.mmrbem.radiointercomplugin.model;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

import com.sydac.mmrbem.radio.enums.CabToCabCallType;
import com.sydac.mmrbem.radio.enums.CallDirection;
import com.sydac.mmrbem.radio.enums.RadioCallTypeState;
import com.sydac.peer.application.CObjectParentId;
import com.sydac.project.runtimedata.ProjectObjectConstants;
import com.sydac.project.runtimedata.ProjectObjectConstants.TypeValue.RadioCallType;
import com.sydac.simulatorcontroller.model.DynamicModel;

/**
 * This model contains dynamic information about On Train Communication in the
 * current session.
 * 
 * @author mulukg
 * 
 */
public abstract class RadioDataModel extends DynamicModel
{
  private final int vehicleIndex;

  private final int scenarioTrainId;

  private final int noOfVehicles;

  private Object MUTEX = new Object();

  private int selectedDialledNo;

  private int selectedCallType;

  private int selectedCallStatus;

  private int cabToCabCallStatus;

  private int ohpCallStatus;

  private int cabToCabCallType;

  private int cabOrSccCallStatus;

  private int radioOrSccCallStatus;

  private int selectedRadioGroup;

  private CObjectParentId radioIntercom;

  private CObjectParentId intercom;

  private CObjectParentId intercomInputs;

  private CObjectParentId intercomOutputs;

  private CObjectParentId radioIntercomInputValues;

  private CObjectParentId ohpInputs;

  private ExecutorService executorService = Executors.newSingleThreadExecutor();
  
  boolean ohpIdSet = false;

  protected RadioDataModel(int scenarioTrainId, int vehicleIndex, int noOfVehicles)
  {
    this.scenarioTrainId = scenarioTrainId;
    this.vehicleIndex = vehicleIndex;
    this.noOfVehicles = noOfVehicles;
  }

  public enum Change
  {
    /** Identifies that the Radio status has changed */
    COMMS_VALUE_CHANGED

  }

  @Override
  protected void onCreate()
  {
    if (scenarioTrainId != -1)
    {
      CObjectParentId train = new CObjectParentId(null, ProjectObjectConstants.ClassId.TRAIN,
          scenarioTrainId);

      radioIntercom = new CObjectParentId(train, ProjectObjectConstants.ClassId.RADIO_INTERCOM, vehicleIndex);

      intercom = new CObjectParentId(train, ProjectObjectConstants.ClassId.INTERCOM, vehicleIndex);

      intercomInputs = new CObjectParentId(intercom, ProjectObjectConstants.ClassId.INTERCOM_INPUTS,
          vehicleIndex);

      intercomOutputs = new CObjectParentId(intercom, ProjectObjectConstants.ClassId.INTERCOM_OUTPUTS,
          vehicleIndex);

      radioIntercomInputValues = new CObjectParentId(radioIntercom,
          ProjectObjectConstants.ClassId.RADIO_INTERCOM_INPUTS_VALUES, vehicleIndex);

      ohpInputs = new CObjectParentId(intercomInputs, ProjectObjectConstants.ClassId.OHP_INPUTS,
          vehicleIndex);

      getCommsManager().registerForNumber(radioIntercom,
          ProjectObjectConstants.ClassId.RADIO_INTERCOM_OUTPUTS, null,
          ProjectObjectConstants.RadioIntercomOutputs.SELECTED_RADIO_DIALLED_NO, 0.5, aNum -> {
            synchronized (MUTEX)
            {
              selectedDialledNo = aNum.getIntValue();
              fireModelChangedEvent(Change.COMMS_VALUE_CHANGED);
            }
          });

      getCommsManager().registerForNumber(radioIntercom,
          ProjectObjectConstants.ClassId.RADIO_INTERCOM_OUTPUTS, null,
          ProjectObjectConstants.RadioIntercomOutputs.SELECTED_RADIO_CALL_TYPE, 0.5, aNum -> {
            synchronized (MUTEX)
            {
              selectedCallType = aNum.getIntValue();
              fireModelChangedEvent(Change.COMMS_VALUE_CHANGED);
            }
          });

      getCommsManager().registerForNumber(radioIntercom,
          ProjectObjectConstants.ClassId.RADIO_INTERCOM_OUTPUTS, null,
          ProjectObjectConstants.RadioIntercomOutputs.SELECTED_RADIO_GROUP_CALL, 0.5, aNum -> {
            synchronized (MUTEX)
            {
              selectedRadioGroup = aNum.getIntValue();
              fireModelChangedEvent(Change.COMMS_VALUE_CHANGED);
            }
          });

      getCommsManager().registerForNumber(radioIntercom,
          ProjectObjectConstants.ClassId.RADIO_INTERCOM_OUTPUTS, null,
          ProjectObjectConstants.RadioIntercomOutputs.RADIO_INTERCOM_STATE, 0.5, aNum -> {
            synchronized (MUTEX)
            {
              selectedCallStatus = aNum.getIntValue();
              fireModelChangedEvent(Change.COMMS_VALUE_CHANGED);
            }
          });

      getCommsManager().registerForNumber(radioIntercom,
          ProjectObjectConstants.ClassId.RADIO_INTERCOM_OUTPUTS, null,
          ProjectObjectConstants.RadioIntercomOutputs.CAB_SCC, 0.5, aNum -> {
            synchronized (MUTEX)
            {
              radioOrSccCallStatus = aNum.getIntValue();
              fireModelChangedEvent(Change.COMMS_VALUE_CHANGED);
            }
          });

      getCommsManager().registerForNumber(intercom, ProjectObjectConstants.ClassId.INTERCOM_OUTPUTS, null,
          ProjectObjectConstants.IntercomOutputs.INTERCOM, 0.5, aNum -> {
            synchronized (MUTEX)
            {
              cabToCabCallStatus = aNum.getIntValue();
              fireModelChangedEvent(Change.COMMS_VALUE_CHANGED);
            }
          });

      getCommsManager().registerForNumber(intercom, ProjectObjectConstants.ClassId.INTERCOM_OUTPUTS, null,
          ProjectObjectConstants.IntercomOutputs.ACTIVE_CALL_TYPE, 0.5, aNum -> {
            synchronized (MUTEX)
            {
              cabToCabCallType = aNum.getIntValue();

              if (CabToCabCallType.ACTIVE_OHP_CALL.getValue() == cabToCabCallType
                  || CabToCabCallType.SCC_TO_CAB_CALL.getValue() == cabToCabCallType)
              {
                cabOrSccCallStatus = CallDirection.OUTGOING.getValue();
              }
              else
              {
                cabOrSccCallStatus = CallDirection.INCOMING.getValue();
              }

              fireModelChangedEvent(Change.COMMS_VALUE_CHANGED);
            }
          });

      getCommsManager().registerForNumber(intercomOutputs, ProjectObjectConstants.ClassId.OHP_OUTPUTS, null,
          ProjectObjectConstants.OHPOutputs.STATUS, 0.5, aNum -> {
            synchronized (MUTEX)
            {
              if (!ohpIdSet)
              {
              ohpCallStatus = aNum.getIntValue();
              fireModelChangedEvent(Change.COMMS_VALUE_CHANGED);
              }
            }
          });

      getCommsManager().registerForNumber(intercomOutputs, ProjectObjectConstants.ClassId.OHP_OUTPUTS, null,
          ProjectObjectConstants.OHPOutputs.OHP_ID, 0.5, aNum -> {
            synchronized (MUTEX)
            {
              ohpCallStatus = aNum.getIntValue();
              fireModelChangedEvent(Change.COMMS_VALUE_CHANGED);
              
             ohpIdSet =  (aNum.getIntValue() == 5);
            }
          });
    }
  }

  public int getRadioOrSccCallStatus()
  {
    return radioOrSccCallStatus;
  }

  public int getCabOrSccCallStatus()
  {
    return cabOrSccCallStatus;
  }

  public int getOhpCallStatus()
  {
    return ohpCallStatus;
  }

  public int getCabToCabCallStatus()
  {
    return cabToCabCallStatus;
  }

  public int getSelectedDialledNo()
  {
    return selectedDialledNo;
  }

  public int getSelectedCallType()
  {
    return selectedCallType;
  }

  public int getSelectedCallStatus()
  {
    return selectedCallStatus;
  }

  public int getCabToCabCallType()
  {
    return cabToCabCallType;
  }

  public int getSelectedRadioGroup()
  {
    return selectedRadioGroup;
  }

  /*
   * Calls a setNumber on the Comms Object.
   */
  private void sendPulse(CObjectParentId parent, String property)
  {
    getCommsManager().setNumber(parent, property, 1);
    executorService.submit(() -> {
      getCommsManager().setNumber(parent, property, 0);
    }, 500);
  }

  /*
   * Calls a setNumber on the Comms Object.
   */
  private void sendPulse(CObjectParentId parent, String property, int setValue, int resetValue)
  {
    getCommsManager().setNumber(parent, property, setValue);
    executorService.submit(() -> {
      getCommsManager().setNumber(parent, property, resetValue);
    }, 500);
  }

  /*
   * Calls a setNumber on the Comms Object.
   */
  private void sendValue(CObjectParentId parent, String property, int value)
  {
    getCommsManager().setNumber(parent, property, value);
  }

  public void acceptIncomingRadioCall()
  {
    sendPulse(radioIntercomInputValues, ProjectObjectConstants.RadioIntercomInputsValues.RADIO_SCC_INTERCOM);
  }

  public void endRadioCall()
  {
    sendPulse(radioIntercomInputValues, ProjectObjectConstants.RadioIntercomInputsValues.RADIO_SCC_CANCEL);
  }

  public void startSccCabToCabCall()
  {
    sendPulse(intercomInputs, ProjectObjectConstants.IntercomInputs.SCC_INTERCOM_BUTTON);
  }

  public void endSccCabToCabCall()
  {
    sendPulse(intercomInputs, ProjectObjectConstants.IntercomInputs.SCC_INTERCOM_CANCEL_BUTTON);
  }

  public void startOHPCall()
  {
    sendPulse(ohpInputs, ProjectObjectConstants.OHPInputs.OHP_BUTTON);
  }

  public void setOHPVehicleId(int vehicleId)
  {
    sendValue(ohpInputs, ProjectObjectConstants.OHPInputs.VEHICLE_ID, vehicleId);
  }

  public void setOHPId(int ohpId)
  {
    sendValue(ohpInputs, ProjectObjectConstants.OHPInputs.OHP_ID, ohpId);
  }

  public int getNoOfVehicles()
  {
    return noOfVehicles;
  }

  public void startRadioCall(RadioCallTypeState radioCallType)
  {
    int value = RadioCallType.RADIO_GROUP;

    String commsNum = ProjectObjectConstants.RadioIntercomInputsValues.RADIO_SCC_GROUP_CALL_REQ;

    if (RadioCallTypeState.EMERGENCY == radioCallType)
    {
      commsNum = ProjectObjectConstants.RadioIntercomInputsValues.RADIO_SCC_EMRGNCY_CALL_REQ;
      value = RadioCallType.RADIO_EMERGNECY;
    }
    else if (RadioCallTypeState.FULL_DUPLEX == radioCallType)
    {
      commsNum = ProjectObjectConstants.RadioIntercomInputsValues.RADIO_SCC_FULL_DUPLEX_CALL_REQ;
      value = RadioCallType.RADIO_FULL_DUPLEX;
    }
    else if (RadioCallTypeState.HALF_DUPLEX == radioCallType)
    {
      commsNum = ProjectObjectConstants.RadioIntercomInputsValues.RADIO_SCC_HALF_DUPLEX_CALL_REQ;
      value = RadioCallType.RADIO_HALF_DUPLEX;
    }

    sendPulse(radioIntercomInputValues, commsNum, 0, value);

  }

  public void startRadioGroupCall(int groupId)
  {

    String commsNum = ProjectObjectConstants.RadioIntercomInputsValues.RADIO_SCC_GROUP_CALL_REQ;

    sendPulse(radioIntercomInputValues, commsNum, 0, groupId);

  }

}