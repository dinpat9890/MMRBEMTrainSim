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
 * SpecialInfoDetailModel acts as a buffer to store the data read from the XML
 * files,
 */

public class SpecialInfoDetailModel
{

  private int specialInfoId;

  private String specialInfoCode;

  public SpecialInfoDetailModel(int specialInfoId, String specialInfoCode)
  {
    super();
    this.specialInfoId = specialInfoId;
    this.specialInfoCode = specialInfoCode;
  }

  public SpecialInfoDetailModel(SpecialInfoDetailModel model)
  {
    super();
    this.specialInfoId = model.specialInfoId;
    this.specialInfoCode = model.specialInfoCode;
  }

  public SpecialInfoDetailModel()
  {
    // do nothing
  }

  public int getSpecialInfoId()
  {
    return specialInfoId;
  }

  public void setSpecialInfoId(int specialInfoId)
  {
    this.specialInfoId = specialInfoId;
  }

  public String getSpecialInfoCode()
  {
    return specialInfoCode;
  }

  public void setSpecialInfoCode(String specialInfoCode)
  {
    this.specialInfoCode = specialInfoCode;
  }
}
