/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.common.utils;

import java.text.NumberFormat;

import javax.measure.converter.UnitConverter;
import javax.measure.unit.Unit;

/**
 * TCMS has to display speed in Km per hour. This class is responsible to do
 * this conversion.
 * 
 * @author mulukg
 *
 */
public class SpeedUnitConverter
{
  private static final String SPEED_UNIT = "km/h"; //$NON-NLS-1$

  private final NumberFormat formatter;

  private final UnitConverter unitConverter;

  /**
   * Constructor.
   */
  public SpeedUnitConverter()
  {
    Unit<?> foreignUnits = Unit.valueOf(SPEED_UNIT);
    Unit<?> siUnits = foreignUnits.getStandardUnit();
    unitConverter = siUnits.getConverterTo(foreignUnits);

    formatter = NumberFormat.getInstance();
    formatter.setMaximumFractionDigits(0);
  }

  /**
   * Converts the specified value and formats.
   * 
   * @param aValue
   *          The value that needs to be converted.
   * @return Formatted value.
   */
  public String convertToFormatted(double aValue)
  {
    return formatter.format(convertTo(aValue));
  } //

  /**
   * Converts the specified value to the unit km/h.
   * 
   * @param aValue
   *          The value that needs to be converted.
   * @return the converted value
   */
  public double convertTo(double aValue)
  {
    return unitConverter.convert(aValue);
  }
}
