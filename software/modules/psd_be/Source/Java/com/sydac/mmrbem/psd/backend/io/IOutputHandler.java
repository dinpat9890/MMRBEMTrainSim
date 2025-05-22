package com.sydac.mmrbem.psd.backend.io;

import com.sydac.simcomms.CObject;

/**
 * Handles output from the business logic to publish to the outside world.
 * <p>
 * This interface would usually be implemented by Comms-aware code, or test
 * code.
 * 
 */
public interface IOutputHandler
{
  /**
   * Sets the CBTCOnboardInputs.
   *
   * @param object
   *          the new CBTCOnboardInputs
   * @param carindex
   *          car index
   */
  void setCBTCOnboardInputs(CObject object, int carindex);

  /**
   * Sets the CBTCOnboardOutputs.
   *
   * @param object
   *          the new CBTCOnboardOutputs
   * @param carindex
   *          car index
   */
  void setCBTCOnboardOutputs(CObject object, int carindex);

  /**
   * Sets the CBTCPlatformOutputs.
   *
   * @param object
   *          the new CBTCPlatformOutputs
   * @param carindex
   *          car index
   */
  void setCBTCPlatformOutputs(CObject object, int carindex);

  /**
   * Sets the PIS outputs.
   *
   * @param object
   *          the new PIS outputs
   */
  void setPISOutputs(CObject object);

  /**
   * Sets the TCMSVehicleOutputs.
   *
   * @param object
   *          the new TCMSVehicleOutputs
   * @param carindex
   *          car index
   */
  void setTCMSVehicleOutputs(CObject object, int carindex);

}
