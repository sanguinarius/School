/*
** my_is_prime.c for my_is_prime in /Users/laxa/Documents/Piscine/C/Jour_03/egloff_j/my_is_prime
** 
** Made by EGLOFF Julien
** Login   <laxa>
** 
** Started on  Thu Mar 27 11:56:19 2014 EGLOFF Julien
** Last update Thu Mar 27 12:07:40 2014 EGLOFF Julien
*/

int	my_is_prime(int nombre);

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
