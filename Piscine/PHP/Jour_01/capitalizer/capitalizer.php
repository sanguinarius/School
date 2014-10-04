#!/usr/local/bin/php
<?php
// capitalizer.php for capitalizer.php in /Users/laxa/Documents/Piscine/PHP/Jour_01/egloff_j/capitalizer
// 
// Made by Julien EGLOFF
// Login   <egloff_j@etna-alternance.net>
// 
// Started on  Tue Apr  8 11:02:54 2014 Julien EGLOFF
// Last update Tue Apr  8 14:08:35 2014 Julien EGLOFF
//

function	capitalizer($str)
{
  for ($i = 0; isset($str[$i]); $i++)
    {
      if ($i == 0 && ord($str[$i]) >= 97 && ord($str[$i] <= 122))
	echo chr(ord($str[$i]) - 32);
      else if ($i > 0 && (ord($str[$i - 1]) == 9 || ord($str[$i - 1]) == 32) &&
	       ord($str[$i]) >= 97 && ord($str[$i]) <= 122)
	echo chr(ord($str[$i]) - 32);
      else if ($i > 0 && ord($str[$i - 1]) != 9 && ord($str[$i - 1]) != 32 &&
	       ord($str[$i]) >= 65 && ord($str[$i]) <= 90)
	echo chr(ord($str[$i]) + 32);
      else
	echo $str[$i];
    }
}

?>
