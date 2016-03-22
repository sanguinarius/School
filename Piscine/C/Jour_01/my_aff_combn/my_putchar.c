/*
** my_putchar.c for my_putchar in /Users/laxa/Documents/Piscine/C/Jour_01/egloff_j
** 
** Made by EGLOFF Julien
** Login   <laxa>
** 
** Started on  Mon Mar 24 09:50:14 2014 EGLOFF Julien
** Last update Mon Mar 24 10:08:53 2014 EGLOFF Julien
*/

#include <unistd.h>

void	my_putchar(char c);

void	my_putchar(char c)
{
  write(1, &c, 1);
}
