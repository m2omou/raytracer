/*
** translation.c for raytracer in /home/brissa_a//c/B2/raytracer
** 
** Made by alexis brissard
** Login   <brissa_a@epitech.net>
** 
** Started on  Sun Apr 17 17:54:18 2011 alexis brissard
** Last update Sun Apr 17 17:58:12 2011 alexis brissard
*/

#include "rt.h"

void			trans(t_vect *vect, t_vect *trans)
{
  vect->x += trans->x;
  vect->y += trans->y;
  vect->z += trans->z;
}

void			anti_trans(t_vect *vect, t_vect *trans)
{
  vect->x -= trans->x;
  vect->y -= trans->y;
  vect->z -= trans->z;
}
