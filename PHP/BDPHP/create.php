<?php
// func_create.php for func_create.php in /Users/laxa/Documents/PHP/BDPHP/egloff_j
// 
// Made by Julien EGLOFF
// Login   <laxa>
// 
// Started on  Wed Apr 23 17:23:07 2014 Julien EGLOFF
// Last update Fri Apr 25 15:37:53 2014 Julien EGLOFF
//

function	func_create($tab)
{
  if ($tab['tab'][1] == 'table')
    {
      $file = file_get_contents($tab['dbfile']);
      if (preg_match('#^TABLE '.$tab['tab'][2].'$#im', $file))
	{
	  echo "Table ".$tab['tab'][2]." already exist\n";
	  return ;
	}
      if (check_parenthis($tab['buf']) === FALSE)
	{
	  echo "Syntax error\n";
	  return ;
	}
      if (preg_match_all('#(\t| )+\w+(\t| )+(integer|float|bool|string)(\t| )?(PRIMARY_KEY|NOT_NULL)?(\t| )?,?#i',
			 $tab['buf']) == 0)
	{
	  echo "Syntax error\n";
	  return ;
	}
      $tab['ubuf'] = preg_replace('#CREATE #i', '', $tab['ubuf']);
      file_put_contents($tab['dbfile'], $tab['ubuf'], FILE_APPEND);
      file_put_contents($tab['dbfile'], "TABLE ".$tab['tab'][2]."\n{\n};\n", FILE_APPEND);
      echo "-> Table '".$tab['tab'][2]."' created.\n";
    }
  else
    echo "Syntax error\n";
}

function	check_parenthis($buf)
{
  $flag = 0;
  for ($i = 0; isset($buf[$i]); $i++)
    {
      if ($buf[$i] == '(')
	++$flag;
      else if ($buf[$i] == ')')
	++$flag;
    }
  if ($flag == 2)
    return (TRUE);
  else
    return (FALSE);
}

?>
