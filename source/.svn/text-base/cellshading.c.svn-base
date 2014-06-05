/*
** cellshading.c for rt in /home/despuj_a//final/rt/rt
**
** Made by adrien despujol
** Login   <despuj_a@epitech.net>
**
** Started on  Mon May 23 16:45:46 2011 adrien despujol
** Last update Sat Jun  4 17:03:10 2011 adrien despujol
*/

#include		"rt.h"

int			coeff_cell(int cur, double cosa, t_scene *scene)
{
  int red;
  int green;
  int blue;
  double mult;

  red = cur / (256 * 256);
  green = cur / 256 % 256;
  blue = cur % 256;
  mult = find_mult_cell(cosa, scene);
  red = floor(red * mult);
  blue = floor(blue * mult);
  green = floor(green * mult);
  cur = red * 256 * 256 + green * 256 + blue;
  return (cur);
}

double			find_mult_cell(double cosa, t_scene *scene)
{
  t_cell *start;

  start = scene->cell;
  while (start)
    {
      if (start->cosa <= cosa)
	return (start->gradient);
      start = start->next;
    }
  return (1.0);
}

void			separ_cell(t_scene *scene)
{
  t_obj *start;
  t_obj *previous;

  previous = 0;
  start = scene->objet;
  while (start)
    {
      if (start->type == O_CELL)
	{
	  add_cell(&scene->cell, start->gloss, start->param);
	  if (previous)
	    {
	      previous->next = start->next;
	      if (start->next == 0)
	  	return;
	    }
	  else
	    scene->objet = scene->objet->next;
	}
      if (start->next && start->next->type != O_CELL)
      	previous = start;
      start = start->next;
    }
  return;
}

void			add_cell(t_cell **root, double gradient, double cosa)
{
  t_cell *res;

  res = PX(malloc(sizeof(*res)));
  res->cosa = cosa;
  res->gradient = gradient;
  res->next = *root;
  *root = res;
}

double			last_gradient(t_scene *s)
{
  t_cell *start;

  start = s->cell;
  while (start)
    {
      if (start->next == 0)
	return (start->gradient);
      start = start->next;
    }
  return (0);
}
