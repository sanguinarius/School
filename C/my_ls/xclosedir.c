/*
** xclosedir.c for xclosedir in /Users/laxa/Documents/C/my_ls/egloff_j
** 
** Made by Julien EGLOFF
** Login   <egloff_j@etna-alternance.net>
** 
** Started on  Wed Aug  6 12:20:58 2014 Julien EGLOFF
** Last update Wed Aug  6 12:27:36 2014 Julien EGLOFF
*/

#include <string.h>
#include <dirent.h>
#include <errno.h>

#include "libmy.h"

int	xclosedir(DIR *dirp)
{
  int	ret;

  ret = closedir(dirp);
  if (ret == -1)
    {
      my_putstr("ls: ");
      my_putstr(strerror(errno));
      my_putchar('\n');
    }
  return (ret);
}
