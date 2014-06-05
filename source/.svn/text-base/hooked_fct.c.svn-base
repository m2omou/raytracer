/*
** hooked_fct.c for rt.h in
**
** Made by alexis brissard
** Login   <brissa_a@epitech.net>
**
** Started on  Tue May  3 18:57:14 2011 alexis brissard
** Last update Sun Jun  5 14:22:05 2011 thomas wilgenbus
*/

#include	"rt.h"
#include	"bmp.h"
#include	"slide_show.h"

int		update_screen(t_screen *screen)
{
  mlx_put_image_to_window(screen->mlx, screen->win, screen->img.img, 0, 0);
  return (0);
}

int		stop(int key, t_screen *screen)
{
  if (key == LOAD_BMP)
    loading_bitmap(screen->img, screen);
  if (key == SLIDE_SHOW)
    slide_show();
  if (key == KEY_EXIT)
    exit(0);
  return (0);
}
