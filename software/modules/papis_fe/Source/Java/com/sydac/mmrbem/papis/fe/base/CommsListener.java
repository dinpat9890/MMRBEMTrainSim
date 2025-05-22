/*
 * ==================================================================
 *
 * (C) Copyright 2017 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *
 * ==================================================================
 */
package com.sydac.mmrbem.papis.fe.base;

import com.sydac.mmrbem.papis.fe.comms.CommsBinding;

public interface CommsListener
{
  void attachToModel(CommsBinding commsBinding);

  void detachFromModel();
}
