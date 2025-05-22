///******************************************************************************
///
/// @File: StudentMarkerUnit.h
///
/// @Description: This unit records time stamps captured by 
///               observer/trainee/instructor who want to refer that event later.
/// @Reference:
///
/// @Author: Dheeraj Jha
/// @Modified By: Pradeep Prajapati
///
/// @ Copyright: SYDAC Pty Ltd, 2015
///
///******************************************************************************
#pragma once
#ifndef STUDENT_MARKER_UNIT_H
#define STUDENT_MARKER_UNIT_H

#include "sim_comms/Unit.h"
#include "sim_comms/Object.h"
#include "sim_comms/ProcessingInterfaces.h"
#include "sim_common/CallbackPolicies.h"
#include "sim_common/Listener.h"
#include "../ReplyPlusAPIInterface/ReplyPlusAPIInterface.h"
#include "ProjectSessionAccess.h"
#include <map>
#include <vector>

#include "core_properties/CommonProperties.h"
#include "core_types/SessionData.h"



namespace SMS
{
    class StudentMarkerUnit : public Comms::SteppingUnit,
        public Comms::ActiveProcessing,
        public Observer
    {
    public:

        StudentMarkerUnit(const Common::Properties          &properties,
            Comms::Gateway         &gateway,
            Hardware &response_hardware, Common::Data::DataAccess *data_access);
        virtual ~StudentMarkerUnit();

        std::string GetName() const override;
        void PlusBaseOnError( const char* base_serial, const char* error ) override;
        void PlusBaseOnKeypadConnect(const char* base_serial, const char* keypad_serial) override;
        

        void Step(double new_time) override;
        virtual double GetPeriod() const override;

    private:
        void Save(OS::UniqueIdentifier tag) override;
        //void StateChanged(Comms::State new_state) override;

        Hardware &m_response_hardware;

        const int m_session_id;
        const int m_time_diff_between_two_response;

        // lets create an vector to store the timestamp and device id
        // pair<timestamp,deviceid>
        std::vector<std::pair<double,std::string>> m_time_stamp;

        double m_old_time;
        double m_new_time;
        int m_temp;
        bool m_is_inserted;
           // A mutex to protect us from saving while setting data
        OS::CriticalSection m_lock;
        //ResponseHardware::Question m_next_question;
        ProjectDataAccess::ProjectSessionAccess *m_pproject_session_access;
    };
}


#endif