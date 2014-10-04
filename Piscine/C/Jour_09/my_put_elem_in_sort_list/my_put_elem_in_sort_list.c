/*
** my_put_elem_in_sort_list.c for my_put_elem_in_sort_list.c in /Users/laxa/Documents/Piscine/C/Jour_09/egloff_j/my_put_elem_in_sort_list
** 
** Made by EGLOFF Julien
** Login   <egloff_j@etna-alternance.net>
** 
** Started on  Fri Apr  4 17:13:19 2014 EGLOFF Julien
** Last update Fri Apr  4 17:24:55 2014 EGLOFF Julien
*/

#include <stdlib.h>
#include "libmy.h"
#include "my_list.h"

int		my_put_elem_in_sort_list(t_list **begin, void *data,
					 int (*cmp)())
{
  t_list	*tmp;

  for (tmp = *begin; tmp->next; tmp = tmp->next);
  tmp->next = add_node(NULL, data);
  my_sort_list(begin, cmp);
  return (0);
}

t_list		*add_node(t_list *list, char *str)
{
  t_list	*new;

  new = malloc(sizeof(*new));
  new->data = my_strdup(str);
  new->next = list;
  return (new);
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
