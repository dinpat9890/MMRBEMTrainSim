/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.cabscreens.fe.app.button;

import com.sydac.mmrbem.cabscreens.fe.common.NodePseudoClassProperty;
import com.sydac.mmrbem.cabscreens.fe.gui.AbstractController;

import javafx.scene.control.Button;

public class RuntimeButton extends Button
{

  private double identifierValue;

  private NodePseudoClassProperty nodePseudoClassProperty;

  /**
   * 
   * @param commsNumber
   *          commsNumber
   * @param identifierValue
   *          identifierValue
   */
  public RuntimeButton(String commsNumber, double identifierValue)
  {
    getProperties().put(AbstractController.COMMS_NUMBER_KEY, commsNumber);
    getProperties().put(ButtonBehavior.KEY_PRESS_VALUE_KEY, String.valueOf(identifierValue));
    this.identifierValue = identifierValue;
  }

  public NodePseudoClassProperty getNodePseudoClassProperty()
  {
    return nodePseudoClassProperty;
  }

  public void setNodePseudoClassProperty(NodePseudoClassProperty nodePseudoClassProperty)
  {
    this.nodePseudoClassProperty = nodePseudoClassProperty;
  }

  public final double getIdentifierValue()
  {
    return identifierValue;
  }
}
