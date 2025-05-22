package com.sydac.mmrbem.dmi.backend.vehicle.io.models;

import com.sydac.foundation.IObservablePropertyModel;

public interface ICBTCPlatformOutputsModel extends IObservablePropertyModel
{

  Integer getTrainDoorStatus();

  Integer getPSDDoorStatus();

  Integer getDepartureOrder();

  byte[] getDepartureInformation();

  byte[] getTrainDockingInfo();

}
