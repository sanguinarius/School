/*
** my_factorielle_rec.c for my_factorielle_rec in /Users/laxa/Documents/Piscine/C/Jour_03/egloff_j/my_factorielle_rec
** 
** Made by EGLOFF Julien
** Login   <egloff_j@etna-alternance.net>
** 
** Started on  Thu Mar 27 09:37:54 2014 EGLOFF Julien
** Last update Thu Mar 27 09:49:37 2014 EGLOFF Julien
*/

int	my_factorielle_rec(int nb);

int	my_factorielle_rec(int nb)
{
  if (nb < 0 || nb > 12)
    return (0);
  if (nb > 0)
    return (nb * my_factorielle_rec(nb - 1));
  return (1);
}
