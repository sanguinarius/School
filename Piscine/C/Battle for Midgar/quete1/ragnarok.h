/*
** ragnarok.h for ragnarok in /Users/laxa/Documents/Piscine/C/Battle for Midgar/felzin_f/quete1
** 
** Made by EGLOFF Julien
** Login   <laxa>
** 
** Started on  Fri Apr  4 19:23:35 2014 EGLOFF Julien
** Last update Sat Apr  5 18:13:43 2014 EGLOFF Julien
*/

#ifndef __RAGNAROK_H__
# define __RAGNAROK_H__

# define	CLEAR_SCREEN	("\033[H\033[2J")

typedef struct	s_hero
{
  char		*name;
  int		pv;
  int		pm;
}		t_hero;

typedef struct	s_ennemy
{
  char		*name;
  int		pv;
  int		pm;
}		t_ennemy;

typedef int	(*t_func)(t_hero **, t_ennemy **);

typedef struct	s_cmd
{
  char		*cmd;
  t_func	f;
}		t_cmd;

char		*readLine(void);
void		ragnarok(char **av);
t_hero		*init_hero(char **av);
t_ennemy	*init_ennemy(void);
t_cmd  		*init_cmd(void);
int		func_hero_attack(t_hero **hero, t_ennemy **ennemy);
int		func_hero_slash(t_hero **hero, t_ennemy **ennemy);
int		func_hero_fire(t_hero **hero, t_ennemy **ennemy);
int		func_hero_thunder(t_hero **hero, t_ennemy **ennemy);
int		func_hero_stat(t_hero **hero, t_ennemy **ennemy);
int		func_hero_libra(t_hero **hero, t_ennemy **ennemy);
int		func_help(t_hero **hero, t_ennemy **ennemy);
int		func_quit(t_hero **hero, t_ennemy **ennemy);
void		end(t_hero *hero, t_ennemy *ennemy);
void		clear(t_hero *hero, t_ennemy *ennemy);
void		monster_attack(t_hero **hero, t_ennemy **ennemy);
void		func_monster_bite(t_hero **hero, t_ennemy **ennemy);
void		func_monster_earthquake(t_hero **hero, t_ennemy **ennemy);
void		func_monster_doom(t_hero **hero, t_ennemy **ennemy);
int		give_me_a_rand(int max);
void		clear_cmd(t_cmd *commands);

#endif /* __RAGNAROK_H__ */
