/*
** my_getnbr_base.c for my_getnbr_base in /Users/laxa/Documents/Piscine/C/Jour_04/egloff_j/my_getnbr_base
** 
** Made by EGLOFF Julien
** Login   <egloff_j@etna-alternance.net>
** 
** Started on  Fri Mar 28 14:57:41 2014 EGLOFF Julien
** Last update Fri Mar 28 18:50:29 2014 EGLOFF Julien
*/

#include <stdio.h>

int	my_getnbr_base(char *str, char *base);
int	my_strlen(char *str);
int	find_pos(char c, char *str);

int	my_getnbr_base(char *str, char *base)
{
  int	nb;
  int	i;
  int	fac;

  nb = 0;
  fac = 1;
  if (str[0] == '-')
    return (-my_getnbr_base(&str[1], base));
  for (i = my_strlen(str) - 1; i >= 0; i--)
    {
      nb = nb + find_pos(str[i], base) * fac;
      fac *= my_strlen(base);
    }
  return (nb);
}

int	my_strlen(char *str)
{
  int	i;

  for (i = 0; str[i]; i++);
  return (i);
}

int	find_pos(char c, char *str)
{
  int	i;

  for (i = 0; str[i]; i++)
    {
      if (str[i] == c)
	return (i);
    }
  return (0);
}
