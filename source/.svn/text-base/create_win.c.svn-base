/*
** create_win.c for rt in /home/brissa_a//c/B2/rt
**
** Made by alexis brissard
** Login   <brissa_a@epitech.net>
**
** Started on  Fri May  6 15:44:06 2011 alexis brissard
** Last update Thu Jun  2 19:11:12 2011 alexis brissard
*/

#include "my_printf.h"
#include "rt.h"

void		create_win(t_screen *screen)
{
  PX(screen->mlx = mlx_init());
  PX(screen->win = mlx_new_window(screen->mlx,
			       screen->width, screen->height,
				  "Raytracer"));
  PX(screen->img.img = mlx_new_image(screen->mlx,
				  screen->width, screen->height));
  PX(screen->img.data = mlx_get_data_addr(screen->img.img,
					  &screen->img.bpp,
					  &screen->img.sizeline,
					  &screen->img.endian));
  screen->img.x_size = screen->width;
  screen->img.y_size = screen->height;
}
