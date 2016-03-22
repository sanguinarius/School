#!/usr/bin/env php
<?php
// find.php for find.php in /Users/laxa/Documents/Piscine/PHP/Jour_06/egloff_j/find
// 
// Made by Julien EGLOFF
// Login   <laxa>
// 
// Started on  Mon Apr 14 11:12:36 2014 Julien EGLOFF
// Last update Mon Apr 14 12:15:48 2014 Julien EGLOFF
//

function	find($argc, $argv)
{
  for ($i = 1; $i < $argc; $i++)
    my_find_rec($argv[$i], 1);
}

function	my_find_rec($path, $first = 0)
{
  if (($fd = check_dir($path)) === FALSE)
    return ;
  if ($first)
    echo $path."\n";
  while ($dir = readdir($fd))
    {
      if ($dir == '..' || $dir == '.')
	continue;
      echo $path.'/'.$dir."\n";
      if (is_dir($path.'/'.$dir) === TRUE)
	my_find_rec($path.'/'.$dir);
    }
  closedir($fd);
}

function	check_dir($path)
{
  if (file_exists($path) === FALSE)
    echo "find.php: ".$path.": No such file or directory\n";
  else if (is_readable($path) === FALSE)
    echo "find.php: ".$path.": Permission denied\n";
  else if (is_dir($path) === FALSE)
    echo $path."\n";
  else if (($fd = @opendir($path)) === FALSE)
    {
      echo "find.php: ".$path.": Cannot open directory\n";
      return ($fd);
    }
  else
    return ($fd);
  return (FALSE);
}

find($_SERVER['argc'], $_SERVER['argv']);

?>
