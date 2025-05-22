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

/**
 * The Interface ITableRowProperty.
 */
public interface ITableRowProperty
{

  /**
   * Gets the row index.
   *
   * @return the value
   */
  int getIndex();

  /**
   * Gets the row name.
   *
   * @return the row name
   */
  String getRowName();

  /**
   * Gets the row text alignment.
   *
   * @return the row text alignment
   */
  String getRowTextAlignment();

}
