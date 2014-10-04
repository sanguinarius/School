/*
** main2.c for main2.c for BFM in /Users/laxa/Documents/Piscine/C/Battle for Midgar/felzin_f/quete1
** 
** Made by EGLOFF Julien
** Login   <egloff_j@etna-alternance.net>
** 
** Started on  Sat Apr  5 10:16:52 2014 EGLOFF Julien
** Last update Sat Apr  5 17:45:25 2014 EGLOFF Julien
*/

#include <stdlib.h>
#include "libmy.h"
#include "ragnarok.h"

void	end(t_hero *hero, t_enemy *enemy, t_cmd *commands)
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
      my_putstr(enemy->name);
      my_putchar('\n');
      my_putstr("Congratulation, you won !!\n");
    }
  clear(hero, enemy);
  clear_cmd(commands);
}

void	clear(t_hero *hero, t_enemy *enemy)
{
  free(hero->name);
  free(hero);
  free(enemy->name);
  free(enemy);
}

void	clear_cmd(t_cmd *commands)
{
  int	i;

  for (i = 0; commands[i].cmd; i++)
    free(commands[i].cmd);
  free(commands);
}

void   	init_cmd2(t_cmd **cmd)
{
  (*cmd)[8].cmd = my_strdup("potion");
  (*cmd)[8].f = func_hero_potion;
  (*cmd)[9].cmd = my_strdup("ether");
  (*cmd)[9].f = func_hero_ether;
  (*cmd)[10].cmd = my_strdup("heal");
  (*cmd)[10].f = func_hero_heal;
  (*cmd)[11].cmd = NULL;
}

t_enemy		*add_node(t_enemy *list)
{
  t_enemy	*new;

  new = malloc(sizeof(*new));
  new->name = my_strdup("Regis");
  new->pv = 75;
  new->pm = 20;
  new->next = list;
  return (new);
}
