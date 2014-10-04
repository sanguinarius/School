/*
** my_power_it.c for my_power_it in /Users/laxa/Documents/Piscine/C/Jour_03/egloff_j/my_power_it
** 
** Made by EGLOFF Julien
** Login   <egloff_j@etna-alternance.net>
** 
** Started on  Thu Mar 27 10:02:00 2014 EGLOFF Julien
** Last update Thu Mar 27 11:04:17 2014 EGLOFF Julien
*/

int	my_power_it(int nb, int power);

int	my_power_it(int nb, int power)
{
  int	i;
  int	res;

  res = 0;
  if (power == 0)
    return (1);
  else if (power < 0)
    return (0);
  for (i = 1, res = nb; i < power; i++)
    res *= nb;
  return (res);
}
