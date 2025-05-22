/*
 * ==================================================================
 *
 * (C) Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *
 * ==================================================================
 */
package com.sydac.mmrbem.psd.backend.test.utils;

import java.lang.reflect.Type;
import java.util.HashMap;
import java.util.Map;
import java.util.Objects;
import java.util.function.Function;

import com.sydac.core.runtimedata.CoreObjectConstants.IOData;
import com.sydac.core.runtimedata.HubIO;
import com.sydac.foundation.IPropertySetter;
import com.sydac.foundation.PropertyKey;
import com.sydac.simcomms.CObject;
import com.sydac.simcomms.CRaw;

public final class TestOutputBindingBuilder
{
  private final Class<?> propertyKeyDefinition;

  private final Map<Class<? extends Enum<?>>, Function<Enum<?>, Integer>> enumConverters = new HashMap<>();

  private final Map<Type, Function<?, Double>> numberConverters = new HashMap<>();

  private final Map<Type, Function<?, byte[]>> rawConverters = new HashMap<>();

  private boolean useHubProperties;

  /**
   * Creates a builder for a {@link IPropertySetter} which sends updates to
   * Comms.
   *
   * @param aPropertyKeyDefinition
   *          An interface defining {@link PropertyKey}s annotated with
   *          {@link AbstractCommsBinding}s to describe their mapping to Comms.
   */
  public TestOutputBindingBuilder(Class<?> aPropertyKeyDefinition)
  {
    propertyKeyDefinition = Objects.requireNonNull(aPropertyKeyDefinition);

    numberConverters.put(Boolean.class, (Boolean b) -> b ? 1.0 : 0.0);
    numberConverters.put(Byte.class, (Byte b) -> b.doubleValue());
    numberConverters.put(Character.class, (Character c) -> Double.valueOf(c.charValue()));
    numberConverters.put(Short.class, (Short s) -> s.doubleValue());
    numberConverters.put(Integer.class, (Integer i) -> i.doubleValue());
    numberConverters.put(Long.class, (Long l) -> l.doubleValue());
    numberConverters.put(Float.class, (Float f) -> f.doubleValue());
    numberConverters.put(Double.class, (Double d) -> d.doubleValue());

    rawConverters.put(String.class, (String s) -> s.getBytes());
  }

  /**
   * Configures the builder to produce bindings for an {@link IOData} object,
   * rather than a "regular" {@link CObject}.
   *
   * @return this, to allow chaining of calls.
   */
  public TestOutputBindingBuilder forIODataBinding()
  {
    useHubProperties = true;
    return this;
  }

  /**
   * Sets a {@link Function} for converting a {@link CRaw} into the desired
   * type.
   *
   * @param type
   *          The type of enum we are converting to.
   * @param converter
   *          The conversion function.
   * @return this, to allow chaining of calls.
   */
  @SuppressWarnings({ "unchecked", "rawtypes" })
  public <T extends Enum<T>> TestOutputBindingBuilder setEnumConverter(Class<T> type,
      Function<Enum<T>, Integer> converter)
  {
    if (!type.isEnum())
    {
      throw new IllegalArgumentException("The type must be an enum"); //$NON-NLS-1$
    }

    enumConverters.put(type, (Function)converter);
    return this;
  }

  /**
   * Sets a {@link Function} for converting a {@link CRaw} into the desired
   * type.
   *
   * @param type
   *          The type of model property we are converting to.
   * @param converter
   *          The conversion function.
   * @return this, to allow chaining of calls.
   */
  public <T> TestOutputBindingBuilder setRawConverter(Class<T> type, Function<?, byte[]> converter)
  {
    rawConverters.put(type, converter);
    return this;
  }

  /**
   * Sets a {@link Function} for converting a {@link CRaw} into the desired
   * type. Note that {@link #setRawConverter(Class, Function)} is a safer way to
   * do this, but this method may be more straightforward to use for
   * parameterised types.
   *
   * @param type
   *          The type of model property we are converting to.
   * @param converter
   *          The conversion function.
   * @return this, to allow chaining of calls.
   */
  public TestOutputBindingBuilder setRawConverter(Type type, Function<?, byte[]> converter)
  {
    rawConverters.put(type, converter);
    return this;
  }

  /**
   * Builds a {@link IPropertySetter} using the {@link PropertyKey}s in the
   * interface supplied at construction.
   *
   * @return a {@link IPropertySetter} for setting Comms properties.
   */
  public TestPropertyContainer build()
  {
    TestPropertyContainer setter = new TestPropertyContainer();

    PropertyKeys.forEachBoundPropertyKey(propertyKeyDefinition,
        (f, property, type, key) -> setter.bindProperty(contextBasedPropertyName(property), type, key));

    return setter;
  }

  private String contextBasedPropertyName(String property)
  {
    return useHubProperties ? HubIO.createIOPropertyName(property) : property;
  }

}
