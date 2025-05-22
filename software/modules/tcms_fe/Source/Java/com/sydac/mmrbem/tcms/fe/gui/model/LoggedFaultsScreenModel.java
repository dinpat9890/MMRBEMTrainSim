/*
 * ==================================================================
 * 
 * (C) Copyright 2023 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.fe.gui.model;

import com.google.protobuf.InvalidProtocolBufferException;
import com.sydac.common.log.Tracer;
import com.sydac.mmrbem.cabscreens.fe.gui.model.AbstractScreenModel;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.LoggedFaultsList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.LoggedFaultsList.LoggedFaultsStatus;
import com.sydac.mmrbem.tcms.fe.gui.data.LoggedFaultsTableDO;

import javafx.beans.property.IntegerProperty;
import javafx.beans.property.ListProperty;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleListProperty;
import javafx.collections.FXCollections;

public class LoggedFaultsScreenModel extends AbstractScreenModel
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

  private ListProperty<LoggedFaultsTableDO> loggedFaultsTableDO = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private LoggedFaultsList loggedFaultsProtoList;

  public ListProperty<LoggedFaultsTableDO> getLoggedFaultsList()
  {
    return loggedFaultsTableDO;
  }

  public LoggedFaultsScreenModel(int carIndex)
  {
    super(carIndex);
  }

  public void setLoggedFaultsList(byte[] loggedFaultsList)
  {
    if (loggedFaultsList.length != 0)
    {
      try
      {
        loggedFaultsProtoList = TCMSProto.LoggedFaultsList.parseFrom(loggedFaultsList);
        updateLoggedFaults();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
    else
    {
      loggedFaultsProtoList = null;
      updateLoggedFaults();
    }
  }

  private void updateLoggedFaults()
  {
    loggedFaultsTableDO.clear();
    if (loggedFaultsProtoList != null)
    {
      for (LoggedFaultsStatus statusTableDO : loggedFaultsProtoList.getFaultsList())
      {
        String occuranceDateTime = new java.text.SimpleDateFormat("yyyy/MM/dd HH:mm:ss") //$NON-NLS-1$
            .format(new java.util.Date(statusTableDO.getFaultOccurrenceDateTime()));

        String clearanceDateTime = ""; //$NON-NLS-1$
        if (statusTableDO.getFaultClearanceDateTime() != 0)
        {
          clearanceDateTime = new java.text.SimpleDateFormat("yyyy/MM/dd HH:mm:ss") //$NON-NLS-1$
              .format(new java.util.Date(statusTableDO.getFaultClearanceDateTime()));
        }

        loggedFaultsTableDO.add(0,
            new LoggedFaultsTableDO(statusTableDO.getId(), statusTableDO.getFaultId(),
                statusTableDO.getCarIndex(), statusTableDO.getFaultCode(), statusTableDO.getFaultLevel(),
                statusTableDO.getFaultSystemName(), statusTableDO.getFaultDescription(), occuranceDateTime,
                clearanceDateTime, statusTableDO.getFaultComponenet(), statusTableDO.getOperatorGuide()));
      }
    }
    else
    {
      loggedFaultsTableDO.clear();
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
