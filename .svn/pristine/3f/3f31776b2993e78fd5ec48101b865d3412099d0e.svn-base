//**************************************************************************************************
//
//  File:           m_vehicle.us.cpp
//
//  Description:    m_vehicle class definition
//
//
//  (C) Copyright:  SYDAC Pty Ltd, 2021
//
//***************************************************************************************************

#ifndef m_vehicle_CPP
#define m_vehicle_CPP

#include <vehicles/Vehicle.us.cpp>

namespace Vehicles
{
    //  Class:          Vehicles::m_vehicle
    //
    //  Description:    Logically abstract base class definition of a vehicle, this class contains
    //                  properties common to all vehicles.
    //
    class m_vehicle : Vehicle
    {
    public:

        //  Function:       m_vehicle
        //
        //  Description:    Constructs a m_vehicle with given properties.
        //
        //  Parameters:
        //      VehicleInfoExtern info - The initial data for this vehicle.
        
        m_vehicle(VehicleInfoExtern info, Properties properties)
        {
            __Vehicle__(info, engine.world.loadNode("m_car_exterior.node"), properties);

            if (getNode() == 0)
                log.error("Unable to create vehicle because m_car_exterior.node was unable to be loaded\n");
            else
                initialiseProperties(info);
        }
    
        //  Function:       ~m_vehicle
        //
        //  Description:    Destructor. Cleans up if necessary.
        
        ~m_vehicle()
        {
        }
		
		//  Function:       setDoorNumber
        //
        //  Description:    Sets a number property on a given door.
        //
        //  Parameters:
        //      string door      - The name of the door to apply the property to.
        //      string property  - The property to apply.
        //      double value     - The value of the property.
        
        void setDoorNumber(string door, string property, double value)
        {
            log.message("Received door number for property %s with value %f on vehicle with door %s\n", property, value, door);
            if(property == "State")
            {
                if(door == "Left_Door_1")
                {
                    setDoorState("door_left_a1", value);
					setDoorState("door_left_b1", value);
                }
                else if(door == "Left_Door_2")
                {
                    setDoorState("door_left_a2", value);
					setDoorState("door_left_b2", value);
                }                
                else if(door == "Left_Door_3")
                {
                    setDoorState("door_left_a3", value);
					setDoorState("door_left_b3", value);
                }
				else if(door == "Left_Door_4")
                {
                    setDoorState("door_left_a4", value);
					setDoorState("door_left_b4", value);
                }
				else if(door == "Right_Door_1")
                {
                    setDoorState("door_right_a1", value);
					setDoorState("door_right_b1", value);
                }
				else if(door == "Right_Door_2")
                {
                    setDoorState("door_right_a2", value);
					setDoorState("door_right_b2", value);
                }
				else if(door == "Right_Door_3")
                {
                    setDoorState("door_right_a3", value);
					setDoorState("door_right_b3", value);
                }
				else if(door == "Right_Door_4")
                {
                    setDoorState("door_right_a4", value);
					setDoorState("door_right_b4", value);
                }
            }
        }
        
    };
    //  Class:          m_vehicles::m_vehicleType
    //
    //  Description:    Logically abstract definition of a vehicle type, this class contains
    //                  methods required to bind a vehicle type name with a factory function
    //                  used to create a vehicle.
    //
    class m_vehicle_type : VehicleType
    {
    public:
        //  Function:       getName
        //
        //  Description:    This is essentially the class code from the database for this Vehicle 
        //                  type.

        string getName()
        {
            return "M";
        }

        //  Function:       createVehicle
        //
        //  Description:    Creates a m_vehicle using the given parameters.
        //
        //  Parameters:
        //      VehicleInfoExtern info - Describes the m_vehicle to create.
        //      Properties properties - Configuration properties for the m_vehicle to be created.
        //
        //  Return value:
        //      Vehicle          - The created Vehicle.

        Vehicle createVehicle(VehicleInfoExtern info, Properties properties)
        {
            return new m_vehicle(info, properties);
        }
    };
}

#endif
