#!/usr/bin/env php
<?php
// parrot.php for parrot.php in /Users/laxa/Documents/Piscine/PHP/Jour_03/egloff_j/parrot
// 
// Made by Julien EGLOFF
// Login   <laxa>
// 
// Started on  Thu Apr 10 09:42:15 2014 Julien EGLOFF
// Last update Thu Apr 10 13:57:34 2014 Julien EGLOFF
//

$toto = "";

function	human($str)
{
  global $toto;

  if (my_strlen($toto) == 0 && my_strlen($str) > 0)
    $toto .= $str;
  else
    {
      $toto .= " ... ";
      $toto .= $str;
    }
}

function	parrot()
{
  global $toto;

  if (my_strlen($toto) == 0)
    echo "Coco ?\n";
  else
    {
      echo $toto." ... Coco ...\n";
      $toto = "";
    }
}

function	my_strlen($str)
{
  for ($i = 0; isset($str[$i]); $i++);
  return ($i);
}

?>
