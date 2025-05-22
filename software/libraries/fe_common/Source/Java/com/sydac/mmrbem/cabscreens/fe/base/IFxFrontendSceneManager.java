/*
 * ==================================================================
 *
 * (C) Copyright 2023 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *
 * ==================================================================
 */
package com.sydac.mmrbem.cabscreens.fe.base;

import com.sydac.mmrbem.cabscreens.fe.app.ApplicationControllerFactory;

import javafx.scene.Scene;

/**
 * handles the creation of a scene. Used in {@link FrontendJFXPanel} Should also
 * be used in the stand-alone version of the FX Application
 *
 * @author ext-vp
 */
public interface IFxFrontendSceneManager
{
  /**
   * Create the scene, loading the named screen, plus any additional handling
   * required.
   *
   * @param screenName
   *          The name of the screen we are wanting to load
   * @param carIndex
   *          The car that we are interested in.
   * @param controllerFactory
   *          controller Factory
   *
   * @return {@link Scene} The created scene
   */
  Scene createScene(String screenName, int carIndex, ApplicationControllerFactory controllerFactory);

  void reset(int carIndex);

  /**
   * @param appWidth
   *          updated application width
   * @param appHeight
   *          updated application height
   */
  default void setSize(double appWidth, double appHeight)
  {}

}
