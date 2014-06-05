/*
** mobus_utils.c for raytracer in /home/wilgen_t/projets/rt
**
** Made by thomas wilgenbus
** Login   <wilgen_t@epitech.net>
**
** Started on  Fri Jun  3 21:56:11 2011 thomas wilgenbus
** Last update Fri Jun  3 22:03:02 2011 thomas wilgenbus
*/

#include "struct.h"
#include "rt.h"

int		check_t(double t, double v, t_vect *p, t_obj *obj)
{
  double	tmp;
  double	r;

  r = obj->param;
  obj = 0;
  tmp = (r + t * cos(v / 2)) * cos(v);
  if (!IS_ZERO(tmp - p->x))
    return (1);
  tmp = (r + t * cos(v / 2)) * sin(v);
  if (!IS_ZERO(tmp - p->y))
    return (1);
  return (0);
}

int		limit(double k, t_obj *obj, t_vect *o, t_vect *u)
{
  t_vect	tmp_p;
  double	v;
  double	t;

  tmp_p.x = o->x + u->x * k;
  tmp_p.y = o->y + u->y * k;
  tmp_p.z = o->z + u->z * k;
  v = atan2(tmp_p.y, tmp_p.x);
  if (!IS_ZERO(v))
    t = tmp_p.z / sin(v / 2);
  else
    return (0);
  if (check_t(t, v, &tmp_p, obj))
    {
      v = v - PI;
      if (!IS_ZERO(v))
	t = tmp_p.z / sin(v / 2);
      else
	return (0);
    }
  if (t > obj->lim_max.x || t < obj->lim_min.x)
    return (0);
  return (1);
}

void		rm_out_of_limit(double res[3], t_obj *obj, t_vect *o, t_vect *u)
{
  int		i;

  i = 0;
  while (i < 3)
    {
      if (!limit(res[i], obj, o, u))
	res[i] = -1.0;
      i++;
    }
}

int		is_min(double res[3], int i)
{
  if ((res[i] > res[0] && res[0] > 0 && i != 0)
      || (res[i] > res[1] && res[1] > 0 && i != 1)
      || (res[i] > res[2] && res[2] > 0 && i != 2))
    return (0);
  return (1);
}
