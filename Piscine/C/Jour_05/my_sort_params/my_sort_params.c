/*
** my_sort_params.c for my_sort_params in /Users/laxa/Documents/Piscine/C/Jour_05/egloff_j/my_sort_params
** 
** Made by EGLOFF Julien
** Login   <laxa>
** 
** Started on  Sat Mar 29 11:59:11 2014 EGLOFF Julien
** Last update Sat Mar 29 12:08:05 2014 EGLOFF Julien
*/

#include "libmy.h"

int	main(int ac, char **av)
{
  int	i;
  char	*tmp;

  for (i = 0; i < ac; i++)
    {
      if (i + 1 < ac && my_strcmp(av[i], av[i + 1]) > 0)
	{
	  tmp = av[i];
	  av[i] = av[i + 1];
	  av[i + 1] = tmp;
	  i = -1;
	}
    }
  for (i = 0; i < ac; i++)
    {
      my_putstr(av[i]);
      my_putchar('\n');
    }
  return (0);
}
