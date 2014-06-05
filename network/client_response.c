/*
** client_response.c for rt in /home/delas_j//c/rt
** 
** Made by jimmy delas
** Login   <delas_j@epitech.net>
** 
** Started on  Sat Jun  4 05:09:59 2011 jimmy delas
** Last update Sat Jun  4 05:19:50 2011 jimmy delas
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

void		srv_coord_data(t_list_client *tmp, t_server *server,
			       t_packet *packet)
{
  int		i;
  int		n;

  i = 0;
  while (i < server->screen->width * (int)sizeof(*(packet->line)))
    {
      while ((n = xrecv(tmp->sock,
			packet->line + i / sizeof(*(packet->line)),
			(server->screen->width
			 * sizeof(*(packet->line))) - i,
			0)) <= 0);
      i += n;
    }
  n = -1;
  while (++n < server->screen->width)
    my_put_pixel_to_img(&server->screen->img, n, tmp->y, packet->line[n]);
  tmp->status = ST_WAITING;
}

void		srv_death_request(t_list_client *tmp, t_server *server,
				  t_packet *packet)
{
  packet = packet;
  server->missing = add_missing_value(server->missing, tmp->y, &tmp->status);
}

void		srv_end_data(t_list_client *tmp, t_server *server,
			     t_packet *packet)
{
  packet = packet;
  send_data(tmp, server);
}
