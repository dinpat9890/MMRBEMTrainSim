///
/// @file       MotionBaseController.h
///
///             Declares the MotionBaseController class.
///
/// @ingroup    MTM Train Sim
///
/// @author     Andy Cooper
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2013
///

#ifndef MOTIONBASE_CONTROLLER_WRAPPER
#define MOTIONBASE_CONTROLLER_WRAPPER

#include <atomic>
#include "common\Utilities.h"


// Forward declarations for some classes referred to in this interface
namespace Project    { class MotionBaseProperties; }
namespace MotionBase { class Parameters; }


namespace MotionBase
{
    enum class SessionState
    {
        /// Simulator Session not active
        Unknown,
        /// Simulator Session Active - Send nothing, the Motionbase should be at Park position.
        Default,
        /// Simulator Session Active and Paused - Send Simulator Pitch and Roll which should not change.
        Paused,
        /// Simulator session running - Send Simulator Pitch and Roll changes.
        Running
    };
}

/// Encapsulates the MotionBase as an object. The MotionBase can be connected to, disconnected from,
/// and written to using this object.

class MotionBaseController : private Common::Unique
{
// Member functions
public:
    // Virtual deconstructor
    virtual ~MotionBaseController() {};

    virtual void start(const Project::MotionBaseProperties &properties) = 0;
    
    virtual void set_session_state(MotionBase::SessionState state) = 0;
    
    virtual void set_motion_parameters(const MotionBase::Parameters &parameters) = 0;

    virtual void set_apply_motion(bool motion_active) = 0;
};

#endif MOTIONBASE_CONTROLLER_WRAPPER
