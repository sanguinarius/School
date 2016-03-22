/*
** my_ls.h for my_ls.h in /Users/laxa/Documents/C/my_ls/egloff_j
** 
** Made by Julien EGLOFF
** Login   <laxa>
** 
** Started on  Wed Aug  6 12:26:46 2014 Julien EGLOFF
** Last update Wed Aug 13 12:19:33 2014 Julien EGLOFF
*/

#ifndef __MY_LS_H__
# define __MY_LS_H__

typedef struct	s_opt
{
  int		l;
  int		a;
  int		standart;
}		t_opt;

/* main.c */
t_opt	check_stdin(int ac, char **av, t_opt opt);
t_opt	init_struct(int ac, char **av);
void	ls_error(char c);
/* xclosedir.c */
int	xclosedir(DIR *dirp);
/* xopendir.c */
DIR	*xopendir(const char *dirname);
/* ls.c */
void	ls_dir(DIR *dir, t_opt opt, char *path);
void	aff_l(struct dirent *cur, char *path);
void	print_spaces(int number, int spaces);

#endif /*__MY_LS_H__ */
