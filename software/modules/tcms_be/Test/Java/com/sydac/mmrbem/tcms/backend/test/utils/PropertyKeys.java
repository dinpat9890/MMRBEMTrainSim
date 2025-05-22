/*
 * ==================================================================
 *
 * (C) Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.backend.test.utils;

import java.lang.reflect.Field;
import java.lang.reflect.ParameterizedType;
import java.lang.reflect.Type;
import java.text.MessageFormat;

import com.sydac.common.febe.binding.CommsBinding;
import com.sydac.common.febe.binding.CommsInputBindingBuilder;
import com.sydac.common.febe.binding.CommsOutputBindingBuilder;
import com.sydac.common.log.Tracer;
import com.sydac.foundation.PropertyKey;

/**
 * Helpers for {@link CommsInputBindingBuilder} and
 * {@link CommsOutputBindingBuilder}.
 *
 * @author Stanley Mladenov
 */
final class PropertyKeys
{
  static void setKeyName(PropertyKey<?> key, String name)
  {
    try
    {
      Field nameFiled = PropertyKey.class.getDeclaredField("name");//$NON-NLS-1$
      nameFiled.setAccessible(true);
      nameFiled.set(key, name);
      nameFiled.setAccessible(false);

    }
    catch (IllegalArgumentException | IllegalAccessException | NoSuchFieldException | SecurityException e)
    {
      Tracer.getInstance().warning("Cannot set the name of a PropertyKey. This may hamper debugging."); //$NON-NLS-1$
      Tracer.getInstance().debug(e);
    }
  }

  /**
   * Invokes the {@link PropertyBindingProcessor} with all {@link PropertyKey}s.
   */
  static void forEachPropertyKey(Class<?> propertyKeyDefinition, PropertyBindingProcessor processor)
  {
    forEachPropertyKey(propertyKeyDefinition, processor, false);
  }

  /**
   * Invokes the {@link PropertyBindingProcessor} with all {@link PropertyKey}s
   * in the definition interface annotated with {@link CommsBinding}.
   */
  static void forEachBoundPropertyKey(Class<?> propertyKeyDefinition, PropertyBindingProcessor processor)
  {
    forEachPropertyKey(propertyKeyDefinition, processor, true);
  }

  /**
   * Invokes the {@link PropertyBindingProcessor} with all {@link PropertyKey}s
   * in the definition interface annotated with {@link CommsBinding}.
   */
  private static void forEachPropertyKey(Class<?> propertyKeyDefinition, PropertyBindingProcessor processor,
      boolean skipUnbound)
  {
    for (Field f : propertyKeyDefinition.getFields())
    {
      if (f.getType().equals(PropertyKey.class))
      {
        PropertyKey<?> key;

        try
        {
          key = (PropertyKey<?>)f.get(null);
        }
        catch (IllegalArgumentException | IllegalAccessException e)
        {
          throw new IllegalStateException(MessageFormat.format("Cannot access {0} in {1}.", //$NON-NLS-1$
              f.getName(), propertyKeyDefinition), e);
        }

        CommsBinding binding = f.getAnnotation(CommsBinding.class);
        Type propertyType = ((ParameterizedType)f.getGenericType()).getActualTypeArguments()[0];

        if (binding != null)
        {
          String property = binding.property();
          processor.process(f, property, propertyType, key);
        }
        else
        {
          Tracer.getInstance().debugFmt("No %s found on %s in %s", //$NON-NLS-1$
              CommsBinding.class, f.getName(), propertyKeyDefinition);

          if (!skipUnbound)
          {
            processor.process(f, null, propertyType, key);
          }
        }
      }
    }
  }

  @FunctionalInterface
  interface PropertyBindingProcessor
  {
    /**
     * Processes a {@link PropertyKey} with a {@link CommsBinding} annotation.
     *
     * @param field
     *          The field the key is referenced by in the defining interface.
     * @param propertyName
     *          The name of the Comms property that is to be bound (if any).
     * @param propertyType
     *          The type of parameter for the {@link PropertyKey}.
     * @param key
     *          The {@link PropertyKey} which identifies the information.
     */
    void process(Field field, String propertyName, Type propertyType, PropertyKey<?> key);
  }

  private PropertyKeys()
  {
    throw new IllegalStateException("Helper class; cannot construct."); //$NON-NLS-1$
  }
}
