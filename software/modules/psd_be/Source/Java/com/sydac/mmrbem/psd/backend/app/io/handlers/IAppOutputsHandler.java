/*******************************************************************************
 * (C) Copyright 2022 Oktal-Sydac Pty Ltd., all rights reserved. This is
 * unpublished proprietary source code of Oktal-Sydac. The copyright notice
 * above does not evidence any actual or intended publication of such source
 * code.
 *******************************************************************************/
package com.sydac.mmrbem.psd.backend.app.io.handlers;

import com.sydac.foundation.IPropertySetter;

/**
 * This interface supplies mutators for ApplicationOutputs variables.
 * 
 * @see IPropertySetter
 * @author ext-jadhalp
 *
 */
public interface IAppOutputsHandler extends IPropertySetter
   
{
  void setPsdScreenId(Integer screenId);
}