/*
** main.c for my_cat in /Users/laxa/Documents/C/my_cat/egloff_j
** 
** Made by Julien EGLOFF
** Login   <egloff_j@etna-alternance.net>
** 
** Started on  Tue Jun 10 15:40:39 2014 Julien EGLOFF
** Last update Thu Jun 26 12:14:05 2014 Julien EGLOFF
*/

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "my_cat.h"
#include "libmy.h"

int	main(int ac, char **av)
{
  FILE	*file;
  int	i;
  t_opt	opt;

  opt = init_struct(ac, av);
  opt = check_stdin(ac, av, opt);
  if (opt.stdin == 1)
    cat_stdin(opt);
  for (i = 1; i < ac; i++)
    {
      file = NULL;
      if (av[i][0] != '-')
	file = xfopen(av[i], "r");
      if (file != NULL)
	{
	  cat_file(opt, file);
	  xfclose(file);
	}
    }
  return (0);
}

t_opt	check_stdin(int ac, char **av, t_opt opt)
{
  int	i;
  int	file;

  opt.stdin = 0;
  for (i = 1, file = 0; i < ac; i++)
    {
      if (av[i][0] == '-')
	continue;
      else
	file++;
    }
  if (file == 0)
    opt.stdin = 1;
  return (opt);
}

t_opt	init_struct(int ac, char **av)
{
  t_opt	opt;
  int	ii;
  int	i;

  opt.e = 0;
  opt.b = 0;
  opt.n = 0;
  for (i = 1; i < ac; i++)
    {
      if (av[i][0] == '-')
	{
	  for (ii = 1; ii < my_strlen(av[i]); ii++)
	    {
	      if (av[i][ii] == 'e')
		opt.e = 1;
	      else if (av[i][ii] == 'b')
		opt.b = 1;
	      else if (av[i][ii] == 'n')
		opt.n = 1;
	      else
		cat_error(av[i][ii]);
	    }
	}
    }
  return (opt);
}

void	cat_error(char c)
{
  my_putstr("cat: illegal option -- ");
  my_putchar(c);
  my_putstr("\nusage: cat [-ben] [file ...]\n");
  exit(-1);
}
