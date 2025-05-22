/*
 * ==================================================================
 *
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *
 * ==================================================================
 */
package com.sydac.mmrbem.radiointercomplugin.components;

import java.awt.Dimension;

import javax.swing.JLabel;
import javax.swing.SwingConstants;

/**
 * <p>
 * Custom Widget for Lable
 *
 * @author mulukg
 *
 */
public class CWLabel extends JLabel
{
  /**
   * 
   */
  private static final long serialVersionUID = 1L;

  public CWLabel(String labelName, Dimension size)
  {
    setPreferredSize(size);
    setSize(size);
    setMaximumSize(size);
    setMinimumSize(size);
    setHorizontalAlignment(SwingConstants.CENTER);
    setVerticalAlignment(SwingConstants.CENTER);
    setOpaque(true);
    setText(labelName);
  }
}
