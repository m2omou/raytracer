/*
** header_bmp.c for header_bmp.c in /home/sabour_m//RTV/rt/bmp
** 
** Made by mourad sabour
** Login   <sabour_m@epitech.net>
** 
** Started on  Wed May 18 14:37:16 2011 mourad sabour
** Last update Wed May 25 00:37:11 2011 mourad sabour
*/

#include		"bmp.h"
#include		"rt.h"

void			header_bmp(t_header hb, int fd)
{
  header_signature(hb.signature, fd);
  hb.file_size = 0;
  xwrite(fd, &hb.file_size, INT_OCT);
  hb.reserved = 0;
  xwrite(fd, &hb.reserved, INT_OCT);
  hb.data_offset = 54;
  xwrite(fd, &hb.data_offset, INT_OCT);
}

void			info_header_bmp_1(t_info_header ihb, t_image info)
{
  ihb.size = 40;
  xwrite(info.fd_bmp, &ihb.size, INT_OCT);
  ihb.width = info.x_size;
  xwrite(info.fd_bmp, &ihb.width, INT_OCT);
  ihb.height = info.y_size;
  xwrite(info.fd_bmp, &ihb.height, INT_OCT);
  ihb.planes = 1;
  xwrite(info.fd_bmp, &ihb.planes, TWO_OCT);
  ihb.bits = info.bpp;
  xwrite(info.fd_bmp, &ihb.bits, TWO_OCT);
}

void			info_header_bmp_2(t_info_header ihb, t_image info)
{
  ihb.compression = 0;
  xwrite(info.fd_bmp, &ihb.compression, INT_OCT);
  ihb.image_size = info.x_size * info.y_size * 4;
  xwrite(info.fd_bmp, &ihb.image_size, INT_OCT);
  ihb.xpixels_perm = 3937;
  xwrite(info.fd_bmp, &ihb.xpixels_perm, INT_OCT);
  ihb.ypixels_perm = 3937;
  xwrite(info.fd_bmp, &ihb.ypixels_perm, INT_OCT);
  ihb.colors_used = 0;
  xwrite(info.fd_bmp, &ihb.colors_used, INT_OCT);
  ihb.colors_important = 0;
  xwrite(info.fd_bmp, &ihb.colors_important, INT_OCT);
}
