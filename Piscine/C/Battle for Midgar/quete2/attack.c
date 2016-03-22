/*
** attack.c for attack for ragnarok in /Users/laxa/Documents/Piscine/C/Battle for Midgar/felzin_f/quete1
** 
** Made by EGLOFF Julien
** Login   <laxa>
** 
** Started on  Sat Apr  5 08:32:36 2014 EGLOFF Julien
** Last update Sat Apr  5 18:01:10 2014 EGLOFF Julien
*/

#include "libmy.h"
#include "ragnarok.h"

int	func_hero_attack(t_hero **hero, t_enemy **enemy)
{
  if (give_me_a_rand(100) < 10)
    func_hero_attack_crit(hero, enemy);
  else
    {
      my_putstr("Hero ");
      my_putstr((*hero)->name);
      my_putstr(" use attack\n");
      my_putstr((*enemy)->name);
      my_putstr(" lose 7 PV\n\n");
      (*enemy)->pv -= 7;
      monster_attack(hero, enemy);
    }
  return (0);
}

int	func_hero_slash(t_hero **hero, t_enemy **enemy)
{
  if (give_me_a_rand(100) < 10)
    func_hero_slash_crit(hero, enemy);
  else
    {
      my_putstr("Hero ");
      my_putstr((*hero)->name);
      my_putstr(" use slash\n");
      my_putstr((*enemy)->name);
      my_putstr(" lose 10 PV\n");
      my_putstr("Hero lose 2 PV\n\n");
      (*enemy)->pv -= 10;
      (*hero)->pv -= 2;
      monster_attack(hero, enemy);
    }
  return (0);
}

int	func_hero_fire(t_hero **hero, t_enemy **enemy)
{
  if ((*hero)->pm >= 3)
    {
      if (give_me_a_rand(100) < 10)
	func_hero_fire_crit(hero, enemy);
      else
	{
	  my_putstr("Hero ");
	  my_putstr((*hero)->name);
	  my_putstr(" use fire\n");
	  my_putstr((*enemy)->name);
	  my_putstr(" lose 10 PV\n");
	  my_putstr("Hero lose 3 PM\n\n");
	  (*enemy)->pv -= 10;
	  (*hero)->pm -= 3;
	  monster_attack(hero, enemy);
	}
    }
  else
    my_putstr("Hero laxa can't use fire MP too low\n");
  return (0);
}

int	func_hero_thunder(t_hero **hero, t_enemy **enemy)
{
  if ((*hero)->pm >= 5)
    {
      if (give_me_a_rand(100) < 10)
	func_hero_thunder_crit(hero, enemy);
      else
	{
	  my_putstr("Hero ");
	  my_putstr((*hero)->name);
	  my_putstr(" use thunder\n");
	  my_putstr((*enemy)->name);
	  my_putstr(" lose 15 PV\n");
	  my_putstr("Hero lose 5 PM\n\n");
	  (*enemy)->pv -= 15;
	  (*hero)->pm -= 5;
	  monster_attack(hero, enemy);
	}
    }
  else
    my_putstr("Hero laxa can't use thunder MP too low\n");
  return (0);
}

int	func_hero_stat(t_hero **hero, t_enemy **enemy)
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
  my_putstr("|--Ether : ");
  my_put_nbr((*hero)->ether);
  my_putchar('\n');
  my_putstr("|--Potion : ");
  my_put_nbr((*hero)->potion);
  my_putchar('\n');
  (*enemy)->pv = (*enemy)->pv;
  return (0);
}
