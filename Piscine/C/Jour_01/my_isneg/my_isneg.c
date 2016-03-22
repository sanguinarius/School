/*
** my_isneg.c for my_isgned in /Users/laxa/Documents/Piscine/C/Jour_01/egloff_j/my_isneg
** 
** Made by EGLOFF Julien
** Login   <laxa>
** 
** Started on  Mon Mar 24 10:34:50 2014 EGLOFF Julien
** Last update Mon Mar 24 10:37:10 2014 EGLOFF Julien
*/

int	my_isneg(int n);
void	my_putchar(char c);

int	my_isneg(int n)
{
  if (n >= 0)
    my_putchar('P');
  else
    my_putchar('N');
  return (0);
}
