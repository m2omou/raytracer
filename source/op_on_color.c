/*
** op_on_color.c for rt.h in /home/brissa_a//c/B2/rt
**
** Made by alexis brissard
** Login   <brissa_a@epitech.net>
**
** Started on  Fri May  6 16:37:31 2011 alexis brissard
** Last update Fri Jun  3 15:57:18 2011 thomas wilgenbus
*/

#include "rt.h"

int		apply_coef(int color_int, double coef)
{
  t_color	color;

  color.all = color_int;
  color.rgb.red = CH_COL(color.rgb.red * coef);
  color.rgb.green = CH_COL(color.rgb.green * coef);
  color.rgb.blue = CH_COL(color.rgb.blue * coef);
  return (color.all);
}

int		add_color(int color1_int, int color2_int)
{
  t_color	color1;
  t_color	color2;
  t_color	result;

  color1.all = color1_int;
  color2.all = color2_int;
  result.rgb.red = CH_COL(color1.rgb.red + color2.rgb.red);
  result.rgb.green = CH_COL(color1.rgb.green + color2.rgb.green);
  result.rgb.blue = CH_COL(color1.rgb.blue + color2.rgb.blue);
  return (result.all);
}

int		color_absorb(int color1, int color2, double gloss, int absorb)
{
  t_color	color1_c;
  t_color	color2_c;
  t_color	result;

  color1_c.all = color1;
  color2_c.all = color2;
  if (absorb)
    {
      result.rgb.red = MIN(color1_c.rgb.red, color2_c.rgb.red);
      result.rgb.green = MIN(color1_c.rgb.green, color2_c.rgb.green);
      result.rgb.blue = MIN(color1_c.rgb.blue, color2_c.rgb.blue);
    }
  else
    {
      result.rgb.red = color1_c.rgb.red * (1 - gloss)
	+ color2_c.rgb.red * gloss;
      result.rgb.green = color1_c.rgb.green * (1 - gloss)
	+ color2_c.rgb.green * gloss;
      result.rgb.blue = color1_c.rgb.blue * (1 - gloss)
	+ color2_c.rgb.blue * gloss;
    }
  return (result.all);
}
