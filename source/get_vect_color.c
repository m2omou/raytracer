/*
** get_vect_color.c for rt in /home/brissa_a//c/B2/rt
**
** Made by alexis brissard
** Login   <brissa_a@epitech.net>
**
** Started on  Thu May  5 01:08:02 2011 alexis brissard
** Last update Sun Jun  5 18:28:53 2011 thomas wilgenbus
*/

#include "rt.h"
#include "bmp.h"

int		get_background_color(t_vect *u, t_obj *camera)
{
  t_vect	tmp;

  if (camera->tex.color.path)
    {
      tmp = *u;
      tmp.x = tmp.x / norme(u);
      tmp.y = tmp.y / norme(u);
      tmp.z = tmp.z / norme(u);
      anti_rot(&tmp, &(camera->move->rot));
      trans(&tmp, &(camera->move->pos));
      return (get_tex_color(&tmp, camera, &camera->tex.color));
    }
  else
    return (camera->color.all);
}

int		mix_color(int l_col, int r_col, int t_col, t_inter *inter)
{
  int		result;

  l_col = apply_coef(l_col, 1 - get_obj_transp(inter));
  t_col = apply_coef(t_col, get_obj_transp(inter));
  result = add_color(l_col, t_col);
  result = apply_coef(result, 1 - inter->obj->reflex);
  r_col = apply_coef(r_col, inter->obj->reflex);
  result = add_color(result, r_col);
  return (result);
}

int		get_vect_color(t_vect *o, t_vect *u, t_scene *scene, int i)
{
  t_inter	inter;
  int		final_color;
  int		light_color;
  int		reflex_color;
  int		transp_color;

  throw_vect(o, u, scene->objet, &inter);
  if (inter.k != -1 && i < 10)
    {
      light_color = get_light_color(&inter, scene);
      transp_color = 0;
      if (inter.obj->transp || inter.obj->tex.transp.path)
      	transp_color = get_transp_color(&inter, scene, u, i);
      if (inter.obj->reflex)
	reflex_color = get_reflex_color(&inter, scene, u, i);
      else
	reflex_color = 0;
      final_color = mix_color(light_color, reflex_color,
			      transp_color, &inter);
    }
  else
    final_color = get_background_color(u, scene->camera);
  final_color = get_direct_color(final_color, o, u, scene);
  return (final_color);
}

int		get_pix_color(t_image *img, t_scene *scene, double x, double y)
{
  t_vect	vect_cam;
  t_vect	cur_pix;
  int		color;

  cur_pix.x = x;
  cur_pix.y = y;
  calc_vect_cam(&vect_cam, img, scene->camera, &cur_pix);
  color = get_vect_color(&scene->camera->move->pos, &vect_cam, scene, 0);
  return (color);
}

double		get_pix_k(t_image *img, t_scene *scene, double x, double y)
{
  t_vect	vect_cam;
  t_vect	cur_pix;
  t_inter	inter;

  cur_pix.x = x;
  cur_pix.y = y;
  calc_vect_cam(&vect_cam, img, scene->camera, &cur_pix);
  throw_vect(&scene->camera->move->pos, &vect_cam, scene->objet, &inter);
  return (inter.k);
}
