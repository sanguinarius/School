/*
** my_showmem.c for my_showmem in /Users/laxa/Documents/Piscine/C/Jour_04/egloff_j/my_showmem
** 
** Made by EGLOFF Julien
** Login   <laxa>
** 
** Started on  Fri Mar 28 17:02:03 2014 EGLOFF Julien
** Last update Fri Mar 28 17:37:42 2014 EGLOFF Julien
*/

#include <stdio.h>

int	my_showmem(char *str, int size);
void	my_putchar(char c);
int	my_putnbr_base(int nbr, char *base);
int	my_strlen(char *str);
void	aff_string(char *str, int i);

int	my_showmem(char *str, int size)
{
  int	i;

  for (i = 0; i < size; i++)
    {
      if ((i % 16 == 0 && i != 0) || (i + 1 == size))
	aff_string(str, i);
      if (i == 0 || i % 16 == 0)
	{
	  my_putnbr_base((int)&str[i], "0123456789abcdef");
	  my_putchar(':');
	  my_putchar(' ');
	}
      if (i % 2 == 0 && i % 16 != 0)
	my_putchar(' ');
      my_putnbr_base(str[i], "0123456789abcdef");
    }
  return (0);
}

void	aff_string(char *str, int i)
{
  int	ii;

  my_putchar(' ');
  for (ii = i - 16; ii < i; ii++)
    {
      if (str[ii] < 32 || str[i] > 126)
	my_putchar('.');
      else
	my_putchar(str[ii]);
    }
  my_putchar('\n');
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
