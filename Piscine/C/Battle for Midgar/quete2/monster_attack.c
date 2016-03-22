/*
** monster_attack.c for monster_attack.c for BFM in /Users/laxa/Documents/Piscine/C/Battle for Midgar/felzin_f/quete1
** 
** Made by EGLOFF Julien
** Login   <laxa>
** 
** Started on  Sat Apr  5 10:26:19 2014 EGLOFF Julien
** Last update Sat Apr  5 18:02:22 2014 EGLOFF Julien
*/

#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "libmy.h"
#include "ragnarok.h"

void	monster_attack(t_hero **hero, t_enemy **enemy)
{
  int	nb;

  while (42)
    {
      nb = give_me_a_rand(3);
      if (nb == 0)
	{
	  func_monster_bite(hero, enemy);
	  return ;
	}
      else if (nb == 1)
	{
	  func_monster_earthquake(hero, enemy);
	  return ;
	}
      else if (nb == 2 && (*enemy)->pm >= 5)
	{
	  func_monster_doom(hero, enemy);
	  return ;
	}
    }
}

void	func_monster_bite(t_hero **hero, t_enemy **enemy)
{
  if (give_me_a_rand(100) < 10)
    func_monster_bite_crit(hero, enemy);
  else
    {
      my_putstr((*enemy)->name);
      my_putstr(" use bite\n");
      my_putstr("Hero ");
      my_putstr((*hero)->name);
      my_putstr(" lose 6 PV\n");
      (*hero)->pv -= 6;
    }
}

void	func_monster_earthquake(t_hero **hero, t_enemy **enemy)
{
  if (give_me_a_rand(100) < 10)
    func_monster_earthquake_crit(hero, enemy);
  else
    {
      my_putstr((*enemy)->name);
      my_putstr(" use earthquake\n");
      my_putstr("Hero ");
      my_putstr((*hero)->name);
      my_putstr(" lose 15 PV\n");
      my_putstr((*enemy)->name);
      my_putstr(" lose 3 PV\n");
      (*enemy)->pv -= 3;
      (*hero)->pv -= 15;
    }
}

void	func_monster_doom(t_hero **hero, t_enemy **enemy)
{
  if (give_me_a_rand(100) < 10)
    func_monster_doom_crit(hero, enemy);
  else
    {
      my_putstr((*enemy)->name);
      my_putstr(" use doom\n");
      my_putstr("Hero ");
      my_putstr((*hero)->name);
      my_putstr(" lose 11 PV\n");
      my_putstr((*enemy)->name);
      my_putstr(" lose 5 MP\n");
      (*enemy)->pm -= 5;
      (*hero)->pv -= 11;
    }
}

int	give_me_a_rand(int max)
{
  int	nb;

  nb = rand() % max;
  return (nb);
}
