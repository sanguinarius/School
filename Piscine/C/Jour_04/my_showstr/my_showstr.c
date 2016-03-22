/*
** my_showstr.c for my_showstr in /Users/laxa/Documents/Piscine/C/Jour_04/egloff_j/my_showstr
** 
** Made by EGLOFF Julien
** Login   <laxa>
** 
** Started on  Fri Mar 28 16:08:16 2014 EGLOFF Julien
** Last update Fri Mar 28 16:59:47 2014 EGLOFF Julien
*/

#include <stdio.h>

int	my_showstr(char *str);
int	my_putnbr_base(int nbr, char *base);
int	my_strlen(char *str);
void	my_putchar(char c);

int	my_showstr(char *str)
{
  int	i;

  for (i = 0; str[i]; i++)
    {
      if (str[i] < 32 || str[i] > 126)
	{
	  my_putchar('\\');
	  if (str[i] <= 16)
	    my_putchar('0');
	  my_putnbr_base(str[i], "0123456789abcdef");
	}
      else
	my_putchar(str[i]);
    }
  return (0);
}

int	my_putnbr_base(int nbr, char *base)
{
  if (nbr < 0)
    {
      my_putchar('-');
      nbr *= -1;
    }
  if (nbr >= my_strlen(base) - 1)
    my_putnbr_base(nbr / my_strlen(base), base);
  my_putchar(base[nbr % my_strlen(base)]);
  return (1);
}

int	my_strlen(char *str)
{
  int	i;

  for (i = 0; str[i]; i++);
  return (i);
}
