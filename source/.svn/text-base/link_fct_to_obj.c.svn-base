/*
** link_fct_to_obj.c for rt.h in /home/brissa_a//c/B2/rt/source
**
** Made by alexis brissard
** Login   <brissa_a@epitech.net>
**
** Started on  Tue May  3 15:23:59 2011 alexis brissard
** Last update Sat Jun  4 03:28:53 2011 thomas wilgenbus
*/

#include "rt.h"

void		init_fct_tab(t_fct_obj_tab *fct_tab)
{
  fct_tab[O_SPHERE].calc_neg = is_in_sphere_eq;
  fct_tab[O_SPHERE].calc_k = calc_k_sphere;
  fct_tab[O_SPHERE].calc_normal = calc_normal_sphere;
  fct_tab[O_SPHERE].convert_3d_to_2d = convert_3d_to_2d_sphere;
  fct_tab[O_PLAN].calc_neg = is_in_plane_eq;
  fct_tab[O_PLAN].calc_k = calc_k_plane;
  fct_tab[O_PLAN].calc_normal = calc_normal_plane;
  fct_tab[O_PLAN].convert_3d_to_2d = convert_3d_to_2d_plane;
  fct_tab[O_CYLINDER].calc_k = calc_k_cylinder;
  fct_tab[O_CYLINDER].calc_normal = calc_normal_cylinder;
  fct_tab[O_CYLINDER].convert_3d_to_2d = convert_3d_to_2d_cylinder;
  fct_tab[O_CYLINDER].calc_neg = is_in_cylinder_eq;
  fct_tab[O_CONE].calc_k = calc_k_cone;
  fct_tab[O_CONE].calc_normal = calc_normal_cone;
  fct_tab[O_CONE].convert_3d_to_2d = convert_3d_to_2d_cone;
  fct_tab[O_CONE].calc_neg = is_in_cone_eq;
  fct_tab[O_MOBUS].calc_k = calc_k_mobus;
  fct_tab[O_MOBUS].calc_normal = calc_normal_mobus;
  fct_tab[O_MOBUS].convert_3d_to_2d = convert_3d_to_2d_mobus;
  fct_tab[O_MOBUS].calc_neg = NULL;
}

int		link_fct_to_obj(t_scene *scene)
{
  t_fct_obj_tab	fct_tab[NB_OBJ];
  t_obj		*cur_obj;

  init_fct_tab(fct_tab);
  scene->camera->calc_k = fct_tab[O_SPHERE].calc_k;
  scene->camera->calc_normal = fct_tab[O_SPHERE].calc_normal;
  scene->camera->convert_3d_to_2d = fct_tab[O_SPHERE].convert_3d_to_2d;
  cur_obj = scene->objet;
  while (cur_obj)
    {
      if (cur_obj->type != O_CELL)
	{
	  cur_obj->calc_neg = fct_tab[cur_obj->type].calc_neg;
	  cur_obj->calc_k = fct_tab[cur_obj->type].calc_k;
	  cur_obj->calc_normal = fct_tab[cur_obj->type].calc_normal;
	  cur_obj->convert_3d_to_2d = fct_tab[cur_obj->type].convert_3d_to_2d;
	}
      cur_obj = cur_obj->next;
    }
  return (0);
}
