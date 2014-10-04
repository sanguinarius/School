/*
** main.c for main.c in /Users/laxa/Documents/Piscine/C/Battle for Midgar/felzin_f/quete1
** 
** Made by EGLOFF Julien
** Login   <egloff_j@etna-alternance.net>
** 
** Started on  Fri Apr  4 19:21:54 2014 EGLOFF Julien
** Last update Sat Apr  5 18:12:28 2014 EGLOFF Julien
*/

#include <stdlib.h>
#include "libmy.h"
#include "ragnarok.h"

int	main(int ac, char **av)
{
  my_putstr(CLEAR_SCREEN);
  if (ac != 3)
    {
      my_putstr("USAGE: <-n> <Player name>\n");
      return (-1);
    }
  if (ac == 3)
    {
      if (my_strcmp("-n", av[1]) == 0)
	ragnarok(av);
      else
	my_putstr("USAGE: <-n> <Player name>\n");
    }
  return (0);
}

void		ragnarok(char **av)
{
  t_hero	*hero;
  t_ennemy     	*ennemy;
  char		*cmd;
  t_cmd		*commands;
  int		i;
  int		ret;

  commands = init_cmd();
  for (hero = init_hero(av), ennemy = init_ennemy(); hero->pv > 0 &&
	 ennemy->pv > 0;)
    {
      my_putstr("Your turn> ");
      cmd = readLine();
      for (i = 0, ret = 0; commands[i].cmd; i++)
	{
	  if (my_strcmp(cmd, commands[i].cmd) == 0)
	    ret = commands[i].f(&hero, &ennemy);
	}
      free(cmd);
      my_putchar('\n');
      if (ret == 42)
	return ;
    }
  end(hero, ennemy);
  clear_cmd(commands);
}

t_hero		*init_hero(char **av)
{
  t_hero	*new;

  new = malloc(sizeof(*new));
  if (!new)
    my_putstr("Malloc failed in init_hero\n");
  else
    {
      new->name = my_strdup(av[2]);
      new->pv = 100;
      new->pm = 30;
    }
  return (new);
}

t_ennemy	*init_ennemy(void)
{
  t_ennemy	*new;

  new = malloc(sizeof(*new));
  if (!new)
    my_putstr("Malloc failed in init_ennemy\n");
  else
    {
      new->name = my_strdup("Regis");
      new->pv = 75;
      new->pm = 20;
    }
  return (new);
}

t_cmd  		*init_cmd(void)
{
  t_cmd		*cmd;

  cmd = malloc(sizeof(*cmd) * 9);
  if (!cmd)
    my_putstr("Malloc failed in init_cmd\n");
  cmd[0].cmd = my_strdup("attack");
  cmd[0].f = func_hero_attack;
  cmd[1].cmd = my_strdup("slash");
  cmd[1].f = func_hero_slash;
  cmd[2].cmd = my_strdup("fire");
  cmd[2].f = func_hero_fire;
  cmd[3].cmd = my_strdup("thunder");
  cmd[3].f = func_hero_thunder;
  cmd[4].cmd = my_strdup("stat");
  cmd[4].f = func_hero_stat;
  cmd[5].cmd = my_strdup("libra");
  cmd[5].f = func_hero_libra;
  cmd[6].cmd = my_strdup("help");
  cmd[6].f = func_help;
  cmd[7].cmd = my_strdup("quit");
  cmd[7].f = func_quit;
  cmd[8].cmd = NULL;
  return (cmd);
}
