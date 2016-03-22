#!/usr/bin/env php
<?php
// sortint.php for sortint.php in /Users/laxa/Documents/Piscine/PHP/Jour_03/egloff_j/sortint
// 
// Made by Julien EGLOFF
// Login   <laxa>
// 
// Started on  Thu Apr 10 09:34:31 2014 Julien EGLOFF
// Last update Thu Apr 10 09:38:43 2014 Julien EGLOFF
//

function	sortint(&$tab)
{
  for ($i = 0; isset($tab[$i + 1]); $i++)
    {
      if ($tab[$i] > $tab[$i + 1])
	{
	  $tmp = $tab[$i];
	  $tab[$i] = $tab[$i + 1];
	  $tab[$i + 1] = $tmp;
	  $i = -1;
	}
    }
}

?>
