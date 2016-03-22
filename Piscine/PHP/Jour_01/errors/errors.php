#!/usr/local/bin/php
<?php
// errors.php for errors.php in /Users/laxa/Documents/Piscine/PHP/Jour_01/egloff_j/errors
// 
// Made by Julien EGLOFF
// Login   <laxa>
// 
// Started on  Tue Apr  8 10:19:54 2014 Julien EGLOFF
// Last update Tue Apr  8 10:22:59 2014 Julien EGLOFF
//

$nb = rand();
$puiss = 0;
for ($i = 1; $i < $nb; $i *= 10)
  {
    $puiss = $puiss + 1;
  }
echo 'Rand : ';
echo $nb;
echo " - Chiffre(s) : ";
echo $puiss;
echo "\n";

?>
