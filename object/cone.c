/*
** cone.c for cone.c in /home/sabour_m//RTV/rt/object
**
** Made by mourad sabour
** Login   <sabour_m@epitech.net>
**
** Started on  Mon May 16 04:41:19 2011 mourad sabour
** Last update Sat Jun  4 15:42:14 2011 alexis brissard
*/

#include "rt.h"

int		is_in_cone_eq(t_vect *pt, t_obj *obj)
{
  double	r;

  r = PI / 2.0 - PI * (obj->param / 180);
  if (PO(pt->x) + PO(pt->y) - PO(pt->z) / (PO(r)) < 0)
    return (1);
  return (0);
}

double          calc_k_cone(t_vect *o, t_vect *u, t_obj *obj)
{
  t_vect        tmp;
  double        x1;
  double        x2;
  double	r;

  r = PI / 2.0 - PI * (obj->param / 180);
  tmp.x = (u->x * u->x + u->y * u->y) - (u->z * u->z) / (tan(r) * tan(r));
  tmp.y = 2 * (o->x * u->x + o->y * u->y) - 2 * (o->z * u->z) / (PO(tan(r)));
  tmp.z = (o->x * o->x + o->y * o->y) - (o->z * o->z) / (tan(r) * tan(r));
  if (res_eq_sc(&tmp, &x1, &x2))
    {
      if ((x1 * norme(u)) > PAS && x1 < x2 && check_limit(o, u, x1, obj))
	return (x1);
      else if ((x2 * norme(u)) > PAS && check_limit(o, u, x2, obj))
	return (x2);
      else
        return (-1);
    }
  else
    return (-1);
}

void            calc_normal_cone(t_vect *p, t_obj *obj, t_vect *normal)
{
  normal->x = p->x;
  normal->y = p->y;
  normal->z = -1. * SIGN(p->z) * sin(PI * obj->param / 180);
}

void            convert_3d_to_2d_cone(t_vect *p, t_pix *pix, t_obj *obj,
				       t_texture *tex)
{
  double        u;

  u = atan2(p->x / obj->param,
            p->y / obj->param);
  pix->x = (1 - (u + PI) / tex->y_rep / (2.0 * PI)) * (tex->img.x_size - 1);
  pix->y = (ceil(p->z / tex->y_rep) - p->z / tex->y_rep) *
    (tex->img.y_size - 1);
}
