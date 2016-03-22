/*
** my_aff_revalpha.c for my_aff_revalpha in /Users/laxa/Documents/Piscine/C/Jour_01/egloff_j/my_aff_revalpha
** 
** Made by EGLOFF Julien
** Login   <laxa>
** 
** Started on  Mon Mar 24 09:42:22 2014 EGLOFF Julien
** Last update Mon Mar 24 09:44:44 2014 EGLOFF Julien
*/

int	my_aff_revalpha();
void	my_putchar(char c);

int	my_aff_revalpha()
{
  int	i;

  for (i = 122; i >= 97; i--)
    {
      my_putchar(i);
    }
  return (0);
}
