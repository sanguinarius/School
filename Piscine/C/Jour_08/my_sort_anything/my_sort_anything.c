/*
** my_sort_anything.c for my_sort_anything in /Users/laxa/Documents/Piscine/C/Jour_08/egloff_j/my_sort_anything
** 
** Made by EGLOFF Julien
** Login   <laxa>
** 
** Started on  Thu Apr  3 11:49:21 2014 EGLOFF Julien
** Last update Thu Apr  3 17:44:52 2014 EGLOFF Julien
*/

#include "libmy.h"

void	swap(char *a, char *b, int size);

void	my_sort_anything(void *to_sort, int nmemb, int size,
			 int (*compar)(void *, void *))
{
  char	*str;
  int	i;

  if (nmemb < 2 || size == 0)
    return ;
  str = to_sort;
  for (i = 0; (str + size) && i + 1 < nmemb; str += size, i++)
    {
      if (compar(str, str + size) > 0)
	{
	  swap(str, str + size, size);
	  i = -1;
	  str = (char *)to_sort - size;
	}
    }
}

void	swap(char *a, char *b, int size)
{
  char	tmp;

  if (a != b)
    {
      while (size--)
	{
	  tmp = *a;
	  *a++ = *b;
	  *b++ = tmp;
	}
    }
}
