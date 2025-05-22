///
/// @file      PlatformDoors.us.cpp
///
/// @group     95809A9A
///
/// @author    David Lannan
/// @author    Simon Wade
///
/// @copyright SYDAC Pty Ltd, 2012
///
#ifndef PLATFORM_DOORS_FEATURE_CPP
#define PLATFORM_DOORS_FEATURE_CPP

#include <Feature.us.cpp>
#include <EmptyNodeWrapper.us.cpp>

namespace Features
{
    int UNINHIBITED         = 0;

    double DOOR_OPEN_POS    = 1.0;
    double DOOR_CLOSE_POS   = 0.0;

    /// @brief
    /// A feature type used to control platform doors.
    ///
    /// Each instance is matched to a platform by specifying the name of a
    /// node via the "Platform Content Name" property. The doors to control are then
    /// determined by searching for children of the platform node that match a
    /// naming convention: the node's name must contain "station_door". Case is
    /// ignored, so "STATION_DOOR" or even "StATiOn_DOOr" will cause a match.
    /// These nodes then have a World Expression attached to them that will
    /// control their behaviour.
    ///
    /// If a door node has either 'l' or 'L' on the end of its name, it will be
    /// moved in the opposite direction to normal.
    ///
    /// To control how open the doors are, values must be written to the
    /// "Platform Doors State" property of the Comms Object that represents each
    /// feature instance. Values range from 0 to 100, with 0 corresponding to
    /// all doors being closed, and 100 to all being open.
    class PlatformDoors : Feature
    {
    private:
        namespace ObjectProperties
        {
            // Names of properties expected to be found within the Comms Object
            // created for each instance of this feature type. These come
            // directly from the feature type XML.
            string PLATFORM_NAME            = "Platform Content Name";
            string PLATFORM_DOORS_POSITION  = "Door Position";
            string PLATFORM_SDO_CODE        = "SDO Code";
            string PLATFORM_DOOR_STATE      = "State";

            int    DOOR_STATE_AUTOMATED     = 1;
            int    DOOR_STATE_CLOSED        = 2;
            int    DOOR_STATE_OPEN          = 3;
        }

        /// @brief
        /// Composed of a Unigine Property containing the parameters required
        /// to drive the DoorControl World Expression, which is specified by
        /// PlatformDoors::DOOR_CONTROL_NODE_FILE.
        class DoorProperty
        {
        private:
            /// Property with the parameters we expect.
            Property m_property;

            // The following are parameter IDs that are cached, to avoid
            // the need to look them up all the time.
            int m_current_position = -1; ///< ID of the "CurrPos" parameter.
            int m_pop_distance     = -1; ///< ID of the "PopDistance" parameter.
            int m_pop_amount       = -1; ///< ID of the "PopAmount" parameter.
            int m_direction        = -1; ///< ID of the "Direction" parameter.

            // The following parameter is to maintain the door state to avoid
            // unnecessary door position changes, i.e. if door position is 100
            // for a door and state changed to open for all doors then this door
            // should not get affected.
            int m_state            = ObjectProperties::DOOR_STATE_CLOSED;

        public:
            /// @brief
            /// Constructs a new DoorProperty object from the given Node.
            ///
            /// It is expected that the node has a Property containing the
            /// following parameters:
            /// - float CurrPos
            /// - float PopDistance
            /// - float PopAmount
            /// - float Direction
            ///
            /// isValid() may be called to determine the success of this
            /// function.
            ///
            /// @param node A Node containing the expected Property type.
            DoorProperty(Node node)
            {
                m_property = node.getProperty();

                if(m_property != 0)
                {
                    m_current_position = m_property.findParameter("CurrPos");
                    m_pop_distance     = m_property.findParameter("PopDistance");
                    m_pop_amount       = m_property.findParameter("PopAmount");
                    m_direction        = m_property.findParameter("Direction");
                }
            }

            /// @brief
            /// Returns non-zero if this DoorProperty has been successfully
            /// constructed.
            ///
            /// As Unigine doesn't properly support exception handling, this
            /// method is supplied in order to determine the success of
            /// object construction. For example, a Node may be passed to the
            /// constructor that doesn't contain the expected type of
            /// Property.
            //
            /// @note A non-zero return value is a precondition for calling any
            ///       of the other member functions.
            ///
            /// @return Non-zero if the object has been successfully constructed.
            int isValid()
            {
                return m_property         != 0  &&
                       m_current_position != -1 &&
                       m_pop_distance     != -1 &&
                       m_pop_amount       != -1 &&
                       m_direction        != -1;
            }

            // TODO: Somebody needs to look through the Door Control script
            //       to determine valid values for the parameters passed to
            //       the following functions.

            /// @brief
            /// Sets the CurrPos parameter.
            ///
            /// @param VALUE Value to use for the CurrPos parameter.
            /// @pre isValid() returns a non-zero value.
            void setCurrPos(double VALUE)
            {
                m_property.setParameterFloat(m_current_position, VALUE);
            }

            /// @brief
            /// Sets the PopDistance parameter.
            ///
            /// @param DISTANCE Value to use for the PopDistance parameter.
            /// @pre isValid() returns a non-zero value.
            void setPopDistance(double DISTANCE)
            {
                m_property.setParameterFloat(m_pop_distance, DISTANCE);
            }

            /// @brief
            /// Sets the PopAmount parameter.
            ///
            /// @param AMOUNT Value to use for the PopAmount parameter.
            /// @pre isValid() returns a non-zero value.
            void setPopAmount(double AMOUNT)
            {
                m_property.setParameterFloat(m_pop_amount, AMOUNT);
            }

            /// @brief
            /// Sets the Direction parameter.
            ///
            /// @param DIRECTION Value to use for the Direction parameter.
            /// @pre isValid() returns a non-zero value.
            void setDirection(double DIRECTION)
            {
                m_property.setParameterFloat(m_direction, DIRECTION);
            }

            /// @brief
            /// Sets the state parameter.
            ///
            /// @param state Value to use for the state parameter.
            void setState(int state)
            {
                m_state = state;
            }

            /// @brief
            /// Gets the state parameter.
            int getState()
            {
                return m_state;
            }
        };

        /// World Expression Node used to control the doors. Attached as a child
        /// of each door node.
        string DOOR_CONTROL_NODE_FILE = "mmrbem/graphics/expressions/DoorControl.node";

        /// Collection of all the DoorProprties controlled by this feature.
        DoorProperty m_door_props[0];

        /// Node inserted in to the editor to represent this feature.
        NodeDummy m_node;

        /// Last known value of the "Door Position" Number on the Comms
        /// Object representing this feature, normalized and clamped to the
        /// range [0, 1].
        double m_platform_doors_position = 0.0;

        /// Selective Door Open Code for platform doors
        int m_sdo_code = 0;

        /// Platform door state.
        int m_door_state = ObjectProperties::DOOR_STATE_CLOSED;

    public:
        /// @brief
        /// Constructs a new instance of a Platform Doors feature.
        ///
        /// @param info       Details about the feature instance.
        /// @param properties Feature properties.
        /// @param parent     Parent to use for any new Nodes.
        PlatformDoors(FeatureInfoExtern info, Properties properties, Node parent)
        {
            __Feature__(info, new EmptyNodeWrapper(), properties);

            // Create a Dummy Node as a reference to the feature. This node can later contain more information
            // about what Doors are in fault and other similar events / features.
            m_node = new NodeDummy();
            m_node.setName(info.getName());
            m_node.setEnabled(0);
            m_node.setParent(parent);
            engine.editor.addNode(node_remove(m_node));

            // Complain if we couldn't find the root node for this feature.
            if(!isValid())
            {
                log.error("Could not find base node with name '" + info.getName() + "' for feature '" + info.getName() + "'!\n");
                return;
            }
            
        }

        /// @brief
        /// Destructor.
        ~PlatformDoors()
        {
            m_door_props.delete();
        }

        /// @brief
        /// Called when a String property changes on the Comms Object
        /// representing this feature instance.
        //
        /// @param property Property name.
        /// @param value New value for the Property.
        void setString(string property, string value)
        {
            if(property != ObjectProperties::PLATFORM_NAME)
                return;
            //log.message("PlatformDoors(" + getID() + ")::setString(" + property + ", " + value + ")\n");

            // Search for the platform vision content that contains the doors we
            // want to control.
            string parent_platform_door_name = "door_" + value; // ex. door_PDX_PSD1
            int platform_i = engine.editor.findNode(parent_platform_door_name);
            if (platform_i == -1)
            {
                log.error("Did not find PlatformDoor node '" + parent_platform_door_name + "'. This platform door will not be operational.\n");
                return;
            }
            
            Node parent_platform_door = engine.editor.getNode(platform_i);

            // Empty our old list of door properties
            while(m_door_props.size() > 0)
            {
                DoorProperty door_property = m_door_props[0];
                m_door_props.remove(0);

                delete door_property;
            }

            // TODO: Really should try and load up the door control node now,
            //       then clone as required. This way we can fail early if
            //       there's something wrong with it.

            // Grab all the children with "station_door" in their name, which are
            // our doors. All platform doors are operated at the same time.
            forloop(int j = 0; parent_platform_door.getNumChildren())
            {
                Node platform_door = parent_platform_door.getChild(j);
                string platform_door_name = lower(platform_door.getName());

                // Skip the nodes which are not related to platform doors
                // also skip nodes associated to driver doors
                if((strstr(platform_door_name, "station_door") < 0) ||
                   (strstr(platform_door_name, "driver") >= 0))
                    continue;

                string door_control_name = "world_expr_" + platform_door_name;
                    
                // Another layer of indirection so that the uppermost node can be adjusted and actually affect
                // the nodes below.
                forloop(int i = 0; platform_door.getNumChildren())
                {
                    Node door = platform_door.getChild(i);
    
                    // Create world expression only if it does not already exist- it may have already been created
                    // and adjusted, and we don't want to throw that away.
                    Node door_control;
                    int door_control_i = door.findChild(door_control_name);
                    int door_control_new = false;
                    if (door_control_i != -1)
                    {
                        // Found it.
                        door_control = door.getChild(door_control_i);
                        //log.message("Found door control '" + door_control_name + "'.\n");
                    }
                    else
                    {
                        //log.message("Creating new door control '" + door_control_name + "'.\n");
                        door_control_new = true;
                        // Load the door control node, which is a world expression, and
                        // assign it to the door node.
                        door_control = engine.world.loadNode(DOOR_CONTROL_NODE_FILE);
                        if(door_control == 0)
                        {
                            log.error("%s (line %d): Unable to open door control node %s\n. " +
                                      "Door %s (ID: 0x%X) on platform %s will NOT be controlled.",
                                      __FILE__,
                                      __LINE__,
                                      DOOR_CONTROL_NODE_FILE,
                                      door.getName(),
                                      door.getID(),
                                      parent_platform_door.getName());
        
                            continue;
                        }
        
                        door_control.setName(door_control_name);
                        
                        if(engine.editor.addNode(door_control) == 0)
                        {
                            // Take ownership of the node ourselves
                            node_append(door_control);
                            log.warning("%s (line %d): Unable to pass node %s (ID: 0x%X) to the editor.",
                                        __FILE__,
                                        __LINE__,
                                        door_control.getName(),
                                        door_control.getID());
                        }
                    }
                    door_control.setParent(door);
    
                    // Get hold of the Property we will need to modify.
                    DoorProperty door_prop = new DoorProperty(door_control);
    
                    if(!door_prop.isValid())
                    {
                        log.error("%s (line %d): Invalid Property in door control node %s. " +
                                  "Door %s (ID: 0x%X) on platform %s will NOT be controlled.",
                                  __FILE__,
                                  __LINE__,
                                  DOOR_CONTROL_NODE_FILE,
                                  door.getName(),
                                  door.getID(),
                                  parent_platform_door.getName());
    
                        delete door_prop;
                        continue;
                    }
    
                    if(door_control_new)
                    {
                        // Set some default parameters that are sensible for sliding doors
                        double direction = (strstr(platform_door_name, "left") < 0) ? 180.0f : 0.0f;
                        door_prop.setDirection(direction);
                        door_prop.setPopDistance(0.0f);
                        door_prop.setPopAmount(0.0f);
                    }
                    // Set initial position.
                    door_prop.setCurrPos(m_platform_doors_position);
    
                    m_door_props.append(door_prop);
                }
            }
        }

        /// @brief
        /// Returns 1 always - this is to be used in the future to enable/disable platform doors.
        /// @return Always 1.
        int isValid()
        {
            return 1;
        }

        /// @brief
        /// Called when a Number changes on the Comms Object representing this
        /// feature instance.
        ///
        /// @param property Number name.
        /// @param value    New value of the Number.
        void setNumber(string property, double value)
        {
            if(property == ObjectProperties::PLATFORM_DOORS_POSITION)
            {
                // We expect values in the range [0, 100], however the world
                // expression expects a normalized value in the range [0, 1].
                // Ideally we would like our input to match the world expression's
                // requirements, but the ObjectProperties::PLATFORM_DOORS_POSITION
                // number has a delta of 0.5, so we're forced to use a larger
                // range of values.
                m_platform_doors_position = clamp(value * 0.01, DOOR_CLOSE_POS, DOOR_OPEN_POS);
                updateDoors();

            }
            else if(property == ObjectProperties::PLATFORM_SDO_CODE)
            {
                m_sdo_code = int(value);
                updateDoors();
            }
            else if(property == ObjectProperties::PLATFORM_DOOR_STATE)
            {
                m_door_state = int(value);
                updateDoors();
            }
        }

        /// @brief
        /// Called per frame to update the feature in vision.
        void update()
        {
           // Currently unused, and should stay that way.
           // NOTE: I dont think we should be using this function at all if possible.
        }
        
        void updateDoors()
        {
            // Update the position of selective doors.
            int sdo_code = m_sdo_code;
            int consider_next_door_pair = true;
            foreach(DoorProperty door_prop; m_door_props)
            {
                consider_next_door_pair = !(consider_next_door_pair);
                int current_door_state = door_prop.getState();
                if((sdo_code & 1) == UNINHIBITED && current_door_state != m_door_state)
                {
                    door_prop.setCurrPos(m_platform_doors_position);

                    if((m_platform_doors_position == DOOR_OPEN_POS && m_door_state == ObjectProperties::DOOR_STATE_OPEN) ||
                       (m_platform_doors_position == DOOR_CLOSE_POS && m_door_state == ObjectProperties::DOOR_STATE_CLOSED))
                        door_prop.setState(m_door_state);
                }

                if(consider_next_door_pair == true)
                    sdo_code = (sdo_code >> 1);
            }

            engine.world.updateSpatial();
        }
    };

    class PlatformDoorsType : FeatureType
    {
    public:
        /// @brief
        /// Returns the name of the feature type created by this factory.
        ///
        /// @return The name of the feature type
        string getName()
        {
            return "PlatformDoors";
        }

        /// @brief
        /// Factory function - creates a PlatformDoors using FeatureInfo and Properties.
        ///
        /// @param info
        ///        Structure containing information about the feature instance
        ///        to be created.
        /// @param properties
        ///        Configuration information about this feature.
        /// @param parent
        ///        The node parent.
        ///
        /// @return The feature created - ownership is now with the caller.
        Feature createFeature(FeatureInfoExtern info, Properties properties, Node parent)
        {
            return new PlatformDoors(info, properties, parent);
        }
    };
}

#endif // PLATFORM_DOORS_FEATURE_CPP
