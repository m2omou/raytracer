/*
** xnetwork2.c for rt in /home/delas_j//c/rt
** 
** Made by jimmy delas
** Login   <delas_j@epitech.net>
** 
** Started on  Fri Apr  8 11:53:23 2011 jimmy delas
** Last update Sat Apr  9 17:48:01 2011 jimmy delas
*/

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <errno.h>
#include "network.h"
#include "my_printf.h"

int		xbind(int sockfd, const struct sockaddr *addr,
		      socklen_t addrlen)
{
  int		ret;

  if ((ret = bind(sockfd, addr, addrlen)) < 0)
    {
      my_printf("Can't bind server\n");
      exit(0);
    }
  return (ret);
}

int		xlisten(int sockfd, int backlog)
{
  int		ret;

  if ((ret = listen(sockfd, backlog)) < 0)
    {
      my_printf("Can't listen any client\n");
      exit(0);
    }
  return (ret);
}

int		xfcntl(int fd, int cmd, int arg)
{
  int		ret;

  if ((ret = fcntl(fd, cmd, arg)) < 0)
    {
      my_printf("Can't set flag to fd\n");
      exit(0);
    }
  return (ret);
}

int		xrecv(int sockfd, void *buf, size_t len, int flags)
{
  int		ret;

  if ((ret = recv(sockfd, buf, len, flags)) < 0
      && errno != EWOULDBLOCK)
    {
      my_printf("Can't receive packet\n");
      exit(0);
    }
  return (ret);
}

int		xsend(int sockfd, const void *buf, size_t len, int flags)
{
  int		ret;

  if ((ret = send(sockfd, buf, len, flags)) < 0
      && errno != EWOULDBLOCK)
    {
      my_printf("Can't send packet\n");
      exit(0);
    }
  return (ret);
}
