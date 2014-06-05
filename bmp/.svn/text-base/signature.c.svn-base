/*
** signature.c for signature.c in /home/sabour_m//RTV/rt/bmp
** 
** Made by mourad sabour
** Login   <sabour_m@epitech.net>
** 
** Started on  Wed May 18 14:23:41 2011 mourad sabour
** Last update Thu May 19 13:32:10 2011 mourad sabour
*/

#include		"bmp.h"

void			init_signature(char *signature)
{
  int			count;

  count = -1;
  while (++count != TWO_OCT)
    signature[count] = HEADER_FIELD[count];
}

void			write_signature(char *signature, int fd)
{
  int			count;

  count = -1;
  while (++count != TWO_OCT)
    xwrite(fd, &signature[count], 1);
}

void			header_signature(char *signature, int fd)
{
  init_signature(signature);
  write_signature(signature, fd);
}
