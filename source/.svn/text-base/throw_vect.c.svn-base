/*
** throw_vect.c for raytracer in /home/brissa_a//c/B2/raytracer
**
** Made by alexis brissard
** Login   <brissa_a@epitech.net>
**
** Started on  Tue Apr  5 17:14:10 2011 alexis brissard
   Last update Sat Jun  4 18:39:55 2011 mourad sabour
*/

#include	"my_printf.h"
#include	"rt.h"

double			get_k(t_obj *obj, t_vect *o,
			      t_vect *u)
{
  t_vect		tmp_o;
  t_vect		tmp_u;
  double		k;

  tmp_o = *o;
  anti_mouvement(&tmp_o, obj->move, ROT | TRANS);
  tmp_u = *u;
  anti_mouvement(&tmp_u, obj->move, ROT);
  k = obj->calc_k(&tmp_o, &tmp_u, obj);
  return (k);
}

void			save_nearest(t_obj *obj, double k, t_inter *inter)
{
  if ((inter->k > k || inter->k == -1) && k > 0)
    {
      inter->k = k;
      inter->obj = obj;
    }
}

void			fill_inter(t_vect *o, t_vect *u, t_inter *inter)
{
  t_vect		tmp_vect;

  inter->p.x = o->x + u->x * inter->k;
  inter->p.y = o->y + u->y * inter->k;
  inter->p.z = o->z + u->z * inter->k;
  tmp_vect = inter->p;
  anti_mouvement(&tmp_vect, inter->obj->move, TRANS | ROT);
  inter->obj->calc_normal(&tmp_vect, inter->obj, &inter->normal);
  mouvement(&inter->normal, inter->obj->move, ROT);
  if (get_cos_a(u, &inter->normal) > 0)
    {
      inter->normal.x *= -1.0;
      inter->normal.y *= -1.0;
      inter->normal.z *= -1.0;
    }
  if (inter->obj->tex.bump.path)
    get_bump_mapping_normal(inter);
}

void			throw_vect(t_vect *o, t_vect *u,
				   t_obj *obj_list, t_inter *inter)
{
  t_obj			*cur_obj;
  double		k;

  inter->k = -1;
  cur_obj = obj_list;
  while (cur_obj != 0)
    {
      if (!cur_obj->is_neg && cur_obj->type != O_CELL)
	{
	  k = get_k(cur_obj, o, u);
	  save_nearest(cur_obj, k, inter);
	}
      cur_obj = cur_obj->next;
    }
  if (inter->k > 0)
    {
      fill_inter(o, u, inter);
      cur_obj = cur_obj->next;
    }
  else
    {
      inter->k = -1;
      inter->obj = 0;
    }
}
