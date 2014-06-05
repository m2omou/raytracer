/*
** display_error.c for raytracer in /home/wilgen_t/projets/raytracer/utils
**
** Made by thomas wilgenbus
** Login   <wilgen_t@epitech.net>
**
** Started on  Thu Apr  7 10:09:23 2011 thomas wilgenbus
** Last update Fri Jun  3 15:43:03 2011 thomas wilgenbus
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "utils.h"

int		xcall(int ret, char *error)
{
  if (ret == -1)
    {
      fprintf(stderr, "error : %s\n", error);
      exit(EXIT_FAILURE);
    }
  return (ret);
}

int		x0call(int ret, char *error)
{
  if (ret == 0)
    {
      fprintf(stderr, "error : %s\n", error);
      exit(EXIT_FAILURE);
    }
  return (ret);
}

void		*pxcall(void *ret, char *error)
{
  if (ret == NULL)
    {
      fprintf(stderr, "error : %s\n", error);
      exit(EXIT_FAILURE);
    }
  return (ret);
}
