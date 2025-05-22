package com.sydac.mmrbem.radio.backend.logic.handler;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.sydac.foundation.IPropertySetter;
import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.radio.backend.comms.CommsBinding;
import com.sydac.mmrbem.radio.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.radio.backend.logic.SharedDataModel;
import com.sydac.mmrbem.radio.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.radio.backend.radiointercom.properties.IRadioIntercomInputProperties;
import com.sydac.mmrbem.radio.backend.radiointercom.properties.IRadioIntercomOutputProperties;
import com.sydac.mmrbem.radio.common.ScreenId;
import com.sydac.mmrbem.radio.common.data.ContactDO;
import com.sydac.mmrbem.radio.common.io.RadioPropertiesReader;
import com.sydac.mmrbem.radio.common.io.properties.IAppInputsContactScreenProperties;
import com.sydac.mmrbem.radio.common.io.properties.IAppInputsKeyPadPanelProperties;
import com.sydac.mmrbem.radio.common.io.properties.IAppInputsPowerMenuNavPanelProperties;
import com.sydac.mmrbem.radio.common.io.properties.IAppOutputCallInfoProperties;
import com.sydac.mmrbem.radio.common.io.properties.IAppOutputContactScreenProperties;
import com.sydac.mmrbem.radio.common.io.properties.IAppOutputsCommonProperties;
import com.sydac.mmrbem.radio.common.state.ApplicationConstants;
import com.sydac.mmrbem.radio.common.utils.timer.CommsTimer;
import com.sydac.radio.proto.RadioProtos.ContactList;

@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class, SharedDataModel.class })
public class ContactListScreenHandler extends AbstractFunctionalLogic implements IScreenChangeListener
{

  private List<ContactDO> contactList = new ArrayList<>();

  private List<ContactDO> groupList = new ArrayList<>();

  private List<ContactDO> selectedList = new ArrayList<>();

  private int selectedContactId = 0;

  private int selectedBtn = ApplicationConstants.NO_BUTTON;

  private int volume;

  @Autowired
  private SharedDataModel sharedDataModel;

  @Autowired
  private ScreenChangeHandler screenChangeHandler;

  private final static long STAY_TIME = 3000; // $NON-NLS-1$

  private CommsTimer volumeScreenTimer;

  /** Runnable to perform show status screen */
  private Runnable volumeScreenRunnable = () -> {
    if (volumeScreenTimer != null)
    {
      screenChangeHandler.requestScreenChange(ScreenId.MAIN_SCREEN);
      volumeScreenTimer.safeCancel();

    }
  };

  public ContactListScreenHandler(CommsBinding commsBinding)
  {
    super(commsBinding, IRadioIntercomOutputProperties.class, IAppInputsContactScreenProperties.class,
        IAppInputsKeyPadPanelProperties.class, IAppInputsPowerMenuNavPanelProperties.class);
    volumeScreenTimer = CommsTimer.newScheduledTimer(volumeScreenRunnable, STAY_TIME);
    initMessageList();

  }

  private void initMessageList()
  {

    contactList = RadioPropertiesReader.getInstance().getContactsMap().entrySet().stream()
        .map(m -> new ContactDO(m.getValue().getContactText(), m.getKey())).collect(Collectors.toList());

    groupList = RadioPropertiesReader.getInstance().getGroupsMap().entrySet().stream()
        .map(m -> new ContactDO(m.getValue().getContactText(), m.getKey())).collect(Collectors.toList());

    selectedList = contactList;

  }

  private void updateContactList()
  {
    ContactList.Builder contacts = ContactList.newBuilder();
    selectedList.forEach(m -> {
      ContactList.Contact.Builder contact = ContactList.Contact.newBuilder();

      contact.setContactId(m.getContactId());
      contact.setContactText(m.getContactText());

      contacts.addContact(contact);

    });
    setApplicationOutputsProperty(IAppOutputContactScreenProperties.CONTACT_LIST,
        contacts.build().toByteArray());

  }

  @Override
  public <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {
    if (vehicleIndex == getActiveVehicleIndex() && (Integer)newValue > 0)
    {
      if (IAppInputsPowerMenuNavPanelProperties.NAVIGATION_UP_ARROW_REQUEST.equals(key))
      {
        if (sharedDataModel.getScreenId() == ScreenId.CONTACT_SCREEN.getId())
        {
          moveMenuForward();
        }
        else if (sharedDataModel.getScreenId() == ScreenId.MAIN_SCREEN.getId())
        {
          screenChangeHandler.requestScreenChange(ScreenId.VOLUME_SCREEN);
          startTimer();

        }
        else if (sharedDataModel.getScreenId() == ScreenId.VOLUME_SCREEN.getId())
        {
          volume++;

          setApplicationOutputsProperty(IAppOutputsCommonProperties.UP_BUTTON_VALUE, volume);
        }
      }
      else if (IAppInputsPowerMenuNavPanelProperties.NAVIGATION_DOWN_ARROW_REQUEST.equals(key))
      {
        if (sharedDataModel.getScreenId() == ScreenId.CONTACT_SCREEN.getId())
        {
          moveMenuBackword();
        }
        else if (sharedDataModel.getScreenId() == ScreenId.MAIN_SCREEN.getId())
        {
          screenChangeHandler.requestScreenChange(ScreenId.VOLUME_SCREEN);
          startTimer();

        }
        else if (sharedDataModel.getScreenId() == ScreenId.VOLUME_SCREEN.getId())
        {
          volume--;

          setApplicationOutputsProperty(IAppOutputsCommonProperties.DOWN_BUTTON_VALUE, volume);
        }
      }
      else if (IAppInputsContactScreenProperties.SELECTED_CONTACT_LIST_ID.equals(key)
          && (Integer)newValue > 0)
      {
        selectedContactId = (Integer)newValue;
        setSelectedContactId();
      }
      else if (IAppInputsContactScreenProperties.CONTACTS_BTN_REQUEST.equals(key))
      {
        setContactBtnStatus();
      }

      else if (IAppInputsContactScreenProperties.GROUP_LIST_BTN_REQUEST.equals(key))
      {
        setGroupBtnStatus();
      }
      else if (IAppInputsKeyPadPanelProperties.BTN_DOWN_ARROW_REQUEST.equals(key))
      {
        ContactDO contact = selectedList.stream().filter(m -> m.getContactId() == selectedContactId)
            .findFirst().orElse(null);
        int index = 0;
        if (contact != null)
        {
          index = selectedList.indexOf(contact);
        }
        int nextContactIndex = index + 1;
        if (selectedList.size() > nextContactIndex)
        {
          selectedContactId = selectedList.get(nextContactIndex).getContactId();
          setSelectedContactId();
        }
      }
      else if (IAppInputsKeyPadPanelProperties.BTN_UP_ARROW_REQUEST.equals(key))
      {
        ContactDO contact = selectedList.stream().filter(m -> m.getContactId() == selectedContactId)
            .findFirst().orElse(null);
        int index = 0;
        if (contact != null)
        {
          index = selectedList.indexOf(contact);
        }
        int nextContactIndex = index - 1;
        if (nextContactIndex != -1)
        {
          selectedContactId = selectedList.get(nextContactIndex).getContactId();
          setSelectedContactId();
        }
      }
      else if (IAppInputsKeyPadPanelProperties.ENTER_START_CALL_BTN_REQUEST.equals(key)
          && sharedDataModel.getScreenId() == ScreenId.CONTACT_SCREEN.getId())
      {
        IPropertySetter radioIntercomInputSetter = getRadioIntercomInputSetter(getActiveVehicleIndex());
        if (selectedBtn == ApplicationConstants.GROUP_BTN)
        {

          sharedDataModel.setCallCatagory(ApplicationConstants.GROUP_BTN);
          System.out.println(
              "ContactListScreenHandler.appInputsPropertyUpdated()" + sharedDataModel.getCallCatagory());
          setChanel(selectedContactId);
          // sendPulseRequest(radioIntercomInputSetter,
          // IRadioIntercomInputProperties.RADIO_FULL_DUPLEX_CALL_REQ,
          // ApplicationConstants.RESET_VALUE, selectedContactId);

        }
        else if (selectedBtn == ApplicationConstants.CONTACT_BTN)
        {
          sharedDataModel.setCallCatagory(ApplicationConstants.CONTACT_BTN);

          sendPulseRequest(radioIntercomInputSetter, IRadioIntercomInputProperties.RADIO_FULL_DUPLEX_CALL_REQ,
              ApplicationConstants.RESET_VALUE, selectedContactId);

        }
        screenChangeHandler.requestScreenChange(ScreenId.MAIN_SCREEN); // added
                                                                       // this
        // fix
        // for
        // MMRBEM-3344
      }
    }
  }

  private void moveMenuBackword()
  {
    selectedBtn--;

    if (selectedBtn >= ApplicationConstants.DIAGNOSTIC_BTN)
    {
      updateButtonId();
    }

  }

  private void moveMenuForward()
  {
    selectedBtn++;

    if (selectedBtn <= ApplicationConstants.MODES_BTN)
    {
      updateButtonId();
    }

  }

  private void updateButtonId()
  {
    if (selectedBtn == ApplicationConstants.DIAGNOSTIC_BTN)
    {
      setDiagnosticBtnStatus();
    }
    else if (selectedBtn == ApplicationConstants.CONTACT_BTN)
    {
      setContactBtnStatus();
    }
    else if (selectedBtn == ApplicationConstants.CALLHISTORY_BTN)
    {
      setCallHistoryBtnStatus();
    }
    else if (selectedBtn == ApplicationConstants.BITE_BTN)
    {
      setBiteBtnStatus();

    }
    else if (selectedBtn == ApplicationConstants.GROUP_BTN)
    {
      setGroupBtnStatus();
    }
    else if (selectedBtn == ApplicationConstants.MODES_BTN)
    {
      setModeBtnStatus();
    }
  }

  private void setGroupBtnStatus()
  {
    selectedBtn = ApplicationConstants.GROUP_BTN;
    selectedList = groupList;
    selectedContactId = ApplicationConstants.RESET_VALUE;
    setSelectedContactId();
    updateContactList();
    setSelectedBtn();
  }

  private void setContactBtnStatus()
  {
    selectedList = contactList;
    selectedBtn = ApplicationConstants.CONTACT_BTN;
    // selectedContactId = ApplicationConstants.RESET_VALUE;
    setSelectedContactId();
    updateContactList();
    setSelectedBtn();
  }

  private void setDiagnosticBtnStatus()
  {

    selectedBtn = ApplicationConstants.DIAGNOSTIC_BTN;
    selectedContactId = ApplicationConstants.RESET_VALUE;

    setSelectedBtn();
  }

  private void setCallHistoryBtnStatus()
  {
    selectedBtn = ApplicationConstants.CALLHISTORY_BTN;
    selectedContactId = ApplicationConstants.RESET_VALUE;
    setSelectedBtn();
  }

  private void setBiteBtnStatus()
  {
    selectedBtn = ApplicationConstants.BITE_BTN;
    selectedContactId = ApplicationConstants.RESET_VALUE;
    setSelectedBtn();
  }

  private void setModeBtnStatus()
  {
    selectedBtn = ApplicationConstants.MODES_BTN;
    selectedContactId = ApplicationConstants.RESET_VALUE;
    setSelectedBtn();
  }

  private void setSelectedContactId()
  {
    setApplicationOutputsProperty(IAppOutputContactScreenProperties.SELECTED_CONTACT_LIST_ID,
        selectedContactId);
  }

  private void setSelectedBtn()
  {
    setApplicationOutputsProperty(IAppOutputContactScreenProperties.CONTACT_SCREEN_SELECTED_BTN, selectedBtn);
  }

  @Override
  public void detachListeners()
  {
    selectedContactId = ApplicationConstants.RESET_VALUE;
    setSelectedContactId();
  }

  @Override
  public void onEnteringScreen(int screenId)
  {
    selectedContactId = ApplicationConstants.RESET_VALUE;
    selectedBtn = ApplicationConstants.DIAGNOSTIC_BTN;

    updateContactList();

    setSelectedContactId();
    setSelectedBtn();
  }

  @Override
  public void onLeavingScreen(int screenId)
  {
    selectedContactId = ApplicationConstants.RESET_VALUE;
  }

  private void startTimer()
  {
    if (!volumeScreenTimer.isRunning())
    {
      volumeScreenTimer.start();
    }
  }

  public void setChanel(int dialledNo)
  {
    String contactText = null;
    if (sharedDataModel.getCallCatagory() == ApplicationConstants.GROUP_BTN)
    {
      contactText = getContactIdText(dialledNo, groupList);
    }

    if (contactText != null && !contactText.trim().isEmpty())
    {

      setApplicationOutputsProperty(IAppOutputCallInfoProperties.INCOMING_CALL_NAME, contactText.getBytes());
    }

  }

  private String getContactIdText(int contactId, List<ContactDO> contactList)
  {
    String contactText = null;
    ContactDO contact = contactList.stream().filter(m -> m.getContactId() == contactId).findFirst()
        .orElse(null);
    if (contact != null)
    {
      contactText = contact.getContactText();

    }
    return contactText;
  }

}
