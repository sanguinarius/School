/*
** attack4.c for attack4.c for BFM in /Users/laxa/Documents/Piscine/C/Battle for Midgar/felzin_f/quete2
** 
** Made by EGLOFF Julien
** Login   <egloff_j@etna-alternance.net>
** 
** Started on  Sat Apr  5 15:53:09 2014 EGLOFF Julien
** Last update Sat Apr  5 15:58:29 2014 EGLOFF Julien
*/

#include "libmy.h"
#include "ragnarok.h"

int	func_hero_heal_crit(t_hero **hero, t_enemy **enemy)
{
  my_putstr("Hero ");
  my_putstr((*hero)->name);
  my_putstr(" use Heal\n");
  my_putstr("Critical Hit!\n");
  my_putstr("Hero ");
  my_putstr((*hero)->name);
  my_putstr(" gain ");
  my_put_nbr(HERO_MAX_HP - (*hero)->pv > 30 ?
	     30 : HERO_MAX_HP - (*hero)->pv);
  my_putstr(" PV\nHero lose 3 PM\n\n");;
  (*hero)->pm -= 3;
  (*hero)->pv += HERO_MAX_HP - (*hero)->pv > 30 ?
    30 : HERO_MAX_HP - (*hero)->pv;
  monster_attack(hero, enemy);
  return (0);
}
