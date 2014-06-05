/*
** client_order.c for rt in /home/delas_j//c/rt
** 
** Made by jimmy delas
** Login   <delas_j@epitech.net>
** 
** Started on  Sat Jun  4 02:31:42 2011 jimmy delas
** Last update Sat Jun  4 19:07:46 2011 jimmy delas
*/

#include	<string.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<strings.h>
#include	<errno.h>
#include	"network.h"
#include	"utils.h"
#include	"my_printf.h"
#include	"rt.h"

void		coord_data(t_client *client)
{
  client->packet.line = client->line;
  client->packet.data_type = COLOR_DATA;
  if (client->packet.x >= 0 && client->packet.x < 3)
    {
      memcpy(client->packet.line,
	     thread_line(client->packet.y, &client->screen,
			 &client->scene,
			 client->calc_line[client->packet.x]),
	     client->screen.width * sizeof(*(client->packet.line)));
      xsend(client->sock, &client->packet, sizeof(client->packet), 0);
      xsend(client->sock, client->packet.line,
	    client->screen.width * sizeof(*(client->packet.line)), 0);
      update_screen(&client->screen);
    }
}

void		end_data(t_client *client)
{
  int		i;
  int		n;

  i = 0;
  while (i < client->screen.img.sizeline * client->screen.height
	 * (int)sizeof(*(client->screen.img.data)))
    {
      while ((n = xrecv(client->sock,
			client->screen.img.data
			+ i / sizeof(*(client->screen.img.data)),
			(client->screen.img.sizeline
			 * client->screen.height
			 * sizeof(*(client->screen.img.data))) - i,
			0)) <= 0);
      i += n;
    }
  printf("client: Complete server scene receive\n");
  update_screen(&client->screen);
}
