<?php

/**
 * Define the session handler
 * Currently one of:
 *  - default: Use PHP Default Session
 *  - none: Don't use sessions at all
 */
$config['session']['sessionHandler'] = 'default';

/**
 * Name of session cookie
 */
$config['session']['name'] = 'SpeediFii';

/**
 * Session Timeout
 */
$config['session']['timeout'] = 1880; //30 Minutes

/* EOF */