/*
** slide_show.h for slide_show.h in /home/sabour_m//RTV/rt
** 
** Made by mourad sabour
** Login   <sabour_m@epitech.net>
** 
** Started on  Sat May 21 20:31:56 2011 mourad sabour
** Last update Sun Jun  5 11:47:53 2011 mourad sabour
*/

#ifndef		__SLIDE_SHOW_H__
# define	__SLIDE_SHOW_H__

# include	<sys/types.h>
# include	<dirent.h>
# include	<sys/types.h>
# include	<sys/stat.h>
# include	<fcntl.h>
# include	<unistd.h>
# include	<stdlib.h>
# include	"mlx.h"
# include	"bmp.h"
# include	"struct.h"

# define	WIN_X		1600
# define	WIN_Y		845
# define	REP_SLIDE	"slide_show/"



typedef	struct s_slide
{
  char		*path;
  void		*clear;
  int		size_x;
  int		size_y;
  int		nb1;
  int		nb2;
}		t_slide;

/*
**		signature_show.c
*/

void		init_signature_show(char *signature);
void		write_signature_show(char *signature, int fd);
void		header_signature_show(char *signature, int fd);
/*
**		header_show.c
*/

void		header_show(t_header header, int fd);
void		info_header_show_1(t_info_header ihb, t_image *info);
void		info_header_show_2(t_info_header ihb, t_image *info);

/*
**		slide_show.c
*/

void		slide_show();
char		*path_of_repertory_bmp(char *name, char *rep);
void		start_the_slide_show(DIR *stock);

/*
**		aff_the_bmp.c
*/

void		aff_the_bmp(char *name, t_image img, t_screen *screen);
void		aff_the_main_menu(t_screen *screen);

/*
**		load_bmp_img.c
*/

void		load_bmp_img(t_image *img, t_screen *screen);
void		init_bmp_img(t_screen *screen, t_image *img);

/*
**		xclosedir.c
*/

void		xclosedir(DIR *read);

#endif		/* __SLIDE_SHOW_H__ */
