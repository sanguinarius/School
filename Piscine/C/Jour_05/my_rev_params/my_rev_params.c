/*
** my_rev_params.c for my_rev_params in /Users/laxa/Documents/Piscine/C/Jour_05/egloff_j/my_rev_params
** 
** Made by EGLOFF Julien
** Login   <egloff_j@etna-alternance.net>
** 
** Started on  Sat Mar 29 11:55:47 2014 EGLOFF Julien
** Last update Sat Mar 29 11:56:38 2014 EGLOFF Julien
*/

#include "libmy.h"

int	main(int ac, char **av)
{
  for (; ac > 0; ac--)
    {
      my_putstr(av[ac - 1]);
      my_putchar('\n');
    }
  return (0);
}
