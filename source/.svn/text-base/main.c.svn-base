/*
** main.c for raytracer in /home/wilgen_t/projets/raytracer
**
** Made by thomas wilgenbus
** Login   <wilgen_t@epitech.net>
**
** Started on  Tue Apr  5 17:17:04 2011 thomas wilgenbus
** Last update Sun Jun  5 14:23:43 2011 thomas wilgenbus
*/

#include	<signal.h>
#include	<stdlib.h>
#include	<strings.h>
#include	"rt.h"
#include	"bmp.h"
#include	"parser.h"
#include	"network.h"
#include	"my_printf.h"

void		destroy_scene(t_scene *scene)
{
  t_obj		*tmp;

  free(scene->camera);
  while (scene->objet)
    {
      tmp = scene->objet;
      scene->objet = scene->objet->next;
      free(tmp);
    }
  while (scene->light)
    {
      tmp = scene->light;
      scene->light = scene->light->next;
      free(tmp);
    }
}

int		main_init(t_opt *opt, t_scene *scene,
			  t_screen *screen, int local)
{
  *scene = load_scene(opt->s1, screen);
  if (!scene->camera)
    {
      printf("Impossible de charger la scene %s\n", opt->s1);
      return (0);
    }
  screen->img.file_name = opt->s1;
  resolve_scene_tree(scene, NULL, 0);
  screen->timeout = opt->timeout;
  screen->img.thread_num = opt->thread;
  scene->cell = NULL;
  separ_cell(scene);
  if (local)
    {
      create_win(screen);
      load_texture(scene, screen);
      link_fct_to_obj(scene);
    }
  return (1);
}

#ifdef _CC_NETWORK_

void		sig_catch(int signum)
{
  if (signum == SIGTERM || signum == SIGINT)
    close_srv(SRV_KILL, 0, NULL);
  exit(0);
}

int		main(int ac, char *av[])
{
  t_scene	scene;
  t_screen	screen;
  t_opt		opt;

  bzero(&scene, sizeof(scene));
  bzero(&screen, sizeof(screen));
  xsignal(SIGTERM, sig_catch);
  xsignal(SIGINT, sig_catch);
  if (!((opt.opt = parse_arg(av, ac, &opt)) & ERROR) && opt.s1 && !opt.s2)
    {
      if (opt.opt & USAGE)
	printf("server: ./rt scene.css {-nofork}\nclient: ./rt ip port");
      if (!main_init(&opt, &scene, &screen, 0))
	return (0);
      server_init(&scene, &screen, opt.opt);
    }
  else if (opt.s1 && opt.s2 && !(opt.opt & ERROR))
    {
      if (opt.opt & USAGE)
	printf("%s", USAGE_RT);
      client_init(opt.s1, atoi(opt.s2));
    }
  return (0);
}

#else

int		main(int ac, char *av[])
{
  t_scene	scene;
  t_screen	screen;
  t_opt		opt;

  if (!((opt.opt = parse_arg(av, ac, &opt)) & ERROR) && opt.s1 && !opt.s2)
    {
      if (opt.opt & NOFORK || opt.opt & TIMEOUT)
	my_printf("Warning, clustering is not support in this version.\n");
      if (opt.opt & USAGE)
	my_printf("Usage: ./rt scene.css");
      if (!main_init(&opt, &scene, &screen, 1))
	return (0);
      fill_img(&screen.img, &scene, &screen);
      if (scene.cell)
      	cell_overlay(&screen, &scene);
      anti_alias(&screen.img, &scene, &screen);
      fill_with_anti_alias(&screen.img, &scene, &screen);
      mlx_expose_hook(screen.win, update_screen, &screen);
      mlx_key_hook(screen.win, stop, &screen);
      thread_quit(scene.thread, &screen.img);
      destroy_scene(&scene);
      mlx_loop(screen.mlx);
      my_printf("\n");
    }
  return (0);
}

#endif
