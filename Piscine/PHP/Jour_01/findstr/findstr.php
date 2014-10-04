#!/usr/local/bin/php
<?php
// findstr.php for findstr.php in /Users/laxa/Documents/Piscine/PHP/Jour_01/egloff_j/findstr
// 
// Made by Julien EGLOFF
// Login   <egloff_j@etna-alternance.net>
// 
// Started on  Tue Apr  8 12:34:21 2014 Julien EGLOFF
// Last update Mon Apr 14 10:00:33 2014 Julien EGLOFF
//

function	findstr($str, $to_find)
{
  for ($i = 0; isset($str[$i]); $i++)
    {
      for ($ii = 0; isset($str[$i]) && isset($to_find[$ii]) &&
	     $str[$i] == $to_find[$ii]; $i++, $ii++);
      if (isset($to_find[$ii]) == FALSE)
	{
	  echo "True\n";
	  return (0);
	}
    }
  echo "False\n";
}

?>
