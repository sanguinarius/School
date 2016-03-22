#!/usr/bin/env php
<?php
// my_pathinfo.php for my_pathinfo.php in /Users/laxa/Documents/Piscine/PHP/Jour_07/egloff_j/my_pathinfo
// 
// Made by Julien EGLOFF
// Login   <laxa>
// 
// Started on  Tue Apr 15 10:21:44 2014 Julien EGLOFF
// Last update Tue Apr 15 18:25:50 2014 Julien EGLOFF
//

function	my_pathinfo($path)
{
  $res = array();

  if ($path == '.')
    return (array('dirname' => '.', 'basename' => '.',
		 'extension' => '', 'filename' => ''));
  $path = trim($path, '/');
  $tab = explode('/', $path);
  for ($i = 0; $i < count($tab) - 1; $i++)
    $res['dirname'] .= '/'.$tab[$i];
  $res['basename'] = $tab[count($tab) - 1];
  if (preg_match("#([a-z]+)\.([a-z]+)#", $tab[count($tab) - 1], $tmp))
    $res['extension'] = $tmp[2];
  if (preg_match("#([a-z]+)\.([a-z]+)#", $tab[count($tab) - 1], $tmp))
    $res['filename'] = $tmp[1];
  else
    $res['filename'] = $tab[count($tab) - 1];
  return ($res);
}

?>
