<?php
// my_explode.php for my_explode.php in /Users/laxa/Documents/Piscine/PHP/Jour_05/egloff_j
// 
// Made by Julien EGLOFF
// Login   <laxa>
// 
// Started on  Sat Apr 12 13:04:58 2014 Julien EGLOFF
// Last update Wed Apr 23 10:14:04 2014 Julien EGLOFF
//

function	my_explode($str)
{
  $ret = array();

  for ($i = 0, $i_r = 0; isset($str[$i]); $i++)
    {
      if ($str[$i] == ' ' || $str[$i] == "\t")
	{
	  if (strlen($ret[$i_r]) > 0)
	    ++$i_r;
	  continue;
	}
      $ret[$i_r] .= $str[$i];
    }
  return ($ret);
}

?>
