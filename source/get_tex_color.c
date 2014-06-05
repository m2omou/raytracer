/*
** get_tex_color.c for get_tex_color.c in /home/sabour_m//RTV/rt/source
**
** Made by mourad sabour
** Login   <sabour_m@epitech.net>
**
** Started on  Sun May 15 17:08:19 2011 mourad sabour
   Last update Sun Jun  5 02:05:02 2011 thomas wilgenbus
*/

#include	"rt.h"
#include	"parser.h"

int		get_pix_texture(int x, int y, t_image *xpm)
{
  int		i;
  t_color	color;

  if (x > (xpm->x_size - 1) || x < 0)
    return (0);
  else if (y > (xpm->y_size - 1) || y < 0)
    return (0);
  i = (xpm->bpp / 8) * (xpm->x_size * y + x);
  color.rgb.blue = xpm->data[i];
  color.rgb.green = xpm->data[i + 1];
  color.rgb.red = xpm->data[i + 2];
  return (color.all);
}

int             get_tex_color(t_vect *p, t_obj *obj, t_texture *tex)
{
  int		color;
  t_pix		pix;
  t_vect	tmp;

  tmp = *p;
  anti_mouvement(&tmp, obj->move, TRANS | ROT);
  obj->convert_3d_to_2d(&tmp, &pix, obj, tex);
  if (obj->tex.color.path && is_equal(obj->tex.color.path, "perlin"))
    color = get_perlin_color(pix.x, pix.y, &obj->tex.perlin);
  else
    color = get_pix_texture(pix.x, pix.y, &tex->img);
  return (color);
}

int		get_obj_color(t_inter *inter)
{
  if (inter->obj->tex.perlin.perlin_octaves && (inter->obj->type == O_PLAN))
    return (get_perlin_color(ABS(inter->p.y), ABS(inter->p.x),
			     &inter->obj->tex.perlin));
  else if (inter->obj->tex.color.path)
    return (get_tex_color(&inter->p, inter->obj, &inter->obj->tex.color));
  else
    return (inter->obj->color.all);
}

double		get_obj_transp(t_inter *inter)
{
  t_color	col;
  double	transp;

  if (inter->obj->tex.transp.path || inter->obj->tex.color.path)
    {
      col.all = get_tex_color(&inter->p, inter->obj, &inter->obj->tex.transp);
      transp = (col.rgb.red + col.rgb.blue + col.rgb.green) / (3.0 * 255.0);
      return (transp);
    }
  else
    return (inter->obj->transp);
}
