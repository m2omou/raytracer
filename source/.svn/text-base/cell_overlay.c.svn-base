/*
** cell_overlay.c for rt in /home/despuj_a//final/rt/rt
**
** Made by adrien despujol
** Login   <despuj_a@epitech.net>
**
** Started on  Wed May 25 15:57:43 2011 adrien despujol
** Last update Sat Jun  4 12:23:54 2011 thomas wilgenbus
*/

#include		"rt.h"
#include		"parser.h"

int			cell_pixel(t_screen *screen, t_scene *scene,
				    double x, double y)
{
  t_obj			*target;

  target = is_border(screen, scene, (int)x, (int)y);
  if (target)
    fill_overlay(&screen->img, (int)x, (int)y, LIM_CELLSHADING);
  return (0);
}

void			fill_overlay(t_image *img, int x, int y, int lim)
{
  if (lim > 0)
    {
      my_put_pixel_to_img(img, x, y, 0x0);
      fill_overlay(img, x, y - 1, lim - 1);
      fill_overlay(img, x, y + 1, lim - 1);
      fill_overlay(img, x + 1, y, lim - 1);
      fill_overlay(img, x - 1, y, lim - 1);
    }
  else
    return;
}

void			cell_overlay(t_screen *screen, t_scene *scene)
{
  int			y;

  y = -1;
  while (++y < screen->img.y_size)
    {
      thread_line(y, screen, scene, cell_pixel);
      update_screen(screen);
    }
}

t_obj			*is_border(t_screen *screen, t_scene *scene, int x, int y)
{
  t_vect		cam_vect;
  t_inter		current;
  t_vect		cur_pix;
  t_obj			*test;

  cur_pix.x = x;
  cur_pix.y = y;
  calc_vect_cam(&cam_vect, &screen->img, scene->camera, &cur_pix);
  throw_vect(&scene->camera->move->pos, &cam_vect, scene->objet, &current);
  test = detect_pix(&screen->img, scene, x + 1, y);
  if (test != current.obj)
    return (test);
  test = detect_pix(&screen->img, scene, x - 1, y);
  if (test != current.obj)
    return (test);
  test = detect_pix(&screen->img, scene, x, y - 1);
  if (test != current.obj)
    return (test);
  test = detect_pix(&screen->img, scene, x, y + 1);
  if (test != current.obj)
    return (test);
  return (0);
}

t_obj				*detect_pix(t_image *img, t_scene *s, int x, int y)
{
  t_vect			cam_vect;
  t_vect			cur_pix;
  t_inter			result;

  cur_pix.x = x;
  cur_pix.y = y;
  calc_vect_cam(&cam_vect, img, s->camera, &cur_pix);
  throw_vect(&s->camera->move->pos, &cam_vect, s->objet, &result);
  return (result.obj);
}
