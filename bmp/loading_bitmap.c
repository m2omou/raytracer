/*
** main.c for loading_bitmap.c in /home/sabour_m//RTV/rt
** 
** Made by mourad sabour
** Login   <sabour_m@epitech.net>
** 
** Started on  Thu May 19 02:56:49 2011 mourad sabour
** Last update Wed May 25 00:37:36 2011 mourad sabour
*/

#include		"bmp.h"
#include		"rt.h"
#include		"parser.h"

void			write_pixel_to_bmp(t_image info)
{
  int			count_y;
  int			count_x;
  int			color;

  count_y = info.y_size;
  while (count_y > 0)
    {
      count_x = 0;
      while (count_x < info.x_size)
        {
          color = get_color(count_x++, count_y, &info);
          xwrite(info.fd_bmp, &color, 4);
        }
      count_y--;
    }
}

int			check_if_rep(char *str)
{
  struct stat   	buf;

  if (stat(str, &buf) != -1)
    if ((S_ISDIR(buf.st_mode)) == 1)
      return (1);
  return (0);
}

void			aff_logo_success(t_screen *screen)
{
  t_image		bmp;

  if ((bmp.img = mlx_xpm_file_to_image(screen->mlx, "bmp/save_bmp.xpm",
				       &bmp.x_size, &bmp.x_size)) != NULL)
    mlx_put_image_to_window(screen->mlx, screen->win, bmp.img, 0, 0);
}

void			loading_bitmap(t_image info, t_screen *screen)
{
  mode_t		mode;
  char			*bmp_img;

  mode = S_IRWXU | S_IRWXG | S_IRWXO;
  if (!check_if_rep(REP_BMP))
    mkdir(REP_BMP, mode);
  bmp_img = convert_scene_to_bmp(info.file_name);
  if ((info.fd_bmp = open(bmp_img, O_CREAT | O_RDWR
  			  | O_TRUNC, S_IRUSR | S_IWUSR)) == -1)
    {
      my_putstr("Error open\n");
      exit(1);
    }
  write_the_bmp(info);
  aff_logo_success(screen);
}
