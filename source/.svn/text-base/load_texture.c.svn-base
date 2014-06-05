/*
** load_texture.c for rt in /home/brissa_a//c/B2/rt
**
** Made by alexis brissard
** Login   <brissa_a@epitech.net>
**
** Started on  Sun May 15 16:45:00 2011 alexis brissard
** Last update Sat Jun  4 23:52:24 2011 thomas wilgenbus
*/

#include "my_printf.h"
#include "rt.h"
#include "parser.h"

void		fill_texture_data(char *name, t_image *tex, t_screen *screen)
{
  if (name && !is_equal(name, "perlin"))
    {
      PX(tex->img = mlx_xpm_file_to_image(screen->mlx, name,
					  &tex->x_size, &tex->y_size));
      PX(tex->data = mlx_get_data_addr(tex->img, &tex->bpp,
				       &tex->sizeline, &tex->endian));
    }
  else
    {
      tex->x_size = 500;
      tex->y_size = 500;
    }
  my_printf("texture %s loaded\n", name);
}

void		load_texture(t_scene *scene, t_screen *screen)
{
  t_obj		*cur_obj;

  if (scene->camera->tex.color.path)
    fill_texture_data(scene->camera->tex.color.path,
		      &scene->camera->tex.color.img,
		      screen);
  cur_obj = scene->objet;
  while (cur_obj)
    {
      if (cur_obj->tex.color.path)
      	fill_texture_data(cur_obj->tex.color.path,
			  &cur_obj->tex.color.img, screen);
      if (cur_obj->tex.transp.path)
      	fill_texture_data(cur_obj->tex.transp.path,
			  &cur_obj->tex.transp.img, screen);
      if (cur_obj->tex.bump.path)
      	fill_texture_data(cur_obj->tex.bump.path,
			  &cur_obj->tex.bump.img, screen);
      cur_obj = cur_obj->next;
    }
}
