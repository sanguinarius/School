/*
** my_power_rec.c for my_power_rec in /Users/laxa/Documents/Piscine/C/Jour_03/egloff_j/my_power_rec
** 
** Made by EGLOFF Julien
** Login   <laxa>
** 
** Started on  Thu Mar 27 10:21:04 2014 EGLOFF Julien
** Last update Thu Mar 27 11:04:44 2014 EGLOFF Julien
*/

int	my_power_rec(int nb, int power);

int	my_power_rec(int nb, int power)
{
  if (power == 0)
    return (1);
  if (power < 0)
    return (0);
  if (power >= 1)
    return (nb * my_power_rec(nb, power - 1));
  return (nb);
}
