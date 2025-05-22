/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.papis.fe.gui.model;

import com.google.protobuf.InvalidProtocolBufferException;
import com.sydac.common.log.Tracer;
import com.sydac.mmrbem.cabscreens.fe.gui.model.AbstractScreenModel;
import com.sydac.mmrbem.papis.common.data.SpecialInfoDetailModel;
import com.sydac.mmrbem.papis.common.protos.PAPISProtos;
import com.sydac.mmrbem.papis.common.protos.PAPISProtos.SpcInfoList;
import com.sydac.mmrbem.papis.common.protos.PAPISProtos.SpcInfoList.SpcInfoDetail;

import javafx.beans.property.IntegerProperty;
import javafx.beans.property.ListProperty;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleListProperty;
import javafx.collections.FXCollections;

public class SpecialInformationScreenModel extends AbstractScreenModel
{

  private ListProperty<SpecialInfoDetailModel> spcInfoDetailList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private IntegerProperty specialMessageSelected = new SimpleIntegerProperty();

  private SpcInfoList spcInfoList;

  public SpecialInformationScreenModel(int carIndex)
  {
    super(carIndex);
  }

  public void setSpcInfoList(byte[] spcInfolist)
  {
    if (spcInfolist.length != 0)
    {
      try
      {
        this.spcInfoList = PAPISProtos.SpcInfoList.parseFrom(spcInfolist);

        updateSpcInfoList();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public ListProperty<SpecialInfoDetailModel> getSpcInfoDetailList()
  {
    return spcInfoDetailList;
  }

  private void updateSpcInfoList()
  {
    if (spcInfoList != null)
    {
      spcInfoDetailList.clear();
      for (SpcInfoDetail spcInfoDetail : this.spcInfoList.getSpcInfoDetailList())
      {
        spcInfoDetailList
            .add(new SpecialInfoDetailModel(spcInfoDetail.getSpcInfoId(), spcInfoDetail.getSpcInfoCode()));
      }
    }
  }

  public IntegerProperty getSpecialMessageSelected()
  {
    return specialMessageSelected;
  }

  public void setSpecialMessageSelected(Integer newValue)
  {
    specialMessageSelected.set(newValue);
  }
}
