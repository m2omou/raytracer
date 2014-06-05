/*
** object_utils.c for rt in /home/brissa_a//c/B2/rt
**
** Made by alexis brissard
** Login   <brissa_a@epitech.net>
**
** Started on  Tue May 24 15:21:11 2011 alexis brissard
** Last update Sat Jun  4 16:02:14 2011 alexis brissard
*/

#include "rt.h"

int			check_limit(t_vect *o, t_vect *u, double k, t_obj *obj)
{
  t_vect		tmp_p;

  tmp_p.x = o->x + u->x * k;
  tmp_p.y = o->y + u->y * k;
  tmp_p.z = o->z + u->z * k;
  if (tmp_p.x > obj->lim_max.x || tmp_p.y > obj->lim_max.y ||
      tmp_p.z > obj->lim_max.z ||
      tmp_p.x < obj->lim_min.x || tmp_p.y < obj->lim_min.y ||
      tmp_p.z < obj->lim_min.z || is_in_neg_object(&tmp_p, obj, NULL))
    return (0);
  else
    return (1);
}

double		res_eq_sc(t_vect *tmp, double *x1, double *x2)
{
  double	delta;

  delta = tmp->y * tmp->y - 4 * tmp->x * tmp->z;
  if (delta > 0)
    {
      *x1 = (-1 * tmp->y - sqrt(delta)) / (2 * tmp->x);
      *x2 = (-1 * tmp->y + sqrt(delta)) / (2 * tmp->x);
      return (2);
    }
  else
    return (0);
}

void		treat_equal_zero(double *coef, double *res, double p, double q)
{
  if (IS_ZERO(p))
    {
      res[0] = -2 * sqrt(-p / 3.0) - coef[2] / (3 * coef[3]);
      res[1] = sqrt(-p / 3) - coef[2] / (3 * coef[3]);
      res[2] = -1.0;
    }
  else
    {
      res[0] = (3 * q) / p - coef[2] / (3 * coef[3]);
      res[1] = (-3 * q) / (2 * p) - coef[2] / (3 * coef[3]);
      res[2] = -1.0;
    }
}

void		res_eq_tr(double *coef, double *res)
{
  double	delta;
  double	p;
  double	q;
  int		i;

  p = (coef[1] / coef[3]) - pow(coef[2], 2.0) / (3.0 * pow(coef[3], 2.0));
  q = (coef[2] / (27 * coef[3])) * (2.0 * pow(coef[2], 2.0) / pow(coef[3], 2.0)
				- 9.0 * coef[1] / coef[3]) + coef[0] / coef[3];
  delta = pow(q, 2.0) / 4.0 + pow(p, 3.0) / 27;
  i = -1;
  if (delta > 0)
    {
      res[0] = cbrt(-q / 2 + sqrt(delta)) + cbrt(-q / 2 - sqrt(delta))
	- coef[2] / (3 * coef[3]);
      res[1] = -1.0;
      res[2] = -1.0;
    }
  else if (delta == 0)
    treat_equal_zero(coef, res, p, q);
  else if (delta < 0)
    while (++i < 3)
      res[i] = 2.0 * sqrt(-p / 3.0) *
	cos((1.0 / 3.0) * acos((-q / 2.0) * sqrt(27.0 / pow(-p, 3.0)))
	    + (2.0 * i * PI) / 3.0) - coef[2] / (3.0 * coef[3]);
}
