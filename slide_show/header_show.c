/*
** header_bmp.c for header_bmp.c in /home/sabour_m//RTV/rt/bmp
**
** Made by mourad sabour
** Login   <sabour_m@epitech.net>
**
** Started on  Wed May 18 14:37:16 2011 mourad sabour
** Last update Sat Jun  4 12:42:14 2011 thomas wilgenbus
*/

#include		"bmp.h"
#include		"slide_show.h"
#include		"rt.h"

void			header_show(t_header hb, int fd)
{
  int			test;
  char			c;

  hb.file_size = 0;
  X(read(fd, &c, 1));
  X(read(fd, &c, 1));
  X(read(fd, &test, 4));
  X(read(fd, &hb.reserved, 4));
  X(read(fd, &test, 4));
}

void			info_header_show_1(t_info_header ihb, t_image *info)
{
  X(read(info->fd_bmp, &ihb.size, INT_OCT));
  X(read(info->fd_bmp, &ihb.width, INT_OCT));
  info->x_size = ihb.width;
  X(read(info->fd_bmp, &ihb.height, INT_OCT));
  info->y_size = ihb.height;
  X(read(info->fd_bmp, &ihb.planes, TWO_OCT));
  X(read(info->fd_bmp, &ihb.bits, TWO_OCT));
  info->bpp = ihb.bits;
}

void			info_header_show_2(t_info_header ihb, t_image *info)
{
  X(read(info->fd_bmp, &ihb.compression, INT_OCT));
  X(read(info->fd_bmp, &ihb.image_size, INT_OCT));
  X(read(info->fd_bmp, &ihb.xpixels_perm, INT_OCT));
  X(read(info->fd_bmp, &ihb.ypixels_perm, INT_OCT));
  X(read(info->fd_bmp, &ihb.colors_used, INT_OCT));
  X(read(info->fd_bmp, &ihb.colors_important, INT_OCT));
}
