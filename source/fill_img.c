/*
** fill_img.c for rt.c in
**
** Made by alexis brissard
** Login   <brissa_a@epitech.net>
**
** Started on  Tue May  3 19:26:48 2011 alexis brissard
   Last update Sat Jun  4 15:49:04 2011 mourad sabour
*/

#include	<unistd.h>
#include	"my_printf.h"
#include	"rt.h"
#include	"bmp.h"

void			my_put_pixel_to_img(t_image *img, int x, int y, int color)
{
  int			i;

  if (x < 0 || y < 0 ||
      x > img->x_size - 1 || y > img->y_size - 1)
    return ;
  i = (img->bpp / 8) * (img->x_size * y + x);
  img->data[i] = color;
  img->data[i + 1] = color >> 8;
  img->data[i + 2] = color >> 16;
}

void			calc_vect_cam(t_vect *vect_cam, t_image *img,
				      t_obj *camera, t_vect *cur_pix)
{
  vect_cam->x = img->x_size / FOV;
  vect_cam->y = img->x_size / 2 - cur_pix->x;
  vect_cam->z = img->y_size / 2 - cur_pix->y;
  mouvement(vect_cam, camera->move, ROT);
}

void			fill_img(t_image *img, t_scene *scene, t_screen *screen)
{
  int			y;

  y = 0;
  while (y < img->y_size)
    {
      my_printf("\r%d%%", y * 100 / img->y_size);
      thread_line(y, screen, scene, get_focus_color);
      update_screen(screen);
      y++;
    }
}
