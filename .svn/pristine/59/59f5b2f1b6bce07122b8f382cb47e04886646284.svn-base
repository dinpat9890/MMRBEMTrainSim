/*
 * ==================================================================
 *
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *
 * ==================================================================
 */
package com.sydac.mmrbem.radiointercomplugin.view;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;

import com.sydac.mmrbem.radiointercomplugin.components.CWButton;
import com.sydac.mmrbem.radiointercomplugin.components.CWLabel;

/**
 * <p>
 * Select Car OHP Setup Panel
 *
 * @author mulukg
 *
 */
public class SelectCarOHPPanel extends JPanel
{

  private static final long serialVersionUID = 1L;

  public SelectCarOHPPanel(RadioCommunicationSetupPanel radioCommunicationSetupPanel)
  {

    setLayout(new GridBagLayout());

    GridBagConstraints gbc = new GridBagConstraints();
    int top = 10;
    int left = 3;
    int bottom = 5;
    int right = 3;
    int rowNumber = 0;
    Insets insects = new Insets(top, left, bottom, right);

    Dimension buttonSize = new Dimension(300, 50);
    Dimension labelSize = new Dimension(300, 30);

    JLabel headerTitleLabel = new CWLabel("Select PECU", labelSize); //$NON-NLS-1$
    headerTitleLabel.setBackground(Color.LIGHT_GRAY);

    gbc.fill = GridBagConstraints.HORIZONTAL;
    gbc.insets = insects;
    gbc.gridx = 0;
    gbc.gridy = rowNumber++;
    this.add(headerTitleLabel, gbc);

    for (int i = 1; i < 5; i++)
    {

      JButton ohpBtn = new CWButton("PECU " + i, buttonSize); //$NON-NLS-1$
      setCarOHPBtnAction(radioCommunicationSetupPanel, ohpBtn, i);

      gbc.insets = insects;
      gbc.gridx = 0;
      gbc.gridy = rowNumber++;
      this.add(ohpBtn, gbc);

    }

    JButton backBtn = new CWButton("Back", buttonSize); //$NON-NLS-1$
    setBackBtnAction(radioCommunicationSetupPanel, backBtn);

    gbc.insets = insects;
    gbc.gridx = 0;
    gbc.gridy = rowNumber++;
    this.add(backBtn, gbc);

  }

  private void setCarOHPBtnAction(RadioCommunicationSetupPanel radioCommunicationSetupPanel, JButton carBtn,
      final int ohpId)
  {
    carBtn.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent arg0)
      {
        radioCommunicationSetupPanel.onCarOHPSelectionAction(ohpId);
      }
    });
  }

  
  private void setBackBtnAction(RadioCommunicationSetupPanel radioCommunicationSetupPanel, JButton backBtn  )
  {
    backBtn.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent arg0)
      {
        radioCommunicationSetupPanel.backToActiveOHPPanel();
      }
    });
  }
}
