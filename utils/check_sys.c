/*
** check_sys.c for raytracer in /home/wilgen_t/projets/raytracer/utils
**
** Made by thomas wilgenbus
** Login   <wilgen_t@epitech.net>
**
** Started on  Thu Apr  7 10:01:59 2011 thomas wilgenbus
** Last update Tue May 31 12:10:32 2011 thomas wilgenbus
*/

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void		*xmalloc(int size)
{
  void		*new;

  if ((new = malloc(size)) == NULL)
    {
      fprintf(stderr, "malloc error : processus aborted\n");
      exit(EXIT_FAILURE);
    }
  return (new);

}
