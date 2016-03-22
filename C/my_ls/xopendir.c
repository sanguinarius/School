/*
** xopendir.c for xopendir.c in /Users/laxa/Documents/C/my_ls/egloff_j
** 
** Made by Julien EGLOFF
** Login   <laxa>
** 
** Started on  Wed Aug  6 12:17:19 2014 Julien EGLOFF
** Last update Wed Aug  6 12:28:01 2014 Julien EGLOFF
*/

#include <dirent.h>
#include <string.h>
#include <errno.h>

#include "libmy.h"

DIR	*xopendir(const char *dirname)
{
  DIR	*dir;

  dir = opendir(dirname);
  if (dir == NULL)
    {
      my_putstr("ls: ");
      my_putstr(dirname);
      my_putstr(": ");
      my_putstr(strerror(errno));
      my_putchar('\n');
    }
  return (dir);
}
