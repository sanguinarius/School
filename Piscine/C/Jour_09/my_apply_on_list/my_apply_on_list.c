/*
** my_apply_on_list.c for my_apply_on_list.c in /Users/laxa/Documents/Piscine/C/Jour_09/egloff_j/my_apply_on_list
** 
** Made by EGLOFF Julien
** Login   <egloff_j@etna-alternance.net>
** 
** Started on  Fri Apr  4 10:52:21 2014 EGLOFF Julien
** Last update Fri Apr  4 10:53:54 2014 EGLOFF Julien
*/

#include "libmy.h"
#include "my_list.h"

int		my_apply_on_list(t_list *begin, int (*f)())
{
  for (; begin; begin = begin->next)
    f(begin->data);
  return (0);
}
