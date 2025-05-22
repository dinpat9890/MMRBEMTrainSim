/*
 * ==================================================================
 * 
 * (C) Copyright 2016 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.papis.common.utils.timer;

import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;
import java.util.SortedSet;
import java.util.TreeSet;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

import com.sydac.mmrbem.papis.common.application.IRunCycleBroadcaster;
import com.sydac.mmrbem.papis.common.application.IRunCycleListener;



/**
 * The nerve-center for managing CommsTimer executions.<br>
 * This entity has to be initialized with a {@link IRunCycleBroadcaster} so as
 * to receive all the runCycle callbacks and trigger timers at the expected
 * times. <br>
 * <br>
 * NOTE: Internally the CommsTimerManager uses a single (JVM) executor-thread to
 * execute all the timer tasks. So any timer action that takes a lot of time (in
 * the order of seconds) will block the other timer tasks from executing. A
 * single thread for execution is done intentionally because the timer task are
 * expected to be very quick in execution. If this gets identified to be a
 * concern in the future we can enhance it to have 'n' number of threads in the
 * thread pool.
 *
 * @author Nazim Oliyath
 */
public final class CommsTimerManager
{

  /* CommsTimerManager instance - gets updated for every new session */
  private static CommsTimerManager instance;

  /* Executor service to execute timer tasks */
  private final ExecutorService executorService = Executors.newSingleThreadExecutor();

  /* Sorted data-structure to keep track of next time for execution */
  private final SortedSet<Long> sortedSet = Collections.synchronizedSortedSet(new TreeSet<Long>());

  /* Mapping to track all tasks that has to be executed at a given time */
  private final Map<Long, Set<TimerInfo>> timeMapping = Collections
      .synchronizedMap(new HashMap<Long, Set<TimerInfo>>());

  /* Mapping to track execution time assigned to a timer */
  private final Map<TimerInfo, Long> executionTimeMapping = Collections
      .synchronizedMap(new HashMap<TimerInfo, Long>());

  /* Internal run cycle listener which get notified on each run cycle */
  private final IRunCycleListener runCycleListener = new RunCycleListener();

  /* Current simulation time in milliseconds */
  private long nowInMillis;

  /**
   * Private constructor.
   */
  private CommsTimerManager(IRunCycleBroadcaster runCycleBroadcaster)
  {
    runCycleBroadcaster.join(runCycleListener);
    this.nowInMillis = runCycleBroadcaster.getCurrentTimeInMillis();
  }

  /**
   * Initialize the CommsTimerManager. It is expected to have only one
   * CommsTimerManager per CommsApplication. <br>
   * For eg: In case on FEBE backend applications, CommsTimerManager need not be
   * initialized for each IVehicleBackend but only once for the project specific
   * BackendModule extension
   *
   * @param runCycleBroadcaster
   *          runCycleBroadcaster
   */
  public static final synchronized void initializeTimerManager(IRunCycleBroadcaster runCycleBroadcaster)
  {
    if (instance == null)
    {
      instance = new CommsTimerManager(runCycleBroadcaster);
    }
  }

  /**
   * Stop the CommsTimerManager. This API should be called without fail during
   * scSessionTermination() if the CommsTimerManager had been initialized in the
   * session.
   */
  public static final synchronized void stopTimerManager()
  {
    if (instance != null)
    {
      instance.stopTimerManagerImpl();
      instance = null;
    }
  }

  /**
   * Called by CommsTimer instance to schedule (start) itself.
   *
   * @param commsTimer
   */
  static final void scheduleTimer(CommsTimer commsTimer)
  {
    if (instance == null)
    {
      throw new IllegalStateException("CommsTimerManager not initialized"); //$NON-NLS-1$
    }

    instance.scheduleTimerImpl(commsTimer);
  }

  /**
   * Called by CommsTimer instance to cancel itself.
   *
   * @param commsTimer
   */
  static final void cancelTimer(CommsTimer commsTimer)
  {
    if (instance == null)
    {
      throw new IllegalStateException("CommsTimerManager not initialized"); //$NON-NLS-1$
    }

    instance.cancelTimerImpl(commsTimer);
  }

  /*
   * Implementation of scheduleTimer() static calls.
   */
  private void scheduleTimerImpl(CommsTimer commsTimer)
  {
    TimerInfo timerInfo = new TimerInfo(commsTimer.getSequenceNumber(), commsTimer.getAction(),
        commsTimer.isRepeated(), commsTimer.getPeriod());

    /* Set the execution time for the task */
    timerInfo.nextExecTime = nowInMillis + commsTimer.getInitialDelay();

    /* Add the task for execution */
    addTimerInfo(timerInfo);
  }

  /*
   * Implementation of cancleTimer() static calls.
   */
  private void cancelTimerImpl(CommsTimer commsTimer)
  {
    TimerInfo timerInfo = new TimerInfo(commsTimer.getSequenceNumber(), commsTimer.getAction(),
        commsTimer.isRepeated(), commsTimer.getPeriod());

    /* Remove the task from the list of tasks to be executed */
    removeTimerInfo(timerInfo);
  }

  /*
   * Implementation of stopTimerManager() static calls.
   */
  private void stopTimerManagerImpl()
  {
    executorService.shutdownNow();

    /* Discard any pending tasks */
    sortedSet.clear();

    /* Discard all mappings */
    timeMapping.clear();
  }

  /**
   * Executes the task in the timer
   *
   * @param info
   */
  private void doExecute(TimerInfo info)
  {
    Runnable command = info.command;
    executorService.execute(command);
  }

  /**
   * Adds the timer task to be scheduled for execution.
   *
   * @param timerInfo
   */
  private void addTimerInfo(TimerInfo timerInfo)
  {
    long nextExecTime = timerInfo.nextExecTime;

    /* Add the execution time to sorted set */
    sortedSet.add(nextExecTime);

    /*
     * Map the task to this execution time. There can be more than one task to
     * execute at a given time
     */
    if (!timeMapping.containsKey(nextExecTime))
    {
      timeMapping.put(nextExecTime, new HashSet<TimerInfo>());
    }
    timeMapping.get(nextExecTime).add(timerInfo);

    /* Map the timer to its execution time */
    executionTimeMapping.put(timerInfo, nextExecTime);
  }

  /**
   * Removes the timer task from the list of scheduled tasks
   *
   * @param timerInfo
   */
  private void removeTimerInfo(TimerInfo timerInfo)
  {
    /* if timer is planned for execution */
    if (executionTimeMapping.containsKey(timerInfo))
    {
      long nextExecTime = executionTimeMapping.get(timerInfo);

      /*
       * Remove only this specific task from the tasks to be executed at
       * nextExecTime
       */
      timeMapping.get(nextExecTime).remove(timerInfo);

      /* Remove the timer's execution time mapping */
      executionTimeMapping.remove(timerInfo);
    }
    /* else timer not planned for execution, so do nothing */
  }

  /**
   * Clear all timer tasks at the specified execution time.
   *
   * @param executionTime
   */
  private void clearTimersAt(long executionTime)
  {
    if (timeMapping.containsKey(executionTime))
    {
      timeMapping.get(executionTime).clear();
      timeMapping.put(executionTime, null);
    }
    timeMapping.remove(executionTime);
    sortedSet.remove(executionTime);
  }

  /**
   * Execute all tasks that are scheduled to run now or before now.
   */
  private void runTimers()
  {
    Long[] buffer;

    /* Get all execution times at or less than now */
    synchronized (sortedSet)
    {
      SortedSet<Long> headSet = sortedSet.headSet(nowInMillis + 1);
      buffer = new Long[headSet.size()];
      buffer = headSet.toArray(buffer);
    }

    /* For each of these execution times, execute all its tasks */
    for (Long nextExecTime : buffer)
    {
      /* Clear the execution time that is going to be processed */
      sortedSet.remove(nextExecTime);

      if (timeMapping.containsKey(nextExecTime))
      {
        for (TimerInfo timerInfo : timeMapping.get(nextExecTime))
        {
          /* execute the task */
          doExecute(timerInfo);

          /* task executed. remove timer's execution time mapping */
          executionTimeMapping.remove(timerInfo);

          /* if the task is to be repeated, then schedule for next execution */
          if (timerInfo.isRepeated)
          {
            timerInfo.nextExecTime = nowInMillis + timerInfo.period;
            addTimerInfo(timerInfo);
          }
        }
      }
      /* Clear all tasks at this execution time as they have been completed */
      clearTimersAt(nextExecTime);
    }
  }

  /**
   * Internal data-structure that encapsulates all the required information from
   * a CommsTimer to be used by {@link CommsTimerManager}
   *
   * @author Nazim Oliyath
   */
  private static class TimerInfo
  {
    int sequenceNumber;

    Runnable command;

    boolean isRepeated;

    long period;

    long nextExecTime;

    /**
     * Constructor
     *
     * @param sequenceNumber
     * @param command
     * @param isRepeated
     * @param period
     */
    TimerInfo(int sequenceNumber, Runnable command, boolean isRepeated, long period)
    {
      this.sequenceNumber = sequenceNumber;
      this.command = command;
      this.isRepeated = isRepeated;
      this.period = period;
    }

    /**
     * TimerInfo are equal if they are the details of the same CommsTimer.
     */
    @Override
    public boolean equals(Object obj)
    {
      if (obj instanceof TimerInfo)
      {
        return obj.hashCode() == this.hashCode();
      }
      return false;
    }

    /**
     * TimerInfo are equal if they are the details of the same CommsTimer.
     */
    @Override
    public int hashCode()
    {
      return sequenceNumber;
    }

    @Override
    public String toString()
    {
      return "CommsTimer (" + sequenceNumber + ") - " + nextExecTime; //$NON-NLS-1$ //$NON-NLS-2$
    }
  }

  /**
   * Internal run cycle listener that gets notified on each run cycle and
   * triggers an execution of any applicable timer tasks.
   *
   * @author Nazim Oliyath
   */
  final class RunCycleListener implements IRunCycleListener
  {

    @Override
    public void runCycle(long simulationTimeInMillis)
    {
      /* Update nowInMillis to current simulation time */
      CommsTimerManager.this.nowInMillis = simulationTimeInMillis;

      /* Execute applicable tasks */
      CommsTimerManager.this.runTimers();
    }

  }

}
