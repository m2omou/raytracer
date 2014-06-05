/*
** aff.c for my_printf in /home/wilgen_t//afs/projets/my_printf
** 
** Made by thomas wilgenbus
** Login   <wilgen_t@epitech.net>
** 
** Started on  Tue Nov 16 12:58:19 2010 thomas wilgenbus
** Last update Sun Nov 21 22:33:20 2010 thomas wilgenbus
*/

#include	<stdarg.h>
#include	"my_printf.h"
#include	"str_utils.h"
#include	"aff.h"

void		aff_nb(unsigned int nbr, t_flags *flag)
{
  if (flag->car & S_INT)
    my_putnbr_base1(nbr, "0123456789", flag);
  else if (flag->car & OCTAL)
    my_putnbr_base2(nbr, "01234567", flag);
  else if (flag->car & UNS_INT)
    my_putnbr_base2(nbr, "0123456789", flag);
  else if (flag->car & HEX)
    my_putnbr_base2(nbr, "0123456789abcdef", flag);
  else if (flag->car & HEX2)
    my_putnbr_base2(nbr, "0123456789ABCDEF", flag);
  else if (flag->car & POINTER)
    my_putnbr_base2(nbr, "0123456789abcdef", flag);
  else if (flag->car & BINAIRE)
    my_putnbr_base2(nbr, "01", flag);
}

void		take_format(char c, va_list *ap, t_flags *flag)
{
  if (flag->opt & POINT)
    {
      flag->nbr_point *= 10;
      flag->nbr_point += c - '0';      if (flag->opt & STAR)
	{
	  flag->nbr_point = va_arg(*ap, int);
    	  flag->opt ^= STAR;
	}
    }
  else if (!(flag->opt & POINT))
    {
      flag->nbr_format *= 10;
      flag->nbr_format += c - '0';
      if ((flag->opt & STAR))
	{
	  flag->nbr_format = va_arg(*ap, int);
	  flag->opt ^= STAR;
	}
    }
}

void		my_put_bad_arg(char c, t_flags *flag)
{
  my_putchar(c, flag);
}

void		my_put_unwritable(char *str, t_flags *flag)
{
  int		i;

  i = 0;
  flag->nbr_format -= my_strlen_unwritable(str);
  while (!(flag->opt & MINUS) && ((flag->nbr_format--) > 0))
    my_putchar(' ', flag);
  while (str[i])
    {
      if (UNWRITABLE(str[i]))
	{
	  my_putchar('\\', flag);
	  if (str[i] < 0100)
	    my_putchar('0', flag);
	  if (str[i] <= 010)
	    my_putchar('0', flag);
	  my_putnbr_base2(str[i], "01234567", flag);
	}
      else
	my_putchar(str[i], flag);
      i++;
    }
  while (((flag->nbr_format--) > 0) && (flag->opt & MINUS))
    my_putchar(' ', flag);
}
