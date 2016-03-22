/*
** my_params_in_list.c for my_params_in_list.c in /Users/laxa/Documents/Piscine/C/Jour_09/egloff_j/my_params_in_list
** 
** Made by EGLOFF Julien
** Login   <laxa>
** 
** Started on  Fri Apr  4 09:39:57 2014 EGLOFF Julien
** Last update Fri Apr  4 09:55:11 2014 EGLOFF Julien
*/

#include <stdlib.h>
#include "libmy.h"
#include "my_list.h"

t_list		*add_node(t_list *list, char *str)
{
  t_list	*new;

  new = malloc(sizeof(*new));
  new->data = my_strdup(str);
  new->next = list;
  return (new);
}

t_list		*my_params_in_list(int ac, char **av)
{
  t_list	*new;
  int		i;

  new = NULL;
  for (i = 0; i < ac; i++)
    new = add_node(new, av[i]);
  return (new);
}
