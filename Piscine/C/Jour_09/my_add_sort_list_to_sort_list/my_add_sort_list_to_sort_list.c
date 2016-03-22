/*
** my_add_sort_list_to_sort_list.c for my_add_sort_list_to_sort_list.c in /Users/laxa/Documents/Piscine/C/Jour_09/egloff_j/my_add_sort_list_to_sort_list
** 
** Made by EGLOFF Julien
** Login   <laxa>
** 
** Started on  Fri Apr  4 17:28:36 2014 EGLOFF Julien
** Last update Fri Apr  4 17:37:07 2014 EGLOFF Julien
*/

#include <stdlib.h>
#include "libmy.h"
#include "my_list.h"

int		my_add_sort_list_to_sort_list(t_list **begin1, t_list *begin2,
					      int (*cmp)())
{
  my_add_list_to_list(begin1, begin2);
  my_sort_list(begin1, cmp);
  return (0);
}

int		my_sort_list(t_list **begin, int (*cmp)())
{
  t_list	*act;
  t_list	*next;
  void		*tmp;

  act = *begin;
  next = (*begin)->next;
  while (next != NULL)
    {
      if (cmp(act->data, next->data) > 0)
	{
	  tmp = act->data;
	  act->data = next->data;
	  next->data = tmp;
	  act = *begin;
	  next = (*begin)->next;
	}
      else
	{
	  act = act->next;
	  next = next->next;
	}
    }
  return (0);
}

int		my_add_list_to_list(t_list **begin1, t_list *begin2)
{
  t_list	*list;
  t_list	*prev;

  for (list = *begin1; list; list = list->next)
    prev = list;
  prev->next = begin2;
  return (0);
}
