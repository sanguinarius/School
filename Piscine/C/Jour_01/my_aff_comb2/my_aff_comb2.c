/*
** my_aff_comb2.c for my_aff_comb2 in /Users/laxa/Documents/Piscine/C/Jour_01/egloff_j/my_aff_comb2
** 
** Made by EGLOFF Julien
** Login   <egloff_j@etna-alternance.net>
** 
** Started on  Mon Mar 24 11:46:29 2014 EGLOFF Julien
** Last update Mon Mar 24 17:57:00 2014 EGLOFF Julien
*/

#include <stdio.h>

int	my_aff_comb2();
void	my_putchar(char c);
void	print_nbr(int a, int b, int c, int d);

int	my_aff_comb2()
{
  int	a;
  int	b;
  int	c;
  int	d;

  for (a = '0'; a <= '9'; a++)
    {
      for (b = '0'; b <= '9'; b++)
	{
	  for (c = '0'; c <= '9'; c++)
	    {
	      for (d = '0'; d <= '9'; d++)
		{
		  print_nbr(a, b, c, d);
		}
	    }
	}
    }
  return (0);
}

void	print_nbr(int a, int b, int c, int d)
{
  int	tmp;
  int	tmp2;

  tmp = ((a - '0') * 10) + b - '0';
  tmp2 = ((c - '0') * 10) + d - '0';
  if (tmp < tmp2 && (a + b) != 114)
    {
      my_putchar(a);
      my_putchar(b);
      my_putchar(' ');
      my_putchar(c);
      my_putchar(d);
      if (((a + b) != 113) || ((c + d) != 114))
	{
	  my_putchar(',');
	  my_putchar(' ');
	}
    }
}
