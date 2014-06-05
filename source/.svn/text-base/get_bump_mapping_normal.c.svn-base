/*
** get_bump_mapping_normal.c for get_bump_mapping_normal.c in /home/sabour_m//RTV/rt/source
**
** Made by mourad sabour
** Login   <sabour_m@epitech.net>
**
** Started on  Wed Jun  1 21:52:29 2011 mourad sabour
   Last update Sun Jun  5 15:22:13 2011 mourad sabour
*/

#include	"rt.h"

int             get_def_color(t_vect *p, t_obj *obj,
			      t_texture *tex, t_pix *add)
{
  int		color;
  t_pix		pix;
  t_vect	tmp;

  tmp = *p;
  anti_mouvement(&tmp, obj->move, ROT | TRANS);
  obj->convert_3d_to_2d(&tmp, &pix, obj, tex);
  color = get_pix_texture(pix.x + add->x, pix.y + add->y, &tex->img);
  return (color);
}

int		get_mapping_x(t_inter *inter)
{
  t_color	color1;
  t_color	color2;
  t_pix		add;
  int		a;

  add.y = 0;
  add.x = 1;
  color1.all = get_def_color(&inter->p, inter->obj,
			     &inter->obj->tex.bump, &add);
  add.x = -1;
  color2.all = get_def_color(&inter->p, inter->obj,
			     &inter->obj->tex.bump, &add);
  a = (color2.rgb.red - color1.rgb.red + color2.rgb.blue -
       color1.rgb.blue + color2.rgb.green - color1.rgb.green) / 3;
  return (a);
}

int		get_mapping_y(t_inter *inter)
{
  t_color	color1;
  t_color	color2;
  t_pix		add;
  int		a;

  add.x = 0;
  add.y = 1;
  color1.all = get_def_color(&inter->p, inter->obj,
			     &inter->obj->tex.bump, &add);
  add.y = -1;
  color2.all = get_def_color(&inter->p, inter->obj,
			     &inter->obj->tex.bump, &add);
  a = (color2.rgb.red - color1.rgb.red + color2.rgb.blue -
       color1.rgb.blue + color2.rgb.green - color1.rgb.green) / 3;
  return (a);
}

void		get_bump_mapping_normal(t_inter *inter)
{
  double	angle_y;
  double	angle_x;

  angle_x = BUMP(((get_mapping_x(inter) / 255.0) * (PI / 2.0))
		 * inter->obj->tex.bump.ints_bump);
  angle_y = BUMP(((get_mapping_y(inter) / 255.0) * (PI / 2.0))
		 * inter->obj->tex.bump.ints_bump);
  rx(&inter->normal, angle_x);
  ry(&inter->normal, angle_y);
}
