/*
** math.c for math in /Users/laxa/Documents/Piscine/C/Jour_08/egloff_j/do-op
** 
** Made by EGLOFF Julien
** Login   <egloff_j@etna-alternance.net>
** 
** Started on  Thu Apr  3 10:35:26 2014 EGLOFF Julien
** Last update Thu Apr  3 13:46:06 2014 EGLOFF Julien
*/

#include "libmy.h"
#include "do_op.h"

void	do_op_add(int a, int b)
{
  my_put_nbr(a + b);
  my_putchar('\n');
}

void	do_op_substract(int a, int b)
{
  my_put_nbr(a - b);
  my_putchar('\n');
}

void	do_op_mul(int a, int b)
{
  my_put_nbr(a * b);
  my_putchar('\n');
}

void	do_op_div(int a, int b)
{
  if (b == 0)
    {
      my_putstr("Va t'acheter des doigts\n");
      return ;
    }
  my_put_nbr(a / b);
  my_putchar('\n');
}

void	do_op_mod(int a, int b)
{
  if (b == 0)
    {
      my_putstr("Va t'acheter des doigts\n");
      return ;
    }
  my_put_nbr(a % b);
  my_putchar('\n');
}
