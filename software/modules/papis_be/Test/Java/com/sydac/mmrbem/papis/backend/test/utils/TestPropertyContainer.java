/*
 * ==================================================================
 * 
 * (C) Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.papis.backend.test.utils;

import java.lang.reflect.Type;
import java.util.HashMap;
import java.util.Map;

import com.sydac.foundation.IPropertyListenerManagerBuilder;
import com.sydac.foundation.IPropertyModel;
import com.sydac.foundation.PropertyKey;

public class TestPropertyContainer implements IPropertyModel
{

  private final Map<PropertyKey<?>, Object> dataContainer = new HashMap<>();

  public TestPropertyContainer()
  {}

  public void bindProperty(String property, Type type, PropertyKey<?> key)
  {
    PropertyKeys.setKeyName(key, property);
  }

  @Override
  public <T> void setProperty(PropertyKey<T> key, T value)
  {
    dataContainer.put(key, value);
  }

  @Override
  public void create()
  {

  }

  @SuppressWarnings("unchecked")
  @Override
  public <T> T getProperty(PropertyKey<T> key)
  {
    return (T)dataContainer.get(key);
  }

  @Override
  public IPropertyListenerManagerBuilder newListenerManagerBuilder()
  {
    return null;
  }

  @Override
  public boolean isCreated()
  {
    return true;
  }

  @Override
  public void destroy()
  {

  }
}
