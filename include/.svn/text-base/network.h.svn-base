/*
** network.h for rt in /home/delas_j//c/rt
** 
** Made by jimmy delas
** Login   <delas_j@epitech.net>
** 
** Started on  Thu Apr  7 16:47:31 2011 jimmy delas
** Last update Sat Jun  4 19:02:37 2011 jimmy delas
*/

#ifndef _NETWORK_H_
#define	_NETWORK_H_

#include	<sys/types.h>
#include	<sys/socket.h>
#include	<netdb.h>
#include	<fcntl.h>
#include	"struct.h"

#define		PORT 41337
#define		MAX_PENDING_CONNECTION 10

#define		SRV_KILL -1

#define		ST_DOWN -1
#define		ST_WAITING 1
#define		ST_OCCUPED 2
#define		ST_WFSTRUCT 0

#define		IST_DRAWING 0
#define		IST_CELL 1
#define		IST_NOALIAS 2
#define		IST_FINAL 3

typedef struct sockaddr t_sockaddr;
typedef struct sockaddr_in t_sockaddr_in;

#define		COLOR_DATA 1
#define		COORD_DATA 1
#define		WAIT_SCENE_DATA 3
#define		END_DATA 2
#define		DEATH_REQUEST 0

typedef struct	s_value
{
  int		value;
  struct s_value*next;
}		t_value;

typedef struct	s_list_client
{
  int		status;
  int		sock;
  t_sockaddr_in	client_sock;
  int		x;
  int		y;
  int		img_state;
  clock_t	past_time;
  struct s_list_client*next;
}		t_list_client;

typedef struct	s_packet
{
  int		data_type;
  int		x;
  int		y;
  int		*line;
}		t_packet;

typedef struct	s_server
{
  t_list_client *lclients;
  t_list_client	*cur_client;
  int		sock;
  t_scene	*scene;
  t_screen	*screen;
  t_vect	v;
  int		sock_size;
  t_value	*missing;
  int		img_state;
  void		(*treat_status[3])(t_list_client *, struct s_server *, int *);
  void		(*client_response[3])(t_list_client *,
				      struct s_server *, t_packet *);
}		t_server;

typedef struct	s_client
{
  t_packet	packet;
  t_screen	screen;
  int		sock;
  int		*line;
  t_scene	scene;
  void		(*order[3])(struct s_client *);
  int		(*calc_line[3])(t_screen *, t_scene *, double, double);
}		t_client;

/*
**		client_response.c
*/
void		srv_coord_data(t_list_client *tmp, t_server *server,
			       t_packet *packet);
void		srv_death_request(t_list_client *tmp, t_server *server,
				  t_packet *packet);
void		srv_end_data(t_list_client *tmp, t_server *server,
			     t_packet *packet);

/*
**		order.c
*/
void		coord_data(t_client *client);
void		end_data(t_client *client);

/*
**		event.c
*/
int		server_key_press(int keycode, t_server *server);
int		client_key_press(int keycode, t_client *client);

/*
**		net_close.c
*/
void		exit_serv(t_server *server);
void		exit_client(t_client *client);

/*
**		loop.c
*/
int		client_loop(t_client *client);
int		server_loop(t_server *server);

/*
**		init.c
*/
int		client_init(char *ip, int port);
int		server_init(t_scene *scene, t_screen *screen, int opt);

/*
**		server_response.c
*/
void		st_occuped(t_list_client *tmp, t_server *server, int *line);
void		st_wfstruct(t_list_client *tmp, t_server *server, int *line);
t_value		*add_missing_value(t_value *list, int value, int *status);
void		send_data(t_list_client *tmp, t_server *server);

/*
**		net_close.c
*/
void		close_srv(int order1, int order3, t_list_client *order2);

/*
**		main.c
*/
void		sig_catch(int signum);

/*
**		scene_transfer.c
*/
t_scene		get_scene(int sock, t_screen *screen);
void		*check_packet(t_packet *packet, int size);

/*
**		cell_transfer.c
*/
void		send_cell(t_list_client *tmp, t_cell *obj,
			    t_packet *packet);
t_cell		*get_cell(int sock, t_packet *packet);

/*
**		st_waiting.c
*/
void		st_waiting(t_list_client *tmp, t_server *server, int *line);

/*
**		get_missing_data.c
*/
void		get_missing_data(t_client *client);

/*
**		send_scene.c
*/
int		send_scene(t_list_client *tmp, t_scene *scene, t_screen *screen);

/*
** x functions
*/

typedef void (*sighandler_t)(int);

struct hostent	*xgethostbyname(char *ip);
int		xsocket(int domain, int type, int protocol);
int		xconnect(int sockfd, const struct sockaddr *addr,
			 socklen_t addrlen);
void		xsignal(int signum, sighandler_t handler);
int		xfork();
int		xbind(int sockfd, const struct sockaddr *addr,
		      socklen_t addrlen);
int		xlisten(int sockfd, int backlog);
int		xfcntl(int fd, int cmd, int arg);
int		xrecv(int sockfd, void *buf, size_t len, int flags);
int		xsend(int sockfd, const void *buf, size_t len, int flags);
int		xaccept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);

#endif
