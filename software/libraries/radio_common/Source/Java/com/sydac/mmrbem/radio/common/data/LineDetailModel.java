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
 * LineDetailModel acts as a buffer to store the data read from the XML files,
 * later same is used to populate the FE.
 */
public class LineDetailModel
{
  private int lineId;

  private String lineName;

  private String lineCode;

  public LineDetailModel(LineDetailModel model)
  {
    this.lineId = model.lineId;
    this.lineName = model.lineName;
    this.lineCode = model.lineCode;
  }

  public LineDetailModel()
  {
    // do nothing
  }

  public LineDetailModel(int lineId2, String lineName2, String lineCode2)
  {
    this.lineId = lineId2;
    this.lineName = lineName2;
    this.lineCode = lineCode2;
  }

  public int getLineId()
  {
    return lineId;
  }

  public void setLineId(int lineId)
  {
    this.lineId = lineId;
  }

  public String getLineName()
  {
    return lineName;
  }

  public void setLineName(String lineName)
  {
    this.lineName = lineName;
  }

  public String getLineCode()
  {
    return lineCode;
  }

  public void setLineCode(String lineCode)
  {
    this.lineCode = lineCode;
  }
}
