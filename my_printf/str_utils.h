/*
** str_utils.h for my_printf in /home/wilgen_t//afs/projets/my_printf
** 
** Made by thomas wilgenbus
** Login   <wilgen_t@epitech.net>
** 
** Started on  Mon Nov 15 15:23:37 2010 thomas wilgenbus
** Last update Mon Mar  7 15:57:23 2011 thomas wilgenbus
*/

#ifndef		__STR_UTILS_DEFINED__
# define	__STR_UTILS_DEFINED__

#include	"my_printf.h"

#define		ABS(x)	(((x) > 0) ? (x) : (-x))

int		put_symbols(int *nbr, t_flags *flag);
  int		put_spaces(int nbr, t_flags *flag);
void		my_putchar(char c, t_flags *flag);
void		my_putchar_format(char c, t_flags *flag);
int		my_putstr(char *str, t_flags *flag);
unsigned int	my_putnbr_base2(unsigned int nbr, char *base, t_flags *flag);
int		my_putnbr_base1(int nbr, char *base, t_flags *flag);
int		my_strlen_unwritable(char *str);
void		aff_nb(unsigned int nbr, t_flags *flag);
void		aff_nbr(unsigned int nbr, unsigned int puis,
			char *base, t_flags *flag);

#endif		/*__STR_UTILS_DEFINED__*/
