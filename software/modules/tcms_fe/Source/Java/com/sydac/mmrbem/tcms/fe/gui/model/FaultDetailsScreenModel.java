/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.fe.gui.model;

import java.text.SimpleDateFormat;
import java.util.TimeZone;

import com.google.protobuf.InvalidProtocolBufferException;
import com.sydac.common.log.Tracer;
import com.sydac.mmrbem.cabscreens.fe.gui.model.AbstractScreenModel;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;

import javafx.beans.property.IntegerProperty;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;

public class FaultDetailsScreenModel extends AbstractScreenModel
{
  private final StringProperty faultSystem = new SimpleStringProperty(""); //$NON-NLS-1$

  private final StringProperty faultComponent = new SimpleStringProperty(""); //$NON-NLS-1$

  private final StringProperty faultCar = new SimpleStringProperty(""); //$NON-NLS-1$

  private final StringProperty faultCode = new SimpleStringProperty(""); //$NON-NLS-1$

  private final StringProperty faultDateTime = new SimpleStringProperty(""); //$NON-NLS-1$

  private final StringProperty faultPriority = new SimpleStringProperty(""); //$NON-NLS-1$

  private final StringProperty faultDescription = new SimpleStringProperty(""); //$NON-NLS-1$

  private final StringProperty operatorGuide = new SimpleStringProperty(""); //$NON-NLS-1$

  private IntegerProperty closeToPreviousScreenId = new SimpleIntegerProperty();

  public FaultDetailsScreenModel(int carIndex)
  {
    super(carIndex);
  }

  public void setFaultDetailsInfo(byte[] faultDetail)
  {
    try
    {
      if (faultDetail.length != 0)
      {
        TCMSProto.ActiveFaultsList.FaultsStatus faultInfo = TCMSProto.ActiveFaultsList.parseFrom(faultDetail)
            .getFaults(0);
        
        // converting the time to GMT time zone.
        SimpleDateFormat sdf = new SimpleDateFormat("yyyy/MM/dd HH:mm:ss");
        sdf.setTimeZone(TimeZone.getTimeZone("GMT"));
        String dateTime = sdf.format(new java.util.Date(faultInfo.getFaultOccurrenceDateTime()));
        
        faultSystem.set(faultInfo.getFaultSystemName());
        faultComponent.set(faultInfo.getFaultComponenet());
        faultCar.set(String.valueOf(faultInfo.getCarIndex()));
        setFaultCode(faultInfo.getFaultCode());
        faultDateTime.set(dateTime);
        faultPriority.set(String.valueOf(faultInfo.getFaultLevel()));
        faultDescription.set(faultInfo.getFaultDescription());
        operatorGuide.set(faultInfo.getOperatorGuide().replace(";", "\n")); //$NON-NLS-1$ //$NON-NLS-2$
      }
    }
    catch (InvalidProtocolBufferException e)
    {
      Tracer.getInstance().error(e);
    }

  }

  private void setFaultCode(String code)
  {
    String tempFaultCode = code;
    if (code.length() == 6)
    {
      this.faultCode.set(code);
    }
    else
    {
      do
      {
        tempFaultCode = "0".concat(tempFaultCode); //$NON-NLS-1$
      } while (tempFaultCode.length() < 6);
      this.faultCode.set(tempFaultCode);
    }
  }

  public StringProperty getFaultSystem()
  {
    return faultSystem;
  }

  public StringProperty getFaultComponent()
  {
    return faultComponent;
  }

  public StringProperty getFaultCar()
  {
    return faultCar;
  }

  public StringProperty getFaultCode()
  {
    return faultCode;
  }

  public StringProperty getFaultDateTime()
  {
    return faultDateTime;
  }

  public StringProperty getFaultPriority()
  {
    return faultPriority;
  }

  public StringProperty getFaultDescription()
  {
    return faultDescription;
  }

  public StringProperty getOperatorGuide()
  {
    return operatorGuide;
  }

  public IntegerProperty getCloseToPreviousScreenId()
  {
    return closeToPreviousScreenId;
  }

  public void setCloseToPreviousScreenId(Integer closeToPreviousScreenId)
  {
    this.closeToPreviousScreenId.set(closeToPreviousScreenId);
  }
}
