/*
** get_direct_color.c for raytracer in /home/wilgen_t/projets/rt
**
** Made by thomas wilgenbus
** Login   <wilgen_t@epitech.net>
**
** Started on  Wed May 25 11:30:34 2011 thomas wilgenbus
** Last update Sat Jun  4 20:45:16 2011 alexis brissard
*/

#include "rt.h"

int		apply_cos_a(int	color, int light_color, double cos_a)
{
  t_color	fin_color;
  t_color	l_color;

  l_color.all = light_color;
  fin_color.all = color;
  fin_color.rgb.red = (fin_color.rgb.red * (1 - cos_a)
		       + l_color.rgb.red * cos_a);
  fin_color.rgb.green = (fin_color.rgb.green * (1 - cos_a)
			 + l_color.rgb.green * cos_a);
  fin_color.rgb.blue = (fin_color.rgb.blue * (1 - cos_a)
			+ l_color.rgb.blue * cos_a);
  return (fin_color.all);
}

void		init_var2(t_inter *inter, t_obj **light,
			  t_scene *scene, t_vect *o)
{
  inter->p = *o;
  inter->k = 0;
  *light = scene->light;
}

double		get_cos_a2(double cos_a, t_obj *light,
			   t_vect l_vect, double light_pow)
{
  cos_a = cos_a / exp((1 - cos_a) * (norme(&l_vect) /
				     (light->param *
				      light_pow)) * (500 / light->halo));
  return (cos_a);
}

int		get_direct_color(int final_color, t_vect *o,
				 t_vect *u, t_scene *scene)
{
  double	light_pow;
  int		l_color;
  t_vect	l_vect;
  t_obj		*light;
  t_inter	inter;
  double	cos_a;

  init_var2(&inter, &light, scene, o);
  while (light)
    {
      if (!light->is_paral && light->halo)
	{
	  create_light_vect(&l_vect, &light->move->pos, o, light);
	  cos_a = get_cos_a(u, &l_vect);
	  if (cos_a > 0)
	    {
	      l_color = get_shadow_color(&inter, scene, light, &l_vect);
	      light_pow = get_shadow_pow(&inter, scene, light, &l_vect);
	      cos_a = get_cos_a2(cos_a, light, l_vect, light_pow);
	      final_color = apply_cos_a(final_color, l_color, cos_a);
	    }
	}
      light = light->next;
    }
  return (final_color);
}
