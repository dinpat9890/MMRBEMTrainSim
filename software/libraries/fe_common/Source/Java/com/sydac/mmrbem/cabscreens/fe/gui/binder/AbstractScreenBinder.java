/*
 * ==================================================================
 * 
 * (C) Copyright 2016 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.cabscreens.fe.gui.binder;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Objects;
import java.util.function.Consumer;

import com.google.protobuf.InvalidProtocolBufferException;
import com.sydac.common.log.Tracer;
import com.sydac.mmrbem.cabscreens.fe.base.ApplicationFactory;
import com.sydac.mmrbem.cabscreens.fe.base.IFrontendDataModel;

/**
 * Abstract class for the Screen Binders. This abstraction has the
 * responsibility of using the correct {@link IFrontendDataModel} based on the
 * car index.<br>
 * <br>
 * 
 */
public abstract class AbstractScreenBinder
{
  protected final int carIndex;

  protected final IFrontendDataModel frontendDataModel;

  protected Collection<ProtobufBinding<?>> rawBindings = new ArrayList<>();
  
  protected Collection<NumberBinding> numberBindings = new ArrayList<>();

  /**
   * Constructor
   * 
   * @param carIndex carIndex
   */
  public AbstractScreenBinder(int carIndex)
  {
    this.carIndex = carIndex;
    frontendDataModel = ApplicationFactory.getFrontendDataModel(carIndex);
  }

  /**
   * Concrete class will have to implement this method to bind onto required
   * data from the {@link IFrontendDataModel}
   */
  public abstract void doBinding();

  protected void doProtobufBinding(ProtobufBinding<?> b)
  {
    b.bind();
  }

  protected void doProtobufUpdate(ProtobufBinding<?> b)
  {
    b.update();
  }

  /**
   * Interface for parsing Protobuf data structures. Usually implemented by
   * invoking {@code parseFrom()} on the target type.
   *
   * @param <T>
   *          The Protobuf-generated data type being parsed.
   */
  @FunctionalInterface
  protected interface Parser<T>
  {
    T parse(byte[] data) throws InvalidProtocolBufferException;
  }

  /**
   * Helper for binding protobuf-serialised data to Comms raws.
   *
   * @param <T>
   *          The Protobuf-generated data type being bound.
   */
  public class ProtobufBinding<T>
  {
    private final String commsPropertyName;

    private final Parser<T> parser;

    private final Consumer<T> outputHandler;

    public ProtobufBinding(String aPropertyName, Parser<T> aParser, Consumer<T> aOutputHandler)
    {
      commsPropertyName = Objects.requireNonNull(aPropertyName);
      parser = Objects.requireNonNull(aParser);
      outputHandler = Objects.requireNonNull(aOutputHandler);
    }

    void bind()
    {
      frontendDataModel.bindIORawData(commsPropertyName, this::update);
    }

    protected void update()
    {
      outputHandler.accept(tryParse(getRaw(commsPropertyName)));
    }

    private byte[] getRaw(String aRawName)
    {
      return frontendDataModel.getIORawData(aRawName);
    }

    /**
     * Attempts to parse a Protobuf object from raw data. Logs problems if there
     * are any.
     *
     * @param data
     *          Serialised data.
     * @return The deserialised object.
     */
    private T tryParse(byte[] data)
    {
      if (data.length > 1)
      {
        try
        {
          return parser.parse(data);
        }
        catch (InvalidProtocolBufferException e)
        {
          Tracer.getInstance().error(e);
        }
      }

      return null;
    }
  }

  public String getStringFromBytes(byte[] input){
    String stringEquivalent = new String(input);
    return stringEquivalent;
  }
  
  /**
   * Helper for binding protobuf-serialised data to Comms raws.
   * 
   */
  protected class NumberBinding
  {
    private final String commsPropertyName;

    private final Consumer<Double> outputHandler;

    NumberBinding(String aPropertyName, Consumer<Double> aOutputHandler)
    {
      commsPropertyName = Objects.requireNonNull(aPropertyName);
      outputHandler = Objects.requireNonNull(aOutputHandler);
    }

    void bind()
    {
      frontendDataModel.bindIOData(commsPropertyName, this::update);
    }

    protected void update()
    {
      outputHandler.accept(getNumber(commsPropertyName));
    }

    private double getNumber(String aRawName)
    {
      return frontendDataModel.getIOData(aRawName);
    }
  }
}