///
/// @file       CivillianHandSignal.us.cpp
///
/// @group      
///
/// @author     Supriya Biradawade
///             Craig Biggs
///             Stephen Wright
///
/// @copyright  SYDAC Pty Ltd, 2022
///
///

#ifndef TRACK_WORKER_US_CPP
#define TRACK_WORKER_US_CPP

#include <AnimatedFeature.us.cpp>

namespace Features
{
    /// Staff Hand Signals feature
    class CivillianHandSignalFeature : AnimatedFeature
    {
    private:
        int m_valid;
        ObjectMeshSkinned m_civillian_node = 0;

    public:

        enum
        {
            NOT_VISIBLE = 1,
            IDLE,
            IDLE_GREEN_FLAG,
            WAVING_GREEN_FLAG,
        };

        /// Constructs a new instance of a Civillian Hand Signal feature. The constructor
        /// will define the state to NodeAction transitions required for this feature.
        ///
        /// @param info       Information about the feature. If you have access to
        ///                   it, this is defined externally in
        ///                   Software\Libraries\VisionManager\Source\FeatureInfo.h.
        /// @param properties Generic vision properties.
        /// @param parent     The parent node for the feature.
        CivillianHandSignalFeature(FeatureInfoExtern info, Properties properties, Node parent)
        {
            __AnimatedFeature__(info, properties, parent);
            
            Node civillian = engine.world.loadNode(info.getNodeFileName());
            m_civillian_node = (civillian == 0) ? 0 : node_cast(civillian);

            // Attempt to load the each node. If we are successful loading it, register
            // with the AnimatedFeature class and then associate each state with its set of actions.
            // FIXME: Whilst the animations and content for the IR Staff characters are being fixed we just
            // use the same node for now.

            if (m_civillian_node != 0 /*&& node_master.getType() == NODE_OBJECT_MESH_SKINNED*/)
            {
                registerNode(m_civillian_node);

                // Essentially constants
                string CIVILLIAN_HEAD_SURFACE   = "civillian_signaller_head_LOD_0";
                string CIVILLIAN_BODY_SURFACE   = "civillian_signaller_body_LOD_0";
                string GREEN_FLAG_SURFACE       = "green_flag";

                string IDLE_ANIMATION           = "civilian_flag_idle.anim";  
                string FLAG_WAVE_ANIMATION      = "civilian_flag_waving.anim"; 

                double DEFAULT_ANIMATION_SPEED  = 40.0;

                int civillian_idle_animation_id         = -1; // Civillian Idle
                int civillian_flag_wave_animation_id    = -1; // Civillian Flag Wave

                civillian_idle_animation_id = m_civillian_node.addAnimation(IDLE_ANIMATION);
                civillian_flag_wave_animation_id = m_civillian_node.addAnimation(FLAG_WAVE_ANIMATION);

                NodeAction NO_ROTATION      = new CivillianMoveAndAnimate(m_civillian_node, civillian_idle_animation_id, 45.0, 0.0, 180.0, translate(dvec3(0.0, 0.0, 0.0)) * rotateZ(0.0));

                // This block associates each state with the relevant actions.
                
                // We set an idle animation for not visible, since this will result in nicer blends in future state transitions.
                setAction(NOT_VISIBLE, new NodeActionSequence((NO_ROTATION, new NodeEnableSurfaces(m_civillian_node, (), 1))));

                setAction(IDLE,
                    new NodeActionSequence((NO_ROTATION, new NodeEnableSurfaces(m_civillian_node, (CIVILLIAN_HEAD_SURFACE, CIVILLIAN_BODY_SURFACE), 1),
                    new NodeActionLoop(new CivillianNodeAnimate(m_civillian_node, civillian_idle_animation_id, DEFAULT_ANIMATION_SPEED)))));

                setAction(IDLE_GREEN_FLAG, 
                    new NodeActionSequence((NO_ROTATION, new NodeEnableSurfaces(m_civillian_node, (CIVILLIAN_HEAD_SURFACE, CIVILLIAN_BODY_SURFACE, GREEN_FLAG_SURFACE), 1),
                    new NodeActionLoop(new CivillianNodeAnimate(m_civillian_node, civillian_idle_animation_id, DEFAULT_ANIMATION_SPEED)))));

                setAction(WAVING_GREEN_FLAG, 
                    new NodeActionSequence((NO_ROTATION, new NodeEnableSurfaces(m_civillian_node, (CIVILLIAN_HEAD_SURFACE, CIVILLIAN_BODY_SURFACE, GREEN_FLAG_SURFACE), 1),
                    new NodeActionLoop(new CivillianNodeAnimate(m_civillian_node, civillian_flag_wave_animation_id, DEFAULT_ANIMATION_SPEED)))));

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
                m_civillian_node.setEnabled(0);
            } else {
                m_civillian_node.setEnabled(1);
              AnimatedFeature::setNumber(property, value);
            }
          } else {
            AnimatedFeature::setNumber(property, value);
          }
        }

        /// This class allows us to move and animate track worker. This a specific case
        /// of NodeActionComposite since our completion criteria is based on
        /// whether the movement is complete (the animation will never complete
        /// since movement animations are always looping).1
        class CivillianMoveAndAnimate : NodeAction {
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
            CivillianMoveAndAnimate(ObjectMeshSkinned node, int animation_id,
                              double animation_speed, double move_speed,
                              double turn_speed, dmat4 target_transform) {
            m_enable_action     = new NodeEnable(node, 1);
            m_move_action       = new NodeMove(node, move_speed, turn_speed, target_transform);
            m_animate_action = new NodeActionLoop(new CivillianNodeAnimate(node, animation_id, animation_speed));
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
        /// track worker (which is an ObjectMeshSkinned since it needs to be
        /// capable of animations).
        class CivillianNodeAnimate : NodeActionSingle {
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
            CivillianNodeAnimate(ObjectMeshSkinned node, int animation_id,
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
    /// feature type (TrackWorkerFeature).
    class CivillianHandSignalFeatureType : FeatureType
    {
    public:

        /// Constructs a feature properties object caching data members based on
        /// Unigine engine config. Note this needs to be the feature type's CLASS
        ///
        /// @return The name of the feature type
        string getName()
        {
            return "CivillianHandSignalFeature";
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
            return new CivillianHandSignalFeature(info, properties, parent);
        }
    };
}

#endif
