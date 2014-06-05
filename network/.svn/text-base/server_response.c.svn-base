/*
** server_response.c for rt in /home/delas_j//c/rt
** 
** Made by jimmy delas
** Login   <delas_j@epitech.net>
** 
** Started on  Wed Jun  1 10:30:24 2011 jimmy delas
** Last update Sat Jun  4 05:23:58 2011 jimmy delas
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<strings.h>
#include	<errno.h>
#include	"network.h"
#include	"utils.h"
#include	"my_printf.h"
#include	"rt.h"

void		send_data(t_list_client *tmp, t_server *server)
{
  t_packet	packet;
  int		i;
  int		n;

  packet.data_type = END_DATA;
  xsend(tmp->sock, &packet, sizeof(packet), 0);
  i = 0;
  while (i < server->screen->img.sizeline
	 * server->screen->height * (int)sizeof(*(server->screen->img.data)))
    {
      while ((n = xsend(tmp->sock,
			(i * sizeof(*(server->screen->img.data)))
			+ server->screen->img.data,
			(server->screen->img.sizeline
			 * server->screen->height
			 * sizeof(*(server->screen->img.data))) - i, 0)) <= 0);
      i += n;
    }
  tmp->img_state = server->img_state;
}

t_value		*add_missing_value(t_value *list, int value, int *status)
{
  t_value	*new;

  new = PX(malloc(sizeof(*new)));
  new->value = value;
  new->next = list;
  *status = ST_DOWN;
  return (new);
}

void		st_occuped(t_list_client *tmp, t_server *server, int *line)
{
  int		n;
  t_packet	packet;

  n = xrecv(tmp->sock, &packet, sizeof(packet), 0);
  packet.line = line;
  if (n > 0)
    {
      tmp->past_time = clock();
      server->client_response[packet.data_type](tmp, server, &packet);
    }
}

void		st_wfstruct(t_list_client *tmp, t_server *server, int *line)
{
  line = line;
  if (!server->missing && server->v.y >= server->screen->height)
    {
      tmp->status = send_scene(tmp, server->scene, server->screen);
      send_data(tmp, server);
    }
  else
    tmp->status = send_scene(tmp, server->scene, server->screen);
  tmp->past_time = clock();
}
