/*
** mobus.c for rt in /home/brissa_a//c/B2/rt/object
**
** Made by alexis brissard
** Login   <brissa_a@epitech.net>
**
** Started on  Sun May 22 21:33:30 2011 alexis brissard
** Last update Fri Jun  3 22:02:50 2011 thomas wilgenbus
*/

#include "rt.h"

void		get_coef(t_vect *o, t_vect *u, t_obj *obj, double *coef)
{
  coef[0] = -2.0 * obj->param * o->x * o->z + pow(o->y, 3.0)
    - pow(obj->param, 2.0) * o->y + pow(o->x, 2.0) * o->y
    - 2.0 * pow(o->x, 2.0) * o->z - 2.0 * pow(o->y, 2.0) * o->z
    + o->y * pow(o->z, 2.0);
  coef[1] = 2.0 * o->x * u->x * o->y - 2.0 * obj->param * o->x * u->z
    - 2.0 * obj->param * u->x * o->z - 4.0 * o->x * u->x * o->z
    - 4.0 * o->y * u->y * o->z + 2.0 * o->y * o->z * u->z
    - 2.0 * pow(o->x, 2.0) * u->z - pow(obj->param, 2.0) * u->y
    + 3.0 * pow(o->y, 2.0) * u->y + pow(o->x, 2.0) * u->y
    - 2.0 * pow(o->y, 2.0) * u->z + u->y * pow(o->z, 2.0);
  coef[2] = 2.0 * o->x * u->x * u->y - 2.0 * obj->param * u->x * u->z
    - 4.0 * o->x * u->x * u->z - 4.0 * o->y * u->y * u->z
    + 2.0 * u->y * o->z * u->z + pow(u->x, 2.0) * o->y
    + 3.0 * o->y * pow(u->y, 2.0) - 2.0 * pow(u->x, 2.0) * o->z
    - 2.0 * pow(u->y, 2.0) * o->z + o->y * pow(u->z, 2.0);
  coef[3] = -2.0 * pow(u->x, 2.0) * u->z
    + pow(u->x, 2.0) * u->y - 2.0 * pow(u->y, 2.0) * u->z
    + u->y * pow(u->z, 2.0) + pow(u->y, 3.0);
}

double		calc_k_mobus(t_vect *o, t_vect *u, t_obj *obj)
{
  double	res[3];
  double	coef[4];
  int		i;

  get_coef(o, u, obj, coef);
  res_eq_tr(coef, res);
  rm_out_of_limit(res, obj, o, u);
  i = 0;
  while (i < 3)
    {
      if ((res[i] * norme(u)) > PAS
      	  && is_min(res, i))
      	return (res[i]);
      i++;
    }
  return (-1.0);
}

void		calc_normal_mobus(t_vect *p, t_obj *obj, t_vect *normal)
{
  double	v;
  double	t;

  v = atan2(p->y, p->x);
  t = p->z / sin(v / 2);
  if (check_t(t, v, p, obj))
    {
      v = v - PI;
      t = p->z / sin(v / 2);
    }
  normal->x = -(2 * pow(cos(v / 2), 3) * t
		+ 2 * obj->param * pow(cos(v / 2), 2)
		- 2 * t * cos(v / 2)  - obj->param) * sin(v / 2);
  normal->y = -3 * t * pow(cos(v / 2), 2) + 2 * t * pow(cos(v / 2), 4) - 2
    * obj->param * cos(v / 2) + t / 2 + 2 * pow(cos(v / 2), 3) * obj->param;
  normal->z = cos(v / 2.0) * (obj->param + t * cos(v / 2));
}

void		convert_3d_to_2d_mobus(t_vect *p, t_pix *pix, t_obj *obj,
					t_texture *tex)
{
  double	u;
  double	v;

  u = atan2(p->x / obj->param,
	    p->y / obj->param);
  pix->x = (1 - (u + PI) / tex->x_rep / (2.0 * PI)) * (tex->img.x_size - 1);
  v = p->z / obj->param;
  pix->y = (asin(-v) + (PI / 2)) / PI / tex->y_rep * (tex->img.y_size - 1);
}
