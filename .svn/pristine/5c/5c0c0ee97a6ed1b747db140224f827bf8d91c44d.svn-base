/**
 * ==================================================================
 * 
 * (C) Copyright 2016 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.simulatormanager.plugin.timetable.ui.components;

import java.awt.Color;
import java.awt.Component;

import javax.swing.JTable;
import javax.swing.border.Border;
import javax.swing.border.EmptyBorder;
import javax.swing.table.TableCellRenderer;

import sun.swing.DefaultLookup;

/**
 * @author johnsh
 *
 */
public class TimeCellRenderer extends TimeField implements TableCellRenderer
{

  public TimeCellRenderer()
  {
    setOpaque(true); // MUST do this for background to show up.
  }

  @Override
  public Component getTableCellRendererComponent(JTable table, Object value, boolean isSelected, boolean hasFocus, int row, int column)
  {
    Color fg = null;
    Color bg = null;

    JTable.DropLocation dropLocation = table.getDropLocation();
    if (dropLocation != null && !dropLocation.isInsertRow() && !dropLocation.isInsertColumn() && dropLocation.getRow() == row && dropLocation.getColumn() == column)
    {

      fg = DefaultLookup.getColor(this, ui, "Table.dropCellForeground"); //$NON-NLS-1$
      bg = DefaultLookup.getColor(this, ui, "Table.dropCellBackground"); //$NON-NLS-1$

      isSelected = true;
    }

    if (isSelected)
    {
      setForeground(fg == null ? table.getSelectionForeground() : fg);
      setBackground(bg == null ? table.getSelectionBackground() : bg);
    }
    else
    {
      Color background = table.getBackground();
      if (background == null || background instanceof javax.swing.plaf.UIResource)
      {
        Color alternateColor = DefaultLookup.getColor(this, ui, "Table.alternateRowColor"); //$NON-NLS-1$
        if (alternateColor != null && row % 2 != 0)
        {
          background = alternateColor;
        }
      }
      setForeground(table.getForeground());
      setBackground(background);
    }

    setFont(table.getFont());    

    if (hasFocus)
    {
      Border border = null;
      if (isSelected)
      {
        border = DefaultLookup.getBorder(this, ui, "Table.focusSelectedCellHighlightBorder"); //$NON-NLS-1$
      }
      if (border == null)
      {
        border = DefaultLookup.getBorder(this, ui, "Table.focusCellHighlightBorder"); //$NON-NLS-1$
      }
      setBorder(border);

      if (!isSelected && table.isCellEditable(row, column))
      {
        Color col;
        col = DefaultLookup.getColor(this, ui, "Table.focusCellForeground"); //$NON-NLS-1$
        if (col != null)
        {
          setForeground(col);
        }
        col = DefaultLookup.getColor(this, ui, "Table.focusCellBackground"); //$NON-NLS-1$
        if (col != null)
        {
          setBackground(col);
        }
      }
    }
    else
    {
      setBorder(getNoFocusBorder());
    }

    Long timeInSeconds = (Long)value;
    this.setValue(timeInSeconds);
    return this;
  }

  private Border getNoFocusBorder()
  {
    Border border = DefaultLookup.getBorder(this, ui, "Table.cellNoFocusBorder"); //$NON-NLS-1$
    if (System.getSecurityManager() != null)
    {
      if (border != null)
        return border;
      return new EmptyBorder(1, 1, 1, 1);
    }
    else if (border != null)
    {
      return border;
    }
    return new EmptyBorder(1, 1, 1, 1);
  }
}
