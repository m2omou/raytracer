/*
** bmp.h for bmp.h in /home/sabour_m//RTV/rt/include
** 
** Made by mourad sabour
** Login   <sabour_m@epitech.net>
** 
** Started on  Tue May 17 22:10:17 2011 mourad sabour
** Last update Sun Jun  5 12:35:23 2011 mourad sabour
*/

#ifndef		__BMP_H__
# define	__BMP_H__

# include	<sys/types.h>
# include	<sys/stat.h>
# include	<fcntl.h>
# include	<unistd.h>
# include	<stdlib.h>
# include	"mlx.h"
# include	"struct.h"

#define		CHAR_OCT		1
#define		TWO_OCT			2
#define		INT_OCT			4

#define		HEADER_FIELD		"BM"
#define		FORMAT			".bmp"
#define		REP_BMP			"scene_bmp/"

typedef	struct		s_header
{
  char		signature[TWO_OCT];
  long		file_size;
  short		reserved;
  long		data_offset;
}			t_header;

typedef struct		s_info_header
{
  long		size;
  long		width;
  long		height;
  short		planes;
  short		bits;
  long		compression;
  long		image_size;
  long		xpixels_perm;
  long		ypixels_perm;
  long		colors_used;
  long		colors_important;
}			t_info_header;

/*
**		libmy.a
*/

void		my_putstr(char *str);
int		my_strlen(char *str);

/*
**		xwrite
*/

void		xwrite(int fd, void *c, int size);
void		xclose(int fd);

/*
**		signature.c
*/

void		init_signature(char *signature);
void		write_signature(char *signature, int fd);
void		header_signature(char *signature, int fd);

/*
**		header_bmp.c
*/

void		header_bmp(t_header header, int fd);
void		info_header_bmp_1(t_info_header ihb, t_image info);
void		info_header_bmp_2(t_info_header ihb, t_image info);

/*
**		loading_bitmap.c
*/

void		loading_bitmap(t_image info, t_screen *screen);
void		write_pixel_to_bmp(t_image info);
int		check_if_rep(char *str);

/*
**		convert_scene_to_bmp.c
*/

int		take_only_the_name(char *name, int count);
char		*convert_scene_to_bmp(char *name);

/*
**		name_of_bitmap.c
*/

void		add_the_rep_bmp(char *bmp_name, int *count, char *rep);
void		add_the_name_bmp(char *bmp_name, char *name,
					 int *count, int start);
void		add_the_format_bmp(char *bmp_name, int count2, char *date);
char		*name_of_bitmap(char *name, int start);

/*
**		write_the_bmp.c
*/

void		write_the_bmp(t_image info);

#endif		/* __BMP_H__ */
