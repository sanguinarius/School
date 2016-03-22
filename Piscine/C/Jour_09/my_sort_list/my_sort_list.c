/*
** my_sort_list.c for my_sort_list.c in /Users/laxa/Documents/Piscine/C/Jour_09/egloff_j/my_sort_list
** 
** Made by EGLOFF Julien
** Login   <laxa>
** 
** Started on  Fri Apr  4 15:29:05 2014 EGLOFF Julien
** Last update Fri Apr  4 17:10:12 2014 EGLOFF Julien
*/

#include <stdlib.h>
#include <stdio.h>
#include "libmy.h"
#include "my_list.h"

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
