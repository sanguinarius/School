#!/usr/local/bin/php
<?php
// options.php for options.php in /Users/laxa/Documents/Piscine/PHP/Jour_02/egloff_j/options
// 
// Made by Julien EGLOFF
// Login   <laxa>
// 
// Started on  Wed Apr  9 10:01:11 2014 Julien EGLOFF
// Last update Wed Apr  9 12:05:28 2014 Julien EGLOFF
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

function	sort_options($str)
{
  for ($i = 1; isset($str[$i]); $i++)
    {
      if ($str[$i - 1] > $str[$i])
	{
	  $tmp = $str[$i - 1];
	  $str[$i - 1] = $str[$i];
	  $str[$i] = $tmp;
	  $i = 0;
	}
    }
  return ($str);
}

function	options($argc, $argv)
{
  $options = parse($argc, $argv);
  $options = sort_options($options);
  if (my_strlen($options) == 0)
    echo "No options\n";
  else
    echo "Options: ".$options."\n";
}

function	my_strlen($str)
{
  for ($i = 0; isset($str[$i]); $i++);
  return ($i);
}

options($_SERVER['argc'], $_SERVER['argv']);

?>
