/*
** my_aff_comb.c for my_aff_comb in /Users/laxa/Documents/Piscine/C/Jour_01/egloff_j/my_aff_comb
** 
** Made by EGLOFF Julien
** Login   <laxa>
** 
** Started on  Mon Mar 24 11:09:30 2014 EGLOFF Julien
** Last update Mon Mar 24 11:43:21 2014 EGLOFF Julien
*/

int	my_aff_comb();
void	my_putchar(char c);

int	my_aff_comb()
{
  int	a;
  int	b;
  int	c;

  for (a = '0'; a <= '7'; a++)
    {
      for (b = '1'; b <= '8'; b++)
	{
	  for (c = '2'; c <= '9'; c++)
	    {
	      if ((a < b && b < c) && (a < c))
		{
		  my_putchar(a);
		  my_putchar(b);
		  my_putchar(c);
		  if ((a != '7') || (b != '8') || (c != '9'))
		    {
		      my_putchar(',');
		      my_putchar(' ');
		    }
		}
	    }
	}
    }
  return (0);
}
