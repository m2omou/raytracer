/*
** mouvement.c for raytracer in /home/wilgen_t/projets/rt
**
** Made by thomas wilgenbus
** Login   <wilgen_t@epitech.net>
**
** Started on  Thu Jun  2 12:26:09 2011 thomas wilgenbus
** Last update Sun Jun  5 13:22:25 2011 thomas wilgenbus
*/

#include	"rt.h"

void			anti_mouvement(t_vect *pt, t_move *move, int mode)
{
  if (mode & TRANS)
    anti_trans(pt, &move->pos);
  if (mode & ROT)
    anti_rot(pt, &move->rot);
  if (move && move->next)
    anti_mouvement(pt, move->next, mode);
}

void			mouvement(t_vect *pt, t_move *move, int mode)
{
  if (move && move->next)
    mouvement(pt, move->next, mode);
  if (mode & ROT)
    rot(pt, &move->rot);
  if (mode & TRANS)
    trans(pt, &move->pos);
}
