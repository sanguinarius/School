/*
** my_show_to_wordtab.c for my_show_to_wordtab in /Users/laxa/Documents/Piscine/C/Jour_06/egloff_j/my_show_to_wordtab
** 
** Made by EGLOFF Julien
** Login   <egloff_j@etna-alternance.net>
** 
** Started on  Tue Apr  1 10:47:22 2014 EGLOFF Julien
** Last update Tue Apr  1 12:21:43 2014 EGLOFF Julien
*/

#include "libmy.h"

int	my_show_to_wordtab(char **tab);

int	my_show_to_wordtab(char **tab)
{
  int	i;

  for (i = 0; tab[i]; i++)
    {
      my_putstr(tab[i]);
      my_putchar('\n');
    }
  return (0);
}
