/*
** my_str_islower.c for my_str_islower.c in /Users/laxa/Documents/Piscine/C/Jour_04/egloff_j/my_str_islower
** 
** Made by EGLOFF Julien
** Login   <laxa>
** 
** Started on  Fri Mar 28 12:55:21 2014 EGLOFF Julien
** Last update Fri Mar 28 12:57:06 2014 EGLOFF Julien
*/

int	my_str_islower(char *str);

int	my_str_islower(char *str)
{
  int	i;

  for (i = 0; str[i]; i++)
    {
      if (str[i] >= 'a' && str[i] <= 'z');
      else
	return (0);
    }
  return (1);
}
