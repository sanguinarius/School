<?php
// builtins2.php for builtins2.php in /Users/laxa/Documents/Piscine/PHP/Jour_05/egloff_j
// 
// Made by Julien EGLOFF
// Login   <egloff_j@etna-alternance.net>
// 
// Started on  Fri Apr 11 19:57:55 2014 Julien EGLOFF
// Last update Sat Apr 12 11:12:16 2014 Julien EGLOFF
//

function	func_echo($tab)
{
  $ret = "";

  for ($i = 1; isset($tab[$i]) && $tab[$i] != '>' && $tab[$i] != ">>"; $i++)
    {
      if (isset($tab[$i + 1]) && $tab[$i + 1] != '>' && $tab[$i + 1] != '>>')
	$ret .= $tab[$i].' ';
      else
	$ret .= $tab[$i]."\n";
    }
  return ($ret);
}

function	func_env($tab)
{
  $ret = "";

  foreach ($_ENV as $key => $value)
    $ret .= $key."=".$value."\n";
  return ($ret);
}

function	func_setenv($tab)
{
  $_ENV[$tab[1]] = $tab[2];
  return ("");
}

function	func_unsetenv($tab)
{
  $ret = "";

  for ($i = 1; isset($tab[$i]); $i++)
    {
      $flag = 0;
      foreach ($_ENV as $key => $value)
	{
	  if ($key == $tab[$i])
	    {
	      unset($_ENV[$key]);
	      $flag = 1;
	    }
	}
      if ($flag == 0)
	$ret = "unsetenv: Invalid arguments\n";
    }
  return ($ret);
}

?>
