/*
** ragnarok.h for ragnarok in /Users/laxa/Documents/Piscine/C/Battle for Midgar/felzin_f/quete1
** 
** Made by EGLOFF Julien
** Login   <egloff_j@etna-alternance.net>
** 
** Started on  Fri Apr  4 19:23:35 2014 EGLOFF Julien
** Last update Sat Apr  5 18:13:46 2014 EGLOFF Julien
*/

#ifndef __RAGNAROK_H__
# define __RAGNAROK_H__

# define	CLEAR_SCREEN	("\033[H\033[2J")
# define	HERO_MAX_HP	(100)
# define	HERO_MAX_MP	(30)

typedef struct	s_hero
{
  char		*name;
  int		pv;
  int		pm;
  int		potion;
  int		ether;
}		t_hero;

typedef struct		s_enemy
{
  char			*name;
  int			pv;
  int			pm;
  struct s_enemy	*next;
}			t_enemy;

typedef int	(*t_func)(t_hero **, t_enemy **);

typedef struct	s_cmd
{
  char		*cmd;
  t_func	f;
}		t_cmd;

char		*readLine(void);
void		ragnarok(char **av);
t_hero		*init_hero(char **av);
t_enemy		*init_enemy(void);
t_cmd  		*init_cmd(void);
int		func_hero_attack(t_hero **hero, t_enemy **enemy);
int		func_hero_slash(t_hero **hero, t_enemy **enemy);
int		func_hero_fire(t_hero **hero, t_enemy **enemy);
int		func_hero_thunder(t_hero **hero, t_enemy **enemy);
int		func_hero_stat(t_hero **hero, t_enemy **enemy);
int		func_hero_libra(t_hero **hero, t_enemy **enemy);
int		func_hero_heal(t_hero **hero, t_enemy **enemy);
int		func_hero_potion(t_hero **hero, t_enemy **enemy);
int		func_hero_ether(t_hero **hero, t_enemy **enemy);
int		func_help(t_hero **hero, t_enemy **enemy);
int		func_quit(t_hero **hero, t_enemy **enemy);
void		end(t_hero *hero, t_enemy *enemy, t_cmd *commands);
void		clear(t_hero *hero, t_enemy *enemy);
void		monster_attack(t_hero **hero, t_enemy **enemy);
void		func_monster_bite(t_hero **hero, t_enemy **enemy);
void		func_monster_earthquake(t_hero **hero, t_enemy **enemy);
void		func_monster_doom(t_hero **hero, t_enemy **enemy);
int		give_me_a_rand(int max);
void		clear_cmd(t_cmd *commands);
void		init_cmd2(t_cmd **cmd);
int		func_hero_attack_crit(t_hero **hero, t_enemy **enemy);
int		func_hero_slash_crit(t_hero **hero, t_enemy **enemy);
int		func_hero_fire_crit(t_hero **hero, t_enemy **enemy);
int		func_hero_thunder_crit(t_hero **hero, t_enemy **enemy);
int		func_hero_heal_crit(t_hero **hero, t_enemy **enemy);
void		func_monster_bite_crit(t_hero **hero, t_enemy **enemy);
void		func_monster_earthquake_crit(t_hero **hero, t_enemy **enemy);
void		func_monster_doom_crit(t_hero **hero, t_enemy **enemy);
t_enemy		*add_node(t_enemy *list);
int		check(t_hero **hero, t_enemy **enemy);

#endif /* __RAGNAROK_H__ */
