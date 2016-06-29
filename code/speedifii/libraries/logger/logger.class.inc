<?php

namespace speedifii\libraries\logger;

/**
 * Class Logger
 * @package speedifii\libraries\logger
 *
 * Usage:
 * $log->info('Returned a million search results'); //Prints to the log file
 * $log->error('Oh dear.'); //Prints to the log file
 * $log->debug('Some error occured',array('data'=>$data,'exception'=>$e)); //Prints to the log file
 */
class Logger
{
    /**
     * @var Logger The reference to *Singleton* instance of this class
     */
    private static $__instance;

    /**
     * @var LogWriter $logWriter
     */
    private $logWriter;

    /**
     * @var array $logsToBeWritten
     */
    private $logsToBeWritten;

    /*
     * @var bool $isLogProcessed
     */
    private $isLogProcessed;

    /**
     * Returns the *Singleton* instance of this class.
     *
     * @return Logger The *Singleton* instance.
     */
    public static function getLogger()
    {
        if(self::$__instance == NULL) self::$__instance = new Logger;
        return self::$__instance;
    }

    /**
     * Private clone method to prevent cloning of the instance of the
     * *Singleton* instance.
     *
     * @return void
     */
    private function __clone()
    {
    }

    /**
     * Private unserialize method to prevent unserializing of the *Singleton*
     * instance.
     *
     * @return void
     */
    private function __wakeup()
    {
    }

    /**
     * Logger constructor.
     *
     * Private constructor to prevent creating a new instance of the
     * Singleton* via the `new` operator from outside of this class.
     */
    private function __construct()
    {
        $this->logWriter = NULL;
        $this->logsToBeWritten = array();
        $this->isLogProcessed = false;
    }

    /**
     * Logger destructor
     */
    public function __destruct()
    {
        if (!$this->isLogProcessed) {
            $this->writeLogs();
        }
    }


    /**
     * Collect data to log
     *
     * The message MUST be a string or object implementing __toString().
     *
     * The message MAY contain placeholders in the form: {foo} where foo
     * will be replaced by the context data in key "foo".
     *
     * The context array can contain arbitrary data, the only assumption that
     * can be made by implementors is that if an Exception instance is given
     * to produce a stack trace, it MUST be in a key named "exception".
     *
     * @param string $logLevel
     * @param $message
     * @param array $context
     */
    private function log($logLevel, $message, $context)
    {
        $this->isLogProcessed = false;
        $this->logsToBeWritten[] = array(
            'level' => $logLevel,
            'message' => $message,
            'timestamp' => microtime(true),
            'context' => $context
        );
    }

    /**
     * Write logs to Log File
     * @throws \RuntimeException
     */
    public function writeLogs()
    {
        try {
            $this->logWriter = new LogWriter($GLOBALS['config']['log']['directory'], $GLOBALS['config']['log']['level'], array(
                'prefix' => $GLOBALS['config']['log']['logFilePrefix']
            ));
            foreach ($this->logsToBeWritten as $log) {
                switch ($log['level']) {
                    case 'emergency':
                        $this->logWriter->emergency($log['message'], $log['timestamp'], $log['context']);
                        break;
                    case 'alert':
                        $this->logWriter->alert($log['message'], $log['timestamp'], $log['context']);
                        break;
                    case 'critical':
                        $this->logWriter->critical($log['message'], $log['timestamp'], $log['context']);
                        break;
                    case 'error':
                        $this->logWriter->error($log['message'], $log['timestamp'], $log['context']);
                        break;
                    case 'warning':
                        $this->logWriter->warning($log['message'], $log['timestamp'], $log['context']);
                        break;
                    case 'notice':
                        $this->logWriter->notice($log['message'], $log['timestamp'], $log['context']);
                        break;
                    case 'info':
                        $this->logWriter->info($log['message'], $log['timestamp'], $log['context']);
                        break;
                    default:
                        $this->logWriter->debug($log['message'], $log['timestamp'], $log['context']);
                        break;
                }
            }
            //Empty the logs
            $this->logsToBeWritten = array();
            $this->isLogProcessed = true;
        } catch (\Exception $ex) {
            //In case of exception, write to server logs
            trigger_error('Unable to write logs: ' . json_encode($this->logsToBeWritten),E_USER_ERROR);
        }
    }

    /**
     * System is unusable.
     *
     * @param string $message
     * @param array $context
     * @return null
     */
    public function emergency($message, array $context = array())
    {
        $this->log('emergency', $message, $context);
    }

    /**
     * Action must be taken immediately.
     *
     * Example: Entire website down, database unavailable, etc. This should
     * trigger the SMS alerts and wake you up.
     *
     * @param string $message
     * @param array $context
     * @return null
     */
    public function alert($message, array $context = array())
    {
        $this->log('alert', $message, $context);
    }

    /**
     * Critical conditions.
     *
     * Example: Application component unavailable, unexpected exception.
     *
     * @param string $message
     * @param array $context
     * @return null
     */
    public function critical($message, array $context = array())
    {
        $this->log('critical', $message, $context);
    }

    /**
     * Runtime errors that do not require immediate action but should typically
     * be logged and monitored.
     *
     * @param string $message
     * @param array $context
     * @return null
     */
    public function error($message, array $context = array())
    {
        $this->log('error', $message, $context);
    }

    /**
     * Exceptional occurrences that are not errors.
     *
     * Example: Use of deprecated APIs, poor use of an API, undesirable things
     * that are not necessarily wrong.
     *
     * @param string $message
     * @param array $context
     * @return null
     */
    public function warning($message, array $context = array())
    {
        $this->log('warning', $message, $context);
    }

    /**
     * Normal but significant events.
     *
     * @param string $message
     * @param array $context
     * @return null
     */
    public function notice($message, array $context = array())
    {
        $this->log('notice', $message, $context);
    }

    /**
     * Interesting events.
     *
     * Example: User logs in, SQL logs.
     *
     * @param string $message
     * @param array $context
     * @return null
     */
    public function info($message, array $context = array())
    {
        $this->log('info', $message, $context);
    }

    /**
     * Detailed debug information.
     *
     * @param string $message
     * @param array $context
     * @return null
     */
    public function debug($message, array $context = array())
    {
        $this->log('debug', $message, $context);
    }
}

/* EOF */