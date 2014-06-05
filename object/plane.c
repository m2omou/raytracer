/*
** plan.c for rt in /home/brissa_a//c/B2/rt/object
**
** Made by alexis brissard
** Login   <brissa_a@epitech.net>
**
** Started on  Thu May  5 01:28:41 2011 alexis brissard
** Last update Sat Jun  4 15:09:56 2011 mourad sabour
*/

#include "rt.h"

int		is_in_plane_eq(t_vect *pt, t_obj *obj)
{
  if (IS_ZERO(pt->z - obj->move->pos.z))
    return (1);
  return (0);
}

double		calc_k_plane(t_vect *o, t_vect *u, t_obj *obj)
{
  double	k;

  if (IS_ZERO(u->z))
    return (-1);
  k = ( -1 * o->z / u->z);
  if (k * norme(u) > PAS && check_limit(o, u, k, obj))
    return (k);
  else
    return (-1);
}

void		calc_normal_plane(t_vect *p, t_obj *obj, t_vect *normal)
{
  p = 0;
  obj = 0;
  normal->x = 0;
  normal->y = 0;
  normal->z = 1;
}

void		convert_3d_to_2d_plane(t_vect *p, t_pix *pix, t_obj *obj,
				       t_texture *tex)
{
  double	n;

  n = 0.5;
  obj = 0;
  pix->x = (1 - ((p->y * tex->x_rep) - floor((p->y * tex->x_rep))))
    * (tex->img.x_size - 1);
  pix->y = (1 - ((p->x * tex->y_rep) - floor((p->x * tex->y_rep))))
    * (tex->img.y_size - 1);
}
