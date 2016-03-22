<?php
// parse_html.php for parse_html.php in /Users/laxa/Documents/Piscine/PHP/Jour_09/egloff_j
// 
// Made by Julien EGLOFF
// Login   <laxa>
// 
// Started on  Thu Apr 17 10:04:36 2014 Julien EGLOFF
// Last update Fri Apr 18 09:47:38 2014 Julien EGLOFF
//

function	parse_html($tab)
{
  $img_array = array();

  for ($i = 0; isset($tab['param'][$i]); $i++)
    {
      if (($content = @file_get_contents($tab['param'][$i])) === FALSE)
	{
	  echo "Error while getting content of ".$tab['param'][$i]."\n";
	  continue;
	}
      preg_match_all('#<img[^>]*src="([^?|^"]*)[^>]*>#', $content, $matches);
      foreach ($matches[1] as $key => $value)
	if (strlen(strstr($value, 'http')) == 0)
	  $matches[1][$key] = 'http:'.$value;
      foreach ($matches[1] as $value)
	$img_array[] .= $value;
    }
  $img_array = parse_img_array($img_array);
  return ($img_array);
}

function	parse_img_array($img_array)
{
  foreach ($img_array as $key => $value)
    {
      if (strlen(stristr($value, 'background')))
	unset($img_array[$key]);
      if (strlen(stristr($value, '_bg_')))
	unset($img_array[$key]);
      if (strlen(stristr($value, 'bg_')))
	unset($img_array[$key]);
      if (strlen(stristr($value, '_bg')))
	unset($img_array[$key]);
      if (@getimagesize($value) === FALSE)
	{
	  echo "Image ".$value." not supported by GD\n";
	  unset($img_array[$key]);
	}
      if (preg_match('#(\.jpg|\.png|\.gif)$#', $value) == FALSE)
	{
	  echo "Image ".$value." not having an extension\n";
	  unset($img_array[$key]);
	}
    }
  $img_array = array_values($img_array);
  return ($img_array);
}

?>
