/*
** list_utils.c for parser in /home/wilgen_t/projets/rt
**
** Made by thomas wilgenbus
** Login   <wilgen_t@epitech.net>
**
** Started on  Wed Jun  1 16:26:46 2011 thomas wilgenbus
** Last update Thu Jun  2 13:32:47 2011 alexis brissard
*/

#include <stdlib.h>
#include "struct.h"
#include "rt.h"

void			delete_obj(t_obj *obj)
{
  free(obj->move);
  free(obj->tex.color.path);
  free(obj->tex.transp.path);
  free(obj->tex.bump.path);
}

void			add_mouvement(t_move **mvt_list, t_vect *pos,
				      t_vect *rot)
{
  t_move		*new;

  new = PX(malloc(sizeof(*new)));
  new->pos = *pos;
  new->rot = *rot;
  new->next = *mvt_list;
  *mvt_list = new;
}
