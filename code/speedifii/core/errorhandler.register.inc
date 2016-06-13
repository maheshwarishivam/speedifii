<?php

/**
 * Error handler
 * @param $errno
 * @param $errstr
 * @param $errfile
 * @param $errline
 * @param $errcontext
 */
function speediFiiErrorHandler($errno, $errstr, $errfile, $errline, $errcontext)
{
    // Perform your error handling here, respecting error_reporting() and
    // $errno.  This is where you can log the errors.  The choice of logger
    // that you use is based on your preference.  So long as it implements
    // the observer pattern you will be able to easily add logging for any
    // type of output you desire.
}

//Set Custom Error Handler
$previousErrorHandler = set_error_handler('speediFiiErrorHandler');


/**
 * Exception Handler
 * @param $e
 */
function speediFiixceptionHandler($e)
{
    // Perform your exception handling here.
}

$previousExceptionHandler = set_exception_handler('speediFiixceptionHandler');

/**
 * ShutDown Handler
 */
function speediFiiShutdownFunction()
{
    $err = error_get_last();

    if (!isset($err)) {
        return;
    }

    $handledErrorTypes = array(
        E_USER_ERROR => 'USER ERROR',
        E_ERROR => 'ERROR',
        E_PARSE => 'PARSE',
        E_CORE_ERROR => 'CORE_ERROR',
        E_CORE_WARNING => 'CORE_WARNING',
        E_COMPILE_ERROR => 'COMPILE_ERROR',
        E_COMPILE_WARNING => 'COMPILE_WARNING');

    // If our last error wasn't fatal then this must be a normal shutdown.
    if (!isset($handledErrorTypes[$err['type']])) {
        return;
    }

    if (!headers_sent()) {
        http_response_code(500);
    }

    // Perform simple logging here.
}

register_shutdown_function('speediFiiShutdownFunction');