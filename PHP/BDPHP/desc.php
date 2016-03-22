<?php
// desc.php for desc.php in /Users/laxa/Documents/PHP/BDPHP/egloff_j
// 
// Made by Julien EGLOFF
// Login   <laxa>
// 
// Started on  Thu Apr 24 12:13:42 2014 Julien EGLOFF
// Last update Fri Apr 25 15:22:25 2014 Julien EGLOFF
//

function	func_desc($tab)
{
  if (!isset($tab['tab'][1]))
    {
      echo "Missing parameter to command DESC\n";
      return ;
    }
  $file = file_get_contents($tab['dbfile']);
  if (preg_match('#^TABLE '.$tab['tab'][1].'$#im', $file) == 0)
    {
      echo "Table ".$tab['tab'][1]." doesn't exist\n";
      return ;
    }
  preg_match_all('#TABLE '.$tab['tab'][1].'\n\(\n([\t| ]+([^\n]+)\n)*\)#i', $file, $matches);
  $file = $matches[0][0];
  preg_match_all('#^[\t| ]+(\w+)[\t| ]+(\w+)[\t| ]?(PRIMARY_KEY|NOT_NULL)?#mi', $file, $matches);
  echo "------- TABLE ".$tab['tab'][1]." -------\n";
  for ($i = 0; isset($matches[1][$i]); $i++)
    {
      echo "'".$matches[1][$i]."'\t".$matches[2][$i];
      if (isset($matches[3][$i]))
	echo "\t".$matches[3][$i];
      echo "\n";
    }
  echo "------- TABLE ".$tab['tab'][1]." -------\n";
}

?>
