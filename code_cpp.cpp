/*
 *thrift/lib/cpp/src/thrift/transport
 *TSocket.h
 */
#ifndef _THRIFT_TRANSPORT_TSOCKET_H_
#define _THRIFT_TRANSPORT_TSOCKET_H_ 1
 
#include <string>

#include <thrift/transport/TTransport.h>
#include <thrift/transport/TVirtualTransport.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/PlatformSocket.h>

#ifdef HAVE_ARPA_INET_H
#include <arpa/inet.h>
#endif
#ifdef HAVE_SYS_TIME_H
#include <sys/time.h>
#endif
#ifdef HAVE_NETDB_H
#include <netdb.h>
#endif

namespace apache { namespace thrift { namespace transport {
	/*
	 *TCP socket implementation of the TTransport interface
	 */
	class TSocket : public TVirtualTransport<TSocket>
	{
	public:
		//construct a new socket.Note that this doer not actually connect the socket
		TSocket();
		//@param host An IP address or hostname to connect to 
		//@param port The port to connect on
		TSocket(std::string host, int port);
		//@param path The UNIX domain socket e.g. "tmp/thrifttest.binary.thrift"
		TSocket(std::string path);
		virtual ~TSocket();
		//@return Is the socket alive
		virtual bool isOpen();
		//calls select on the socket to see if there is more data available
		virtual bool peek();
		//Create and open the UNIX socket
		//@throws TTransportException If the socket could not connect
		virtual void open();
		virtual void close();
		virtual uint32_t read(uint8_t* buf, uint32_t len);
		virtual void write(const unint8_t* buf, uint32_t len);
		uint32_t write_partial(const uint8_t* buf, uint32_t len);
		std::string getHost();
		int getPort();
		void setHost(std::string host);
		void setPort(int port);
		void setLinger(bool on, int linger);
		void setNoDelay(bool noDelay);
		void setConnTimeout(int ms);
		void setRecvTimeout(int ms);
		void setSendTimeout(int ms);
		void setMaxRecvRetries(int maxRecvRetries);
		std::string getSocketInfo();
		std::string getPeerHost();
		std::string getPeerAddress();
		int getPeerPort();
		THRIFT_SOCKET getSocketFD()
		{
			return socket_;
		}
		void setSocketFD(THRIFT_SOCKET fd);
		sockaddr* getCacheAddress(socklen_t* len) const;
		static void setUseLowMinRto(bool useLowMinRto);
		static bool getUseLowMinRto();
		TSocket(THRIFT_SOCKET socket);
		void setCacheAddress(const sockaddr* addr, socklen_t len);
	protected:
		void openConnection(struct addrinfo* res);
		std::string host_;
		std::string peerHost_;
		std::string peerAddress_;
		int peerPort_;
		int port_;
		std::string path_;
		THRIFT_SOCKET socket_;
		int connTimeout_;
		int recvTimeout_;
		bool lingerOn_:
		int lingerVal_;
		bool noDelay_;
		int maxRecvRetries_;
		struct timeval recvTimeval_;
		union
		{
			sockaddr_in ipv4;
			sockaddr_in ipv6;
		} cachedPeerAddr_;
		static bool useLowMinRto_;
	private:
		void unix_open();
		void local_open();
	};

}}} 	//apache::thrift::transport

#endif 	//#ifndef _THRIFT_TRANSPORT_TSOCKET_H_

/*
 *thrift/lib/cpp/src/thrift/transport
 *TSocket.cpp
 */
#include <thrift/thrift-config.h>
#include <cstring>
#include <sstream>
#ifdef HAVE_SYS_SOCKET_H
#include <sys/socket.h>
#endif
#ifdef HAVE_SYS_UN_H
#include <sys/un.h>
#endif
#ifdef HAVE_SYS_POLL_H
#include <sys/poll.h>
#endif
#include <sys/types.h>
#ifdef HAVE_NETINET_IN_H
#include <netinet/in.h>
#include <netinet/tcp.h>
#endif
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif
#include <fcntl.h>

#include <thrift/concurrency/Monitor.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportException.h>
#include <thrift/transport/PlatformSocket.h>

#ifndef SOCKOPT_CAST_T
#	ifndef _WIN32
#		define SOCKOPT_CAST_T void
# 	else
#		define SOCKOPT_CAST_T char 
#	endif 	//_WIN32
#endif

template<class T>
inline const SOCKOPT_CAST_T* const_cast_sockopt(const T* v)
{
	return reinterpret_cast<const SOCKOPT_CAST_T*>(v);
}

template<class T>
inline SOCKOPT_CAST_T* cast_sockopt(T* v)
{
	return reinterpret_cast<SOCKOPT_CAST_T*>(v);
}

namespace apache { namespace thrift { namespace transport {
	using namespace std;
	uint32_t g_socket_syscalls = 0;
	TSocket::TSocket(string host, int port) :
	host_(host),
	port_(port),
	path_(""),
	socket_(THRIFT_INVALID_SOCKET),
	connTimeout_(0),
	sendTimeout_(0),
	recvTimeout_(0),
	lingerOn_(1),
	lingerVal(0),
	noDelay_(1),
	maxRecvRetries_(5)
	{
		recvTimeval_.tv_sec = (int)(recvTimeout_ / 1000);
		recvTimeval_.tv_usec = (int)((recvTimeout_ % 1000) * 1000);
	}

	TSocket::TSocket():
	host_(""),
	port_(0),
	path_(""),
	socket_(THRIFT_INVALID_SOCKET),
	connTimeout_(0),
	sendTimeout_(0),
	recvTimeout_(0),
	lingerOn_(1),
	lingerVal_(0),
	noDelay_(1),
	maxRecvRetries_(5)
	{
		recvTimeval_.tv_sec = (int)(recvTimeout_ / 1000);
		recvTimeval_.tv_usec = (int)((recvTimeout_ % 1000) * 1000);
		cachedPeerAddr_.ipv4.sin_family = AF_UNSPEC;
	}

	TSocket::TSocket(THRIFT_SOCKET socket) :
	host_(""),
	port_(0),
	path_(""),
	socket_(socket),
	connTimeout_(0),
	sendTimeout_(0),
	recvTimeout_(0),
	lingerOn_(1),
	lingerVal_(0),
	noDelay_(1),
	maxRecvRetries_(5)
	{
		recvTimeval_.tv_sec = (int)(recvTimeout_ / 1000);
		recvTimeval_.tv_usec = (int)((recvTimeout_ % 1000) * 1000);
		cachedPeerAddr_.ipv4.sin_family = AF_UNSPEC;
	}

	TSocket::~TSocket()
	{
		close();
	}

	bool TSocket::isOpen()
	{
		return (socket_ != THRIFT_INVALID_SOCKET);
	}
	bool TSocket::peek()
	{
		if ( !isOpen() )
			return false;
		unint8_t buf;
		int r = static_cast<int>(recv(socket_, cast_sockopt(&buf), 1, MSG_PEEK));
		if ( r == -1 )
		{
			int errno_copy = THRIFT_GET_SOCKET_ERROR;
			#if defined __FreeBSD__ || definded __MACH__
			if ( errno_copy == THRIFT_ECONNRESET )
			{
				close();
				return false;
			}
			#endif
			GlobalOutput.perror("TSocket::peek() recv() " + getSocketInfo(), errno_copy);
			throw TTransportException(TTransportException::UNKNOW, "recv()", errno_copy);
		}
		return (r > 0);
	}

    void TSocket::openConnection(struct addrinfo* res)
    {
        if ( isopen() )
            return;
        if ( !path_.empty() )
            socket_ = socket(PF_UNIX, SOCK_STREAM, IPPROTO_IP);
        else
            socket_ = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

        if ( socket_ == THRIFT_INVALID_SOCKET )
        {
            int errno_copy = THRIFT_GET_SOCKET_ERROR;
            GlobalOutput.perror("TSocket::open() socket() " + getSocketInfo(), errno_copy);
            throw TTransportException(TTransportException::NOT_OPEN, "socket()", errno_copy);
        }

        //send timeout
        if ( sendTimeout_ > 0 )
            setSendTimeout(sendTimeout);
        //recv timeout
        if ( recvTimeout_ > 0 )
            setRecvTimeout(recvTimeout);
        //linger
        setLinger(lingerOn_, lingerVal_);
        //no delay
        setNoDelay(noDelay_);
        //uses a low min RTO if asked to 
#ifdef TCP_LOW_MIN_RTO
        if ( getUseLowMinRto() )
        {
            int one = 1;
            setsockopt(socket_, IPRTOTO_TCP, TCP_LOW_MIN_RTO, &one, sizeof(one));
        }
#endif
        //set the socket to be non blocking for connect if a timeout exits
        int flags = THRIFT_FCNTL(socket_, THRIFT_F_GETFL, 0);
        if ( connTimeout_ > 0 )
        {
        	if ( -1 == THRIFT_FCNTL(socket_, THRIFT_F_SETFL, flags | THRIFT_O_NONBLOCK) )
        	{
        		int errno_copy = THRIFT_GET_SOCKET_ERROR;
        		GlobalOutput.perror("TSocket::open() THRIFT_FCNTL " + getSocketInfo(), errno_copy);
        		throw TTransportException(TTransportException::NOT_OPEN, "THRIFT_FCNTL() failed", errno_copy);
        	}
        }

        //connect the socket
        int ret;
        if ( !path_.empty() )
        {
#ifndef _WIN32
            struct sockaddr_un address;
            socklen_t len;

            if ( path_.length() > sizeof(address.sun_path) )
            {
                int errno_copy = THRIFT_GET_SOCKET_ERROR;
                GlobalOutput.perror("TSocket::open() Unix Domain socket path too long", errno_copy);
                throw TTransportException(TTransportException::NOT_OPEN, " Unix Domain socket path too long");
            }

            address.sun_family = AF_UNIX;
            THRIFT_SNPRINTF(address.sun_path, sizeof(address.sun_path), "%s", path_.c_str());
            len = sizeof(address);
            ret = connect(socket_, (struct sockaddr *)&address, len);
#else
            GlobalOutput.perror("TSocket::open() Unix Domain socket path not supported on windows", -99);
            throw TTransportException(TTransportException::NOT_OPEN, " Unix Domain socket path not supported");
#endif
        }
        else
        {
            ret = connect(socket_, res->ai_addr, static_cast<int>(res->ai_addrlen));
        }

        //success case
        if ( ret == 0 )
            goto done;

        if ( (THRIFT_GET_SOCKET_ERROR != THRIFT_EINPROGRESS) && (THRIFT_GET_SOCKET_ERROR != THRIFT_EWOULDBLOCK) )
        {
            int errno_copy = THRIFT_GET_SOCKET_ERROR;
            GlobalOutput.perror("TSocket::open() connect() " + getSocketInfo(), errno_copy);
            throw TTransportException(TTransportException::NOT_OPEN, "connect() failed", errno_copy);
        }

        struct THRIFT_POLLFD fds[1];
        std::memset(fds, 0, sizeof(fds));
        fds[0].fd = socket_;
        fds[0].events = THRIFT_POLLFD;
        ret = THRIFT_POLL(fds, 1, connTimeout_);

        if ( ret > 0 )
        {
            //ensure the socket is connected and that there are no errors set
            int         val;
            socketlen_t lon;
            lon = sizeof(int);
            int ret2 = getsockopt(socket_, SOL_SOCKET, SO_ERROR, cast_sockopt(&val), &lon);
            if ( ret2 == -1 )
            {
                int errno_copy = THRIFT_GET_SOCKET_ERROR;
                GlobalOutput.perror("TSocket::open() getsockopt() " + getSocketInfo(), errno_copy);
                throw TTransportException(TTransportException::NOT_OPEN, "getsockopt()", errno_copy);
            }

            //no errors on socket, go to town
            if ( val == 0 )
                goto done;
            GlobalOutput.perror("TSocket::open() error on socket(after THRIFT_POLL) " + getSocketInfo(), val);
            throw TTransportException(TTransportException::NOT_OPEN, "socket open() error", val);
        }
        else if ( ret == 0 )
        {
            //socket timed out
            string errStr = "TSocket::open() timed out " + getSocketInfo();
            GlobalOutput(errStr.c_str());
            throw TTransportException(TTransportException::NOT_OPEN, "open() timed out");
        }
        else
        {
            //error on THRIFT_POLL()
            int errno_copy = THRIFT_GET_SOCKET_ERROR;
            GlobalOutput.perror("TSocket::open() THRIFT_POLL() " + getSocketInfo(), errno_copy);
            throw TTransportException(TTransportException::NOT_OPEN, "THRIFT_POLL() failed", errno_copy);
        }

done:
        //set socket back to normal mode(blocking)
        THRIFT_FCNTL(socket_, THRIFT_F_SETFL, flags);

        if ( path_.empty() )
            setCachedAddress(res->ai_addr, static_cast<socklen_t>(res->ai_addrlen));
        
        void TSocket::open()
        {
            if ( isopen() )
                return;
            if ( !path_.empty() )
                unix_open();
            else
                local_open();
        }

        void TSocket::unix_open()
        {
            if ( !path_.empty() )
                //unix domain socket does not need addrinfo struct, so we pass null
                openConnection(NULL);
        }
        void TSocket::local_open()
        {
#ifdef _WIN32
            TWinsockSingleton::create();
#endif //_WIN32
            if ( isopen() )
                return;
            
            //validate port number
            if ( port_ < 0 || port_ > 0xFFFF )
                throw TTransportException(TTransportException::NOT_OPEN, "Specified port is invalid");
            struct addrinfo hints, *res, *res0;
            res = NULL;
            res0 = NULL;
            int error;
            char port[sizeof("65536")];
            std::memset(&hints, 0, sizeof(hints));
            hints.ai_family = PF_UNSPEC;
            hints.ai_socktype = SOCK_STREAM;
            hints.ai_flags = AI_PASSIVE | AI_ADDRCONFIG;
            sprintf(port, "%d", port_);

            error = getaddrinfo(host_.c_str(), port, &hints, &res0);

            if ( error )
            {
                string errStr = "TSocket::open() getaddrinfo() " + getSocketInfo() + string(THRIFT_GAI_STRERROR(error));
                GlobalOutput(errStr.c_str());
                close();
                throw TTransportException(TTransportException::NOT_OPEN, "Could not resolve host for client socekt.");
            }

            //cycle through all the returned addresses until one
            //connects or push the exception up
            for ( res = res0; res; res = res->ai_next )
            {
                try
                {
                    openConnection(res);
                    break;
                }
                catch ( TTransportException& )
                {
                    if ( res->ai_next )
                        close();
                    else
                    {
                        close();
                        freeaddrinfo(res0);     //clean up on failure
                        throw;
                    }
                }
            }

            //free address structure memory
            freeaddrinfo(res0);
        }

        //396
    }
}}}
