/*
** variable.c for rt in /home/delas_j//c/rt
**
** Made by jimmy delas
** Login   <delas_j@epitech.net>
**
** Started on  Fri Jun  3 01:57:46 2011 jimmy delas
** Last update Sun Jun  5 02:12:01 2011 jimmy delas
*/

#include <strings.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>
#include "rt.h"
#include "parser.h"
#include "get_next_line.h"
#include "my_printf.h"
#include "strutils.h"

t_variable	*add_var(t_variable *list, char *name, t_obj *obj)
{
  t_variable	*new;
  t_variable	*tmp;

  tmp = list;
  while (tmp && tmp->next && !is_equal(tmp->name, name))
    tmp = tmp->next;
  if (tmp && is_equal(tmp->name, name))
    {
      my_printf("Warning: Variable %s will be ignored because"	\
		"it is already defined.\n");
      return (list);
    }
  new = PX(malloc(sizeof(*new)));
  new->obj = obj;
  new->name = my_strdup(name);
  new->next = NULL;
  if (!tmp)
    return (new);
  tmp->next = new;
  return (list);
}

t_obj		*get_obj_var(t_variable *list, char *name)
{
  while (list)
    {
      if (is_equal(name, list->name))
	return (list->obj);
      list = list->next;
    }
  return (NULL);
}

void		fill_content_and_texture(t_obj *obj, t_obj *ret)
{
  t_obj		*tmp_cont;
  t_obj		*ret_cont;
  t_obj		*new_cont;

  if (obj->tex.color.path)
    ret->tex.color.path = my_strdup(ret->tex.color.path);
  if (obj->tex.transp.path)
    ret->tex.transp.path = my_strdup(ret->tex.transp.path);
  if (obj->tex.bump.path)
    ret->tex.bump.path = my_strdup(ret->tex.bump.path);
  tmp_cont = obj->content;
  ret_cont = NULL;
  while (tmp_cont)
    {
      new_cont = PX(malloc(sizeof(*new_cont)));
      cpy_obj(new_cont, tmp_cont);
      if (!ret_cont)
	ret->content = new_cont;
      else
	ret_cont->next = new_cont;
      ret_cont = new_cont;
      tmp_cont = tmp_cont->next;
    }
}

void		cpy_obj(t_obj *ret, t_obj *obj)
{
  t_move	*tmp_move;
  t_move	*ret_move;
  t_move	*new_move;

  *ret = *obj;
  ret->next = NULL;
  tmp_move = obj->move;
  ret_move = NULL;
  while (tmp_move)
    {
      new_move = PX(malloc(sizeof(*(new_move))));
      *(new_move) = *tmp_move;
      if (!ret_move)
	ret->move = new_move;
      else
	ret_move->next = new_move;
      ret_move = new_move;
      tmp_move = tmp_move->next;
    }
  fill_content_and_texture(obj, ret);
}

void		kill_variable(t_variable *variable)
{
  t_variable	*save;

  while (variable)
    {
      save = variable;
      variable = variable->next;
      free(save->name);
      free(save);
    }
}
