package com.sydac.mmrbem.tcms.fe.gui.action;

import com.sydac.mmrbem.tcms.fe.base.TCMSFactory;
import com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;

public class StationScreenCommandRequest   implements EventHandler<ActionEvent>
  {
    private StationCommand command;

    private final int carIndex;

 

    private final int setValue;

    private final int resetValue;

    public enum StationCommand
    {
      //@formatter:off
      REQUEST_STATION_SELECTED(VDUInputs.START_STATION_SElECTED_REQ),
      SKIP_STATION_SELECTED(VDUInputs.SKIP_STTAION_ID_REQ);
      
      
     

      private String currentValue;

      StationCommand(String value)
      {
        currentValue = value;
      }

      /**
       * Gets the input name of {@link TOSInputs} variable.
       *
       * @return the {@link TOSInputs} value.
       */
      public String getInputName()
      {
        return currentValue;
      }
    }

    /**
     * Instantiates a new Message Screen command request.
     * @param aCarNumber the a car index
     * @param aCommand the a command
     * @param aSetvalue the a setvalue
     * @param aResetValue the a reset value
     */
    public StationScreenCommandRequest(int aCarNumber, StationCommand aCommand,
        int aSetvalue, int aResetValue)
    {
      carIndex = aCarNumber;
     
      command = aCommand;
      setValue = aSetvalue;
      resetValue = aResetValue;
    }

    /**
     * Instantiates a new Message Screen command request.
     * @param aCarIndex the a car index
     * @param aCommand the a command
     */
    public StationScreenCommandRequest(int aCarIndex,  StationCommand aCommand)
    {
      this(aCarIndex,  aCommand, 1, 0);
    }

    @Override
    public void handle(ActionEvent event)
    {
      TCMSFactory.getServiceRequestHandler(carIndex).sendStationRequest(command, setValue,
          resetValue);
    }

    /**
     * Send toggle button selected request.
     * call this method when toggle is selected,
     */
    public void sendToggleSelectedRequest()
    {
      TCMSFactory.getServiceRequestHandler(carIndex).sendStationRequest(command, setValue,
          resetValue);
    }
    
   
}
