/*
** anti_alias.c for raytracer in /home/wilgen_t/projets/rt
**
** Made by thomas wilgenbus
** Login   <wilgen_t@epitech.net>
**
** Started on  Tue May 10 15:02:46 2011 thomas wilgenbus
** Last update Sun Jun  5 14:18:17 2011 thomas wilgenbus
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"struct.h"
#include	"anti_alias.h"
#include	"parser.h"
#include	"rt.h"

int		build_new_pixel(t_color *c_tmp, t_scene *scene)
{
  t_color	final;
  int		green;
  int		alias;
  int		blue;
  int		iter;
  int		red;

  alias = (int)scene->camera->anti_alias;
  iter = 0;
  red = 0;
  green = 0;
  blue = 0;
  while (iter < alias * alias)
    {
      red += c_tmp[iter].rgb.red;
      green += c_tmp[iter].rgb.green;
      blue += c_tmp[iter].rgb.blue;
      iter++;
    }
  final.rgb.red = red / (alias * alias * 1.0);
  final.rgb.green = green / (alias * alias * 1.0);
  final.rgb.blue = blue / (alias * alias * 1.0);
  return (final.all);
}

int		fill_sub_pixel_tab(t_screen *screen, t_scene *scene,
				   double x, double y)
{
  t_color	*c_tmp;
  t_vect	subpix;
  int		alias;
  int		iter;

  alias = (int)scene->camera->anti_alias;
  c_tmp = PX(malloc(sizeof(*c_tmp) * (alias * alias)));
  init_tab(c_tmp, alias * alias);
  subpix.y = y * 1.0;
  iter = -1;
  while (subpix.y < y + 1.0)
    {
      subpix.x = x;
      while (subpix.x < x + 1.0)
	{
	  c_tmp[++iter].all = get_focus_color(screen, scene,
	  subpix.x + ((get_rand(1) / (RAND_MAX * 1.)) / alias),
	  subpix.y + ((get_rand(2) / (RAND_MAX * 1.)) / alias));
	  subpix.x += 1. / alias;
	}
      subpix.y += 1. / alias;
    }
  return (build_new_pixel(c_tmp, scene));
}

void		fill_with_anti_alias(t_image *img, t_scene *scene,
				     t_screen *screen)
{
  t_vect	vect;

  vect.y = -1;
  while (++vect.y < img->y_size)
    {
      thread_line((int)vect.y, screen, scene, fill_sub_pixel_tab);
      update_screen(screen);
    }
}

void		aff_line(t_image *img, t_scene *scene, t_screen *screen)
{
  int		x;
  int		y;

  y = -1;
  while (++y < img->y_size)
    {
      x = -1;
      while (++x < img->x_size)
  	if (img->data[(img->bpp / 8) * (img->x_size * y + x) + 3])
  	  my_put_pixel_to_img(img, x, y, 0xff0000);
    }
  update_screen(screen);
  if (scene->camera->param < 1)
    scene->camera->param = 1;
}

void		anti_alias(t_image *img, t_scene *scene, t_screen *screen)
{
  int		x;
  int		y;

  scene->camera->anti_alias = pow(2, scene->camera->anti_alias);
  if (scene->camera->anti_alias < 2)
    return ;
  else if (scene->camera->anti_alias > 512)
    scene->camera->anti_alias = 64;
  y = -1;
  while (++y < img->y_size)
    {
      x = -1;
      while (++x < img->x_size)
	{
	  if (is_alias_around_pix(x, y, img))
	    {
	      img->data[(img->bpp / 8) * (img->x_size * y + x) + 3] = 1;
	    }
	}
    }
  aff_line(img, scene, screen);
}
