/*
** my_revstr.c for my_revstr in /Users/laxa/Documents/Piscine/C/Jour_04/egloff_j/my_revstr
** 
** Made by EGLOFF Julien
** Login   <laxa>
** 
** Started on  Fri Mar 28 09:42:30 2014 EGLOFF Julien
** Last update Fri Mar 28 10:01:52 2014 EGLOFF Julien
*/

char	*my_revstr(char *str);
int	my_strlen(char *str);

char	*my_revstr(char *str)
{
  char	tmp;
  int	i;

  for (i = 0; i < (my_strlen(str) / 2); i++)
    {
      tmp = str[i];
      str[i] = str[my_strlen(str) - i - 1];
      str[my_strlen(str) - i - 1] = tmp;
    }
  return (str);
}

int	my_strlen(char *str)
{
  int	i;

  for (i = 0; str[i]; i++);
  return (i);
}
