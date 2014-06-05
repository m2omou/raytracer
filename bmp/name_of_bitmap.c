/*
** name_of_bitmap.c for name_of_bitmap.c in /home/sabour_m//RTV/rt/bmp
** 
** Made by mourad sabour
** Login   <sabour_m@epitech.net>
** 
** Started on  Fri May 20 21:08:38 2011 mourad sabour
** Last update Sun Jun  5 12:42:22 2011 mourad sabour
*/

#include		"bmp.h"
#include		"rt.h"

void			add_the_rep_bmp(char *bmp_name, int *count, char *rep)
{
  while (rep[*count] != '\0')
    bmp_name[(*count)++] = rep[*count];
}

void			add_the_name_bmp(char *bmp_name, char *name,
					 int *count, int start)
{
  while (name[start] != '\0' && name[start] != '.')
    bmp_name[(*count)++] = name[start++];
  bmp_name[(*count)++] = '-';
}

void			add_the_format_bmp(char *bmp_name, int count2, char *date)
{
  int			count;
  
  count = 0;
  while (date[count] != '\0' && date[count] != '\n')
    bmp_name[count2++] = date[count++];
  count = 0;
  while (FORMAT[count] != '\0')
    bmp_name[count2++] = FORMAT[count++];
  bmp_name[count2] = '\0';
}

char			*name_of_bitmap(char *name, int start)
{
  char			*bmp_name;
  char			*date;
  int			count;
  int			size;
  time_t		tm;

  count = 0;
  X(time(&tm));
  PX(date = ctime(&tm));
  size = my_strlen(name) + my_strlen(REP_BMP) + my_strlen(date) + 1;
  PX(bmp_name = malloc(sizeof(*bmp_name) * size));
  add_the_rep_bmp(bmp_name, &count, REP_BMP);
  add_the_name_bmp(bmp_name, name, &count, start);
  add_the_format_bmp(bmp_name, count, date);
  return (bmp_name);
}
