/*
** xclosedir.c for xclosedir.c in /home/sabour_m//RTV/rt/slide_show
** 
** Made by mourad sabour
** Login   <sabour_m@epitech.net>
** 
** Started on  Mon May 23 01:17:03 2011 mourad sabour
** Last update Mon May 23 01:19:52 2011 mourad sabour
*/

#include		"slide_show.h"
#include		"my_printf.h"

void		xclosedir(DIR *read)
{
  if ((closedir(read)) == -1)
    {
      my_printf("ERROR: closedir\n.");
      exit(1);
    }
}
