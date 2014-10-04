/*
** main2.c for main2.c for BFM in /Users/laxa/Documents/Piscine/C/Battle for Midgar/felzin_f/quete1
** 
** Made by EGLOFF Julien
** Login   <egloff_j@etna-alternance.net>
** 
** Started on  Sat Apr  5 10:16:52 2014 EGLOFF Julien
** Last update Sat Apr  5 11:34:10 2014 EGLOFF Julien
*/

#include <stdlib.h>
#include "libmy.h"
#include "ragnarok.h"

void	end(t_hero *hero, t_ennemy *ennemy)
{
  if (hero->pv <= 0)
    {
      my_putstr("Hero ");
      my_putstr(hero->name);
      my_putstr(" is dead\n");
      my_putstr("You lost\n");
    }
  else
    {
      my_putstr("Hero ");
      my_putstr(hero->name);
      my_putstr(" has defeated ");
      my_putstr(ennemy->name);
      my_putchar('\n');
      my_putstr("Congratulation, you won !!\n");
    }
  clear(hero, ennemy);
}

void	clear(t_hero *hero, t_ennemy *ennemy)
{
  free(hero->name);
  free(hero);
  free(ennemy->name);
  free(ennemy);
}

void	clear_cmd(t_cmd *commands)
{
  int	i;

  for (i = 0; commands[i].cmd; i++)
    free(commands[i].cmd);
  free(commands);
}
