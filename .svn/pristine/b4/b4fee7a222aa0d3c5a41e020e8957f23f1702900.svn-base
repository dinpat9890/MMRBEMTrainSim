/* ==================================================================
 *
 *  (C) Copyright 2011 Sydac Pty Ltd., all rights reserved.
 *  This is unpublished proprietary source code of Sydac.
 *  The copyright notice above does not evidence any actual
 *  or intended publication of such source code.
 *
 * ==================================================================
 */
package com.sydac.mmrbem.marshalling.i18n;

import java.text.MessageFormat;

import com.sydac.common.i18n.libintl.LibIntl;

/**
 * Helper class for using GNU gettext.
 * <p>
 * Wraps up a call to {@link LibIntl#getText(String)}
 * in a low-profile method called <code>_</code> (underscore).
 * <p>
 * The usual pattern for classes with text that must be translatable is to
 * statically import {@link ProjectTrainMarshallingI18N#t(String)} and wrap up
 * the translatable text with a call to <code>_</code>.
 * For example:
 * <pre>
 * jLabel.setText("My label");
 * </pre>
 * becomes...
 * <pre>
 * import static com.sydac.project.marshalling.i18n.ProjectTrainMarshallingI18N._;
 * ...
 * jLabel.setText(_("My label")); //$NON-NLS-1$
 * </pre>
 * Notice the <code>$NON-NLS-*$</code> comment; this marks a string as not
 * requiring externalisation. Warnings can be switched on in the Java compiler
 * to flag non-externalised strings to help you find them.
 *
 * @author Hitesh Pahuja
 *
 * @see <a href="http://www.gnu.org/software/gettext/">http://www.gnu.org/software/gettext/</a>
 */
public final class ProjectTrainMarshallingI18N
{
  private static final String DOMAIN = "ProjectTrainMarshalling"; //$NON-NLS-1$
  private static final LibIntl libIntl = new LibIntl(DOMAIN);

  /**
   * Returns a translated version of the message.
   *
   * @param message A message in English that needs to be translated before being displayed to a user.
   *   The format of the string should follow {@link MessageFormat} conventions.
   *
   * @return a translated version of the message, or the original message if no suitable translation can be found.
   */
  public static String t(String message)
  {
    return libIntl.getText(message);
  }

  /** Can't be constructed */
  private ProjectTrainMarshallingI18N(){}

}
