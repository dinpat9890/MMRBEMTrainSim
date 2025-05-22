package com.sydac.mmrbem.scc.plugin.sessionsetup.simulation;

import static com.sydac.simulatorcontroller.i18n.SimulatorControllerI18N.t;

import java.text.MessageFormat;
import java.util.Date;


import com.sydac.utility.DateTimeUtils;

/**
 * Helper class for showing reference sessions in a combo box.
 */
public class ReferenceSessionItem implements Comparable<ReferenceSessionItem>
{
  private int sessionId = -1;

  private Date startDate;

  private String trainee;

  private String instructor;

  private String sessionCode;

  /**
   * 
   */
  public ReferenceSessionItem()
  {
    super();
  }

  /**
   * @param sessionId
   * @param startDate
   * @param trainee
   * @param instructor
   * @param sessionCode
   */
  public ReferenceSessionItem(int sessionId, Date startDate, String trainee, String instructor, String sessionCode)
  {
    super();
    this.sessionId = sessionId;
    this.startDate = startDate;
    this.trainee = trainee;
    this.instructor = instructor;
    this.sessionCode = sessionCode;
  }

  public int getSessionId()
  {
    return sessionId;
  } // getSessionId

  @Override
  public String toString()
  {
    if (sessionId == -1)
    {
      return t("Run without a Reference Session"); //$NON-NLS-1$
    }    
    else if (sessionCode == null || sessionCode.isEmpty())
    {
      return MessageFormat.format(t(" Session run on {0} at {1} by {2} for {3}"), //$NON-NLS-1$
          DateTimeUtils.getShortDateString(startDate), DateTimeUtils.getShortTimeString(startDate), trainee, instructor);
    }
    else
    {
      return MessageFormat.format(t(" Session run on {0} at {1} by {2} for {3} named {4}"), //$NON-NLS-1$
          DateTimeUtils.getShortDateString(startDate), DateTimeUtils.getShortTimeString(startDate), trainee, instructor, sessionCode);
    }

  }

  @Override
  public int compareTo(ReferenceSessionItem that)
  {
    return this.startDate.compareTo(that.startDate);
  }
}
