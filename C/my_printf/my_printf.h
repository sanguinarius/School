/*
** my_printf.h for my_printf in /Users/laxa/Documents/C/my_printf/egloff_j
** 
** Made by Julien EGLOFF
** Login   <egloff_j@etna-alternance.net>
** 
** Started on  Wed Nov 12 11:28:59 2014 Julien EGLOFF
** Last update Wed Nov 12 16:04:18 2014 Julien EGLOFF
*/

#ifndef __MY_PRINTF_H__
# define __MY_PRINTF_H__

/* my_printf.c */

#include <stdarg.h>

typedef void	(*t_func)(va_list*);

typedef struct	s_op
{
  char		op;
  t_func	func;
}		t_op;

int	my_printf(char *str, ...);

/* operators.c */

void	print_string(va_list *ap);
void	print_char(va_list *ap);
void	print_integer(va_list *ap);
unsigned int	my_ustrlen(char *str);

/* operators2.c */

void	print_uoctal(va_list *ap);
void	print_uinteger(va_list *ap);
void	print_hexa(va_list *ap);
void	print_hexa_upper(va_list *ap);
void	my_putunbr_base(unsigned int nbr, char *base);

#endif /* __MY_PRINTF_H__ */
