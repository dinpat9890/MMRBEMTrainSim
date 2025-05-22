/*
 * ==================================================================
 *
 * (C) Copyright 2018 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *
 * ==================================================================
 */
package com.sydac.simulatormanager.plugin.timetable.ui.components;

import java.awt.Color;
import java.awt.Component;
import java.awt.Container;
import java.awt.Font;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.event.FocusAdapter;
import java.awt.event.FocusEvent;
import java.awt.event.FocusListener;
import java.util.ArrayList;
import java.util.EnumMap;
import java.util.List;
import java.util.Map;

import javax.swing.JComponent;
import javax.swing.JFormattedTextField;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JSpinner;
import javax.swing.JSpinner.DefaultEditor;
import javax.swing.SpinnerNumberModel;
import javax.swing.SwingUtilities;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;

/**
 * Presents 4 spinners for editing a duration.
 * <p>
 *
 * This doesn't send focus lost events, because {@link JSpinner}s don't normally
 * do that. A spinner consists of several components (which aren't defined), and
 * each must be listened to to handle focus lost. This could be added (by
 * walking over the descendants of this component).
 * <p>
 *
 * A {@link ChangeEvent} is fired for each field change.
 * <p>
 *
 * {@link #getValue() value} should be bound properties, but currently aren't.
 * <p>
 *
 * This assumes that everyone around the world types the time in the same way.
 * <p>
 *
 * You can't enter a leap second.
 * <p>
 *
 * @author presserd
 * @author johnsh
 */
public class TimeField extends JPanel
{

  private static final String TEXT_FORMAT = "%d:%02d:%02d:%02d"; //$NON-NLS-1$

  private enum Type
  {
    DAYS, HOURS, MINUTES, SECONDS
  }

  private Map<Type, JSpinner> spinners = new EnumMap<>(Type.class);

  private List<ChangeListener> changeListeners = new ArrayList<>();

  /**
   * Sends change events to listeners on THIS component when one of the fields
   * changes
   */
  private ChangeListener fieldChangeListener = new ChangeListener() {
    @Override
    public void stateChanged(ChangeEvent e)
    {
      fireStateChanged();
    }
  };

  public TimeField()
  {
    super(new GridBagLayout());

    JSpinner dayEditor = new JSpinner(new SpinnerNumberModel(0, 0, 364, 1));
    JSpinner hourEditor = new JSpinner(new SpinnerNumberModel(0, 0, 23, 1));
    JSpinner minuteEditor = new JSpinner(new SpinnerNumberModel(0, 0, 59, 1));
    JSpinner secondEditor = new JSpinner(new SpinnerNumberModel(0, 0, 59, 1));
    hourEditor.setEditor(new JSpinner.NumberEditor(hourEditor, "00")); //$NON-NLS-1$
    minuteEditor.setEditor(new JSpinner.NumberEditor(minuteEditor, "00")); //$NON-NLS-1$
    secondEditor.setEditor(new JSpinner.NumberEditor(secondEditor, "00")); //$NON-NLS-1$

    spinners.put(Type.DAYS, dayEditor);
    spinners.put(Type.HOURS, hourEditor);
    spinners.put(Type.MINUTES, minuteEditor);
    spinners.put(Type.SECONDS, secondEditor);

    // Java 1.5 displays spinners (and formatted text fields) differently if
    // they have a format set
    Font spinnerFont = ((JSpinner.DefaultEditor)hourEditor.getEditor()).getTextField().getFont();
    ((JSpinner.DefaultEditor)minuteEditor.getEditor()).getTextField().setFont(spinnerFont);
    ((JSpinner.DefaultEditor)secondEditor.getEditor()).getTextField().setFont(spinnerFont);

    GridBagConstraints c = new GridBagConstraints();
    c.fill = GridBagConstraints.BOTH;

    for (JSpinner s : spinners.values())
    {
      c.weightx = 1;
      c.weighty = 1;
      add(s, c);
      // Add the separator if necessary
      if (s != secondEditor)
      {
        c.weightx = 0;
        add(new JLabel(" : "), c); //$NON-NLS-1$ (should be localized?)
      }

      s.addChangeListener(fieldChangeListener);
      // As FocusListener should be applied on textField component of
      // spinner.Adding listener to all spinners
      JComponent editor = s.getEditor();
      if (editor instanceof DefaultEditor)
      {
        JFormattedTextField textField = ((DefaultEditor)editor).getTextField();
        textField.addFocusListener(focuslistener);
      }
    }
  }

  /**
   * focusListener will allow timeField's spinner components to highlights when
   * it is focus on or tab on.
   */
  private final FocusListener focuslistener = new FocusAdapter() {
    @Override
    public void focusGained(final FocusEvent evt)
    {
      SwingUtilities.invokeLater(() -> {
        Object eventSource = evt.getSource();
        if (eventSource instanceof JFormattedTextField)
        {
          ((JFormattedTextField)eventSource).selectAll();
        }
      });
    }
  };

  /**
   * 
   * @return the duration in seconds
   */
  public Long getValue()
  {
    long days = (int)spinners.get(Type.DAYS).getValue();
    long hours = (int)spinners.get(Type.HOURS).getValue();
    long mins = (int)spinners.get(Type.MINUTES).getValue();
    long secs = (int)spinners.get(Type.SECONDS).getValue();
    return (days * 86400 + hours * 3600 + mins * 60 + secs);
  }

  /**
   * 
   * @param durationInSeconds
   *          in seconds
   */
  public void setValue(Long durationInSeconds)
  {
    long days = durationInSeconds / 86400;
    long hours = (durationInSeconds % 86400) / 3600;
    long minutes = (durationInSeconds % 86400 % 3600) / 60;
    long seconds = (durationInSeconds % 60);
    setText(String.format(TEXT_FORMAT, days, hours, minutes, seconds)); // $NON-NLS-1$
  }

  /**
   * Accepts a value as a string in the format h:mm:ss.
   * 
   * @param s
   *          time
   */
  public void setText(String s)
  {
    // Sanity checks
    if (s.trim().length() == 0)
      return;

    String[] parts = s.split(":"); //$NON-NLS-1$
    if (parts.length < 4)
      throw new IllegalArgumentException("There isn't 4 parts in " + s); //$NON-NLS-1$

    // Need to suppress these intermediate changes so the update appears atomic
    for (JSpinner spinner : spinners.values())
    {
      spinner.removeChangeListener(fieldChangeListener);
    }

    // Perform the actual update
    try
    {
      for (int i = 0; i < 4; i++)
      {
        int v = Integer.parseInt(parts[i]);
        JSpinner spinner = spinners.get(Type.values()[i]);
        int max = (Integer)((SpinnerNumberModel)spinner.getModel()).getMaximum();
        if (v > max)
          throw new IllegalArgumentException(
              String.format("The value %d for %s is invalid", v, Type.values()[i])); //$NON-NLS-1$
        spinner.setValue(v);
      }
    }
    finally
    {
      // Reattach internal listeners and notify our listeners
      for (JSpinner spinner : spinners.values())
      {
        spinner.addChangeListener(fieldChangeListener);
      }

      fireStateChanged();
    }
  }

  public void addChangeListener(ChangeListener l)
  {
    changeListeners.add(l);
  }

  public void removeChangeListener(ChangeListener l)
  {
    changeListeners.remove(l);
  }

  @Override
  public void setForeground(Color fg)
  {
    for (Component c : getComponents())
    {
      c.setForeground(fg);
    }
    super.setForeground(fg);
  }

  @Override
  public void setBackground(Color bg)
  {
    for (Component c : getComponents())
    {
      c.setBackground(bg);
    }
    super.setBackground(bg);
  }

  protected void fireStateChanged()
  {
    ChangeEvent e = new ChangeEvent(this);
    for (ChangeListener l : changeListeners)
      l.stateChanged(e);
  }

  @Override
  public void setEnabled(boolean enabled)
  {
    super.setEnabled(enabled);

    // Walk over the children, so the buttons and text fields are enabled too
    setTreeEnabled(this, enabled);
  }

  private void setTreeEnabled(Component c, boolean enabled)
  {
    if (c != this)
      c.setEnabled(enabled);
    if (c instanceof Container)
      for (Component child : ((Container)c).getComponents())
        setTreeEnabled(child, enabled);
  }

  @Override
  public void setToolTipText(String text)
  {
    super.setToolTipText(text);
    setToolTipText(this, text);
  }

  private void setToolTipText(JComponent c, String text)
  {
    if (c != this)
      c.setToolTipText(text);
    for (Component child : c.getComponents())
      if (child instanceof JComponent) // probably always true
        setToolTipText((JComponent)child, text);
  }
}
