/*
** my_rev_list.c for my_rev_list.c in /Users/laxa/Documents/Piscine/C/Jour_09/egloff_j/my_rev_list
** 
** Made by EGLOFF Julien
** Login   <egloff_j@etna-alternance.net>
** 
** Started on  Fri Apr  4 10:04:48 2014 EGLOFF Julien
** Last update Fri Apr  4 12:25:21 2014 EGLOFF Julien
*/

#include <stdlib.h>
#include "libmy.h"
#include "my_list.h"

int		my_rev_list(t_list **begin)
{
  t_list	*tmp;
  t_list	*prev;
  t_list	*next;

  for (prev = NULL, tmp = *begin; *begin; *begin = next)
    {
      next = (*begin)->next;
      (*begin)->next = prev;
      prev = tmp;
      tmp = next;
    }
  *begin = prev;
  return (0);
}
