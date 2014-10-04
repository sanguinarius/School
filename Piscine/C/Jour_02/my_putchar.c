/*
** my_putchar.c for my_putchar in /Users/laxa/Documents/Piscine/C/Jour_02/egloff_j
** 
** Made by EGLOFF Julien
** Login   <egloff_j@etna-alternance.net>
** 
** Started on  Tue Mar 25 09:03:56 2014 EGLOFF Julien
** Last update Tue Mar 25 09:04:30 2014 EGLOFF Julien
*/

#include <unistd.h>

void	my_putchar(char c);

void	my_putchar(char c)
{
  write(1, &c, 1);
}
