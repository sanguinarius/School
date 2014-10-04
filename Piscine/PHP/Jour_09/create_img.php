<?php
// create_img.php for create_img.php in /Users/laxa/Documents/Piscine/PHP/Jour_09/egloff_j
// 
// Made by Julien EGLOFF
// Login   <egloff_j@etna-alternance.net>
// 
// Started on  Thu Apr 17 11:14:35 2014 Julien EGLOFF
// Last update Fri Apr 18 11:29:22 2014 Julien EGLOFF
//

$x = 0;
$y = 0;
$highest = 0;
$count = 1;

function	create_img($img_array, $tab, $path)
{
  global	$count;

  $image = imagecreatetruecolor(1440, 900);
  for ($i = 0; isset($img_array[$i]); $i++)
    {
      $image2 = create_img_from_array($img_array[$i]);
      $image2 = resize_image($image2);
      if (check_space($image2) === FALSE || ($i != 0 &&
					     ($i  + 1) % $tab['l'] == 0))
	{
	  save_img($image, $tab);
	  imagedestroy($image);
	  $image = imagecreatetruecolor(1440, 900);
	  ++$count;
	}
      $path['i'] = $i;
      copy_image($image, $image2, $path, $tab);
      imagedestroy($image2);
    }
  save_img($image, $tab);
  imagedestroy($image);
  echo count($img_array)." found images\n";
}

function	resize_image($image)
{
  while (imagesx($image) > 200 || imagesy($image) > 200)
    {
      $dest = imagecreatetruecolor(imagesx($image) / 2, imagesy($image) / 2);
      imagecopyresampled($dest, $image, 0, 0, 0, 0, imagesx($image) / 2,
			 imagesy($image) / 2, imagesx($image), imagesy($image));
      imagedestroy($image);
      $image = $dest;
    }
  return ($image);
}

function	check_space($image)
{
  global	$x;
  global	$y;
  global	$highest;

  if (imagesx($image) + $x > 1440)
    {
      $x = 0;
      $y += $highest;
      $highest = 0;
    }
  if (imagesy($image) + $y > 900)
    {
      $x = 0;
      $y = 0;
      $highest = 0;
      return (FALSE);
    }
  return (TRUE);
}

function	create_img_from_array($img)
{
  if (strlen(strstr($img, '.png')))
    $image = imagecreatefrompng($img);
  else if (strlen(strstr($img, '.gif')))
    $image = imagecreatefromgif($img);
  else if (strlen(strstr($img, '.jpg')))
    $image = imagecreatefromjpeg($img);
  return ($image);
}

function	copy_image($dest, $src, $path, $tab)
{
  global	$x;
  global	$y;
  global	$highest;

  imagecopy($dest, $src, $x, $y, 0, 0, imagesx($src), imagesy($src));
  if ($tab['n'])
    {
      put_text_under_img($dest, $src, $path);
      $highest = imagesy($src) > $highest ? imagesy($src) : $highest;
      $highest += 3;
    }
  else if ($tab['N'])
    {
      put_text_extension_img($dest, $src, $path);
      $highest = imagesy($src) > $highest ? imagesy($src) : $highest;
      $highest += 3;
    }
  else
    $highest = imagesy($src) > $highest ? imagesy($src) : $highest;
  $x += imagesx($src);
  $highest = imagesy($src) > $highest ? imagesy($src) : $highest;
}

?>
