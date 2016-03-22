/*
** readline.c for readline in /Users/laxa/Documents/Piscine/C/Battle for Midgar/felzin_f/quete1
** 
** Made by EGLOFF Julien
** Login   <laxa>
** 
** Started on  Fri Apr  4 19:22:54 2014 EGLOFF Julien
** Last update Fri Apr  4 19:47:28 2014 EGLOFF Julien
*/

#include <unistd.h>
#include <stdlib.h>

char		*readLine(void)
{
  size_t	ret;
  char		*buff;

  if ((buff = malloc(sizeof(*buff) * (50 + 1))) == NULL)
    return (NULL);
  if ((ret = read(0, buff, 50)) > 1)
    {
      buff[ret - 1] = '\0';
      return (buff);
    }
  buff[0] = '\0';
  return (buff);
}
