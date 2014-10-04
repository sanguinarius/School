/*
** my_show_tab.h for my_show_tab.h in /Users/laxa/Documents/Piscine/C/Jour_07/egloff_j/my_show_tab
** 
** Made by EGLOFF Julien
** Login   <egloff_j@etna-alternance.net>
** 
** Started on  Wed Apr  2 11:31:50 2014 EGLOFF Julien
** Last update Wed Apr  2 11:36:44 2014 EGLOFF Julien
*/

#ifndef __MY_SHOW_TAB_H__
# define __MY_SHOW_TAB_H__

struct s_stock_par
{
  int  size_param;     /* longueur du parametre */
  char *str;           /* adresse du parametre  */
  char *copy;          /* copie du parametre    */
  char **tab;          /* renvoye par my_str_to_wordtab  */
};

int	my_show_tab(struct s_stock_par *par);

#endif /* __MY_SHOW_TAB_H__ */
