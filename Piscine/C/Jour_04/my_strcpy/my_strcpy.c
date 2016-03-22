/*
** my_strcpy.c for my_strcpy in /Users/laxa/Documents/Piscine/C/Jour_04/egloff_j/my_strcpy
** 
** Made by EGLOFF Julien
** Login   <laxa>
** 
** Started on  Fri Mar 28 09:07:01 2014 EGLOFF Julien
** Last update Fri Mar 28 09:08:55 2014 EGLOFF Julien
*/

char	*my_strcpy(char *dest, char *src);
int	my_strlen(char *str);

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  for (i = 0; src[i]; i++)
    dest[i] = src[i];
  dest[i] = '\0';
  return (dest);
}

int	my_strlen(char *str)
{
  int	i;

  for (i = 0; str[i]; i++);
  return (i);
}
