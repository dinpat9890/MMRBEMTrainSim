/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.fe.base.utils;

import javafx.scene.control.Label;

public class TCMSUtil
{

  private TCMSUtil()
  {
    super();
  }

  public static final double getProgressBarMovingFactor(Double progressBarLength, Double maxValue)
  {
    return progressBarLength / maxValue;
  }

  public static void updateProgressBar(double value, Double maxValue, Double minValue,
      Double progressBarLength, Label label)
  {
    double actualValue = 0;
    if (value > maxValue)
    {
      actualValue = maxValue;
    }
    else if (value < minValue)
    {
      actualValue = minValue;
    }
    else
    {
      actualValue = value;
    }

    double movingFactor = getProgressBarMovingFactor(progressBarLength, maxValue);

    Double height = actualValue * movingFactor;

    label.setPrefHeight(height);
    label.setMaxHeight(height);
    label.setMinHeight(height);

  }

}
