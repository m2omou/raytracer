/*
** properties_utils.c for raytracer in /home/wilgen_t/projets/rt
**
** Made by thomas wilgenbus
** Login   <wilgen_t@epitech.net>
**
** Started on  Sat Jun  4 22:59:45 2011 thomas wilgenbus
** Last update Sun Jun  5 18:27:37 2011 thomas wilgenbus
*/

#include <stdlib.h>
#include "rt.h"
#include "strutils.h"
#include "parser.h"
#include "my_printf.h"

int		get_light(char *var, char *value,
			  t_obj *obj)
{
  if (is_equal(var, "is-paral"))
    obj->is_paral = get_nbr_float(value);
  else if (is_equal(var, "halo"))
    obj->halo = get_nbr_float(value);
  else if (is_equal(var, "AA"))
    obj->anti_alias = get_nbr_float(value);
  else if (is_equal(var, "is-neg"))
    obj->is_neg = get_nbr_float(value);
  else if (is_equal(var, "content_name"))
    obj->content_name = my_strdup(value);
  else
    return (0);
  return (1);
}

int		get_perlin(char *var, char *value,
			   t_obj *obj, int n_line)
{
  if (is_equal(var, "perlin_s1"))
    obj->tex.perlin.s1 = get_nbr_float(value);
  else if (is_equal(var, "perlin-s2"))
    obj->tex.perlin.s2 = get_nbr_float(value);
  else if (is_equal(var, "perlin-s3"))
    obj->tex.perlin.s3 = get_nbr_float(value);
  else if (is_equal(var, "perlin-octaves"))
    {
      if ((obj->tex.perlin.perlin_octaves = get_nbr_float(value)) < 0)
	warn("Perlin_octave value may be greater than 0\n", n_line);
    }
  else if (is_equal(var, "perlin-pas"))
    {
      if ((obj->tex.perlin.perlin_pas = get_nbr_float(value)) < 0)
	warn("Perlin_pas value may be greater than 0\n", n_line);
    }
  else if (is_equal(var, "perlin-persistance"))
    {
      if ((obj->tex.perlin.perlin_persistance = get_nbr_float(value)) < 0)
	warn("Perlin_persistance value may be greater than 0\n", n_line);
    }
  else
    return (0);
  return (1);
}

int		perlin_utils(char *var, char *value, t_obj *obj, int n_line)
{
  if (is_equal(var, "perlin-kind"))
    {
      if ((obj->tex.perlin.perlin_kind = get_nbr_float(value)) < 0)
	warn("perlin_kind value may be only between 0 and 2\n", n_line);
    }
  if (is_equal(var, "perlin-c1"))
    obj->tex.perlin.c1.all = my_getcolor(value, -1);
  else if (is_equal(var, "perlin-c2"))
    obj->tex.perlin.c2.all = my_getcolor(value, -1);
  else if (is_equal(var, "perlin-c3"))
    obj->tex.perlin.c3.all = my_getcolor(value, -1);
  else if (is_equal(var, "ints-bump"))
    {
      if ((obj->tex.bump.ints_bump = get_nbr_float(value)) < 0)
	warn("Ints_bump value may be greater than 0\n", n_line);
    }
  else if (get_tex_repetition(var, value, obj))
    return (1);
  else
    return (0);
  return (1);
}

int		get_special_var(char *var, char *value,
				t_obj **obj, t_parser *parser)
{
  if (is_equal("content_type", var))
    {
      if (parser->father)
	*obj = get_reference(*obj, value, parser->father->content);
      else
	my_printf("Warning line %d: context is not a subcontent\n");
    }
  else
    return (0);
  return (1);
}

int		add_propertie2(char *var, char *value, t_obj *obj, int n_line)
{
  if (is_equal(var, "refrac"))
    {
      if ((obj->refrac = get_nbr_float(value)) < 0)
	warn("Absorption value may be greater than 0\n", n_line);
    }
  else if (is_equal(var, "ints-bump"))
    {
      if ((obj->tex.bump.ints_bump = get_nbr_float(value)) < 0)
	warn("Ints_bump value may be greater than 0\n", n_line);
    }
  else if (is_equal(var, "focus"))
    {
      if ((obj->focus = get_nbr_float(value)) < 0)
        warn("Focus value may be greater than 0\n", n_line);
    }
  else if (is_equal(var, "focus-speed"))
    {
      if ((obj->focus_speed = get_nbr_float(value)) < 0)
        warn("Focus-speed value may be greater than 0\n", n_line);
    }
  else
    return (0);
  return (1);
}
