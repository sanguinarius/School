/*
** do_op.c for do_op in /Users/laxa/Documents/Piscine/C/Jour_08/egloff_j/do-op
** 
** Made by EGLOFF Julien
** Login   <laxa>
** 
** Started on  Thu Apr  3 10:13:39 2014 EGLOFF Julien
** Last update Thu Apr  3 16:05:00 2014 EGLOFF Julien
*/

#include "do_op.h"
#include "libmy.h"

void	do_op(char **av)
{
  int	i;
  int	mark;
  t_op	tab[] = {
    {'+', do_op_add},
    {'-', do_op_substract},
    {'*', do_op_mul},
    {'/', do_op_div},
    {'%', do_op_mod},
    {0, 0}
  };

  for (i = 0, mark = 0; tab[i].op; i++)
    {
      if (tab[i].op == av[2][0])
	{
	 tab[i].func(my_getnbr(av[1]), my_getnbr(av[3]));
	 mark = 1;
	}
    }
  if (mark == 0)
    my_putstr("Syntax Error\n");
}
