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

import java.util.ArrayList;
import java.util.Arrays;

import com.google.protobuf.InvalidProtocolBufferException;
import com.sydac.common.log.Tracer;
import com.sydac.mmrbem.cabscreens.fe.gui.model.AbstractScreenModel;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.VehiclePecuList.VehiclePecu;

import javafx.beans.property.IntegerProperty;
import javafx.beans.property.MapProperty;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleMapProperty;
import javafx.collections.FXCollections;

public class PISSystemScreenModel extends AbstractScreenModel
{
  private IntegerProperty pecuCallVehicleIndex = new SimpleIntegerProperty();

  private IntegerProperty pecuIsoVehicleIndex = new SimpleIntegerProperty();

  private IntegerProperty pecuCallId = new SimpleIntegerProperty();

  private IntegerProperty pecuCallStatus = new SimpleIntegerProperty();

  private IntegerProperty pecuCallResetStatus = new SimpleIntegerProperty();

  private IntegerProperty pabrStatus = new SimpleIntegerProperty();

  private IntegerProperty pabrStatusDm2 = new SimpleIntegerProperty();

  private IntegerProperty paborStatusDm1 = new SimpleIntegerProperty();

  private IntegerProperty paborStatusDm2 = new SimpleIntegerProperty();

  private MapProperty<Integer, ArrayList<Integer>> carConfigData = new SimpleMapProperty<>(
      FXCollections.<Integer, ArrayList<Integer>> observableHashMap());

  public PISSystemScreenModel(int carIndex)
  {
    super(carIndex);
  }

  public IntegerProperty getPecuCallVehicleIndex()
  {
    return pecuCallVehicleIndex;
  }

  public void setPecuCallVehicleIndex(Integer newVal)
  {

    this.pecuCallVehicleIndex.set(newVal);

  }

  public IntegerProperty getPecuCallId()
  {
    return pecuCallId;
  }

  public void setPecuCallId(Integer newVal)
  {
    this.pecuCallId.set(newVal);

  }

  public IntegerProperty getPecuCallStatus()
  {
    return pecuCallStatus;
  }

  public void setPecuCallStatus(Integer newVal)
  {
    this.pecuCallStatus.set(newVal);

  }

  public IntegerProperty getPecuCallResetStatus()
  {
    return pecuCallResetStatus;
  }

  public void setPecuCallResetStatus(Integer newVal)
  {
    this.pecuCallResetStatus.set(newVal);

  }

  public void setIsolationDeState(byte[] newValue)
  {
    if (newValue.length != 0)
    {

      try
      {

        TCMSProto.VehiclePecuList isoInfo = TCMSProto.VehiclePecuList.parseFrom(newValue);

        if (isoInfo != null)
        {

          for (VehiclePecu stationDetail : isoInfo.getPecuListList())
          {

            setPecuIsoVehicleIndex(stationDetail.getVehInd());
            carConfigData.put(stationDetail.getVehInd(),
                new ArrayList<Integer>(Arrays.asList(stationDetail.getPecu1(), stationDetail.getPecu2(),
                    stationDetail.getPecu3(), stationDetail.getPecu4())));
          }

        }

      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }

  }

  public MapProperty<Integer, ArrayList<Integer>> carConfigDataProperty()
  {
    return carConfigData;
  }

  public IntegerProperty getPecuIsoVehicleIndex()
  {
    return pecuIsoVehicleIndex;
  }

  public void setPecuIsoVehicleIndex(Integer newVal)
  {

    this.pecuIsoVehicleIndex.set(newVal);

  }

  public IntegerProperty getPabrStatus()
  {
    return pabrStatus;
  }

  public void setPabrStatus(Integer pabrStatus)
  {
    this.pabrStatus.set(pabrStatus);
  }

  public IntegerProperty getPabrStatusDm2()
  {
    return pabrStatusDm2;
  }

  public void setPabrStatusDm2(Integer pabrStatusDm2)
  {
    this.pabrStatusDm2.set(pabrStatusDm2);
  }

  public IntegerProperty getPaborStatusDm1()
  {
    return paborStatusDm1;
  }

  public void setPaborStatusDm1(Integer paborStatusDm1)
  {
    this.paborStatusDm1.set(paborStatusDm1);
  }

  public IntegerProperty getPaborStatusDm2()
  {
    return paborStatusDm2;
  }

  public void setPaborStatusDm2(Integer paborStatusDm2)
  {
    this.paborStatusDm2.set(paborStatusDm2);
  }

}
