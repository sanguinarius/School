/*
** xfopen.c for xfopen.c in /Users/laxa/Documents/C/my_cat/egloff_j
** 
** Made by Julien EGLOFF
** Login   <laxa>
** 
** Started on  Thu Jun 26 11:33:43 2014 Julien EGLOFF
** Last update Thu Jun 26 11:38:58 2014 Julien EGLOFF
*/

#include <string.h>
#include <stdio.h>
#include <errno.h>
#include "libmy.h"

FILE	*xfopen(const char *filename, const char *mode)
{
  FILE	*ret;

  ret = fopen(filename, mode);
  if (ret == NULL)
    {
      my_putstr("cat: ");
      my_putstr(filename);
      my_putstr(": ");
      my_putstr(strerror(errno));
      my_putchar('\n');
    }
  return (ret);
}
