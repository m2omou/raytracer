/*
** rt.h for raytracer in /home/brissa_a//c/B2/raytracer
**
** Made by alexis brissard
** Login   <brissa_a@epitech.net>
**
** Started on  Wed Mar 30 10:15:26 2011 alexis brissard
** Last update Sun Jun  5 17:53:49 2011 mourad sabour
*/

#ifndef		__RT_H__
#define		__RT_H__

#include	<stdlib.h>
#include	<stdio.h>
#include	<math.h>
#include	"mlx.h"
#include	"struct.h"

#define		USAGE			1
#define		ERROR			2
#define		NOFORK			4
#define		THREAD			8
#define		TIMEOUT			16

#define		PAS			0.000001
#define		IS_ZERO(x)		((x > -PAS) && (x < PAS))
#define		PI			3.14159265358979323846
#define		FOV			1
#define		CH_COL(x)		(x > 255) ? 255 : ((x < 0) ? 0 : x)
#define         CH_COL_FOG(x, y)	(x > 255) ? 255 : ((x < 0) ? y : \
							   ((x < y) ? y : x))
#define		MIN(x, y)		(((x) <= (y)) ? (x) : (y))
#define		MAX(x, y)		(((x) >= (y)) ? (x) : (y))
#define		ABS(x)			(((x) > 0) ? (x) : (-(x)))
#define		SIGN(x)			((x > 0) ? (1.0) : (-1.0))
#define		PO(x)			(x * x)
#define		LIMITE(x)		(x > 255 ? 255 : x)
#define		BUMP(x)			(x > (PI / 2)) ? (0) : (x)

#define		NOISE			1073741824.0
#define		RAND_NOISE		1376312589
#define		COEF_NOISE		789221
#define		COEF_NOISE2		850000
#define		WOOD			1
#define		MARBLE			2

#define		NB_EFFECTS		8
#define		NB_OBJ			5
#define		NB_SPE_OBJ		3
#define		LIM_CELLSHADING		3

#define		O_CELL			-4
#define         O_NULL			-3
#define         O_LIGHT			-2
#define         O_EYE			-1
#define         O_SPHERE		0
#define         O_PLAN			1
#define         O_CYLINDER		2
#define         O_CONE			3
#define         O_MOBUS			4

#define		X(c)			xcall(c, #c)
#define		X0(c)			x0call(c, #c)
#define		PX(c)			pxcall(c, #c)

#define		ROT			(1)
#define		TRANS			(2)

#define		USAGE_RT "server: ./rt scene.css {-nofork} {-thread nb}"\
                         "{-thread timeout}\nclient: ./rt ip port\n"

/*
**		Event
*/

#define		KEY_EXIT       		65307
#define		SLIDE_SHOW		100
#define		LOAD_BMP		115

int		coeff_cell(int cur, double cosa, t_scene *scene);

/*
**		anti_alias.c
*/
void		anti_alias(t_image *img, t_scene *scene, t_screen *screen);
int		fill_sub_pixel_tab(t_screen *screen, t_scene *scene,
				   double x, double y);
void		fill_with_anti_alias(t_image *img, t_scene *scene,
				     t_screen *screen);

/*
**		test_aliasing.c
*/
int             get_color(int x, int y, t_image *img);

/*
**		bump_mapping.c
*/

void		get_bump_mapping_normal(t_inter *inter);

/*
**		parse_arge.c
*/
int		parse_arg(char **av, int ac, t_opt *opt);

/*
**		display_error.c
*/

void		puterror(char *str);
int		xcall(int ret, char *error);
int		x0call(int ret, char *error);
void		*pxcall(void *ret, char *error);

/*
**		mouvement.c
*/
void		anti_mouvement(t_vect *pt, t_move *move, int mode);
void		mouvement(t_vect *pt, t_move *move, int mode);

/*
**		neg_object.c
*/
int		is_in_neg_object(t_vect *p, t_obj *obj, t_obj *obj_list);

/*
**		multi_thread.c
*/
char		*thread_line(int line, t_screen *screen, t_scene *scene,
			    int (*calc_method)(t_screen *, t_scene *,
					       double, double));
void		thread_quit(t_thread *thread, t_image *img);
void		*calc_line(void *arg);

/*
**		main_function (PS: Elles sont dans le fichier qui porte leur nom)
*/

void		load_texture(t_scene *scene, t_screen *screen);
void		create_win(t_screen *screen);
void		fill_img(t_image *img, t_scene *scene, t_screen *screen);

int		get_pix_color(t_image *img, t_scene *scene, double x, double y);
double		get_pix_k(t_image *img, t_scene *scene, double x, double y);

int		get_vect_color(t_vect *o, t_vect *u, t_scene *scene, int i);
int		get_light_color(t_inter *inter, t_scene *scene);
int		get_reflex_color(t_inter *inter, t_scene *scene,
				 t_vect *u, int i);
int		get_transp_color(t_inter *inter, t_scene *scene,
				 t_vect *u, int i);
int		get_direct_color(int final_color, t_vect *o,
				 t_vect *u, t_scene *scene);
int		get_shadow_color(t_inter *inter, t_scene *scene,
				 t_obj *light, t_vect *light_v);
void		throw_vect(t_vect *o, t_vect *u, t_obj *obj_list, t_inter *inter);

/*
**		PS: Sauf celle la
*/
void		calc_vect_cam(t_vect *vect_cam, t_image *img,
			      t_obj *camera, t_vect *cur_pix);
void		my_put_pixel_to_img(t_image *img, int x, int y, int color);

/*
**		op_on_vect.c
*/
double		norme(t_vect *vect);
double		scal(t_vect *vect1, t_vect *vect2);
void		create_light_vect(t_vect *l_vect, t_vect *l_pos,
				  t_vect *p_pos, t_obj *obj);
double		get_cos_a(t_vect *vect1, t_vect *vect2);

/*
**		op_on_color.c
*/
int		add_color(int color1_int, int color2_int);
int		apply_coef(int color_int, double coef);
int		color_absorb(int color1, int color2, double gloss, int absorb);

/*
**		rotation.c
*/
void		rot(t_vect *vect, t_vect *angle);
void		anti_rot(t_vect *vect, t_vect *angle);
void		rx(t_vect *vect, double x);
void		ry(t_vect *vect, double y);

/*
**		cellshading.c
*/
double		last_gradient(t_scene *s);
int		coeff_cell(int cur, double cosa, t_scene *scene);
double		find_mult_cell(double cosa, t_scene *scene);
void		add_cell(t_cell **root, double gradient, double cosa);
void		separ_cell(t_scene *scene);

/*
**		cell_overlay.c
*/

void		cell_overlay(t_screen *screen, t_scene *scene);
t_obj		*is_border(t_screen *screen, t_scene *s, int x, int y);
void		fill_overlay(t_image *img, int x, int y, int lim);
t_obj		*detect_pix(t_image *img, t_scene *scene, int x, int y);
int		cell_pixel(t_screen *screen, t_scene *scene,
			   double x, double y);

/*
**		translation.c
*/

void		trans(t_vect *vect, t_vect *trans);
void		anti_trans(t_vect *vect, t_vect *trans);

/*
**		link_fct_to_obj.c
*/

int		link_fct_to_obj(t_scene *scene);

/*
**		hooked_fct.c
*/

int		update_screen(t_screen *screen);
int		stop(int key, t_screen *screen);

/*
**		get_texcolor.c
*/

int		get_pix_texture(int x, int y, t_image *xpm);
int		get_tex_color(t_vect *p, t_obj *obj, t_texture *tex);
double		get_obj_transp(t_inter *inter);
int		get_obj_color(t_inter *inter);

/*
**		get_shadow.c
*/

int		get_shadow_color(t_inter *inter, t_scene *scene,
				 t_obj *light, t_vect *light_v);
double		get_shadow_pow(t_inter *inter, t_scene *scene,
			       t_obj *light, t_vect *light_v);

/*
**		copy_img.c
*/

t_image		copy_img(t_image *img, t_screen *screen);

/*
**		get_fog_color.c
*/

int		calc_fog_color(t_scene *scene, t_inter *inter,
			       t_vect *vect_cam, int color);

/*
**		get_focus_color.c
*/

int		get_focus_color(t_screen *screen, t_scene *scene,
				double x, double y);
double		calc_focus_distance(t_scene *scene, t_image *img,
				    t_vect *cur_pix);
int		mlx_pixel_around_focus(t_scene *scene, t_vect *cur_pix,
					       t_image *tmp_img, double flou);

/*
**		get_perlin_color.c
*/

int		get_perlin_color(double x, double y, t_perlin *perlin);
int		get_seuil2(t_perlin *perlin, double value);
int		get_seuil3(t_perlin *perlin, double value);
double		cos_interpolation(double a, double b, double x);

/*
**		kind_texture_perlin.c
*/

int		get_marbre_color(double x, double y, t_perlin *perlin);
int		get_bois_color(double x, double y, t_perlin *perlin);
int		get_standard_color(double x, double y, t_perlin *perlin);

/*
**		calc_noise_perlin.c
*/

double		rand_noise(int noise);
double		get_coherent_noise(double x, double y, t_perlin *perlin);

/*
**		object
*/

double		res_eq_sc(t_vect *tmp, double *x1, double *x2);
void		res_eq_tr(double *coef, double *res);
int		check_limit(t_vect *o, t_vect *u, double k, t_obj *obj);

/* sphere */
double		calc_k_sphere(t_vect *o, t_vect *u, t_obj *obj);
void		calc_normal_sphere(t_vect *p, t_obj *obj, t_vect *normal);
void		convert_3d_to_2d_sphere(t_vect *p, t_pix *pix, t_obj *obj,
					t_texture *tex);
int		is_in_sphere_eq(t_vect *pt, t_obj *obj);

/* plane */
double		calc_k_plane(t_vect *o, t_vect *u, t_obj *obj);
void		calc_normal_plane(t_vect *p, t_obj *obj, t_vect *normal);
void		convert_3d_to_2d_plane(t_vect *p, t_pix *pix, t_obj *obj,
				       t_texture *tex);
int		is_in_plane_eq(t_vect *pt, t_obj *obj);

/* cylinder */
double		calc_k_cylinder(t_vect *o, t_vect *u, t_obj *obj);
void		calc_normal_cylinder(t_vect *p, t_obj *obj, t_vect *normal);
void		convert_3d_to_2d_cylinder(t_vect *p, t_pix *pix, t_obj *obj,
					  t_texture *tex);
int		is_in_cylinder_eq(t_vect *pt, t_obj *obj);

/* cone */
double		calc_k_cone(t_vect *o, t_vect *u, t_obj *obj);
void		calc_normal_cone(t_vect *p, t_obj *obj, t_vect *normal);
void		convert_3d_to_2d_cone(t_vect *p, t_pix *pix, t_obj *obj,
				      t_texture *tex);
int		is_in_cone_eq(t_vect *pt, t_obj *obj);

/* mobus */
double		calc_k_mobus(t_vect *o, t_vect *u, t_obj *obj);
void		calc_normal_mobus(t_vect *p, t_obj *obj, t_vect *normal);
void		convert_3d_to_2d_mobus(t_vect *p, t_pix *pix, t_obj *obj,
					t_texture *tex);
int		is_min(double res[3], int i);
void		rm_out_of_limit(double res[3], t_obj *obj,
				t_vect *o, t_vect *u);
int		limit(double k, t_obj *obj, t_vect *o, t_vect *u);
int		check_t(double t, double v, t_vect *p, t_obj *obj);

/*
**		main.c
*/

void		destroy_scene(t_scene *scene);

#endif	/* __RT_H__ */
