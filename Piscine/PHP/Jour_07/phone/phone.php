#!/usr/bin/env php
<?php
// phone.php for phone.php in /Users/laxa/Documents/Piscine/PHP/Jour_07/egloff_j/phone
// 
// Made by Julien EGLOFF
// Login   <laxa>
// 
// Started on  Tue Apr 15 10:01:49 2014 Julien EGLOFF
// Last update Tue Apr 15 10:19:56 2014 Julien EGLOFF
//

function	phone($argc, $argv)
{
  for ($i = 1; $i < $argc; $i++)
    {
      if (preg_match("#^([0-9]{2}[- \.]?){4}[0-9]{2}$#", $argv[$i], $res))
	print_phone($argv[$i]);
    }
}

function	print_phone($str)
{
  $flag = 0;
  for ($i = 0; isset($str[$i]); $i++)
    {
      if ($flag == 2 && isset($str[$i + 1]))
	{
	  $flag = 0;
	  echo '.';
	}
      if ($str[$i] >= '0' && $str[$i] <= '9')
	{
	  echo $str[$i];
	  $flag++;
	}
    }
  echo "\n";
}

phone($_SERVER['argc'], $_SERVER['argv']);

?>
