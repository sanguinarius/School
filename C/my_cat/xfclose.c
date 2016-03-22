/*
** xfclose.c for xfclose.c in /Users/laxa/Documents/C/my_cat/egloff_j
** 
** Made by Julien EGLOFF
** Login   <laxa>
** 
** Started on  Thu Jun 26 11:37:53 2014 Julien EGLOFF
** Last update Thu Jun 26 11:39:21 2014 Julien EGLOFF
*/

#include <string.h>
#include <stdio.h>
#include <errno.h>
#include "libmy.h"

int	xfclose(FILE *stream)
{
  int	ret;

  ret = fclose(stream);
  if (ret == EOF)
    {
      my_putstr("cat: ");
      my_putstr(strerror(errno));
      my_putchar('\n');
    }
  return (ret);
}
