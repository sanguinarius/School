<?php
// create_img2.php for create_img2.php in /Users/laxa/Documents/Piscine/PHP/Jour_09/egloff_j
// 
// Made by Julien EGLOFF
// Login   <egloff_j@etna-alternance.net>
// 
// Started on  Thu Apr 17 16:45:36 2014 Julien EGLOFF
// Last update Fri Apr 18 11:27:29 2014 Julien EGLOFF
//

function	save_img($image, $tab)
{
  global	$count;
  global	$x;
  global	$y;
  global	$highest;

  $x = 0;
  $y = 0;
  $highest = 0;
  if ($tab['j'] == 1)
    imagejpeg($image, $tab['base'].$count.'.jpg');
  else if ($tab['g'] == 1)
    imagegif($image, $tab['base'].$count.'.gif');
  else if ($tab['p'] == 1)
    imagepng($image, $tab['base'].$count.'.png');
  else
    imagejpeg($image, $tab['base'].$count.'.jpg');
}

function	put_text_under_img($dest, $src, $path)
{
  global	$x;
  global	$y;

  $white = imagecolorallocate ($dest, 255, 255, 255);
  imagestring($dest, 3, $x, imagesy($src) + $y + 3, $path['name'][$path['i']]
	      , $white);
}

function	put_text_extension_img($dest, $src, $path)
{
  global	$x;
  global	$y;

  $white = imagecolorallocate ($dest, 255, 255, 255);
  imagestring($dest, 3, $x, imagesy($src) + $y + 3,
	      $path['name'][$path['i']].'.'.$path['extension'][$path['i']],
	      $white);
}

?>
