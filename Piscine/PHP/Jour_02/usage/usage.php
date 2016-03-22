#!/usr/bin/env php
<?php
// usage.php for usage.php in /Users/laxa/Documents/Piscine/PHP/Jour_02/egloff_j/usage
// 
// Made by Julien EGLOFF
// Login   <laxa>
// 
// Started on  Wed Apr  9 11:11:51 2014 Julien EGLOFF
// Last update Wed Apr  9 12:40:04 2014 Julien EGLOFF
//

function	parse($argc, $argv)
{
  $options = "";

  for ($i = 1; $i < $argc; $i++)
    {
      if (isset($argv[$i][1]) && $argv[$i][0] == '-' && $argv[$i][1] == '-')
	return ($options);
      if ($argv[$i][0] == '-')
	{
	  for ($ii = 1; isset($argv[$i][$ii]); $ii++)
	    {
	      if (($argv[$i][$ii] >= 'a' && $argv[$i][$ii] <= 'z') ||
		  ($argv[$i][$ii] >= 'A' && $argv[$i][$ii] <= 'Z'))
		{
		  for ($i_options = 0, $flag = 0;
		       isset($options[$i_options]); $i_options++)
		    if ($options[$i_options] == $argv[$i][$ii])
		      $flag = 1;
		  if ($flag != 1)
		    $options .= $argv[$i][$ii];
		}
	    }
	}
    }
  return ($options);
}

function	usage($argc, $argv)
{
  $options = parse($argc, $argv);
  if ($argc < 2)
    echo "Usage: ./usage.php [-NRlnq] [-m message] argument1 [argument2 ...]\n";
  else if (my_strlen($options) == 0 && $argc >= 2);
  else if (check_options($options, "NRlnqm") == FALSE)
    echo "Usage: ./usage.php [-NRlnq] [-m message] argument1 [argument2 ...]\n";
  else if (my_strlen($options) == 1 && $options[0] == 'm' && $argc < 4)
    echo "Usage: ./usage.php [-NRlnq] [-m message] argument1 [argument2 ...]\n";
  else if (my_strlen($options) != 1 && check_char($options, 'm') && $argc < 4)
    echo "Usage: ./usage.php [-NRlnq] [-m message] argument1 [argument2 ...]\n";
}

function	check_char($str, $char)
{
  for ($i = 0; isset($str[$i]); $i++)
    {
      if ($str[$i] == $char)
	return (TRUE);
    }
  return (FALSE);
}

function	check_options($options, $str)
{
  for ($i = 0; isset($options[$i]); $i++)
    {
      for ($ii = 0, $flag = 0; isset($str[$ii]); $ii++)
	{
	  if ($options[$i] == $str[$ii])
	    $flag = 1;
	}
      if ($flag == 0)
	return (FALSE);
    }
  return (TRUE);
}

function	my_strlen($str)
{
  for ($i = 0; isset($str[$i]); $i++);
  return ($i);
}

usage($_SERVER['argc'], $_SERVER['argv']);

?>
