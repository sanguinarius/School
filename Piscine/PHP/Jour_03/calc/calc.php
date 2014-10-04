#!/usr/bin/env php
<?php
// calc.php for calc.php in /Users/laxa/Documents/Piscine/PHP/Jour_03/egloff_j/calc
// 
// Made by Julien EGLOFF
// Login   <egloff_j@etna-alternance.net>
// 
// Started on  Thu Apr 10 10:08:43 2014 Julien EGLOFF
// Last update Thu Apr 10 12:21:23 2014 Julien EGLOFF
//

function	calc($operator = NULL, $nb = NULL)
{
  static $res = 0;

  if (isset($operator) && isset($nb) && $operator == '+')
    (int)$res += (int)$nb;
  else if (isset($operator) && isset($nb) && $operator == '=')
    (int)$res = (int)$nb;
  else if (isset($operator) && isset($nb) && $operator == '-')
    (int)$res -= (int)$nb;
  else if (isset($operator) && isset($nb) && $operator == '*')
    (int)$res *= (int)$nb;
  else if (isset($operator) && isset($nb) && $operator == '/')
    {
      if ($nb == 0)
	echo "Division by 0!\n";
      else
	(int)$res /= (int)$nb;
    }
  else if (isset($operator) && isset($nb) && $operator == '%')
    {
      if ($nb == 0)
	echo "Modulo by 0!\n";
      else
	(int)$res %= (int)$nb;
    }
  return ((int)$res);
}

?>
