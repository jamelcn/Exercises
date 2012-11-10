/*-----------------------------------------------------------------------------
 *  Return sock file descriptor
 *-----------------------------------------------------------------------------*/
#include <sys/socket.h>
int socket(int domain, int type, int protocol);
/*-----------------------------------------------------------------------------
 *  Domain:
 *	    AF_INET
 *	    AF_INET6
 *	    AF_UNIX
 *	    AF_UNSPEC
 *
 *  Type:
 *	    SOCK_DGRAM
 *	    SOCK_RAW
 *	    SOCK_SEQPACKET
 *	    SOCK_STREAM
 *
 *  Protocol:
 *	    TCP
 *	    UDP
 *-----------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------
 *  Return 0 if succed, -1 if failed
 *-----------------------------------------------------------------------------*/
#include <sys/socket.h>
int shutdown(int sockfd, int how);
/*-----------------------------------------------------------------------------
 *  How:
 *	SHUT_RD
 *	SHUT_WR
 *	SHUT_RDWR
 *-----------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------
 *  "n" represents "network", "h" represents "host"
 *-----------------------------------------------------------------------------*/
#include <arpa/inet.h>
uint32_t htonl(uint32_t hostint32);
uint16_t htons(uint16_t hostint16);
uint32_t ntol(uint32_t netint32);
uint16_t ntol(uint16_t netint16);


/*-----------------------------------------------------------------------------
 *  Adress Type
 *-----------------------------------------------------------------------------*/
struct sockaddr
{
    sa_family_t sa_family;                      /* address family */
    char	sa_data[];                      /* variable-length address */
    // ...
};


/*-----------------------------------------------------------------------------
 *  Linux version
 *-----------------------------------------------------------------------------*/
struct sockaddr {
	sa_family_t sa_family;                  /* address family */
	char	    sa_data[14];                 /* variable-length address */
};

/*-----------------------------------------------------------------------------
 *  FreeBSD version
 *-----------------------------------------------------------------------------*/
struct sockaddr {
	unsigned char sa_len;                   /* total lenghth */
	sa_family_t sa_family;                  /* address family */
	char	    sa_data[14];                 /* variable-length address */
};


/*-----------------------------------------------------------------------------
 *  IPV4 Internet domain
 *-----------------------------------------------------------------------------*/
struct in_addr
{
    in_addr_t	s_addr;                         /* IPV4 address, defined with uint32_t */
};

struct sockaddr_in
{
    sa_family_t	    sin_family;                 /* address family */
    in_port_t	    sin_port;                   /* port number, defined with uint16_t */
    struct in_addr  sin_addr                    /* IPV4 address */
};

/*-----------------------------------------------------------------------------
 *  Linux version
 *-----------------------------------------------------------------------------*/
struct sockaddr_in {
	sa_family_t	sa_family;              /* address family */
	in_port_t	sin_port;               /* port number */
	struct in_addr	sin_addr;               /* IPV4 address */
	unsigned char	sin_zero[8];            /* filler */
};

/*-----------------------------------------------------------------------------
 *  IPV6 Inetrnet domain
 *-----------------------------------------------------------------------------*/
struct in6_addr
{
   uint8_t s6_addr[16];                         /* IPV6 address */
};

struct sockaddr_in6
{
    sa_family_t sin6_family;                    /* address family */
    in_port_t	sin6_port;                      /* port number */
    uint32_t	sin6_flowinfo;                  /* traffic class and flow info */
    struct in6_addr sin6_addr;                  /* IPV6 address */
    uint32_t	sin6_scope_id;                  /* set of interfaces for scope */
}


/*-----------------------------------------------------------------------------
 *  Net Address Translator
 *-----------------------------------------------------------------------------*/
#include <arpa/inet.h>
const char* inet_ntop(int domain, const void* restrict addr,
	char* restrict str, socklen_t size);
                                                /* return value: return address string pointer if succed, failed return NULL */

int inet_pton(int domain, const char* restrict str,
	void* restrict addr);
                                                /* return value: return 1 if succed, return 0 if invalid format, return -1 if error occured */


/*-----------------------------------------------------------------------------
 *  Query Address
 *-----------------------------------------------------------------------------*/
#include <netdb.h>
struct hostent* gethostent(void);               /* return value: return pointer if succed, else return NULL */

void sethostent(int stayopen);
void endhostent(void);


/*-----------------------------------------------------------------------------
 *  Struct hostent, using Net bytes sequence
 *-----------------------------------------------------------------------------*/
struct hostent {
	char	    *h_name;                    /* name of host */
	char	    **h_aliases;                /* pointer to alternative host name array */
	int	    h_addrtype;                 /* address type */
	int	    h_length;                   /* length in bytes of address */
	char	    **h_addr_list;              /* pointer to array of network address */
};


/*-----------------------------------------------------------------------------
 *  Get Network name and Network No.
 *-----------------------------------------------------------------------------*/
#include <netdb.h>
struct netent* getnetbyaddr(uint32_t net, int type);
struct netent* getnetbyname(const char* name);
struct netent* getnetent(void);
	    /* These three functions' return value: return pointe if succed, else return NULL */

void setnetent(int stayopen);
void endnetent(void);

/*-----------------------------------------------------------------------------
 *  Struct netent, using Net bytes sequence
 *-----------------------------------------------------------------------------*/
struct netent {
	char	    *n_name;                        /* network name */
	char	    **n_aliases;                    /* alternative network name array pointer */
	int	    n_addrtype;                     /* address type */
	uint32_t    n_net;			    /* network number */
	// ...
} ;


/*-----------------------------------------------------------------------------
 *  Get Protocol name and Protocol number
 *-----------------------------------------------------------------------------*/
#include <netdb.h>
struct protoent* getprotobyname(const char* name);
struct protoent* getprotobynumber(int proto);
struct protoent* getprotoent(void);
	    /* These three functions' return value: return pointe if succed, else return NULL */
void setprotoent(int stayopen);
void endprotoent(void);


/*-----------------------------------------------------------------------------
 *  struct protoent, using Net bytes sequence
 *-----------------------------------------------------------------------------*/
struct protoent {
	char	*p_name;                        /* protocol name */
	char	**p_aliases;                    /* pointer to alternative protocol name array */
	int	p_proto;                        /* protocol number */
	// ...
};


/*-----------------------------------------------------------------------------
 *  Get Service number and Service name
 *-----------------------------------------------------------------------------*/
#include <netdb.h>
struct servent* getservbyname(const char* name, const char* proto);
struct servent* getservbyport(int port, const char* proto);
struct servent* getservent(void);
	    /* These three functions' return value: return pointe if succed, else return NULL */

void setservent(int stayopen);
void endservent(void);

/*-----------------------------------------------------------------------------
 *  struct servent, using Net bytes sequence
 *-----------------------------------------------------------------------------*/
struct servent {
	char	    *s_name;                    /* service name */
	char	    **s_aliases;                /* pointer to alternative service name array */
	int	    s_port;                     /* port number */
	char	    *s_proto;                   /* name of protocol */
	// ...
};


/*-----------------------------------------------------------------------------
 *  Map Host name and Service Name to Address
 *-----------------------------------------------------------------------------*/
#include <sys/socket.h>
#include <netdb.h>
int getaddrinfo(const char* restrict host,
		const char* restrict service,
		const struct addrinfo* restrict hint,
		struct addrinfo **restrict res);
                                                /* return value: return 0 if succed, else return nonzero error code */
void freeaddrinfo(struct addrinfo* ai);

/*-----------------------------------------------------------------------------
 *  struct addrinfo
 *-----------------------------------------------------------------------------*/
struct addrinfo {
        int             ai_flags;               /* customize behavior */
        int             ai_family;              /* address family */
        int             ai_socktype;            /* socket type */
        int             ai_protocol;            /* protocol */
	socklen_t	ai_addrlen;             /* length in bytes of address */
	struct sockaddr	*ai_addr;               /* address */
	char		*ai_canonname;          /* canonical name of host */
	struct addrinfo	*ai_next;               /* next in list */
};

/*-----------------------------------------------------------------------------
 *  ai_flags:
 *		AI_ADDRCONFIG
 *		AI_ALL
 *		AI_CANONNAME
 *		AI_NUMERICHOST
 *		AI_NUMERICSERV
 *		AI_PASSIVE
 *		AI_V4MAPPED
 *-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
 *  Deal with getaddrinfo's error code
 *-----------------------------------------------------------------------------*/
#include <netdb.h>
const char* gai_strerror(int error);

/*-----------------------------------------------------------------------------
 *  Map Address to Host and Name
 *-----------------------------------------------------------------------------*/
#include <sys/socket.h>
#include <netdb.h>
int getnameinfo(const struct sockaddr* restrict addr,
		socklen_t alen, char* restrict host,
		socklen_t hostlen, char* restrict service,
		socklen_t servlen, unsigned int flags);
                                                /* return value: return 0 if succed, else return nonzero error code */

/*-----------------------------------------------------------------------------
 *  getnameinfo's flag:
 *			NI_DGRAM
 *			NI_NAMEREQD
 *			NI_NOFQDN
 *			NI_NUMERICHOST
 *			NI_NUMERICSERV
 *-----------------------------------------------------------------------------*/
