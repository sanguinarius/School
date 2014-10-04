#!/usr/bin/env php
<?php
// hello.php for hello.php in /Users/laxa/Documents/Piscine/PHP/Jour_03/egloff_j/hello
// 
// Made by Julien EGLOFF
// Login   <egloff_j@etna-alternance.net>
// 
// Started on  Thu Apr 10 09:21:49 2014 Julien EGLOFF
// Last update Thu Apr 10 10:15:17 2014 Julien EGLOFF
//

function	hello($param = NULL)
{
  if (isset($param))
    echo "Hello ".$param." !\n";
  else
    echo "Hello world !\n";
}

?>
