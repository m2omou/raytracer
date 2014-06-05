/*
** load_bmp_img.c for load_bmp.img.c in /home/sabour_m//RTV/rt
** 
** Made by mourad sabour
** Login   <sabour_m@epitech.net>
** 
** Started on  Mon May 23 01:04:04 2011 mourad sabour
** Last update Sun Jun  5 04:15:04 2011 mourad sabour
*/

#include		"bmp.h"
#include		"rt.h"
#include		"parser.h"
#include		"slide_show.h"
#include		"my_printf.h"

void			put_the_bmp_to_window(t_screen *screen, t_image *img)
{
  t_slide		slide;

  slide.size_x = (WIN_X - img->x_size) / 2;
  slide.size_y = (WIN_Y - img->y_size) / 2;
  slide.path = path_of_repertory_bmp("clear.xpm", REP_SLIDE);
  if ((slide.clear = mlx_xpm_file_to_image(screen->mlx, slide.path,
					   &slide.nb1, &slide.nb2)) != NULL)
    mlx_put_image_to_window(screen->mlx, screen->win, slide.clear, 0, 0);
  mlx_put_image_to_window(screen->mlx, screen->win, img->img,
			  slide.size_x, slide.size_y);
  mlx_destroy_image(screen->mlx, img->img);
  free(slide.path);
}

void			init_bmp_img(t_screen *screen, t_image *img)
{
  PX(img->img = mlx_new_image(screen->mlx, img->x_size, img->y_size));
  PX(img->data = mlx_get_data_addr(img->img, &img->bpp,
				   &img->sizeline, &img->endian));
}

void			load_bmp_img(t_image *img, t_screen *screen)
{
  int			size_x;
  int			size_y;
  int			color;

  size_y = 0;
  init_bmp_img(screen, img);
  size_y = img->y_size;
  while (size_y > 0)
    {
      size_x = 0;
      while (size_x != img->x_size)
  	{
  	  read(img->fd_bmp, &color, 4);
  	  my_put_pixel_to_img(img, size_x, size_y, color);
  	  size_x++;
  	}
      size_y--;
    }
  
  put_the_bmp_to_window(screen, img);
}
