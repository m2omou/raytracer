/*
** my_printf.c for my_printf in /home/wilgen_t//afs/projets/my_printf
** 
** Made by thomas wilgenbus
** Login   <wilgen_t@epitech.net>
** 
** Started on  Fri Nov 12 14:53:07 2010 thomas wilgenbus
** Last update Thu Feb  3 16:57:46 2011 thomas wilgenbus
*/

#include	<stdarg.h>
#include	<unistd.h>
#include	"str_utils.h"
#include	"my_printf.h"
#include	"aff.h"

void		read_car(char c, va_list *ap, t_flags *flag)
{
  int		*n;

  if (flag->car & PERCENT)
    my_putstr("%", flag);
  else if ((flag->car & S_INT) || (flag->car & OCTAL) ||
	   (flag->car & UNS_INT) || (flag->car & HEX) ||
	   (flag->car & HEX2) || (flag->car & POINTER) || (flag->car & BINAIRE))
    aff_nb(va_arg(*ap, unsigned int), flag);
  else if (flag->car & CHAR)
    my_putchar_format(va_arg(*ap, int), flag);
  else if (flag->car & STRING)
    my_putstr(va_arg(*ap, char *), flag);
  else if (flag->car & STRING_EXTEND)
    my_put_unwritable(va_arg(*ap, char *), flag);
  else if (flag->car & WRITTEN)
    {
      n = va_arg(*ap, int *);
      *n = flag->ret_value;
    }
  else if (flag->car & BAD_CAR)
    my_put_bad_arg(c, flag);
}

void		test_flags(char c, va_list *ap, t_flags *flag)
{
  if (c == '%' && (flag->car |= PERCENT));
  else if ((c == 'd' || c == 'i') && (flag->car |= S_INT));
  else if (c == 'o' && (flag->car |= OCTAL));
  else if (c == 'u' && (flag->car |= UNS_INT));
  else if (c == 'x' && (flag->car |= HEX));
  else if (c == 'X' && (flag->car |= HEX2));
  else if (c == 'b' && (flag->car |= BINAIRE));
  else if (c == 'c' && (flag->car |= CHAR));
  else if (c == 's' && (flag->car |= STRING));
  else if (c == 'S' && (flag->car |= STRING_EXTEND));
  else if (c == 'p' && (flag->car |= POINTER));
  else if (c == 'n' && (flag->car |= WRITTEN));
  else if (c == '#' && (flag->opt |= CONVERTER));
  else if (c == ' ' && (flag->opt |= SPACE));
  else if (c == '-' && (flag->opt |= MINUS));
  else if (c == '+' && (flag->opt |= PLUS));
  else if (c == '.' && (flag->opt |= POINT));
  else if (c == 'l' && (flag->opt |= LONG));
  else if (c == '*' && (flag->opt |= STAR))
    take_format(c, ap, flag);
  else if ((c >= '0' && c <= '9') && (flag->opt |= NBR_FORMAT))
    take_format(c, ap, flag);
  else
    (flag->car += BAD_CAR);
}

int		my_printf(const char *str, ...)
{
  int		i;
  va_list	ap;
  t_flags	flag;

  i = 0;
  va_start(ap, str);
  flag.ret_value = 0;
  while (str[i])
    {
      flag.car = 0;
      flag.nbr_format = 0;
      flag.nbr_point = 0;
      flag.opt = 0;
      if (str[i] != '%' && str[i])
	my_putchar(str[i], &flag);
      else while (!flag.car && str[i])
	     {
	       test_flags(str[i + 1], &ap, &flag);
	       read_car(str[++i], &ap, &flag);
	     }
      i++;
    }
  va_end(ap);
  return (flag.ret_value);
}
