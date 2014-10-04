#!/usr/bin/env php
<?php
// microshell.php for microshell.php in /Users/laxa/Documents/Piscine/PHP/Jour_05/egloff_j
// 
// Made by Julien EGLOFF
// Login   <egloff_j@etna-alternance.net>
// 
// Started on  Sat Apr 12 08:45:24 2014 Julien EGLOFF
// Last update Wed Apr 23 10:43:13 2014 Julien EGLOFF
//

require_once('builtins.php');
require_once('builtins2.php');
require_once('my_explode.php');

function	microshell()
{
  $fd = fopen("php://stdin", 'rb');
  while (42)
    {
      echo '$> ';
      $buf = fgets($fd);
      if (strlen($buf) == 0)
	exit();
      $buf = trim($buf);
      $tab = my_explode($buf);
      $tab = parse($tab);
      $ptr = 'func_'.$tab[0];
      $ret = "";
      if (strlen($buf) > 0 && function_exists($ptr))
	$ret = $ptr($tab);
      else
	if (strlen($buf) > 0)
	  echo $tab[0].": Command not found\n";
      $ret = check_redirection($tab, $ret);
      echo $ret;
    }
  fclose($fd);
}

function	parse($tab)
{
  $ret = array();
  $tmp = "";

  for ($i = 0; isset($tab[$i]); $i++)
    {
      $var = "";
      if ($tab[$i][0] == '$')
	{
	  for ($ii = 1; isset($tab[$i][$ii]); $ii++)
	    $tmp .= $tab[$i][$ii];
	  foreach ($_ENV as $key => $value)
	    if ($tmp == $key)
	      $var = $value;
	  if (strlen($var) > 0)
	    $ret[] .= $var;
	  else
	    $ret[] .= $tab[$i];
	}
      else
	$ret[] .= $tab[$i];
    }
  return ($ret);
}

function	check_redirection($tab, $ret)
{
  for ($i = 0; isset($tab[$i]); $i++)
    {
      if ($tab[$i] == '>')
	{
	  if (($fd = @fopen($tab[$i + 1], 'w')) === FALSE)
	    $ret = $tab[$i + 1].": No such file or directory\n";
	  else
	    {
	      file_put_contents($tab[$i + 1], $ret);
	      $ret = "";
	    }
	}
      else if ($tab[$i] == '>>')
	{
	  if (($fd = @fopen($tab[$i + 1], 'a')) === FALSE)
	    $ret = $tab[$i + 1].": No such file or directory\n";
	  else
	    {
	      file_put_contents($tab[$i + 1], $ret, FILE_APPEND);
	      $ret = "";
	    }
	}
    }
  return ($ret);
}

function	path_check($path)
{
  if (file_exists($path) === false)
    return ("cd: ".$path.": No such file or directory\n");
  else if (is_readable($path) === false)
    return ("cd: ".$path.": Permission denied\n");
  else if (is_dir($path) === false)
    return ("cd: ".$path.": Not a directory\n");
  else if (($fd = opendir($path)) === false)
    return ("cd: ".$path.": Cannot open dir\n");
  if (isset($fd) && $fd !== FALSE)
    {
      chdir($path);
      $_ENV['OLDPWD'] = $_ENV['PWD'];
      $_ENV['PWD'] = getcwd();
      closedir($fd);
      return ("");
    }
}

function	ls2($dir, $path)
{
  $ret = "";

  for ($i = 0; isset($dir[$i]); $i++)
    {
      if ($dir[$i][0] != '.' && strlen($dir[$i]) > 0)
	{
	  if (is_dir($path.'/'.$dir[$i]) === true)
	    $ret .= $dir[$i].'/'."\n";
	  else if (is_link($path.'/'.$dir[$i]) === true)
	    $ret .= $dir[$i].'@'."\n";
	  else if (is_executable($path.'/'.$dir[$i]) === true)
	    $ret .= $dir[$i].'*'."\n";
	  else
	    $ret .= $dir[$i]."\n";
	}
    }
  return ($ret);
}

microshell();

?>
