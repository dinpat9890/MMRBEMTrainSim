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

import com.sydac.mmrbem.radio.enums.RadioCallGroup;
import com.sydac.mmrbem.radiointercomplugin.components.CWButton;
import com.sydac.mmrbem.radiointercomplugin.components.CWLabel;

/**
 * <p>
 * Select Radio Group Panel
 *
 * @author mulukg
 *
 */
public class RadioGroupCallPanel extends JPanel
{

  private static final long serialVersionUID = 1L;

  public RadioGroupCallPanel(RadioCommunicationSetupPanel radioCommunicationSetupPanel)
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

    JLabel headerTitleLabel = new CWLabel("Select Radio Group", labelSize);
    headerTitleLabel.setBackground(Color.LIGHT_GRAY);

    gbc.fill = GridBagConstraints.HORIZONTAL;
    gbc.insets = insects;
    gbc.gridx = 0;
    gbc.gridy = rowNumber++;
    this.add(headerTitleLabel, gbc);

    JButton mainGroup = new CWButton(RadioCallGroup.MAIN_GROUP_CALL.getText(), buttonSize);
    setGroupCallBtnAction(radioCommunicationSetupPanel, mainGroup, RadioCallGroup.MAIN_GROUP_CALL.getValue());

    gbc.insets = insects;
    gbc.gridx = 0;
    gbc.gridy = rowNumber++;
    this.add(mainGroup, gbc);

    JButton depotGroup = new CWButton(RadioCallGroup.DEPOT_GROUP_CALL.getText(), buttonSize);
    setGroupCallBtnAction(radioCommunicationSetupPanel, depotGroup,
        RadioCallGroup.DEPOT_GROUP_CALL.getValue());

    gbc.insets = insects;
    gbc.gridx = 0;
    gbc.gridy = rowNumber++;
    this.add(depotGroup, gbc);

    JButton shuntGroup = new CWButton(RadioCallGroup.SHUNT_GROUP_CALL.getText(), buttonSize);
    setGroupCallBtnAction(radioCommunicationSetupPanel, shuntGroup,
        RadioCallGroup.SHUNT_GROUP_CALL.getValue());

    gbc.insets = insects;
    gbc.gridx = 0;
    gbc.gridy = rowNumber++;
    this.add(shuntGroup, gbc);

    JButton trainGroup = new CWButton(RadioCallGroup.TRAIN_GROUP_CALL.getText(), buttonSize);
    setGroupCallBtnAction(radioCommunicationSetupPanel, trainGroup,
        RadioCallGroup.TRAIN_GROUP_CALL.getValue());

    gbc.insets = insects;
    gbc.gridx = 0;
    gbc.gridy = rowNumber++;
    this.add(trainGroup, gbc);
    
    JButton backButton = new CWButton("Back", buttonSize);
    setBackBtnAction(radioCommunicationSetupPanel, backButton);
       

    gbc.insets = insects;
    gbc.gridx = 0;
    gbc.gridy = rowNumber++;
    this.add(backButton, gbc);

  }

  private void setGroupCallBtnAction(RadioCommunicationSetupPanel radioCommunicationSetupPanel,
      JButton carBtn, final int groupId)
  {
    carBtn.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent arg0)
      {
        radioCommunicationSetupPanel.startRadioGroupCall(groupId);
      }
    });
  }

  private void setBackBtnAction(RadioCommunicationSetupPanel radioCommunicationSetupPanel,
      JButton carBtn)
  {
    carBtn.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent arg0)
      {
       radioCommunicationSetupPanel.backToStartRadioCallPanel();
      }
    });
  }
  
}
