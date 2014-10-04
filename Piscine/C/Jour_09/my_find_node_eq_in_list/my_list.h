/*
** my_list.h for my_list.h in /Users/laxa/Documents/Piscine/C/Jour_09/egloff_j/my_list
** 
** Made by EGLOFF Julien
** Login   <egloff_j@etna-alternance.net>
** 
** Started on  Fri Apr  4 09:01:48 2014 EGLOFF Julien
** Last update Fri Apr  4 11:56:41 2014 EGLOFF Julien
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
int		my_list_size(t_list *begin);
int		my_rev_list(t_list **begin);
int		my_apply_on_list(t_list *begin, int (*f)());
int		my_apply_on_eq_in_list(t_list *begin, int (*f)(), void *data_ref, int (*cmp)());
void		*my_find_elm_eq_in_list(t_list *begin, void *data_ref, int (*cmp)());
t_list		*my_find_node_eq_in_list(t_list *begin, void *data_ref, int (*cmp)());

#endif /* __MY_LIST_H__ */
