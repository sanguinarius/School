<?php
// insert.php for insert.php in /Users/laxa/Documents/PHP/BDPHP/egloff_j
// 
// Made by Julien EGLOFF
// Login   <egloff_j@etna-alternance.net>
// 
// Started on  Fri Apr 25 10:37:25 2014 Julien EGLOFF
// Last update Fri Apr 25 16:12:29 2014 Julien EGLOFF
//

function	func_insert($tab)
{
  if (!isset($tab['tab'][1]))
    {
      echo "Missing parameter to command INSERT\n";
      return ;
    }
  $file = file_get_contents($tab['dbfile']);
  if (preg_match('#^TABLE '.$tab['tab'][1].'$#im', $file) == 0)
    {
      echo "Table ".$tab['tab'][1]." doesn't exist\n";
      return ;
    }
  preg_match('#TABLE '.$tab['tab'][1].'[^}]+};#im', $file, $matches);
  $file = $matches[0];
  preg_match_all('#^[\t| ]+(\w+)[\t| ]+(integer|float|string|bool)[\t| ]{0,}(PRIMARY_KEY|NOT_NULL)?#im', $file, $matches);
  $tab_table = get_table_struct($matches);
  $tab_content = get_table_content($file, $tab_table);
  $tab_insert = get_table_insert($tab);
}

function	get_table_insert($tab)
{
  preg_match_all('#^[\t| ]+(\w+)[ ]?=[ ]?(\w+)#im', $tab['ubuf'], $matches);
  var_dump($matches);
  return ($matches[2]);
}

function	get_table_content($file, $tab)
{
  preg_match_all('#^((?:\w+[\t| ]{0,}){'.count($tab['name']).'})$#im', $file, $matches);
  foreach ($matches[1] as $key => $value)
    {
      if (strlen(strstr($value, 'TABLE')))
	unset($matches[1][$key]);
    }
  $matches = array_values($matches[1]);
  var_dump($matches);
  for ($i = 0; isset($matches[$i]); $i++)
    $ret[$i] = my_explode($matches[$i]);
  return ($ret);
}

function	get_table_struct($matches)
{
  for ($i = 0; isset($matches[1][$i]); $i++)
    {
      $tab['name'][$i] = $matches[1][$i];
      $tab['type'][$i] = $matches[2][$i];
      $tab['option'][$i] = "";
      if (strlen($matches[3][$i]) > 0)
	$tab['option'][$i] = $matches[3][$i];
    }
  return ($tab);
}

?>
