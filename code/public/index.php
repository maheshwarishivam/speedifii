<?php
ob_start();

//Define core constants
define('SPEEDIIFIIBASE', 1);

//Require Bootstrap Class
require realpath(__dir__ . DIRECTORY_SEPARATOR . '..' . DIRECTORY_SEPARATOR . 'speedifii' . DIRECTORY_SEPARATOR . 'bootstrap.class.inc');

//Run
speedifii\Bootstrap::run();

/* EoF */