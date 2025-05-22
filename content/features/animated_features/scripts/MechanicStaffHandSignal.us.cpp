///
/// @file       MechanicStaffHandSignal.us.cpp
///
/// @group      
///
/// @author     Supriya Biradawade
///             Craig Biggs
///
/// @copyright  SYDAC Pty Ltd, 2022
///
///

#ifndef MECHANIC_STAFF_US_CPP
#define MECHANIC_STAFF_US_CPP

#include <AnimatedFeature.us.cpp>

namespace Features
{
    /// Mechanic Staff Hand Signals feature
    class MechanicStaffHandSignalFeature : AnimatedFeature
    {
    private:
        int m_valid;
        ObjectMeshSkinned m_mechanic_staff_hand_signal_node = 0;

    public:

        enum
        {
            NOT_VISIBLE = 1,
            IDLE,
            STOP_FLAG,
            STOP_HANDS,
            STOP_LANTERN,
            CAUTION_FLAG,
            CAUTION_HANDS,
            CAUTION_LANTERN,
            PROCEED_FLAG,
            PROCEED_HANDS,
            PROCEED_LANTERN,
            SHUNTING_LEFT,
            SHUNTING_RIGHT
        };

        /// Constructs a new instance of a Mechanic Staff Hand Signal feature. The constructor
        /// will define the state to NodeAction transitions required for this feature.
        ///
        /// @param info       Information about the feature. If you have access to
        ///                   it, this is defined externally in
        ///                   Software\Libraries\VisionManager\Source\FeatureInfo.h.
        /// @param properties Generic vision properties.
        /// @param parent     The parent node for the feature.
        MechanicStaffHandSignalFeature(FeatureInfoExtern info, Properties properties, Node parent)
        {
            __AnimatedFeature__(info, properties, parent);
            
            Node mechanic_staff = engine.world.loadNode(info.getNodeFileName());
            m_mechanic_staff_hand_signal_node = (mechanic_staff == 0) ? 0 : node_cast(mechanic_staff);

            // Attempt to load the each node. If we are successful loading it, register
            // with the AnimatedFeature class and then associate each state with its set of actions.
            // FIXME: Whilst the animations and content for the IR Staff characters are being fixed we just
            // use the same node for now.

            if (m_mechanic_staff_hand_signal_node != 0 /*&& node_master.getType() == NODE_OBJECT_MESH_SKINNED*/)
            {
                registerNode(m_mechanic_staff_hand_signal_node);

                // Essentially constants
                string GUARD_HEAD_SURFACE       = "station_guard_blue_head_LOD_0";
                string GUARD_BODY_SURFACE       = "station_guard_blue_body_LOD_0";
                string RED_FLAG_SURFACE         = "flag_red";
                string RED_LANTERN_SURFACE      = "lantern_red";
                string GREEN_FLAG_SURFACE       = "flag_green";
                string GREEN_LANTERN_SURFACE    = "lantern_green";

                string IDLE_ANIMATION                       = "civilian_flag_idle.anim";  
                string PROCEED_AND_STOP_FLAG_ANIMATION      = "proceed_stop_flag.anim";
                string PROCEED_AND_STOP_LANTERN_ANIMATION   = "proceed_stop_lantern.anim";
                string STOP_HANDS_ANIMATION                 = "stop_hands.anim";
                string CAUTION_FLAG_ANIMATION               = "caution_flag.anim";
                string CAUTION_HANDS_ANIMATION              = "caution_hands.anim";
                string CAUTION_LANTERN_ANIMATION            = "caution_lantern.anim";
                string PROCEED_HANDS_ANIMATION              = "proceed_hands.anim";
                string SHUNTING_ANIMATION                   = "shunting_signal.anim";

                double DEFAULT_ANIMATION_SPEED      = 40.0;

                int mechanic_staff_idle_animation_id                     = -1; // Mechanic Staff Idle
                int mechanic_staff_proceed_stop_flag_animation_id        = -1; // Mechanic Staff Proceed and Stop Flag
                int mechanic_staff_proceed_stop_lantern_animation_id     = -1; // Mechanic Staff Proceed and Stop Lantern
                int mechanic_staff_stop_hands_animation_id               = -1; // Mechanic Staff Stop Hands
                int mechanic_staff_caution_flag_animation_id             = -1; // Mechanic Staff Caution Flag
                int mechanic_staff_caution_hands_animation_id            = -1; // Mechanic Staff Caution Hands
                int mechanic_staff_caution_lantern_animation_id          = -1; // Mechanic Staff Caution Lantern
                int mechanic_staff_proceed_hands_animation_id            = -1; // Mechanic Staff Proceed Hands
                int mechanic_staff_shunting_animation_id                 = -1; // Mechanic Staff Shunting

                mechanic_staff_idle_animation_id                 = m_mechanic_staff_hand_signal_node.addAnimation(IDLE_ANIMATION);
                mechanic_staff_proceed_stop_flag_animation_id    = m_mechanic_staff_hand_signal_node.addAnimation(PROCEED_AND_STOP_FLAG_ANIMATION);
                mechanic_staff_proceed_stop_lantern_animation_id = m_mechanic_staff_hand_signal_node.addAnimation(PROCEED_AND_STOP_LANTERN_ANIMATION);
                mechanic_staff_stop_hands_animation_id           = m_mechanic_staff_hand_signal_node.addAnimation(STOP_HANDS_ANIMATION);
                mechanic_staff_caution_flag_animation_id         = m_mechanic_staff_hand_signal_node.addAnimation(CAUTION_FLAG_ANIMATION);
                mechanic_staff_caution_hands_animation_id        = m_mechanic_staff_hand_signal_node.addAnimation(CAUTION_HANDS_ANIMATION);
                mechanic_staff_caution_lantern_animation_id      = m_mechanic_staff_hand_signal_node.addAnimation(CAUTION_LANTERN_ANIMATION);
                mechanic_staff_proceed_hands_animation_id        = m_mechanic_staff_hand_signal_node.addAnimation(PROCEED_HANDS_ANIMATION);
                mechanic_staff_shunting_animation_id             = m_mechanic_staff_hand_signal_node.addAnimation(SHUNTING_ANIMATION);


                NodeAction NO_ROTATION      = new MechanicStaffMoveAndAnimate(m_mechanic_staff_hand_signal_node, mechanic_staff_idle_animation_id, 45.0, 0.0, 180.0, translate(dvec3(0.0, 0.0, 0.0)) * rotateZ(0.0));
                NodeAction PARTIAL_ROTATION_LEFT = new MechanicStaffMoveAndAnimate(m_mechanic_staff_hand_signal_node, mechanic_staff_idle_animation_id, 45.0, 0.0, 80.0, translate(dvec3(0.0, 0.0, 0.0)) * rotateZ(90.0));
                NodeAction PARTIAL_ROTATION_RIGHT = new MechanicStaffMoveAndAnimate(m_mechanic_staff_hand_signal_node, mechanic_staff_idle_animation_id, 45.0, 0.0, 80.0, translate(dvec3(0.0, 0.0, 0.0)) * rotateZ(-90.0));

                // This block associates each state with the relevant actions.
                
                // We set an idle animation for not visible, since this will result in nicer blends in future state transitions.
                setAction(NOT_VISIBLE, new NodeActionSequence((NO_ROTATION, new NodeEnableSurfaces(m_mechanic_staff_hand_signal_node, (), 1))));

                setAction(IDLE, 
                    new NodeActionSequence((NO_ROTATION, new NodeEnableSurfaces(m_mechanic_staff_hand_signal_node, (GUARD_HEAD_SURFACE, GUARD_BODY_SURFACE), 1),
                    new NodeActionLoop(new MechanicStaffNodeAnimate(m_mechanic_staff_hand_signal_node, mechanic_staff_idle_animation_id, DEFAULT_ANIMATION_SPEED)))));

                setAction(STOP_FLAG, new NodeActionSequence((NO_ROTATION,
                    new NodeEnableSurfaces(m_mechanic_staff_hand_signal_node, (GUARD_HEAD_SURFACE, GUARD_BODY_SURFACE, RED_FLAG_SURFACE), 1),
                    new NodeActionLoop(new MechanicStaffNodeAnimate(m_mechanic_staff_hand_signal_node, mechanic_staff_proceed_stop_flag_animation_id, DEFAULT_ANIMATION_SPEED)))));

                setAction(STOP_HANDS, new NodeActionSequence((NO_ROTATION,
                    new NodeEnableSurfaces(m_mechanic_staff_hand_signal_node, (GUARD_HEAD_SURFACE, GUARD_BODY_SURFACE), 1),
                    new NodeActionLoop(new MechanicStaffNodeAnimate(m_mechanic_staff_hand_signal_node, mechanic_staff_stop_hands_animation_id, DEFAULT_ANIMATION_SPEED)))));

                setAction(STOP_LANTERN, new NodeActionSequence((NO_ROTATION,
                    new NodeEnableSurfaces(m_mechanic_staff_hand_signal_node, (GUARD_HEAD_SURFACE, GUARD_BODY_SURFACE, RED_LANTERN_SURFACE), 1),
                    new NodeActionLoop(new MechanicStaffNodeAnimate(m_mechanic_staff_hand_signal_node, mechanic_staff_proceed_stop_lantern_animation_id, DEFAULT_ANIMATION_SPEED)))));

                setAction(CAUTION_FLAG, new NodeActionSequence((NO_ROTATION,
                    new NodeEnableSurfaces(m_mechanic_staff_hand_signal_node, (GUARD_HEAD_SURFACE, GUARD_BODY_SURFACE, GREEN_FLAG_SURFACE), 1),
                    new NodeActionLoop(new MechanicStaffNodeAnimate(m_mechanic_staff_hand_signal_node, mechanic_staff_caution_flag_animation_id, DEFAULT_ANIMATION_SPEED)))));

                setAction(CAUTION_HANDS, new NodeActionSequence((NO_ROTATION,
                    new NodeEnableSurfaces(m_mechanic_staff_hand_signal_node, (GUARD_HEAD_SURFACE, GUARD_BODY_SURFACE), 1),
                    new NodeActionLoop(new MechanicStaffNodeAnimate(m_mechanic_staff_hand_signal_node, mechanic_staff_caution_hands_animation_id, DEFAULT_ANIMATION_SPEED)))));

                setAction(CAUTION_LANTERN, new NodeActionSequence((NO_ROTATION,
                    new NodeEnableSurfaces(m_mechanic_staff_hand_signal_node, (GUARD_HEAD_SURFACE, GUARD_BODY_SURFACE, GREEN_LANTERN_SURFACE), 1),
                    new NodeActionLoop(new MechanicStaffNodeAnimate(m_mechanic_staff_hand_signal_node, mechanic_staff_caution_lantern_animation_id, DEFAULT_ANIMATION_SPEED)))));

                setAction(PROCEED_FLAG, new NodeActionSequence((NO_ROTATION,
                    new NodeEnableSurfaces(m_mechanic_staff_hand_signal_node, (GUARD_HEAD_SURFACE, GUARD_BODY_SURFACE, GREEN_FLAG_SURFACE), 1),
                    new NodeActionLoop(new MechanicStaffNodeAnimate(m_mechanic_staff_hand_signal_node, mechanic_staff_proceed_stop_flag_animation_id, DEFAULT_ANIMATION_SPEED)))));

                setAction(PROCEED_HANDS, new NodeActionSequence((NO_ROTATION,
                    new NodeEnableSurfaces(m_mechanic_staff_hand_signal_node, (GUARD_HEAD_SURFACE, GUARD_BODY_SURFACE), 1),
                    new NodeActionLoop(new MechanicStaffNodeAnimate(m_mechanic_staff_hand_signal_node, mechanic_staff_proceed_hands_animation_id, DEFAULT_ANIMATION_SPEED)))));

                setAction(PROCEED_LANTERN, new NodeActionSequence((NO_ROTATION,
                    new NodeEnableSurfaces(m_mechanic_staff_hand_signal_node, (GUARD_HEAD_SURFACE, GUARD_BODY_SURFACE, GREEN_LANTERN_SURFACE), 1),
                    new NodeActionLoop(new MechanicStaffNodeAnimate(m_mechanic_staff_hand_signal_node, mechanic_staff_proceed_stop_lantern_animation_id, DEFAULT_ANIMATION_SPEED)))));

                setAction(SHUNTING_LEFT, new NodeActionSequence((PARTIAL_ROTATION_LEFT,
                    new NodeEnableSurfaces(m_mechanic_staff_hand_signal_node, (GUARD_HEAD_SURFACE, GUARD_BODY_SURFACE, GREEN_FLAG_SURFACE), 1),
                    new NodeActionLoop(new MechanicStaffNodeAnimate(m_mechanic_staff_hand_signal_node, mechanic_staff_shunting_animation_id, DEFAULT_ANIMATION_SPEED)))));

                setAction(SHUNTING_RIGHT, new NodeActionSequence((PARTIAL_ROTATION_RIGHT,
                    new NodeEnableSurfaces(m_mechanic_staff_hand_signal_node, (GUARD_HEAD_SURFACE, GUARD_BODY_SURFACE, GREEN_FLAG_SURFACE), 1),
                    new NodeActionLoop(new MechanicStaffNodeAnimate(m_mechanic_staff_hand_signal_node, mechanic_staff_shunting_animation_id, DEFAULT_ANIMATION_SPEED)))));

                m_valid = 1;
            }
            else
            {
                log.error("Unable to load child feature - invalid node file for feature with id %d\n", info.getID());
                m_valid = 0;
            }
        }

        /// Returns the validity of this feature.
        ///
        /// @return 1 if the feature is valid, 0 otherwise.
        int isValid()
        {
            return AnimatedFeature::isValid() && m_valid ? 1 : 0;
        }

        void setNumber(string property, double value) {
          if (property == "State") {
            if (int(value) == NOT_VISIBLE) {
                m_mechanic_staff_hand_signal_node.setEnabled(0);
            } else {
                m_mechanic_staff_hand_signal_node.setEnabled(1);
              AnimatedFeature::setNumber(property, value);
            }
          } else {
            AnimatedFeature::setNumber(property, value);
          }
        }

        /// This class allows us to move and animate Mechanic Staff. This a specific case
        /// of NodeActionComposite since our completion criteria is based on
        /// whether the movement is complete (the animation will never complete
        /// since movement animations are always looping).1
        class MechanicStaffMoveAndAnimate : NodeAction {
        private:
          NodeEnable m_enable_action;
          NodeMove m_move_action;
          NodeActionLoop m_animate_action;

        public:
          /// Constructor. Stores the given vector of actions
          /// in an internal Unigine::Vector.
          ///
          /// @param node             The ObjectMeshSkinned object we are
          /// animating.
          /// @param animation _id    The identifier of the animation we are
          /// applying to this ObjectMeshSkinned object.
          /// @param animation_speed  The animation we are applying to this
          /// ObjectMeshSkinned object.
          /// @param move_speed       The speed that we wish to move the Node
          /// at. As a guide 2.0 would give you the movement of a fast walk.
          ///                         This will require tuning in the derived
          ///                         class to get it right.
          /// @param turn_speed       The number of degrees per frame that the
          /// Node can rotate. Something around 180 looks sensible.
          /// @param target_transform The target transform in world coordinates.
          /// The raycaster for this feature will be used to obtain a
          ///                         true target transform.
            MechanicStaffMoveAndAnimate(ObjectMeshSkinned node, int animation_id,
                              double animation_speed, double move_speed,
                              double turn_speed, dmat4 target_transform) {
            m_enable_action     = new NodeEnable(node, 1);
            m_move_action       = new NodeMove(node, move_speed, turn_speed, target_transform);
            m_animate_action = new NodeActionLoop(new MechanicStaffNodeAnimate(node, animation_id, animation_speed));
          }

          /// Executes this action at the given time.
          ///
          /// @param time  The time at which this action is to be executed.
          void executeImpl(double time) {
            m_enable_action.execute(time);
            m_move_action.execute(time);
            m_animate_action.execute(time);

            // The move action will drive the completion of this Action
            if (m_move_action.isCompleted())
              completed();
          }

          /// Feeds the reset down to constituent NodeAction objects.
          void reset() {
            m_enable_action.reset();
            m_move_action.reset();
            m_animate_action.reset();

            m_initialised = 0;
            m_completed = 0;
          }
        };

        /// This class represents the action to animate the given node
        /// Mechanic Staff (which is an ObjectMeshSkinned since it needs to be
        /// capable of animations).
        class MechanicStaffNodeAnimate : NodeActionSingle {
        private:
          int m_animation_id;
          int m_layer;
          int m_speed;
          double m_start_time;

        public:
          /// Constructor - intialises all members.
          ///
          /// @param node             The ObjectMeshSkinned object we are
          /// animating.
          /// @param animation _id    The identifier of the animation we are
          /// applying to this ObjectMeshSkinned object.
          /// @param speed            The speed to be applied to this animation.
            MechanicStaffNodeAnimate(ObjectMeshSkinned node, int animation_id,
                           int speed) {
            __NodeActionSingle__(node);
            m_animation_id = animation_id;
            m_layer = 0; // default layer
            m_speed = speed;
          }

          /// Executes this node action at the given time. This will modify the
          /// state of the Node (thus changing the animation frame for the
          /// primary layer and fixing any blends on secondary animation layers.
          ///
          /// @param The time to execute this action at.
          void executeImpl(double time) {
            m_skinned_node.setAnimation(m_layer, m_animation_id);

            // Figure out the frame of the animation we need for the elapsed
            // time.
            double delta_time = time - m_start_time;
            double frame = delta_time * m_speed;

            // As this is zero-based, the maximum frame number is getNumFrames()
            // - 1, BUT we also have to discard the bind pose, so our number
            // of frames is one fewer again (getNumFrames() - 2).
            int MAX_FRAMES = m_skinned_node.getNumFrames(m_layer) - 2;
            frame = clamp(frame, 0.0, double(MAX_FRAMES));
            m_skinned_node.setFrame(m_layer, frame,
                                    1); // Our animation starts at frame 1.
            if (frame == MAX_FRAMES)
              completed();
          }

          /// This function initialises the start time of the NodeAction and
          /// sets up some animation parameters on the animation Node.
          ///
          /// @param time The time at which this action starts.
          void init(double time) {
            m_start_time = time;
            m_skinned_node.setLayer(m_layer, 1, 1.0);
            m_initialised = 1;
          }
        };
    };

    /// Representation of a feature type. Contains the binding between
    /// a feature type name and a factory function to create the associated
    /// feature type (StationGuardFeature).
    class MechanicStaffHandSignalFeatureType : FeatureType
    {
    public:

        /// Constructs a feature properties object caching data members based on
        /// Unigine engine config. Note this needs to be the feature type's CLASS
        ///
        /// @return The name of the feature type
        string getName()
        {
            return "MechanicStaffHandSignalFeature";
        }

        /// Factory function - creates a Children using FeatureInfo and Properties.
        ///
        /// @param info Structure containing information about the feature instance
        ///             to be created.
        /// @param properties Configuration information about this feature.
        /// @param parent Parent node
        ///
        /// @return The feature created - ownership is now with the caller.
        Feature createFeature(FeatureInfoExtern info, Properties properties, Node parent)
        {
            return new MechanicStaffHandSignalFeature(info, properties, parent);
        }
    };
}

#endif
