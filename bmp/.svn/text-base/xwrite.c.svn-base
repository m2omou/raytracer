/*
** xwrite.c for xwrite.c in /home/sabour_m//RTV/rt/bmp
** 
** Made by mourad sabour
** Login   <sabour_m@epitech.net>
** 
** Started on  Wed May 18 14:28:20 2011 mourad sabour
** Last update Thu May 19 12:46:49 2011 mourad sabour
*/

#include	"bmp.h"

void		xwrite(int fd, void *c, int size)
{
  if (write(fd, c, size) == -1)
    {
      my_putstr("Error write\n");
      exit(1);
    }
}
