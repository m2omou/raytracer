/*
** get_next_line.c for get_next_line in /home/delas_j//c/get_next_line
**
** Made by jimmy delas
** Login   <delas_j@epitech.net>
**
** Started on  Mon Nov  8 18:13:47 2010 jimmy delas
** Last update Sat Jun  4 12:44:15 2011 thomas wilgenbus
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include "strutils.h"
#include "rt.h"
#include "parser.h"

char		*my_str_realloc(char *old, int size, int is_malloc)
{
  int		i;
  char		*new;

  new = PX(malloc(size * sizeof(*new)));
  i = -1;
  if (is_malloc)
    {
      while (++i < size - BUFFER_SIZE)
	new[i] = old[i];
      free(old);
    }
  return (new);
}

void		load_buf(int fd, int *buf_i, int *was_read, void *buffer)
{
  if (*buf_i == *was_read)
    {
      *was_read = X(read(fd, buffer, BUFFER_SIZE));
      *buf_i = 0;
    }
}

char		*get_next_line(const int fd)
{
  static char	buffer[BUFFER_SIZE];
  static int	buf_i = 0;
  static int	was_read = 0;
  char		*ret;
  int		i;
  int		it;

  it = 0;
  i = 0;
  ret = NULL;
  while ((buf_i == was_read && was_read) || !ret)
    {
      load_buf(fd, &buf_i, &was_read, buffer);
      if (!ret && ((!was_read && fd) || was_read == -1))
	return (NULL);
      ret = my_str_realloc(ret, (it + 1) * BUFFER_SIZE, it);
      it++;
      while (buffer[buf_i] != '\n' && buf_i < was_read)
	ret[i++] = buffer[buf_i++];
    }
  if (!was_read && !i)
    return (NULL);
  ret[i] = 0;
  BUFF_INCR(buf_i, was_read);
  return (ret);
}

void		add_char(char **str, char c)
{
  char		*tmp;
  char		tinybuff[2];

  tinybuff[1] = 0;
  tinybuff[0] = c;
  tmp = *str;
  *str = my_strmcat(*str, tinybuff);
  free(tmp);
}

char		*get_next_word(char *str, int *i)
{
  int		j;
  char		*ret;
  int		is_quote;

  is_quote = 0;
  j = -1;
  ret = NULL;
  while (str[++(*i)] && (str[*i] == ' ' || str[*i] == '\t' || str[*i] == ':'));
  while (str[*i] && ((str[*i] != ' ' && str[*i] != '\t' && str[*i] != ':')
		     || is_quote))
    {
      if ((str[*i] == '\'' || str[*i] == '"')
	  && (!(*i) || str[*i - 1] != '\\'))
	is_quote ^= 1;
      else
	add_char(&ret, str[*i]);
      (*i)++;
    }
  (*i)--;
  return (ret);
}
