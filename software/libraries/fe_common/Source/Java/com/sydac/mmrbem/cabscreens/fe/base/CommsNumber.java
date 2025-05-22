/*
 * ==================================================================
 * 
 * (C) Copyright 2017 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.cabscreens.fe.base;

import java.lang.annotation.ElementType;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;

import com.sydac.mmrbem.cabscreens.fe.gui.AbstractController;

import javafx.scene.Node;

/**
 * Each UI element (JavaFx Control) that accepts user-inputs has to be
 * registered with COMMS. Applying this annotation on a Control and specifying
 * its corresponding COMMS number will register the COMMS number name into the
 * Control.<br>
 * The COMMS number of the Control can be accessed by looking up the
 * {@link AbstractController#COMMS_NUMBER_KEY} key properties of the Control (
 * {@link Node#getProperties()})
 * 
 * @author Nazim Oliyath
 *
 */
@Retention(RetentionPolicy.RUNTIME)
@Target(ElementType.FIELD)
public @interface CommsNumber {

  public String value();

}
