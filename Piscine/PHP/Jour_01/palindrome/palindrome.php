#!/usr/local/bin/php
<?php
// palindrome.php for palindrome.php in /Users/laxa/Documents/Piscine/PHP/Jour_01/egloff_j/palindrome
// 
// Made by Julien EGLOFF
// Login   <egloff_j@etna-alternance.net>
// 
// Started on  Tue Apr  8 11:36:55 2014 Julien EGLOFF
// Last update Tue Apr  8 15:57:48 2014 Julien EGLOFF
//

function	palindrome($str)
{
  $res = "";
  for ($i = 0; isset($str[$i]); $i++)
    if (ord($str[$i]) != 32 && ord($str[$i]) != 9)
      $res .= $str[$i];
  for ($i = 0; isset($res[$i]); $i++);
  $i--;
  for ($ii = 0; isset($res[$ii]) && $ii < $i; $ii++, $i--)
    {
      if ($res[$ii] == $res[$i])
	continue;
      else if (ord($res[$ii]) + 32 == ord($res[$i]))
	continue;
      else if (ord($res[$ii]) == ord($res[$i]) + 32)
	continue;
      else
	{
	  echo "False\n";
	  return (0);
	}
    }
  echo "True\n";
}

?>
