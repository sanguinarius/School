#!/usr/local/bin/php
<?php
// type.php for type.php in /Users/laxa/Documents/Piscine/PHP/Jour_02/egloff_j/type
// 
// Made by Julien EGLOFF
// Login   <laxa>
// 
// Started on  Wed Apr  9 09:37:14 2014 Julien EGLOFF
// Last update Wed Apr  9 09:47:47 2014 Julien EGLOFF
//

function	type($str, $type)
{
  if ($type == "int")
    echo "int(".(int)$str.")\n";
  else if ($type == "float")
    echo "float(".(float)$str.")\n";
  else if ($type == "string")
    echo "string(".my_strlen($str).") \"".(string)$str."\"\n";
  else if ($type == "bool")
    {
      echo "bool(";
      if ((bool)$str == 1)
	echo "true)\n";
      else
	echo "false)\n";
    }
}

function	my_strlen($str)
{
  for ($i = 0; isset($str[$i]); $i++);
  return ($i);
}

if ($_SERVER['argc'] == 3)
  type($_SERVER['argv'][1], $_SERVER['argv'][2]);

?>
