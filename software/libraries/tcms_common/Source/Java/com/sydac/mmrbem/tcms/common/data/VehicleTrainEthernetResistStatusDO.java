/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */

package com.sydac.mmrbem.tcms.common.data;

/**
 * This class hold data for ECN TBN Status. <br>
 * Note: Data can be hold as {@link Integer}
 */
public class VehicleTrainEthernetResistStatusDO
{

  private int trainEthernetResistStatus;

  private int trainEthernetResistFault;

  public int getTrainEthernetResistStatus()
  {
    return trainEthernetResistStatus;
  }

  public void setTrainEthernetResistStatus(int trainEthernetResistStatus)
  {
    this.trainEthernetResistStatus = trainEthernetResistStatus;
  }

  public int getTrainEthernetResistFault()
  {
    return trainEthernetResistFault;
  }

  public void setTrainEthernetResistFault(int trainEthernetResistFault)
  {
    this.trainEthernetResistFault = trainEthernetResistFault;
  }
}