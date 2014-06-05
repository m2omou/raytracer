/*
** cell_transfer.c for rt in /home/delas_j//c/rt
** 
** Made by jimmy delas
** Login   <delas_j@epitech.net>
** 
** Started on  Sat Jun  4 16:20:48 2011 jimmy delas
** Last update Sat Jun  4 18:59:55 2011 jimmy delas
*/

#include	<strings.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"network.h"
#include	"utils.h"
#include	"str_utils.h"

void		get_one_cell(int sock, t_packet *packet,
			     t_cell *tmp)
{
  t_cell	*addr_save;

  addr_save = tmp->next;
  packet->x = 0;
  xsend(sock, packet, sizeof(*packet), 0);
  while (xrecv(sock, tmp, sizeof(*(tmp)), 0) <= 0);
  printf("client: Cell received...\n");
  tmp->next = addr_save;
}

t_cell		*get_cell(int sock, t_packet *packet)
{
  t_cell	*tmp;
  t_cell	*ret;

  if (!(ret = check_packet(packet, sizeof(*ret))))
    return (NULL);
  tmp = ret;
  while (--packet->x > 0)
    {
      tmp->next = xmalloc(sizeof(*(tmp)));
      tmp = tmp->next;
    }
  tmp->next = NULL;
  tmp = ret;
  while (tmp)
    {
      get_one_cell(sock, packet, tmp);
      tmp = tmp->next;
    }
  return (ret);
}

void		send_cell(t_list_client *tmp, t_cell *obj,
			  t_packet *packet)
{
  t_cell	*tmp_obj;

  packet->y = 0;
  while (!packet->y)
    xrecv(tmp->sock, packet, sizeof(*packet), 0);
  packet->x = 0;
  tmp_obj = obj;
  while (tmp_obj)
    {
      packet->x++;
      tmp_obj = tmp_obj->next;
    }
  xsend(tmp->sock, packet, sizeof(*packet), 0);
  tmp_obj = obj;
  while (tmp_obj)
    {
      packet->y = 0;
      while (!packet->y)
      	xrecv(tmp->sock, packet, sizeof(*packet), 0);
      printf("server: Sending cell...\n");
      xsend(tmp->sock, tmp_obj, sizeof(*(tmp_obj)), 0);
      tmp_obj = tmp_obj->next;
    }
}
