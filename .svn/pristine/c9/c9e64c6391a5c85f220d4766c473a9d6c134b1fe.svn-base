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

import java.awt.Component;
import java.awt.event.MouseEvent;
import java.io.Serializable;
import java.util.EventObject;

import javax.swing.AbstractCellEditor;
import javax.swing.JTable;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;
import javax.swing.table.TableCellEditor;

/**
 * @author johnsh
 *
 */
public class TimeCellEditor extends AbstractCellEditor implements TableCellEditor
{

  //
  // Instance Variables
  //

  /** The Swing component being edited. */
  protected TimeField editorComponent;

  /**
   * The delegate class which handles all methods sent from the
   * <code>CellEditor</code>.
   */
  protected EditorDelegate delegate;

  /**
   * An integer specifying the number of clicks needed to start editing. Even if
   * <code>clickCountToStart</code> is defined as zero, it will not initiate
   * until a click occurs.
   */
  protected int clickCountToStart = 1;

  //
  // Constructors
  //

  /**
   * Constructs a <code>DefaultCellEditor</code> object that uses a time field.
   * 
   */
  public TimeCellEditor()
  {
    editorComponent = new TimeField();
    delegate = new EditorDelegate() {
      @Override
      public void setValue(Object value)
      {
        Long timeInSeconds = (Long)value;
        editorComponent.setValue(timeInSeconds);
      }

      @Override
      public Object getCellEditorValue()
      {
        return editorComponent.getValue();
      }

      @Override
      public boolean shouldSelectCell(EventObject anEvent)
      {
        if (anEvent instanceof MouseEvent)
        {
          MouseEvent e = (MouseEvent)anEvent;
          return e.getID() != MouseEvent.MOUSE_DRAGGED;
        }
        return true;
      }
    };
    editorComponent.addChangeListener(delegate);
  }

  /**
   * Returns a reference to the editor component.
   *
   * @return the editor <code>Component</code>
   */
  public Component getComponent()
  {
    return editorComponent;
  }

  //
  // Modifying
  //

  /**
   * Specifies the number of clicks needed to start editing.
   *
   * @param count
   *          an int specifying the number of clicks needed to start editing
   * @see #getClickCountToStart
   */
  public void setClickCountToStart(int count)
  {
    clickCountToStart = count;
  }

  /**
   * Returns the number of clicks needed to start editing.
   * 
   * @return the number of clicks needed to start editing
   */
  public int getClickCountToStart()
  {
    return clickCountToStart;
  }

  //
  // Override the implementations of the superclass, forwarding all methods
  // from the CellEditor interface to our delegate.
  //

  /**
   * Forwards the message from the <code>CellEditor</code> to the
   * <code>delegate</code>.
   * 
   * @see EditorDelegate#getCellEditorValue
   */
  @Override
  public Object getCellEditorValue()
  {
    return delegate.getCellEditorValue();
  }

  /**
   * Forwards the message from the <code>CellEditor</code> to the
   * <code>delegate</code>.
   * 
   * @see EditorDelegate#isCellEditable(EventObject)
   */
  @Override
  public boolean isCellEditable(EventObject anEvent)
  {
    return delegate.isCellEditable(anEvent);
  }

  /**
   * Forwards the message from the <code>CellEditor</code> to the
   * <code>delegate</code>.
   * 
   * @see EditorDelegate#shouldSelectCell(EventObject)
   */
  @Override
  public boolean shouldSelectCell(EventObject anEvent)
  {
    return delegate.shouldSelectCell(anEvent);
  }

  /**
   * Forwards the message from the <code>CellEditor</code> to the
   * <code>delegate</code>.
   * 
   * @see EditorDelegate#stopCellEditing
   */
  @Override
  public boolean stopCellEditing()
  {
    return delegate.stopCellEditing();
  }

  /**
   * Forwards the message from the <code>CellEditor</code> to the
   * <code>delegate</code>.
   * 
   * @see EditorDelegate#cancelCellEditing
   */
  @Override
  public void cancelCellEditing()
  {
    delegate.cancelCellEditing();
  }

  //
  // Implementing the CellEditor Interface
  //
  /** Implements the <code>TableCellEditor</code> interface. */
  @Override
  public Component getTableCellEditorComponent(JTable table, Object value, boolean isSelected, int row,
      int column)
  {
    delegate.setValue(value);
    return editorComponent;
  }

  //
  // Protected EditorDelegate class
  //

  /**
   * The protected <code>EditorDelegate</code> class.
   */
  protected class EditorDelegate implements ChangeListener, Serializable
  {

    /** The value of this cell. */
    protected Object value;

    /**
     * Returns the value of this cell.
     * 
     * @return the value of this cell
     */
    public Object getCellEditorValue()
    {
      return value;
    }

    /**
     * Sets the value of this cell.
     * 
     * @param value
     *          the new value of this cell
     */
    public void setValue(Object value)
    {
      this.value = value;
    }

    /**
     * Returns true if <code>anEvent</code> is <b>not</b> a
     * <code>MouseEvent</code>. Otherwise, it returns true if the necessary
     * number of clicks have occurred, and returns false otherwise.
     *
     * @param anEvent
     *          the event
     * @return true if cell is ready for editing, false otherwise
     * @see #setClickCountToStart
     * @see #shouldSelectCell
     */
    public boolean isCellEditable(EventObject anEvent)
    {
      if (anEvent instanceof MouseEvent)
      {
        return ((MouseEvent)anEvent).getClickCount() >= clickCountToStart;
      }
      return true;
    }

    /**
     * Returns true to indicate that the editing cell may be selected.
     *
     * @param anEvent
     *          the event
     * @return true
     * @see #isCellEditable
     */
    public boolean shouldSelectCell(EventObject anEvent)
    {
      return true;
    }

    /**
     * Returns true to indicate that editing has begun.
     *
     * @param anEvent
     *          the event
     * @return boolean cell editing
     */
    public boolean startCellEditing(EventObject anEvent)
    {
      return true;
    }

    /**
     * Stops editing and returns true to indicate that editing has stopped. This
     * method calls <code>fireEditingStopped</code>.
     *
     * @return true
     */
    public boolean stopCellEditing()
    {
      fireEditingStopped();
      return true;
    }

    /**
     * Cancels editing. This method calls <code>fireEditingCanceled</code>.
     */
    public void cancelCellEditing()
    {
      fireEditingCanceled();
    }

    @Override
    public void stateChanged(ChangeEvent e)
    {
      TimeCellEditor.this.stopCellEditing();

    }
  }

}
