///******************************************************************************
///
/// @File: SMSApplication.cpp
///
/// @Description: This application records time stamps captured by 
///               observer/trainee/instructor who want to refer that event later.
/// @Reference:
///
/// @Author: Dheeraj Jha
///
/// @ Copyright: SYDAC Pty Ltd, 2015
///
///******************************************************************************

#pragma once
#ifndef SMS_APPLICATION_H
#define SMS_APPLICATION_H

#include "core_types/SessionData.h"
//#include "CoreUnits/CoreUnitProperties.h"
//#include "SMSProperties.h"
#include "Utility/SelectiveModule.h"
#include "world_api/WorldAccess.h"
#include "ProjectOracleProxy.h"

#include "../ReplyPlusAPIInterface/ReplyPlusAPIInterface.h"

#include <Windows.h>
#include <memory>

namespace SMS
{
    class SMSApplication : public Core::HubApplication
    {
    public:

        SMSApplication(const Common::Properties &properties,
            Common::Data::DataAccess &data_access);
        ~SMSApplication();

    protected:
        Comms::UnitCreators DefineSession(Comms::Gateway &gateway) override;

    private:

        const Common::Properties &m_properties;
        std::unique_ptr<SMS::Hardware> m_response_hardware;
        Common::Data::DataAccess *m_data_access;
    };
}
#endif
