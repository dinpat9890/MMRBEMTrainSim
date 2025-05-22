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
import java.util.Date;
import java.util.TimeZone;

import com.google.protobuf.InvalidProtocolBufferException;
import com.sydac.common.log.Tracer;
import com.sydac.mmrbem.cabscreens.fe.gui.model.AbstractScreenModel;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.ActiveFaultsList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.ActiveFaultsList.FaultsStatus;
import com.sydac.mmrbem.tcms.fe.gui.data.FaultsTableDO;

import javafx.beans.property.IntegerProperty;
import javafx.beans.property.ListProperty;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleListProperty;
import javafx.collections.FXCollections;

public class ActiveFaultsScreenModel extends AbstractScreenModel
{
  private IntegerProperty totalPageNumber = new SimpleIntegerProperty(1);

  private IntegerProperty currentPageNumber = new SimpleIntegerProperty(1);

  private IntegerProperty totalActiveFaults = new SimpleIntegerProperty();

  private IntegerProperty selectedFaultIndex = new SimpleIntegerProperty();

  private IntegerProperty faultListUpdateAvailable = new SimpleIntegerProperty();

  private IntegerProperty appliedSystemFilterId = new SimpleIntegerProperty();

  private IntegerProperty appliedCarFilterId = new SimpleIntegerProperty();

  private IntegerProperty appliedPriorityFilterId = new SimpleIntegerProperty();

  private IntegerProperty pageUpActive = new SimpleIntegerProperty();

  private IntegerProperty pageDownActive = new SimpleIntegerProperty();

  private ListProperty<FaultsTableDO> activeFaultsTableDO = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ActiveFaultsList activeFaultsProtoList;

  public ListProperty<FaultsTableDO> getActiveFaultsList()
  {
    return activeFaultsTableDO;
  }

  public ActiveFaultsScreenModel(int carIndex)
  {
    super(carIndex);
  }

  public void setActiveFaultsList(byte[] activeFaultsList)
  {
    if (activeFaultsList.length != 0)
    {
      try
      {
        activeFaultsProtoList = TCMSProto.ActiveFaultsList.parseFrom(activeFaultsList);
        updateActiveFaults();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
    else
    {
      activeFaultsProtoList = null;
      updateActiveFaults();
    }
  }

  private void updateActiveFaults()
  {
    activeFaultsTableDO.clear();
    if (activeFaultsProtoList != null)
    {
      for (FaultsStatus statusTableDO : activeFaultsProtoList.getFaultsList())
      {
        SimpleDateFormat sdf = new SimpleDateFormat("yyyy/MM/dd HH:mm:ss");
        sdf.setTimeZone(TimeZone.getTimeZone("GMT"));
        String dateTime = sdf.format(new Date(statusTableDO.getFaultOccurrenceDateTime()));

        activeFaultsTableDO.add(0,
            new FaultsTableDO(statusTableDO.getId(), statusTableDO.getFaultId(), statusTableDO.getCarIndex(),
                statusTableDO.getFaultCode(), statusTableDO.getFaultLevel(),
                statusTableDO.getFaultSystemName(), statusTableDO.getFaultDescription(), dateTime,
                statusTableDO.getFaultComponenet(), statusTableDO.getOperatorGuide(),
                statusTableDO.getAcknowledged()));
      }
    }
    else
    {
      activeFaultsTableDO.clear();
    }
  }

  public IntegerProperty getTotalPageNumber()
  {
    return totalPageNumber;
  }

  public IntegerProperty getCurrentPageNumber()
  {
    return currentPageNumber;
  }

  public IntegerProperty getSelectedFaultIndex()
  {
    return selectedFaultIndex;
  }

  public IntegerProperty getTotalActiveFaults()
  {
    return totalActiveFaults;
  }

  public void setTotalPageNumber(Integer totalPageNumber)
  {
    this.totalPageNumber.set(totalPageNumber);
  }

  public void setCurrentPageNumber(Integer currentPageNumber)
  {
    this.currentPageNumber.set(currentPageNumber);
  }

  public void setSelectedFaultIndex(Integer selectedFaultIndex)
  {
    this.selectedFaultIndex.set(selectedFaultIndex);
  }

  public void setTotalActiveFaults(Integer totalActiveFaults)
  {
    this.totalActiveFaults.set(totalActiveFaults);
  }

  public IntegerProperty getFaultListUpdateAvailable()
  {
    return faultListUpdateAvailable;
  }

  public void setFaultListUpdateAvailable(Integer faultListUpdateAvailable)
  {
    this.faultListUpdateAvailable.set(faultListUpdateAvailable);
  }

  public IntegerProperty getAppliedSystemFilterId()
  {
    return appliedSystemFilterId;
  }

  public void setAppliedSystemFilterId(Integer appliedSystemFilterId)
  {
    this.appliedSystemFilterId.set(appliedSystemFilterId);
  }

  public IntegerProperty getAppliedCarFilterId()
  {
    return appliedCarFilterId;
  }

  public void setAppliedCarFilterId(Integer appliedCarFilterId)
  {
    this.appliedCarFilterId.set(appliedCarFilterId);
  }

  public IntegerProperty getAppliedPriorityFilterId()
  {
    return appliedPriorityFilterId;
  }

  public void setAppliedPriorityFilterId(Integer appliedPriorityFilterId)
  {
    this.appliedPriorityFilterId.set(appliedPriorityFilterId);
  }

  public IntegerProperty getPageUpActive()
  {
    return pageUpActive;
  }

  public void setPageUpActive(Integer pageUpActive)
  {
    this.pageUpActive.set(pageUpActive);
  }

  public IntegerProperty getPageDownActive()
  {
    return pageDownActive;
  }

  public void setPageDownActive(Integer pageDownActive)
  {
    this.pageDownActive.set(pageDownActive);
  }
}
