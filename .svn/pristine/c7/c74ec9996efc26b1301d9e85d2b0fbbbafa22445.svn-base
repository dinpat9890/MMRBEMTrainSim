/*
 * ================================================================== (C)
 * Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.dmi.backend.vehicle.request.handler;

import java.util.Collections;
import java.util.List;

import com.sydac.common.log.Tracer;
import com.sydac.mmrbem.dmi.common.data.Entry;

/**
 * 
 * @author joshian
 */
@FunctionalInterface
public interface IDMIVehicleOutputsRequestHandler<K>
{
  static final Tracer LOGGER = Tracer.getInstance();

  /**
   * 
   * @param request
   *          request
   */
  public void handleRequest(K request);

  /**
   * 
   * @param aList
   *          aList
   * @param carIndex
   *          carIndex
   * @param type
   *          type
   * @param <E>
   *          the type variable
   * @return E the type variable
   * @throws InstantiationException
   *           instantiation exception
   */
  static <E> E getVehicleStatusDo(List<Entry<E>> aList, int carIndex, Class<E> type)
      throws InstantiationException
  {
    try
    {
      synchronized (aList)
      {
        return aList.stream().filter(entry -> entry.getIndex() == carIndex).findFirst().map(Entry::getData)
            .orElse(type.newInstance());
      }
    }
    catch (InstantiationException | IllegalAccessException e)
    {
      LOGGER.info(e);
      throw new InstantiationException(e.getMessage());
    }
  }

  /**
   * Generic method to set the modified DO object in to the collection and sort.
   * 
   * @param list
   *          list
   * @param statusDo
   *          statusDo
   * @param vehicleIndex
   *          vehicleIndex
   * @param <E>
   *          the type variable
   */
  static <E> void updateVehicleStatusDOList(List<Entry<E>> list, E statusDo, int vehicleIndex)
  {
    synchronized (list)
    {
      if (list.stream().anyMatch(entry -> entry.getIndex() == vehicleIndex))
      {
        list.stream().filter(entry -> entry.getIndex() == vehicleIndex)
            .forEach(entry -> entry.setData(statusDo));
      }
      else
      {
        list.add(new Entry<>(vehicleIndex, statusDo));
        Collections.sort(list);
      }
    }
  }
}
