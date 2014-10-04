/*
** my_strdup.c for my_strdup in /Users/laxa/Documents/Piscine/C/Jour_06
** 
** Made by EGLOFF Julien
** Login   <egloff_j@etna-alternance.net>
** 
** Started on  Mon Mar 31 18:42:18 2014 EGLOFF Julien
** Last update Wed Apr  2 11:18:07 2014 EGLOFF Julien
*/

#include <stdlib.h>
#include "libmy.h"
#include "my_param_to_tab.h"

char	*my_strdup(char *str)
{
  char	*new;
  int	i;

  new = malloc(my_strlen(str) + 1);
  for (i = 0; str[i]; i++)
    new[i] = str[i];
  new[i] = '\0';
  return (new);
}