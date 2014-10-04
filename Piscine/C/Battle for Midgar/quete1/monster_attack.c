/*
** monster_attack.c for monster_attack.c for BFM in /Users/laxa/Documents/Piscine/C/Battle for Midgar/felzin_f/quete1
** 
** Made by EGLOFF Julien
** Login   <egloff_j@etna-alternance.net>
** 
** Started on  Sat Apr  5 10:26:19 2014 EGLOFF Julien
** Last update Sat Apr  5 11:22:45 2014 EGLOFF Julien
*/

#include <stdlib.h>
#include <time.h>
#include "libmy.h"
#include "ragnarok.h"

void	monster_attack(t_hero **hero, t_ennemy **ennemy)
{
  int	nb;

  while (42)
    {
      nb = give_me_a_rand(3);
      if (nb == 0)
	{
	  func_monster_bite(hero, ennemy);
	  return ;
	}
      else if (nb == 1)
	{
	  func_monster_earthquake(hero, ennemy);
	  return ;
	}
      else if (nb == 2 && (*ennemy)->pm >= 5)
	{
	  func_monster_doom(hero, ennemy);
	  return ;
	}
    }
}

void	func_monster_bite(t_hero **hero, t_ennemy **ennemy)
{
  my_putstr((*ennemy)->name);
  my_putstr(" use bite\n");
  my_putstr("Hero ");
  my_putstr((*hero)->name);
  my_putstr(" lose 6 PV\n");
  (*hero)->pv -= 6;
  (*ennemy)->pv = (*ennemy)->pv;
}

void	func_monster_earthquake(t_hero **hero, t_ennemy **ennemy)
{
  my_putstr((*ennemy)->name);
  my_putstr(" use earthquake\n");
  my_putstr("Hero ");
  my_putstr((*hero)->name);
  my_putstr(" lose 15 PV\n");
  my_putstr((*ennemy)->name);
  my_putstr(" lose 3 PV\n");
  (*ennemy)->pv -= 3;
  (*hero)->pv -= 15;
}

void	func_monster_doom(t_hero **hero, t_ennemy **ennemy)
{
  my_putstr((*ennemy)->name);
  my_putstr(" use doom\n");
  my_putstr("Hero ");
  my_putstr((*hero)->name);
  my_putstr(" lose 11 PV\n");
  my_putstr((*ennemy)->name);
  my_putstr(" lose 5 MP\n");
  (*ennemy)->pm -= 5;
  (*hero)->pv -= 11;
}

int	give_me_a_rand(int max)
{
  int	nb;

  srand(time(NULL));
  nb = rand() % max;
  return (nb);
}
