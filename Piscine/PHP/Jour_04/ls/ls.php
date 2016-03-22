#!/usr/bin/env php
<?php
// ls.php for ls.php in /Users/laxa/Documents/Piscine/PHP/Jour_04/egloff_j/ls
// 
// Made by Julien EGLOFF
// Login   <laxa>
// 
// Started on  Fri Apr 11 11:52:16 2014 Julien EGLOFF
// Last update Mon Apr 14 19:29:50 2014 Julien EGLOFF
//

function	content($file)
{
  if (file_exists($file))
    {
      if (is_dir($file))
	{
	  $fd = opendir($file);
	  return ($fd);
	}
    }
  if (is_file($file) === false)
    echo "ls.php: ".$file.": No such file or directory\n";
  else if (is_dir($file) === false)
    echo "ls.php: ".$file.": Not a directory\n";
  else if (is_readable($file) === false)
    echo "ls.php: ".$file.": Permission denied\n";
  else
    echo "ls.php: ".$file.": Cannot open directory\n";
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
if (check_options($options, "an") == FALSE)
  {
    echo "ls.php: Invalid options\n";
    exit();
  }
$file = array();
for ($i = 1, $flag = 0; $i < $_SERVER['argc']; $i++)
  {
    if ($flag == 1)
      $file[] .= $_SERVER['argv'][$i];
    else if ($_SERVER['argv'][$i] == '--')
      $flag = 1;
    else if ($_SERVER['argv'][$i] == '-')
      $file[] = $_SERVER['argv'][$i];
    else if ($_SERVER['argv'][$i][0] != '-')
      $file[] .= $_SERVER['argv'][$i];
  }
if (count($file) == 0)
  $file[] .= '.';
for ($i = 0; isset($file[$i]); $i++)
  {
    $fd = content($file[$i]);
    if ($fd === FALSE)
      continue;
    while (($buf = readdir($fd)) != FALSE)
      {
	if (strlen($options) == 0)
	  {
	    if ($buf[0] == '.' || $buf == '..');
	    else
	      echo $buf."\n";
	  }
	else if (check_char($options, 'n'))
	  {
	    $perms = fileperms($buf);
	    if (($perms & 0xC000) == 0xC000)
	      $info = 's';
	    elseif (($perms & 0xA000) == 0xA000)
	      $info = 'l';
	     elseif (($perms & 0x8000) == 0x8000)
	      $info = '-';
	     elseif (($perms & 0x6000) == 0x6000)
	      $info = 'b';
	     elseif (($perms & 0x4000) == 0x4000)
	      $info = 'd';
	     elseif (($perms & 0x2000) == 0x2000)
	      $info = 'c';
	     elseif (($perms & 0x1000) == 0x1000)
	      $info = 'p';
	     else
	      $info = 'u';
	    $info .= (($perms & 0x0100) ? 'r' : '-');
	    $info .= (($perms & 0x0080) ? 'w' : '-');
	    $info .= (($perms & 0x0040) ?
		      (($perms & 0x0800) ? 's' : 'x' ) :
		      (($perms & 0x0800) ? 'S' : '-'));
	    $info .= (($perms & 0x0020) ? 'r' : '-');
	    $info .= (($perms & 0x0010) ? 'w' : '-');
	    $info .= (($perms & 0x0008) ?
		      (($perms & 0x0400) ? 's' : 'x' ) :
		      (($perms & 0x0400) ? 'S' : '-'));
	    $info .= (($perms & 0x0004) ? 'r' : '-');
	    $info .= (($perms & 0x0002) ? 'w' : '-');
	    $info .= (($perms & 0x0001) ?
		      (($perms & 0x0200) ? 't' : 'x' ) :
		      (($perms & 0x0200) ? 'T' : '-'));
	    $stat = stat($buf);
	    if (check_char($options, 'a'))
	      {
		echo $info;
		echo '      ';
		echo $stat['uid'];
		echo '      ';
		echo $stat['gid'];
		echo '      ';
		echo $buf."\n";
	      }
	    else if ($buf[0] != '.' && $buf != '..')
	      {
		echo $info;
		echo '      ';
		echo $stat['uid'];
		echo '      ';
		echo $stat['gid'];
		echo '      ';
		echo $buf."\n";
	      }
	  }
	else if (check_char($options, 'a'))
	  echo $buf."\n";
      }
  }

?>
