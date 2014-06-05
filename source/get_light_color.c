/*
** get_light_color.c for rt in /home/brissa_a//c/B2/rt/source
**
** Made by alexis brissard
** Login   <brissa_a@epitech.net>
**
** Started on  Thu May  5 02:00:09 2011 alexis brissard
   Last update Sat Jun  4 19:27:32 2011 mourad sabour
*/

#include "rt.h"
#include "bmp.h"

int		get_cell_shading_color(t_inter *inter, t_scene *scene,
				       t_obj *light)
{
  t_vect	light_v;
  double	cos_a;
  double	light_pow;
  t_inter	cell_shadow;
  int		lc;

  lc = get_obj_color(inter);
  create_light_vect(&light_v, &light->move->pos, &inter->p, light);
  lc = color_absorb(lc, get_shadow_color(inter, scene, light, &light_v),
		    inter->obj->gloss, inter->obj->absorb);
  cos_a = get_cos_a(&light_v, &inter->normal);
  light_pow = 1.0 / exp(norme(&light_v) / light->param);
  throw_vect(&inter->p, &light_v, scene->objet, &cell_shadow);
  lc = coeff_cell(lc, cos_a, scene);
  if (inter->obj != cell_shadow.obj && cell_shadow.obj != 0)
    lc = apply_coef(lc, 0.2);
  return (lc);
}

int		get_one_light_color(t_inter *inter, t_scene *scene,
				    t_obj *light)
{
  t_vect	light_v;
  double	cos_a;
  double	light_pow;
  int		lc;

  lc = get_obj_color(inter);
  create_light_vect(&light_v, &light->move->pos, &inter->p, light);
  lc = color_absorb(lc, get_shadow_color(inter, scene, light, &light_v),
		    inter->obj->gloss, inter->obj->absorb);
  cos_a = get_cos_a(&light_v, &inter->normal);
  light_pow = 1.0 / exp(norme(&light_v) / light->param);
  if (cos_a > 0)
    {
      lc = apply_coef(lc, light_pow * cos_a);
      lc = apply_coef(lc, get_shadow_pow(inter, scene, light, &light_v));
	}
  else
    lc = 0x000000;
  return (lc);
}

int		get_light_color(t_inter *inter, t_scene *scene)
{
  t_obj		*cur_light;
  int		fc;

  fc = 0;
  cur_light = scene->light;
  while (cur_light)
    {
      if (!scene->cell)
	fc = add_color(fc, get_one_light_color(inter, scene, cur_light));
      else
	fc = add_color(fc, get_cell_shading_color(inter, scene, cur_light));
      cur_light = cur_light->next;
    }
  return (fc);
}
