/*
 * ==================================================================
 * 
 * (C) Copyright 2017 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.cabscreens.fe.app.button;

import java.util.Collections;
import java.util.function.Consumer;

import com.sun.javafx.scene.control.behavior.BehaviorBase;
import com.sydac.mmrbem.cabscreens.fe.base.ApplicationFactory;
import com.sydac.mmrbem.cabscreens.fe.base.ComponentManager;
import com.sydac.mmrbem.cabscreens.fe.gui.AbstractController;

import javafx.event.EventHandler;
import javafx.scene.control.ButtonBase;
import javafx.scene.input.MouseEvent;
import javafx.scene.input.TouchEvent;

/**
 * Behavior for TMS Buttons.<br>
 * <br>
 * Very similar in functionality to {@link ButtonBehavior} with the exception
 * that:<br>
 * - Mouse press and release are not directly processed. Instead they are sent
 * through to COMMS and processed on callbacks from COMMS<br>
 * - Does not have keyboard bindings. i.e. the button will not respond to
 * pressing the SPACE key
 * 
 * @author Nazim Oliyath
 * 
 * @see ComponentManager#register(String, Consumer)
 * @see ComponentManager#setNumber(String, double)
 *
 */
public class ButtonBehavior<C extends ButtonBase> extends BehaviorBase<C>
{
  private static final int KEY_PRESSED_PLACEHOLDER_VALUE = 9999;

  public static final String KEY_PRESS_VALUE_KEY = "key.keypress.value";
  
  private static final double KEY_PRESSED = 1.0;

  private static final double KEY_RELEASED = 0.0;

  private boolean keyDown;

  private String commsNumber;
  
  private double keyPressValue;

  private ComponentManager componentManager;
  
  /*
   * When using the application on a touch screen, we will respond to touch
   * events and ignore mouse pressed and released events.
   * 
   * When a button is touched and released, it sends both TOUCH_EVENTS and
   * MOUSE_EVENTS. To distinguish the source of the event mouseEvents can check
   * for isSynthesized() to identify if it were from a mouse click or a touch.
   */
  private EventHandler<TouchEvent> touchEventHandler = event -> {

    if (event.getEventType() == TouchEvent.TOUCH_PRESSED)
    {
      triggerPressedEvent();
    }
    if (event.getEventType() == TouchEvent.TOUCH_RELEASED)
    {
      triggerReleaseEvent();
    }
  };  

  private Consumer<Double> consumer = t -> {
    if (t.compareTo(keyPressValue) == 0)
    {
      ButtonBehavior.this.doButtonPress();
    }
    else if (t.compareTo(KEY_RELEASED) == 0)
    {
      ButtonBehavior.this.doButtonRelease();
    }
  };

  public ButtonBehavior(C button)
  {
    super(button, Collections.emptyList());

    int carIndex = (Integer)button.getScene().getProperties().get(ApplicationFactory.SCENARIO_CAR_INDEX);

    componentManager = ApplicationFactory.getComponentManager(carIndex);
    commsNumber = button.getProperties().get(AbstractController.COMMS_NUMBER_KEY).toString();
    componentManager.register(commsNumber, consumer);
    
    /*
     * 1. if KEY_PRESS value is present use that as keyPressValue
     * 
     * 2. if KEY_PRESS value is present and is 0.0, use another constant,
     * because 0.0 is already used by KEY_RELEASED
     * 
     * 3. if KEY_PRESS value is not present use default value viz KEY_PRESSED
     */
    Object value = button.getProperties().get(KEY_PRESS_VALUE_KEY);
    keyPressValue = value != null ? 
        Double.valueOf(value.toString()) == (int)KEY_RELEASED ? 
            KEY_PRESSED_PLACEHOLDER_VALUE : Double.valueOf(value.toString()) 
        : KEY_PRESSED;
    
    /* Add event handlers for touch events */
    button.addEventHandler(TouchEvent.TOUCH_PRESSED, touchEventHandler);
    button.addEventHandler(TouchEvent.TOUCH_RELEASED, touchEventHandler);
    
  }

  /**
   * Mouse event handling
   */

  /**
   * Invoked when a mouse press has occurred over the button. In addition to
   * potentially arming the Button, this will transfer focus to the button
   */
  @Override
  public void mousePressed(MouseEvent e)
  {
    // ignore the event if it were from a touch action
    if (!e.isSynthesized())
    {
      triggerPressedEvent();
    }
  }

  /*
   * Performs the UI actions required for button press
   */
  private void doButtonPress()
  {
    final ButtonBase button = getControl();

    // if the button is not already focused, then request the focus
    if (!button.isFocused() && button.isFocusTraversable())
    {
      button.requestFocus();
    }

    if (!button.isArmed())
    {
      button.arm();
    }
  }

  /**
   * Invoked when a mouse release has occurred. We determine whether this was
   * done in a manner that would fire the button's action. This happens only if
   * the button was armed by a corresponding mouse press.
   */
  @Override
  public void mouseReleased(MouseEvent e)
  {
    // ignore the event if it were from a touch action    
    if (!e.isSynthesized())
    {
      triggerReleaseEvent();
    }
  }

  /*
   * Performs the UI actions required for button release
   */
  private void doButtonRelease()
  {
    // if armed by a mouse press instead of key press, then fire!
    final ButtonBase button = getControl();
    if (!keyDown && button.isArmed())
    {
      button.fire();
      button.disarm();
    }
  }

  /**
   * Invoked when the mouse enters the Button. If the Button had been armed by a
   * mouse press and the mouse is still pressed, then this will cause the button
   * to be rearmed.
   */
  @Override
  public void mouseEntered(MouseEvent e)
  {
    // rearm if necessary
    final ButtonBase button = getControl();
    super.mouseEntered(e);
    if (!keyDown && button.isPressed())
    {
      button.arm();
    }
  }

  /**
   * Invoked when the mouse exits the Button. If the Button is armed due to a
   * mouse press, then this function will disarm the button upon the mouse
   * exiting it.
   */
  @Override
  public void mouseExited(MouseEvent e)
  {
    // Disarm if necessary
    final ButtonBase button = getControl();
    super.mouseExited(e);
    if (!keyDown && button.isArmed())
    {
      button.disarm();
    }
  }

  /**
   * Focus change handling
   */
  @Override
  protected void focusChanged()
  {
    // If we did have the key down, but are now not focused, then we must
    // disarm the button.
    final ButtonBase button = getControl();
    if (keyDown && !button.isFocused())
    {
      keyDown = false;
      button.disarm();
    }
  }
  
  /*
   * Pressed event can occur via a mouse click or a touch event.
   */
  private void triggerPressedEvent()
  {
    componentManager.setNumber(commsNumber, keyPressValue);
  }
  
  /*
   * Released event can occur via a mouse click or a touch event.
   */
  private void triggerReleaseEvent()
  {
    componentManager.setNumber(commsNumber, KEY_RELEASED);
  }  
  
}
