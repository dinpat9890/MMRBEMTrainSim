//*****************************************************************************
// @file         UnitDLL.cpp
//
//               Implements the DLL interface for this specific Unit DLL.
//
// @ingroup      Platform Passenger Unit
//
//
// @author       Pankaj Chandra
//
// @copyright (C) Copyright:  SYDAC Pty Ltd, 2017
//*****************************************************************************

#include "sim_comms/UnitDLL.h"
#include "sim_comms/System.h"
#include "world_api/PathWatcher.h"
#include "world_api/TrainPathWatcher.h"
#include "world_api/PathFeatureWatcher.h"
#include "core_types/SessionData.h"
#include "sim_comms/Unit.h"
#include "sim_common/Listener.h"
#include "Utility/DLLModel.h"
#include "core_properties/CommonProperties.h"
#include "PlatformPassengersUnit.h"

// == GLOBAL VARIABLES ============================================================================
// Remember the old logger
Trace::BaseLogger *g_old_logger = nullptr;

Common::Properties *g_properties = nullptr;

// == NON-EXPORTED FUNCTIONS ======================================================================

/// This function is called whenever a new process attaches to the DLL. It is responsible for
/// allocating resources for later use by the DLL. It is also responsible for acquiring, or
/// creating, handles to resources shared between processes. It is also responsible for
/// initializing global objects, such as the databases and caches.
void Initialize()
{
    // Register versions
    Common::LocalVersions::Instance().Register<Core::BaseScenarioData>(Core::BaseScenarioData::GetVersion());
	Common::LocalVersions::Instance().Register<Core::BaseSessionData>(Core::BaseSessionData::GetVersion());

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

UNIT_DLL_API Common::Version GetVersion(const char *component)
{
    // Return a default version if we don't know about this component
    if(!Common::LocalVersions::Instance().Exists(component))
        return Common::Version();

    // Return the version that we have registered
    return Common::LocalVersions::Instance().Get(component);
}

UNIT_DLL_API void Configure(Common::Resources &resources, Common::Properties &properties, Trace::BaseLogger &logger)
{
    assert(!g_properties);

    // Switch to use this logger, but remember the original one so that we can replace it at the end
    g_old_logger = &Trace::GetLogger();
    Trace::SetLogger(&logger);

    // Remember our properties and resources
    g_properties = &properties;
}

UNIT_DLL_API Comms::UnitCreators GetModuleUnitCreators(Common::Resources &resources)
{
    return Comms::UnitCreators();
}

UNIT_DLL_API Comms::UnitCreators GetScenarioUnitCreators(Common::Resources &resources, Comms::System system)
{
    return Comms::UnitCreators();
}

// Comments are in the header

UNIT_DLL_API Comms::UnitCreators GetSessionUnitCreators(Common::Resources &resources, Comms::Gateway &gateway)
{
    Comms::UnitCreators ret;
    if(!gateway.IsReplay())
    {
        // Provide a creator for this unit.
        ret.push_back([&]
        {
            //assert(resources.Exists <Common::Data::DataAccess>());
            assert(resources.Exists<WorldAPI::WorldAccess>());
            
            return std::shared_ptr<Comms::Unit>(new PlatformPassengersUnit(gateway,
                                                                           resources.Get<Common::Data::DataAccess>(),
                                                                           resources.Get<WorldAPI::WorldAccess>(),
                                                                           PlatformPassengerProperties(*g_properties)));
        });
    }

    return ret;
}

UNIT_DLL_API Comms::UnitCreators GetParticipatingUnitCreators(Common::Resources &resources, Comms::Gateway &gateway)
{
    return Comms::UnitCreators();
}
