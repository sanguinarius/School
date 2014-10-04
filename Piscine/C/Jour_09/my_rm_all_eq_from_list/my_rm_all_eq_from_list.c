/*
** my_rm_all_eq_from_list.c for my_rm_all_eq_from_list.c in /Users/laxa/Documents/Piscine/C/Jour_09/egloff_j/my_rm_all_eq_from_list
** 
** Made by EGLOFF Julien
** Login   <egloff_j@etna-alternance.net>
** 
** Started on  Fri Apr  4 12:03:04 2014 EGLOFF Julien
** Last update Fri Apr  4 17:32:24 2014 EGLOFF Julien
*/

#include <stdlib.h>
#include "libmy.h"
#include "my_list.h"

int		my_rm_all_eq_from_list(t_list **begin, void *data_ref,
				       int (*cmp)())
{
  t_list	*tmp;
  t_list	*prev;
  t_list	*next;

  prev = NULL;
  tmp = *begin;
  next = tmp->next;
  while (tmp)
    {
      if (cmp(tmp->data, data_ref) == 0)
	{
	  if (prev)
	    prev->next = next;
	  else
	    *begin = (*begin)->next;
	}
      prev = tmp;
      tmp = tmp->next;
      if (tmp)
	next = tmp->next;
      else
	next = NULL;
    }
  return (0);
}
