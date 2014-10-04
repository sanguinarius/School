#!/usr/bin/env php
<?php
// login.php for login.php in /Users/laxa/Documents/Piscine/PHP/Jour_07/egloff_j/login
// 
// Made by Julien EGLOFF
// Login   <egloff_j@etna-alternance.net>
// 
// Started on  Tue Apr 15 09:17:22 2014 Julien EGLOFF
// Last update Tue Apr 15 09:58:39 2014 Julien EGLOFF
//

function	login($argc, $argv)
{
  for ($i = 1; $i < $argc; $i++)
    {
      if (preg_match("#^[a-z0-9]{1}[a-z0-9-]{0,5}_[a-z0-9-]{1}$#", $argv[$i]))
	echo $argv[$i].": ok\n";
      else
	echo $argv[$i].": ko\n";
    }
}

login($_SERVER['argc'], $_SERVER['argv']);

?>
