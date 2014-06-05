/*
** init.c for rt in /home/delas_j//c/rt
** 
** Made by jimmy delas
** Login   <delas_j@epitech.net>
** 
** Started on  Fri Apr  8 10:52:57 2011 jimmy delas
** Last update Sat Jun  4 19:13:39 2011 jimmy delas
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

void		init_draw(t_client *client)
{
  client->order[0] = exit_client;
  client->order[1] = coord_data;
  client->order[2] = end_data;
  client->calc_line[0] = get_focus_color;
  client->calc_line[1] = cell_pixel;
  client->calc_line[2] = fill_sub_pixel_tab;
  client->scene = get_scene(client->sock, &client->screen);
  link_fct_to_obj(&client->scene);
  client->line = xmalloc((client->screen.width + 1)
			* sizeof(*(client->packet.line)));
  client->screen.img.x_size = client->screen.width;
  client->screen.img.y_size = client->screen.height;
  create_win(&client->screen);
  get_missing_data(client);
  printf("client: Ready to draw\n");
}

int		client_init(char *ip, int port)
{
  t_client	client;
  t_sockaddr_in	host_sock;
  struct hostent*host_info;

  bzero(&host_sock, sizeof(host_sock));
  host_info = xgethostbyname(ip);
  client.sock = xsocket(AF_INET, SOCK_STREAM, 0);
  host_sock.sin_addr = *(struct in_addr*)host_info->h_addr_list[0];
  host_sock.sin_port = htons(port);
  host_sock.sin_family = AF_INET;
  close_srv(0, client.sock, NULL);
  xconnect(client.sock, (t_sockaddr *)&host_sock, sizeof(host_sock));
  printf("client: You're now connect to %s:%d\n", ip, port);
  init_draw(&client);
  xfcntl(client.sock, F_SETFL, O_NONBLOCK);
  mlx_loop_hook(client.screen.mlx, client_loop, &client);
  mlx_expose_hook(client.screen.win, update_screen, &client.screen);
  mlx_key_hook(client.screen.win, client_key_press, &client);
  mlx_loop(client.screen.mlx);
  return (1);
}

void		server_ready(t_server *server)
{
  printf("server: Server launched succefully\n");
  printf("server: Working on port %d\n", PORT);
  server->treat_status[0] = st_wfstruct;
  server->treat_status[1] = st_waiting;
  server->treat_status[2] = st_occuped;
  server->client_response[0] = srv_death_request;
  server->client_response[1] = srv_coord_data;
  server->client_response[2] = srv_end_data;
}

void		launch_serv(t_server *server, t_scene *scene, t_screen *screen)
{
  server->scene = scene;
  server->screen = screen;
  server->sock_size = sizeof(t_sockaddr);
  server->v.y = 0;
  server->cur_client = server->lclients;
  server->missing = NULL;
  server->img_state = IST_DRAWING;
  create_win(server->screen);
  load_texture(server->scene, server->screen);
  mlx_loop_hook(server->screen->mlx, server_loop, server);
  mlx_expose_hook(server->screen->win, update_screen, server->screen);
  mlx_key_hook(server->screen->win, server_key_press, server);
  mlx_loop(server->screen->mlx);
}

int		server_init(t_scene *scene, t_screen *screen, int opt)
{
  int		child;
  t_sockaddr_in	host_sock;
  t_server	server;

  if (!(opt & NOFORK) && !(child = xfork()))
    return (client_init("localhost", PORT));
  server.lclients = xmalloc(sizeof(*(server.lclients)));
  server.lclients->status = ST_DOWN;
  server.lclients->next = NULL;
  bzero(&server.lclients->client_sock, sizeof(server.lclients->client_sock));
  bzero(&host_sock, sizeof(host_sock));
  server.sock = xsocket(AF_INET, SOCK_STREAM, 0);
  host_sock.sin_addr.s_addr = htonl(INADDR_ANY);
  host_sock.sin_family = AF_INET;
  host_sock.sin_port = htons(PORT);
  xbind(server.sock, (t_sockaddr *)&host_sock, sizeof(host_sock));
  xlisten(server.sock, MAX_PENDING_CONNECTION);
  close_srv(server.sock, 0, server.lclients);
  server_ready(&server);
  xfcntl(server.sock, F_SETFL, O_NONBLOCK);
  launch_serv(&server, scene, screen);
  return (1);
}
