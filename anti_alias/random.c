/*
** random.c for raytracer in /home/wilgen_t/projets/rt
**
** Made by thomas wilgenbus
** Login   <wilgen_t@epitech.net>
**
** Started on  Fri Jun  3 20:37:46 2011 thomas wilgenbus
** Last update Fri Jun  3 20:38:45 2011 thomas wilgenbus
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"struct.h"
#include	"anti_alias.h"
#include	"parser.h"
#include	"rt.h"

int		get_rand(int num)
{
  static int	randm[2] = {0, 0};
  static int	first = 1;

  if (first)
    {
      randm[0] = rand();
      randm[1] = rand();
    }
  first = 0;
  return (randm[num]);
}

