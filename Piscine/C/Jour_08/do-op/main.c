/*
** main.c for main in /Users/laxa/Documents/Piscine/C/Jour_08/egloff_j/do-op
** 
** Made by EGLOFF Julien
** Login   <laxa>
** 
** Started on  Thu Apr  3 10:11:51 2014 EGLOFF Julien
** Last update Thu Apr  3 11:24:56 2014 EGLOFF Julien
*/

#include "do_op.h"
#include "libmy.h"

int	main(int ac, char **av)
{
  if (ac == 4)
    do_op(av);
  return (0);
}
