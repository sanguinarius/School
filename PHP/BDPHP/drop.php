<?php
// drop.php for drop in /Users/laxa/Documents/PHP/BDPHP/egloff_j
// 
// Made by Julien EGLOFF
// Login   <egloff_j@etna-alternance.net>
// 
// Started on  Thu Apr 24 16:39:30 2014 Julien EGLOFF
// Last update Fri Apr 25 15:36:08 2014 Julien EGLOFF
//

function	func_drop($tab)
{
  if (!isset($tab['tab'][1]))
    {
      echo "Missing parameter to command DROP\n";
      return ;
    }
  $file = file_get_contents($tab['dbfile']);
  if (preg_match('#^TABLE '.$tab['tab'][1].'$#im', $file) == 0)
    {
      echo "Table ".$tab['tab'][1]." doesn't exist\n";
      return ;
    }
  $file = preg_replace('#^TABLE '.$tab['tab'][1].'\n\([^\)]+\);[^}]+};$#im', '', $file);
  file_put_contents($tab['dbfile'], $file);
  echo "'".$tab['tab'][1]."' has been droped\n";
}

?>
