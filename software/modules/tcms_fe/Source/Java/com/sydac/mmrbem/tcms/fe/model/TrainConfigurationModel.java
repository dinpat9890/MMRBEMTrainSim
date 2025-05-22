/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.fe.model;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

import com.google.protobuf.InvalidProtocolBufferException;
import com.sydac.mmrbem.cabscreens.fe.gui.model.AbstractScreenModel;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.TrainConfigurationData;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.TrainConfigurationData.VehicleDetail;
import com.sydac.mmrbem.tcms.fe.gui.model.CarConfigurationModel;

import javafx.beans.property.IntegerProperty;
import javafx.beans.property.MapProperty;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleMapProperty;
import javafx.collections.FXCollections;

/**
 * The Class TrainConfigurationModel.
 */
public class TrainConfigurationModel extends AbstractScreenModel
{
  private List<Integer> vehicleIdentifier;

  private MapProperty<Integer, CarConfigurationModel> carConfigData = new SimpleMapProperty<>(
      FXCollections.<Integer, CarConfigurationModel> observableHashMap());

  private IntegerProperty totalCars = new SimpleIntegerProperty();

  /**
   * Instantiates a new train configuration model.
   *
   * @param carIndex
   *          the car index
   */
  public TrainConfigurationModel(int carIndex)
  {
    super(carIndex);
  }

  /**
   * Process update.
   */
  private void processUpdate(byte[] data)
  {
    if (data != null)
    {
      HashMap<Integer, CarConfigurationModel> carConfigs = new HashMap<>();

      flush();
      TrainConfigurationData configData;
      try
      {
        configData = TrainConfigurationData.parseFrom(data);

        totalCars.set(configData.getVehicleDetailsCount());

        for (VehicleDetail vehicleDetail : configData.getVehicleDetailsList())
        {
          CarConfigurationModel carConfig = new CarConfigurationModel();
          carConfig.setCarClassCode(vehicleDetail.getCarClassCode());
          carConfig.setCarIndex(vehicleDetail.getCarIndex());
          carConfig.setCarType(vehicleDetail.getCarType());
          carConfig.setCarOrientation(vehicleDetail.getCarOrientation());
          carConfig.setCarDisplayName(vehicleDetail.getCarDisplayName());
          carConfigs.put(vehicleDetail.getCarIndex(), carConfig);

          // add vehicle number to data-structure
          vehicleIdentifier.add(vehicleDetail.getCarIndex());
        }
        carConfigData.set(FXCollections.observableMap(carConfigs));
      }
      catch (InvalidProtocolBufferException e)
      {
        e.printStackTrace();
      }
    }
    else
    {
      flush();
    }

  }

  /**
   * Gets the all vehicle identifier.
   *
   * @return the all vehicle identifier (car index)
   */
  public List<Integer> getAllVehicleIdentifier()
  {
    return vehicleIdentifier.subList(0, totalCars.get());
  }

  /**
   * Car config map property.
   *
   * @return the map property
   */
  public MapProperty<Integer, CarConfigurationModel> carConfigDataProperty()
  {
    return carConfigData;
  }

  /**
   * Gets the car config.
   *
   * @param carIndex
   *          as the vehicle identifier
   * @return the car config
   */
  public final CarConfigurationModel getCarConfig(int carIndex)
  {
    return carConfigData.get(carIndex);
  }

  /**
   * Total cars property.
   *
   * @return the integer property
   */
  public IntegerProperty totalCarsProperty()
  {
    return totalCars;
  }

  /**
   * Flush.
   */
  private void flush()
  {
    if (carConfigData.isEmpty())
    {
      carConfigData = new SimpleMapProperty<>(
          FXCollections.<Integer, CarConfigurationModel> observableHashMap());
      vehicleIdentifier = new ArrayList<>();
    }
    else
    {
      carConfigData.clear();
      vehicleIdentifier.clear();
    }
  }

  public void setTrainConfigurationData(byte[] data)
  {
    processUpdate(data);
  }
}
