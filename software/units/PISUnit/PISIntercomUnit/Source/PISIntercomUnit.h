/// @file       PISIntercomUnit declaration
///
/// @author     Nand Kumar Sharma
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2020

#ifndef PIS_INTERCOM_UNIT_H_
#define PIS_INTERCOM_UNIT_H_



#include <core_types/SessionData.h>
#include <common/Properties.h>

#include "InputCommsInterface.h"
#include "MessageController.h"
#include "OutputCommsInterface.h"

#include <string>

// This unit is responsible for handling Intercom requests coming into its input via DACU & OHP and comms objects

namespace Intercom
{
    class PISIntercomUnit : public Comms::SessionUnit
    {
    public:
        /// Constructor
        ///
        /// @param gateway                  The comms gateway
        /// @param module_props             The module configuration
        /// @param unit_props               The unit configuration
        /// @param scenario_train_id        The scenario train id

        PISIntercomUnit(Comms::Gateway&                 gateway,
                        const Common::Properties&       module_props,
                        const Common::Properties&       unit_props,
                        const int                       scenario_train_id);

        std::string GetName() const override;
    private:
        std::shared_ptr<InputCommsInterface>            m_intercom_comms_interface;
        std::shared_ptr<MessageController>              m_message_controller;
        std::shared_ptr<OutputCommsInterface>           m_intercom_output;
    };
}

#endif // PIS_INTERCOM_UNIT_H

