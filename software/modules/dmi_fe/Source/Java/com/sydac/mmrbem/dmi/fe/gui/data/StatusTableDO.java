/*
 * ==================================================================
 * 
 * (C) Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.dmi.fe.gui.data;

import java.util.ArrayList;
import java.util.List;

import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;

/**
 * Class to hold information for tables having information in row wise format
 *
 */
public class StatusTableDO
{

  /** The status unit. */
  private StringProperty statusUnit = new SimpleStringProperty();

  /** The row name. */
  private StringProperty rowName = new SimpleStringProperty();

  /** The all car data. */
  private List<StatusTableCellDO> allCarData = new ArrayList<>();

  /** The car index. */
  private int carIndex;

  /**
   * Gets the status unit.
   *
   * @return the status unit
   */
  public String getStatusUnit()
  {
    return statusUnit.get();
  }

  /**
   * Sets the status unit.
   *
   * @param aUnit
   *          the new status unit
   */
  public void setStatusUnit(String aUnit)
  {
    this.statusUnit.set(aUnit);
  }

  /**
   * Gets the row name.
   *
   * @return the row name
   */
  public String getRowName()
  {
    return rowName.get();
  }

  /**
   * Sets the row name.
   *
   * @param aRowName
   *          the new row name
   */
  public void setRowName(String aRowName)
  {
    this.rowName.set(aRowName);
  }

  /**
   * Gets the car index.
   *
   * @return the car index
   */
  public int getCarIndex()
  {
    return carIndex;
  }

  /**
   * Sets the car index.
   *
   * @param carIndex
   *          the new car index
   */
  public void setCarIndex(int carIndex)
  {
    this.carIndex = carIndex;
  }

  /**
   * Gets the all car data.
   *
   * @return the all car data
   */
  public List<StatusTableCellDO> getAllCarData()
  {
    return allCarData;
  }

  /**
   * Sets the all car data.
   *
   * @param carData
   *          the new all car data
   */
  public void setAllCarData(List<StatusTableCellDO> carData)
  {
    allCarData.addAll(carData);
  }
}