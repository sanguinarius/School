/*
** attack.c for attack for ragnarok in /Users/laxa/Documents/Piscine/C/Battle for Midgar/felzin_f/quete1
** 
** Made by EGLOFF Julien
** Login   <egloff_j@etna-alternance.net>
** 
** Started on  Sat Apr  5 08:32:36 2014 EGLOFF Julien
** Last update Sat Apr  5 11:14:04 2014 EGLOFF Julien
*/

#include "libmy.h"
#include "ragnarok.h"

int	func_hero_attack(t_hero **hero, t_ennemy **ennemy)
{
  my_putstr("Hero ");
  my_putstr((*hero)->name);
  my_putstr(" use attack\n");
  my_putstr((*ennemy)->name);
  my_putstr(" lose 7 PV\n");
  (*ennemy)->pv -= 7;
  my_putchar('\n');
  monster_attack(hero, ennemy);
  return (0);
}

int	func_hero_slash(t_hero **hero, t_ennemy **ennemy)
{
  my_putstr("Hero ");
  my_putstr((*hero)->name);
  my_putstr(" use slash\n");
  my_putstr((*ennemy)->name);
  my_putstr(" lose 10 PV\n");
  my_putstr("Hero lose 2 PV\n");
  (*ennemy)->pv -= 10;
  (*hero)->pv -= 2;
  my_putchar('\n');
  monster_attack(hero, ennemy);
  return (0);
}

int	func_hero_fire(t_hero **hero, t_ennemy **ennemy)
{
  if ((*hero)->pm >= 3)
    {
      my_putstr("Hero ");
      my_putstr((*hero)->name);
      my_putstr(" use fire\n");
      my_putstr((*ennemy)->name);
      my_putstr(" lose 10 PV\n");
      my_putstr("Hero lose 3 PM\n");
      (*ennemy)->pv -= 10;
      (*hero)->pm -= 3;
      my_putchar('\n');
      monster_attack(hero, ennemy);
    }
  else
    my_putstr("Hero laxa can't use fire MP too low\n");
  return (0);
}

int	func_hero_thunder(t_hero **hero, t_ennemy **ennemy)
{
  if ((*hero)->pm >= 5)
    {
      my_putstr("Hero ");
      my_putstr((*hero)->name);
      my_putstr(" use thunder\n");
      my_putstr((*ennemy)->name);
      my_putstr(" lose 15 PV\n");
      my_putstr("Hero lose 5 PM\n");
      (*ennemy)->pv -= 15;
      (*hero)->pm -= 5;
      my_putchar('\n');
      monster_attack(hero, ennemy);
    }
  else
    my_putstr("Hero laxa can't use thunder MP too low\n");
  return (0);
}

int	func_hero_stat(t_hero **hero, t_ennemy **ennemy)
{
  my_putstr("Hero : ");
  my_putstr((*hero)->name);
  my_putchar('\n');
  my_putstr("|--PV : ");
  my_put_nbr((*hero)->pv);
  my_putchar('\n');
  my_putstr("|--PM : ");
  my_put_nbr((*hero)->pm);
  my_putchar('\n');
  (*ennemy)->pv = (*ennemy)->pv;
  return (0);
}
