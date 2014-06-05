/*
** parser_utils.c for raytracer in /home/wilgen_t/projets/rt
**
** Made by jimmy delas
** Login   <delas_j@epitech.net>
**
** Started on  Sat Mar 12 16:58:02 2011 jimmy delas
** Last update Sun Jun  5 16:07:10 2011 mourad sabour
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <strings.h>
#include "rt.h"
#include "strutils.h"
#include "get_next_line.h"
#include "parser.h"

void            my_putnbr(int num)
{
  int           i;
  int           neg;
  char          c;

  i = 1;
  while ((num / i >= 10) ^ (num / i <= -10))
    i *= 10;
  neg = 1;
  if (num < 0)
    neg = -1;
  while (i)
    {
      c = (num / i % 10) * neg + '0';
      if (X(write(1, &c, 1)) == -1)
        {
          X(write(2, "Write error\n", my_strlen("Write error\n")));
          exit(0);
        }
      i /= 10;
    }
}

int		is_dim(char *line, t_screen *screen)
{
  char		*word;
  int		i;

  i = -1;
  if ((word = get_next_word(line, &i)) && is_equal(word, "screen_dim"))
    {
      free(word);
      if ((word = get_next_word(line, &i)))
	screen->width = my_getcolor(word, -1);
      free(word);
      if ((word = get_next_word(line, &i)))
	screen->height = my_getcolor(word, -1);
      free(word);
      return (1);
    }
  free(word);
  return (0);
}

void		reset_perlin(t_obj *mal)
{
  mal->tex.perlin.perlin_pas = 128;
  mal->tex.perlin.perlin_persistance = 0.5;
  mal->tex.perlin.c1.all = 0xFF0000;
  mal->tex.perlin.c2.all = 0x00FF00;
  mal->tex.perlin.c3.all = 0x0000FF;
  mal->tex.perlin.s1 = -0.5;
  mal->tex.perlin.s2 = 0.2;
  mal->tex.perlin.s3 = 0.5;
  mal->tex.perlin.perlin_kind = 0;
}

void		reset_obj(t_obj *mal)
{
  mal->type = O_NULL;
  mal->move = PX(malloc(sizeof(*(mal->move))));
  bzero(mal->move, sizeof(*(mal->move)));
  mal->lim_min.x = -10000000;
  mal->lim_min.y = -10000000;
  mal->lim_min.z = -10000000;
  mal->lim_max.x = 10000000;
  mal->lim_max.y = 10000000;
  mal->lim_max.z = 10000000;
  mal->refrac = 1;
  mal->tex.color.x_rep = 1;
  mal->tex.color.y_rep = 1;
  mal->tex.transp.x_rep = 1;
  mal->tex.transp.y_rep = 1;
  mal->tex.bump.x_rep = 1;
  mal->tex.bump.y_rep = 1;
  reset_perlin(mal);
  mal->color_fog = 0xFFFFFF;
  mal->param = 1;
  mal->focus = 0;
  mal->focus_speed = 1.0;
}
