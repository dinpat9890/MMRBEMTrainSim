//**************************************************************************************************
//
//  File:           dm_vehicle.us.cpp
//
//  Description:    dm_vehicle class definition
//
//
//  (C) Copyright:  SYDAC Pty Ltd, 2021
//
//***************************************************************************************************

#ifndef dm_vehicle_CPP
#define dm_vehicle_CPP

#include <framework/Timing.us.cpp>
#include <vehicles/Vehicle.us.cpp>
#include <vehicles/common/AutoVehicle.us.cpp>
#include <vehicles/SelectiveVehicleType.us.cpp>
#include <windscreen/WindscreenEffects.us.cpp>

namespace Vehicles
{
    //  Class:          Vehicles::dm_vehicle
    //
    //  Description:    Logically abstract base class definition of a vehicle, this class contains
    //                  properties common to all vehicles.
    //
    class dm_vehicle : Vehicle
    {
    private:
        int     m_under_cover                = 0;
        double  m_last_under_cover_test_time = -1.0; // This ensures we get a check at time zero.

    public:

        //  Function:       dm_vehicle
        //
        //  Description:    Constructs a dm_vehicle with given properties.
        //
        //  Parameters:
        //      VehicleInfoExtern info - The initial data for this vehicle.

        dm_vehicle(VehicleInfoExtern info, Properties properties)
        {
            __Vehicle__(info, engine.world.loadNode("dm_train_exterior.node"), properties);

            WindscreenEffects::loadConfig("dm_train/scripts/windscreen_effects.xml", m_windscreen_effect_monitor);

            if (getNode() == 0)
                log.error("Unable to create vehicle because dm_train_exterior.node was unable to be loaded\n");
            else
                initialiseProperties(info);

            VehicleManager::vehicle_manager.updateNextFrame(this);
        }

        //  Function:       ~dm_vehicle
        //
        //  Description:    Destructor. Cleans up if necessary.

        ~dm_vehicle()
        {
        }

        //  Function:       setNumber
        //
        //  Description:    Sets a number property associated with this SRTLSC_CSR_Vehicle.
        //
        //  Parameters:
        //      string property  - The property name
        //      double value     - The property value

        void setNumber(string property, double value)
        {
			log.message("Received wiper number for property %s with value %f on vehicle DM\n", property, value);
            if(property == "Overlay/SydacTrainDerailment")
                setOverlayEnabled(property, int(value));
            else if(property == "Overlay/SydacTrainCollision")
                setOverlayEnabled(property, int(value));
			else if (property == "Coupled Overlay" || property == "Coupled")
                setOverlayEnabled("Overlay/CouplingSuccessful", int(value));
			else if (property == "Coupler Damaged Overlay" || property == "Coupler Damaged")
                setOverlayEnabled("Overlay/CouplerDamaged", int(value));
            else if (property == "Wiper Position Center")
            {
                m_windscreen_effect_monitor.updateWiper("center_wiper", value);
            }
			else if (property == "Wiper Position Left")
            {
                m_windscreen_effect_monitor.updateWiper("left_wiper", value);
            }
			else if (property == "Wiper Position Right")
            {
                m_windscreen_effect_monitor.updateWiper("right_wiper", value);
			}                
			else if(property == "Head Light" || property == "Car Headlights")
            {
                if(value == 0 /* Off */)
                {
                    enableHeadlightModel("HeadLightLowBeamLHS", 0);
                    enableHeadlightModel("HeadLightLowBeamRHS", 0);
                    enableHeadlightModel("HeadLightHighBeamLHS", 0);
                    enableHeadlightModel("HeadLightHighBeamRHS", 0);


                    enableSurface("headlight_l", 0);
                    enableSurface("headlight_r", 0);
                }
                else if(value == 1 /* Low */)
                {
                    enableHeadlightModel("HeadLightLowBeamLHS", 1);
                    enableHeadlightModel("HeadLightLowBeamRHS", 1);
                    enableHeadlightModel("HeadLightHighBeamLHS", 0);
                    enableHeadlightModel("HeadLightHighBeamRHS", 0);

                    enableSurface("headlight_l", 1);
                    enableSurface("headlight_r", 1);

                }
                else if(value == 2 /* High */)
                {
                    enableHeadlightModel("HeadLightLowBeamLHS", 0);
                    enableHeadlightModel("HeadLightLowBeamRHS", 0);
                    enableHeadlightModel("HeadLightHighBeamLHS", 1);
                    enableHeadlightModel("HeadLightHighBeamRHS", 1);

                    enableSurface("headlight_l", 1);
                    enableSurface("headlight_r", 1);
                }
            }
            else if(property == "Flood Light" || property == "Car Flood Light")
            {
                if(value == 0 /* Off */)
                {
                    enableHeadlightModel("FloodLight", 0);
                    enableSurface("floodlight", 0);
                }
                else if(value == 1 /* On */)
                {
                    enableHeadlightModel("FloodLight", 1);
                    enableSurface("floodlight", 1);
                }
            }
            else if(property == "Flasher Light" || property == "Car Flasher Light")
            {
                if(value == 0 /* Off */)
                {
                    enableHeadlightModel("FlashLight", 0);
                    enableSurface("flasherlight", 0);
                }
                else if(value == 1 /* On */)
                {
                    enableHeadlightModel("FlashLight", 1);
                    enableSurface("flasherlight", 1);
                }
            }
            else if(property == "UTO Or RM Light" || property == "Car UTO RM Lights")
            {
                if(value == 0 /* Off */)
                {
                    enableHeadlightModel("rmlight_LHS", 0);
                    enableHeadlightModel("rmlight_RHS", 0);

                    enableSurface("indicator_l_green", 0);
                    enableSurface("indicator_r_green", 0);
                }
                else if(value == 1 || value == 2)
                {
                    enableHeadlightModel("rmlight_LHS", 1);
                    enableHeadlightModel("rmlight_RHS", 1);

                    enableSurface("indicator_l_green", 1);
                    enableSurface("indicator_r_green", 1);
                }
            }
            else if(property == "Marker Or Tail Light" || property == "Car Marker Lights")
            {
                if(value == 0 /* Off */)
                {
                    enableHeadlightModel("Taillight_LHS", 0);
                    enableHeadlightModel("Taillight_RHS", 0);
                    enableSurface("taillight_l_white", 0);
                    enableSurface("taillight_r_white", 0);
                    enableSurface("taillight_l_red", 0);
                    enableSurface("taillight_r_red", 0);
                }
                else if(value == 1 /* On */)
                {
                    enableHeadlightModel("Taillight_LHS", 1);
                    enableHeadlightModel("Taillight_RHS", 1);
                    enableSurface("taillight_l_white", 1);
                    enableSurface("taillight_r_white", 1);
                    enableSurface("taillight_l_red", 0);
                    enableSurface("taillight_r_red", 0);
                }
                else if(value == 2 /* On */)
                {
                    enableHeadlightModel("Taillight_LHS", 1);
                    enableHeadlightModel("Taillight_RHS", 1);
                    enableSurface("taillight_l_white", 0);
                    enableSurface("taillight_r_white", 0);
                    enableSurface("taillight_l_red", 1);
                    enableSurface("taillight_r_red", 1);
                }
            }
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

        //  Function:       update
        //
        //  Description:    Update function for the vehicle.

        void update()
        {
            Vehicle::update();
        }

        // Vehicles::Vehicle override.
        int isUnderCover()
        {
            // Every half a second, raycast from above the train to see if it is beneath cover.
            double now = Timing::getTime();
            if (abs(now - m_last_under_cover_test_time) > 0.5)
            {
                m_under_cover = 0;

                WorldIntersection intersection_results = new WorldIntersection();

                vec3 left_side_end    = m_node.getWorldTransform() * vec3(-1, 0, 0);
                vec3 left_side_origin = left_side_end + vec3(0, 0, 50);

                int left_hit = engine.world.getIntersection(left_side_origin, left_side_end, 0x2, intersection_results) != 0;
                if (left_hit)
                {
                    vec3 right_side_end    = m_node.getWorldTransform() * vec3(1, 0, 0);
                    vec3 right_side_origin = right_side_end + vec3(0, 0, 50);

                    int right_hit = engine.world.getIntersection(right_side_origin, right_side_end, 0x2, intersection_results) != 0;
                    if (right_hit)
                        m_under_cover = 1;
                }

                delete intersection_results;
                intersection_results = 0;

                m_last_under_cover_test_time = now;
            }

            return m_under_cover;
        }
    };

    class dm_AutoVehicle : AutoVehicle
    {
    public:
        dm_AutoVehicle(VehicleInfoExtern info, Properties properties)
          : AutoVehicle(info, properties, "csr_sda3_auto.node")
        {
        }

        ~dm_AutoVehicle()
        {
        }

        void setCarHeadlights(int enable_headlights)
        {
        }

        void setCarMarkerLights(int enable_marker_lights)
        {
        }

        void setCarCallingOnLight(int enable_calling_on_light)
        {
        }
    };


    //  Class:          dm_vehicles::dm_vehicleType
    //
    //  Description:    Logically abstract definition of a vehicle type, this class contains
    //                  methods required to bind a vehicle type name with a factory function
    //                  used to create a vehicle.
    //
    class dm_vehicle_type : VehicleType
    {
    public:
        //  Function:       getName
        //
        //  Description:    This is essentially the class code from the database for this Vehicle
        //                  type.

        string getName()
        {
            return "DM";
        }

        //  Function:       createVehicle
        //
        //  Description:    Creates a dm_vehicle using the given parameters.
        //
        //  Parameters:
        //      VehicleInfoExtern info - Describes the dm_vehicle to create.
        //      Properties properties - Configuration properties for the dm_vehicle to be created.
        //
        //  Return value:
        //      Vehicle          - The created Vehicle.

        Vehicle createVehicle(VehicleInfoExtern info, Properties properties)
        {
            return new dm_vehicle(info, properties);
        }

        Vehicle createAutoVehicle(VehicleInfoExtern info, Properties properties)
        {
            return new dm_AutoVehicle(info, properties);
        }
    };
}

#endif
