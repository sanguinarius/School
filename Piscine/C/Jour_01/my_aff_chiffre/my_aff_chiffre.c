/*
** my_aff_chiffre.c for my_aff_chiffre in /Users/laxa/Documents/Piscine/C/Jour_01/egloff_j/my_aff_chiffre
** 
** Made by EGLOFF Julien
** Login   <laxa>
** 
** Started on  Mon Mar 24 10:06:22 2014 EGLOFF Julien
** Last update Mon Mar 24 10:08:31 2014 EGLOFF Julien
*/

int	my_aff_chiffre();
void	my_putchar(char c);

int	my_aff_chiffre()
{
  int	i;

  for (i = 48; i <= 57; i++)
    {
      my_putchar(i);
    }
  return (0);
}
