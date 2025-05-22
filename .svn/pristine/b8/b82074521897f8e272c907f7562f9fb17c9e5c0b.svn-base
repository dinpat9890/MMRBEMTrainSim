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
import com.sydac.common.febe.frontend.gui.AbstractScreenModel;
import com.sydac.common.log.Tracer;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.utils.UnitConverterHelper;
import com.sydac.mmrbem.tcms.fe.gui.data.TestScreenTableDO;

import javafx.beans.property.IntegerProperty;
import javafx.beans.property.ListProperty;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleListProperty;
import javafx.collections.FXCollections;

public class TestSystemScreenModel extends AbstractScreenModel
{

  private IntegerProperty totalPageNumber = new SimpleIntegerProperty(1);

  private IntegerProperty currentPageNumber = new SimpleIntegerProperty(1);

  private IntegerProperty totalTestStatus = new SimpleIntegerProperty();

  private IntegerProperty selectedTestStatusIndex = new SimpleIntegerProperty();

  private ListProperty<TestScreenTableDO> activeTestStatusList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  public ListProperty<TestScreenTableDO> getActiveTestStatusList()
  {
    return activeTestStatusList;
  }

  public void setActiveTestStatusList(ListProperty<TestScreenTableDO> activeTestStatusList)
  {
    this.activeTestStatusList = activeTestStatusList;
  }

  public void setActiveTestStatusList(byte[] activeTestStatusList)
  {
    try
    {

      this.activeTestStatusList.clear();

      if (activeTestStatusList.length != 0)
      {

        this.activeTestStatusList.addAll(FXCollections.observableArrayList(TCMSProto.TestSystemStatusList
            .parseFrom(activeTestStatusList).getTestSystemStatusList().stream()
            .map(test -> new TestScreenTableDO(test.getId(), test.getCarIndex(), test.getComponenetName(),
                test.getTestStatus(), UnitConverterHelper.convertTime(test.getLastUpdateDate()),
                UnitConverterHelper.convertTime(test.getLastUpdateTime())))
            .collect(Collectors.toList())));
      }

    }
    catch (InvalidProtocolBufferException e)
    {
      Tracer.getInstance().error(e);
    }
  }

  public TestSystemScreenModel(int carIndex)
  {
    super(carIndex);
  }

  public IntegerProperty getTotalPageNumber()
  {
    return totalPageNumber;
  }

  public IntegerProperty getCurrentPageNumber()
  {
    return currentPageNumber;
  }

  public IntegerProperty getTotalTestStatus()
  {
    return totalTestStatus;
  }

  public IntegerProperty getSelectedTestStatusIndex()
  {
    return selectedTestStatusIndex;
  }

  public void setTotalPageNumber(Integer totalPageNumber)
  {
    this.totalPageNumber.set(totalPageNumber);
  }

  public void setCurrentPageNumber(Integer currentPageNumber)
  {
    this.currentPageNumber.set(currentPageNumber);
  }

  public void setTotalTestStatus(Integer totalTestStatus)
  {
    this.totalTestStatus.set(totalTestStatus);
  }

  public void setSelectedTestStatusIndex(Integer selectedTestStatusIndex)
  {
    this.selectedTestStatusIndex.set(selectedTestStatusIndex);
  }

}
