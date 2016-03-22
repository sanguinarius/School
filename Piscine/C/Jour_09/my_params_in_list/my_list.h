/*
** my_list.h for my_list.h in /Users/laxa/Documents/Piscine/C/Jour_09/egloff_j/my_list
** 
** Made by EGLOFF Julien
** Login   <laxa>
** 
** Started on  Fri Apr  4 09:01:48 2014 EGLOFF Julien
** Last update Fri Apr  4 09:42:48 2014 EGLOFF Julien
*/

#ifndef __MY_LIST_H__
# define __MY_LIST_H__

typedef struct     s_list
{
  void             *data;
  struct s_list    *next;
}                  t_list;

t_list		*my_params_in_list(int ac,char **av);
t_list		*add_node(t_list *list, char *str);

#endif /* __MY_LIST_H__ */
