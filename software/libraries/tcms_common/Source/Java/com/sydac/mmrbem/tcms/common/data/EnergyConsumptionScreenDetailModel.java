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
 * FireTestScreenDetailModel acts as a buffer to store the data read from the
 * XML files,
 */

public class EnergyConsumptionScreenDetailModel
{

  private int energyId;

  private String compName;

  private String descName;

  private int energyValue;

  public EnergyConsumptionScreenDetailModel()
  {
    super();

  }

  public int getEnergyId()
  {
    return energyId;
  }

  public void setEnergyId(int carId)
  {
    this.energyId = carId;
  }

  public String getCompName()
  {
    return compName;
  }

  public void setCompName(String compName)
  {
    this.compName = compName;
  }

  public String getDescName()
  {
    return descName;
  }

  public void setDescName(String descName)
  {
    this.descName = descName;
  }

  public int getEnergyValue()
  {
    return energyValue;
  }

  public void setEnergyValue(int energyValue)
  {
    this.energyValue = energyValue;
  }

}
