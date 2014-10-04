<?php
// buildtins.php for builstins.php in /Users/laxa/Documents/Piscine/PHP/Jour_05/egloff_j
// 
// Made by Julien EGLOFF
// Login   <egloff_j@etna-alternance.net>
// 
// Started on  Fri Apr 11 19:54:28 2014 Julien EGLOFF
// Last update Sat Apr 12 13:32:20 2014 Julien EGLOFF
//

function	func_exit($tab)
{
  exit();
}

function	func_cat($tab)
{
  $ret = "";

  if (count($tab) == 1)
    $ret = "cat: Invalid arguments\n";
  for ($i = 1; isset($tab[$i]) && $tab[$i][0] != '>'; $i++)
    {
      if (is_dir($tab[$i]) === true)
	$ret .= "cat: ".$tab[$i].": Is a directory\n";
      else if (is_file($tab[$i]) === false)
	$ret .= "cat: ".$tab[$i].": No such file or directory\n";
      else if (is_readable($tab[$i]) === false)
	$ret .= "cat: ".$tab[$i].": Permission denied\n";
      else if (($fd = fopen($tab[$i], 'rb')) === false)
	$ret .= "cat: ".$tab[$i].": Cannot open file\n";
      if (isset($fd) && $fd !== FALSE)
	{
	  $ret .= file_get_contents($tab[$i]);
	  fclose($fd);
	  unset($fd);
	}
    }
  return ($ret);
}

function	func_cd($tab)
{
  $ret = "";

  if (count($tab) == 1 && $_ENV['PWD'] != $_ENV['HOME'])
    {
      $_ENV['OLDPWD'] = $_ENV['PWD'];
      $_ENV['PWD'] = $_ENV['HOME'];
    }
  else if ($tab[1][0] == '-')
    {
      $tmp = $_ENV['PWD'];
      $ret .= $_ENV['OLDPWD']."\n";
      $_ENV['PWD'] = $_ENV['OLDPWD'];
      $_ENV['OLDPWD'] = $tmp;
    }
  else
    $ret = path_check($tab[1]);
  return ($ret);
}

function	func_pwd($tab)
{
  $ret = $_ENV['PWD']."\n";
  return ($ret);
}

function	func_ls($tab)
{
  $ret = "";

  if (count($tab) == 1)
    $tab[] .= '.';
  if (file_exists($tab[1]) === false)
    $ret = "ls: ".$tab[1].": No such file or directory\n";
  else if (is_readable($tab[1]) === false)
    $ret = "ls: ".$tab[1].": Permission denied\n";
  else if (is_dir($tab[1]) === false)
    $ret = "ls: ".$tab[1].": Not a directory\n";
  else if (($fd = opendir($tab[1])) === false)
    $ret = "ls: ".$tab[1].": Cannot open dir\n";
  if (isset($fd) && $fd !== FALSE)
    {
      $dir = array();
      while ($dir[] .= readdir($fd));
      usort($dir, "strcmp");
      $ret = ls2($dir, $tab[1]);
      closedir($fd);
    }
  return ($ret);
}

?>
