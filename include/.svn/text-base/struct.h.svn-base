/*
** struct.h for raytracer in /home/brissa_a//c/B2/raytracer
**
** Made by alexis brissard
** Login   <brissa_a@epitech.net>
**
** Started on  Wed Mar 30 10:13:50 2011 alexis brissard
** Last update Sun Jun  5 15:55:41 2011 mourad sabour
*/

#ifndef __STRUCT_H__
#define __STRUCT_H__

#include	<pthread.h>

typedef struct		s_opt
{
  int			opt;
  int			thread;
  int			timeout;
  char			*s1;
  char			*s2;
}			t_opt;

typedef struct		s_rgb
{
  unsigned char		blue;
  unsigned char		green;
  unsigned char		red;
  unsigned char		transp;
}			t_rgb;

typedef union		s_color
{
  int			all;
  t_rgb			rgb;
}			t_color;

typedef	struct		s_pix
{
  int			x;
  int			y;
}			t_pix;

typedef struct		s_vect
{
  double		x;
  double		y;
  double		z;
}			t_vect;

typedef struct		s_image
{
  int			x;
  int			y;
  int			x_size;
  int	        	y_size;
  void          	*img;
  int           	bpp;
  int           	sizeline;
  int           	endian;
  char          	*data;
  int			fd_bmp;
  char			*file_name;
  int			thread_num;
}               	t_image;

typedef struct		s_texture
{
  char			*path;
  t_image		img;
  int			ints_bump;
  double		x_rep;
  double		y_rep;
}			t_texture;

typedef struct		s_perlin
{
  int			perlin_kind;
  int		        perlin_octaves;
  int			perlin_pas;
  double		perlin_persistance;
  double		s1;
  double		s2;
  double		s3;
  t_color		c1;
  t_color		c2;
  t_color		c3;
}			t_perlin;

typedef struct		s_tex_box
{
  t_texture		color;
  t_texture		transp;
  t_texture		bump;
  t_perlin		perlin;
}			t_tex_box;

typedef struct		s_move
{
  t_vect		pos;
  t_vect		rot;
  struct s_move		*next;
}			t_move;

typedef struct		s_obj
{
  double		gloss;
  double		transp;
  double		reflex;
  double		absorb;
  double		refrac;
  double		focus;
  double		focus_speed;
  double		ints_fog;
  double		dist_fog;
  int			is_paral;
  int			type;
  t_move		*move;
  t_color		color;
  double		color_fog;
  double		halo;
  double		anti_alias;
  double		param;
  t_tex_box		tex;
  t_vect		lim_min;
  t_vect		lim_max;
  int			is_neg;
  double		(*calc_k)(t_vect *o, t_vect *u, struct s_obj *obj);
  void			(*calc_normal)(t_vect *p, struct s_obj *obj, t_vect *normal);
  void			(*convert_3d_to_2d)(t_vect *p, t_pix *pix,
					    struct s_obj *obj, t_texture *tex);
  int			(*calc_neg)(t_vect *p, struct s_obj *obj);
  struct s_obj		*content;
  char			*content_name;
  int			add_obj;
  struct s_obj		*next;
}			t_obj;

typedef struct		s_cell
{
  double		gradient;
  double		cosa;
  struct s_cell		*next;
}			t_cell;

typedef struct		s_thread
{
  int			y;
  int			sx;
  int			ex;
  int			num;
  int			quit;
  struct s_screen	*screen;
  pthread_t		thread;
  int			calc_new;
  int			pipein[2];
  int			pipeout[2];
  int			(*calc_method)();
  struct s_scene	*scene;
}			t_thread;

typedef struct		s_scene
{
  t_obj			*camera;
  t_obj			*light;
  t_obj			*objet;
  t_cell		*cell;
  t_thread		*thread;
}			t_scene;

typedef	struct		s_inter
{
  t_vect		p;
  double		k;
  t_vect		normal;
  t_obj			*obj;
}			t_inter;

typedef struct		s_screen
{
  void			*mlx;
  void			*win;
  t_image		img;
  int			width;
  int			height;
  int			timeout;
}			t_screen;

typedef struct		s_fct_obj_tab
{
  double		(*calc_k)(t_vect *o, t_vect *u, struct s_obj *obj);
  void			(*calc_normal)(t_vect *p, struct s_obj *obj, t_vect *normal);
  void			(*convert_3d_to_2d)(t_vect *p, t_pix *pix,
					    struct s_obj *obj, t_texture *tex);
  int			(*calc_neg)(t_vect *p, struct s_obj *obj);
}			t_fct_obj_tab;

typedef struct		s_main_data
{
  t_scene		*scene;
  t_screen		*screen;
  t_vect		cur_pix;
}			t_main_data;

typedef	struct		s_var
{
  double       		count_x;
  double       		count_y;
  int			red;
  int			blue;
  int			green;
  int			all_pix;
}			t_var;

typedef struct		s_variable
{
  char			*name;
  t_obj			*obj;
  struct s_variable	*next;
}			t_variable;

typedef struct		s_parser
{
  int			fd;
  char			*line;
  t_scene		ret;
  t_obj			*tmp;
  int			n_line;
  t_variable		*var;
  t_obj			*father;
  int			comment;
}			t_parser;

typedef struct		s_type
{
  char			*name;
  int			num;
}			t_type;

#endif /* __STRUCT_H__ */
