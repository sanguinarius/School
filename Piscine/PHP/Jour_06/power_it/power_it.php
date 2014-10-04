#!/usr/bin/env php
<?php
// power_it.php for power_it in /Users/laxa/Documents/Piscine/PHP/Jour_06/egloff_j/power_it
// 
// Made by Julien EGLOFF
// Login   <egloff_j@etna-alternance.net>
// 
// Started on  Mon Apr 14 09:03:26 2014 Julien EGLOFF
// Last update Mon Apr 14 09:11:03 2014 Julien EGLOFF
//

function	power_it($nb, $pow)
{
  if ($pow == 0)
    return (1);
  else if ($pow < 0)
    return (FALSE);
  for ($res = $nb; $pow > 1; $pow--)
    $res *= $nb;
  return ($res);
}

?>
