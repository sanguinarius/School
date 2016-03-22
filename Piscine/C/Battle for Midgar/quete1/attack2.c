/*
** attack2.c for attack2.c for ragnarok in /Users/laxa/Documents/Piscine/C/Battle for Midgar/felzin_f/quete1
** 
** Made by EGLOFF Julien
** Login   <laxa>
** 
** Started on  Sat Apr  5 08:34:12 2014 EGLOFF Julien
** Last update Sat Apr  5 11:25:44 2014 EGLOFF Julien
*/

#include <stdlib.h>
#include "libmy.h"
#include "ragnarok.h"

int	func_hero_libra(t_hero **hero, t_ennemy **ennemy)
{
  my_putstr((*ennemy)->name);
  my_putchar('\n');
  my_putstr("|--PV : ");
  my_put_nbr((*ennemy)->pv);
  my_putchar('\n');
  my_putstr("|--PM : ");
  my_put_nbr((*ennemy)->pm);
  my_putchar('\n');
  (*hero)->pv = (*hero)->pv;
  my_putchar('\n');
  (*hero)->pm -= 1;
  monster_attack(hero, ennemy);
  return (0);
}

int	func_help(t_hero **hero, t_ennemy **ennemy)
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
  (*hero)->pv = (*hero)->pv;
  (*ennemy)->pv = (*ennemy)->pv;
  return (0);
}

int	func_quit(t_hero **hero, t_ennemy **ennemy)
{
  free((*hero)->name);
  free((*hero));
  free((*ennemy)->name);
  free((*ennemy));
  my_putstr("You leave the game\n");
  return (42);
}
