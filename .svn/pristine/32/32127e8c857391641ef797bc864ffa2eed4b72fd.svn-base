/// @file       PISIntercomUnit definition
///
/// @author     Nand Kumar Sharma
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2020

#include <project_comms_structure/ProjectObjectConstants.h>
#include <project_comms_structure/ProjectObjectDefinition.h>
#include <Utility/Utilities.h>

#include "PISIntercomUnit.h"
//#include "PISAudioControllerProxy/AudioControllerProxy.h"

namespace Intercom {

    PISIntercomUnit::PISIntercomUnit(Comms::Gateway&                  gateway,
                                     const Common::Properties&        module_props,
                                     const Common::Properties&        unit_props,
                                     const int                        scenario_train_id)
        : Comms::SessionUnit(gateway)
    {
        m_intercom_output           = std::make_shared<OutputCommsInterface>(gateway);
        m_message_controller        = std::make_shared<PIS::Announcement::MessageController>(gateway, m_intercom_output);
        m_intercom_comms_interface  = std::make_shared<InputCommsInterface>(gateway, module_props, unit_props, scenario_train_id, m_message_controller);
    }

    /// Returns a string holding the name of this unit.

    std::string PISIntercomUnit::GetName() const
    {
        return "PISIntercomUnit";
    }
}