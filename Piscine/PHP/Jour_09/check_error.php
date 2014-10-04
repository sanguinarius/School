<?php
// check_error.php for  in /Users/ferielabachi/picine/phpicine/imagepanel/egloff_j
// 
// Made by fériel abachi
// Login   <abachi_f@etna-alternance.net>
// 
// Started on  Thu Apr 17 19:07:35 2014 fériel abachi
// Last update Fri Apr 18 11:21:27 2014 Julien EGLOFF
//

function	recup_filename($img)
{
  $name = array('name' => array(), 'extension' => array());
  for ($i = 0; isset($img[$i]); $i++)
    {
      $path = pathinfo($img[$i]);
      $name['name'][$i] = $path['filename'];
      $name['extension'][$i] = $path['extension'];
    }
  return ($name);
}

function	check_arg($argc, $argv)
{
  if ($argc > 2)
    $op = recup_option($argc, $argv);
  else
    {
      echo "./imagepanel.php [options] lien1 [lien2 [...]] base\n";
      exit ();
    }
  return ($op);
}

function	check_options($opt)
{
  if ($opt['j'] && ($opt['g'] || $opt['p']))
    {
      echo "Can only have 1 of the following options : j or g or p\n";
      exit();
    }
  if ($opt['g'] && ($opt['j'] || $opt['p']))
    {
      echo "Can only have 1 of the following options : j or g or p\n";
      exit();
    }
  if ($opt['p'] && ($opt['g'] || $opt['j']))
    {
      echo "Can only have 1 of the following options : j or g or p\n";
      exit();
    }
  if ($opt['n'] && $opt['N'])
    {
      echo "Can only have 1 of the following options : n or N\n";
      exit();
    }
}
