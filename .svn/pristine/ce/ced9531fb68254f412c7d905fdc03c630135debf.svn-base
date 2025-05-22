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
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.DerailmentStatusList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.DerailmentStatusList.DerailmentStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.ObstrectionStatusList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.ObstrectionStatusList.ObstrectionStatus;

import javafx.beans.property.IntegerProperty;
import javafx.beans.property.SimpleIntegerProperty;

public class MiscellaniaScreenModel extends AbstractScreenModel
{
  private IntegerProperty hornIsolateReinsertFrontStatus = new SimpleIntegerProperty();

  private IntegerProperty hornIsolateReinsertRearStatus = new SimpleIntegerProperty();

  private IntegerProperty firstCarDerailmentLeft = new SimpleIntegerProperty();

  private IntegerProperty lastCarDerailmentLeft = new SimpleIntegerProperty();

  private IntegerProperty firstCarDerailmentRight = new SimpleIntegerProperty();

  private IntegerProperty lastCarDerailmentRight = new SimpleIntegerProperty();

  private IntegerProperty firstCarObstrectionLeft = new SimpleIntegerProperty();

  private IntegerProperty lastCarObstrectionLeft = new SimpleIntegerProperty();

  private IntegerProperty firstCarObstrectionRight = new SimpleIntegerProperty();

  private IntegerProperty lastCarObstrectionRight = new SimpleIntegerProperty();

  private DerailmentStatusList derailmentStatusListLeft;

  private DerailmentStatusList derailmentStatusListRight;

  private ObstrectionStatusList obstrectionStatusListLeft;

  private ObstrectionStatusList obstrectionStatusListRight;

  public MiscellaniaScreenModel(int carIndex)
  {
    super(carIndex);

  }

  public IntegerProperty getHornIsolateReinsertFrontStatus()
  {
    return hornIsolateReinsertFrontStatus;
  }

  public void setHornIsolateReinsertFrontStatus(Integer hornIsolateReinsertFrontStatus)
  {
    this.hornIsolateReinsertFrontStatus.set(hornIsolateReinsertFrontStatus);
  }

  public IntegerProperty getHornIsolateReinsertRearStatus()
  {
    return hornIsolateReinsertRearStatus;
  }

  public void setHornIsolateReinsertRearStatus(Integer hornIsolateReinsertRearStatus)
  {
    this.hornIsolateReinsertRearStatus.set(hornIsolateReinsertRearStatus);
  }

  public void setDerailmentDetectedLeftState(byte[] newValue)
  {

    if (newValue.length != 0)
    {

      try
      {
        derailmentStatusListLeft = TCMSProto.DerailmentStatusList.parseFrom(newValue);
        updateDerailmentDetectedLeft();

      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }

  }

  private void updateDerailmentDetectedLeft()
  {
    if (derailmentStatusListLeft != null)
    {

      for (DerailmentStatus statusTableDO : derailmentStatusListLeft.getDerailmentStatusList())
      {

        if (statusTableDO.getCarIndex() == 0)
        {
          setFirstCarDerailmentLeft(statusTableDO.getMiscState().getNumber());
        }
        else if (statusTableDO.getCarIndex() == 5 || statusTableDO.getCarIndex() == 7)
        {

          setLastCarDerailmentLeft(statusTableDO.getMiscState().getNumber());
        }

      }
    }
  }

  private void updateDerailmentDetectedRight()
  {
    if (derailmentStatusListRight != null)
    {

      for (DerailmentStatus statusTableDO : derailmentStatusListRight.getDerailmentStatusList())
      {

        if (statusTableDO.getCarIndex() == 0)
        {
          setFirstCarDerailmentRight(statusTableDO.getMiscState().getNumber());
        }
        else if (statusTableDO.getCarIndex() == 5 || statusTableDO.getCarIndex() == 7)
        {

          setLastCarDerailmentRight(statusTableDO.getMiscState().getNumber());
        }

      }
    }
  }

  public void setDerailmentDetectedRightState(byte[] newValue)
  {

    if (newValue.length != 0)
    {
      try
      {
        derailmentStatusListRight = TCMSProto.DerailmentStatusList.parseFrom(newValue);
        updateDerailmentDetectedRight();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }

  }

  public void setObstructionDetectedLeftState(byte[] newValue)
  {

    if (newValue.length != 0)
    {
      try
      {
        obstrectionStatusListLeft = TCMSProto.ObstrectionStatusList.parseFrom(newValue);
        updateObstructionDetectedLeft();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  private void updateObstructionDetectedRight()
  {

    if (obstrectionStatusListRight != null)
    {

      for (ObstrectionStatus statusTableDO : obstrectionStatusListRight.getObstrectionStatusList())
      {

        if (statusTableDO.getCarIndex() == 0)
        {
          setFirstCarObstrectionRight(statusTableDO.getMiscState().getNumber());
        }
        else if (statusTableDO.getCarIndex() == 5 || statusTableDO.getCarIndex() == 7)
        {

          setLastCarObstrectionRight(statusTableDO.getMiscState().getNumber());
        }

      }
    }

  }

  public void setObstructionDetectedRightState(byte[] newValue)
  {

    if (newValue.length != 0)
    {
      try
      {
        obstrectionStatusListRight = TCMSProto.ObstrectionStatusList.parseFrom(newValue);
        updateObstructionDetectedRight();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }

  }

  private void updateObstructionDetectedLeft()
  {

    if (obstrectionStatusListLeft != null)
    {

      for (ObstrectionStatus statusTableDO : obstrectionStatusListLeft.getObstrectionStatusList())
      {

        if (statusTableDO.getCarIndex() == 0)
        {
          setFirstCarObstrectionLeft(statusTableDO.getMiscState().getNumber());
        }
        else if (statusTableDO.getCarIndex() == 5 || statusTableDO.getCarIndex() == 7)
        {

          setLastCarObstrectionLeft(statusTableDO.getMiscState().getNumber());
        }

      }
    }

  }

  public IntegerProperty getLastCarObstrectionLeft()
  {
    return lastCarObstrectionLeft;
  }

  public IntegerProperty getFirstCarObstrectionLeft()
  {
    return firstCarObstrectionLeft;
  }

  private void setLastCarObstrectionLeft(int number)
  {
    this.lastCarObstrectionLeft.set(number);

  }

  private void setFirstCarObstrectionLeft(int number)
  {
    this.firstCarObstrectionLeft.set(number);

  }

  public IntegerProperty getLastCarObstrectionRight()
  {
    return lastCarObstrectionRight;
  }

  public IntegerProperty getFirstCarObstrectionRight()
  {
    return firstCarObstrectionRight;
  }

  private void setLastCarObstrectionRight(int number)
  {
    this.lastCarObstrectionRight.set(number);

  }

  private void setFirstCarObstrectionRight(int number)
  {
    this.firstCarObstrectionRight.set(number);

  }

  public IntegerProperty getFirstCarDerailmentLeft()
  {
    return firstCarDerailmentLeft;
  }

  public void setFirstCarDerailmentLeft(Integer id)
  {
    this.firstCarDerailmentLeft.set(id);
  }

  public IntegerProperty getLastCarDerailmentLeft()
  {
    return lastCarDerailmentLeft;
  }

  public void setLastCarDerailmentLeft(Integer id)
  {
    this.lastCarDerailmentLeft.set(id);
  }

  public IntegerProperty getFirstCarDerailmentRight()
  {
    return firstCarDerailmentRight;
  }

  public void setFirstCarDerailmentRight(Integer id)
  {
    this.firstCarDerailmentRight.set(id);
  }

  public IntegerProperty getLastCarDerailmentRight()
  {
    return lastCarDerailmentRight;
  }

  public void setLastCarDerailmentRight(Integer id)
  {
    this.lastCarDerailmentRight.set(id);
  }

}
