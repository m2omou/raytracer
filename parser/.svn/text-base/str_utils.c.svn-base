/*
** str_utils2.c for minishell1 in /home/delas_j//c/minishell1
**
** Made by jimmy delas
** Login   <delas_j@epitech.net>
**
** Started on  Tue Dec  7 16:57:50 2010 jimmy delas
** Last update Wed May  4 15:22:00 2011 thomas wilgenbus
*/

#include <stdlib.h>
#include "rt.h"
#include "strutils.h"
#include "parser.h"
#include "my_printf.h"

char		*my_strmcat(char *s1, char *s2)
{
  char		*ret;
  int		i;
  int		j;

  if (!s1)
    return (my_strdup(s2));
  if (s2)
    {
      ret = PX(malloc((1 + my_strlen(s1) + my_strlen(s2)) * sizeof(*ret)));
      my_strcpy(ret, s1);
      i = -1;
      j = my_strlen(s1) - 1;
      while (s2[++i])
	ret[++j] = s2[i];
      ret[++j] = 0;
    }
  else
    {
      ret = PX(malloc((1 + my_strlen(s1)) * sizeof(*ret)));
      my_strcpy(ret, s1);
    }
  return (ret);
}

void		my_strcpy(char *dest, char *src)
{
  int		i;

  i = -1;
  while (++i < my_strlen(src))
    dest[i] = src[i];
  dest[i] = src[i];
}

char		*my_strdup(char *str)
{
  char		*ptr;

  if (!(ptr = PX(malloc((my_strlen(str) + 1) * sizeof(*ptr)))))
    {
      my_printf("Unable to duplicate str\n");
      exit(0);
    }
  my_strcpy(ptr, str);
  return (ptr);
}

int		is_equal(char *s1, char *s2)
{
  int		i;

  i = -1;
  while (s1[++i] && s1[i] == s2[i]);
  if (s1[i] == s2[i])
    return (1);
  return (0);
}
