<?php
// truncate.php for  in /Users/princetim/piscine/BDPHP
// 
// Made by timothee lestin
// Login   <lestin_t@etna-alternance.net>
// 
// Started on  Fri Apr 25 11:05:58 2014 timothee lestin
// Last update Fri Apr 25 15:27:11 2014 Julien EGLOFF
//

function	func_truncate($tab)
{
  if (!isset($tab['tab'][1]))
    {
      echo "Missing parameter to command Truncate\n";
      return ;
    }
  $file = file_get_contents($tab['dbfile']);
  if (preg_match('#^TABLE '.$tab['tab'][1].'$#im', $file) == 0)
    {
      echo "Table ".$tab['tab'][1]." doesn't exist\n";
      return ;
    }
  $file = preg_replace('#^TABLE '.$tab['tab'][1].'\n{[^}]+};#im', "TABLE ".$tab['tab'][1]."\n{\n};", $file);
  file_put_contents($tab['dbfile'], $file);
  echo "-> Table '".$tab['tab'][1]."' is truncate\n";
}

?>
