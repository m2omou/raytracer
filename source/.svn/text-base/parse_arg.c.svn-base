/*
** parse_arg.c for rt in /home/delas_j//c/rt
** 
** Made by jimmy delas
** Login   <delas_j@epitech.net>
** 
** Started on  Sat Jun  4 19:33:43 2011 jimmy delas
** Last update Sat Jun  4 19:40:35 2011 jimmy delas
*/

#include	"parser.h"
#include	"rt.h"

int		get_arg(t_opt *opt, char **av, int ac, int *i)
{
  if (is_equal(av[*i], "-usage"))
    opt->opt |= USAGE;
  else if (is_equal(av[*i], "-nofork"))
    opt->opt |= NOFORK;
  else if (is_equal(av[*i], "-thread"))
    {
      if (++(*i) >= ac || (opt->thread = atoi(av[*i]) + 1) <= 1)
	{
	  printf("Invalid or missing thread number\n");
	  opt->opt = ERROR;
	}
      opt->opt |= THREAD;
    }
  else if (is_equal(av[*i], "-timeout"))
    {
      if (++(*i) >= ac || (opt->timeout = atoi(av[*i])) <= 0)
	{
	  printf("Invalid or missing timeout number\n");
	  opt->opt = ERROR;
	}
      opt->opt |= TIMEOUT;
    }
  else
    return (0);
  return (1);
}

int		parse_arg(char **av, int ac, t_opt *opt)
{
  int		i;

  opt->s1 = NULL;
  opt->s2 = NULL;
  opt->opt = 0;
  opt->thread = 2;
  opt->timeout = 10000;
  i = 0;
  while (++i < ac && opt->opt != ERROR)
    if (get_arg(opt, av, ac, &i));
    else if (!opt->s1)
      opt->s1 = av[i];
    else if (!opt->s2)
      opt->s2 = av[i];
    else
      {
	printf("Too many arguments\n");
	opt->opt = ERROR;
      }
  return (opt->opt);
}
