/*
** attack3.c for attack3.c for BFM in /Users/laxa/Documents/Piscine/C/Battle for Midgar/felzin_f/quete2
** 
** Made by EGLOFF Julien
** Login   <laxa>
** 
** Started on  Sat Apr  5 12:17:44 2014 EGLOFF Julien
** Last update Sat Apr  5 18:01:30 2014 EGLOFF Julien
*/

#include "libmy.h"
#include "ragnarok.h"

int	func_hero_heal(t_hero **hero, t_enemy **enemy)
{
  if ((*hero)->pm >= 3)
    {
      if (give_me_a_rand(100) < 10)
	func_hero_heal_crit(hero, enemy);
      else
	{
	  my_putstr("Hero ");
	  my_putstr((*hero)->name);
	  my_putstr(" use Heal\n");
	  my_putstr("Hero ");
	  my_putstr((*hero)->name);
	  my_putstr(" gain ");
	  my_put_nbr(HERO_MAX_HP - (*hero)->pv > 25 ?
		     25 : HERO_MAX_HP - (*hero)->pv);
	  my_putstr(" PV\nHero lose 3 PM\n\n");;
	  (*hero)->pm -= 3;
	  (*hero)->pv += HERO_MAX_HP - (*hero)->pv > 25 ?
	    25 : HERO_MAX_HP - (*hero)->pv;
	  monster_attack(hero, enemy);
	}
    }
  else
    my_putstr("Hero has not enough MP to use heal\n");
  return (0);
}

int	func_hero_attack_crit(t_hero **hero, t_enemy **enemy)
{
  my_putstr("Hero ");
  my_putstr((*hero)->name);
  my_putstr(" use attack\n");
  my_putstr("Critical Hit!\n");
  my_putstr((*enemy)->name);
  my_putstr(" lose 8 PV\n\n");
  (*enemy)->pv -= 8;
  monster_attack(hero, enemy);
  return (0);
}

int	func_hero_slash_crit(t_hero **hero, t_enemy **enemy)
{
  my_putstr("Hero ");
  my_putstr((*hero)->name);
  my_putstr(" use slash\n");
  my_putstr("Critical Hit!\n");
  my_putstr((*enemy)->name);
  my_putstr(" lose 12 PV\n");
  my_putstr("Hero lose 2 PV\n\n");
  (*enemy)->pv -= 12;
  (*hero)->pv -= 2;
  monster_attack(hero, enemy);
  return (0);
}

int	func_hero_fire_crit(t_hero **hero, t_enemy **enemy)
{
  my_putstr("Hero ");
  my_putstr((*hero)->name);
  my_putstr(" use fire\n");
  my_putstr("Critical Hit!\n");
  my_putstr((*enemy)->name);
  my_putstr(" lose 12 PV\n");
  my_putstr("Hero lose 3 PM\n\n");
  (*enemy)->pv -= 12;
  (*hero)->pm -= 3;
  monster_attack(hero, enemy);
  return (0);
}

int	func_hero_thunder_crit(t_hero **hero, t_enemy **enemy)
{
  my_putstr("Hero ");
  my_putstr((*hero)->name);
  my_putstr(" use thunder\n");
  my_putstr((*enemy)->name);
  my_putstr(" lose 18 PV\n");
  my_putstr("Hero lose 5 PM\n\n");
  (*enemy)->pv -= 18;
  (*hero)->pm -= 5;
  monster_attack(hero, enemy);
  return (0);
}
