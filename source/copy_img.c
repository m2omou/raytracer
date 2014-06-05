/*
** copy_img.c for copy_img.c in /home/sabour_m//RTV/rt/source
**
** Made by mourad sabour
** Login   <sabour_m@epitech.net>
**
** Started on  Tue May 24 14:49:15 2011 mourad sabour
** Last update Fri Jun  3 20:41:00 2011 thomas wilgenbus
*/

#include		"rt.h"
#include		"slide_show.h"
#include		"struct.h"
#include		"parser.h"
#include		"bmp.h"

t_image			copy_img(t_image *img, t_screen *screen)
{
  t_image		tmp_img;
  int			color;
  int			x;
  int			y;

  y = 0;
  tmp_img.y_size = img->y_size;
  tmp_img.x_size = img->x_size;
  init_bmp_img(screen, &tmp_img);
  while (y < img->y_size)
    {
      x = 0;
      while (x < img->x_size)
	{
	  color = get_color(x, y, img);
	  my_put_pixel_to_img(&tmp_img, x, y, color);
	  x++;
	}
      y++;
    }
  return (tmp_img);
}
