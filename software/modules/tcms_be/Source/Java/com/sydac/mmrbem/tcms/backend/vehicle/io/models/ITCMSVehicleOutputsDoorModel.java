/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.backend.vehicle.io.models;

import com.sydac.foundation.IObservablePropertyModel;

/**
 * This interface supplies getters for Door of VehicleOutputs variables.
 */
public interface ITCMSVehicleOutputsDoorModel extends IObservablePropertyModel
{
  // Door x Open
  Integer getDoorA1Open();

  Integer getDoorA2Open();

  Integer getDoorA3Open();

  Integer getDoorA4Open();

  Integer getDoorB1Open();

  Integer getDoorB2Open();

  Integer getDoorB3Open();

  Integer getDoorB4Open();

  Integer getEmergencyEscapeDoorOpen();

  // Door x Isolated
  Integer getDoorA1Isolated();

  Integer getDoorA2Isolated();

  Integer getDoorA3Isolated();

  Integer getDoorA4Isolated();

  Integer getDoorB1Isolated();

  Integer getDoorB2Isolated();

  Integer getDoorB3Isolated();

  Integer getDoorB4Isolated();

  Integer getEmergencyEscapeDoorIsolated();

  // Door x Fault
  Integer getDoorA1Fault();

  Integer getDoorA2Fault();

  Integer getDoorA3Fault();

  Integer getDoorA4Fault();

  Integer getDoorB1Fault();

  Integer getDoorB2Fault();

  Integer getDoorB3Fault();

  Integer getDoorB4Fault();

  Integer getEmergencyEscapeDoorFault();

  // Door x Emergency Released
  Integer getDoorA1EmergencyReleased();

  Integer getDoorA2EmergencyReleased();

  Integer getDoorA3EmergencyReleased();

  Integer getDoorA4EmergencyReleased();

  Integer getDoorB1EmergencyReleased();

  Integer getDoorB2EmergencyReleased();

  Integer getDoorB3EmergencyReleased();

  Integer getDoorB4EmergencyReleased();

  Integer getEmergencyEscapeDoorReleased();
  
  // Door x Locked
  Integer getDoorA1Locked();
  
  Integer getDoorA2Locked();
  
  Integer getDoorA3Locked();
  
  Integer getDoorA4Locked();
  
  Integer getDoorB1Locked();
  
  Integer getDoorB2Locked();
  
  Integer getDoorB3Locked();
  
  Integer getDoorB4Locked();
  
  Integer getEmergencyEscapeDoorLocked();
}
