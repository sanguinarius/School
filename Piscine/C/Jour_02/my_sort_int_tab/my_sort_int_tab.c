/*
** my_sort_int_tab.c for my sort int tab in /Users/laxa/Documents/Piscine/C/Jour_02/egloff_j/my_sort_int_tab
** 
** Made by EGLOFF Julien
** Login   <laxa>
** 
** Started on  Tue Mar 25 11:54:09 2014 EGLOFF Julien
** Last update Tue Mar 25 12:07:17 2014 EGLOFF Julien
*/

void	my_sort_int_tab(int *tab, int size);

void	my_sort_int_tab(int *tab, int size)
{
  int	i;
  int	tmp;

  for (i = 0; i < size; i++)
    {
      if (i + 1 < size && tab[i] > tab[i + 1])
	{
	  tmp = tab[i];
	  tab[i] = tab[i + 1];
	  tab[i + 1] = tmp;
	  i = -1;
	}
    }
}
