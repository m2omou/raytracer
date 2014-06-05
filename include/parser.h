/*
** parser.h for rtv1 in /home/delas_j//c/rtv1/parser
**
** Made by jimmy delas
** Login   <delas_j@epitech.net>
**
** Started on  Thu Feb 24 23:39:32 2011 jimmy delas
** Last update Sun Jun  5 02:26:37 2011 jimmy delas
*/

#ifndef		_PARSER_H_
#define		_PARSER_H_

#include	"struct.h"

#define		START	(1)
#define		END	(2)

#define		SET_TMP(x, y)	((x) ? *(x) : (y))

/*
**		complex.c
*/
int		resolve_scene_tree(t_scene *scene, t_obj **orig, int n);

/*
**		protertie.c
*/
void		add_object_propertie(t_parser *parser, t_obj **obj, int n_line);
void		warn(char *message, int line);

/*
**		parser.c
*/
void		put_in_list(t_obj *list, t_obj *elem);
t_scene		load_scene(const char *path, t_screen *screen);
int		is_comment(t_parser *parser);
int		check_line_state(char *line, t_screen *screen);

/*
**		get_nbr.c
*/
float           get_nbr_float(char *num);
int		my_getcolor(char *color, int i);

/*
**		parser_utils.c
*/
void            my_putnbr(int num);
int             my_strlen(char *str);
int		is_dim(char *line, t_screen *screen);
void		reset_obj(t_obj *obj);

/*
**		list_utils.c
*/
void		delete_obj(t_obj *obj);
void		add_mouvement(t_move **mvt_list, t_vect *pos,
			      t_vect *rot);

/*
**		parser_loop.c
*/
void		new_obj_find(t_parser *parser, t_screen *screen);

/*
**		get_properties.c
*/
int		get_limit(char *var, char *value, t_obj *obj);
int		get_tex_repetition(char *var, char *value, t_obj *obj);
int		get_position_rotation(char *var, char *value, t_obj *obj);
int		add_propertie3(char *var, char *value,
			       t_obj *obj, int n_line);
int		add_propertie4(char *var, char *value,
			       t_obj *obj, int n_line);
int		get_perlin(char *var, char *value,
			   t_obj *obj, int n_line);
int		perlin_utils(char *var, char *value,
			     t_obj *obj, int n_line);
int		get_light(char *var, char *value,
			  t_obj *obj);
int		get_special_var(char *var, char *value,
				t_obj **obj, t_parser *parser);
t_obj		*get_reference(t_obj *obj, char *value, t_obj *content);
int		add_propertie2(char *var, char *value,
			       t_obj *obj, int n_line);

/*
**		obj_utils.c
*/
int		add_obj_scene(t_scene *scene, t_obj *obj,
			      int n_line, t_obj *father);

/*
**		str_utils.c
*/
int		is_equal(char *s1, char *s2);

/*
**		variable.c
*/
void		cpy_obj(t_obj *ret, t_obj *obj);
t_obj		*get_obj_var(t_variable *list, char *name);
t_variable	*add_var(t_variable *list, char *name, t_obj *obj);
void		kill_variable(t_variable *variable);

#endif
