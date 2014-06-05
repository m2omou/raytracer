/*
** str_utils.c for my_printf in /home/wilgen_t//afs/projets/my_printf
**
** Made by thomas wilgenbus
** Login   <wilgen_t@epitech.net>
**
** Started on  Thu Nov 18 12:36:15 2010 thomas wilgenbus
** Last update Sat Jun  4 14:51:32 2011 alexis brissard
*/

#include		<unistd.h>
#include	       	<stdlib.h>
#include		"my_printf.h"
#include		"str_utils.h"

int		my_strlen(char *str)
{
  unsigned int		i;

  if (str == NULL)
    return (0);
  i = 0;
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}

void			my_putchar(char c, t_flags *flag)
{
  flag->ret_value++;
  X(write(1, &c, 1));
}

void			my_putchar_format(char c, t_flags *flag)
{
  while (flag->nbr_format-- > 1 && !(flag->opt & MINUS))
    my_putchar(' ', flag);
  X(write(1, &c, 1));
  while (flag->nbr_format-- > 0 && (flag->opt & MINUS))
    my_putchar(' ', flag);
}

int		my_strlen_unwritable(char *str)
{
  int		i;
  int		count;

  if (str == NULL)
    return (0);
  i = 0;
  count = 0;
  while (str[i])
    {
      if (UNWRITABLE(str[i]))
	count += 3;
      i++;
      count++;
    }
  return (count);
}

int			my_putstr(char *str, t_flags *flag)
{
  int			i;

  flag->nbr_format -= my_strlen(str);
  while (flag->nbr_format-- > 0 && !(flag->opt & MINUS))
    my_putchar(' ', flag);
  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i], flag);
      i = i + 1;
    }
  while (flag->nbr_format-- >= 0 && (flag->opt & MINUS))
    my_putchar(' ', flag);
  return (i);
}
