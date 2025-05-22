/**
 * ==================================================================
 * 
 * (C) Copyright 2018 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.simulatormanager.plugin.timetable.ui.controller;

import java.util.Comparator;

import com.sydac.simulatormanager.plugin.timetable.ui.model.StationTableData;
/**
* StationTableStationIdComparator - Comparator for {@link StationTableData} 
* which compares on the basis of station ID
*/
public class StationTableStationIdComparator implements Comparator<StationTableData>
{
  @Override
  public int compare(StationTableData obj1, StationTableData obj2)
  {

    return obj1.getStationID() - obj2.getStationID();
  }

}
