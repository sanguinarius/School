/*
** do-op.h for do-op in /Users/laxa/Documents/Piscine/C/Jour_08/egloff_j/do-op
** 
** Made by EGLOFF Julien
** Login   <laxa>
** 
** Started on  Thu Apr  3 10:12:29 2014 EGLOFF Julien
** Last update Thu Apr  3 13:46:50 2014 EGLOFF Julien
*/

#ifndef __DO_OP_H__
# define __DO_OP_H__

typedef void	(*t_func)(int, int);

typedef struct	s_op
{
  char		op;
  t_func	func;
}		t_op;

void	do_op(char **av);
void	do_op_add(int a, int b);
void	do_op_substract(int a, int b);
void	do_op_mul(int a, int b);
void	do_op_div(int a, int b);
void	do_op_mod(int a, int b);

#endif /* __DO_OP_H__ */
