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
 * Radio Intercom Call Start Panel
 *
 * @author mulukg
 *
 */
public class StartRadioCallPanel extends JPanel
{

  private static final long serialVersionUID = 1L;

  public StartRadioCallPanel(RadioCommunicationSetupPanel radioCommunicationSetupPanel)
  {
    setLayout(new GridBagLayout());

    GridBagConstraints gbc = new GridBagConstraints();
    int top = 10;
    int left = 3;
    int bottom = 10;
    int right = 3;
    int rowNumber = 0;
    Insets insects = new Insets(top, left, bottom, right);

    Dimension buttonSize = new Dimension(300, 50);
    Dimension labelSize = new Dimension(300, 30);

    JLabel headerTitleLabel = new CWLabel("Radio Call", labelSize);
    headerTitleLabel.setBackground(Color.LIGHT_GRAY);

    JButton halfDuplexCallBtn = new CWButton("Half Duplex Call", buttonSize);
    halfDuplexCallBtn.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent arg0)
      {
        radioCommunicationSetupPanel.onStartHalfDuplexCallBtnAction();
      }
    });

    JButton emergencyCallBtn = new CWButton("Emergency Call", buttonSize);
    emergencyCallBtn.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent arg0)
      {
        radioCommunicationSetupPanel.onEmergencyCallBtnAction();
      }
    });

    JButton fullDuplexCallBtn = new CWButton("Full Duplex Call", buttonSize);

    fullDuplexCallBtn.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent arg0)
      {
        radioCommunicationSetupPanel.onFullDuplexCallBtnAction();
      }
    });

    JButton groupCallBtn = new CWButton("Group Call", buttonSize);

    groupCallBtn.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent arg0)
      {
        radioCommunicationSetupPanel.onGroupCallBtnAction();
      }
    });
    
    JButton backBtn = new CWButton("Back", buttonSize);

    backBtn.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent arg0)
      {
        radioCommunicationSetupPanel.backToMainPanel();
      }
    });

    gbc.fill = GridBagConstraints.HORIZONTAL;
    gbc.insets = insects;
    gbc.gridx = 0;
    gbc.gridy = rowNumber++;
    this.add(headerTitleLabel, gbc);

    gbc.insets = insects;
    gbc.gridx = 0;
    gbc.gridy = rowNumber++;
    this.add(halfDuplexCallBtn, gbc);

    gbc.gridx = 0;
    gbc.gridy = rowNumber++;
    this.add(fullDuplexCallBtn, gbc);

    gbc.gridx = 0;
    gbc.gridy = rowNumber++;
    this.add(emergencyCallBtn, gbc);

    gbc.gridx = 0;
    gbc.gridy = rowNumber++;
    this.add(groupCallBtn, gbc);
    
    gbc.gridx = 0;
    gbc.gridy = rowNumber++;
    this.add(backBtn, gbc);

  }

}
