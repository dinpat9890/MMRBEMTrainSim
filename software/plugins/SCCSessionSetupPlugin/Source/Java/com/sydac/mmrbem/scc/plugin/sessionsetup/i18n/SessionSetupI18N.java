/*
 * ==================================================================
 * 
 * (C) Copyright 2011 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.scc.plugin.sessionsetup.i18n;

import java.text.MessageFormat;

import com.sydac.common.i18n.libintl.LibIntl;
import com.sydac.simulatorcontroller.i18n.SimulatorControllerI18N;

/**
 * Helper class for using GNU gettext.
 * <p>
 * Wraps up a call to {@link LibIntl#getText(String)} in a low-profile method
 * called {@code t}.
 * <p>
 * The usual pattern for classes with text that must be translatable is to
 * statically import {@link SimulatorControllerI18N#t(String)} and wrap up the
 * translatable text with a call to {@code t}. For example:
 * 
 * <pre>
 * jLabel.setText(&quot;My label&quot;);
 * </pre>
 * 
 * becomes...
 * 
 * <pre>
 * import static com.sydac.simulatorcontroller.i18n.SimulatorControllerI18N.t;
 * ...
 * jLabel.setText(t("My label")); //$NON-NLS-1$
 * </pre>
 * 
 * Often messages may require formatting before display to include dynamic
 * information; luckily there is a helper for this use case. For example:
 * 
 * <pre>
 * String message = &quot;There are &quot; + bottleCount + &quot; bottles of beer on the wall.&quot;;
 * </pre>
 * 
 * should be converted to...
 * 
 * <pre>
 * import static com.sydac.simulatorcontroller.i18n.SimulatorControllerI18N.t;
 * ...
 * String message = t("There are {0} bottles of beer on the wall.", bottleCount); //$NON-NLS-1$
 * </pre>
 * <p>
 * Notice the <code>$NON-NLS-*$</code> comment; this marks a string as not
 * requiring externalisation. Warnings can be switched on in the Java compiler
 * to flag non-externalised strings to help you find them.
 *
 * @author Stanley Mladenov
 *
 * @see <a
 *      href="http://www.gnu.org/software/gettext/">http://www.gnu.org/software/gettext/</a>
 */
public final class SessionSetupI18N
{
  private static final String DOMAIN = "CofmowNewSessionPlugin"; //$NON-NLS-1$

  private static final LibIntl libIntl = new LibIntl(DOMAIN);

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
   *          Objects to pass to {@link MessageFormat#format(String, Object...)}
   *          . Note that any Strings passed in must be localised by the caller.
   *
   * @return a translated version of the message, or the original message if no
   *         suitable translation can be found.
   */
  public static String t(String message, Object... args)
  {
    return MessageFormat.format(libIntl.getText(message), args);
  }

  /** Can't be constructed */
  private SessionSetupI18N()
  {}

}
