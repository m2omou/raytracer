/*
** calc_noise_perlin.c for calc_noise_perlin.c in /home/sabour_m//RTV/rt
** 
** Made by mourad sabour
** Login   <sabour_m@epitech.net>
** 
** Started on  Sat Jun  4 19:09:29 2011 mourad sabour
** Last update Sun Jun  5 01:03:10 2011 mourad sabour
*/

#include		"rt.h"
#include		"struct.h"

#define		NOISE			1073741824.0
#define		RAND_NOISE		1376312589
#define		COEF_NOISE		789221
#define		COEF_NOISE2		850000

double			rand_noise(int noise)
{
  double		final_noise;

  noise = (noise << 13) ^ noise;
  noise = (noise * (noise * noise * COEF_NOISE) + RAND_NOISE);
  final_noise = (1.0 - (noise & 0x7fffffff) / NOISE);
  return (final_noise);
}

double			noise(int x, int y)
{
  int			tmp;

  tmp = rand_noise(x) * COEF_NOISE2;
  return (rand_noise(tmp + y));
}

double			get_noise(double x, double y, t_perlin *perlin)
{
  int			i;
  int			j;
  double       		y1;
  double		y2;

  i = (x / perlin->perlin_pas);
  j = (y / perlin->perlin_pas);
  y1 = cos_interpolation(noise(i, j), noise((i + 1), j),
			 fmod((x / perlin->perlin_pas), 1));
  y2 = cos_interpolation(noise(i, (j + 1)),
			 noise((i + 1), (j + 1)),
			 fmod((x / perlin->perlin_pas), 1));
  return (cos_interpolation(y1, y2, fmod((y / perlin->perlin_pas), 1)));
}

double			get_coherent_noise(double x, double y, t_perlin *perlin)
{
  double		res_final;
  double		coef_p;
  int			coef_f;
  int			count;

  coef_f = 1;
  coef_p = 1;
  res_final = 0;
  count = 0;
  while (count < perlin->perlin_octaves)
    {
      res_final += coef_p * get_noise((x * coef_f), (y * coef_f), perlin);
      coef_p *= perlin->perlin_persistance;
      coef_f *= 2;
      count++;
    }
  return (res_final * (1 - perlin->perlin_persistance) / (1 - coef_p));
}
