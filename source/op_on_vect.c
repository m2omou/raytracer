/*
** op_on_vect.c for rt.h in
**
** Made by alexis brissard
** Login   <brissa_a@epitech.net>
**
** Started on  Sun May  8 17:22:28 2011 alexis brissard
** Last update Wed Jun  1 18:53:55 2011 thomas wilgenbus
*/

#include "rt.h"

double		norme(t_vect *vect)
{
  return (sqrt(vect->x * vect->x + vect->y * vect->y + vect->z * vect->z));
}

double		scal(t_vect *vect1, t_vect *vect2)
{
  return (vect1->x * vect2->x + vect1->y * vect2->y + vect1->z * vect2->z);
}

void		create_light_vect(t_vect *l_vect, t_vect *l_pos,
				  t_vect *p_pos, t_obj *light)
{
  if (!light->is_paral)
    {
      l_vect->x = l_pos->x - p_pos->x;
      l_vect->y = l_pos->y - p_pos->y;
      l_vect->z = l_pos->z - p_pos->z;
    }
  else
    {
      l_vect->x = -light->move->pos.x;
      l_vect->y = -light->move->pos.y;
      l_vect->z = -light->move->pos.z;
    }
}

double		get_cos_a(t_vect *vect1, t_vect *vect2)
{
  double	scal_v;
  double	n;
  double	l;

  n = norme(vect1);
  l = norme(vect2);
  scal_v = scal(vect1, vect2);
  return (scal_v / (n * l));
}
