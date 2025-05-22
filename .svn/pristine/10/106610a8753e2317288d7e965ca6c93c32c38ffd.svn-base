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
 * Active OHP Setup Panel
 *
 * @author mulukg
 *
 */
public class ActiveOHPPanel extends JPanel
{

  private static final long serialVersionUID = 1L;

  private RadioCommunicationSetupPanel radioCommunicationSetupPanel;

  private JPanel carPanel = new JPanel();

  private Insets insects;

  public ActiveOHPPanel(RadioCommunicationSetupPanel radioCommunicationSetupPanel)
  {
    this.radioCommunicationSetupPanel = radioCommunicationSetupPanel;
    setLayout(new GridBagLayout());
    carPanel.setLayout(new GridBagLayout());

    GridBagConstraints gbc = new GridBagConstraints();
    int top = 5;
    int left = 3;
    int bottom = 5;
    int right = 3;
    int rowNumber = 0;
    insects = new Insets(top, left, bottom, right);

    Dimension labelSize = new Dimension(300, 30);

    JLabel headerTitleLabel = new CWLabel("Select Car", labelSize); //$NON-NLS-1$
    headerTitleLabel.setBackground(Color.LIGHT_GRAY);

    gbc.fill = GridBagConstraints.HORIZONTAL;
    gbc.insets = insects;
    gbc.gridx = 0;
    gbc.gridy = rowNumber++;
    this.add(headerTitleLabel, gbc);

    gbc.fill = GridBagConstraints.HORIZONTAL;
    gbc.insets = insects;
    gbc.gridx = 0;
    gbc.gridy = rowNumber++;
    this.add(carPanel, gbc);

  }

  private void setCarBtnAction(RadioCommunicationSetupPanel radioCommunicationSetupPanel, JButton carBtn,
      final int carIndex)
  {
    carBtn.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent arg0)
      {
        radioCommunicationSetupPanel.onCarSelectionAction(carIndex);
      }
    });
  }

  private void setMultiplePecuCallAction(RadioCommunicationSetupPanel radioCommunicationSetupPanel,
      JButton multiPecuBtn)
  {
    multiPecuBtn.addActionListener(new ActionListener() {

      @Override
      public void actionPerformed(ActionEvent e)
      {
        radioCommunicationSetupPanel.onMultiplePecuCallSelectionAction();
      }
    });
  }
  
  private void setBackBtnAction(RadioCommunicationSetupPanel radioCommunicationSetupPanel,
      JButton backBtn)
  {
    backBtn.addActionListener(new ActionListener() {

      @Override
      public void actionPerformed(ActionEvent e)
      {
        radioCommunicationSetupPanel.backToMainPanel();
      }
    });
  }

  public void refresh()
  {

    carPanel.removeAll();

    GridBagConstraints gbc = new GridBagConstraints();

    Dimension buttonSize = new Dimension(300, 43);

    int rowNumber = 0;

    for (int i = 1; i < radioCommunicationSetupPanel.getNoOfVehicles() + 1; i++)
    {
      JButton carBtn = new CWButton("Car " + i, buttonSize); //$NON-NLS-1$
      setCarBtnAction(radioCommunicationSetupPanel, carBtn, i);

      gbc.insets = insects;
      gbc.gridx = 0;
      gbc.gridy = rowNumber++;
      carPanel.add(carBtn, gbc);

    }

    JButton multiPecuBtn = new CWButton("Multiple PECU Call", buttonSize); //$NON-NLS-1$
    setMultiplePecuCallAction(radioCommunicationSetupPanel, multiPecuBtn);

    gbc.insets = insects;
    gbc.gridx = 0;
    gbc.gridy = rowNumber++;
    carPanel.add(multiPecuBtn, gbc);
    
    JButton backBtn = new CWButton("Back", buttonSize); //$NON-NLS-1$
    setBackBtnAction(radioCommunicationSetupPanel, backBtn);

    gbc.insets = insects;
    gbc.gridx = 0;
    gbc.gridy = rowNumber;
    carPanel.add(backBtn, gbc);

    carPanel.revalidate();
    carPanel.repaint();

  }

}
