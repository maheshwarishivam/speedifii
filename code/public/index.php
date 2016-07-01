<?php
//Don't display errors
ini_set('display_errors','off');

ob_start();

//Require Bootstrap Class
require realpath(__dir__ . DIRECTORY_SEPARATOR . '..' . DIRECTORY_SEPARATOR . 'speedifii' . DIRECTORY_SEPARATOR . 'bootstrap.class.inc');

//Run
speedifii\Bootstrap::run();
/* EoF */
