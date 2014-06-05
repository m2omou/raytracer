/*
** get_transp_color.c for rt in /home/brissa_a//c/B2/rt/source
**
** Made by alexis brissard
** Login   <brissa_a@epitech.net>
**
** Started on  Sat May 14 17:09:27 2011 alexis brissard
** Last update Sat Jun  4 12:37:36 2011 thomas wilgenbus
*/

#include "rt.h"

void		create_transp_vect(t_vect *t, t_vect *n, t_vect *u, double nr)
{
  double	cos_a;
  double	sin_2_b;
  double	coef;

  cos_a = get_cos_a(u, n);
  sin_2_b = nr * nr * (1.0 - cos_a * cos_a);
  if (sin_2_b < 1)
    {
      coef = nr * cos_a + sqrt(1 - sin_2_b);
      t->x = nr * u->x / norme(u) + coef * n->x / norme(n);
      t->y = nr * u->y / norme(u) + coef * n->y / norme(n);
      t->z = nr * u->z / norme(u) + coef * n->z / norme(n);
    }
  else
    *t = *u;
}

int		get_transp_color(t_inter *inter, t_scene *scene, t_vect *u, int i)
{
  int		tc;
  t_vect	transp_v_in;

  create_transp_vect(&transp_v_in, &inter->normal, u,
		     inter->obj->refrac / scene->camera->refrac);
  tc = get_vect_color(&inter->p, &transp_v_in, scene, i + 1);
  return (tc);
}
