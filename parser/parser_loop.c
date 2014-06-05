/*
** parser_loop.c for rt in /home/delas_j//c/rt
** 
** Made by jimmy delas
** Login   <delas_j@epitech.net>
** 
** Started on  Sun Jun  5 02:13:44 2011 jimmy delas
** Last update Sun Jun  5 02:21:12 2011 jimmy delas
*/

#include	<stdlib.h>
#include	<strings.h>
#include	"get_next_line.h"
#include	"rt.h"
#include	"parser.h"

void		add_obj_in_scene(t_scene *scene, t_obj *obj,
				 int n_line, t_obj *father)
{
  if (add_obj_scene(scene, obj, n_line, father));
  else if (obj->type == O_EYE)
    {
      if (obj->param < 1)
	obj->param = 1;
      scene->camera = obj;
    }
  else if (obj->type == O_LIGHT && scene->light)
    put_in_list(scene->light, obj);
  else if (obj->type == O_LIGHT)
    scene->light = obj;
  else if (father && !father->content)
    father->content = obj;
  else if (father)
    put_in_list(father->content, obj);
  else if (scene->objet)
    put_in_list(scene->objet, obj);
  else
    scene->objet = obj;
}

void		add_obj_in_obj(t_parser *parser, t_obj *cur_obj,
			       t_screen *screen)
{
  t_obj		*new;

  parser->father = cur_obj;
  parser->n_line++;
  new = PX(malloc(sizeof(*new)));
  bzero(new, sizeof(*new));
  reset_obj(new);
  new->add_obj = 1;
  free(parser->line);
  while ((parser->line = get_next_line(parser->fd))
	 && check_line_state(parser->line, screen) != END)
    if (is_comment(parser));
    else if (check_line_state(parser->line, screen) == START)
      add_obj_in_obj(parser, new, screen);
    else
      add_object_propertie(parser, &new, ++parser->n_line);
  if (new->add_obj)
    add_obj_in_scene(&parser->ret, new, ++parser->n_line, cur_obj);
  else
    parser->n_line++;
  parser->father = cur_obj;
  free(parser->line);
}

void		new_obj_find(t_parser *parser, t_screen *screen)
{
  parser->father = NULL;
  parser->tmp = PX(malloc(sizeof(*(parser->tmp))));
  bzero(parser->tmp, sizeof(*(parser->tmp)));
  reset_obj(parser->tmp);
  parser->tmp->add_obj = 1;
  free(parser->line);
  while ((parser->line = get_next_line(parser->fd))
	 && check_line_state(parser->line, screen) != END)
    if (is_comment(parser));
    else if (check_line_state(parser->line, screen) == START)
      add_obj_in_obj(parser, parser->tmp, screen);
    else
      add_object_propertie(parser, &parser->tmp, ++parser->n_line);
  if (parser->tmp->add_obj)
    add_obj_in_scene(&parser->ret, parser->tmp, ++parser->n_line, NULL);
  else
    parser->n_line++;
  parser->father = NULL;
}
