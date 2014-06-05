/*
** loop.c for rt in /home/delas_j//c/rt
** 
** Made by jimmy delas
** Login   <delas_j@epitech.net>
** 
** Started on  Fri Apr  8 10:27:05 2011 jimmy delas
** Last update Sat Jun  4 05:18:19 2011 jimmy delas
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

int		client_loop(t_client *client)
{
  int		n;

  if ((n = xrecv(client->sock, &client->packet,
		 sizeof(client->packet), 0)) > 0)
    client->order[client->packet.data_type](client);
  return (0);
}

t_list_client	*new_client(t_list_client *cur_client)
{
  xfcntl(cur_client->sock, F_SETFL, O_NONBLOCK);
  cur_client->status = ST_WFSTRUCT;
  cur_client->img_state = IST_DRAWING;
  cur_client->next = xmalloc(sizeof(*cur_client));
  cur_client = cur_client->next;
  cur_client->next = NULL;
  cur_client->status = ST_DOWN;
  cur_client->past_time = clock();
  bzero(&cur_client->client_sock, sizeof(cur_client->client_sock));
  printf("server: New client is now connected\n");
  return (cur_client);
}

void		response(t_list_client *tmp, t_server *server)
{
  static int	*line = NULL;
  t_packet	packet;

  if (!line)
    line = xmalloc(server->screen->width * sizeof(*(packet.line)));
  if (tmp->status >= 0)
    server->treat_status[tmp->status](tmp, server, line);
}

int		is_timeout(t_list_client *tmp, t_server *server,
			   t_packet *packet)
{
  if (tmp->status == ST_OCCUPED
      && clock() - tmp->past_time >
      server->screen->timeout * (CLOCKS_PER_SEC / 1000.))
    {
      printf("server: Killing client, connection timeout\n");
      packet->data_type = DEATH_REQUEST;
      if (send(tmp->sock, packet, sizeof(*packet), 0) == -1)
	printf("server: Can't kill, client must be down\n");
      server->missing = add_missing_value(server->missing,
					  tmp->y, &tmp->status);
      return (1);
    }
  return (0);
}

int		server_loop(t_server *server)
{
  t_list_client	*tmp;
  t_packet	packet;

  if ((server->cur_client->sock
       = xaccept(server->sock,
		 (t_sockaddr *)&server->cur_client->client_sock,
		 (socklen_t *)&server->sock_size)) > 0)
    server->cur_client = new_client(server->cur_client);
  tmp = server->lclients;
  while (tmp)
    {
      if (tmp->status != ST_DOWN && !is_timeout(tmp, server, &packet))
	response(tmp, server);
      tmp = tmp->next;
    }
  return (0);
}
