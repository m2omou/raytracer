/*
** calc_line.c for raytracer in /home/wilgen_t/projets/rt
**
** Made by thomas wilgenbus
** Login   <wilgen_t@epitech.net>
**
** Started on  Fri Jun  3 16:00:55 2011 thomas wilgenbus
** Last update Sat Jun  4 05:15:39 2011 thomas wilgenbus
*/

#include	<stdio.h>
#include	<unistd.h>
#include	"rt.h"
#include	"bmp.h"

void			*calc_line(void *arg)
{
  t_thread		*thread;
  int			color;
  t_vect		pix;
  int			x;

  thread = arg;
  x = thread->sx;
  while (x < thread->ex)
    {
      if ((thread->calc_method != fill_sub_pixel_tab) ||
	  thread->screen->img.data[(thread->screen->img.bpp / 8) *
	  (thread->screen->img.x_size * thread->y + x) + 3])
	{
	  pix.x = x;
	  pix.y = thread->y;
	  color = thread->calc_method(thread->screen, thread->scene, pix.x, pix.y);
	  if (thread->calc_method != cell_pixel)
	    my_put_pixel_to_img(&thread->screen->img, x, thread->y, color);
	}
      x++;
    }
  return (NULL);
}
