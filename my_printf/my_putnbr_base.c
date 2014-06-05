/*
** my_putnbr_base.c for my_putnbr_base in /home/wilgen_t//afs/Jour_06
** 
** Made by thomas wilgenbus
** Login   <wilgen_t@epitech.net>
** 
** Started on  Wed Oct 13 17:26:14 2010 thomas wilgenbus
** Last update Mon Mar  7 15:56:38 2011 thomas wilgenbus
*/

#include	"str_utils.h"
#include	"my_printf.h"

void		aff_nbr(unsigned int nbr, unsigned int puis,
			char *base, t_flags *flag)
{
  unsigned int	len_base;

  len_base = my_strlen(base);
  while (puis >= 1)
    {
      my_putchar(base[nbr / puis], flag);
      nbr = nbr - ((nbr / puis) * puis);
      puis = puis / len_base;
    }
  while ((flag->opt & MINUS) && !(flag->car & STRING_EXTEND) &&
	 (flag->nbr_format-- > 1))
    my_putchar(' ', flag);
}

unsigned int	my_putnbr_base2(unsigned int nbr, char *base, t_flags *flag)
{
  unsigned int	len_base;
  unsigned int	cpy;
  unsigned int	puis;

  len_base = my_strlen(base);
  cpy = nbr;
  puis = 1;
  while (cpy > (len_base - 1))
    {
      if (!(flag->car & STRING_EXTEND))
	flag->nbr_format--;
      flag->nbr_point--;
      cpy = cpy / len_base;
      puis = puis * len_base;
    }
  if (flag->nbr_point > 0)
    flag->nbr_format -= flag->nbr_point-- - 1;
  put_spaces(nbr, flag);
  put_symbols((int *)nbr, flag);
  aff_nbr(nbr, puis, base, flag);
  return (nbr);
}

int		put_symbols(int *nbr, t_flags *flag)
{
  if ((flag->car & S_INT) && (*nbr < 0))
    my_putchar('-', flag);
  else if ((flag->car & S_INT) && (flag->opt & PLUS) && (*nbr >= 0))
    my_putchar('+', flag);
  else if ((flag ->opt & CONVERTER) && (flag->car & HEX) && *nbr)
    flag->ret_value += my_printf("0x");
  else if ((flag->opt & CONVERTER) && (flag->car & HEX2) && *nbr)
    flag->ret_value += my_printf("0X");
  else if (flag->car & POINTER)
    flag->ret_value += my_printf("0x");
  else if ((flag->opt & CONVERTER) && (flag->car & OCTAL) && (*nbr) &&
	   !(flag->nbr_point > 0))
    flag->ret_value += my_printf("0");
  while ((flag->nbr_point-- > 0))
    my_putchar('0', flag);
  return (0);
}

int		put_spaces(int nbr, t_flags *flag)
{
  if ((flag->opt & CONVERTER) && ((flag->car & HEX) || (flag->car & HEX2))
      && nbr)
    flag->nbr_format -= 2;
  else if (flag->car & POINTER)
    flag->nbr_format -= 2;
  else if ((flag->opt & CONVERTER) && (flag->car & OCTAL) && nbr &&
	   !(flag->nbr_point > 0))
    flag->nbr_format--;
  if ((flag->opt & SPACE) && (nbr >= 0) &&
      !(flag->opt & PLUS) && !(flag->opt & NBR_FORMAT))
    my_putchar(' ', flag);
  while (!(flag->opt & STRING_EXTEND) && !(flag->opt & MINUS) &&
	 (flag->nbr_format-- > 1))
    my_putchar(' ', flag);
  return (0);
}

int		my_putnbr_base1(int nbr, char *base, t_flags *flag)
{
  unsigned int	len_base;
  unsigned int	cpy;
  unsigned int	puis;

  len_base = my_strlen(base);
  cpy = ABS(nbr);
  puis = 1;
  while (cpy > (len_base - 1))
    {
      flag->nbr_format--;
      flag->nbr_point--;
      cpy = cpy / len_base;
      puis = puis * len_base;
    }
  if  ((flag->opt & PLUS) || (nbr < 0))
    flag->nbr_format--;
  if (flag->nbr_point > 0)
    flag->nbr_format -= flag->nbr_point-- - 1;
  put_spaces(nbr, flag);
  put_symbols(&nbr, flag);
  aff_nbr(ABS(nbr), puis, base, flag);
  return (nbr);
}
