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
#include "SMSApplication.h"
#include "common/DataAccess.h"
#include "common/CommonExceptions.h"
#include "ProjectOracleProxy.h"
#include "StudentMarkerUnit.h"
//#include "SMSProperties.h"
#include "oracle_access/OracleProvider.h"



using namespace SMS;
//using namespace std;

namespace
{
    // Sections
    const char * const SMS_SECTION = "Student Response System";

    // Properties
    const char * const TIME_DIFFERENCE = "Time Difference";
    const char * const RESPONSE_HARDWARE_DLL = "Response Hardware DLL";

    template <class ImplInterface, class Impl, class Provider>
    std::function<std::unique_ptr<ImplInterface>(Provider &)> MakeCreator()
    {
        return [](Provider &provider)
        {
            return std::unique_ptr<ImplInterface>(new Impl(provider));
        };
    }
}

/// @Function: SMSApplication
///
/// @Description: constructor
///
/// @param properties 
/// @param data_access 

SMSApplication::SMSApplication(const Common::Properties          &properties,
                            Common::Data::DataAccess &data_access)
                               :Core::HubApplication(properties, data_access),
                               m_properties(properties),
                               m_data_access(&data_access)
{

    int ret = GetLastError();
    const std::string DLL_NAME =/*std::string("..\\") + */properties.GetProperty<std::string>(SMS_SECTION, RESPONSE_HARDWARE_DLL);
    HMODULE hardware_lib = LoadLibrary("ReplyPlusAPIInterface.dll");//LoadLibrary(DLL_NAME.c_str());

    ret = GetLastError();
    if(hardware_lib == NULL)
    {
        throw CommonException(FLSTAMP) << "Unable to load " << DLL_NAME << ". GetLastError() returned " <<
            std::showbase << std::hex << GetLastError() << ".";
    }

    SMS::FACTORY_PROC hardware_factory = (SMS::FACTORY_PROC)GetProcAddress(hardware_lib, "MakeResponseHardware");
    if(hardware_factory == NULL)
    {
        throw CommonException(FLSTAMP) << "Unable to find factory function in " << DLL_NAME << ". GetLastError() returned " <<
            std::showbase << std::hex << GetLastError() << ".";
    }
    /*auto ptr = hardware_factory();
    m_response_hardware.reset(ptr);*/
    ret = GetLastError();
    try
    {
        std::cout << "hardware_factory ptr : " << hardware_factory << std::endl;
        m_response_hardware.reset(hardware_factory());
        ret = GetLastError();
    }
    catch (std::exception &ex)
    {
        std::cout << "Exception : " << ex.what() << std::endl;
    }
    catch(...)
    {
        std::cout << "Unknown Exception : " << std::endl;
    }

    data_access.Register(MakeCreator<ProjectDataAccess::IOracleProxy, ProjectDataAccess::OracleProxyImpl, Common::Data::OracleProvider>());
}

/// @Function: Define
///
/// @Description: Define
///
/// @param session_data 
/// @param replay 
Comms::UnitCreators SMSApplication::DefineSession(Comms::Gateway &gateway)
{
    Comms::UnitCreators ret;

    // Do nothing in replay
    if((!gateway.IsReplay()) || (!gateway.GetSessionData<Core::BaseSessionData>().data.preview))
    {
        const auto session_id = gateway.GetSessionData<Core::BaseSessionData>().data.session_id;

        Trace::g_plog->STAMP(Trace::INFO) << " Session ID : "  << session_id<< Trace::EndLog();
        ret.push_back([&, session_id] { return std::shared_ptr<Comms::Unit>(new StudentMarkerUnit(m_properties, GetGateway(), *m_response_hardware, m_data_access)); });
    }

    return ret;
}


SMSApplication::~SMSApplication()
{
    /*DataAccess::DataConnection connection = m_data_access->GetConnection();
    
    connection.oracle_conn->Close();*/
}


