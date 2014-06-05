/*
** aff_the_bmp.c for aff_the_bmp.c in /home/sabour_m//RTV/rt
** 
** Made by mourad sabour
** Login   <sabour_m@epitech.net>
** 
** Started on  Mon May 23 00:58:19 2011 mourad sabour
** Last update Wed May 25 00:18:18 2011 mourad sabour
*/

#include		"bmp.h"
#include		"rt.h"
#include		"parser.h"
#include		"slide_show.h"
#include		"my_printf.h"

void			aff_the_bmp(char *name, t_image img, t_screen *screen)
{
  t_header		hb;
  t_info_header		ihb;
  char			*path;

  path = path_of_repertory_bmp(name, REP_BMP);
  if ((img.fd_bmp = open(path, O_RDONLY)) == -1)
    {
      my_printf("ERROR: can't found this bitmap '%s'.\n", path);
      return ;
    }
  header_show(hb, img.fd_bmp);
  info_header_show_1(ihb, &img);
  info_header_show_2(ihb, &img);
  load_bmp_img(&img, screen);
  mlx_string_put(screen->mlx, screen->win,
		 (WIN_X / 2) - 50, WIN_Y - 100, 0xFFFFFF, name);
  free(path);
  sleep(3);
}

void			aff_the_main_menu(t_screen *screen)
{
  char			*path;
  void			*menu;
  int			nb1;
  int			nb2;

  PX(screen->mlx = mlx_init());
  path = path_of_repertory_bmp("main.xpm", REP_SLIDE);
  PX(screen->win = mlx_new_window(screen->mlx, WIN_X, WIN_Y, "slide_show"));
  if ((menu = mlx_xpm_file_to_image(screen->mlx, path, &nb1, &nb2)) != NULL)
    mlx_put_image_to_window(screen->mlx, screen->win, menu, 0, 0);
  free(path);
  sleep(1);
}
