/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.model;

import com.google.protobuf.InvalidProtocolBufferException;
import com.sydac.common.log.Tracer;
import com.sydac.mmrbem.cabscreens.fe.gui.model.AbstractScreenModel;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.EbInterlockData;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.EbInterlockData.EbInterlockStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.EbInterlockData.EbState;

import javafx.beans.property.IntegerProperty;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;

public class EmergencyBrakeInterlockScreenModel extends AbstractScreenModel
{
  private EbInterlockData ebInterlockData;

  private final StringProperty ebByCcState = new SimpleStringProperty(); // $NON-NLS-1$

  private final StringProperty ebByPushButtonFirstCarState = new SimpleStringProperty(); // $NON-NLS-1$

  private final StringProperty ebByPushButtonLastCarState = new SimpleStringProperty(); // $NON-NLS-1$

  private final StringProperty ebByEbByDeadmanFirstCarState = new SimpleStringProperty(); // $NON-NLS-1$

  private final StringProperty ebByEbByDeadmanLastCarState = new SimpleStringProperty(); // $NON-NLS-1$

  private final StringProperty ebByNonCabEnabledState = new SimpleStringProperty(); // $NON-NLS-1$

  private final StringProperty ebByNonDirectionSelectedState = new SimpleStringProperty(); // $NON-NLS-1$

  private final StringProperty ebEbByMcState = new SimpleStringProperty(); // $NON-NLS-1$

  private final StringProperty ebEbByBrakeLoopState = new SimpleStringProperty(); // $NON-NLS-1$

  private final StringProperty ebEbByAtcZeroSpeedState = new SimpleStringProperty(); // $NON-NLS-1$

  private final IntegerProperty lastVehicleId = new SimpleIntegerProperty(); // $NON-NLS-1$

  private final StringProperty masterControllerInFSBPositionState = new SimpleStringProperty();

  public EmergencyBrakeInterlockScreenModel(int carIndex)
  {
    super(carIndex);
  }

  public IntegerProperty getLastVehicleId()
  {
    return lastVehicleId;
  }

  public StringProperty getEbByCcState()
  {
    return ebByCcState;
  }

  public StringProperty getEbByPushButtonFirstState()
  {
    return ebByPushButtonFirstCarState;
  }

  public StringProperty getEbByPushButtonLastCarState()
  {
    return ebByPushButtonLastCarState;
  }

  public StringProperty getEbByPushButtonFirstCarState()
  {
    return ebByPushButtonFirstCarState;
  }

  public StringProperty getEbByEbByDeadmanFirstCarState()
  {
    return ebByEbByDeadmanFirstCarState;
  }

  public StringProperty getEbByEbByDeadmanLastCarState()
  {
    return ebByEbByDeadmanLastCarState;
  }

  public StringProperty getEbByNonCabEnabledState()
  {
    return ebByNonCabEnabledState;
  }

  public StringProperty getEbByNonDirectionSelectedState()
  {
    return ebByNonDirectionSelectedState;
  }

  public StringProperty getEbByMcState()
  {
    return ebEbByMcState;
  }

  public StringProperty getEbByBrakeLoopState()
  {
    return ebEbByBrakeLoopState;
  }

  public StringProperty getEbEbByAtcZeroSpeedState()
  {
    return ebEbByAtcZeroSpeedState;
  }

  public void setEbInterlockState(byte[] emergencyBrakeList)
  {
    if (emergencyBrakeList.length != 0)
    {
      try
      {
        ebInterlockData = TCMSProto.EbInterlockData.parseFrom(emergencyBrakeList);
        updateEmegencyBrakeState();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  private void updateEmegencyBrakeState()
  {
    if (ebInterlockData != null)
    {
      boolean isEbByCcOpen = false;
      boolean isEbByPushButtonFirstCar = false;
      boolean isEbByPushButtonLastCar = false;
      boolean isEbByNonCabEnabledOpen = false;
      boolean isEbByNonDirectionSelectedOpen = false;
      boolean isEbByMcOpen = false;
      boolean isEbByBrakeLoopOpen = false;
      boolean isEbByAtcZeroSpeedOpen = false;
      boolean isEbByDeadmanFirstCar = false;
      boolean isEbByDeadmanLastCar = false;
      boolean isMasterControllerInFsbPosition = false;
      for (EbInterlockStatus status : ebInterlockData.getEbInterlockStatusList())
      {
        if (status.getCarIndex() == 0 && EbState.OPEN.equals(status.getMasterControllerInFSB()))
        {
          isMasterControllerInFsbPosition = true;
        }
        if ((status.getCarIndex() == 0
            || status.getCarIndex() == ebInterlockData.getEbInterlockStatusList().size() - 1))
        {
          if (EbState.OPEN.equals(status.getEbByCc()))
          {
            isEbByCcOpen = true;
          }
          if (EbState.OPEN.equals(status.getEbByNonCabEnabled()))
          {
            isEbByNonCabEnabledOpen = true;
          }
          if (EbState.OPEN.equals(status.getEbByNonDirectionSelected()))
          {
            isEbByNonDirectionSelectedOpen = true;
          }
          if (EbState.OPEN.equals(status.getEbByMc()))
          {
            isEbByMcOpen = true;
          }
          if (EbState.OPEN.equals(status.getEbByBrakeLoop()))
          {
            isEbByBrakeLoopOpen = true;
          }
          if (EbState.OPEN.equals(status.getEbByAtcZeroSpeed()))
          {
            isEbByAtcZeroSpeedOpen = true;
          }
        }
        if ((status.getCarIndex() == 0) && (EbState.OPEN.equals(status.getEbByPushButton())))
        {
          isEbByPushButtonFirstCar = true;
        }
        else if ((status.getCarIndex() == ebInterlockData.getEbInterlockStatusList().size() - 1)
            && (EbState.OPEN.equals(status.getEbByPushButton())))
        {
          isEbByPushButtonLastCar = true;
        }
        if ((status.getCarIndex() == 0) && (EbState.OPEN.equals(status.getEbByDeadman())))
        {
          isEbByDeadmanFirstCar = true;
        }
        else if ((status.getCarIndex() == ebInterlockData.getEbInterlockStatusList().size() - 1)
            && (EbState.OPEN.equals(status.getEbByDeadman())))
        {
          isEbByDeadmanLastCar = true;
        }
      }
      lastVehicleId.setValue(ebInterlockData.getEbInterlockStatusList().size());

      updatedEbByCc(isEbByCcOpen);
      updateEbByPushButtonFirstCar(isEbByPushButtonFirstCar);
      updateEbByPushButtonLastCar(isEbByPushButtonLastCar);
      updatedEbByNonCabEnabled(isEbByNonCabEnabledOpen);
      updatedEbByNonDirectionSelected(isEbByNonDirectionSelectedOpen);
      updatedEbByMc(isEbByMcOpen);
      updatedEbByBrakeLoop(isEbByBrakeLoopOpen);
      updatedEbByAtcZeroSpeed(isEbByAtcZeroSpeedOpen);
      updateEbByDeadmanFirstCar(isEbByDeadmanFirstCar);
      updateEbByDeadmanLastCar(isEbByDeadmanLastCar);
      updateMasterControllerInFSBPosition(isMasterControllerInFsbPosition);
    }
  }

  private void updateMasterControllerInFSBPosition(boolean isMasterControllerInFsbPosition)
  {
    if (isMasterControllerInFsbPosition)
    {
      masterControllerInFSBPositionState.setValue(EbState.OPEN.toString().toLowerCase());
    }
    else
    {
      masterControllerInFSBPositionState.set(EbState.CLOSED.toString().toLowerCase());
    }
  }

  private void updateEbByDeadmanLastCar(boolean isEbOpen)
  {
    if (isEbOpen)
    {
      ebByEbByDeadmanLastCarState.setValue(EbState.OPEN.toString().toLowerCase());
    }
    else
    {
      ebByEbByDeadmanLastCarState.setValue(EbState.CLOSED.toString().toLowerCase());
    }
  }

  private void updateEbByDeadmanFirstCar(boolean isEbOpen)
  {

    if (isEbOpen)
    {
      ebByEbByDeadmanFirstCarState.setValue(EbState.OPEN.toString().toLowerCase());
    }
    else
    {
      ebByEbByDeadmanFirstCarState.setValue(EbState.CLOSED.toString().toLowerCase());
    }
  }

  private void updatedEbByAtcZeroSpeed(boolean isEbOpen)
  {
    if (isEbOpen)
    {
      ebEbByAtcZeroSpeedState.setValue(EbState.OPEN.toString().toLowerCase());
    }
    else
    {
      ebEbByAtcZeroSpeedState.setValue(EbState.CLOSED.toString().toLowerCase());
    }

  }

  private void updatedEbByBrakeLoop(boolean isEbOpen)
  {

    if (isEbOpen)
    {
      ebEbByBrakeLoopState.setValue(EbState.OPEN.toString().toLowerCase());
    }
    else
    {
      ebEbByBrakeLoopState.setValue(EbState.CLOSED.toString().toLowerCase());
    }

  }

  private void updatedEbByMc(boolean isEbOpen)
  {
    if (isEbOpen)
    {
      ebEbByMcState.setValue(EbState.OPEN.toString().toLowerCase());
    }
    else
    {
      ebEbByMcState.setValue(EbState.CLOSED.toString().toLowerCase());
    }
  }

  private void updatedEbByNonDirectionSelected(boolean isEbOpen)
  {
    if (isEbOpen)
    {
      ebByNonDirectionSelectedState.setValue(EbState.OPEN.toString().toLowerCase());
    }
    else
    {
      ebByNonDirectionSelectedState.setValue(EbState.CLOSED.toString().toLowerCase());
    }
  }

  private void updatedEbByNonCabEnabled(boolean isEbOpen)
  {
    if (isEbOpen)
    {
      ebByNonCabEnabledState.setValue(EbState.OPEN.toString().toLowerCase());
    }
    else
    {
      ebByNonCabEnabledState.setValue(EbState.CLOSED.toString().toLowerCase());
    }
  }

  private void updateEbByPushButtonLastCar(boolean isEbByPushButtonLastCar)
  {
    if (isEbByPushButtonLastCar)
    {
      ebByPushButtonLastCarState.setValue(EbState.OPEN.toString().toLowerCase());
    }
    else
    {
      ebByPushButtonLastCarState.setValue(EbState.CLOSED.toString().toLowerCase());
    }
  }

  private void updateEbByPushButtonFirstCar(boolean isEbByPushButtonFirstCar)
  {
    if (isEbByPushButtonFirstCar)
    {
      ebByPushButtonFirstCarState.setValue(EbState.OPEN.toString().toLowerCase());
    }
    else
    {
      ebByPushButtonFirstCarState.setValue(EbState.CLOSED.toString().toLowerCase());

    }
  }

  private void updatedEbByCc(boolean isEbByCcOpened)
  {
    if (isEbByCcOpened)
    {
      ebByCcState.setValue(EbState.OPEN.toString().toLowerCase());
    }
    else
    {
      ebByCcState.setValue(EbState.CLOSED.toString().toLowerCase());
    }
  }

  public StringProperty getMasterControllerInFSBPositionState()
  {
    return masterControllerInFSBPositionState;
  }
}
