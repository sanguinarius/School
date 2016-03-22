#!/usr/bin/env php
<?php
// usort.php for usort.php in /Users/laxa/Documents/Piscine/PHP/Jour_03/egloff_j/usort
// 
// Made by Julien EGLOFF
// Login   <laxa>
// 
// Started on  Thu Apr 10 10:22:58 2014 Julien EGLOFF
// Last update Thu Apr 10 12:23:35 2014 Julien EGLOFF
//

function	my_usort($argc, $argv)
{
  $tab = array();

  for ($i = 1; $i < $argc; $i++)
    $tab[] .= $argv[$i];
  for ($i = 0; isset($tab[$i + 1]); $i++)
    if (lencmp($tab[$i], $tab[$i + 1]) > 0)
      {
	$tmp = $tab[$i];
	$tab[$i] = $tab[$i + 1];
	$tab[$i + 1] = $tmp;
	$i = -1;
      }
  for ($i = 0; isset($tab[$i + 1]); $i++)
    if (my_strcmp($tab[$i], $tab[$i + 1]) == 1)
      {
	$tmp = $tab[$i];
	$tab[$i] = $tab[$i + 1];
	$tab[$i + 1] = $tmp;
	$i = -1;
      }
  for ($i = 0; isset($tab[$i]); $i++)
    echo $tab[$i]."\n";
}

function	my_strlen($str)
{
  for ($i = 0; isset($str[$i]); $i++);
  return ($i);
}

function	lencmp($s1, $s2)
{
  return (my_strlen($s1) - my_strlen($s2));
}

function	my_strcmp($s1, $s2)
{
  if (my_strlen($s1) != my_strlen($s2))
    return (-1);
  for ($tmp1 = "", $tmp2 = "", $i = 0; isset($s1[$i]); $i++)
    {
      if ($s1[$i] >= 'A' && $s1[$i] <= 'Z')
	$tmp1 .= chr(ord($s1[$i]) + 32);
      else
	$tmp1 .= $s1[$i];
      if ($s2[$i] >= 'A' && $s2[$i] <= 'Z')
	$tmp2 .= chr(ord($s2[$i]) + 32);
      else
	$tmp2 .= $s2[$i];
    }
  for ($i = 0; isset($tmp1[$i]); $i++)
    {
      if ($tmp1[$i] > $tmp2[$i])
	return (1);
      if ($tmp1[$i] < $tmp2[$i])
	return (-1);
    }
  return (0);
}

my_usort($_SERVER['argc'], $_SERVER['argv']);

?>
