/*
** my_strstr.c for my_strstr in /Users/laxa/Documents/Piscine/C/Jour_04/egloff_j/my_strstr
** 
** Made by EGLOFF Julien
** Login   <laxa>
** 
** Started on  Fri Mar 28 10:03:32 2014 EGLOFF Julien
** Last update Fri Mar 28 10:26:06 2014 EGLOFF Julien
*/

char	*my_strstr(char *str, char *to_find);
int	my_strlen(char *str);

char	*my_strstr(char *str, char *to_find)
{
  int	i;
  int	ii;

  if (!my_strlen(to_find))
    return (str);
  for (i = 0; str[i]; i++)
    {
      for (ii = 0; to_find[ii] == str[i] && to_find[ii] && str[i]; ii++, i++)
	{
	  if (my_strlen(to_find) == (ii + 1))
	    return (&str[i - ii]);
	}
    }
  return (0);
}

int	my_strlen(char *str)
{
  int	i;

  for (i = 0; str[i]; i++);
  return (i);
}
