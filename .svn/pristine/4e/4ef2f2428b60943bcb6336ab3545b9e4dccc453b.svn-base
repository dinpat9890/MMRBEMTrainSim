/*
 * ==================================================================
 * 
 * (C) Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.psd.common.utils.timer;

import javafx.animation.Animation;
import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.scene.control.Label;
import javafx.util.Duration;

/**
 * Class to flash label
 * 
 * @author ext-savanjin
 *
 */

public class FlashTimer
{

  private Timeline timeline;

  private Label label;

  public FlashTimer(Label label)
  {
    this.label = label;

    timeline = new Timeline(new KeyFrame(Duration.seconds(0.5), evt -> label.setVisible(false)),
        new KeyFrame(Duration.seconds(1), evt -> label.setVisible(true)));

    timeline.setCycleCount(Animation.INDEFINITE);

  }

  public void stop()
  {
    label.setVisible(false);
    timeline.stop();
  }

  public void pause()
  {
    timeline.pause();
  }

  public void play()
  {
    label.setVisible(true);
    timeline.play();
  }

}
