/*
** my_strcmp.c for my_strcmp in /Users/laxa/Documents/Piscine/C/Jour_04/egloff_j/my_strcmp
** 
** Made by EGLOFF Julien
** Login   <egloff_j@etna-alternance.net>
** 
** Started on  Fri Mar 28 10:30:04 2014 EGLOFF Julien
** Last update Fri Mar 28 10:39:48 2014 EGLOFF Julien
*/

int	my_strcmp(char *s1, char *s2);

int	my_strcmp(char *s1, char *s2)
{
  for ( ; *s1 == *s2; s1++, s2++)
    {
      if (!(*s1))
	return (0);
    }
  return (*s1 - *s2);
}
