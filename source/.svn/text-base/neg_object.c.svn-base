/*
** neg_object.c for raytracer in /home/wilgen_t/projets/rt
**
** Made by thomas wilgenbus
** Login   <wilgen_t@epitech.net>
**
** Started on  Thu Jun  2 19:09:36 2011 thomas wilgenbus
** Last update Sun Jun  5 13:10:50 2011 thomas wilgenbus
*/

#include	"rt.h"

int			check_neg_limit(t_vect *p, t_obj *obj)
{
  t_vect		tmp_p;

  tmp_p = *p;
  if (tmp_p.x > obj->lim_max.x || tmp_p.y > obj->lim_max.y ||
      tmp_p.z > obj->lim_max.z ||
      tmp_p.x < obj->lim_min.x || tmp_p.y < obj->lim_min.y ||
      tmp_p.z < obj->lim_min.z)
    return (0);
  else
    return (1);
}

int		is_in_neg_object(t_vect *p, t_obj *obj, t_obj *ptr)
{
  static t_obj	*obj_list = NULL;
  t_obj		*cur_obj;
  t_vect	tmp_p;

  if (!obj_list)
    {
      obj_list = ptr;
      return (0);
    }
  mouvement(p, obj->move, ROT | TRANS);
  obj = obj;
  cur_obj = obj_list;
  while (cur_obj)
    {
      if (cur_obj->is_neg && cur_obj->calc_neg)
	{
	  tmp_p = *p;
	  anti_mouvement(&tmp_p, cur_obj->move, ROT | TRANS);
	  if (check_neg_limit(&tmp_p, cur_obj) &&
	      cur_obj->calc_neg(&tmp_p, cur_obj))
	    return (1);
	}
      cur_obj = cur_obj->next;
    }
  return (0);
}
