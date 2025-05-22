package com.sydac.mmrbem.radio.common.io;

import java.io.IOException;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import com.sydac.common.log.Tracer;
import com.sydac.common.registry.Registry;
import com.sydac.common.registry.SydacProperties;
import com.sydac.mmrbem.radio.common.data.ContactDO;
import com.sydac.mmrbem.radio.common.data.MessageDO;
import com.sydac.mmrbem.radio.common.state.ApplicationConstants;

public class RadioPropertiesReader
{
  private static final Tracer LOGGER = Tracer.getInstance();

  private static Map<Integer, ContactDO> contactsMap = new HashMap<>();

  private static Map<Integer, ContactDO> groupsMap = new HashMap<>();

  private static Map<Integer, MessageDO> inboxMsgMap = new HashMap<>();

  private static Map<Integer, MessageDO> outboxMsgMap = new HashMap<>();

  public static final String DOT = "."; //$NON-NLS-1$

  /** The Constant instance. */
  private static RadioPropertiesReader instance;

  private String routeListPath;

  public static synchronized RadioPropertiesReader getInstance()
  {
    if (instance == null)
    {
      instance = new RadioPropertiesReader();
      try
      {

        SydacProperties contactsProperties = new SydacProperties();
        contactsProperties.load("../Environment/ContactList.ini");//$NON-NLS-1$

        instance.loadContactInfoList(contactsProperties, contactsMap);

        SydacProperties groupsProperties = new SydacProperties();
        groupsProperties.load("../Environment/GroupList.ini");//$NON-NLS-1$

        instance.loadContactInfoList(groupsProperties, groupsMap);

        SydacProperties inboxMsgProperties = new SydacProperties();
        inboxMsgProperties.load("../Environment/InboxMessageList.ini");//$NON-NLS-1$

        instance.loadMessageInfoList(inboxMsgProperties, inboxMsgMap);

        SydacProperties outboxMsgProperties = new SydacProperties();
        outboxMsgProperties.load("../Environment/OutboxMessageList.ini");//$NON-NLS-1$

        instance.loadMessageInfoList(outboxMsgProperties, outboxMsgMap);

        instance.loadPapisRouteListPath();

      }
      catch (IOException e)
      {
        LOGGER.error(e);
      }
    }
    return instance;
  }

  private void loadContactInfoList(SydacProperties properties, Map<Integer, ContactDO> map)
  {
    List<String> listSections = properties.listSections();

    for (String section : listSections)
    {
      ContactDO contact = new ContactDO();
      List<String> keys = properties.listKeys(section);
      String sectionIdStr = section.replace(ApplicationConstants.ID, ""); //$NON-NLS-1$
      Integer contactId = Integer.parseInt(sectionIdStr);

      contact.setContactId(contactId);

      for (String key : keys)
      {
        if (key.equals(ApplicationConstants.TEXT))
        {
          String messageText = properties.getStringProperty(section, key, ""); //$NON-NLS-1$
          contact.setContactText(messageText);
        }

      }
      map.put(contactId, contact);
    }

  }

  /**
   * Load message list from properties file
   */
  private void loadMessageInfoList(SydacProperties properties, Map<Integer, MessageDO> map)
  {
    List<String> listSections = properties.listSections();

    for (String section : listSections)
    {
      MessageDO message = new MessageDO();
      List<String> keys = properties.listKeys(section);
      String sectionIdStr = section.replace(ApplicationConstants.ID, ""); //$NON-NLS-1$
      Integer messageId = Integer.parseInt(sectionIdStr);

      message.setMsgId(messageId);

      for (String key : keys)
      {
        if (key.equals(ApplicationConstants.TEXT))
        {
          String messageText = properties.getStringProperty(section, key, ""); //$NON-NLS-1$
          message.setMsgText(messageText);
        }

      }
      map.put(messageId, message);
    }
  }

  public Map<Integer, ContactDO> getContactsMap()
  {
    return contactsMap;
  }

  public Map<Integer, ContactDO> getGroupsMap()
  {
    return groupsMap;
  }

  public Map<Integer, MessageDO> getInboxMsgMap()
  {
    return inboxMsgMap;
  }

  public Map<Integer, MessageDO> getOutboxMsgMap()
  {
    return outboxMsgMap;
  }

  private void loadPapisRouteListPath()
  {

    routeListPath = Registry.getInstance().getString(ApplicationConstants.DOMAIN_NAME, "pisFolderPath");//$NON-NLS-1$ //$NON-NLS-2$
  }

  public static String getRouteListFilePath()
  {
    return instance.routeListPath;
  }
}
