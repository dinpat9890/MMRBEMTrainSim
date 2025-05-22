/*
 * ==================================================================
 * 
 * (C) Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.radio.fe.i18n;

import java.text.MessageFormat;

import com.sydac.common.i18n.libintl.LibIntl;

public class RadioFrontendI18N
{
  private static final String DOMAIN = "RadioFrontend"; //$NON-NLS-1$

  private static final LibIntl libIntl = new LibIntl(DOMAIN);

  /** Can't be constructed */
  private RadioFrontendI18N()
  {}

  /**
   * Returns a translated version of the message.
   * 
   * @param message
   *          A message in English that needs to be translated before being
   *          displayed to a user. The format of the string should follow
   *          {@link MessageFormat} conventions.
   * 
   * @return a translated version of the message, or the original message if no
   *         suitable translation can be found.
   */
  public static String t(String message)
  {
    return libIntl.getText(message);
  }

  /**
   * Returns a translated version of the message formatted with a
   * {@link MessageFormat} using the given arguments.
   * <p>
   * Calling this method is equivalent to calling
   * {@code MessageFormat.format(t(message), args);} which means that
   * <strong>only the {@code message} will be localised</strong>. Typically
   * callers would not pass string literals in amongst the arguments, but if you
   * do, they should be wrapped in calls to {@link #t} first.
   *
   * @param message
   *          A message in English that needs to be translated and formatted
   *          before being displayed to a user. The format of the string should
   *          follow {@link MessageFormat} conventions.
   * @param args
   *          Objects to pass to
   *          {@link MessageFormat#format(String, Object...)}. Note that any
   *          Strings passed in must be localised by the caller.
   *
   * @return a translated version of the message, or the original message if no
   *         suitable translation can be found.
   */
  public static String t(String message, Object... args)
  {
    return MessageFormat.format(libIntl.getText(message), args);
  }
}
