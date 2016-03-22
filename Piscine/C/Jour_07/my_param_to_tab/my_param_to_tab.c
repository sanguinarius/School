/*
** my_param_to_tab.c for my_param_to_tab in /Users/laxa/Documents/Piscine/C/Jour_07/egloff_j/my_param_to_tab
** 
** Made by EGLOFF Julien
** Login   <laxa>
** 
** Started on  Wed Apr  2 10:12:43 2014 EGLOFF Julien
** Last update Wed Apr  2 11:30:00 2014 EGLOFF Julien
*/

#include <stdlib.h>
#include "my_param_to_tab.h"
#include "libmy.h"

struct s_stock_par	*my_param_to_tab(int ac, char **av)
{
  struct s_stock_par	*tab;
  int			i;

  tab = malloc(sizeof(*tab) * ac + 1);
  for (i = 0; i < ac; i++)
    {
      tab[i].size_param = my_strlen(av[i]);
      tab[i].str = av[i];
      tab[i].copy = my_strdup(av[i]);
      tab[i].tab = my_str_to_wordtab(av[i]);
    }
  tab[i].str = NULL;
  return (tab);
}
