#!/usr/bin/env php
<?php
// titles.php for titles.php in /Users/laxa/Documents/Piscine/PHP/Jour_08/egloff_j/titles
// 
// Made by Julien EGLOFF
// Login   <laxa>
// 
// Started on  Wed Apr 16 10:14:35 2014 Julien EGLOFF
// Last update Wed Apr 16 12:16:16 2014 Julien EGLOFF
//

function	titles($file)
{
  if (($fd = check_dir($file)) === FALSE)
    return ;
  fclose($fd);
  $content = file_get_contents($file);
  $pat = '#<h([1-6]).*>(.+)</h\1>#';
  preg_match_all($pat, $content, $matches);
  foreach ($matches[0] as $value)
    echo preg_replace('#<\/?[^>]+>#', '', $value)."\n";
}

function	check_dir($path)
{
  $fd = FALSE;

  if (file_exists($path) === FALSE)
    echo "titles.php: ".$path.": No such file or directory\n";
  else if (is_readable($path) === FALSE)
    echo "titles.php: ".$path.": Permission denied\n";
  else if (is_dir($path) === TRUE)
    echo "titles.php: ".$path.": Is a directory\n";
  else if (($fd = @fopen($path, 'r')) === FALSE)
    echo "titles.php: ".$path.": Cannot open file\n";
  return ($fd);
}

if ($argc == 2)
  titles($_SERVER['argv'][1]);

?>
