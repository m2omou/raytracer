/*
** scene_transfer.c for rt in /home/delas_j//c/rt/network
** 
** Made by jimmy delas
** Login   <delas_j@epitech.net>
** 
** Started on  Thu Apr 28 09:29:54 2011 jimmy delas
** Last update Sat Jun  4 17:48:56 2011 jimmy delas
*/

#include	<strings.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"network.h"
#include	"utils.h"
#include	"str_utils.h"

void		*check_packet(t_packet *packet, int size)
{
  void		*ret;

  packet->y = 1;
  if (packet->x)
    ret = xmalloc(size);
  else
    ret = NULL;
  return (ret);
}

t_move		*get_move(int sock, t_packet *packet)
{
  t_move	*tmp;
  t_move	*addr_save;
  t_move	*ret;
  int		i;

  if (!(ret = check_packet(packet, sizeof(*ret))))
    return (NULL);
  tmp = ret;
  i = packet->x;
  while (--packet->x > 0)
    {
      tmp->next = xmalloc(sizeof(*(tmp)));
      tmp = tmp->next;
    }
  tmp->next = NULL;
  tmp = ret;
  while (tmp)
    {
      addr_save = tmp->next;
      xsend(sock, packet, sizeof(*packet), 0);
      while (xrecv(sock, tmp, sizeof(*(tmp)), 0) <= 0);
      tmp->next = addr_save;
      tmp = tmp->next;
    }
  return (ret);
}

void		get_one_client(int sock, t_packet *packet,
				t_obj *tmp, char *type)
{
  t_obj		*addr_save;

  addr_save = tmp->next;
  tmp->type = -10;
  xsend(sock, packet, sizeof(*packet), 0);
  while (tmp->type < -9)
    xrecv(sock, tmp, sizeof(*(tmp)), 0);
  xsend(sock, packet, sizeof(*packet), 0);
  xrecv(sock, packet, sizeof(*packet), 0);
  tmp->move = get_move(sock, packet);
  printf("client: %s received...\n", type);
  tmp->next = addr_save;
}

t_obj		*get_obj(int sock, t_packet *packet, char *type)
{
  t_obj		*tmp;
  t_obj		*ret;

  xsend(sock, packet, sizeof(*packet), 0);
  xrecv(sock, packet, sizeof(*packet), 0);
  printf("client: Waiting for %d %s...\n", packet->x, type);
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
      get_one_client(sock, packet, tmp, type);
      tmp = tmp->next;
    }
  return (ret);
}

t_scene		get_scene(int sock, t_screen *screen)
{
  t_packet	packet;
  t_scene	scene;

  bzero(&packet, sizeof(packet));
  bzero(&scene, sizeof(scene));
  packet.y = 1;
  printf("client: Start receive scene...\nclient: Waiting for screen data\n");
  xrecv(sock, screen, sizeof(*screen), 0);
  printf("client: Screen data received...\nclient: Waiting for camera...\n");
  scene.camera = get_obj(sock, &packet, "Camera");
  printf("client: Camera received...\n");
  scene.objet = get_obj(sock, &packet, "Object");
  scene.light = get_obj(sock, &packet, "Light");
  xsend(sock, &packet, sizeof(packet), 0);
  xrecv(sock, &packet, sizeof(packet), 0);
  printf("client: Waiting for %d cell...\n", packet.x);
  scene.cell = get_cell(sock, &packet);
  printf("client: Scene received... Ok\n");
  return (scene);
}
