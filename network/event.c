/*
** event.c for rt in /home/delas_j//c/rt
** 
** Made by jimmy delas
** Login   <delas_j@epitech.net>
** 
** Started on  Wed May 25 15:53:29 2011 jimmy delas
** Last update Fri Jun  3 21:12:50 2011 jimmy delas
*/

#include	<stdlib.h>
#include	"rt.h"
#include	"network.h"
#include	"slide_show.h"

int		server_key_press(int keycode, t_server *server)
{
  if (keycode == KEY_EXIT)
    {
      printf("server: Exiting\n");
      exit_serv(server);
      exit(EXIT_SUCCESS);
    }
  else if (keycode == LOAD_BMP && server->img_state == IST_FINAL)
    loading_bitmap(server->screen->img, server->screen);
  return (0);
}

int		client_key_press(int keycode, t_client *client)
{
  t_packet	packet;

  if (keycode == KEY_EXIT)
    {
      printf("client: Exiting\n");
      exit_client(client);
      exit(EXIT_SUCCESS);
    }
  else if (keycode == 'r')
    {
      printf("client: Reload request\n");
      packet.data_type = END_DATA;
      xsend(client->sock, &packet, sizeof(packet), 0);
    }
  else if (keycode == LOAD_BMP)
    loading_bitmap(client->screen.img, &client->screen);
  return (0);
}
