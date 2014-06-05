/*
** multi_thread.c for raytracer in /home/wilgen_t/projets/rt
**
** Made by thomas wilgenbus
** Login   <wilgen_t@epitech.net>
**
** Started on  Tue May 31 19:01:25 2011 thomas wilgenbus
** Last update Sat Jun  4 23:57:01 2011 thomas wilgenbus
*/

#include	<unistd.h>
#include	"rt.h"
#include	"bmp.h"

void			*thread_loop(void *arg)
{
  t_thread		*thread;
  char			*nil[1];

  thread = arg;
  X(write(thread->pipeout[1], "a", 1));
  while (!thread->quit)
    {
      X(read(thread->pipein[0], nil, 1));
      if (thread->quit)
	return (NULL);
      calc_line(thread);
      X(write(thread->pipeout[1], "a", 1));
    }
  return (NULL);
}

int			init_thread(t_screen *screen, t_scene *scene)
{
  int			num;
  int			x;

  num = -1;
  scene->thread = PX(malloc(sizeof(*(scene->thread)) *
			    (screen->img.thread_num)));
  x = 0;
  is_in_neg_object(NULL, NULL, scene->objet);
  while (++num < screen->img.thread_num)
    {
      scene->thread[num].sx = x;
      x = (num * screen->img.x_size) / (screen->img.thread_num - 1);
      scene->thread[num].ex = x;
      scene->thread[num].screen = screen;
      scene->thread[num].scene = scene;
      scene->thread[num].quit = 0;
      scene->thread[num].calc_new = 0;
      scene->thread[num].num = num;
      X(pipe(scene->thread[num].pipein));
      X(pipe(scene->thread[num].pipeout));
      pthread_create(&scene->thread[num].thread, NULL,
		     thread_loop, &scene->thread[num]);
    }
  return (num);
}

void			thread_quit(t_thread *thread, t_image *img)
{
  int			num;

  num = -1;
  while (++num < img->thread_num)
    {
      thread[num].quit = 1;
      X(write(thread[num].pipein[1], "a", 1));
      X(pthread_join(thread[num].thread, NULL));
    }
}

void			wait_child(t_thread *thread, t_image *img)
{
  char			nil[1];
  int			num;

  num = -1;
  while (++num < img->thread_num)
    X(read(thread[num].pipeout[0], nil, 1));
}

char			*thread_line(int line, t_screen *screen, t_scene *scene,
				    int (*calc_method)(t_screen *screen, t_scene *,
						       double, double))
{
  static int		start = 1;
  int			num;

  if (start)
    {
      init_thread(screen, scene);
      wait_child(scene->thread, &screen->img);
    }
  start = 0;
  num = -1;
  while (++num < screen->img.thread_num)
    {
      scene->thread[num].y = line;
      scene->thread[num].calc_method = calc_method;
      X(write(scene->thread[num].pipein[1], "a", 1));
    }
  wait_child(scene->thread, &screen->img);
  return (screen->img.data + line * screen->img.sizeline);
}
