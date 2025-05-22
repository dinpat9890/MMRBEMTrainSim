package com.sydac.mmrbem.tcms.common.data;

/**
 * Data object class to hold fault/warning message.
 *
 * @author ext-vp
 */
public class TCMSEventsDO implements Comparable<TCMSEventsDO>
{

  private Integer eventId;

  private Integer faultId;

  private String faultDescription;

  private String faultSystem;

  private String faultComponenet;

  private Integer faultpriority;

  private Integer faultVehicleId;

  private String operatorGuide;

  private Long eventTime;

  private Long eventResolutionTime;

  private boolean active;

  private Integer occuranceCount;

  private boolean isAcknowledged; // Event is acknowledged or not.

  public TCMSEventsDO()
  {}

  public TCMSEventsDO(TCMSEventsDO eventDO)
  {
    setEventId(eventDO.eventId);
    setFaultId(eventDO.faultId);
    setFaultDescription(eventDO.faultDescription);
    setFaultSystem(eventDO.faultSystem);
    setFaultComponenet(eventDO.faultComponenet);
    setFaultpriority(eventDO.faultpriority);
    setFaultVehicleId(eventDO.faultVehicleId);
    setOperatorGuide(eventDO.operatorGuide);
    setEventTime(eventDO.eventTime);
    setEventResolutionTime(eventDO.eventResolutionTime);
    setActive(eventDO.active);
    setOccuranceCount(eventDO.occuranceCount);
    setAcknowledged(eventDO.isAcknowledged);
  }

  public TCMSEventsDO(Integer eventId, Integer faultId, String faultDescription, String faultSystem,
      String faultComponenet, Integer faultpriority, Integer faultVehicleId, String operatorGuide,
      Long eventTime, Long eventResolutionTime, boolean active, Integer occuranceCount,
      boolean isAcknowledged)
  {
    super();
    this.eventId = eventId;
    this.faultId = faultId;
    this.faultDescription = faultDescription;
    this.faultSystem = faultSystem;
    this.faultComponenet = faultComponenet;
    this.faultpriority = faultpriority;
    this.faultVehicleId = faultVehicleId;
    this.operatorGuide = operatorGuide;
    this.eventTime = eventTime;
    this.eventResolutionTime = eventResolutionTime;
    this.active = active;
    this.occuranceCount = occuranceCount;
    this.isAcknowledged = isAcknowledged;
  }

  public Integer getEventId()
  {
    return eventId;
  }

  public void setEventId(Integer eventId)
  {
    this.eventId = eventId;
  }

  public Integer getFaultId()
  {
    return faultId;
  }

  public void setFaultId(Integer faultId)
  {
    this.faultId = faultId;
  }

  public String getFaultDescription()
  {
    return faultDescription;
  }

  public void setFaultDescription(String faultDescription)
  {
    this.faultDescription = faultDescription;
  }

  public String getFaultSystem()
  {
    return faultSystem;
  }

  public void setFaultSystem(String faultSystem)
  {
    this.faultSystem = faultSystem;
  }

  public String getFaultComponenet()
  {
    return faultComponenet;
  }

  public void setFaultComponenet(String faultComponenet)
  {
    this.faultComponenet = faultComponenet;
  }

  public Integer getFaultpriority()
  {
    return faultpriority;
  }

  public void setFaultpriority(Integer faultpriority)
  {
    this.faultpriority = faultpriority;
  }

  public Integer getFaultVehicleId()
  {
    return faultVehicleId;
  }

  public void setFaultVehicleId(Integer faultVehicleId)
  {
    this.faultVehicleId = faultVehicleId;
  }

  public String getOperatorGuide()
  {
    return operatorGuide;
  }

  public void setOperatorGuide(String operatorGuide)
  {
    this.operatorGuide = operatorGuide;
  }

  public Long getEventTime()
  {
    return eventTime;
  }

  public void setEventTime(Long eventTime)
  {
    this.eventTime = eventTime;
  }

  public Long getEventResolutionTime()
  {
    return eventResolutionTime;
  }

  public void setEventResolutionTime(Long eventResolutionTime)
  {
    this.eventResolutionTime = eventResolutionTime;
  }

  public boolean isActive()
  {
    return active;
  }

  public void setActive(boolean active)
  {
    this.active = active;
  }

  public Integer getOccuranceCount()
  {
    return occuranceCount;
  }

  public void setOccuranceCount(Integer occuranceCount)
  {
    this.occuranceCount = occuranceCount;
  }

  public boolean isAcknowledged()
  {
    return isAcknowledged;
  }

  public void setAcknowledged(boolean isAcknowledged)
  {
    this.isAcknowledged = isAcknowledged;
  }

  @Override
  public int compareTo(TCMSEventsDO o)
  {
    int priorityResult = this.getFaultpriority() - o.getFaultpriority();
    if (priorityResult != 0)
    {
      return priorityResult;
    }

    Long eventTime1 = o.getEventTime() == null ? 0L : o.getEventTime();
    Long eventTime2 = this.eventTime == null ? 0L : this.eventTime;

    int date = eventTime1.compareTo(eventTime2);
    if (date != 0)
    {
      return date;
    }

    return 0;
  }
}