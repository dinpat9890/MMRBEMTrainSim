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

import com.sydac.mmrbem.dmi.fe.common.DMIUIConstants;

import javafx.beans.property.BooleanProperty;
import javafx.beans.property.SimpleBooleanProperty;
import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;

/**
 * Each table cell will have data, status, car index and alignment attached to
 * it. This holds data for each cell. Helps to update cell easily.
 * 
 * @author rautprit
 */
public class StatusTableCellDO
{

  /** The car index. */
  private int carIndex;

  /** The text alignment. */
  private StringProperty textAlignment = new SimpleStringProperty(DMIUIConstants.NOT_APPLICABLE_CSS);

  /** Boolean property to check whether second bogie data is available or not */
  private BooleanProperty isSecondBogieCellDataExist = new SimpleBooleanProperty(false);

  /** The first bogie cell state. */
  private StringProperty firstBogieCellState = new SimpleStringProperty(""); //$NON-NLS-1$

  /** The second bogie cell state. */
  private StringProperty secondBogieCellState = new SimpleStringProperty(""); //$NON-NLS-1$

  /** The first bogie cell data. */
  private StringProperty firstBogieCellData = new SimpleStringProperty(""); //$NON-NLS-1$

  /** The second bogie cell data. */
  private StringProperty secondBogieCellData = new SimpleStringProperty(""); //$NON-NLS-1$

  public StatusTableCellDO()
  {
    // do nothing
  }

  public StatusTableCellDO(int carIndex, String textAlignment, Boolean isSecondBogieCellDataExist,
      String firstBogieCellData, String firstBogieCellState, String secondBogieCellData,
      String secondBogieCellState)
  {
    super();
    this.carIndex = carIndex;
    this.textAlignment.set(textAlignment);
    this.isSecondBogieCellDataExist.set(isSecondBogieCellDataExist);
    this.firstBogieCellState.set(firstBogieCellState);
    this.secondBogieCellState.set(secondBogieCellState);
    this.firstBogieCellData.set(firstBogieCellData);
    this.secondBogieCellData.set(secondBogieCellData);
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
   * Gets the text alignment.
   *
   * @return the text alignment
   */
  public String getTextAlignment()
  {
    return textAlignment.get();
  }

  /**
   * Sets the text alignment.
   *
   * @param textAlignment
   *          the new text alignment
   */
  public void setTextAlignment(String textAlignment)
  {
    this.textAlignment.set(textAlignment);
  }

  /**
   * Gets the first bogie cell data.
   *
   * @return first bogie cell data
   */
  public String getFirstBogieCellData()
  {
    return firstBogieCellData.get();
  }

  /**
   * Sets the first bogie cell data.
   *
   * @param cellData
   *          the new cell data
   */
  public void setFirstBogieCellData(String cellData)
  {
    this.firstBogieCellData.set(cellData);
  }

  /**
   * Checks if second bogie cell data exist or not.
   *
   * @return true, if second bogie exist
   */
  public boolean isSecondBogieCellDataExist()
  {
    return isSecondBogieCellDataExist.get();
  }

  /**
   * Sets true if second bogie cell data exist.
   *
   * @param isSecondBogieExist
   *          true if second bogie cell data exist
   */
  public void setSecondBogieCellDataExist(boolean isSecondBogieExist)
  {
    this.isSecondBogieCellDataExist.set(isSecondBogieExist);
  }

  /**
   * Gets the second bogie cell data.
   *
   * @return the cell data
   */
  public String getSecondBogieCellData()
  {
    return secondBogieCellData.get();
  }

  /**
   * Sets the second bogie cell data.
   *
   * @param cellData
   *          the new cell data
   */
  public void setSecondBogieCellData(String cellData)
  {
    this.secondBogieCellData.set(cellData);
  }

  /**
   * Sets the first bogie cell state (CSS to display background colour).
   *
   * @param cellState
   *          the new cell state
   */
  public void setFirstBogieCellState(String cellState)
  {
    this.firstBogieCellState.set(cellState);
  }

  /**
   * Sets the second bogie cell state (CSS to display background colour).
   *
   * @param cellState
   *          the new cell state
   */
  public void setSecondBogieCellState(String cellState)
  {
    this.secondBogieCellState.set(cellState);
  }

  /**
   * Gets the first bogie cell state.
   *
   * @return first bogie cell state
   */
  public String getFirstBogieCellState()
  {
    return firstBogieCellState.get();
  }

  /**
   * Gets the second bogie cell state.
   *
   * @return the cell state
   */
  public String getSecondBogieCellState()
  {
    return secondBogieCellState.get();
  }

  /**
   * Gets Cell alignment property
   * 
   * @return {@link StringProperty}
   */
  public final StringProperty textAlignmentProperty()
  {
    return textAlignment;
  }

  /**
   * Gets first bogie cell data property
   * 
   * @return {@link StringProperty}
   */
  public final StringProperty firstBogieCellDataProperty()
  {
    return firstBogieCellData;
  }

  /**
   * Gets seconf bogie cell data property
   * 
   * @return {@link StringProperty}
   */
  public final StringProperty secondBogieCellDataProperty()
  {
    return secondBogieCellData;
  }

  /**
   * Gets first bogie cell state property (CSS to display background colour)
   * 
   * @return {@link StringProperty}
   */
  public final StringProperty firstBogieCellStateProperty()
  {
    return firstBogieCellState;
  }

  /**
   * Gets second bogie cell state property (CSS to display background colour)
   * 
   * @return {@link StringProperty}
   */
  public final StringProperty secondBogieCellStateProperty()
  {
    return secondBogieCellState;
  }

  /**
   * Gets second bogie cell exist property
   * 
   * @return {@link BooleanProperty}
   */
  public final BooleanProperty secondBogieExistProperty()
  {
    return isSecondBogieCellDataExist;
  }
}
