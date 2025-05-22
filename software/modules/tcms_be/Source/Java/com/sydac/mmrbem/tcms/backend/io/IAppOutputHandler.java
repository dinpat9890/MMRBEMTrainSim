/*
 * ==================================================================
 *
 * (C) Copyright 2021 Oktal Sydac Pvt Ltd., all rights reserved. This is
 * unpublished proprietary source code of Sydac. The copyright notice above does
 * not evidence any actual or intended publication of such source code.
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.backend.io;

import com.sydac.simcomms.CObject;

/**
 * Handles output from the business logic to publish to the outside world.
 * <p>
 * This interface would usually be implemented by Comms-aware code, or test
 * code.
 * 
 */
public interface IAppOutputHandler
{
  /**
   * Sets the Vehicle inputs.
   *
   * @param object
   *          the new Vehicle inputs.
   * @param carindex
   *          car index
   */
  void setVehicleInputs(CObject object, int carindex);

  /**
   * Sets the Vehicle outputs.
   *
   * @param object
   *          the new Vehicle outputs.
   * @param carindex
   *          car index
   */
  void setVehicleOutputs(CObject object, int carindex);

  /**
   * Sets the Vehicle Object.
   *
   * @param object
   *          the new Vehicle Object.
   * @param carindex
   *          car index
   */
  void setVehicleObject(CObject object, int carindex);

  void setTCMSVehicleOutputs(CObject object, int carindex);

  void setPISBEOutputs(CObject object, int carindex);

}
