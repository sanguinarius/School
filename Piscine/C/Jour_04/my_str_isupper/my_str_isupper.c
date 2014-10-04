/*
** my_str_isupper.c for my_str_isupper in /Users/laxa/Documents/Piscine/C/Jour_04/egloff_j/my_str_isupper
** 
** Made by EGLOFF Julien
** Login   <egloff_j@etna-alternance.net>
** 
** Started on  Fri Mar 28 13:15:12 2014 EGLOFF Julien
** Last update Fri Mar 28 13:16:15 2014 EGLOFF Julien
*/

int	my_str_isupper(char *str);

int	my_str_isupper(char *str)
{
  int	i;

  for (i = 0; str[i]; i++)
    {
      if (str[i] >= 'A' && str[i] <= 'Z');
      else
	return (0);
    }
  return (1);
}
