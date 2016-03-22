/*
** my_sort_wordtab.c for my_sort_wordtab in /Users/laxa/Documents/Piscine/C/Jour_08/egloff_j/my_sort_wordtab
** 
** Made by EGLOFF Julien
** Login   <laxa>
** 
** Started on  Thu Apr  3 11:39:32 2014 EGLOFF Julien
** Last update Thu Apr  3 11:47:17 2014 EGLOFF Julien
*/

#include "libmy.h"

int	my_sort_wordtab(char **tab)
{
  int	i;
  char	*tmp;

  for (i = 0; tab[i + 1]; i++)
    {
      if (my_strcmp(tab[i], tab[i + 1]) > 0)
	{
	  tmp = tab[i];
	  tab[i] = tab[i + 1];
	  tab[i + 1] = tmp;
	  i = -1;
	}
    }
  return (0);
}
