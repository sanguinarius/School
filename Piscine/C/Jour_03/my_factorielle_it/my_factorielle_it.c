/*
** my_factorielle_it.c for my_factorielle_it in /Users/laxa/Documents/Piscine/C/Jour_03/egloff_j/my_factorielle_it
** 
** Made by EGLOFF Julien
** Login   <egloff_j@etna-alternance.net>
** 
** Started on  Thu Mar 27 09:02:06 2014 EGLOFF Julien
** Last update Thu Mar 27 09:28:58 2014 EGLOFF Julien
*/

#include <stdio.h>

int	my_factorielle_it(int nb);

int	my_factorielle_it(int nb)
{
  int	i;
  int	fact;

  if (nb < 0 || nb > 12)
    return (0);
  else if (nb == 1 || nb == 0)
    return (1);
  for (i = 1, fact = 1; i < nb; i++)
    fact = fact * (i + 1);
  return (fact);
}
