/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.papis.fe.gui.model;

import com.google.protobuf.InvalidProtocolBufferException;
import com.sydac.common.log.Tracer;
import com.sydac.mmrbem.cabscreens.fe.gui.model.AbstractScreenModel;
import com.sydac.mmrbem.papis.common.data.LineDetailModel;
import com.sydac.mmrbem.papis.common.protos.PAPISProtos;
import com.sydac.mmrbem.papis.common.protos.PAPISProtos.LineList;
import com.sydac.mmrbem.papis.common.protos.PAPISProtos.LineList.LineDetail;

import javafx.beans.property.ListProperty;
import javafx.beans.property.SimpleListProperty;
import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;
import javafx.collections.FXCollections;

public class RouteSettingScreenModel extends AbstractScreenModel
{

  private StringProperty lineNameProperty = new SimpleStringProperty();

  private ListProperty<LineDetailModel> lineDetailList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private LineList lineList;

  public RouteSettingScreenModel(int carIndex)
  {
    super(carIndex);
  }

  public LineList getLineList()
  {
    return lineList;
  }

  public void setLineList(byte[] lineList)
  {
    if (lineList.length != 0)
    {
      try
      {
        this.lineList = PAPISProtos.LineList.parseFrom(lineList);

        updateLineList();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }

  }

  public ListProperty<LineDetailModel> getLineDetailList()
  {
    return lineDetailList;
  }

  private void updateLineList()
  {
    if (lineList != null)
    {
      lineDetailList.clear();
      for (LineDetail list : this.lineList.getLineDetailList())
      {
        lineDetailList.add(new LineDetailModel(list.getLineId(), list.getLineName(), list.getLineCode()));
      }

    }

  }

  public StringProperty getLineNameProperty()
  {
    return lineNameProperty;
  }

  public void setLineNameProperty(byte[] lineNameProperty)
  {
    this.lineNameProperty.set(new String(lineNameProperty));
  }

}
