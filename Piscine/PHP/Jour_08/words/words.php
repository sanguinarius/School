#!/usr/bin/env php
<?php
// words.php for words.php in /Users/laxa/Documents/Piscine/PHP/Jour_08/egloff_j/words
// 
// Made by Julien EGLOFF
// Login   <egloff_j@etna-alternance.net>
// 
// Started on  Wed Apr 16 10:07:05 2014 Julien EGLOFF
// Last update Wed Apr 16 10:55:43 2014 Julien EGLOFF
//

function	words($str)
{
  preg_match_all("#\w+\s?#", $str, $matches);
  foreach ($matches[0] as $value)
    echo trim($value)."\n";
}

if ($argc == 2)
  words($_SERVER['argv'][1])

?>
