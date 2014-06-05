/*
** kind_texture_perlin.c for kind_texture_perlin.c in /home/sabour_m//RTV/rt
** 
** Made by mourad sabour
** Login   <sabour_m@epitech.net>
** 
** Started on  Sun Jun  5 11:59:46 2011 mourad sabour
** Last update Sun Jun  5 12:08:18 2011 mourad sabour
*/

#include		"rt.h"
#include		"struct.h"

int			get_marbre_color(double x, double y, t_perlin *perlin)
{
  double		value;
  t_color		result;

  value = 1 - sqrt(fabs(sin(2 * PI * get_coherent_noise(x, y, perlin))));
  result.rgb.red = perlin->c1.rgb.red * (1 - value)
    + perlin->c2.rgb.red * value;
  result.rgb.green = perlin->c1.rgb.green * (1 - value)
    + perlin->c2.rgb.green * value;
  result.rgb.blue = perlin->c1.rgb.blue * (1 - value)
    + perlin->c2.rgb.blue * value;
  return (result.all);
}

int			get_bois_color(double x, double y, t_perlin *perlin)
{
  double		value;
  t_color		result;
  double		f;
  double		seuil;

  seuil = 0.2;
  value = fmod(get_coherent_noise(x, y, perlin), seuil);
  if (value > seuil / 2)
    value = seuil / 2;
  f = (1 - cos(PI * value / (seuil / 2))) / 2;
  result.rgb.red = perlin->c1.rgb.red * (1 - f)
    + perlin->c2.rgb.red * f;
  result.rgb.green = perlin->c1.rgb.green * (1 - f)
    + perlin->c2.rgb.green * f;
  result.rgb.blue = perlin->c1.rgb.blue * (1 - f)
    + perlin->c2.rgb.blue * f;
  return (result.all);
}

int			get_standard_color(double x, double y, t_perlin *perlin)
{
  double		value;

  value = get_coherent_noise(x, y, perlin);
  if (value <= perlin->s1)
    return (perlin->c1.all);
  else if (value <= perlin->s2)
    return (get_seuil2(perlin, value));
  else if (value <= perlin->s3)
    return (get_seuil3(perlin, value));
  return (perlin->c3.all);
}
