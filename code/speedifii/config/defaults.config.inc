<?php

//Application defaults

/**
 * The default Timezone
 */
$config['application']['timezone'] = 'UTC';

/**
 * The default language
 */
$config['application']['language'] = 'en_us';

//Session Defaults

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

//Application Log Defaults

/**
 * Log Files Directory
 */

$config['log']['directory'] = ROOT . 'logs';

/**
 * Log Level
 *
 * Possible Values are (in order of highest priority to lowest):
 * - emergency;
 * - alert;
 * - critical;
 * - error;
 * - warning;
 * - notice;
 * - info;
 * - debug;
 */
$config['log']['level'] = 'debug';

/**
 * Log file Prefix
 */
$config['log']['logFilePrefix'] = 'application_';

/* EOF */