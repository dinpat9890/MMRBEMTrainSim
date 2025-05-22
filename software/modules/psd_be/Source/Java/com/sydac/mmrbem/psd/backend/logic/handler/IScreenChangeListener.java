/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.psd.backend.logic.handler;

/**
 * Entities that would like to be informed when a particular screen has been
 * changed have to implement this interface and register with the
 * {@link ScreenChangeHandler}
 * 
 */
public interface IScreenChangeListener
{

  /**
   * Notifies on entering screen with id screenId
   * 
   * @param screenId
   *          Screen Id
   */
  void onEnteringScreen(int screenId);

  /**
   * Notifies on leaving screen with id screenId
   * 
   * @param screenId
   *          Screen Id
   */
  void onLeavingScreen(int screenId);
}
