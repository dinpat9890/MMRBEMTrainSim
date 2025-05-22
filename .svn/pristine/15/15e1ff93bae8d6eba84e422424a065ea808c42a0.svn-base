///
/// @file       TrackSideWorkers.us.cpp
///
/// @group      95809A9A
///
/// @author     Craig Biggs
/// @Modified by: Shubham Adgane
///
/// @copyright  SYDAC Pty Ltd, 2022
///
///

#ifndef TRACKSIDEWORKERS_US_CPP
#define TRACKSIDEWORKERS_US_CPP

#include <AnimatedFeature.us.cpp>

namespace Features
{
    /// TrackSideWorkers obstruction feature
    class TrackSideWorkers : AnimatedFeature
    {
    private:
        int m_valid;
        
        enum
        {
            NOT_VISIBLE = 1,
            IDLE_LEFT = 2,
            WORKING = 3,
            IDLE_RIGHT = 4
        };
        
        ObjectMeshSkinned trackworker_a;
        ObjectMeshSkinned trackworker_b;
        ObjectMeshSkinned trackworker_c;

    public:

        /// Constructs a new instance of a TrackSideWorkers feature. The constructor
        /// will define the state to NodeAction transitions required for this feature.
        ///
        /// @param info       Information about the feature. If you have access to
        ///                   it, this is defined externally in
        ///                   Software\Libraries\VisionManager\Source\FeatureInfo.h.
        /// @param properties Generic vision properties.
        /// @param parent     The parent node for the feature.
        TrackSideWorkers(FeatureInfoExtern info, Properties properties, Node parent)
        {
            __AnimatedFeature__(info, properties, parent);
            
            // Attempt to load the each node. If we are successful loading it, register
            // with the AnimatedFeature class and then associate each state with its set of actions.
            Node worker_1    = engine.world.loadNode("trackworker_a.node");
            Node worker_2    = engine.world.loadNode("trackworker_b.node");
            Node worker_3    = engine.world.loadNode("trackworker_c.node");
            trackworker_a = (worker_1 == 0) ? 0 : node_cast(worker_1);
            trackworker_b = (worker_2 == 0) ? 0 : node_cast(worker_2);
            trackworker_c = (worker_3 == 0) ? 0 : node_cast(worker_3);
            
            if(trackworker_a != 0 && trackworker_b != 0 && trackworker_c != 0)
            {
                // Register the children nodes
                registerNode(trackworker_a);
                registerNode(trackworker_b);
                registerNode(trackworker_c);
                
                string trackworker_a_idle_anim  = "trackworker_a_idle.anim";
                string trackworker_b_idle_anim  = "trackworker_b_idle.anim";
                string trackworker_c_idle_anim  = "trackworker_c_idle.anim";
                string trackworker_a_dig_anim   = "trackworker_a_digging.anim";
                string trackworker_a_walk_anim  = "trackworker_a_walk.anim";
                string trackworker_b_walk_anim  = "trackworker_b_walk.anim";
                string trackworker_c_walk_anim  = "trackworker_c_walk.anim";

                string TRACKWORKER_A_HEAD = "MA_cman0323_LOD0_head";
                string TRACKWORKER_A_BODY = "MA_cman0323_LOD0_body";
                string TRACKWORKER_A_SHOVEL = "shovel_shovel";
                string TRACKWORKER_B_HEAD = "trackworker_bman0103_LOD_0_head";
                string TRACKWORKER_B_BODY = "trackworker_bman0103_LOD_0_body";
                string TRACKWORKER_C_HEAD = "MA_cman0104_LOD_0_head";
                string TRACKWORKER_C_BODY = "MA_cman0104_LOD_0_body";

                int trackworker_idle_worker_1_animation_id = -1;    // Worker 1 Idle
                int trackworker_idle_worker_2_animation_id = -1;    // Worker 2 Idle
                int trackworker_idle_worker_3_animation_id = -1;    // Worker 3 Idle
                
                int a_dig_worker_1_animation_id = -1;               // Worker 1 A Dig
                
                int trackworker_walk_worker_1_animaton_id = -1;     // Worker 1 Walk
                int trackworker_walk_worker_2_animaton_id = -1;     // Worker 2 Walk
                int trackworker_walk_worker_3_animaton_id = -1;     // Worker 3 Walk

                trackworker_idle_worker_1_animation_id = trackworker_a.addAnimation(trackworker_a_idle_anim);
                trackworker_idle_worker_2_animation_id = trackworker_b.addAnimation(trackworker_b_idle_anim);
                trackworker_idle_worker_3_animation_id = trackworker_c.addAnimation(trackworker_c_idle_anim);

                a_dig_worker_1_animation_id = trackworker_a.addAnimation(trackworker_a_dig_anim);

                trackworker_walk_worker_1_animaton_id = trackworker_a.addAnimation(trackworker_a_walk_anim);
                trackworker_walk_worker_2_animaton_id = trackworker_b.addAnimation(trackworker_b_walk_anim);
                trackworker_walk_worker_3_animaton_id = trackworker_c.addAnimation(trackworker_c_walk_anim);

                // Left track involves each child walking to the location left of the track and grouped in a circle standing idle talking
                NodeActionParallel worker_left = new NodeActionParallel(());
                worker_left.addAction(new WorkerMoveAndAnimate(trackworker_a, trackworker_walk_worker_1_animaton_id, 48.0, 2.1, 190.0, translate(dvec3(5.0, 0.0, 0.0)) * rotateZ(20.0)));
                worker_left.addAction(new WorkerMoveAndAnimate(trackworker_b, trackworker_walk_worker_2_animaton_id, 37.0, 1.7, 160.0, translate(dvec3(5.0, -1.0, 0.0)) * rotateZ(0.0)));
                worker_left.addAction(new WorkerMoveAndAnimate(trackworker_c, trackworker_walk_worker_3_animaton_id, 45.0, 2.0, 180.0, translate(dvec3(6.0, -1.0, 0.0)) * rotateZ(10.0)));
                
                // On track state involves each child walking onto the track and then standing idle talking on the track facing the train
                NodeActionParallel on_track = new NodeActionParallel(());
                on_track.addAction(new WorkerMoveAndAnimate(trackworker_a, trackworker_walk_worker_1_animaton_id, 48.0, 2.1, 190.0, translate(dvec3(1.0, 1.0, 0.0)) * rotateZ(20.0)));
                on_track.addAction(new WorkerMoveAndAnimate(trackworker_b, trackworker_walk_worker_2_animaton_id, 37.0, 1.7, 160.0, translate(dvec3(-1.0, 1.0, 0.0)) * rotateZ(-135.0)));
                on_track.addAction(new WorkerMoveAndAnimate(trackworker_c, trackworker_walk_worker_3_animaton_id, 45.0, 2.0, 180.0, translate(dvec3(0.8, -0.5, 0.0)) * rotateZ(35.0)));

                // Right track involves each child walking to the location right of the track and grouped in a circle standing idle talking
                NodeActionParallel worker_right = new NodeActionParallel(());
                worker_right.addAction(new WorkerMoveAndAnimate(trackworker_a, trackworker_walk_worker_1_animaton_id, 48.0, 2.1, 190.0, translate(dvec3(-5.0, 0.0, 0.0)) * rotateZ(-20.0)));
                worker_right.addAction(new WorkerMoveAndAnimate(trackworker_b, trackworker_walk_worker_2_animaton_id, 37.0, 1.7, 160.0, translate(dvec3(-5.0, -1.0, 0.0)) * rotateZ(0.0)));
                worker_right.addAction(new WorkerMoveAndAnimate(trackworker_c, trackworker_walk_worker_3_animaton_id, 45.0, 2.0, 180.0, translate(dvec3(-6.0, -1.0, 0.0)) * rotateZ(-10.0)));
                
                // Define the idle talking action for each child which is the action that the child transitions to                
                NodeActionParallel working_action = new NodeActionParallel(());
                working_action.addAction(new NodeActionLoop(new WorkerAnimate(trackworker_a, a_dig_worker_1_animation_id, 15.0)));
                working_action.addAction(new NodeActionLoop(new WorkerAnimate(trackworker_b, trackworker_idle_worker_2_animation_id, 20.0)));
                working_action.addAction(new NodeActionLoop(new WorkerAnimate(trackworker_c, trackworker_idle_worker_3_animation_id, 10.0)));
                 
                // Define the idle talking action for each child which is the action that the child transitions to                
                NodeActionParallel idle_action = new NodeActionParallel(());
                idle_action.addAction(new NodeActionLoop(new WorkerAnimate(trackworker_a, trackworker_idle_worker_1_animation_id, 15.0)));
                idle_action.addAction(new NodeActionLoop(new WorkerAnimate(trackworker_b, trackworker_idle_worker_2_animation_id, 20.0)));
                idle_action.addAction(new NodeActionLoop(new WorkerAnimate(trackworker_c, trackworker_idle_worker_3_animation_id, 10.0)));
                
                // Now define the state transitions 1 - Left Side Of Track 2 - On Track 3 - Right Side Of Track. 
                setAction(NOT_VISIBLE, 
                    new NodeActionSequence((new NodeEnableSurfaces(trackworker_a, (), 1), new NodeEnableSurfaces(trackworker_b, (), 1), new NodeEnableSurfaces(trackworker_c, (), 1))));
                setAction(IDLE_LEFT, 
                    new NodeActionSequence((new NodeEnableSurfaces(trackworker_a, (TRACKWORKER_A_HEAD, TRACKWORKER_A_BODY, TRACKWORKER_A_SHOVEL), 1),
                    new NodeEnableSurfaces(trackworker_b, (TRACKWORKER_B_HEAD, TRACKWORKER_B_BODY), 1),
                    new NodeEnableSurfaces(trackworker_c, (TRACKWORKER_C_HEAD, TRACKWORKER_C_BODY), 1),
                    worker_left, idle_action)));
                setAction(WORKING, new NodeActionSequence((new NodeEnableSurfaces(trackworker_a, (TRACKWORKER_A_HEAD, TRACKWORKER_A_BODY, TRACKWORKER_A_SHOVEL), 1),
                    new NodeEnableSurfaces(trackworker_b, (TRACKWORKER_B_HEAD, TRACKWORKER_B_BODY), 1),
                    new NodeEnableSurfaces(trackworker_c, (TRACKWORKER_C_HEAD, TRACKWORKER_C_BODY), 1), 
                    on_track, working_action)));
                setAction(IDLE_RIGHT, new NodeActionSequence((new NodeEnableSurfaces(trackworker_a, (TRACKWORKER_A_HEAD, TRACKWORKER_A_BODY, TRACKWORKER_A_SHOVEL), 1),
                    new NodeEnableSurfaces(trackworker_b, (TRACKWORKER_B_HEAD, TRACKWORKER_B_BODY), 1),
                    new NodeEnableSurfaces(trackworker_c, (TRACKWORKER_C_HEAD, TRACKWORKER_C_BODY), 1), 
                    worker_right, idle_action)));

                //initialiseProperties(info);
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

         /// This class allows us to move and animate Worker. This a
         /// specific case of NodeActionComposite since our completion criteria is based on
         /// whether the movement is complete (the animation will never complete
         /// since movement animations are always looping).1
         class WorkerMoveAndAnimate : NodeAction {
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
           /// @param target_transform The target transform in world
           /// coordinates. The raycaster for this feature will be used to
           /// obtain a
           ///                         true target transform.
           WorkerMoveAndAnimate(ObjectMeshSkinned node, 
                                int animation_id, 
                                double animation_speed, 
                                double move_speed,
                                double turn_speed,
                                dmat4 target_transform) 
           {
             m_enable_action    = new NodeEnable(node, 1);
             m_move_action      = new NodeMove(node, move_speed, turn_speed, target_transform);
             m_animate_action   = new NodeActionLoop(new WorkerAnimate(node, animation_id, animation_speed));
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
             if (m_move_action.isCompleted())
               completed();
           }

           /// Feeds the reset down to constituent NodeAction objects.
           void reset() 
           {
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
         class WorkerAnimate : NodeActionSingle {
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
           /// @param speed            The speed to be applied to this
           /// animation.
           WorkerAnimate(ObjectMeshSkinned node, 
                             int animation_id,
                             int speed) 
           {
             __NodeActionSingle__(node);
             m_animation_id = animation_id;
             m_layer = 0; // default layer
             m_speed = speed;
           }

           /// Executes this node action at the given time. This will modify the
           /// state of the Node (thus changing the animation frame for the
           /// primary layer and fixing any blends on secondary animation
           /// layers.
           ///
           /// @param The time to execute this action at.
           void executeImpl(double time) 
           {
             m_skinned_node.setAnimation(m_layer, m_animation_id);

             // Figure out the frame of the animation we need for the elapsed
             // time.
             double delta_time = time - m_start_time;
             double frame = delta_time * m_speed;

             // As this is zero-based, the maximum frame number is
             // getNumFrames()
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
    /// feature type (TrackSideWorkers).
    class TrackSideWorkersType : FeatureType
    {
    public:

        /// Constructs a feature properties object caching data members based on
        /// Unigine engine config. Note this needs to be the feature type's CLASS
        ///
        /// @return The name of the feature type
        string getName()
        {
            return "TrackSideWorkers";
        }

        /// Factory function - creates a TrackSideWorkers using FeatureInfo and Properties.
        ///
        /// @param info Structure containing information about the feature instance
        ///             to be created.
        /// @param properties Configuration information about this feature.
        /// @param parent Parent node
        ///
        /// @return The feature created - ownership is now with the caller.
        Feature createFeature(FeatureInfoExtern info, Properties properties, Node parent)
        {
            return new TrackSideWorkers(info, properties, parent);
        }
    };
}

#endif
