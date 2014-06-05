/*
** test_aliasing.c for raytracer in /home/wilgen_t/projets/rt
**
** Made by thomas wilgenbus
** Login   <wilgen_t@epitech.net>
**
** Started on  Tue May 24 19:53:59 2011 thomas wilgenbus
** Last update Fri Jun  3 20:36:38 2011 thomas wilgenbus
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"struct.h"
#include	"anti_alias.h"
#include	"rt.h"

void		init_tab(t_color *c_tmp, int size)
{
  int		iter;

  iter = 0;
  while (iter < size)
    c_tmp[iter++].all = 0;
}

int		is_aliasing(int color, int color_up)
{
  t_color	c_u;
  t_color	c;

  c.all = color;
  c_u.all = color_up;
  if (ABS(c.rgb.red - c_u.rgb.red) > LIMIT_ALIAS ||
      ABS(c.rgb.blue - c_u.rgb.blue) > LIMIT_ALIAS ||
      ABS(c.rgb.green - c_u.rgb.green) > LIMIT_ALIAS)
    return (1);
  return (0);
}

int		get_color(int x, int y, t_image *img)
{
  t_color	color;
  int		i;

  i = (img->bpp / 8) * (img->x_size * y + x);
  color.rgb.blue = img->data[i];
  color.rgb.green = img->data[i + 1];
  color.rgb.red = img->data[i + 2];
  return (color.all);
}

int		is_alias_around_pix(int x, int y, t_image *img)
{
  return ((x < img->x_size - 1 &&
	   is_aliasing(get_color(x, y, img), get_color(x + 1, y, img))) ||
	  (y < img->y_size - 1 &&
	   is_aliasing(get_color(x, y, img), get_color(x, y + 1, img))) ||
	  (x && is_aliasing(get_color(x, y, img), get_color(x - 1, y, img))) ||
	  (y && is_aliasing(get_color(x, y, img), get_color(x, y - 1, img))));
}
