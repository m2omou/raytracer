/*
** transformation.c for raytracer in /home/brissa_a//c/B2/raytracer
**
** Made by alexis brissard
** Login   <brissa_a@epitech.net>
**
** Started on  Sun Apr 17 15:16:17 2011 alexis brissard
   Last update Thu Jun  2 11:41:51 2011 thomas wilgenbus
*/

#include "rt.h"

void		rx(t_vect *vect, double x)
{
  t_vect	tmp;

  tmp.x = vect->x;
  tmp.y = vect->y * cos(x) - vect->z * sin(x);
  tmp.z = vect->y * sin(x) + vect->z * cos(x);
  *vect = tmp;
}

void		ry(t_vect *vect, double y)
{
  t_vect	tmp;

  tmp.x = vect->x * cos(y) + vect->z * sin(y);
  tmp.y = vect->y;
  tmp.z = vect->x * -sin(y) + vect->z * cos(y);
  *vect = tmp;
}

void		rz(t_vect *vect, double z)
{
  t_vect	tmp;

  tmp.x = vect->x * cos(z) - vect->y * sin(z);
  tmp.y = vect->x * sin(z) + vect->y * cos(z);
  tmp.z = vect->z;
  *vect = tmp;
}

void		rot(t_vect *vect, t_vect *angle)
{
  rx(vect, angle->x);
  ry(vect, angle->y);
  rz(vect, angle->z);
}

void		anti_rot(t_vect *vect, t_vect *angle)
{
  rz(vect, -angle->z);
  ry(vect, -angle->y);
  rx(vect, -angle->x);
}
