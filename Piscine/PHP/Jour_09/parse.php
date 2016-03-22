<?php
// main.php for  in /Users/ferielabachi/picine/phpicine/imagepanel
// 
// Made by fériel abachi
// Login   
// 
// Started on  Wed Apr 16 19:09:24 2014 fériel abachi
// Last update Fri Apr 18 10:48:58 2014 Julien EGLOFF
//

require_once('check_error.php');

function	verif_option($char)
{
  if ($char == 'g' || $char == 'j' || $char == 'n'
      || $char == 'N' || $char == 'p' || $char == 's')
    return (0);
  return (-1);
}

function	check_value(&$opt, $char)
{
  $i = 0;
  foreach ($opt as $key => $value)
    {
      if ($key == $char)
      	$opt[$key] = 1;
    }
  return ($opt);
}

function	exit_prog($str)
{
  echo "option ".$str." is not valid\n";
  exit();
}

function	check_value_l($opt, $argv, $i, $char)
{
  if (ctype_digit($argv[$i + 1]))
    {
      foreach ($opt as $key => $value)
	{
	  if ($key == $char)
	    $opt[$key] = $argv[$i + 1];
	}
    }
  else
    {
      echo "is a string ".$argv[$i + 1]." is not a number\n";
      exit ();
    }
  return ($opt);
}

function	recup_option($argc, $argv)
{
  $opt = array('param' => array(), 'base' => 'default', 'g' => 0, 'j' => 0,
	       'l' => 300, 'n' => 0, 'p' => 0, 'N' => 0, 's' => 0);
  for ($i = 1; isset($argv[$i]); $i++)
	{
	  if ($argv[$i][0] == '-')
	    {
	      for ($j = 1; isset($argv[$i][$j]); $j++)
		{
		  if (verif_option($argv[$i][$j]) == 0)
		    $opt = check_value($opt, $argv[$i][$j]);
		  else if ($argv[$i][$j] == 'l')
		    $opt = check_value_l($opt, $argv, $i, $argv[$i][$j]);
		  else
		    exit_prog($argv[$i][$j]);
		}
	    }
	  if ($argv[$i][0] != '-' && $i < $argc - 1)
	    $opt['param'][] = $argv[$i];
	  else
	    $opt['base'] = $argv[$i];
	}
  check_options($opt);
  return ($opt);
}

?>
