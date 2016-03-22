/*
** main.c for main in /Users/laxa/Documents/C/my_ls/egloff_j
** 
** Made by Julien EGLOFF
** Login   <laxa>
** 
** Started on  Wed Aug  6 11:10:28 2014 Julien EGLOFF
** Last update Wed Aug 13 11:51:31 2014 Julien EGLOFF
*/

#include <dirent.h>
#include <stdlib.h>

#include "my_ls.h"
#include "libmy.h"

int	main(int ac, char **av)
{
  DIR	*dir;
  t_opt	opt;
  int	i;

  opt = init_struct(ac, av);
  opt = check_stdin(ac, av, opt);
  if (opt.standart == 1)
    {
      dir = xopendir(".");
      ls_dir(dir, opt, ".");
      xclosedir(dir);
    }
  for (i = 1; i < ac; i++)
    {
      dir = NULL;
      if (av[i][0] != '-')
	dir = xopendir(av[i]);
      if (dir != NULL)
	ls_dir(dir, opt, av[i]);
    }
  return (0);
}

t_opt	check_stdin(int ac, char **av, t_opt opt)
{
  int	i;
  int	file;

  opt.standart = 0;
  for (i = 1, file = 0; i < ac; i++)
    {
      if (av[i][0] == '-')
	continue;
      else
	file++;
    }
  if (file == 0)
    opt.standart = 1;
  return (opt);
}

t_opt	init_struct(int ac, char **av)
{
  t_opt	opt;
  int	ii;
  int	i;

  opt.l = 0;
  opt.a = 0;
  for (i = 1; i < ac; i++)
    {
      if (av[i][0] == '-')
	{
	  for (ii = 1; ii < my_strlen(av[i]); ii++)
	    {
	      if (av[i][ii] == 'l')
		opt.l = 1;
	      else if (av[i][ii] == 'a')
		opt.a = 1;
	      else
		ls_error(av[i][ii]);
	    }
	}
    }
  return (opt);
}

void	ls_error(char c)
{
  my_putstr("ls: illegal option -- ");
  my_putchar(c);
  my_putstr("\nusage: ls [-la] [file ...]\n");
  exit(-1);
}
