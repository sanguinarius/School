#!/usr/bin/env php
<?php
// html.php for html.php in /Users/laxa/Documents/Piscine/PHP/Jour_08/egloff_j/html
// 
// Made by Julien EGLOFF
// Login   <egloff_j@etna-alternance.net>
// 
// Started on  Wed Apr 16 12:17:37 2014 Julien EGLOFF
// Last update Wed Apr 16 13:46:33 2014 Julien EGLOFF
//

function	html($file)
{
  if (($fd = check_dir($file)) === FALSE)
    return ;
  fclose($fd);
  $content = file_get_contents($file);
  preg_match_all('#<\/?[^>]+>#', $content, $matches);
  foreach ($matches[0] as $key => $value)
    {
      if (preg_match('#<img src=.+/>#', $value))
	unset($matches[0][$key]);
    }
  $matches = array_values($matches[0]);
  if (count($matches) % 2 == 1)
    {
      echo "Ko\n";
      return ;
    }
  check_order($matches);
  echo "Ok\n";
}

function	check_order($matches)
{
  for ($i = 0; isset($matches[$i + 1]); $i += 2)
    {
      preg_match('#<([^ ]+).*>#', $matches[$i], $tab);
      $balise = $tab[1];
      $pat = '#</'.$balise.'>#';
      if (preg_match($pat, $matches[$i + 1]) === 0)
	{
	  echo "Ko\n";
	  exit();
	}
    }
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
  html($_SERVER['argv'][1]);

?>
