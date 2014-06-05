/*
** get_focus_color.c for get_focus_color.c in /home/sabour_m//RTV/rt/source
**
** Made by mourad sabour
** Login   <sabour_m@epitech.net>
**
** Started on  Mon May 23 21:38:03 2011 mourad sabour
** Last update Sat Jun  4 03:06:23 2011 thomas wilgenbus
*/

#include		"rt.h"
#include		"struct.h"
#include		"bmp.h"
#include		"parser.h"
#include		"network.h"
#include		"my_printf.h"

int			final_focus(int red, int blue, int green, int all_pix)
{
  t_color		color_final;

  color_final.rgb.red = CH_COL((red / all_pix));
  color_final.rgb.blue = CH_COL((blue / all_pix));
  color_final.rgb.green = CH_COL((green / all_pix));
  return (color_final.all);
}

void			select_and_sum_pixel_around(t_var *var, t_color *color,
						    t_image *img, t_scene *scene)
{
  color->all = get_pix_color(img, scene, var->count_x, var->count_y);
  var->all_pix++;
  var->red += color->rgb.red;
  var->blue += color->rgb.blue;
  var->green += color->rgb.green;
}

void			init_var(t_var *var, double x, double y, double flou)
{
  var->count_x = x - flou;
  var->count_y = y - flou;
  var->red = 0;
  var->green = 0;
  var->blue = 0;
  var->all_pix = 0;
}

int			mlx_pixel_around_focus(t_scene *scene, t_vect *cur_pix,
					       t_image *tmp_img, double flou)
{
  t_color		color;
  t_var			var;

  if (!flou)
    return (get_pix_color(tmp_img, scene, cur_pix->x, cur_pix->y));
  init_var(&var, cur_pix->x, cur_pix->y, flou);
  while (var.count_y <= cur_pix->y + (flou + 1))
    {
      if ((var.count_x >= 0 && var.count_x <= tmp_img->x_size) &&
	  (var.count_y >= 0 && var.count_y <= tmp_img->y_size))
	if ((get_pix_k(tmp_img, scene, var.count_x, var.count_y)) >= cur_pix->z)
	  select_and_sum_pixel_around(&var, &color, tmp_img, scene);
      var.count_x += 1;
      if (var.count_x >= cur_pix->x + (flou + 1))
	{
	  var.count_x = cur_pix->x - flou;
	  var.count_y += 1;
	}
    }
  if (!var.all_pix)
    return (get_pix_color(tmp_img, scene, cur_pix->x, cur_pix->y));
  return (final_focus(var.red, var.blue, var.green, var.all_pix));
}

int			get_focus_color(t_screen *screen, t_scene *scene,
					double x, double y)
{
  int			color;
  double       		flou;
  t_vect		cur_pix;

  cur_pix.x = x;
  cur_pix.y = y;
  if (!scene->camera->focus)
    return (get_pix_color(&screen->img, scene, x, y));
  flou = calc_focus_distance(scene, &screen->img, &cur_pix);
  color = mlx_pixel_around_focus(scene, &cur_pix, &screen->img, flou);
  return (color);
}
