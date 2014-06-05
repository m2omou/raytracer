/*
** get_perlin_color2.c for get_perlin_color2.c in /home/sabour_m//RTV/rt
** 
** Made by mourad sabour
** Login   <sabour_m@epitech.net>
** 
** Started on  Sat Jun  4 19:41:32 2011 mourad sabour
** Last update Sun Jun  5 15:42:28 2011 mourad sabour
*/

#include		"rt.h"
#include		"struct.h"
#include		"parser.h"

double			cos_interpolation(double a, double b, double x)
{
  double		result;

  result = (1 - cos(x * PI)) / 2;
  return (a * (1 - result) + b * result);
}

int			get_seuil2(t_perlin *perlin, double value)
{
  t_color		result;
  double		f;

  f = (value - perlin->s1) / (perlin->s2 - perlin->s1);
  result.rgb.red = perlin->c1.rgb.red * (1 - f) + perlin->c2.rgb.red * f;
  result.rgb.green = perlin->c1.rgb.green * (1 - f) + perlin->c2.rgb.green * f;
  result.rgb.blue = perlin->c1.rgb.blue * (1 - f) + perlin->c2.rgb.blue * f;
  return (result.all);
}

int			get_seuil3(t_perlin *perlin, double value)
{
  t_color		result;
  double		f;

  f = (value - perlin->s2) / (perlin->s3 - perlin->s1);
  result.rgb.red = perlin->c2.rgb.red * (1 - f) + perlin->c3.rgb.red * f;
  result.rgb.green = perlin->c2.rgb.green * (1 - f) + perlin->c3.rgb.green * f;
  result.rgb.blue = perlin->c2.rgb.blue * (1 - f) + perlin->c3.rgb.blue * f;
  return (result.all);
}

int			get_perlin_color(double x, double y, t_perlin *perlin)
{
  if (perlin->perlin_kind == WOOD)
    return (get_bois_color(x, y, perlin));
  else if (perlin->perlin_kind == MARBLE)
    return (get_marbre_color(x, y, perlin));
  return (get_standard_color(x, y, perlin));
}
