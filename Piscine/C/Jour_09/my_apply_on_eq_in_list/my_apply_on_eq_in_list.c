/*
** my_apply_on_eq_in_list.c for my_apply_on_eq_in_list.c in /Users/laxa/Documents/Piscine/C/Jour_09/egloff_j/my_apply_on_eq_in_list
** 
** Made by EGLOFF Julien
** Login   <egloff_j@etna-alternance.net>
** 
** Started on  Fri Apr  4 11:09:30 2014 EGLOFF Julien
** Last update Fri Apr  4 11:32:56 2014 EGLOFF Julien
*/

#include "libmy.h"
#include "my_list.h"

int	my_apply_on_eq_in_list(t_list *begin, int (*f)(),
			       void *data_ref, int (*cmp)())
{
  for (; begin; begin = begin->next)
    {
      if (cmp(begin->data, data_ref) == 0)
	f(begin->data);
    }
  return (0);
}
