#include "UDPSocketClientConnection.h"
#include "MotionBaseExceptions.h"
#include "common/LexicalCast.h"
#include "common/StandardLogging.h"
#include "time.h"
#include "WS2tcpip.h"

namespace 
{
    const unsigned int DEFAULT_DEST_PORT            = 1260;
    const unsigned int DEFAULT_LOCAL_PORT           = 1261;
    const unsigned int MAX_BUFFER_SIZE              =  512;
}


void UDPSocketClientConnection::ThrowSocketException(const std::string &info)
{
    ThrowSocketException(info, WSAGetLastError());
}

void UDPSocketClientConnection::ThrowSocketException(const std::string &info, int wsa_error)
{
    Trace::GetLogger().STAMP(Trace::ERR) << info.c_str() << ". WSAError:" << wsa_error << Trace::EndLog();
    throw SocketException(FLSTAMP) << wsa_error << ": " << info;
}

UDPSocketClientConnection::UDPSocketClientConnection(): m_destination_address(""),m_destination_port(DEFAULT_DEST_PORT),m_local_port(DEFAULT_LOCAL_PORT),m_socket(INVALID_SOCKET), m_is_open(false)
{
}

UDPSocketClientConnection::UDPSocketClientConnection(const std::string& destination_address,unsigned short destination_port,unsigned short local_port, double connection_timeout) : m_destination_address(destination_address),m_destination_port(destination_port),m_local_port(local_port), m_is_open(false)
{
    m_socket        = INVALID_SOCKET;

    WSADATA         wsa_startup_data;

    Trace::GetLogger().STAMP(Trace::INFO) << "Initialising Winsock..." << Trace::EndLog();

    if (WSAStartup(MAKEWORD(2,2),&wsa_startup_data) != 0)
        ThrowSocketException("Error initialising Winsock. Error code:",WSAGetLastError());

    Trace::GetLogger().STAMP(Trace::INFO) << "Successfully initialized Winsock..." << Trace::EndLog();
}


UDPSocketClientConnection::~UDPSocketClientConnection(void)
{
    if(IsOpen())
        Close();
}


//Function that binds to the local port and destination host/port
bool UDPSocketClientConnection::Open()
{
    if(IsOpen())
        Close();

    m_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if(m_socket == INVALID_SOCKET)
        ThrowSocketException("Error creating UDP socket. Error code:",WSAGetLastError() );


    sockaddr_in local_addr;
    local_addr.sin_family      = AF_INET;
    local_addr.sin_addr.s_addr = INADDR_ANY;
    local_addr.sin_port        = htons(m_local_port);
    std::string destination_port_str = Common::LexicalCast<std::string>(m_destination_port);

    if(bind(m_socket, reinterpret_cast<sockaddr *>(&local_addr), sizeof(local_addr)) == SOCKET_ERROR)
    {
        const int LAST_ERROR = WSAGetLastError();

        if(shutdown(m_socket, 1) == SOCKET_ERROR || closesocket(m_socket) == SOCKET_ERROR)
            Trace::GetLogger().STAMP(Trace::VERBOSE) << "Error shutting down or closing a new socket we were trying to bind()." << Trace::EndLog();

        ThrowSocketException("Error binding to port:" + destination_port_str, LAST_ERROR);
    }

    sockaddr_in dest_addr;
    memset((char *) &dest_addr, 0, sizeof(dest_addr));

    dest_addr.sin_family      = AF_INET;
    inet_pton(AF_INET, m_destination_address.c_str(), &(dest_addr.sin_addr.s_addr));
    dest_addr.sin_port        = htons(m_destination_port);

    if(dest_addr.sin_addr.s_addr == INADDR_NONE)
    {
        // The 'IP address' might be a hostname, so we need to look up the address.
        // const hostent *const host_info = gethostbyname(m_destination_address.c_str());
        struct addrinfo hints;
        struct addrinfo *result = NULL;

        ZeroMemory(&hints, sizeof(hints));
        hints.ai_family = AF_INET;
        hints.ai_socktype = SOCK_STREAM;

        const int get_addr = getaddrinfo(m_destination_address.c_str(), destination_port_str.c_str(), &hints, &result);
        if(get_addr)
            ThrowSocketException("Looking for its IP address of '" + m_destination_address + "'.");

        // Cast from a sockaddr to a sockaddr_in
        dest_addr.sin_addr = reinterpret_cast<sockaddr_in &>(result->ai_addr).sin_addr;
    }

    int result = connect(m_socket, reinterpret_cast<sockaddr *>(&dest_addr), sizeof(dest_addr));
    if( result == SOCKET_ERROR)
        ThrowSocketException("connecting UDP socket to '" + m_destination_address + ":" + Common::LexicalCast<std::string>(m_destination_port) + "'");

    m_is_open = true;

    Trace::GetLogger().STAMP(Trace::INFO) << "Socket opened on local port '" << m_local_port << "', destination: '" << m_destination_address << ":" << m_destination_port << "'" << Trace::EndLog();

    // enable non blocking mode
    unsigned long enableNonBlocking=1;
    result = ioctlsocket(m_socket,FIONBIO,&enableNonBlocking);
    if(result !=0)
        Trace::GetLogger().STAMP(Trace::ERR) << "setsockopt for SO_KEEPALIVE failed with error:" << WSAGetLastError() << Trace::EndLog();

    return true;
}

bool UDPSocketClientConnection::Close()
{
    if(!IsOpen())
        return true;

    // TODO - in the next two stages, if we get a SOCKET_ERROR, should we exit 
    // this method early and return false?

    if(shutdown(m_socket, SD_BOTH) == SOCKET_ERROR)
        Trace::GetLogger().STAMP(Trace::ERR) << "Failed shutting down socket. Error:" << WSAGetLastError() << Trace::EndLog();

    if(closesocket(m_socket) == SOCKET_ERROR)
        Trace::GetLogger().STAMP(Trace::ERR) << "Failed closing the socket."  << WSAGetLastError() << Trace::EndLog();

    m_is_open       = false;
    m_socket        = INVALID_SOCKET;

    Trace::GetLogger().STAMP(Trace::VERBOSE) << "Socket shutdown and closed." << Trace::EndLog();

    return true;
}

std::string UDPSocketClientConnection::Receive()
{
    if(!IsOpen())
        throw CommonException(FLSTAMP, "Socket has not been opened!");

    char  buffer[MAX_BUFFER_SIZE+1]={'\0'};

    const int bytesRecvd = recv(m_socket, buffer, MAX_BUFFER_SIZE, 0);

    if(bytesRecvd == 0)
    {
        // The socket was closed on us.
        Close();
        ThrowSocketException("Socket closed while recv()ing!");
    }
    else if(bytesRecvd == SOCKET_ERROR)
    {
        const int sockError = WSAGetLastError();

        if( (sockError != WSAETIMEDOUT) && (sockError != WSAEWOULDBLOCK))
        {
            Close();
            ThrowSocketException("Socket error while recv()ing!",sockError);
        }
    }
    
    // null terminate the received buffer
    buffer[bytesRecvd+1] = '\0';

    std::string dataReceived(buffer);
    return dataReceived;
}


bool UDPSocketClientConnection::Send(const std::string& string_to_send)
{
    if(!IsOpen())
        throw CommonException(FLSTAMP, "Socket has not been opened!");


    if(send(m_socket, string_to_send.c_str(), static_cast<int>(string_to_send.size()), 0) == SOCKET_ERROR)
    {
        const int LAST_ERROR = WSAGetLastError();
        Close();
        ThrowSocketException("send()ing", LAST_ERROR);
    }
    return true;
}

bool UDPSocketClientConnection::IsOpen()
{
    return m_is_open;
}