/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.papis.fe.gui.model;

import com.google.protobuf.InvalidProtocolBufferException;
import com.sydac.common.log.Tracer;
import com.sydac.mmrbem.cabscreens.fe.gui.model.AbstractScreenModel;
import com.sydac.mmrbem.papis.common.data.EmergencyInfoDetailModel;
import com.sydac.mmrbem.papis.common.protos.PAPISProtos;
import com.sydac.mmrbem.papis.common.protos.PAPISProtos.EmgInfoList;
import com.sydac.mmrbem.papis.common.protos.PAPISProtos.EmgInfoList.EmgInfoDetail;

import javafx.beans.property.IntegerProperty;
import javafx.beans.property.ListProperty;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleListProperty;
import javafx.collections.FXCollections;

public class EmergencyInformationScreenModel extends AbstractScreenModel
{

  private ListProperty<EmergencyInfoDetailModel> emgInfoDetailList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private IntegerProperty emengencyInfromationSelected = new SimpleIntegerProperty();

  private EmgInfoList emgInfoList;

  public EmergencyInformationScreenModel(int carIndex)
  {
    super(carIndex);
  }

  public void setEmgInfoList(byte[] emgInfolist)
  {
    if (emgInfolist.length != 0)
    {
      try
      {
        this.emgInfoList = PAPISProtos.EmgInfoList.parseFrom(emgInfolist);

        updateEmgInfoList();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public ListProperty<EmergencyInfoDetailModel> getEmgInfoDetailList()
  {
    return emgInfoDetailList;
  }

  private void updateEmgInfoList()
  {
    if (emgInfoList != null)
    {
      emgInfoDetailList.clear();
      for (EmgInfoDetail emgInfoDetail : this.emgInfoList.getEmgInfoDetailList())
      {
        emgInfoDetailList
            .add(new EmergencyInfoDetailModel(emgInfoDetail.getEmgInfoId(), emgInfoDetail.getEmgInfoCode()));
      }
    }
  }

  public IntegerProperty getEmergencyInfromationSelected()
  {
    return emengencyInfromationSelected;
  }

  public void setEmergencyInformationSelected(Integer newValue)
  {
    emengencyInfromationSelected.set(newValue);
  }
}
