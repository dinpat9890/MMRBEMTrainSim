///******************************************************************************
///
/// @File: StudentMarkerUnit.cpp
///
/// @Description: This unit records time stamps captured by 
///               observer/trainee/instructor who want to refer that event later.
/// @Reference:
///
/// @Author     : Dheeraj Jha
/// @Modified By: Pradeep Prajapati
///
/// @ Copyright: SYDAC Pty Ltd, 2015
///
///******************************************************************************

#include "StudentMarkerUnit.h"
#include "Utility/Utilities.h"
//#include "Project/ObjectConstants.h"
//#include "Project/ObjectDefinition.h"
//#include "SydacCommon/StandardLogging.h"
#include "ProjectOracleProxy.h"

#include <algorithm>
#include <functional>
#include "ProjectOracleProxy.h"

using namespace SMS;
using namespace std;
//using namespace std::tr1;


namespace
{
    // Sections
    const char * const SMS_SECTION = "Student Response System";

    // Properties
    const char * const TIME_DIFFERENCE = "Time Difference";


    // You could also take an existing vector as a parameter.
    vector<string> split(string str, char delimiter) {
        vector<string> internal;
        stringstream ss(str); // Turn the string into a stream.
        string tok;

        while (getline(ss, tok, delimiter)) {
            internal.push_back(tok);
        }

        return internal;
    }
}
/// @Function: StudentMarkerUnit
///
/// @Description: constructor
///
/// @param gateway 
/// @param response_hardware 
/// @param project_data_access 
/// @param scenario_id
/// @param time_diff - time diff between two responses

StudentMarkerUnit::StudentMarkerUnit(const Common::Properties     &properties,
                                     Comms::Gateway         &gateway,
                                     Hardware &response_hardware,
                                     Common::Data::DataAccess *data_access)
                                     : Comms::SteppingUnit(gateway),
                                     m_response_hardware(response_hardware),
                                     m_pproject_session_access(new ProjectDataAccess::ProjectSessionAccess(*data_access)),
                                     m_session_id(gateway.GetSessionData<Core::BaseSessionData>().data.session_id),
                                     m_is_inserted(false),
                                     m_old_time(0),
                                     m_time_diff_between_two_response(properties.GetProperty<int>(SMS_SECTION, TIME_DIFFERENCE, 60))
{
    // This will notify us for every student that is already logged in, which is why
    // I'm calling this under the Comms lock. If you have a peek at the ResponseReceived()
    // callback, it requires the Comms lock - calling from here should mean this thread
    // already *has* the lock and doesn't need to excessively lock and unlock.
    // In theory, at least.
    m_response_hardware.AttachObserver(this);
}


/// @Function: StudentMarkerUnit
///
/// @Description: distructor
///

StudentMarkerUnit::~StudentMarkerUnit()
{
    // It's pretty critical that we detach ourselves before proceeding any further in the destructor.
    // The reason is that another thread may be in this object's callbacks, messing around with our
    // insides. As both this function and the callbacks are mutexed, this call will effectively block
    // until that kind of operation is complete.
    m_response_hardware.Disconnect();
    m_response_hardware.DetachObserver(this);
}

/// @Function: GetName
///
/// @Description:
/// @param

std::string StudentMarkerUnit::GetName() const
{
    return "SMS Student Marker";
}

/// When asked to save this adds a frame to close of the existing one and then the SimData object is
/// used to save the file. It is then copied to the server if we have a separate server path.
///
/// @param tag An optional tag to use to help identify the save. Not used here.his.

void StudentMarkerUnit::Save(OS::UniqueIdentifier tag)
{
    // Acquire the mutex, to stop any updates while we are saving, and perform the save. We can't
    // hold the mutex the whole time though, because there may still be some late updates coming,
    // and particularly object destructions. If we keep the comms mutex we will lock up the comms
    // thread, and stop watchdogging, as saving can take quite some time.
    // So, we instead use a flag to say that we have started saving. No inputs will be accepted
    // after this, which seems fair ... we may have missed some updates anyway, so if we were to
    // continue to accept inputs afterwards our saved data would be incorrect anyway.
    const OS::SectionLock LOCK(m_lock);
    m_is_inserted = true;
    Trace::g_plog->STAMP(Trace::INFO) << "StudentMarkerUnit::Save :  Going to write in DB. Number of entries = " << m_time_stamp.size() << Trace::EndLog();
    for(auto itr = m_time_stamp.begin(); itr != m_time_stamp.end(); ++itr)
    {
        m_pproject_session_access->InsertTimeStamp(m_session_id, itr->first, itr->second);
    }
}

/// Callback on device error
/// @param base_serial device serial code
/// @param error error description

void StudentMarkerUnit::PlusBaseOnError( const char* base_serial, const char* error )
{
    Trace::g_plog->STAMP(Trace::INFO) << "base_serial : " << base_serial << " info "<<error<< Trace::EndLog();
}

/// Periodically called function
///

void StudentMarkerUnit::Step(double new_time)
{
    if(m_response_hardware.Connected())
    {
        while(m_response_hardware.NumberOfKeypadVotes() > 0)
        {
            const char *response = m_response_hardware.GetNextKeypadVote();

            string str = response;
            vector<string> response_array = split(str,'|');
            Trace::g_plog->STAMP(Trace::INFO) << "Response from device :" << response_array[1] << Trace::EndLog();
            if(((m_old_time == 0) || (new_time > (m_old_time + m_time_diff_between_two_response))) && response_array[1] != "")
            {
                Trace::g_plog->STAMP(Trace::INFO) << "New Marker received at : "  << new_time << "   device id :" << response_array[1] << Trace::EndLog();
                string marker_msg = "'Marker received from device : ";
                marker_msg += response_array[1] + "'";
                m_time_stamp.push_back(pair<double,string>(new_time, marker_msg)); //response_array[1]));
                m_old_time = new_time;
            }
        }
    }
    else
    {
        // GetAvailableBases - A method used to detect bases connected via USB.
        // A boolean parameter tells whether or not to include the name of the 
        // base along with the serial number. 
        // Results are comma "," delimited and the name is separated from the serial number with dash "-".
        // If not device is found the result is "No Device Found".
        std::string bases = m_response_hardware.GetAvailableBases();
        Trace::g_plog->STAMP(Trace::INFO) << " bases : "  << bases<< Trace::EndLog();
        if(bases != "No device found")
        {
            // Connect to the found base/device
            m_response_hardware.Connect(bases.c_str());
        }
    }
}

/// @Function: GetPeriod
///
/// @Description:

double StudentMarkerUnit::GetPeriod() const
{
    return 1;
}

/// Callback for new keypad connect
///
void StudentMarkerUnit::PlusBaseOnKeypadConnect(const char* base_serial, const char* keypad_serial)
{
     Trace::g_plog->STAMP(Trace::INFO) << " Connected new keypad: " << keypad_serial  << Trace::EndLog();

     if(m_response_hardware.Connected())
     {
        m_response_hardware.UnlockKeys("All"); 
        m_response_hardware.AutomateQuestionNumber();
     }
}
