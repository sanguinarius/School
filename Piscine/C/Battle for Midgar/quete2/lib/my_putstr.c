/*
** my_putstr.c for my_putstr in /Users/laxa/Documents/Piscine/C/Jour_02/egloff_j/my_putstr
** 
** Made by EGLOFF Julien
** Login   <laxa>
** 
** Started on  Tue Mar 25 09:41:00 2014 EGLOFF Julien
** Last update Sat Mar 29 13:51:47 2014 EGLOFF Julien
*/

#include "libmy.h"

int	my_putstr(char *str)
{
  int	i;

  for (i = 0; str[i]; i++)
    my_putchar(str[i]);
  return (0);
}
