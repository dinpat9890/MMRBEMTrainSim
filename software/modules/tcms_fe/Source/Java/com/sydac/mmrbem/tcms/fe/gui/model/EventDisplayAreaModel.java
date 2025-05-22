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

import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;

import com.google.protobuf.InvalidProtocolBufferException;
import com.sydac.common.log.Tracer;
import com.sydac.mmrbem.cabscreens.fe.gui.model.AbstractScreenModel;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.fe.gui.data.EventAreaDO;

import javafx.beans.property.BooleanProperty;
import javafx.beans.property.IntegerProperty;
import javafx.beans.property.ListProperty;
import javafx.beans.property.SimpleBooleanProperty;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleListProperty;
import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;
import javafx.collections.FXCollections;

public class EventDisplayAreaModel extends AbstractScreenModel
{
  private final StringProperty faultSystem = new SimpleStringProperty();

  private final StringProperty faultCar = new SimpleStringProperty();

  private final StringProperty faultCode = new SimpleStringProperty();

  private final IntegerProperty faultPriority = new SimpleIntegerProperty();

  private final StringProperty faultDescription = new SimpleStringProperty();

  private BooleanProperty firstFaultInfo = new SimpleBooleanProperty();

  private ListProperty<EventAreaDO> incomingFaultsList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  public EventDisplayAreaModel(int carIndex)
  {
    super(carIndex);
  }

  public void setFaultDetailsInfo(byte[] faultDetail)
  {
    try
    {
      if (faultDetail.length != 0)
      {
        incomingFaultsList.clear();
        for (TCMSProto.ActiveFaultsList.FaultsStatus faultInfo : TCMSProto.ActiveFaultsList
            .parseFrom(faultDetail).getFaultsList())
        {
          incomingFaultsList.add(new EventAreaDO(faultInfo.getCarIndex(), faultInfo.getFaultCode(),
              faultInfo.getFaultLevel(), faultInfo.getFaultSystemName(), faultInfo.getFaultDescription(),
              faultInfo.getFaultOccurrenceDateTime(), faultInfo.getAcknowledged()));
        }

        List<EventAreaDO> faultTimeSorted = incomingFaultsList.stream()
            .sorted(Comparator.comparingLong(EventAreaDO::getFaultOccuranceDateTime).reversed())
            .collect(Collectors.toList());

        List<EventAreaDO> faultLevelSorted = faultTimeSorted.stream()
            .sorted(Comparator.comparingInt(EventAreaDO::getFaultLevel)).collect(Collectors.toList());

        incomingFaultsList.clear();
        incomingFaultsList.addAll(faultLevelSorted);

        if (!incomingFaultsList.isEmpty())
        {
          updateEventDisplayFields(faultLevelSorted.get(0));
          firstFaultInfo.set(true);
        }
        else
        {
          firstFaultInfo.set(false);
        }

      }
      else
      {
        firstFaultInfo.set(false);
      }
    }
    catch (InvalidProtocolBufferException e)
    {
      Tracer.getInstance().error(e);
    }
  }

  private void updateEventDisplayFields(EventAreaDO eventAreaDO)
  {
    faultSystem.set(eventAreaDO.getFaultSystemName().get());
    faultCar.set(eventAreaDO.getCarCode().get());
    faultCode.set(eventAreaDO.getFaultCode().get());
    faultPriority.set(eventAreaDO.getFaultLevel());
    faultDescription.set(eventAreaDO.getFaultDescription().get());
  }

  public ListProperty<EventAreaDO> getIncomingFaultsList()
  {
    return incomingFaultsList;
  }

  public void setIncomingFaultsList(ListProperty<EventAreaDO> incomingFaultsList)
  {
    this.incomingFaultsList = incomingFaultsList;
  }

  public StringProperty getFaultSystem()
  {
    return faultSystem;
  }

  public StringProperty getFaultCar()
  {
    return faultCar;
  }

  public StringProperty getFaultCode()
  {
    return faultCode;
  }

  public IntegerProperty getFaultPriority()
  {
    return faultPriority;
  }

  public StringProperty getFaultDescription()
  {
    return faultDescription;
  }

  public BooleanProperty getFirstFaultInfo()
  {
    return firstFaultInfo;
  }

  public void setFirstFaultInfo(Boolean firstFaultInfo)
  {
    this.firstFaultInfo.set(firstFaultInfo);
  }
}
