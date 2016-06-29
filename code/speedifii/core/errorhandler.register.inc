<?php

use \speedifii\libraries\logger\Logger;

/**
 * Error handler
 * @param $errno
 * @param $errstr
 * @param $errfile
 * @param $errline
 * @param $errcontext
 *
function speediFiiErrorHandler($errno, $errstr, $errfile, $errline, $errcontext)
{
    // Perform your error handling here, respecting error_reporting() and
    // $errno.  This is where you can log the errors.  The choice of logger
    // that you use is based on your preference.  So long as it implements
    // the observer pattern you will be able to easily add logging for any
    // type of output you desire.
    //echo $errno . $errstr . $errfile . $errline . $errcontext;

}

//Set Custom Error Handler
//$previousErrorHandler = set_error_handler('speediFiiErrorHandler');
*/

/**
 * Exception Handler
 * @param $e
 */
function speediFiiExceptionHandler(\Exception $e)
{
    //Log Exception
    Logger::getLogger()->emergency('Unhandled Exception: ' . $e->getMessage(),array('exception'=>$e));

    //Trigger Error
    trigger_error('Unhandled Exception: ' . $e->getMessage(), E_USER_ERROR);
}

$previousExceptionHandler = set_exception_handler('speediFiiExceptionHandler');

/**
 * ShutDown Handler
 */
function speediFiiShutdownFunction()
{
    $err = error_get_last();

    $handledErrorTypes = array(
        E_USER_ERROR => 'USER ERROR',
        E_ERROR => 'ERROR',
        E_PARSE => 'PARSE',
        E_CORE_ERROR => 'CORE_ERROR',
        E_CORE_WARNING => 'CORE_WARNING',
        E_COMPILE_ERROR => 'COMPILE_ERROR',
        E_COMPILE_WARNING => 'COMPILE_WARNING');

    // If our last error was fatal then this can not be a normal shutdown.
    if (isset($err) && isset($handledErrorTypes[$err['type']])) {
        if (!headers_sent()) {
            http_response_code(500);
        }
        //Log error
        Logger::getLogger()->error("Unhandled error",$err);
    }
    //Send the output back to client
    ob_end_flush();

    //Write Logs to file
    Logger::getLogger()->writeLogs();
}

register_shutdown_function('speediFiiShutdownFunction');