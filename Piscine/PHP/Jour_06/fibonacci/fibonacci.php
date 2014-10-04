#!/usr/bin/env php
<?php
// fibonacci.php for fibonacci.php in /Users/laxa/Documents/Piscine/PHP/Jour_06/egloff_j/fibonacci
// 
// Made by Julien EGLOFF
// Login   <egloff_j@etna-alternance.net>
// 
// Started on  Mon Apr 14 09:16:16 2014 Julien EGLOFF
// Last update Mon Apr 14 09:24:35 2014 Julien EGLOFF
//

function	fibonacci($n)
{
  if ($n <= 0)
    return (FALSE);
  else if
    ($n == 1)
    return (1);
  else
    return (fibonacci($n - 1) + fibonacci($n - 2));
}

?>
