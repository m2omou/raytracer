/*
** write_the_bmp.c for write_the_bmp.c in /home/sabour_m//RTV/rt
** 
** Made by mourad sabour
** Login   <sabour_m@epitech.net>
** 
** Started on  Sat May 21 12:48:04 2011 mourad sabour
** Last update Wed May 25 00:37:20 2011 mourad sabour
*/

#include		"bmp.h"
#include		"rt.h"
#include		"parser.h"

void			write_the_bmp(t_image info)
{
  t_header		hb;
  t_info_header		ihb;

  header_bmp(hb, info.fd_bmp);
  info_header_bmp_1(ihb, info);
  info_header_bmp_2(ihb, info);
  write_pixel_to_bmp(info);
}
