/*
** test.c for test in /home/delas_j/
**
** Made by jimmy delas
** Login   <delas_j@epitech.net>
**
** Started on  Sat Dec  4 19:41:04 2010 jimmy delas
** Last update Wed May 25 12:09:33 2011 thomas wilgenbus
*/

#include <stdlib.h>
#include <stdio.h>
#include "strutils.h"
#include "my_printf.h"

float           get_nbr_float(char *num)
{
  float         n;
  int           i;
  int           neg;
  int           vir;

  vir = 1;
  n = 0;
  neg = 1;
  if (num[0] == '-')
    neg = -1;
  i = -1;
  if (neg < 0)
    i++;
  while (num[++i] >= '0' && num[i] <= '9')
    n = (n * 10) + num[i] - '0';
  if (num[i] == '.')
    while (num[++i] >= '0' && num[i] <= '9')
      n += (float)(num[i] - '0') / (vir *= 10);
  return (n * neg);
}

int		my_getnbr_base(char *num, char *base, int offset)
{
  int		i;
  int		res;
  int		pow;
  int		j;
  int		base_size;

  base_size = -1;
  while (base[++base_size]);
  i = offset;
  pow = 1;
  res = 0;
  while (num[++i] && num[i] != ' ' && num[i] != '\t');
  while (--i > offset)
    {
      j = -1;
      while (base[++j] && base[j] != num[i]);
      if (!base[j])
	return (-1);
      res += pow * j;
      if (res < 0)
	return (-2);
      pow *= base_size;
    }
  return (res);
}

void		check_ret(int ret)
{
  if (ret == -1)
    {
      my_printf("Invalid color format\n");
      exit(0);
    }
  else if (ret == -2)
    {
      my_printf("Error: color overflow\n");
      exit(0);
    }
}

int		my_getcolor(char *color, int i)
{
  int		ret;
  int		sign;

  sign = 1;
  if (color[0] == '-')
    {
      i++;
      sign = -1;
    }
  if (color[++i] != '0')
    ret = my_getnbr_base(color, "0123456789", --i);
  else
    {
      if (color[++i] == 'x')
	{
	  if ((ret = my_getnbr_base(color, "0123456789abcdef", i)) < 0)
	    ret = my_getnbr_base(color, "0123456789ABCDEF", i);
	}
      else
	ret = my_getnbr_base(color, "01234567", --i);
    }
  check_ret(ret);
  return (ret * sign);
}
