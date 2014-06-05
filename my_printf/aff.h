/*
** aff.h for my_printf in /home/wilgen_t//afs/projets/my_printf
** 
** Made by thomas wilgenbus
** Login   <wilgen_t@epitech.net>
** 
** Started on  Tue Nov 16 14:10:12 2010 thomas wilgenbus
** Last update Sat Jun  4 14:51:14 2011 alexis brissard
*/

#ifndef		__AFF_DEFINED__
# define	__AFF_DEFINED__

#include	<stdarg.h>
#include	"my_printf.h"

#define		X(c)			xcall(c, #c)
#define		X0(c)			x0call(c, #c)
#define		PX(c)			pxcall(c, #c)

void		aff_nb(unsigned int nbr, t_flags *flag);
void		my_put_unwritable(char *str, t_flags *flag);
void		my_put_bad_arg(char c, t_flags *flag);
void		take_format(char c, va_list *ap, t_flags *flag);

#endif		/*__AFF_DEFINED__*/
