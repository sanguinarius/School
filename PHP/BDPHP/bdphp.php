#!/usr/bin/env php
<?php
// bdphp.php for bdphp.net in /Users/laxa/Documents/PHP/BDPHP/egloff_j
// 
// Made by Julien EGLOFF
// Login   <laxa>
// 
// Started on  Tue Apr 22 10:35:45 2014 Julien EGLOFF
// Last update Fri Apr 25 15:25:28 2014 Julien EGLOFF
//

require_once('my_explode.php');
require_once('quit.php');
require_once('create.php');
require_once('desc.php');
require_once('drop.php');
require_once('insert.php');
require_once('truncate.php');

function	bdphp($argc, $argv)
{
  $tab = parse($argc, $argv);
  check_files($tab);
  main_loop($tab);
}

function	main_loop($tab)
{
  while (42)
    {
      echo "bdphp> ";
      $tab['ubuf'] = fgets($tab['fd_input']);
      if (strlen($tab['ubuf']) == 0)
	exit();
      while (strlen(strstr($tab['ubuf'], ';')) == 0)
	$tab['ubuf'] .= fgets($tab['fd_input']);
      $tab['buf'] = trim($tab['ubuf']);
      $tab['buf'] = trim($tab['buf'], ';');
      $tab['buf'] = strtolower($tab['buf']);
      $tab['tab'] = my_explode($tab['buf']);
      $ptr = 'func_'.$tab['tab'][0];
      if (function_exists($ptr))
	$ptr($tab);
      else
	echo $tab['tab'][0].": Command not found\n";
    }
}

function	check_files(&$tab)
{
  if (($tab['fd_dbfile'] = @fopen($tab['dbfile'], 'a+')) === FALSE)
    {
      echo "./bdphp.php: ".$tab['dbfile'].": Failed opening file\n";
      exit();
    }
  if ($tab['input'] != 'php://stdin')
    {
      if (check_path($tab['input']) === FALSE)
	exit();
      else
	$tab['fd_input'] = fopen($tab['input'], 'rb');
    }
  else
    $tab['fd_input'] = fopen($tab['input'], 'rb');
  if ($tab['output'] != 'stdout')
    $tab['fd_output'] = fopen($tab['output'], 'w');
}

function	check_path($file)
{
  if (file_exists($file) === FALSE)
    {
      echo "./bdphp.php: ".$file.": No such file or directory\n";
      return (FALSE);
    }
  if (is_dir($file) === TRUE)
    {
      echo "./bdphp.php: ".$file.": is a directory\n";
      return (FALSE);
    }
  if (is_readable($file) === FALSE)
    {
      echo "./bdphp.php: ".$file.": Permission denied\n";
      return (FALSE);
    }
  return (TRUE);
}

function	parse($argc, $argv)
{
  $tab = array('input' => 'php://stdin', 'output' => 'stdout');

  if ($argc < 2)
    {
      echo "Usage: ./bdphp.php [-i inputfile] [-o outputfile] dbfile\n";
      exit();
    }
  for ($i = 1; $i < $argc; $i++)
    {
      if ($argv[$i] == '-i' && isset($argv[$i + 1]))
	$tab['input'] = $argv[$i + 1];
      if ($argv[$i] == '-o' && isset($argv[$i + 1]))
	$tab['output'] = $argv[$i + 1];
      if ($argv[$i] != '-o' && $argv[$i] != '-i' &&
	  $argv[$i - 1] != '-i' && $argv[$i - 1] != '-o')
	$tab['dbfile'] = $argv[$i];
    }
  if (!isset($tab['dbfile']))
    {
      echo "Usage: ./bdphp.php [-i inputfile] [-o outputfile] dbfile\n";
      exit();
    }
  return ($tab);
}

bdphp($_SERVER['argc'], $_SERVER['argv']);

?>
