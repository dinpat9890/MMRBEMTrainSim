/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */

package com.sydac.mmrbem.papis.backend.logic.handler;

import com.sydac.mmrbem.papis.common.ScreenId;

/**
 * Handles screen change requests.
 * 
 * @author joshian
 *
 */
@FunctionalInterface
public interface IScreenChangeHandler
{

  /**
   * Request for a screen change.
   * 
   * @param newScreenId
   *          required screen id
   */
  void requestScreenChange(ScreenId newScreenId);

}
