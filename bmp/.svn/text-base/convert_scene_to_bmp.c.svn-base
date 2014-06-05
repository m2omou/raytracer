/*
** convert_scene_to_bmp.c for convert_scene_to_bmp.c in /home/sabour_m//RTV/rt/bmp
** 
** Made by mourad sabour
** Login   <sabour_m@epitech.net>
** 
** Started on  Thu May 19 12:40:19 2011 mourad sabour
** Last update Fri May 20 21:07:18 2011 mourad sabour
*/

#include		"bmp.h"
#include		"rt.h"

int			take_only_the_name(char *name, int count)
{
  while (name[count] != '\0')
    {
      if (name[count] == '/')
	return (1);
      count++;
    }
  return (0);
}

char			*convert_scene_to_bmp(char *name)
{
  int			count;
  char			*bmp_name;

  count = 0;
  while (take_only_the_name(name, count))
    count++;
  bmp_name = name_of_bitmap(name, count);
  return (bmp_name);
}
