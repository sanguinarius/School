/*
** my_getnbr.c for my_getnbr in /Users/laxa/Documents/Piscine/C/Jour_02/egloff_j/my_getnbr
** 
** Made by EGLOFF Julien
** Login   <egloff_j@etna-alternance.net>
** 
** Started on  Tue Mar 25 11:09:32 2014 EGLOFF Julien
** Last update Wed Mar 26 11:56:54 2014 EGLOFF Julien
*/

int	my_getnbr(char *str);

int	my_getnbr(char *str)
{
  int	nb;
  int	i;
  int	neg;

  nb = 0;
  neg = 0;
  for (i = 0; str[i]; i++)
    {
      if (str[i] == '-')
	return (-my_getnbr(str + 1));
      else
	{
	  if ((str[i] < '0') || (str[i] > '9'))
	    return (nb);
	  nb += str[i] - '0';
	  if (str[i + 1] && str[i + 1] >= '0' && str[i + 1] <= '9')
	    nb *= 10;
	}
    }
  return (nb);
}
