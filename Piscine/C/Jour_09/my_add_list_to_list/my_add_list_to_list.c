/*
** my_add_list_to_list.c for my_add_list_to_list.c in /Users/laxa/Documents/Piscine/C/Jour_09/egloff_j/my_add_list_to_list
** 
** Made by EGLOFF Julien
** Login   <egloff_j@etna-alternance.net>
** 
** Started on  Fri Apr  4 13:37:32 2014 EGLOFF Julien
** Last update Fri Apr  4 17:35:47 2014 EGLOFF Julien
*/

#include <stdlib.h>
#include "libmy.h"
#include "my_list.h"

int		my_add_list_to_list(t_list **begin1, t_list *begin2)
{
  t_list	*list;
  t_list	*prev;

  for (list = *begin1; list; list = list->next)
    prev = list;
  prev->next = begin2;
  return (0);
}
