#!/usr/local/bin/php
<?php
// sortparams.php for sortparams.php in /Users/laxa/Documents/Piscine/PHP/Jour_02/egloff_j/sortparams
// 
// Made by Julien EGLOFF
// Login   <egloff_j@etna-alternance.net>
// 
// Started on  Wed Apr  9 09:09:50 2014 Julien EGLOFF
// Last update Wed Apr  9 09:32:45 2014 Julien EGLOFF
//

function	sort_params($argc, $argv)
{
  $tmp = NULL;

  for ($i = 1; $i + 1 < $argc; $i++)
    {
      if (my_strlen($argv[$i]) > my_strlen($argv[$i + 1]))
	{
	  $tmp = $argv[$i];
	  $argv[$i] = $argv[$i + 1];
	  $argv[$i + 1] = $tmp;
	  $i = 0;
	}
    }
  for ($i = 1; $i < $argc; $i++)
    {
      if ($i != 1 && my_strlen($argv[$i - 1]) == my_strlen($argv[$i]))
	echo " ";
      echo $argv[$i];
      if ($i + 1 < $argc && my_strlen($argv[$i]) < my_strlen($argv[$i + 1]))
	echo "\n";
    }
  if ($argc > 1)
    echo "\n";
}

function	my_strlen($str)
{
  for ($i = 0; isset($str[$i]); $i++);
  return ($i);
}

sort_params($_SERVER['argc'], $_SERVER['argv']);

?>
