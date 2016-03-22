/*
** my_strncmp.c for my_strncmp in /Users/laxa/Documents/Piscine/C/Jour_04/egloff_j/my_strncmp
** 
** Made by EGLOFF Julien
** Login   <laxa>
** 
** Started on  Fri Mar 28 10:54:21 2014 EGLOFF Julien
** Last update Fri Mar 28 10:57:22 2014 EGLOFF Julien
*/

int	my_strncmp(char *s1, char *s2, int n);

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  for (i = 0; i < n && s1[i] == s2[i]; i++)
    {
      if (!(s1[i]))
	return (0);
    }
  return (s1[i] - s2[i]);
}
