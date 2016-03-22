/*
** my_find_node_eq_in_list.c for my_find_node_eq_in_list.c in /Users/laxa/Documents/Piscine/C/Jour_09/egloff_j/my_find_node_eq_in_list
** 
** Made by EGLOFF Julien
** Login   <laxa>
** 
** Started on  Fri Apr  4 11:55:10 2014 EGLOFF Julien
** Last update Fri Apr  4 11:57:36 2014 EGLOFF Julien
*/

#include <stdlib.h>
#include "libmy.h"
#include "my_list.h"

t_list	*my_find_node_eq_in_list(t_list *begin, void *data_ref, int (*cmp)())
{
  for (; begin; begin = begin->next)
    {
      if (cmp(begin->data, data_ref) == 0)
	return (begin);
    }
  return (NULL);
}
