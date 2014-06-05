/*
** calc_focus_distance.c for calc_focus_distance.c in /home/sabour_m//RTV/rt/source
**
** Made by mourad sabour
** Login   <sabour_m@epitech.net>
**
** Started on  Tue May 24 15:44:00 2011 mourad sabour
** Last update Sun Jun  5 17:37:08 2011 mourad sabour
*/

#include		<math.h>
#include		"rt.h"
#include		"struct.h"

double			calc_focus_distance(t_scene *scene, t_image *img,
					    t_vect *cur_pix)
{
  t_vect		vect_cam;
  t_inter		inter;
  double		k;
  double       		flou;

  calc_vect_cam(&vect_cam, img, scene->camera, cur_pix);
  throw_vect(&scene->camera->move->pos, &vect_cam, scene->objet, &inter);
  cur_pix->z = inter.k;
  k = inter.k * norme(&vect_cam);
  if (k < 0)
    return (0);
  flou = ABS((k - scene->camera->focus));
  flou /= scene->camera->focus_speed;
  if (flou > 8)
    return (8);
  return (flou);
}
