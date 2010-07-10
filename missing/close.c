/* Ignore ECONNRESET of FreeBSD */
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>

int
ruby_getpeername(int s, struct sockaddr * name,
         socklen_t * namelen)
{
    errno = 0;
    s = getpeername(s, name, namelen);
    if (errno == ECONNRESET) {
	errno = 0;
	s = 0;
    }
    return s;
}

int
ruby_getsockname(int s, struct sockaddr * name,
         socklen_t * namelen)
{
    errno = 0;
    s = getsockname(s, name, namelen);
    if (errno == ECONNRESET) {
	errno = 0;
	s = 0;
    }
    return s;
}

int
ruby_shutdown(int s, int how)
{
    errno = 0;
    s = shutdown(s, how);
    if (errno == ECONNRESET) {
	errno = 0;
	s = 0;
    }
    return s;
}

int
ruby_close(int s)
{
    errno = 0;
    s = close(s);
    if (errno == ECONNRESET) {
	errno = 0;
	s = 0;
    }
    return s;
}
