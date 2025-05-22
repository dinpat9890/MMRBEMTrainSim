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

import java.util.stream.Collectors;

import com.google.protobuf.InvalidProtocolBufferException;
import com.sydac.common.log.Tracer;
import com.sydac.mmrbem.cabscreens.fe.gui.model.AbstractScreenModel;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.fe.gui.data.EnergyConsumpCountersTableDO;

import javafx.beans.property.IntegerProperty;
import javafx.beans.property.ListProperty;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleListProperty;
import javafx.collections.FXCollections;

public class EnergyConsumptionCountersScreenModel extends AbstractScreenModel
{
  private IntegerProperty totalPageNumber = new SimpleIntegerProperty(1);

  private IntegerProperty currentPageNumber = new SimpleIntegerProperty(1);

  private IntegerProperty totalEnergyConsumpCounters = new SimpleIntegerProperty();

  private ListProperty<EnergyConsumpCountersTableDO> energyConsumptionCounterList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  public EnergyConsumptionCountersScreenModel(int carIndex)
  {
    super(carIndex);
    // TODO Auto-generated constructor stub
  }

  public void setEnergyConsumptionCounters(byte[] energyConsumptionCounterList)
  {
    try
    {
      this.energyConsumptionCounterList.clear();

      if (energyConsumptionCounterList.length != 0)
      {
        this.energyConsumptionCounterList
            .addAll(FXCollections.observableArrayList(TCMSProto.EnergyConsumpCountersList
                .parseFrom(energyConsumptionCounterList).getEnergyConsumpStatusList().stream()
                .map(counter -> new EnergyConsumpCountersTableDO(counter.getCounterName(),
                    counter.getDescription(), String.valueOf(counter.getCurrentValue()),
                    counter.getMeasurUnit()))
                .collect(Collectors.toList())));
      }
    }
    catch (InvalidProtocolBufferException e)
    {
      Tracer.getInstance().error(e);
    }
  }

  public ListProperty<EnergyConsumpCountersTableDO> getEnergyConsumptionCounterList()
  {
    return energyConsumptionCounterList;
  }

  public IntegerProperty getTotalPageNumber()
  {
    return totalPageNumber;
  }

  public IntegerProperty getCurrentPageNumber()
  {
    return currentPageNumber;
  }

  public IntegerProperty getTotalEnergyConsumpCounters()
  {
    return totalEnergyConsumpCounters;
  }

  public void setTotalPageNumber(Integer totalPageNumber)
  {
    this.totalPageNumber.set(totalPageNumber);
  }

  public void setCurrentPageNumber(Integer currentPageNumber)
  {
    this.currentPageNumber.set(currentPageNumber);
  }

  public void setTotalEnergyConsumpCounters(Integer totalEnergyConsumpCounters)
  {
    this.totalEnergyConsumpCounters.set(totalEnergyConsumpCounters);
  }
}
