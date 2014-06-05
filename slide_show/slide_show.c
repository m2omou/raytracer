/*
** main.c for loading_bitmap.c in /home/sabour_m//RTV/rt
** 
** Made by mourad sabour
** Login   <sabour_m@epitech.net>
** 
** Started on  Thu May 19 02:56:49 2011 mourad sabour
** Last update Sun Jun  5 12:30:12 2011 mourad sabour
*/

#include		"bmp.h"
#include		"rt.h"
#include		"parser.h"
#include		"slide_show.h"
#include		"my_printf.h"
#include		<time.h>

char			*path_of_repertory_bmp(char *name, char *rep)
{
  char			*tmp;
  int			count;
  int			count2;

  count = 0;
  count2 = 0;
  PX(tmp = malloc(sizeof(tmp) * (my_strlen(name) *
  				 my_strlen(rep) + 1)));
  add_the_rep_bmp(tmp, &count, rep);
  while (name[count2])
    tmp[count++] = name[count2++];
  tmp[count] = '\0';
  return (tmp);
}

void			start_the_slide_show(DIR *read_bmp)
{
  t_image		img;
  t_screen		screen;
  struct dirent		*read;
  int			init_screen;

  init_screen = 1;
  while ((read = readdir(read_bmp)))
    {
      if (read->d_name[0] != '.')
      	{
      	  if (init_screen)
      	    {
      	      aff_the_main_menu(&screen);
      	      init_screen = 0;
      	    }
	  aff_the_bmp(read->d_name, img, &screen);
	}
    }
  xclosedir(read_bmp);
  mlx_destroy_window(screen.mlx, screen.win);
}

void			slide_show()
{
  DIR			*read_bmp;

  if ((read_bmp = opendir(REP_BMP)) == NULL)
    {
      my_putstr("There's no scene.bpm\nPut 's' to load one.\n");
      return ;
    }
  start_the_slide_show(read_bmp);
}
