///
/// @file       ObstructionCow.us.cpp
///
/// @group      95809A9A
///
/// @author     Raghu Gandi (unigine 2 related changes)
/// @author     Craig Biggs
///
/// @copyright  SYDAC Pty Ltd, 2013
///
///

#ifndef OBSTRUCTION_COW_US_CPP
#define OBSTRUCTION_COW_US_CPP

#include <AnimatedFeature.us.cpp>

namespace Features
{
    /// Cow obstruction feature
    class ObstructionCow : AnimatedFeature
    {
    private:
        int m_valid;
        enum
        {
            NOT_VISIBLE = 1,
            OFF_TRACK = 2,
            ON_TRACK = 3,
        };
    public:
        /// Constructs a new instance of a ObstructionCow feature. The constructor
        /// will define the state to NodeAction transitions required for this feature.
        ///
        /// @param info       Information about the feature. If you have access to
        ///                   it, this is defined externally in
        ///                   Software\Libraries\VisionManager\Source\FeatureInfo.h.
        /// @param properties Generic vision properties.
        /// @param parent     The parent node for the feature.
        ObstructionCow(FeatureInfoExtern info, Properties properties, Node parent)
        {
            __AnimatedFeature__(info, properties, parent);

            // Attempt to load the cow node. If we are successful loading it, register
            // with the AnimatedFeature class and then associate each state with its set of actions.
            Node cow                      = engine.world.loadNode("cow.node");
            ObjectMeshSkinned skinned_cow = (cow == 0) ? 0 : node_cast(cow);
            if(skinned_cow != 0)
            {
                registerNode(skinned_cow);

                int cow_idle_animation_id       = -1;   // Cow Idle
                int cow_walk_animation_id       = -1;   // Cow Walk

                cow_idle_animation_id = skinned_cow.addAnimation("cow_idle.anim");
                cow_walk_animation_id = skinned_cow.addAnimation("cow_walk.anim");

                // Now define the state transitions 1 - Not Visible 2 - Off Track 3 - On Track.
                setAction(NOT_VISIBLE, new NodeEnable(skinned_cow, 0));
                setAction(OFF_TRACK, new NodeActionSequence((new ObstructionMoveAndAnimate(skinned_cow, cow_walk_animation_id, 45.0, 2.0, 180.0, translate(dvec3(-5.0, 0.0, 0.0)) * rotateZ(180.0)), new NodeActionLoop(new ObstructionNodeAnimate(skinned_cow, cow_idle_animation_id, 15.0)))));
                setAction(ON_TRACK, new NodeActionSequence((new ObstructionMoveAndAnimate(skinned_cow, cow_walk_animation_id, 45.0, 2.0, 180.0, translate(dvec3(0.0, 0.0, 0.0)) * rotateZ(180.0)), new NodeActionLoop(new ObstructionNodeAnimate(skinned_cow, cow_idle_animation_id, 15.0)))));
                m_valid = 1;
            }
            else
            {
                log.error("Unable to load cow obstruction - invalid node file for feature with id %d\n", info.getID());
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

        /// This class allows us to move and animate obstruction (in this case it is cow). This a specific case of
        /// NodeActionComposite since our completion criteria is based on whether
        /// the movement is complete (the animation will never complete since movement
        /// animations are always looping).1

        class ObstructionMoveAndAnimate : NodeAction
        {
        private:
            NodeEnable     m_enable_action;
            NodeMove       m_move_action;
            NodeActionLoop m_animate_action;

        public:

            /// Constructor. Stores the given vector of actions
            /// in an internal Unigine::Vector.
            ///
            /// @param node             The ObjectMeshSkinned object we are animating.
            /// @param animation _id    The identifier of the animation we are applying to this ObjectMeshSkinned object.
            /// @param animation_speed  The animation we are applying to this ObjectMeshSkinned object.
            /// @param move_speed       The speed that we wish to move the Node at. As a guide 2.0 would give you the movement of a fast walk.
            ///                         This will require tuning in the derived class to get it right.
            /// @param turn_speed       The number of degrees per frame that the Node can rotate. Something around 180 looks sensible.
            /// @param target_transform The target transform in world coordinates. The raycaster for this feature will be used to obtain a
            ///                         true target transform.
            ObstructionMoveAndAnimate(ObjectMeshSkinned node, int animation_id, double animation_speed, double move_speed, double turn_speed, dmat4 target_transform)
            {
                m_enable_action  = new NodeEnable(node, 1);
                m_move_action    = new NodeMove(node, move_speed, turn_speed, target_transform);
                m_animate_action = new NodeActionLoop(new ObstructionNodeAnimate(node, animation_id, animation_speed));
            }

            /// Executes this action at the given time.
            ///
            /// @param time  The time at which this action is to be executed.
            void executeImpl(double time)
            {
                m_enable_action.execute(time);
                m_move_action.execute(time);
                m_animate_action.execute(time);

                // The move action will drive the completion of this Action
                if(m_move_action.isCompleted())
                    completed();
            }

            /// Feeds the reset down to constituent NodeAction objects.
            void reset()
            {
                m_enable_action.reset();
                m_move_action.reset();
                m_animate_action.reset();

                m_initialised = 0;
                m_completed   = 0;
            }
        };

        /// This class represents the action to animate the given obstruction node cow (which is
        /// an ObjectMeshSkinned since it needs to be capable of animations).
        class ObstructionNodeAnimate : NodeActionSingle
        {
        private:
            int               m_animation_id;
            int               m_layer;
            int               m_speed;
            double            m_start_time;
        public:
            /// Constructor - intialises all members.
            ///
            /// @param node             The ObjectMeshSkinned object we are animating.
            /// @param animation _id    The identifier of the animation we are applying to this ObjectMeshSkinned object.
            /// @param speed            The speed to be applied to this animation.
            ObstructionNodeAnimate(ObjectMeshSkinned node, int animation_id, int speed)
            {
                __NodeActionSingle__(node);
                m_animation_id      = animation_id;
                m_layer             = 0;    //default layer
                m_speed             = speed;
            }

            /// Executes this node action at the given time. This will modify the state of the Node (thus
            /// changing the animation frame for the primary layer and fixing any blends on secondary
            /// animation layers.
            ///
            /// @param The time to execute this action at.
            void executeImpl(double time)
            {
                m_skinned_node.setAnimation(m_layer, m_animation_id);

                // Figure out the frame of the animation we need for the elapsed time.
                double delta_time  = time - m_start_time;
                double frame       = delta_time * m_speed;

                // As this is zero-based, the maximum frame number is getNumFrames()
                // - 1, BUT we also have to discard the bind pose, so our number
                // of frames is one fewer again (getNumFrames() - 2).
                int MAX_FRAMES = m_skinned_node.getNumFrames(m_layer) - 2;
                frame = clamp(frame, 0.0, double(MAX_FRAMES));
                m_skinned_node.setFrame(m_layer, frame, 1); // Our animation starts at frame 1.
                if(frame == MAX_FRAMES)
                    completed();
            }

            /// This function initialises the start time of the NodeAction and sets up some animation
            /// parameters on the animation Node.
            ///
            /// @param time The time at which this action starts.
            void init(double time)
            {
                m_start_time = time;
                m_skinned_node.setLayer(m_layer, 1, 1.0);
                m_initialised = 1;
            }
        };
    };


    /// Representation of a feature type. Contains the binding between
    /// a feature type name and a factory function to create the associated
    /// feature type (ObstructionCow).
    class ObstructionCowType : FeatureType
    {
    public:

        /// Constructs a feature properties object caching data members based on
        /// Unigine engine config. Note this needs to be the feature type's CLASS
        ///
        /// @return The name of the feature type
        string getName()
        {
            return "ObstructionCow";
        }

        /// Factory function - creates a ObstructionCow using FeatureInfo and Properties.
        ///
        /// @param info Structure containing information about the feature instance
        ///             to be created.
        /// @param properties Configuration information about this feature.
        /// @param parent Parent node
        ///
        /// @return The feature created - ownership is now with the caller.
        Feature createFeature(FeatureInfoExtern info, Properties properties, Node parent)
        {
            return new ObstructionCow(info, properties, parent);
        }
    };
}

#endif