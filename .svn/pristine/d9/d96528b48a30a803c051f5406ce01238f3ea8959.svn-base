/*
 * ==================================================================
 * 
 * (C) Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.radio.common.data;

/**
 * Wrapper for sorting to work properly.
 * 
 * @author Nazim Oliyath
 * 
 */
public class Entry<T> implements Comparable<Entry<T>>
{
  int index;

  T data;

  public Entry(int index, T data)
  {
    this.index = index;
    this.data = data;
  }

  /**
   * Get index
   * 
   * @return get index
   */
  public int getIndex()
  {
    return index;
  }

  /**
   * Get Data
   * 
   * @return data
   */
  public T getData()
  {
    return data;
  }

  public void setData(T data)
  {
    this.data = data;
  }

  @Override
  public int compareTo(Entry<T> o)
  {
    return this.index - o.index;
  }

  @Override
  public boolean equals(Object obj)
  {
    return (obj instanceof Entry) && (this.hashCode() == obj.hashCode());
  }

  @Override
  public int hashCode()
  {
    return this.index;
  }
}
