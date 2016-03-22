/*
** main.c for main.c for Hyrule in /Users/laxa/Documents/Piscine/C/Hyrule
** 
** Made by Julien EGLOFF
** Login   <laxa>
** 
** Started on  Thu Apr 10 15:55:24 2014 Julien EGLOFF
** Last update Thu Apr 10 17:05:58 2014 Julien EGLOFF
*/

#include "libmy.h"
#include "hyrule.h"

int	main(int ac, char **av)
{
  if (ac == 3)
    {
      if (my_strcmp(av[1], "-h") == 0 && my_getnbr(av[2]) > 0)
	hyrule(my_getnbr(av[2]));
      else
	my_putstr("Usage : ./hyrule -h height\n");
    }
  else
    my_putstr("Usage : ./hyrule -h height\n");
  return (0);
}

void	hyrule(int nb)
{
  int	i;
  int	star;
  int	space;
  int	space2;

  for (i = 0, star = 1; i < nb; i++, star += 2)
    {
      space = (nb - 1) * 2 + 1 - i;
      the_putchar(space, ' ');
      the_putchar(star, '*');
      my_putchar('\n');
    }
  space--;
  for (i = 0, star = 1, space2 = (nb - 1) * 2 + 1; i < nb;
       i++, star += 2, space--, space2 -= 2)
    {
      the_putchar(space, ' ');
      the_putchar(star, '*');
      the_putchar(space2, ' ');
      the_putchar(star, '*');
      my_putchar('\n');
    }
}

void	the_putchar(int nb, char c)
{
  int	i;

  for (i = 0; i < nb; i++)
    my_putchar(c);
}
