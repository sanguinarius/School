/*
** my_aff_combn.c for my_aff_combn in /Users/laxa/Documents/Piscine/C/Jour_01/egloff_j/my_aff_combn
** 
** Made by EGLOFF Julien
** Login   <egloff_j@etna-alternance.net>
** 
** Started on  Mon Mar 24 12:41:23 2014 EGLOFF Julien
** Last update Mon Mar 24 14:12:07 2014 EGLOFF Julien
*/

int	my_aff_combn(int n);
void	my_putchar(char c);
int	my_put_nbr(int nb);

int	my_aff_combn(int n)
{
  int	nb;

  while (n)
    {
      for (nb = 0; nb <= 9; nb++)
	{
	  my_aff_combn(n - 1);
	  my_putchar(nb + '0');
	  if (nb != 9)
	    {
	      my_putchar(',');
	      my_putchar(' ');
	    }
	}
    }
  return (0);
}

int	my_put_nbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      nb *= -1;
    }
  if (nb >= 10)
    {
      my_put_nbr(nb / 10);
    }
  my_putchar(nb % 10 + '0');
  return (0);
}
