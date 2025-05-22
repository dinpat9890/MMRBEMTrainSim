/*
 * ==================================================================
 *
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *
 * ==================================================================
 */
package com.sydac.mmrbem.radio.common.utils;

/**
 * Exception to check duplicate screen id
 *
 * @author ext-tambet
 */
public class DuplicateScreenIdException extends RuntimeException
{

  /**
   * 
   */
  private static final long serialVersionUID = 1L;

  public DuplicateScreenIdException(String message)
  {
    super(message);
  }

}
