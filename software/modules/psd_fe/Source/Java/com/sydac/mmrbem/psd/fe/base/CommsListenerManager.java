/*
 * =======================================================================
 * 
 * (C) Copyright 2020 Oktal Sydac. all rights reserved. This is unpublished
 * proprietary source code. The copyright notice above does not evidence any
 * actual or intended publication of such source code.
 * 
 * =======================================================================
 */
package com.sydac.mmrbem.psd.fe.base;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import com.sydac.mmrbem.psd.fe.comms.CommsBinding;


public final class CommsListenerManager
{
  private static final Map<Integer, List<CommsListener>> commsListenerList = Collections
      .synchronizedMap(new HashMap<>());

  private CommsListenerManager()
  {}

  public static void addListener(int carIndex, CommsListener listener)
  {
    if (!commsListenerList.containsKey(carIndex))
    {
      commsListenerList.put(carIndex, new ArrayList<CommsListener>());
    }

    commsListenerList.get(carIndex).add(listener);
  }

  public static void clear()
  {
    commsListenerList.clear();
  }

  public static void detachFromModel(int carIndex)
  {
    if (commsListenerList.containsKey(carIndex))
    {
      commsListenerList.get(carIndex).forEach(CommsListenerManager::detachFromModel);
    }
  }

  public static void attachToModel(int carIndex, CommsBinding commsBinding)
  {
    if (commsListenerList.containsKey(carIndex))
    {
      commsListenerList.get(carIndex).forEach(l -> l.attachToModel(commsBinding));
    }
  }

  private static void detachFromModel(CommsListener listener)
  {
    listener.detachFromModel();
  }
}
