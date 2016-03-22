#!/usr/bin/env php
<?php
// content.php for content.php in /Users/laxa/Documents/Piscine/PHP/Jour_04/egloff_j/content
// 
// Made by Julien EGLOFF
// Login   <laxa>
// 
// Started on  Fri Apr 11 09:22:48 2014 Julien EGLOFF
// Last update Fri Apr 11 09:45:56 2014 Julien EGLOFF
//

function	content($argc, $argv)
{
  for ($i = 1; $i < $argc; $i++)
    {
      if (is_dir($argv[$i]) === true)
	echo "content.php: ".$argv[$i].": Is a directory\n";
      else if (is_file($argv[$i]) === false)
	echo "content.php: ".$argv[$i].": No such file or directory\n";
      else if (is_readable($argv[$i]) === false)
	echo "content.php: ".$argv[$i].": Permission denied\n";
      else if (($fd = fopen($argv[$i], 'rb')) === false)
	echo "content.php: ".$argv[$i].": Cannot open file\n";
      if (isset($fd) && $fd)
	{
	  while ($buf = fread($fd, 512))
	    echo $buf;
	  fclose($fd);
	}
    }
}

content($_SERVER['argc'], $_SERVER['argv']);

?>
