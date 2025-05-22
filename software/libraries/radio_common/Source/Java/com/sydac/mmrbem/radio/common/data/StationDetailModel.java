/*
 * ==================================================================
 *
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *
 * ==================================================================
 */
package com.sydac.mmrbem.radio.common.data;

/**
 * StationXMLModel acts as a buffer to store the data read from the XML files,
 * later same is used to populate the table.
 */
public class StationDetailModel
{
  private int stationId;

  private String stationName;

  private boolean isStationSkip;

  private String stationCode;

  public String getStationCode()
  {
    return stationCode;
  }

  public void setStationCode(String stationCode)
  {
    this.stationCode = stationCode;
  }

  public boolean isStationSkip()
  {
    return isStationSkip;
  }

  public StationDetailModel(StationDetailModel model)
  {
    this.stationId = model.stationId;
    this.stationName = model.stationName;
    this.isStationSkip = model.isStationSkip;
    this.stationCode = model.stationCode;
  }

  public StationDetailModel()
  {
    // do nothing
  }

  public StationDetailModel(int stationId2, String stationCode2, String stationName2)
  {
    this.stationId = stationId2;
    this.stationName = stationName2;
    this.stationCode = stationCode2;
  }

  /**
   * Sets the station id.
   *
   * @param stationId
   *          the new station id
   */
  public void setStationId(int stationId)
  {
    this.stationId = stationId;
  }

  /**
   * Sets the station name.
   *
   * @param stationName
   *          the new station name
   */
  public void setStationName(String stationName)
  {
    this.stationName = stationName;
  }

  /**
   * Gets the station id.
   *
   * @return the station id
   */
  public int getStationId()
  {
    return stationId;
  }

  /**
   * Gets the station name.
   *
   * @return the station name
   */
  public String getStationName()
  {
    return stationName;
  }

  /**
   * Sets the station skip.
   *
   * @param isStationSkip
   *          the new station skip
   */
  public void setStationSkip(boolean isStationSkip)
  {
    this.isStationSkip = isStationSkip;
  }
}
