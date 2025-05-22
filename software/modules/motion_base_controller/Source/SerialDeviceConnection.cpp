#include "SerialDeviceConnection.h"
#include "common/StandardLogging.h"

namespace {
#define DEFAULT_DEST_PORT                           1260
#define DEFAULT_CONNECTION_TIMEOUT                  10
    const unsigned int MAX_BUFFER_SIZE              =   512;

}

std::string SerialDeviceConnection::GetLastErrorMessage() {
    char message[1024];
    FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, 0, GetLastError(), MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), message, sizeof(message), 0);
    std::string result(message);
    return result;
}



SerialDeviceConnection::SerialDeviceConnection(const std::string& destination_address) : m_destination_address(destination_address),m_com_port_handle(NULL),m_is_open(false)
{
    m_com_port_handle  = com_port_handle = INVALID_HANDLE_VALUE;
}

SerialDeviceConnection::SerialDeviceConnection(): m_destination_address(""),m_com_port_handle(NULL), com_port_handle(NULL),m_is_open(false)
{
}

SerialDeviceConnection::~SerialDeviceConnection(void)
{
}


bool SerialDeviceConnection::Open()
{
    Trace::GetLogger().STAMP(Trace::INFO) << "Opening COM port...." << Trace::EndLog();

    if (m_com_port_handle != INVALID_HANDLE_VALUE)
        CloseHandle(com_port_handle);

    com_port_handle = m_com_port_handle = CreateFile(m_destination_address.c_str(), GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, 0, 0);
    if (m_com_port_handle == INVALID_HANDLE_VALUE)
    {
        Trace::GetLogger().STAMP(Trace::ERR) << "CreateFile failed: Error opening COM Port: " << m_destination_address.c_str() << " : " << GetLastErrorMessage() << Trace::EndLog();
        return false;
    }

    DCB dcb;
    SecureZeroMemory(&dcb, sizeof(DCB));
    dcb.DCBlength = sizeof(DCB);
    if (!GetCommState(m_com_port_handle, &dcb)) {
        Trace::GetLogger().STAMP(Trace::ERR) << "GetCommState failed: " << GetLastErrorMessage() << Trace::EndLog();
        return false;
    }

    dcb.BaudRate = 250000;
    dcb.ByteSize = 8;
    dcb.Parity = NOPARITY;
    dcb.StopBits = ONESTOPBIT;
    if (!SetCommState(m_com_port_handle, &dcb)) {
        Trace::GetLogger().STAMP(Trace::ERR) << "SetCommState failed: " << GetLastErrorMessage() << Trace::EndLog();
    }

    COMMTIMEOUTS timeouts;
    timeouts.ReadIntervalTimeout = MAXDWORD;
    timeouts.ReadTotalTimeoutConstant = 1;
    timeouts.ReadTotalTimeoutMultiplier = MAXDWORD;
    timeouts.WriteTotalTimeoutConstant = 1;
    timeouts.WriteTotalTimeoutMultiplier = 1;

    if (!SetCommTimeouts(m_com_port_handle, &timeouts)) {
        Trace::GetLogger().STAMP(Trace::ERR) << "SetCommTimeouts failed: " << GetLastErrorMessage() << Trace::EndLog();
    }

    Trace::GetLogger().STAMP(Trace::INFO) << "Port reopened" << Trace::EndLog();

    m_is_open = true;

    return m_is_open;
}

bool SerialDeviceConnection::Close()
{
    if (m_com_port_handle != INVALID_HANDLE_VALUE)
    {
        if (!CloseHandle(m_com_port_handle))
            Trace::GetLogger().STAMP(Trace::ERR) << "Failed to close COM port" << Trace::EndLog();
    }

    m_is_open       = false;

    m_com_port_handle  = com_port_handle = INVALID_HANDLE_VALUE;

    Trace::GetLogger().STAMP(Trace::VERBOSE) << "COM port closed." << Trace::EndLog();

    return false;
}


bool SerialDeviceConnection::Send(const std::string& string_to_send)
{

    if (! string_to_send.empty()) {
        size_t writte = 0;
        size_t to_write = string_to_send.size (); //string_data.size();
        DWORD bytes_written = 0;
        WriteFile(m_com_port_handle, string_to_send.c_str (), to_write, &bytes_written, 0);
        if (bytes_written < 1) {
            Trace::GetLogger().STAMP(Trace::ERR) << "Error writing string to file." << GetLastError() << Trace::EndLog();
            CloseHandle (m_com_port_handle);
            return false;
        }
    }

    return true;
}



std::string SerialDeviceConnection::Receive()
{
    char data [1024]= {'\0'};

    DWORD bytes_read = 0;

    ReadFile (com_port_handle, & data, sizeof (data) - 4, & bytes_read, 0);
    if (bytes_read > 0 && bytes_read < sizeof (data)) {
        data [bytes_read] = '\0';
    }

    std::string dataReceived(data);

    return dataReceived;
}



bool SerialDeviceConnection::IsOpen()
{
    return m_is_open;
}