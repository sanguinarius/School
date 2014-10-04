/*
** cat_file.c for cat_file.c in /Users/laxa/Documents/C/my_cat/egloff_j
** 
** Made by Julien EGLOFF
** Login   <egloff_j@etna-alternance.net>
** 
** Started on  Tue Jun 24 16:51:47 2014 Julien EGLOFF
** Last update Fri Jul  4 15:23:04 2014 Julien EGLOFF
*/

#include <unistd.h>
#include <stdio.h>
#include "my_cat.h"
#include "libmy.h"

void		cat_file(t_opt opt, FILE *file)
{
  char	buffer[BUFFER_SIZE];
  int	line;
  int	i;

  line = 1;
  while (fgets(buffer, BUFFER_SIZE, file))
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
