#!/usr/bin/env php
<?php
// findstr_rec.php for findstr_rec.php in /Users/laxa/Documents/Piscine/PHP/Jour_06/egloff_j/findstr_rec
// 
// Made by Julien EGLOFF
// Login   <egloff_j@etna-alternance.net>
// 
// Started on  Mon Apr 14 09:26:23 2014 Julien EGLOFF
// Last update Mon Apr 14 13:23:48 2014 Julien EGLOFF
//

function	findstr_rec($str, $to_find, $i = 0, $ii = 0)
{
  if (!(isset($to_find[$ii])))
    return (TRUE);
  else if (isset($str[$i]) && isset($to_find[$ii]) && $str[$i] != $to_find[$ii])
    return (findstr_rec($str, $to_find, ++$i));
  else if (isset($str[$i]) && isset($to_find[$ii]) && $str[$i] == $to_find[$ii])
    return (findstr_rec($str, $to_find, ++$i, ++$ii));
  return (FALSE);
}

?>
