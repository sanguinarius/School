#!/usr/bin/env php
<?php
// cat.php for cat.php in /Users/laxa/Documents/Piscine/PHP/Jour_04/egloff_j/cat
// 
// Made by Julien EGLOFF
// Login   <egloff_j@etna-alternance.net>
// 
// Started on  Fri Apr 11 09:47:37 2014 Julien EGLOFF
// Last update Tue Jun 10 15:37:30 2014 Julien EGLOFF
//

function	content($file)
{
  if ($file == "php://stdin")
    $fd = fopen($file, 'rb');
  else if (is_file($file) === false)
    echo "cat.php: ".$file.": No such file or directory\n";
  else if (is_dir($file) === true)
    echo "cat.php: ".$file.": Is a directory\n";
  else if (is_readable($file) === false)
    echo "cat.php: ".$file.": Permission denied\n";
  else if (($fd = fopen($file, 'rb')) === false)
    echo "cat.php: ".$file.": Cannot open file\n";
  if (isset($fd) && $fd)
    return ($fd);
  return (FALSE);
}

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

function	check_char($str, $char)
{
  for ($i = 0; isset($str[$i]); $i++)
    {
      if ($str[$i] == $char)
	return (TRUE);
    }
  return (FALSE);
}

function	print_spaces($line)
{
  for ($i = 6 - strlen($line); $i != 0; $i--)
    echo ' ';
}

$options = parse($_SERVER['argc'], $_SERVER['argv']);
if (check_options($options, "bne") == FALSE)
  {
    echo "cat.php: Invalid options\n";
    exit();
  }
$file = array();
for ($i = 1, $flag = 0; $i < $_SERVER['argc']; $i++)
  {
    if ($flag == 1)
      $file[] .= $_SERVER['argv'][$i];
    else if (strlen($_SERVER['argv'][$i]) == 1 && $_SERVER['argv'][$i] == '-')
      $file[] .= "php://stdin";
    else if ($_SERVER['argv'][$i] == '--')
      $flag = 1;
    else if ($_SERVER['argv'][$i][0] != '-')
      $file[] .= $_SERVER['argv'][$i];
  }
if (count($file) == 0)
  $file[] .= "php://stdin";
for ($i = 0; isset($file[$i]); $i++)
  {
    $line = 1;
    $flag = 0;
    $fd = content($file[$i]);
    if ($fd === FALSE)
      continue;
    while (($buf = fread($fd, 8192)) != FALSE)
      {
	if (strlen($options) == 0)
	  echo $buf;
	else if (check_char($options, 'b'))
	  {
	    for ($ii = 0; isset($buf[$ii]); $ii++)
	      {
		if ($ii == 0 && $flag == 0 && $buf[$ii] != "\n")
		  {
		    print_spaces($line);
		    echo $line."\t";
		    ++$line;
		  }
		if (!(isset($buf[$ii + 1])) && $buf[$ii] != "\n")
		  $flag = 1;
		if ($buf[$ii] == "\n" && check_char($options, 'e'))
		  echo '$';
		echo $buf[$ii];
		if (($buf[$ii] == "\n" && $ii != 0 && isset($buf[$ii + 1]) &&
		     $buf[$ii + 1] != "\n") ||
		    ($buf[$ii] == "\n" && $flag == 1 && $ii == 0))
		  {
		    print_spaces($line);
		    echo $line."\t";
		    ++$line;
		  }
		if ($flag == 1 && $ii == 0)
		  $flag = 0;
	      }
	  }
	else if (check_char($options, 'n'))
	  {
	    for ($ii = 0; isset($buf[$ii]); $ii++)
	      {
		if ($ii == 0 && $flag == 0)
		  {
		    print_spaces($line);
		    echo $line."\t";
		    ++$line;
		  }
		if (!(isset($buf[$ii + 1])) && $buf[$ii] != "\n")
		  $flag = 1;
		if ($buf[$ii] == "\n" && check_char($options, 'e'))
		  echo '$';
		echo $buf[$ii];
		if (($buf[$ii] == "\n" && $ii != 0 && isset($buf[$ii + 1])) ||
		    $buf[$ii] == "\n" && $flag == 1)
		  {
		    print_spaces($line);
		    echo $line."\t";
		    ++$line;
		  }
		if ($flag == 1 && $ii == 0)
		  $flag = 0;
	      }
	  }
	else if (check_char($options, 'e'))
	  {
	    for ($ii = 0; isset($buf[$ii]); $ii++)
	      {
		if ($buf[$ii] == "\n")
		  echo '$';
		echo $buf[$ii];
	      }
	  }
      }
    fclose($fd);
  }

?>
