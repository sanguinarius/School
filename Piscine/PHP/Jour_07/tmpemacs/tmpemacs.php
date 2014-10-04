#!/usr/bin/env php
<?php
// tmpemacs.php for tmpemacs.php in /Users/laxa/Documents/Piscine/PHP/Jour_07/egloff_j/tmpemacs
// 
// Made by Julien EGLOFF
// Login   <egloff_j@etna-alternance.net>
// 
// Started on  Tue Apr 15 11:40:44 2014 Julien EGLOFF
// Last update Tue Apr 15 11:55:47 2014 Julien EGLOFF
//

function	tmpemacs($argc, $argv)
{
  if ($argc == 1)
    {
      $argv[1] = '.';
      $argc++;
    }
  for ($i = 1; $i < $argc; $i++)
    my_find_rec($argv[$i]);
}

function	my_find_rec($path)
{
  if (($fd = check_dir($path)) === FALSE)
    return ;
  while ($dir = readdir($fd))
    {
      if ($dir == '..' || $dir == '.')
	continue;
      if (preg_match("#~$#", $dir))
	echo $path.'/'.$dir."\n";
      else if (preg_match("#^\#.+\#$#", $dir))
	echo $path.'/'.$dir."\n";
      if (is_dir($path.'/'.$dir) === TRUE)
	my_find_rec($path.'/'.$dir);
    }
  closedir($fd);
}

function	check_dir($path)
{
  if (file_exists($path) === FALSE)
    echo "tmpemacs.php: ".$path.": No such file or directory\n";
  else if (is_readable($path) === FALSE)
    echo "tmpemacs.php: ".$path.": Permission denied\n";
  else if (is_dir($path) === FALSE)
    echo $path."\n";
  else if (($fd = @opendir($path)) === FALSE)
    {
      echo "tmpemacs.php: ".$path.": Cannot open directory\n";
      return ($fd);
    }
  else
    return ($fd);
  return (FALSE);
}

tmpemacs($_SERVER['argc'], $_SERVER['argv']);

?>
