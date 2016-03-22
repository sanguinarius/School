/*
** my_convert_base.c for my_convert_base in /Users/laxa/Documents/Piscine/C/Jour_06/egloff_j/my_convert_base
** 
** Made by EGLOFF Julien
** Login   <laxa>
** 
** Started on  Tue Apr  1 10:53:54 2014 EGLOFF Julien
** Last update Tue Apr  1 15:07:56 2014 EGLOFF Julien
*/

#include <stdlib.h>
#include <stdio.h>
#include "libmy.h"

char	*convert_base(char *nbr, char *base_from, char *base_to);

char	*convert_base(char *nbr, char *base_from, char *base_to)
{
  char	*res;
  int	nb;
  int	i;
  int	neg;

  res = malloc(sizeof(*res) * 100);
  nb = my_getnbr_base(nbr, base_from);
  neg = 0;
  if (nb < 0 && (neg = 1))
    nb *= -1;
  i = 0;
  do
    {
      res[i] = base_to[nb % my_strlen(base_to)];
      nb /= my_strlen(base_to);
      i++;
    } while (nb > 0);
  if (neg == 1)
    {
      res[i] = '-';
      i++;
    }
  res[i] = '\0';
  res = my_revstr(res);
  return (res);
}
