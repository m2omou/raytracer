/*
** obj_utils.c for raytracer in /home/wilgen_t/projets/rt
**
** Made by thomas wilgenbus
** Login   <wilgen_t@epitech.net>
**
** Started on  Sun Jun  5 00:37:43 2011 thomas wilgenbus
** Last update Sun Jun  5 02:12:44 2011 jimmy delas
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

int		add_obj_scene(t_scene *scene, t_obj *obj,
			      int n_line, t_obj *father)
{
  if (obj->type == O_NULL && !obj->content)
    {
      warn("Object will be ignored because type is missing", n_line);
      delete_obj(obj);
    }
  else if (father && father->type != O_NULL)
    {
      warn("Complex object will be ignored because father have a type.",
	   n_line);
      delete_obj(obj);
    }
  else if (obj->type == O_EYE && (scene->camera || father))
    {
      warn("Eye redefined", n_line);
      delete_obj(obj);
    }
  else if (obj->type == O_LIGHT && father)
    {
      warn("Light will be ignored", n_line);
      delete_obj(obj);
    }
  else
    return (0);
  return (1);
}
