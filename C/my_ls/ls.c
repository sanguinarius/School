/*
** ls.c for ls.c in /Users/laxa/Documents/C/my_ls/egloff_j
** 
** Made by Julien EGLOFF
** Login   <egloff_j@etna-alternance.net>
** 
** Started on  Wed Aug  6 14:33:56 2014 Julien EGLOFF
** Last update Wed Aug 13 15:02:44 2014 Julien EGLOFF
*/

#include <sys/types.h>
#include <uuid/uuid.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <time.h>
#include <grp.h>
#include <pwd.h>

#include "my_ls.h"
#include "libmy.h"

void		ls_dir(DIR *dir, t_opt opt, char *path)
{
  struct dirent	*cur;
  char	fullpath[100];

  while ((cur = readdir(dir)))
    {
      if (cur->d_name[0] == '.' && opt.a == 0)
	continue;
      if (opt.l == 1)
	{
	  my_strcpy(fullpath, "");
	  my_strcat(fullpath, path);
	  my_strcat(fullpath, "/");
	  my_strcat(fullpath, cur->d_name);
	  aff_l(cur, fullpath);
	}
      else
	{
	  my_putstr(cur->d_name);
	  my_putchar('\n');
	}
    }
}

void	aff_l(struct dirent *cur, char *path)
{
  struct stat	buf;
  struct passwd	*wd;
  struct group	*gr;
  char		*time;
  int		i;

  stat(path, &buf);
  if (S_ISLNK(buf.st_mode))
    my_putstr("l");
  else if (S_ISREG(buf.st_mode))
    my_putstr("-");
  else if (S_ISDIR(buf.st_mode))
    my_putstr("d");
  else if (S_ISCHR(buf.st_mode))
    my_putstr("c");
  else if (S_ISBLK(buf.st_mode))
    my_putstr("b");
  else if (S_ISFIFO(buf.st_mode))
    my_putstr("f");
  else if (S_ISSOCK(buf.st_mode))
    my_putstr("s");
  if (buf.st_mode & S_IRUSR)
    my_putstr("r");
  else
    my_putstr("-");
  if (buf.st_mode & S_IWUSR)
    my_putstr("w");
  else
    my_putstr("-");
  if (buf.st_mode & S_IXUSR)
    my_putstr("x");
  else
    my_putstr("-");
  if (buf.st_mode & S_IRGRP)
    my_putstr("r");
  else
    my_putstr("-");
  if (buf.st_mode & S_IWGRP)
    my_putstr("w");
  else
    my_putstr("-");
  if (buf.st_mode & S_IXGRP)
    my_putstr("x");
  else
    my_putstr("-");
  if (buf.st_mode & S_IROTH)
    my_putstr("r");
  else
    my_putstr("-");
  if (buf.st_mode & S_IWOTH)
    my_putstr("w");
  else
    my_putstr("-");
  if (buf.st_mode & S_IXOTH)
    my_putstr("x");
  else
    my_putstr("-");
  print_spaces(buf.st_nlink, 4);
  my_put_nbr(buf.st_nlink);
  my_putchar(' ');
  wd = getpwuid(buf.st_uid);
  my_putstr(wd->pw_name);
  my_putstr("  ");
  gr = getgrgid(buf.st_gid);
  my_putstr(gr->gr_name);
  print_spaces(buf.st_size, 7);
  my_put_nbr(buf.st_size);
  my_putchar(' ');
  time = ctime(&buf.st_mtimespec.tv_sec);
  time = &time[4];
  for (i = my_strlen(time) - 1; i > 11; i--)
    time[i] = '\0';
  my_putstr(time);
  my_putchar(' ');
  my_putstr(cur->d_name);
  my_putchar('\n');
}

void	print_spaces(int number, int spaces)
{
  int	len;
  int	nb;

  nb = number;
  len = 0;
  while (nb > 0)
    {
      len++;
      nb /= 10;
    }
  for (nb = spaces - len; nb != 0; nb--)
    my_putchar(' ');
}
