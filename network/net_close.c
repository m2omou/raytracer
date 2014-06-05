/*
** net_close.c for rt in /home/delas_j//c/rt
**
** Made by jimmy delas
** Login   <delas_j@epitech.net>
**
** Started on  Fri Apr  8 10:19:10 2011 jimmy delas
** Last update Sat Jun  4 00:41:02 2011 thomas wilgenbus
*/

#include	<strings.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<unistd.h>
#include	"network.h"
#include	"utils.h"
#include	"my_printf.h"
#include	"rt.h"

void		exit_client(t_client *client)
{
  client->packet.data_type = DEATH_REQUEST;
  xsend(client->sock, &client->packet, sizeof(client->packet), 0);
  free(client->screen.img.file_name);
  free(client->line);
  close(client->sock);
  thread_quit(client->scene.thread, &client->screen.img);
  printf("client: Exiting properly\n");
  exit(EXIT_SUCCESS);
}

void		request_client_death(t_server *server)
{
  t_list_client	*tmp;
  t_packet	packet;

  bzero(&packet, sizeof(packet));
  packet.data_type = DEATH_REQUEST;
  tmp = server->lclients;
  while (tmp)
    {
      if (tmp->status != ST_DOWN)
	if (send(tmp->sock, &packet, sizeof(packet), 0) == -1)
	  printf("server: Can't kill, client must be down\n");
      tmp = tmp->next;
    }
}

void		exit_serv(t_server *server)
{
  request_client_death(server);
  if (server->scene->camera)
    destroy_scene(server->scene);
  printf("server: Image drawing success\n");
  close_srv(SRV_KILL, 0, NULL);
}

void		kill_serv(int fd1, t_list_client *fd2, int client_fd)
{
  t_list_client	*tmp;

  if (client_fd)
    {
      close(client_fd);
      printf("\nClient child's server closed properly\n");
    }
  else
    {
      sleep(1);
      close(fd1);
      while (fd2)
	{
	  tmp = fd2;
	  fd2 = fd2->next;
	  if (tmp->status)
	    close(tmp->sock);
	  free(tmp);
	}
      printf("\nServer closed properly\n");
    }
}

void		close_srv(int order1, int order3, t_list_client *order2)
{
  static int	fd1 = 0;
  static t_list_client*fd2 = NULL;
  static int	client_fd = 0;

  if (order1 == SRV_KILL)
    kill_serv(fd1, fd2, client_fd);
  else
    {
      if (order1 > 0)
	fd1 = order1;
      if (order1 > 0)
	fd2 = order2;
      if (order3)
	client_fd = order3;
    }
}
