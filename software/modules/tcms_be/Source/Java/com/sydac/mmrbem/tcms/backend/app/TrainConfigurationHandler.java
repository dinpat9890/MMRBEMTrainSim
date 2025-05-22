/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.backend.app;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import com.sydac.common.dataobjects.DBScenarioTrain;
import com.sydac.common.dataobjects.DBTrainElement;
import com.sydac.common.dataobjects.DBTrainElementManager;
import com.sydac.common.febe.SimplePropertySetter;
import com.sydac.common.febe.backend.StateObjectsCallbackAdapter;
import com.sydac.foundation.functional.Pair;
import com.sydac.mmrbem.tcms.backend.logic.SharedDataModel;
import com.sydac.mmrbem.tcms.common.data.VehicleDetailModel;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.TrainConfigurationData;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.TrainConfigurationData.VehicleDetail;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;
import com.sydac.mmrbem.tcms.common.state.CarType;
import com.sydac.project.runtimedata.ProjectObjectConstants.VDUOutputs;
import com.sydac.simcomms.CObject;
import com.sydac.simcomms.Gateway;

/**
 * Class to generate the TMSOutputs#TRAIN_CONFIGURATION_DATA raw based on the
 * train details obtained from the session data.
 * 
 * @author walbeg
 * 
 */
@SuppressWarnings("deprecation")
public class TrainConfigurationHandler extends StateObjectsCallbackAdapter
{

  private final DBTrainElementManager dbTrainElementManager;

  private final VehicleDetailsHolder vehicleDetailsHolder;

  private final Gateway gateway;

  private final int noOfCars;

  private SimplePropertySetter tmsOutput;

  private SharedDataModel sharedModel;

  /** Store the car display name **/
  private Map<Integer, Pair<CarType, String>> carDisplayNameMap = new HashMap<>();

  public TrainConfigurationHandler(Gateway aGateway, DBScenarioTrain dbScenarioTrain,
      SharedDataModel aSharedModel)
  {
    sharedModel = aSharedModel;
    this.dbTrainElementManager = dbScenarioTrain.getTrain().getElements();
    this.vehicleDetailsHolder = new VehicleDetailsHolder();
    this.gateway = aGateway;
    this.noOfCars = dbTrainElementManager.size();
    sharedModel.setTotalCar(noOfCars);

    loadCarDisplayName();
  }

  /**
   * Loads car display name
   */
  private void loadCarDisplayName()
  {

    for (int carIndex = 0; carIndex < noOfCars; carIndex++)
    {
      char carPositionIdentity = (char)(carIndex + 65);
      DBTrainElement element = dbTrainElementManager.get(carIndex);
      String carDescription = CarType.valueOf(element.getCar().getClassType().getClassCode()).getDisplayCode()
          + ApplicationConstants.LINE_IDENTIFICATION + carPositionIdentity
          + ApplicationConstants.TRAIN_SET_NUMBER;

      if (carDescription.startsWith(CarType.DM.getDisplayCode()))
      {
        carDisplayNameMap.put(carIndex, new Pair<>(CarType.DM, carDescription));
      }
      else if (carDescription.startsWith(CarType.T.getDisplayCode()))
      {
        carDisplayNameMap.put(carIndex, new Pair<>(CarType.T, carDescription));
      }
      else if (carDescription.startsWith(CarType.M.getDisplayCode()))
      {
        carDisplayNameMap.put(carIndex, new Pair<>(CarType.M, carDescription));
      }
    }
  }

  /**
   * On each vehicle object creation in COMMS, we populate the details required
   * for the raw. Once we get all the vehicles, write the raw to TMSOutputs
   */
  @Override
  public void onVehicleObjectCreation(CObject aVehicleObject, int aVehicleIndex)
  {
    Pair<CarType, String> carTypeNamePair = carDisplayNameMap.get(aVehicleIndex);

    /* Add vehicle details */
    vehicleDetailsHolder.add(dbTrainElementManager.get(aVehicleIndex), aVehicleIndex, carTypeNamePair);

    /*
     * when all vehicles received, populate unit numbers and write to TMS output
     */
    checkAndWriteToHubOutput();
  }

  /**
   * Once the TMSOutput COMMS object is created, hold on to it. If in the mean
   * time the train configuration data has been created, write the raw the
   * TMSOutput.
   */
  @Override
  public void onApplicationOutputsObjectCreation(CObject aApplicationOutputsObject)
  {
    tmsOutput = new SimplePropertySetter(gateway, aApplicationOutputsObject);
    checkAndWriteToHubOutput();
  }

  /**
   * If all the vehicles have been received, write RAW to TMS output
   */
  private void checkAndWriteToHubOutput()
  {
    if (vehicleDetailsHolder.size() == noOfCars && tmsOutput != null)
    {
      List<VehicleDetail> vehicleDetails = vehicleDetailsHolder.getVehicleDetails();
      /* Build train configuration data */
      TrainConfigurationData trainConfigurationData = TrainConfigurationData.newBuilder()
          .addAllVehicleDetails(vehicleDetails).build();

      /* Write RAW to TMS output */
      tmsOutput.setRaw(VDUOutputs.TRAIN_CONFIGURATION_DATA, trainConfigurationData.toByteArray()); /////////////////////////
      createTrainDetailsModel(vehicleDetails);

      /* Write total car to TMS output */
      tmsOutput.setNumber(VDUOutputs.NUMBER_OF_CARS, noOfCars);
    }
  }

  private void createTrainDetailsModel(List<VehicleDetail> vehicleDetailList)
  {
    List<VehicleDetailModel> vehicleDetailModelList = new ArrayList<>();
    if (vehicleDetailList != null)
    {
      for (TrainConfigurationData.VehicleDetail vehicleDetail : vehicleDetailList)
      {
        VehicleDetailModel vehicleDetailModel = new VehicleDetailModel();
        vehicleDetailModel.setCarType(vehicleDetail.getCarType());
        vehicleDetailModel.setCarOrientation(vehicleDetail.getCarOrientation());
        vehicleDetailModel.setCarClassCode(vehicleDetail.getCarClassCode());
        vehicleDetailModel.setCarIndex(vehicleDetail.getCarIndex());
        vehicleDetailModel.setCarDisplayName(vehicleDetail.getCarDisplayName());

        vehicleDetailModelList.add(vehicleDetailModel);
      }
      sharedModel.setVehicleDetailModelList(vehicleDetailModelList);
    }
  }

  /**
   * Wrapper to hold vehicle details
   * 
   * @author Nazim Oliyath
   * 
   */
  private static class VehicleDetailsHolder
  {
    private final List<Entry> entries = new ArrayList<>();

    /**
     * Add a vehicle details given the train element, vehicle number and car
     * index. This API is used to create a vehicle detail without the unit
     * number information.
     * 
     * @param trainElement
     *          {@link DBTrainElement reference}
     * @param carIndex
     *          car index of this car
     * @param carTypeNamePair
     *          Display Name to be display on car for this car
     */
    void add(DBTrainElement trainElement, int carIndex, Pair<CarType, String> carTypeNamePair)
    {
      VehicleDetail vehicleDetail = VehicleDetail.newBuilder()
          .setCarType(carTypeNamePair.getFirst().getCarTypeCode())
          .setCarOrientation(trainElement.getCar().getOrientation().getCodeName())
          .setCarClassCode(trainElement.getCar().getClassType().getClassCode()).setCarIndex(carIndex)
          .setCarDisplayName(carTypeNamePair.getSecond()).buildPartial();
      Entry newEntry = new Entry(vehicleDetail);
      if (!entries.contains(newEntry))
      {
        entries.add(newEntry);
        Collections.sort(entries);
      }
    }

    /**
     * Returns the number of vehicle details.
     * 
     * @return int, number of vehicle details present.
     */
    int size()
    {
      return entries.size();
    }

    /**
     * Gives all the vehicle details.
     * 
     * @return List<VehicleDetail>
     */
    List<VehicleDetail> getVehicleDetails()
    {
      List<VehicleDetail> vehicleDetails = new ArrayList<>();
      for (Entry entry : entries)
      {
        vehicleDetails.add(entry.getVehicleDetail());
      }
      return vehicleDetails;
    }

    /**
     * Wrapper which allows sorting the vehicle details based on carIndex
     * 
     * @author Nazim Oliyath
     * 
     */
    private static class Entry implements Comparable<Entry>
    {
      private VehicleDetail detail;

      Entry(VehicleDetail vehicleDetail)
      {
        this.detail = vehicleDetail;
      }

      VehicleDetail getVehicleDetail()
      {
        return this.detail;
      }

      @Override
      public int compareTo(Entry other)
      {
        return detail.getCarIndex() - other.getVehicleDetail().getCarIndex();
      }

      @Override
      public boolean equals(Object obj)
      {
        return (obj instanceof Entry) && (this.hashCode() == obj.hashCode());
      }

      @Override
      public int hashCode()
      {
        return this.detail.getCarIndex();
      }

      @SuppressWarnings("unused")
      public final void flush()
      {
        this.detail = null;
      }

    }

  }

}
