/*
** attack2.c for attack2.c for ragnarok in /Users/laxa/Documents/Piscine/C/Battle for Midgar/felzin_f/quete1
** 
** Made by EGLOFF Julien
** Login   <laxa>
** 
** Started on  Sat Apr  5 08:34:12 2014 EGLOFF Julien
** Last update Sat Apr  5 17:58:19 2014 EGLOFF Julien
*/

#include <stdlib.h>
#include "libmy.h"
#include "ragnarok.h"

int	func_hero_libra(t_hero **hero, t_enemy **enemy)
{
  my_putstr((*enemy)->name);
  my_putchar('\n');
  my_putstr("|--PV : ");
  my_put_nbr((*enemy)->pv);
  my_putchar('\n');
  my_putstr("|--PM : ");
  my_put_nbr((*enemy)->pm);
  my_putstr("\n\n");
  (*hero)->pm -= 1;
  monster_attack(hero, enemy);
  return (0);
}

int	func_help(t_hero **hero, t_enemy **enemy)
{
  my_putstr("List of existing commands\n");
  my_putstr("|--help\n");
  my_putstr("|--stat\n");
  my_putstr("|--quit\n");
  my_putstr("|--libra\n");
  my_putstr("|--attack\n");
  my_putstr("|--slash\n");
  my_putstr("|--fire\n");
  my_putstr("|--thunder\n");
  my_putstr("|--potionr\n");
  my_putstr("|--ether\n");
  my_putstr("|--heal\n");
  (*hero)->pv = (*hero)->pv;
  (*enemy)->pv = (*enemy)->pv;
  return (0);
}

int	func_quit(t_hero **hero, t_enemy **enemy)
{
  free((*hero)->name);
  free((*hero));
  free((*enemy)->name);
  free((*enemy));
  my_putstr("You leave the game\n");
  return (42);
}

int	func_hero_potion(t_hero **hero, t_enemy **enemy)
{
  if ((*hero)->potion > 0)
    {
      my_putstr("Hero ");
      my_putstr((*hero)->name);
      my_putstr(" use Potion\nHero ");
      my_putstr((*hero)->name);
      my_putstr(" gain ");
      my_put_nbr(HERO_MAX_HP - (*hero)->pv > 30 ?
		 30 : HERO_MAX_HP - (*hero)->pv);
      my_putstr(" PV\nhero lose 1 Potion\n\n");
      (*hero)->potion -= 1;
      (*hero)->pv += HERO_MAX_HP - (*hero)->pv > 30 ?
	30 : HERO_MAX_HP - (*hero)->pv;
      monster_attack(hero, enemy);
    }
  else
    my_putstr("Hero doesn't have any potion\n");
  return (0);
}

int	func_hero_ether(t_hero **hero, t_enemy **enemy)
{
  if ((*hero)->ether > 0)
    {
      my_putstr("Hero ");
      my_putstr((*hero)->name);
      my_putstr(" use Ether\nHero ");
      my_putstr((*hero)->name);
      my_putstr(" gain ");
      my_put_nbr(HERO_MAX_MP - (*hero)->pm > 12 ?
		 12 : HERO_MAX_MP - (*hero)->pm);
      my_putstr(" PM\nhero lose 1 Ether\n\n");
      (*hero)->ether -= 1;
      (*hero)->pm += HERO_MAX_MP - (*hero)->pm > 12 ?
	12 : HERO_MAX_MP - (*hero)->pm;
      monster_attack(hero, enemy);
    }
  else
    my_putstr("Hero doesn't have any ether\n");
  return (0);
}
