/*
** cylindre.c for rt in /home/brissa_a//c/B2/rt/object
**
** Made by alexis brissard
** Login   <brissa_a@epitech.net>
**
** Started on  Sun May  8 15:00:45 2011 alexis brissard
** Last update Fri Jun  3 21:26:51 2011 thomas wilgenbus
*/

#include "rt.h"

int		is_in_cylinder_eq(t_vect *pt, t_obj *obj)
{
  if (PO(pt->x) + PO(pt->y) - PO(obj->param) < 0)
    return (1);
  return (0);
}

double		calc_k_cylinder(t_vect *o, t_vect *u, t_obj *obj)
{
  t_vect	tmp;
  double	x1;
  double	x2;

  tmp.x = (u->x * u->x + u->y * u->y);
  tmp.y = 2 * (o->x * u->x + o->y * u->y);
  tmp.z = (o->x * o->x + o->y * o->y - obj->param * obj->param);
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

void		calc_normal_cylinder(t_vect *p, t_obj *obj, t_vect *normal)
{
  obj = 0;
  normal->x = p->x;
  normal->y = p->y;
  normal->z = 0;
}

void            convert_3d_to_2d_cylinder(t_vect *p, t_pix *pix, t_obj *obj,
					   t_texture *tex)
{
  double        u;

  u = atan2(p->x / obj->param,
            p->y / obj->param);
  pix->x = (1 - (u + PI) / tex->x_rep / (2.0 * PI)) * (tex->img.x_size - 1);
  pix->y = (ceil(p->z / tex->y_rep) - p->z / tex->y_rep)
    * (tex->img.y_size - 1);
}
