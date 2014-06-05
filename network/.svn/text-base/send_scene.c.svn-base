/*
** send_scene.c for rt in /home/delas_j//c/rt
** 
** Made by jimmy delas
** Login   <delas_j@epitech.net>
** 
** Started on  Sat Jun  4 05:39:22 2011 jimmy delas
** Last update Sat Jun  4 18:38:21 2011 jimmy delas
*/

#include	<strings.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"network.h"
#include	"utils.h"
#include	"str_utils.h"

void		send_move(int sock, t_move *move, t_packet *packet)
{
  t_move	*tmp_move;

  packet->y = 0;
  while (!packet->y)
    xrecv(sock, packet, sizeof(*packet), 0);
  packet->x = 0;
  tmp_move = move;
  while (tmp_move)
    {
      packet->x++;
      tmp_move = tmp_move->next;
    }
  xsend(sock, packet, sizeof(*packet), 0);
  tmp_move = move;
  while (tmp_move)
    {
      packet->y = 0;
      while (!packet->y)
      	xrecv(sock, packet, sizeof(*packet), 0);
      xsend(sock, tmp_move, sizeof(*(tmp_move)), 0);
      tmp_move = tmp_move->next;
    }
}

void		send_object(t_list_client *tmp, t_obj *obj,
			    t_packet *packet, char *type)
{
  t_obj		*tmp_obj;

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
      printf("server: Sending %s...\n", type);
      xsend(tmp->sock, tmp_obj, sizeof(*(tmp_obj)), 0);
      send_move(tmp->sock, tmp_obj->move, packet);
      tmp_obj = tmp_obj->next;
    }
}

void		send_tex_data(int sock, t_texture *tex, t_packet *packet)
{
  int		i;
  int		n;
  static int	deb;

  deb++;
  packet->x = 0;
  if (tex->path)
    packet->x = tex->img.x_size * tex->img.y_size * (tex->img.bpp / 8);
  i = xsend(sock, packet, sizeof(*packet), 0);
  while (xrecv(sock, packet, sizeof(*packet), 0) <= 0);
  if (packet->x)
    {
      i = 0;
      while (i < packet->x * (int)sizeof(*(tex->img.data)))
	{
	  while ((n = xsend(sock, tex->img.data + i,
			    (packet->x * sizeof(*(tex->img.data))) - i, 0)) <= 0);
	  i += n;
	}
    }
}

void		send_texture(int sock, t_obj *obj)
{
  t_packet	packet;
  int		i;

  printf("server: Sending textures...\n");
  i = 1;
  bzero(&packet, sizeof(packet));
  while (obj)
    {
      while (xrecv(sock, &packet, sizeof(packet), 0) <= 0);
      send_tex_data(sock, &obj->tex.color, &packet);
      while (xrecv(sock, &packet, sizeof(packet), 0) <= 0);
      send_tex_data(sock, &obj->tex.transp, &packet);
      while (xrecv(sock, &packet, sizeof(packet), 0) <= 0);
      send_tex_data(sock, &obj->tex.bump, &packet);
      printf("server: Object texture %d done...\n", i++);
      obj = obj->next;
    }
  printf("server: Textures send...\n");
}

int		send_scene(t_list_client *tmp, t_scene *scene, t_screen *screen)
{
  t_packet	packet;

  printf("server: Start sending scene...\n");
  printf("server: dim = [%d;%d]\n", screen->width, screen->height);
  packet.y = 0;
  xsend(tmp->sock, screen, sizeof(*(screen)), 0);
  printf("server: Screen send...\n");
  send_object(tmp, scene->camera, &packet, "camera");
  printf("server: Camera send...\n");
  send_object(tmp, scene->objet, &packet, "object");
  printf("server: Objects send...\n");
  send_object(tmp, scene->light, &packet, "light");
  printf("server: Lights send...\n");
  send_cell(tmp, scene->cell, &packet);
  printf("server: Cells send...\nserver: Sendinf scene... Ok\n");
  packet.y = 0;
  while (!packet.y)
    xrecv(tmp->sock, &packet, sizeof(packet), 0);
  packet.x = my_strlen(screen->img.file_name);
  xsend(tmp->sock, &packet, sizeof(packet), 0);
  xsend(tmp->sock, screen->img.file_name,
	packet.x * sizeof(*(screen->img.file_name)), 0);
  send_texture(tmp->sock, scene->objet);
  return (ST_WAITING);
}
