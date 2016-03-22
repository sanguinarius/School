<?php
// my_explode.php<2> for my_explode.php in /Users/laxa/Documents/PHP/BDPHP/egloff_j
// 
// Made by Julien EGLOFF
// Login   <laxa>
// 
// Started on  Wed Apr 23 10:14:22 2014 Julien EGLOFF
// Last update Thu Apr 24 17:05:10 2014 Julien EGLOFF
//

function	my_explode($str)
{
  $ret = array();
  $ret[0] = NULL;
  for ($i = 0, $i_r = 0; isset($str[$i]); $i++)
    {
      if ($str[$i] == ' ' || $str[$i] == "\t" || $str[$i] == "\n")
	{
	  if (strlen($ret[$i_r]) > 0)
	    {
	      ++$i_r;
	      $ret[$i_r] = NULL;
	    }
	  continue;
	}
      $ret[$i_r] .= $str[$i];
    }
  return ($ret);
}

?>
