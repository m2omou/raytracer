/*
** get_shadow.c for rt in /home/brissa_a//c/B2/rt
**
** Made by alexis brissard
** Login   <brissa_a@epitech.net>
**
** Started on  Wed May 25 17:23:20 2011 alexis brissard
** Last update Sat Jun  4 19:27:34 2011 alexis brissard
*/

#include	"rt.h"

int		get_shadow_color(t_inter *inter, t_scene *scene,
				 t_obj *light, t_vect *light_v)
{
  int		shad_col;
  int		obj_col;
  t_inter	l_inter;
  t_vect	test;
  t_vect	o;
  int		i;

  i = -1;
  l_inter = *inter;
  test = *light_v;
  shad_col = light->color.all;
  while (!(++i) || (l_inter.k != -1 && (get_cos_a(&test, light_v) > 0)))
    {
      o = l_inter.p;
      if (i != 0)
	{
	  obj_col = get_obj_color(&l_inter);
	  shad_col = color_absorb(shad_col, add_color(obj_col,
          apply_coef(0xFFFFFF, get_obj_transp(&l_inter))),
          light->gloss, light->absorb);
 	}
      throw_vect(&o, light_v, scene->objet, &l_inter);
      create_light_vect(&test, &light->move->pos, &l_inter.p, light);
    }
  return (shad_col);
}

double		get_shadow_pow(t_inter *inter, t_scene *scene,
			       t_obj *light, t_vect *light_v)
{
  t_inter	l_inter;
  double	pow;
  t_vect	o;
  int		i;
  t_vect	test;

  i = 0;
  l_inter = *inter;
  pow = 1;
  test = *light_v;
  while (l_inter.k != -1 && (light->is_paral ||
			     (get_cos_a(&test, light_v) > 0 || !i)))
    {
      o = l_inter.p;
      if (i != 0)
	pow = pow * ((get_obj_transp(&l_inter) * 1.5) > 1
		     ? 1 : (get_obj_transp(&l_inter) * 1.5));
      throw_vect(&o, light_v, scene->objet, &l_inter);
      i++;
      create_light_vect(&test, &light->move->pos, &l_inter.p, light);
    }
  return (pow);
}
