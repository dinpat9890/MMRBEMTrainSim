///
/// @file       SpeedLimitTypes.h
///
///             Declares common speed limit types, and particularly the SpeedLimitType and
///             SpeedLimitConfig interfaces.
///
/// @ingroup    CoreTrainSim
///
/// @author     Luke Errington
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2015
///

#ifndef CORE_SPEED_LIMIT_TYPES_H
#define CORE_SPEED_LIMIT_TYPES_H

// For the use of WorldAPI::SegmentPath in our interfaces
#include "WorldAPI/WorldAccess.h"

#include <memory>
#include <stack>
#include <vector>

namespace Core
{
    namespace SpeedLimits
    {
        /// Represents a single speed limit element, most likely corresponding to a change in limit
        /// speed for a particular speed limit type - often due to the passing of a feature. It also
        /// allows the association of an optional ID, perhaps a feature ID, or limit ID, so that it
        /// can be selectively disabled at a later point in time (by the POP_ID action type).

        struct Element
        {
            /// The speed that this element is limiting the train to
            double speed;

            /// An optional ID to help with removal/cancellation of the limit
            int    id;

            /// Constructor, which just initialises the members
            ///
            /// @param speed_in The speed for the element to correspond to
            /// @param id_in    The ID for the element to have

            Element(double speed_in = 0.0, int id_in = -1)
              : speed(speed_in), id(id_in)
            {
            }
        };

        /// Elements are generally used in a stack, so this typedef makes things a bit briefer ...
        typedef std::stack<Element> Elements;

        /// An action to take on a stack of Elements, thereby most likely modifying the speed limit
        /// required by a particular speed limit type.

        struct Action
        {
            /// An action may push on a new limit, pop off the last, pop off up to and including an
            /// element with a particular ID, or clear all current elements.

            enum class Type
            {
                PUSH,
                POP,
                POP_ID,
                CLEAR
            };

            /// The type of action to take on the element stack
            Type    type;

            /// The data associated with this action - generally the new limit to apply if adding,
            /// or the ID to pop off if popping
            Element data;

            /// Constructor, which just initialises the members. Made explicit to help stop nasty
            /// conversions where a speed was accidentally converted to a type! For a similar reason
            /// this is presented as one constructor, rather than two or three, due to potential
            /// overloading surprises.
            ///
            /// @param type_in  The type of action to take
            /// @param speed_in The speed for the element to correspond to, if pushing
            /// @param id_in    The ID to be removed, if popping

            explicit Action(Type type_in, double speed_in = 0.0, int id_in = -1)
              : type(type_in), data(speed_in, id_in)
            {
            }
        };

        /// Represents a point, or position, at which changes should be made. More accurately, it
        /// reflects a point at which it became clear that changes may be required, although they
        /// may actually apply to a different location on the track. The actions to take may be a
        /// series of actions.

        struct ChangePoint
        {
            /// The manner in which this changes should be applied. They may apply to the location
            /// of the driver (which is generally an immediate speed limit change) or to the
            /// location of the train (in which case the entire train must be in the higher speed
            /// limit, where transitioning, before it is allowed to speed up).

            enum class Application
            {
                DRIVER,
                TRAIN
            } application;

            /// The position at which the actions should be taken
            double              position;

            /// The actions to take on the element stack for a particular type of speed limit
            std::vector<Action> actions;

            /// Constructor, which just initialises the members
            ///
            /// @param position_in    The position for the changes to correspond to
            /// @param application_in The manner in which the position and changes should be applied

            ChangePoint(double position_in, Application application_in = Application::TRAIN)
              : position(position_in), application(application_in)
            {
            }
        };

        /// The base class for an individual type of speed limit, which the SpeedLimitUnit will
        /// likely deal with and extract profile and adjustment information for that type.

        class SpeedLimitType
        {
        public:
            /// Destructor in case the implementation classes' destructors need to be called
            virtual ~SpeedLimitType() {}

            /// Queried to determine what change points are on the path in a given direction of travel, generally
            /// relating to where the speed limits change for this speed limit type.
            ///
            /// Possible to generate a speed for a train travelling in either the forward or reverse direction
            /// - Forward Speed profile : Will report the change points that are ahead of the train. The distance
            ///   to these change points is given relative to the front of the train  
            /// - Reverse Speed profile : Will report the change points that are behind of the train. The distance
            ///   to these change points is given relative to the rear of the train  
            ///
            /// @param path              The current path, where the train is at the origin.
            /// @param scenario_train_id The Scenario Train ID that identifies the train
            ///                          travelling on this path.
            /// @param train_length      Length of the train which is used to find the rear  
            ///                          of the train when creating a reverse profile
            /// @param forward_profile   Flag indicating if the profile is in the forward or 
            //                           reverse direction. True implies forward direction.
            ///
            /// @return The set of points to make changes at, and the changes to make

            virtual std::vector<ChangePoint> GetProfilePoints(const WorldAPI::SegmentPath &path, int scenario_train_id, double train_length, bool forward_profile) = 0;

            /// Queried to determine what changes should be made to the current element stack for
            /// this speed limit type. This generally relates to looking for a previous
            /// mainline speed limit, or clearing a signal's stop state when a signal that had previously
            /// been past by the train is no longer in a stop state.
            ///
            /// @param path              The current path, where the train is at the origin.
            /// @param elements          The current element stack (for the closest change point
            ///                          prior to the train's current location) that may need
            ///                          modification.
            /// @param scenario_train_id The Scenario Train ID that identifies the train
            ///                          travelling on this path.
            /// @param train_length      Length of the train which is used to find the rear  
            ///                          of the train when adjusting a reverse profile
            /// @param forward_profile   Flag indicating if the profile being adjusted is a forward
            ///                          or reverse direction profile. True implies forward direction.
            ///
            /// @return The actions to be taken on the current element stack for this speed limit
            ///         type

            virtual std::vector<Action> GetAdjustments(const WorldAPI::SegmentPath &path, const Elements &elements, int scenario_train_id, double train_length, bool forward_profile) = 0;

            /// Queried to determine if this speed limit type contributes towards the line limit
            ///
            /// @return True if any speed limit restriction imposed by this type should contribute
            ///         to the line limit.

            virtual bool IsLineLimit() const = 0;
        };

        /// Handy helper class which implements the SpeedLimitType interface, but delegates the calls
        /// through to registered std::functions (which likely all call back into some master
        /// class).

        class SpeedLimitTypeDelegator : public SpeedLimitType
        {
        public:
            // Handy typedefs just to simplify the syntax
            typedef std::function<std::vector<ChangePoint> (const WorldAPI::SegmentPath &path, int scenario_train_id, double train_length, bool forward_profile)>                      ProfileFunc;
            typedef std::function<std::vector<Action> (const WorldAPI::SegmentPath &path, const Elements &elements, int scenario_train_id, double train_length, bool forward_profile)> AdjustmentFunc;

        public:
            /// Constructor, which remembers the functions to call when necessary, and whether we
            /// contribute to line limits or not.
            ///
            /// @param profile_func The function to call when determining the profile points
            /// @param adjust_func  The function to call when determining adjustments to the current
            ///                     element stack

            SpeedLimitTypeDelegator(ProfileFunc profile_func, AdjustmentFunc adjust_func, bool line_limit)
              : m_profile_func(profile_func), m_adjust_func(adjust_func), m_line_limit(line_limit)
            {
            }

            /// Queried to determine what change points are on the path in a given direction of travel, generally
            /// relating to where the speed limits change for this speed limit type.
            ///
            /// Possible to generate a speed for a train travelling in either the forward or reverse direction
            /// - Forward Speed profile : Will report the change points that are ahead of the train. The distance
            ///   to these change points is given relative to the front of the train  
            /// - Reverse Speed profile : Will report the change points that are behind of the train. The distance
            ///   to these change points is given relative to the rear of the train  
            ///
            /// @param path              The current path, where the train is at the origin.
            /// @param scenario_train_id The Scenario Train ID that identifies the train
            ///                          travelling on this path.
            /// @param train_length      Length of the train which is used to find the rear  
            ///                          of the train when creating a reverse profile
            /// @param forward_profile   Flag indicating if the profile is in the forward or 
            //                           reverse direction. True implies forward direction.
            ///
            /// @return The set of points to make changes at, and the changes to make

            std::vector<ChangePoint> GetProfilePoints(const WorldAPI::SegmentPath &path, int scenario_train_id, double train_length, bool forward_profile = true) override
            {
                if(m_profile_func)
                    return m_profile_func(path, scenario_train_id, train_length, forward_profile);
                return std::vector<ChangePoint>();
            }

            /// Queried to determine what changes should be made to the current element stack for
            /// this speed limit type. This generally relates to looking for a previous
            /// mainline speed limit, or clearing a signal's stop state when a signal that had previously
            /// been past by the train is no longer in a stop state.
            ///
            /// @param path              The current path, where the train is at the origin.
            /// @param elements          The current element stack (for the closest change point
            ///                          prior to the train's current location) that may need
            ///                          modification.
            /// @param scenario_train_id The Scenario Train ID that identifies the train
            ///                          travelling on this path.
            /// @param train_length      Length of the train which is used to find the rear  
            ///                          of the train when adjusting a reverse profile
            /// @param forward_profile   Flag indicating if the profile being adjusted is a forward
            ///                          or reverse direction profile. True implies forward direction.
            ///                          travelling on this path.
            ///
            /// @return The actions to be taken on the current element stack for this speed limit
            ///         type

            std::vector<Action> GetAdjustments(const WorldAPI::SegmentPath &path, const Elements &elements, int scenario_train_id, double train_length, bool forward_profile) override
            {
                if(m_adjust_func)
                    return m_adjust_func(path, elements, scenario_train_id, train_length, forward_profile);
                return std::vector<Action>();
            }

            /// Queried to determine if this speed limit type contributes towards the line limit.
            /// This just returns the value that the object was initialised with.
            ///
            /// @return True if any speed limit restriction imposed by this type should contribute
            ///         to the line limit.

            bool IsLineLimit() const override
            {
                return m_line_limit;
            }

        private:
            ProfileFunc    m_profile_func;
            AdjustmentFunc m_adjust_func;
            bool           m_line_limit;
        };

        /// The interface that likely will need to be supplied to a SpeedLimitUnit on construction.
        /// It provides a way to create all of the SpeedLimitType interfaces for use.

        class SpeedLimitConfig
        {
        public:
            /// Destructor so that the implementation classes' destructors are called
            virtual ~SpeedLimitConfig() {}

            /// Queried to determine all of the speed limit types that we need to track.
            ///
            /// @return All of the speed limit types as shared pointers to the SpeedLimitType
            ///         interface, which allows us to use them to also determine profile points and
            ///         adjustments for their type.

            virtual std::vector<std::shared_ptr<SpeedLimitType>> GetSpeedLimitTypes() = 0;
        };
    }
}

#endif // CORE_SPEED_LIMIT_TYPES_H
