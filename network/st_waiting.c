/*
** st_waiting.c for rt in /home/delas_j//c/rt
** 
** Made by jimmy delas
** Login   <delas_j@epitech.net>
** 
** Started on  Sat Jun  4 05:23:25 2011 jimmy delas
** Last update Sat Jun  4 19:09:12 2011 jimmy delas
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

int		test_new_state(t_server *server)
{
  if (!server->missing && server->v.y >= server->screen->height
      && server->img_state == IST_DRAWING)
    {
      if (server->scene->cell)
	server->v.y = 0;
      server->img_state = IST_CELL;
      return (1);
    }
  else if (!server->missing && server->v.y >= server->screen->height
	   && server->img_state == IST_CELL)
    {
      anti_alias(&server->screen->img, server->scene, server->screen);
      server->img_state = IST_NOALIAS;
      server->v.y = 0;
      return (1);
    }
  else if (!server->missing && server->v.y >= server->screen->height
	   && server->img_state == IST_NOALIAS)
    {
      server->img_state = IST_FINAL;
      return (1);
    }
  return (0);
}

void		set_next_pixel_to_send(t_server *server, t_list_client *tmp)
{
  t_value	*save;

  if (server->missing)
    {
      save = server->missing;
      tmp->y = server->missing->value;
      server->missing = server->missing->next;
      free(save);
    }
  else
    tmp->y = server->v.y++;
}

void		st_waiting(t_list_client *tmp, t_server *server, int *line)
{
  t_packet	packet;

  bzero(&packet, sizeof(packet));
  if (tmp->img_state == IST_FINAL)
    return ;
  if (test_new_state(server))
    return ;
  if ((tmp->img_state != IST_NOALIAS && server->img_state == IST_NOALIAS)
      || (tmp->img_state != IST_CELL && server->img_state == IST_CELL)
      || (tmp->img_state != IST_FINAL && server->img_state == IST_FINAL))
    {
      send_data(tmp, server);
      return ;
    }
  line = line;
  tmp->status = ST_OCCUPED;
  set_next_pixel_to_send(server, tmp);
  packet.y = tmp->y;
  packet.x = server->img_state;
  packet.data_type = COORD_DATA;
  xsend(tmp->sock, &packet, sizeof(packet), 0);
  update_screen(server->screen);
}
