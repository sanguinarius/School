/*
** my_strlen.c for my_strlen in /Users/laxa/Documents/Piscine/C/Jour_02/egloff_j/my_strlen
** 
** Made by EGLOFF Julien
** Login   <laxa>
** 
** Started on  Tue Mar 25 10:10:38 2014 EGLOFF Julien
** Last update Tue Mar 25 10:11:15 2014 EGLOFF Julien
*/

int	my_strlen(char *str);

int	my_strlen(char *str)
{
  int	i;

  for (i = 0; str[i]; i++);
  return (i);
}
