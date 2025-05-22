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
 * Radio Intercom Call Setup Panel
 *
 * @author mulukg
 *
 */
public class RadioIntercomPanel extends JPanel
{

  private static final long serialVersionUID = 1L;

  public RadioIntercomPanel(RadioCommunicationSetupPanel radioCommunicationSetupPanel)
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

    JLabel headerTitleLabel = new CWLabel("Radio and Intercom", labelSize);
    headerTitleLabel.setBackground(Color.LIGHT_GRAY);

    JButton startRadioCallBtn = new CWButton("Start Radio Call", buttonSize);
    startRadioCallBtn.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent arg0)
      {
        radioCommunicationSetupPanel.onStartRadioCallBtnAction();
      }
    });

    JButton cabToCabInercomBtn = new CWButton("Cab to Cab Intercom", buttonSize);
    cabToCabInercomBtn.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent arg0)
      {
        radioCommunicationSetupPanel.onCabToCabIntercomBtnAction();
      }
    });

    JButton activeOhpBtn = new CWButton("PECU Call", buttonSize);

    activeOhpBtn.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent arg0)
      {
        radioCommunicationSetupPanel.onActivateOHPBtnAction();
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
    this.add(startRadioCallBtn, gbc);

    gbc.gridx = 0;
    gbc.gridy = rowNumber++;
    this.add(cabToCabInercomBtn, gbc);

    gbc.gridx = 0;
    gbc.gridy = rowNumber++;
    this.add(activeOhpBtn, gbc);

  }

}
