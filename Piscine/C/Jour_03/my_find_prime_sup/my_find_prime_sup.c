/*
** my_find_prime_sup.c for my_find_prime_sup in /Users/laxa/Documents/Piscine/C/Jour_03/egloff_j/my_find_prime_sup
** 
** Made by EGLOFF Julien
** Login   <egloff_j@etna-alternance.net>
** 
** Started on  Thu Mar 27 12:12:01 2014 EGLOFF Julien
** Last update Thu Mar 27 12:16:23 2014 EGLOFF Julien
*/

int	my_find_prime_sup(int nb);
int	my_is_prime(int nombre);

int	my_find_prime_sup(int nb)
{
  int	i;

  for (i = 0; my_is_prime(nb + i) == 0; i++);
  return (nb + i);
}

int	my_is_prime(int nombre)
{
  int	i;

  if (nombre < 0 || nombre == 0 || nombre == 1)
    return (0);
  for (i = 2; i < nombre; i++)
    {
      if (nombre % i == 0)
	return (0);
    }
  return (1);
}
