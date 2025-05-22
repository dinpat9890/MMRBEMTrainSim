/*******************************************************************************
 * (C) Copyright 2022 Oktal-Sydac Pty Ltd., all rights reserved. This is
 * unpublished proprietary source code of Oktal-Sydac. The copyright notice
 * above does not evidence any actual or intended publication of such source
 * code.
 *******************************************************************************/
package com.sydac.mmrbem.papis.backend.app.io.handlers;

import com.sydac.foundation.IPropertySetter;

/**
 * This interface supplies mutators for ApplicationOutputs variables.
 * 
 * @see IPropertySetter
 * @author joshian
 *
 */
public interface IAppOutputsHandler extends IPropertySetter
{
  void setCurrentScreenId(Integer screenId);

  void setPopupScreenId(Integer popupId);
}