/**
 * ==================================================================
 * 
 * (C) Copyright 2018 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.simulatormanager.plugin.timetable.ui.model;

import com.sydac.simulatormanager.scenariobuilder.model.TableRowEditControlModel;

/**
 * 
 * @author patanges
 *
 */

public class TimetablesTableRowEditControlModel extends TableRowEditControlModel
{

  private static TimetablesTableRowEditControlModel instance = null;

  // ======================================================================
  // construction and access
  // ======================================================================

  public static TimetablesTableRowEditControlModel getInstance()
  {
    if (null == instance)
    {
      instance = new TimetablesTableRowEditControlModel();
      instance.create();
    } // if

    return instance;
  } // getInstance

} // class TrackTimeTableListTableRowEditControlModel

// -- EOF
