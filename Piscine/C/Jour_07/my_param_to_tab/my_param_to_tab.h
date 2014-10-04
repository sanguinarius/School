/*
** my_param_to_tab.h for my_param_to_tab.h in /Users/laxa/Documents/Piscine/C/Jour_07/egloff_j/my_param_to_tab
** 
** Made by EGLOFF Julien
** Login   <egloff_j@etna-alternance.net>
** 
** Started on  Wed Apr  2 10:13:44 2014 EGLOFF Julien
** Last update Wed Apr  2 11:17:56 2014 EGLOFF Julien
*/

#ifndef __MY_PARAM_TO_TAB_H__
# define __MY_PARAM_TO_TAB_H__

struct s_stock_par
{
  int  size_param;     /* longueur du parametre */
  char *str;           /* adresse du parametre  */
  char *copy;          /* copie du parametre    */
  char **tab;          /* renvoye par my_str_to_wordtab  */
};

struct s_stock_par	*my_param_to_tab(int ac, char **av);
int	size_next_word(char *str, int i);
int	number_of_word(char *str);
char	**my_str_to_wordtab(char *str);
char	*my_strdup(char *str);

#endif /* __MY_PARAM_TO_TAB_H__ */
