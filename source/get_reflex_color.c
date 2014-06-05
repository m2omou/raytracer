/*
** get_reflex_color.c for rt in 
** 
** Made by alexis brissard
** Login   <brissa_a@epitech.net>
** 
** Started on  Sun May  8 16:26:47 2011 alexis brissard
** Last update Wed Jun  1 09:42:55 2011 alexis brissard
*/

#include "rt.h"

void		create_reflex_vect(t_vect *r, t_vect *n, t_vect *u)
{
  double	scal_v;

  scal_v = get_cos_a(u, n);
  r->x = (u->x / norme (u)) - 2.0 * (n->x / norme(n)) * scal_v;
  r->y = (u->y / norme (u)) - 2.0 * (n->y / norme(n)) * scal_v;
  r->z = (u->z / norme (u)) - 2.0 * (n->z / norme(n)) * scal_v;
}

int		get_reflex_color(t_inter *inter, t_scene *scene, t_vect *u, int i)
{
  int		rc;
  t_vect	reflex_v;

  create_reflex_vect(&reflex_v, &inter->normal, u);
  rc = get_vect_color(&inter->p, &reflex_v, scene, i + 1);
  return (rc);
}
