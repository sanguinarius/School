/*
** operators2.c for operators2 in /Users/laxa/Documents/C/my_printf/egloff_j
** 
** Made by Julien EGLOFF
** Login   <egloff_j@etna-alternance.net>
** 
** Started on  Wed Nov 12 15:49:06 2014 Julien EGLOFF
** Last update Wed Nov 12 16:03:58 2014 Julien EGLOFF
*/

#include <stddef.h>
#include <stdarg.h>
#include "my_printf.h"
#include "libmy.h"

void	print_uoctal(va_list *ap)
{
  unsigned int	i;

  i = va_arg(*ap, unsigned int);
  my_putunbr_base(i, "01234567");
}

void	print_uinteger(va_list *ap)
{
  unsigned int	i;

  i = va_arg(*ap, unsigned int);
  my_putunbr_base(i, "0123456789");
}

void	print_hexa(va_list *ap)
{
  unsigned int	i;

  i = va_arg(*ap, unsigned int);
  my_putunbr_base(i, "0123456789abcdef");
}

void	print_hexa_upper(va_list *ap)
{
  unsigned int	i;

  i = va_arg(*ap, unsigned int);
  my_putunbr_base(i, "0123456789ABCDEF");
}

void	my_putunbr_base(unsigned int nbr, char *base)
{
  if (nbr >= my_ustrlen(base) - 1)
    my_putnbr_base(nbr / my_strlen(base), base);
  my_putchar(base[nbr % my_strlen(base)]);
}
