/*
** my_sum_params.c for my_sum_params in /Users/laxa/Documents/Piscine/C/Jour_06/egloff_j/my_sum_params
** 
** Made by EGLOFF Julien
** Login   <laxa>
** 
** Started on  Tue Apr  1 11:41:55 2014 EGLOFF Julien
** Last update Tue Apr  1 14:42:46 2014 EGLOFF Julien
*/

#include <stdlib.h>
#include "libmy.h"

char	*sum_params(int argc, char **argv);
int	size_to_malloc(int ac, char **av);

char	*sum_params(int argc, char **argv)
{
  char	*res;
  int	i;
  int	ii;
  int	iii;

  res = malloc(size_to_malloc(argc, argv) * sizeof(*res) + 1);
  for (i = 0, iii = 0; i < argc; i++)
    {
      for (ii = 0; argv[i][ii]; ii++, iii++)
	res[iii] = argv[i][ii];
      res[iii] = '\n';
      iii++;
    }
  res[iii] = '\0';
  return (res);
}

int	size_to_malloc(int ac, char **av)
{
  int	size;
  int	i;

  for (i = 0, size = 0; i < ac; i++)
    size += my_strlen(av[i]) + 1;
  return (size);
}
