/*
 * ==================================================================
 * 
 * (C) Copyright 2016 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */

package com.sydac.mmrbem.cabscreens.fe.common;

import javafx.beans.property.StringPropertyBase;
import javafx.css.PseudoClass;
import javafx.scene.Node;

/**
 * Implementation to support properties that have multiple states.<br>
 * <br>
 * This entity removes the previous CSS state and sets the new CSS state upon
 * invalidation
 */
public class NodePseudoClassProperty extends StringPropertyBase
{
  Node node;

  String currentState;

  public NodePseudoClassProperty(Node node)
  {
    this.node = node;
  }

  @Override
  protected void invalidated()
  {
    if (currentState != null && currentState.length() > 0)
    {
      node.pseudoClassStateChanged(PseudoClass.getPseudoClass(currentState), false);
    }
    node.pseudoClassStateChanged(PseudoClass.getPseudoClass(get()), true);
    this.currentState = get();
  }

  @Override
  public Object getBean()
  {
    return this;
  }

  @Override
  public String getName()
  {
    return node.getId() + " pseudoClass property"; //$NON-NLS-1$
  }

}
