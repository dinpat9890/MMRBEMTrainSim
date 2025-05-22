/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.common.io;

import java.io.IOException;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Objects;

import com.sydac.common.log.Tracer;
import com.sydac.common.registry.SydacProperties;
import com.sydac.mmrbem.tcms.common.data.TCMSEventsDO;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;

/**
 * Class to Read the event.ini files and load the information into the map
 * 
 * @author ext-vp
 */
public class TCMSEventsPropertiesReader
{
  private static final Tracer LOGGER = Tracer.getInstance();

  private Map<Integer, TCMSEventsDO> eventsMap = new HashMap<>();

  /** The single static instance of this class. */
  private static TCMSEventsPropertiesReader instance;

  public TCMSEventsPropertiesReader()
  {
    super();
  }

  public static synchronized TCMSEventsPropertiesReader getInstance()
  {
    if (instance == null)
    {
      instance = new TCMSEventsPropertiesReader();

      try
      {

        SydacProperties eventProperties = new SydacProperties();
        eventProperties.load(ApplicationConstants.EVENT_INI_FILE_PATH);
        instance.loadEventList(eventProperties);

      }
      catch (IOException e)
      {
        LOGGER.error(e);
      }

    }

    return instance;
  }

  private void loadEventList(SydacProperties eventProperties)
  {
    List<String> listSections = eventProperties.listSections();

    for (String section : listSections)
    {
      TCMSEventsDO eventsDO = new TCMSEventsDO();
      List<String> keys = eventProperties.listKeys(section);
      String sectionIdStr = section.replace(ApplicationConstants.EVENT_ID, ""); //$NON-NLS-1$
      Integer eventId = Integer.parseInt(sectionIdStr);

      eventsDO.setEventId(eventId);

      for (String key : keys)
      {
        if (Objects.equals(ApplicationConstants.FAULT_DESCRIPTION, key))
        {
          String faultDescrption = eventProperties.getStringProperty(section, key, ""); //$NON-NLS-1$
          eventsDO.setFaultDescription(faultDescrption);
        }
        else if (Objects.equals(ApplicationConstants.FAULT_LEVEL, key))
        {
          String faultPrority = eventProperties.getStringProperty(section, key, ""); //$NON-NLS-1$
          eventsDO.setFaultpriority(Integer.parseInt(faultPrority));
        }
        else if (Objects.equals(ApplicationConstants.FAULT_VEHICLE_ID, key))
        {
          String vehicleId = eventProperties.getStringProperty(section, key, ""); //$NON-NLS-1$
          eventsDO.setFaultVehicleId(Integer.parseInt(vehicleId));
        }
        else if (Objects.equals(ApplicationConstants.FAULT_ID, key))
        {
          String faultId = eventProperties.getStringProperty(section, key, ""); //$NON-NLS-1$
          eventsDO.setFaultId(Integer.parseInt(faultId));
        }
        else if (Objects.equals(ApplicationConstants.FAULT_COMPONENET, key))
        {
          String faultComponenet = eventProperties.getStringProperty(section, key, ""); //$NON-NLS-1$
          eventsDO.setFaultComponenet(faultComponenet);
        }
        else if (Objects.equals(ApplicationConstants.OPERATOR_GUIDANCE, key))
        {
          String operatorGuide = eventProperties.getStringProperty(section, key, ""); //$NON-NLS-1$
          eventsDO.setOperatorGuide(operatorGuide);
        }
        else if (Objects.equals(ApplicationConstants.FAULT_SYSTEM, key))
        {
          String faultSystem = eventProperties.getStringProperty(section, key, ""); //$NON-NLS-1$
          eventsDO.setFaultSystem(faultSystem);
        }

        this.eventsMap.put(eventId, eventsDO);
      }
    }
  }

  public Map<Integer, TCMSEventsDO> getEventsMap()
  {
    return eventsMap;
  }

  public void setEventsMap(Map<Integer, TCMSEventsDO> eventsMap)
  {
    this.eventsMap = eventsMap;
  }
}
