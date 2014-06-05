/*
** xnetwork3.c for rt in /home/delas_j//c/rt
** 
** Made by jimmy delas
** Login   <delas_j@epitech.net>
** 
** Started on  Fri Apr  8 14:08:20 2011 jimmy delas
** Last update Sat Apr  9 17:47:52 2011 jimmy delas
*/

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <errno.h>
#include "network.h"
#include "my_printf.h"

int		xaccept(int sockfd, struct sockaddr *addr, socklen_t *addrlen)
{
  int		ret;

  if ((ret = accept(sockfd, addr, addrlen)) < 0
      && errno != EWOULDBLOCK)
    {
      my_printf("Can't accept client\n");
      exit(0);
    }
  return (ret);
}
