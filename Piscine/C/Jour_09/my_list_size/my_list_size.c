/*
** my_list_size.c for my_list_size in /Users/laxa/Documents/Piscine/C/Jour_09/egloff_j/my_list_size
** 
** Made by EGLOFF Julien
** Login   <egloff_j@etna-alternance.net>
** 
** Started on  Fri Apr  4 09:58:02 2014 EGLOFF Julien
** Last update Fri Apr  4 10:02:24 2014 EGLOFF Julien
*/

#include "libmy.h"
#include "my_list.h"

int	my_list_size(t_list *begin)
{
  int	size;

  for (size = 0; begin; begin = begin->next)
    size++;
  return (size);
}
