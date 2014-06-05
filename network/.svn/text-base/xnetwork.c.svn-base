/*
** xnetwork.c for rt in /home/delas_j//c/rt
**
** Made by jimmy delas
** Login   <delas_j@epitech.net>
**
** Started on  Fri Apr  8 11:15:38 2011 jimmy delas
** Last update Sat Jun  4 12:45:55 2011 thomas wilgenbus
*/

#include	<signal.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<strings.h>
#include	<errno.h>
#include	"network.h"
#include	"my_printf.h"

struct hostent	*xgethostbyname(char *ip)
{
  struct hostent*ret;

  if (!(ret = gethostbyname(ip)))
    {
      my_printf("Unable to find host %s\n", ip);
      exit(0);
    }
  return (ret);
}

int		xsocket(int domain, int type, int protocol)
{
  int		ret;

  if ((ret = socket(domain, type, protocol)) < 0)
    {
      my_printf("Can't initialize socket\n");
      exit(0);
    }
  return (ret);
}

int		xconnect(int sockfd, const struct sockaddr *addr,
			 socklen_t addrlen)
{
  int		ret;

  if ((ret = connect(sockfd, addr, addrlen)) < 0)
    {
      my_printf("Can't connect through socket\n");
      exit(0);
    }
  return (ret);
}

void		xsignal(int signum, sighandler_t handler)
{
  if (signal(signum, handler) == SIG_ERR)
    {
      my_printf("Can't set signal %d\n", signum);
      exit(0);
    }
}

int		xfork()
{
  int		ret;

  if ((ret = fork()) < 0)
    {
      my_printf("Unable to fork\n");
      return (0);
    }
  return (ret);
}
