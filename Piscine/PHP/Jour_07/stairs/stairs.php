#!/usr/bin/env php
<?php
// stairs.php for stairs.php in /Users/laxa/Documents/Piscine/PHP/Jour_07/egloff_j/stairs
// 
// Made by Julien EGLOFF
// Login   <egloff_j@etna-alternance.net>
// 
// Started on  Tue Apr 15 09:08:36 2014 Julien EGLOFF
// Last update Tue Apr 15 09:15:21 2014 Julien EGLOFF
//

function	stairs($argc, $argv)
{
  if ($argc == 2)
    {
      (int)$nb = $argv[1];
      if ($nb > 0)
	{
	  for ($i = 1; $i < $nb + 1; $i++)
	    {
	      for ($ii = 0; $ii < $i; $ii++)
		echo $i;
	      echo "\n";
	    }
	}
      else
	{
	  for (; $nb != 0; $nb++)
	    {
	      for ($i = $nb; $i != 0; $i++)
		echo -$nb;
	      echo "\n";
	    }
	}
    }
}

stairs($_SERVER['argc'], $_SERVER['argv']);

?>
