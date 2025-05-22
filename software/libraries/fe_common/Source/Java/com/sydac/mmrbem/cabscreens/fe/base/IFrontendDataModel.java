/*
 * ==================================================================
 * 
 * (C) Copyright 2016 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.cabscreens.fe.base;

import com.sydac.simcomms.CObject;
import com.sydac.simcomms.framework.GatewayProvider;

/**
 * Abstract facade to access data required for the GUI layer
 * 
 * @author Nazim Oliyath
 *
 */
public interface IFrontendDataModel
{

  public abstract void setHubOutputObject(CObject hubOutputObject, GatewayProvider gatewayProvider);

  public abstract void bindIOData(String attribute, Consumer callback);

  /**
   * Method should implement the Binding for the Raw COMMS data
   * 
   * @param attribute
   *          the attribute Saloon CCTV COMMS constants.
   * @param callback
   *          the {@link Consumer}
   */
  void bindIORawData(String attribute, Consumer callback);

  double getIOData(String attribute);
  
  boolean getIODataAsBoolean(String attribute);

  /**
   * Gets the Raw data in byte stream from the COMMS for given attribute.
   * 
   * @param attribute
   *          the attribute Saloon CCTV COMMS constants.
   * @return the iO raw data in byte array.
   */
  byte[] getIORawData(String attribute);

  /**
   * 
   * @author Nazim Oliyath
   * 
   */
  @FunctionalInterface
  public interface Consumer
  {
    void dataUpdated();
  }

}
