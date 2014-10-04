#!/usr/bin/env php
<?php
// surface.php for surface.php in /Users/laxa/Documents/Piscine/PHP/Jour_08/egloff_j/surface
// 
// Made by Julien EGLOFF
// Login   <egloff_j@etna-alternance.net>
// 
// Started on  Wed Apr 16 09:31:25 2014 Julien EGLOFF
// Last update Wed Apr 16 09:40:01 2014 Julien EGLOFF
//

function	surface($argc, $argv)
{
  if ($argc == 3)
    {
      $x = (int)$argv[1];
      $y = (int)$argv[2];
      echo '/';
      print_x($x);
      echo "\\\n";
      print_y($x, $y);
      echo '\\';
      print_x($x);
      echo "/\n";
    }
}

function	print_y($x, $y)
{
  for (; $y != 0; $y--)
    {
      echo '|';
      for ($i = 0; $i < $x; $i++)
	echo ' ';
      echo '|';
      echo "\n";
    }
}

function	print_x($x)
{
  for (; $x != 0; $x--)
    echo '-';
}

surface($_SERVER['argc'], $_SERVER['argv']);

?>
