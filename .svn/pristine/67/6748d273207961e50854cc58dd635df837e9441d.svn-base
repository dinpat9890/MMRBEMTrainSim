///
/// @file       CBTCOnBoardUnit.h
///
///             Main unit of the CBTC Onboard system which controls the systems runcycle.
///
/// @author     Adam Zielinski
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2020
///

#pragma once

#include "CBTCOnBoardProperties.h"
#include "OnBoardController.h"

#include "CommsInterface.h"
#include "sim_comms/ProcessingInterfaces.h"
#include "sim_comms/Unit.h"
#include "utility/Locking.h"

/// This is the main class which controls the execution of the CBTC OnBoard System Controller
/// RunCycle and triggers the reporting of data to the external interfaces
///
class CBTCOnBoardUnit : public Comms::SteppingUnit
{
public:
    CBTCOnBoardUnit(Comms::Gateway& gateway, CBTCOnBoardProperties& properties, int train_id, unsigned long date_time);

    // Unit functionality
    std::string GetName() const override;
    void        Step(double new_time) override;
    double      GetPeriod() const override;

private:
    /// Identifies the train on which the unit is located
    int m_train_id;

    /// Comms Interface
    std::unique_ptr<Project::CBTCOnBoard::CommsInterface> m_external_intefaces;

    /// OnBoard Controller
    std::unique_ptr<Project::CBTCOnBoard::OnBoardController> m_on_board_controller;
};