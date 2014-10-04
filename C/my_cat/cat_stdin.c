/*
** cat_stdin.c for cat_stdin in /Users/laxa/Documents/C/my_cat/egloff_j
** 
** Made by Julien EGLOFF
** Login   <egloff_j@etna-alternance.net>
** 
** Started on  Tue Jun 24 15:12:32 2014 Julien EGLOFF
** Last update Thu Jun 26 12:08:12 2014 Julien EGLOFF
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my_cat.h"
#include "libmy.h"

void	cat_stdin(t_opt opt)
{
  char	buffer[BUFFER_SIZE];
  int	line;
  int	i;

  line = 1;
  while (fgets(buffer, BUFFER_SIZE, stdin))
    {
      for (i = 0; buffer[i]; i++)
	{
	  if (opt.b == 1 && i == 0 && buffer[i] != '\n')
	    print_line(&line);
	  else if (opt.n == 1 && i == 0 && opt.b == 0)
	    print_line(&line);
	  if (opt.e == 1 && buffer[i] == '\n')
	    my_putchar('$');
	  my_putchar(buffer[i]);
	}
    }
}

void	print_line(int *line)
{
  print_spaces(*line);
  my_put_nbr(*line);
  my_putchar('\t');
  *line += 1;
}

void	print_spaces(int line)
{
  int	len;
  int	nb;

  nb = line;
  len = 0;
  while (nb > 0)
    {
      len++;
      nb /= 10;
    }
  for (nb = 6 - len; nb != 0; nb--)
    my_putchar(' ');
}
