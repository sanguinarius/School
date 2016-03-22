/*
** my_show_tab.c for my_show_tab in /Users/laxa/Documents/Piscine/C/Jour_07/egloff_j/my_param_to_tab
** 
** Made by EGLOFF Julien
** Login   <laxa>
** 
** Started on  Wed Apr  2 11:21:18 2014 EGLOFF Julien
** Last update Wed Apr  2 15:12:34 2014 EGLOFF Julien
*/

#include "libmy.h"
#include "my_show_tab.h"

int	my_show_tab(struct s_stock_par *par)
{
  int	ii;
  int	i;

  for (i = 0; par[i].str; i++)
    {
      my_putstr(par[i].copy);
      my_putchar('\n');
      my_put_nbr(par[i].size_param);
      my_putchar('\n');
      for (ii = 0; par[i].tab[ii]; ii++)
	{
	  my_putstr(par[i].tab[ii]);
	  my_putchar('\n');
	}
    }
  return (0);
}
