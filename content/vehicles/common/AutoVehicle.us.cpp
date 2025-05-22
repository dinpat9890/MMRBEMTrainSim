/// @file AutoVehicle.us.cpp
///
/// @copyright © Copyright: SYDAC Pty Ltd, 2022
#ifndef AUTO_VEHICLE_US_CPP
#define AUTO_VEHICLE_US_CPP

#include <vehicles/Vehicle.us.cpp>
#include <utilities/Trace.us.cpp>

namespace Vehicles
{
    class AutoVehicle : Vehicle
    {
    public:
        AutoVehicle(VehicleInfoExtern info, Properties properties, string node_name)
        {
            __Vehicle__(info, engine.world.loadNode(node_name), properties);

            if(getNode() == 0)
                Trace::log(Trace::ERR, FLSTAMP, "Failed to load vehicle node %s.", node_name);
            else
                initialiseProperties(info);

            Trace::log(Trace::VERBOSE, FLSTAMP, "Successfully loaded vehicle ID %d.", getID());
        }

        void setNumber(string property, double value)
        {
            Trace::log(Trace::VERBOSE, FLSTAMP, "Received number property %s with value %g, for vehicle ID %d.", property, value, getID());

            if(property == "Car Headlights")
                setCarHeadlights(value > 0.0);
            else if(property == "Car Marker Lights")
                setCarMarkerLights(value > 0.0);
            else if(property == "Calling On Light")
                setCarCallingOnLight(value > 0.0);
            else if(property == "Vehicle On Fire")
                setCarOnFire(value > 0.0);
            else
                Vehicle::setNumber(property, value);
        }

    private:
        void enableSurfaces(string SURFACE_NAMES[], int IS_ENABLED)
        {
            foreach(string SURFACE_NAME; SURFACE_NAMES)
                enableSurface(SURFACE_NAME, IS_ENABLED);
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

        void setCarOnFire(int is_on_fire)
        {
            int NODE_ID = m_node.findChild("fire");
            if(NODE_ID != -1)
            {
                Node fire_node = m_node.getChild(NODE_ID);
                if(fire_node != 0)
                    fire_node.setEnabled(is_on_fire);
                else
                    Trace::log(Trace::ERR, FLSTAMP, "Failed to get fire node for vehicle ID %d.", getID());
            }
            else
                Trace::log(Trace::ERR, FLSTAMP, "Failed to find fire node for vehicle ID %d.", getID());
        }
    };
}

#endif
