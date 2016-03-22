<?php
// quit.php for quit.php in /Users/laxa/Documents/PHP/BDPHP/egloff_j
// 
// Made by Julien EGLOFF
// Login   <laxa>
// 
// Started on  Thu Apr 24 11:57:36 2014 Julien EGLOFF
// Last update Fri Apr 25 15:25:35 2014 Julien EGLOFF
//

function	func_quit($tab)
{
  fclose($tab['fd_input']);
  fclose($tab['fd_dbfile']);
  if (isset($tab['fd_output']))
    fclose($tab['fd_output']);
  exit();
}

?>
