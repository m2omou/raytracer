/*
** complex.c for rt in /home/delas_j//c/rt
**
** Made by jimmy delas
** Login   <delas_j@epitech.net>
**
** Started on  Tue May 31 22:18:41 2011 jimmy delas
** Last update Sun Jun  5 13:19:28 2011 thomas wilgenbus
*/

#include	<signal.h>
#include	<stdlib.h>
#include	"rt.h"
#include	"bmp.h"
#include	"parser.h"
#include	"network.h"

void		mix_tree(t_obj *father, t_obj *child)
{
  add_mouvement(&child->move, &father->move->pos, &father->move->rot);
  if (child->lim_min.x < father->lim_min.x)
    child->lim_min.x = father->lim_min.x;
  if (child->lim_min.y < father->lim_min.y)
    child->lim_min.y = father->lim_min.y;
  if (child->lim_min.z < father->lim_min.z)
    child->lim_min.z = father->lim_min.z;
  if (child->lim_max.x > father->lim_max.x)
    child->lim_max.x = father->lim_max.x;
  if (child->lim_max.y > father->lim_max.y)
    child->lim_max.y = father->lim_max.y;
  if (child->lim_max.z > father->lim_max.z)
    child->lim_max.z = father->lim_max.z;
  if ((child->reflex += father->reflex) > 1)
    child->reflex = 1;
  if ((child->gloss += father->gloss) > 1)
    child->gloss = 1;
  if ((child->transp += father->transp) > 1)
    child->transp = 1;
  if ((child->refrac += father->refrac) > 1)
    child->refrac = 1;
  if (father->absorb)
    child->absorb = 1;
  if (father->is_neg)
    child->is_neg = father->is_neg;
}

int		resolve_obj(t_obj **tmp, t_obj **prev, t_obj **orig,
			    t_scene *scene)
{
  if ((*tmp)->content && (*tmp)->content->type != O_NULL)
    {
      mix_tree(*tmp, (*tmp)->content);
      put_in_list(*tmp, (*tmp)->content);
      *prev = (*tmp)->content;
      (*tmp)->content = (*tmp)->content->next;
      (*prev)->next = NULL;
      return (0);
    }
  else if (!((*tmp)->content) && (*tmp)->type == O_NULL)
    {
      if (*prev)
	(*prev)->next = (*tmp)->next;
      else if (orig)
	*orig = (*tmp)->next;
      else if (scene->objet)
	scene->objet = (*tmp)->next;
      *prev = *tmp;
      *tmp = (*tmp)->next;
      free(*prev);
      return (0);
    }
  return (1);
}

int		resolve_scene_tree(t_scene *scene, t_obj **orig, int n)
{
  t_obj		*tmp;
  int		done;
  t_obj		*prev;

  done = 0;
  while (!done)
    {
      tmp = SET_TMP(orig, scene->objet);
      prev = NULL;
      done = 1;
      while (tmp)
	{
	  if (!resolve_obj(&tmp, &prev, orig, scene))
	    done = 0;
	  else if (tmp->content)
	    done = resolve_scene_tree(scene, &tmp->content, n);
	  if (tmp)
	    {
	      prev = tmp;
	      tmp = tmp->next;
	    }
	}
    }
  return (0);
}
