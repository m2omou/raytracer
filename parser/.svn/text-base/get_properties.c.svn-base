/*
** get_properties.c for raytracer in /home/wilgen_t/projets/rt
**
** Made by thomas wilgenbus
** Login   <wilgen_t@epitech.net>
**
** Started on  Sat Jun  4 18:45:43 2011 thomas wilgenbus
** Last update Sun Jun  5 18:27:01 2011 thomas wilgenbus
*/

#include "strutils.h"
#include "parser.h"
#include "rt.h"

int		get_tex_repetition(char *var, char *value, t_obj *obj)
{
  if (is_equal(var, "x-rep-tex"))
    obj->tex.color.x_rep = get_nbr_float(value);
  else if (is_equal(var, "y-rep-tex"))
    obj->tex.color.y_rep = get_nbr_float(value);
  else if (is_equal(var, "tex-path"))
    obj->tex.color.path = my_strdup(value);
  else if (is_equal(var, "transp-path"))
    obj->tex.transp.path = my_strdup(value);
  else if (is_equal(var, "x-rep-transp"))
    obj->tex.transp.x_rep = get_nbr_float(value);
  else if (is_equal(var, "y-rep-transp"))
    obj->tex.transp.y_rep = get_nbr_float(value);
  else if (is_equal(var, "bump-path"))
    obj->tex.bump.path = my_strdup(value);
  else if (is_equal(var, "x-rep-bump"))
    obj->tex.bump.x_rep = get_nbr_float(value);
  else if (is_equal(var, "y-rep-bump"))
    obj->tex.bump.y_rep = get_nbr_float(value);
  else
    return (0);
 return (1);
}

int		get_position_rotation(char *var, char *value, t_obj *obj)
{
  if (is_equal(var, "x"))
    obj->move->pos.x = get_nbr_float(value);
  else if (is_equal(var, "y"))
    obj->move->pos.y = get_nbr_float(value);
  else if (is_equal(var, "z"))
    obj->move->pos.z = get_nbr_float(value);
  else if (is_equal(var, "rx"))
    obj->move->rot.x = get_nbr_float(value) * PI / 180.0;
  else if (is_equal(var, "ry"))
    obj->move->rot.y = get_nbr_float(value) * PI / 180.0;
  else if (is_equal(var, "rz"))
    obj->move->rot.z = get_nbr_float(value) * PI / 180.0;
  else
    return (0);
  return (1);
}

int		get_limit(char *var, char *value, t_obj *obj)
{
  if (is_equal(var, "lim-min-x"))
    obj->lim_min.x = get_nbr_float(value);
  else if (is_equal(var, "lim-min-y"))
    obj->lim_min.y = get_nbr_float(value);
  else if (is_equal(var, "lim-min-z"))
    obj->lim_min.z = get_nbr_float(value);
  else if (is_equal(var, "lim-max-x"))
    obj->lim_max.x = get_nbr_float(value);
  else if (is_equal(var, "lim-max-y"))
    obj->lim_max.y = get_nbr_float(value);
  else if (is_equal(var, "lim-max-z"))
    obj->lim_max.z = get_nbr_float(value);
  else
    return (0);
  return (1);
}

int		add_propertie3(char *var, char *value,
			       t_obj *obj, int n_line)
{
  if (is_equal(var, "gloss"))
    {
      if ((obj->gloss = get_nbr_float(value)) < 0 || obj->gloss > 1)
	warn("Gloss value may be between 0 and 1\n", n_line);
    }
  else if (is_equal(var, "transp"))
    {
      if ((obj->transp = get_nbr_float(value)) < 0 || obj->transp > 1)
	warn("Transparence value may be between 0 and 1\n", n_line);
    }
  else if (is_equal(var, "reflex"))
    {
      if ((obj->reflex = get_nbr_float(value)) < 0 || obj->reflex > 1)
	warn("Reflexion value may be between 0 and 1\n", n_line);
    }
  else if (is_equal(var, "absorb"))
    {
      if ((obj->absorb = get_nbr_float(value)) < 0 || obj->absorb > 1)
	warn("Absorption value may be between 0 and 1\n", n_line);
    }
  else
    return (0);
  return (1);
}
