<?php

//Autoload PRedis
require CORE_LIB_PATH . 'redissession' . DS . 'predis' . DS . 'Autoloader.php';
Predis\Autoloader::register();

//Require RedisSessionHandler
require CORE_LIB_PATH . 'redissession' . DS . 'redissessionhandler.class.inc';
