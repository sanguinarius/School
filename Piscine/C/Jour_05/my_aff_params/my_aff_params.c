/*
** my_aff_params.c for my_aff_params in /Users/laxa/Documents/Piscine/C/Jour_05/egloff_j/my_aff_params
** 
** Made by EGLOFF Julien
** Login   <laxa>
** 
** Started on  Sat Mar 29 11:51:12 2014 EGLOFF Julien
** Last update Sat Mar 29 11:53:59 2014 EGLOFF Julien
*/

#include "libmy.h"

int	main(int ac, char **av)
{
  int	i;

  for (i = 0; i < ac; i++)
    {
      my_putstr(av[i]);
      my_putchar('\n');
    }
  return (0);
}
