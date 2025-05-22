//**************************************************************************************************
//
//  File:           t_vehicle.us.cpp
//
//  Description:    t_vehicle class definition
//
//
//  (C) Copyright:  SYDAC Pty Ltd, 2021
//
//***************************************************************************************************

#ifndef t_vehicle_CPP
#define t_vehicle_CPP

#include <vehicles/Vehicle.us.cpp>

namespace Vehicles
{
    //  Class:          Vehicles::t_vehicle
    //
    //  Description:    Logically abstract base class definition of a vehicle, this class contains
    //                  properties common to all vehicles.
    //
    class t_vehicle : Vehicle
    {
    public:

        //  Function:       t_vehicle
        //
        //  Description:    Constructs a t_vehicle with given properties.
        //
        //  Parameters:
        //      VehicleInfoExtern info - The initial data for this vehicle.
        
        t_vehicle(VehicleInfoExtern info, Properties properties)
        {
            __Vehicle__(info, engine.world.loadNode("t_car_exterior.node"), properties);

            if (getNode() == 0)
                log.error("Unable to create vehicle because t_car_exterior.node was unable to be loaded\n");
            else
                initialiseProperties(info);
        }
    
        //  Function:       ~t_vehicle
        //
        //  Description:    Destructor. Cleans up if necessary.
        
        ~t_vehicle()
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
		
		//  Function:       setNumber
		//
		//  Description:    Sets a number property associated with this MC1Vehicle.
		//
		//  Parameters:
		//      string property  - The property name
		//      double value     - The property value

		void setNumber(string property, double value)
		{
			log.message("Received Panto Request for property %s with value %f \n", property, value);
			if(property == "Pantograph Position")
            {
				if(value == 0 /* Panto Down */)
                {
					enableSurface("pantograph_down_m_car", 1);
					enableSurface("pantograph_up_m_car", 0);
				}
				else if(value == 1 /* Panto UP */)
				{
					enableSurface("pantograph_down_m_car", 0);
					enableSurface("pantograph_up_m_car", 1);
				}
			}
		}
        
    };
    //  Class:          t_vehicles::t_vehicleType
    //
    //  Description:    Logically abstract definition of a vehicle type, this class contains
    //                  methods required to bind a vehicle type name with a factory function
    //                  used to create a vehicle.
    //
    class t_vehicle_type : VehicleType
    {
    public:
        //  Function:       getName
        //
        //  Description:    This is essentially the class code from the database for this Vehicle 
        //                  type.

        string getName()
        {
            return "T";
        }

        //  Function:       createVehicle
        //
        //  Description:    Creates a t_vehicle using the given parameters.
        //
        //  Parameters:
        //      VehicleInfoExtern info - Describes the t_vehicle to create.
        //      Properties properties - Configuration properties for the t_vehicle to be created.
        //
        //  Return value:
        //      Vehicle          - The created Vehicle.

        Vehicle createVehicle(VehicleInfoExtern info, Properties properties)
        {
            return new t_vehicle(info, properties);
        }
    };
}

#endif
