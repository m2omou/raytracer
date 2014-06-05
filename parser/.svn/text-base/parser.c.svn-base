/*
** parser.c for rtv1 in /home/delas_j//c/rtv1/parser
**
** Made by jimmy delas
** Login   <delas_j@epitech.net>
**
** Started on  Thu Feb 24 23:38:54 2011 jimmy delas
** Last update Sun Jun  5 02:21:42 2011 jimmy delas
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

int		is_comment(t_parser *parser)
{
  int		i;

  i = -1;
  while (parser->line[++i])
    {
      if (parser->line[i] == '/' && parser->line[i + 1] == '*')
	return (parser->comment = 1);
      else if (parser->line[i] == '*' && parser->line[i + 1] == '/')
	return ((parser->comment = 0) ^ 1);
    }
  return (parser->comment);
}

int		check_line_state(char *line, t_screen *screen)
{
  int		i;
  int		type;

  if (is_dim(line, screen))
    return (0);
  i = -1;
  type = 0;
  while (line[++i])
    {
      if (line[i] == '{' && !type)
	type = START;
      else if (line[i] == '}' && !type)
	type = END;
      else if (line[i] != ' ' && line[i] != '\t')
	return (0);
    }
  return (type);
}

void		put_in_list(t_obj *list, t_obj *elem)
{
  t_obj		*tmp;

  tmp = list;
  while (tmp->next)
    tmp = tmp->next;
  tmp->next = elem;
}

void		init_parser(t_parser *parser, t_screen *screen)
{
  parser->n_line = 0;
  parser->ret.camera = NULL;
  parser->ret.objet = NULL;
  parser->ret.light = NULL;
  parser->tmp = NULL;
  parser->var = NULL;
  parser->comment = 0;
  screen->width = 800;
  screen->height = 600;
}

t_scene		load_scene(const char *path, t_screen *screen)
{
  t_parser	parser;

  init_parser(&parser, screen);
  if ((parser.fd = open(path, O_RDONLY)) == -1)
    return (parser.ret);
  while ((parser.line = get_next_line(parser.fd)) && (++parser.n_line || 1))
    {
      if (!is_comment(&parser)
	  && check_line_state(parser.line, screen) == START)
	new_obj_find(&parser, screen);
      free(parser.line);
    }
  kill_variable(parser.var);
  X(close(parser.fd));
  return (parser.ret);
}
