/*
** my_str_isalpha.c for my_str_isalpha in /Users/laxa/Documents/Piscine/C/Jour_04/egloff_j/my_str_isalpha
** 
** Made by EGLOFF Julien
** Login   <egloff_j@etna-alternance.net>
** 
** Started on  Fri Mar 28 12:10:20 2014 EGLOFF Julien
** Last update Fri Mar 28 12:22:05 2014 EGLOFF Julien
*/

int	my_str_isalpha(char *str);

int	my_str_isalpha(char *str)
{
  int	i;

  for (i = 0; str[i]; i++)
    {
      if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'));
      else
	return (0);
    }
  return (1);
}
