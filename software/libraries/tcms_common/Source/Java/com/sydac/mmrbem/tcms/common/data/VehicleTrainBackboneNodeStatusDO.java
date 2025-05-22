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
public class VehicleTrainBackboneNodeStatusDO
{

  private int trainBackboneNodeStatus;

  private int trainBackboneFaultStatus;

  public int getTrainBackboneNodeStatus()
  {
    return trainBackboneNodeStatus;
  }

  public void setTrainBackboneNodeStatus(int trainBackboneNodeStatus)
  {
    this.trainBackboneNodeStatus = trainBackboneNodeStatus;
  }

  public int getTrainBackboneFaultStatus()
  {
    return trainBackboneFaultStatus;
  }

  public void setTrainBackboneFaultStatus(int trainBackboneFaultStatus)
  {
    this.trainBackboneFaultStatus = trainBackboneFaultStatus;
  }
}