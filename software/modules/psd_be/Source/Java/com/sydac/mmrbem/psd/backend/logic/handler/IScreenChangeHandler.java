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

import com.sydac.mmrbem.psd.common.ScreenId;

/**
 * Handles screen change requests.
 * 
 * @author joshian
 *
 */
@FunctionalInterface
public interface IScreenChangeHandler
{

  void requestScreenChange(ScreenId newScreenId);

}
