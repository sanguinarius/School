#!/usr/bin/env php
<?php
// eval.php for eval.php in /Users/laxa/Documents/Piscine/PHP/Jour_02/egloff_j/eval
// 
// Made by Julien EGLOFF
// Login   <egloff_j@etna-alternance.net>
// 
// Started on  Wed Apr  9 13:43:08 2014 Julien EGLOFF
// Last update Wed Apr  9 13:51:10 2014 Julien EGLOFF
//

function	my_eval($argc, $argv)
{
  if ($argc != 4)
    echo "Usage: ./eval.php nb1 operator nb2\n";
  else if ($argv[2] == '+')
    echo (int)($argv[1]) + (int)$argv[3]."\n";
  else if ($argv[2] == '-')
    echo (int)($argv[1]) - (int)$argv[3]."\n";
  else if ($argv[2] == '*')
    echo (int)($argv[1]) * (int)$argv[3]."\n";
  else if ($argv[2] == '/')
    {
      if ((int)$argv[3] == 0)
	echo "Division by 0!\n";
      else
	echo (int)((int)($argv[1]) / (int)$argv[3])."\n";
    }
  else if ($argv[2] == '%')
    {
      if ((int)$argv[3] == 0)
	echo "Modulo by 0!\n";
      else
	echo (int)($argv[1]) % (int)$argv[3]."\n";
    }
  else
    echo "Usage: ./eval.php nb1 operator nb2\n";
}

my_eval($_SERVER['argc'], $_SERVER['argv']);

?>
