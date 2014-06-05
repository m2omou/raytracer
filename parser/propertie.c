/*
** propertie.c for rtv1 in /home/delas_j//c/rtv1
**
** Made by jimmy delas
** Login   <delas_j@epitech.net>
**
** Started on  Fri Feb 25 00:56:18 2011 jimmy delas
** Last update Sun Jun  5 18:28:21 2011 thomas wilgenbus
*/

#include <stdlib.h>
#include "rt.h"
#include "strutils.h"
#include "get_next_line.h"
#include "parser.h"
#include "my_printf.h"

void		warn(char *message, int line)
{
  my_printf("Warning line %d: %s\n", line, message);
}

void		check_type(char *value, int n_line,
			   t_obj *obj, t_parser *parser)
{
  static t_type type[NB_OBJ + NB_SPE_OBJ] = {
    {"plan", O_PLAN}, {"eye", O_EYE}, {"sphere", O_SPHERE},
    {"cone", O_CONE}, {"light", O_LIGHT}, {"cylinder", O_CYLINDER},
    {"mobus", O_MOBUS}, {"cell", O_CELL}
  };
  t_obj		*var;
  int		i;
  int		found;

  i = -1;
  found = 0;
  while (++i < NB_OBJ + NB_SPE_OBJ)
    if (is_equal(value, type[i].name))
      {
	found = 1;
	obj->type = type[i].num;
      }
  if (!found && (var = get_obj_var(parser->var, value)))
    cpy_obj(obj, var);
  else if (!found)
    {
      my_printf("Error line %d: Unknow value %s\n", n_line, value);
      exit(0);
    }
}

int		add_propertie1(char *var, char *value, t_obj *obj, int n_line)
{
  if (is_equal(var, "color"))
    obj->color.all = my_getcolor(value, -1);
  else if (is_equal(var, "param"))
    obj->param = get_nbr_float(value);
  else if (get_light(var, value, obj))
    return (1);
  else if (get_position_rotation(var, value, obj))
    return (1);
  else if (get_limit(var, value, obj))
    return (1);
  else if (add_propertie3(var, value, obj, n_line))
    return (1);
  else if (get_perlin(var, value, obj, n_line))
    return (1);
  else if (add_propertie2(var, value, obj, n_line))
    return (1);
  else if (perlin_utils(var, value, obj, n_line))
    return (1);
  else
    return (0);
  return (1);
}

t_obj		*get_reference(t_obj *obj, char *value, t_obj *content)
{
  t_obj		*tmp;

  tmp = content;
  while (tmp && !(tmp->content_name && is_equal(tmp->content_name, value)))
    tmp = tmp->next;
  if (!tmp)
    return (obj);
  delete_obj(obj);
  tmp->add_obj = 0;
  return (tmp);
}

void		add_object_propertie(t_parser *parser, t_obj **obj, int n_line)
{
  char		*var;
  char		*value;
  int		i;

  i = -1;
  if (!(var = get_next_word(parser->line, &i)))
    return ;
  if (!(value = get_next_word(parser->line, &i)))
    {
      my_printf("Syntax error line %d: Missing value\n", n_line);
      exit(0);
    }
  if (is_equal(var, "type"))
    check_type(value, n_line, *obj, parser);
  else if (is_equal("name", var))
    parser->var = add_var(parser->var, value, *obj);
  else if (add_propertie1(var, value, *obj, n_line));
  else if (get_special_var(var, value, obj, parser));
  else
    my_printf("Warning line %d: Unknow type '%s'\n", n_line, var);
  free(var);
  free(value);
  free(parser->line);
}
