/*
** monster_attack2.c for monster_attack2.c in /Users/laxa/Documents/Piscine/C/Battle for Midgar/felzin_f/quete2
** 
** Made by EGLOFF Julien
** Login   <egloff_j@etna-alternance.net>
** 
** Started on  Sat Apr  5 15:59:00 2014 EGLOFF Julien
** Last update Sat Apr  5 16:05:04 2014 EGLOFF Julien
*/

#include "libmy.h"
#include "ragnarok.h"

void	func_monster_bite_crit(t_hero **hero, t_enemy **enemy)
{
  my_putstr((*enemy)->name);
  my_putstr(" use bite\n");
  my_putstr("Critical Hit!\n");
  my_putstr("Hero ");
  my_putstr((*hero)->name);
  my_putstr(" lose 7 PV\n");
  (*hero)->pv -= 7;
  (*enemy)->pv = (*enemy)->pv;
}

void	func_monster_earthquake_crit(t_hero **hero, t_enemy **enemy)
{
  my_putstr((*enemy)->name);
  my_putstr(" use earthquake\n");
  my_putstr("Critical Hit!\n");
  my_putstr("Hero ");
  my_putstr((*hero)->name);
  my_putstr(" lose 18 PV\n");
  my_putstr((*enemy)->name);
  my_putstr(" lose 3 PV\n");
  (*enemy)->pv -= 3;
  (*hero)->pv -= 18;
}

void	func_monster_doom_crit(t_hero **hero, t_enemy **enemy)
{
  my_putstr((*enemy)->name);
  my_putstr(" use doom\n");
  my_putstr("Critical Hit!\n");
  my_putstr("Hero ");
  my_putstr((*hero)->name);
  my_putstr(" lose 13 PV\n");
  my_putstr((*enemy)->name);
  my_putstr(" lose 5 MP\n");
  (*enemy)->pm -= 5;
  (*hero)->pv -= 13;
}
