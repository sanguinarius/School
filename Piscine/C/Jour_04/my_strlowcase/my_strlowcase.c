/*
** my_strlowcase.c for my_strlowcase in /Users/laxa/Documents/Piscine/C/Jour_04/egloff_j/my_strlowcase
** 
** Made by EGLOFF Julien
** Login   <laxa>
** 
** Started on  Fri Mar 28 11:27:14 2014 EGLOFF Julien
** Last update Fri Mar 28 11:30:30 2014 EGLOFF Julien
*/

char	*my_strlowcase(char *str);

char	*my_strlowcase(char *str)
{
  int	i;

  for (i = 0; str[i]; i++)
    {
      if (str[i] >= 'A' && str[i] <= 'Z')
	str[i] += 32;
    }
  return (str);
}
