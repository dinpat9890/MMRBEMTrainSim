///
/// @file       ResourceDLL.cpp
///
///             Implements the DLL interface for this specific Resource DLL.
///
/// @ingroup    CoreTrainSim
///
/// @author     Luke Errington
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2015
///

#include "common/ResourceDLL.h"

#include "SpeedLimitTracker.h"

#include "core_properties/CommonProperties.h"
#include "core_types/SessionData.h"
#include "world_api/PointsWatcher.h"

#include <cassert>

// == GLOBAL VARIABLES =============================================================================

Common::Properties *g_properties;

// Remember the old logger
Trace::BaseLogger *g_old_logger = nullptr;

namespace
{
    // The frequency to request our speed limit information at
    const double SPEED_LIMIT_REQUEST_FREQ = 10.0;
}

// == NON-EXPORTED FUNCTIONS =======================================================================

/// This function is called whenever a new process attaches to the DLL. It is responsible for
/// allocating resources for later use by the DLL. It is also responsible for acquiring, or
/// creating, handles to resources shared between processes. It is also responsible for
/// initializing global objects, such as the databases and caches.

void Initialize()
{
    // Register versions
    Common::LocalVersions::Instance().Register<Core::BaseScenarioData>(Core::BaseScenarioData::GetVersion());
}

/// Called when a process is detaching from the DLL. Its task is to release allocated
/// resources, and to close any handles held. If there are still some registered callback
/// function their corresponding threads are terminated.

void Terminate()
{
    // Replace the logger
    Trace::SetLogger(g_old_logger);
}

// == DLL ENTRY POINT ==============================================================================

/// The entry point function for processes loading this DLL. Each time a new process attaches to
/// the DLL we call Initialise() to set up global variables, and similarly, when a process
/// detaches we need to clean these resources up with Terminate().
///
/// @param module          module handle (to get instance resources)
/// @param reason_for_call process or thread attach/detach
/// @param reserved        reserved
///
/// @return return true

BOOL APIENTRY DllMain(HANDLE module, DWORD reason_for_call, LPVOID reserved)
{
    switch(reason_for_call)
    {
        // A new process attaching
        case DLL_PROCESS_ATTACH:
            Initialize();
            break;

        case DLL_THREAD_ATTACH:
        case DLL_THREAD_DETACH:
            break;

        // A registered and initialised process is leaving
        case DLL_PROCESS_DETACH:
            Terminate();
            break;
    }

    return TRUE;
}

// Comments are in the header

RESOURCE_DLL_API Common::Version GetVersion(const char *component)
{
    // Return a default version if we don't know about this component
    if(!Common::LocalVersions::Instance().Exists(component))
        return Common::Version();

    // Return the version that we have registered
    return Common::LocalVersions::Instance().Get(component);
}

// Comments are in the header

RESOURCE_DLL_API void Configure(Common::Resources &resources, Common::Properties &properties, Trace::BaseLogger &logger)
{
    assert(!g_properties);

    // Switch to use this logger, but remember the original one so that we can replace it at the end
    g_old_logger = &Trace::GetLogger();
    Trace::SetLogger(&logger);

    // Remember our properties and resources
    g_properties = &properties;
}

// Comments are in the header

RESOURCE_DLL_API bool CheckDependencies(const Common::Resources &resources)
{
    return resources.Exists<Core::BaseScenarioData>() && resources.Exists<Common::DataAccess>() && resources.Exists<WorldAPI::WorldAccess>() && resources.Exists<WorldAPI::PointsWatcher>();
}

// Comments are in the header

RESOURCE_DLL_API void CreateResources(Common::Resources &resources)
{
    assert(resources.Exists<Comms::Gateway>());
    assert(resources.Exists<Common::DataAccess>());
    assert(resources.Exists<WorldAPI::WorldAccess>());
    assert(resources.Exists<WorldAPI::PointsWatcher>());

    // Prepare for an error in doing this, such as a version mismatch
    try
    {
        // Create the basic resource and add it directly
        Common::AddResource(resources, std::unique_ptr<Train::SpeedLimits::SpeedLimitConfig>(new SpeedLimitTracker(resources.Get<Comms::Gateway>(),
                                                                                                                   resources.Get<Common::DataAccess>(),
                                                                                                                   resources.Get<WorldAPI::WorldAccess>(),
                                                                                                                   resources.Get<WorldAPI::PointsWatcher>(),
                                                                                                                   *g_properties,
                                                                                                                   SPEED_LIMIT_REQUEST_FREQ)));


        // Create the CBTC specific resource and add it directly
        Common::AddResource(resources, std::unique_ptr<SpeedLimitCBTCConfig>(new SpeedLimitTracker(resources.Get<Comms::Gateway>(),
                                                                                                                   resources.Get<Common::DataAccess>(),
                                                                                                                   resources.Get<WorldAPI::WorldAccess>(),
                                                                                                                   resources.Get<WorldAPI::PointsWatcher>(),
                                                                                                                   *g_properties,
                                                                                                                   SPEED_LIMIT_REQUEST_FREQ)));
    }
    catch(std::exception &e)
    {
        Trace::GetLogger().STAMP(Trace::ERR) << "Could not create speed limit tracker resources:\n    " << e.what() << Trace::EndLog();
    }
}

// Comments are in the header
 
RESOURCE_DLL_API void DestroyResources(Common::Resources &resources)
{
    assert(resources.Exists<Train::SpeedLimits::SpeedLimitConfig>());
    assert(resources.Exists<SpeedLimitCBTCConfig>());

    Common::DestroyResource<Train::SpeedLimits::SpeedLimitConfig>(resources);
    Common::DestroyResource<SpeedLimitCBTCConfig>(resources);
}
