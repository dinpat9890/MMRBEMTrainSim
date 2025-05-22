/*
 * ==================================================================
 *
 * (C) Copyright 2017 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.fe.base;

import com.sydac.mmrbem.tcms.fe.comms.CommsBinding;

public interface CommsListener
{
  void attachToModel(CommsBinding commsBinding);

  void detachFromModel();
}
