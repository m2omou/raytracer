/*
** my_printf.h for my_printf in /home/wilgen_t//afs/projets/my_printf
** 
** Made by thomas wilgenbus
** Login   <wilgen_t@epitech.net>
** 
** Started on  Mon Nov 15 14:54:56 2010 thomas wilgenbus
** Last update Sat Jun  4 14:54:03 2011 alexis brissard
*/

#ifndef		__MY_PRINTF_DEFINED__
# define	__MY_PRINTF_DEFINED__

#include	<stdarg.h>
#include	"my_printf.h"

# define	NO_FLAG		0x0

# define	PERCENT		0x1
# define	S_INT		0x2
# define	OCTAL		0x8
# define	UNS_INT		0x10
# define	HEX		0x20
# define	HEX2		0x40
# define	BINAIRE		0x80
# define	CHAR		0x100
# define	STRING		0x200
# define	STRING_EXTEND	0x400
# define	POINTER		0x800
# define	WRITTEN		0x1000
# define	BAD_CAR		0x2000

# define	CONVERTER	0x1
# define	NBR_FORMAT	0x2
# define	SPACE		0x4
# define	MINUS		0x8
# define	PLUS		0x10
# define	POINT		0x20
# define	LONG		0x40
# define	STAR		0x80

# define	UNWRITABLE(x)	(((x >= 0 && x <= 31) || (x == 127)) ? 1 : 0)

#define		X(c)			xcall(c, #c)
#define		X0(c)			x0call(c, #c)
#define		PX(c)			pxcall(c, #c)

int		xcall(int ret, char *error);
int		x0call(int ret, char *error);
void		*pxcall(void *ret, char *error);

typedef struct	s_flags
{
  unsigned int	car;
  unsigned int	opt;
  int		nbr_format;
  int		nbr_point;
  int		ret_value;
}		t_flags;

int		my_strlen(char *str);
int		my_printf(const char *str, ...);
void		test_flags(char c, va_list *ap, t_flags *flag);
void		read_car(char c, va_list *ap, t_flags *flag);

#endif		/*__MY_PRINTF_DEFINED__*/
