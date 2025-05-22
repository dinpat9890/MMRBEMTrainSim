/*
 * ==================================================================
 * 
 * (C) Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.papis.common.utils.timer;

import com.sydac.gui.control.NodePseudoClassProperty;

import javafx.animation.Animation;
import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.util.Duration;

/**
 * Class to flash label
 * 
 * @author pathann
 *
 */

public class AlarmFlashTimer
{

  private Timeline timeline;

  public AlarmFlashTimer(NodePseudoClassProperty label, String borderColor1, String borderColor2)
  {
    timeline = new Timeline(new KeyFrame(Duration.seconds(0.5), evt -> {
      label.set(borderColor1);
    }), new KeyFrame(Duration.seconds(1), evt -> {
      label.set(borderColor2);
    }));

    timeline.setCycleCount(Animation.INDEFINITE);

  }

  public void stop()
  {
    timeline.stop();
  }

  public void pause()
  {
    timeline.pause();
  }

  public void play()
  {
    timeline.play();
  }

}