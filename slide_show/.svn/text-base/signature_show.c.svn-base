/*
** signature.c for signature.c in /home/sabour_m//RTV/rt/bmp
**
** Made by mourad sabour
** Login   <sabour_m@epitech.net>
**
** Started on  Wed May 18 14:23:41 2011 mourad sabour
** Last update Sat Jun  4 12:40:52 2011 thomas wilgenbus
*/

#include		"bmp.h"
#include		"rt.h"

void			write_signature_show(char *signature, int fd)
{
  int			count;

  printf("entre\n\n\n");
  count = -1;
  while (++count != TWO_OCT)
    {
      X(read(fd, &signature[count], 1));
      printf("signature[count] = %c\n", signature[count]);
    }
}

void			header_signature_show(char *signature, int fd)
{
  write_signature_show(signature, fd);
}
