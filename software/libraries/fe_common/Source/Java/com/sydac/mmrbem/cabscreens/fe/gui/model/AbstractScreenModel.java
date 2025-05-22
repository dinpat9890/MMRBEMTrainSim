/*
 * ==================================================================
 * 
 * (C) Copyright 2016 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.cabscreens.fe.gui.model;

import com.sydac.mmrbem.cabscreens.fe.base.IFrontendDataModel;

import javafx.beans.property.IntegerProperty;
import javafx.beans.property.SimpleIntegerProperty;

/**
 * Abstract class for the Screen Models. This abstraction has the responsibility
 * of using the correct {@link IFrontendDataModel} based on the car index.<br>
 * <br>
 * 
 */
public abstract class AbstractScreenModel
{

  protected final int carIndex;

  protected static final String CENTER = "center"; //$NON-NLS-1$

  protected static final String LEFT = "center_left"; //$NON-NLS-1$

  protected final IntegerProperty activeCabIndex = new SimpleIntegerProperty(0);

  /**
   * Constructor
   * 
   * @param carIndex
   *          carIndex
   */
  public AbstractScreenModel(int carIndex)
  {
    this.carIndex = carIndex;
  }
}