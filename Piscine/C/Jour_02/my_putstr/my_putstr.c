/*
** my_putstr.c for my_putstr in /Users/laxa/Documents/Piscine/C/Jour_02/egloff_j/my_putstr
** 
** Made by EGLOFF Julien
** Login   <laxa>
** 
** Started on  Tue Mar 25 09:41:00 2014 EGLOFF Julien
** Last update Tue Mar 25 17:04:48 2014 EGLOFF Julien
*/

#include <unistd.h>

int	my_putstr(char *str);
void	my_putchar(char c);

int	my_putstr(char *str)
{
  int	i;

  for (i = 0; str[i]; i++)
    write(1, &str[i], 1);
  return (0);
}
