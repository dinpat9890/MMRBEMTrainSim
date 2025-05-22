/*
 * ==================================================================
 * 
 * (C) Copyright 2017 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */

package com.sydac.mmrbem.cabscreens.fe.common;

import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.css.PseudoClass;
import javafx.scene.Node;

/**
 * Implementation to support selected state update.
 * <br>
 * Every node will specify the Pseudo class which will be set/removed based on
 * the boolean property.
 */
public class SelectedPseudoClassProperty implements ChangeListener<Boolean>
{
  private Node node;

  private PseudoClass customPseudoClass;

  /**
   * Instantiates a new selected pseudo class property.
   *
   * @param node the node
   * @param pseudoClassName the pseudo class name
   * @param initialValue the initial value
   */
  public SelectedPseudoClassProperty(Node node, String pseudoClassName, boolean initialValue)
  {
    this.node = node;
    this.customPseudoClass = PseudoClass.getPseudoClass(pseudoClassName);
    this.node.pseudoClassStateChanged(customPseudoClass, initialValue);
  }

  @Override
  public void changed(ObservableValue<? extends Boolean> observable, Boolean oldValue, Boolean newValue)
  {
    this.node.pseudoClassStateChanged(customPseudoClass, oldValue);
    this.node.pseudoClassStateChanged(customPseudoClass, newValue);
  }

}
