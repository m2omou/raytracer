/*
** get_missing_data.c for rt in /home/delas_j//c/rt
** 
** Made by jimmy delas
** Login   <delas_j@epitech.net>
** 
** Started on  Sat Jun  4 05:35:58 2011 jimmy delas
** Last update Sat Jun  4 18:41:31 2011 jimmy delas
*/

#include	<signal.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<strings.h>
#include	<errno.h>
#include	"network.h"
#include	"utils.h"
#include	"my_printf.h"
#include	"rt.h"

void		get_tex_data(int sock, t_texture *tex, t_packet *packet)
{
  int		i;
  int		n;
  static int	deb = 0;

  deb++;
  packet->x = 0;
  while ((i = xrecv(sock, packet, sizeof(*packet), 0)) <= 0);
  xsend(sock, packet, sizeof(*packet), 0);
  if (packet->x)
    {
      tex->img.data = PX(malloc((packet->x + 1) * sizeof(*(tex->img.data))));
      i = 0;
      while (i < packet->x * (int)sizeof(*(tex->img.data)))
	{
	  while ((n = xrecv(sock, tex->img.data + i,
			    (packet->x * sizeof(*(tex->img.data))) - i, 0)) <= 0);
	  i += n;
	}
      tex->img.data[packet->x] = 0;
    }
}

void		get_texture(t_client *client)
{
  t_obj		*obj;
  t_packet	packet;
  int		i;

  printf("client: Receiving textures...\n");
  bzero(&packet, sizeof(packet));
  obj = client->scene.objet;
  i = 1;
  while (obj)
    {
      xsend(client->sock, &packet, sizeof(packet), 0);
      get_tex_data(client->sock, &obj->tex.color, &packet);
      xsend(client->sock, &packet, sizeof(packet), 0);
      get_tex_data(client->sock, &obj->tex.transp, &packet);
      xsend(client->sock, &packet, sizeof(packet), 0);
      get_tex_data(client->sock, &obj->tex.bump, &packet);
      printf("client: Object texture %d received\n", i++);
      obj = obj->next;
    }
  printf("client: Textures received...\n");
}

void		get_missing_data(t_client *client)
{
  t_packet	packet;

  bzero(&packet, sizeof(packet));
  packet.y = 1;
  xsend(client->sock, &packet, sizeof(packet), 0);
  while (xrecv(client->sock, &packet, sizeof(packet), 0) <= 0);
  client->screen.img.file_name
    = PX(malloc((packet.x + 1) *
		sizeof(*(client->screen.img.file_name))));
  while (xrecv(client->sock, client->screen.img.file_name,
	       packet.x * sizeof(*(client->screen.img.file_name)), 0) <= 0);
  client->screen.img.file_name[packet.x] = 0;
  get_texture(client);
  printf("client: Scene filename \"%s\"\n", client->screen.img.file_name);
}
