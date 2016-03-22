/*
** my_printf.c for my_printf in /Users/laxa/Documents/C/my_printf/egloff_j
** 
** Made by Julien EGLOFF
** Login   <laxa>
** 
** Started on  Wed Nov 12 11:21:37 2014 Julien EGLOFF
** Last update Wed Nov 12 15:48:28 2014 Julien EGLOFF
*/

#include <stdarg.h>
#include "libmy.h"
#include "my_printf.h"

t_op tab[] = {
  {'s', print_string},
  {'c', print_char},
  {'i', print_integer},
  {'d', print_integer},
  {'o', print_uoctal},
  {'u', print_uinteger},
  {'x', print_hexa},
  {'X', print_hexa_upper},
  {0, 0}
};

int	my_printf(char *str, ...)
{
  int	i;
  int index;
  va_list ap;

  va_start(ap, str);
  for (i = 0; i < my_strlen(str); i++)
    {
      if (str[i] == '%' && i + 1 < my_strlen(str) && str[i + 1] != '%')
	{
	  for (index = 0; tab[index].op; index++)
	    {
	      if (str[i + 1] == tab[index].op)
		{
		  tab[index].func(&ap);
		  i++;
		}
	    }
	}
      else if (str[i] == '%' && i + 1 < my_strlen(str) && str[i + 1] == '%')
	{
	  i++;
	  my_putchar(str[i]);
	}
      else
	my_putchar(str[i]);
    }
  va_end(ap);
  return (0);
}
