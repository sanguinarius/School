#!/usr/bin/env php
<?php
// imagepanel.php for imagepanel.php in /Users/laxa/Documents/Piscine/PHP/Jour_09/egloff_j
// 
// Made by Julien EGLOFF
// Login   <laxa>
// 
// Started on  Wed Apr 16 19:27:11 2014 Julien EGLOFF
// Last update Fri Apr 18 10:51:09 2014 fériel abachi
//

require_once('parse.php');
require_once('parse_html.php');
require_once('create_img.php');
require_once('create_img2.php');

function	imagepanel($argc, $argv)
{
  $tab = check_arg($argc, $argv);
  $img_array = parse_html($tab);
  $path = recup_filename($img_array);
  if ($tab['s'] == 1)
    usort($img_array, "strcmp");
  if (count($img_array))
    create_img($img_array, $tab, $path);
}

imagepanel($_SERVER['argc'], $_SERVER['argv']);

?>
