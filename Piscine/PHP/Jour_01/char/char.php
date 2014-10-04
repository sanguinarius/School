#!/usr/local/bin/php
<?php
// char.php for char.php in /Users/laxa/Documents/Piscine/PHP/Jour_01/egloff_j/char
// 
// Made by Julien EGLOFF
// Login   <egloff_j@etna-alternance.net>
// 
// Started on  Tue Apr  8 10:49:48 2014 Julien EGLOFF
// Last update Tue Apr  8 10:51:54 2014 Julien EGLOFF
//

function	charbychar($str)
{
  for ($i = 0; isset($str[$i]); $i++)
    echo $str[$i]."\n";
}

?>
