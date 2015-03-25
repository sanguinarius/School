/*
** operators.c for operators.c in /Users/laxa/Documents/C/my_printf/egloff_j
** 
** Made by Julien EGLOFF
** Login   <egloff_j@etna-alternance.net>
** 
** Started on  Wed Nov 12 12:38:58 2014 Julien EGLOFF
** Last update Wed Nov 12 16:05:41 2014 Julien EGLOFF
*/

#include <stddef.h>
#include <stdarg.h>
#include "my_printf.h"
#include "libmy.h"

void	print_string(va_list *ap)
{
  char	*s;

  s = va_arg(*ap, char*);
  if (s != NULL)
    my_putstr(s);
  else
    my_putstr("(null)");
}

void	print_char(va_list *ap)
{
  char	c;

  c = (char)va_arg(*ap, int);
  if (&c != NULL)
    my_putchar(c);
}

void	print_integer(va_list *ap)
{
  int	i;

  i = va_arg(*ap, int);
  if (&i != NULL)
    my_put_nbr(i);
}

unsigned int	my_ustrlen(char *str)
{
  unsigned int	ret;

  for (ret = 0; *str; str++, ret++);
  return (ret);
}
