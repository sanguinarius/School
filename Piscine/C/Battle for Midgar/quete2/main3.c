/*
** main3.c for main3.c for BFM in /Users/laxa/Documents/Piscine/C/Battle for Midgar/felzin_f/quete2
** 
** Made by EGLOFF Julien
** Login   <laxa>
** 
** Started on  Sat Apr  5 17:49:27 2014 EGLOFF Julien
** Last update Sat Apr  5 18:04:56 2014 EGLOFF Julien
*/

#include <stdlib.h>
#include "libmy.h"
#include "ragnarok.h"

int		check(t_hero **hero, t_enemy **enemy)
{
  t_enemy	*tmp;

  if ((*hero)->pv <= 0)
    return (0);
  else if ((*enemy)->pv <= 0)
    {
      if ((*enemy)->next)
	{
	  tmp = (*enemy);
	  my_putstr("Hero ");
	  my_putstr((*hero)->name);
	  my_putstr(" killed a Monster\nA new Monster appear\n\n");
	  (*enemy) = (*enemy)->next;
	  free(tmp);
	  return (42);
	}
      else
	return (0);
    }
  return (42);
}
