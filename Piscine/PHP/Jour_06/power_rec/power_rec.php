#!/usr/bin/env php
<?php
// power_rec.php for power_rec.php in /Users/laxa/Documents/Piscine/PHP/Jour_06/egloff_j/power_rec
// 
// Made by Julien EGLOFF
// Login   <laxa>
// 
// Started on  Mon Apr 14 09:12:00 2014 Julien EGLOFF
// Last update Mon Apr 14 09:14:58 2014 Julien EGLOFF
//

function	power_rec($nb, $pow)
{
  if ($pow == 0)
    return (1);
  else if ($pow < 0)
    return (FALSE);
  if ($pow >= 1)
    return ($nb * power_rec($nb, --$pow));
  return ($nb);
}

?>
