#!/usr/bin/env php
<?php
// counter.php for counter.php in /Users/laxa/Documents/Piscine/PHP/Jour_03/egloff_j/counter
// 
// Made by Julien EGLOFF
// Login   <laxa>
// 
// Started on  Thu Apr 10 09:30:33 2014 Julien EGLOFF
// Last update Thu Apr 10 10:15:04 2014 Julien EGLOFF
//

function	counter($inc = NULL)
{
  static $i = 0;

  if (isset($inc))
    $i += $inc;
  return ($i);
}

?>
