/*
** my_putnbr_base.c for my_putnbr_base in /Users/laxa/Documents/Piscine/C/Jour_04/egloff_j/my_putnbr_base
** 
** Made by EGLOFF Julien
** Login   <laxa>
** 
** Started on  Fri Mar 28 14:39:31 2014 EGLOFF Julien
** Last update Fri Mar 28 17:39:31 2014 EGLOFF Julien
*/

int	my_putnbr_base(int nbr, char *base);
int	my_strlen(char *str);
void	my_putchar(char c);

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
