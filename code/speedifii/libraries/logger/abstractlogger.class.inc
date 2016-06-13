<?php

namespace speedifii\libraries\logger;


/**
 * This is a simple Logger implementation that other Loggers can inherit from.
 *
 * It simply delegates all log-level-specific methods to the `log` method to
 * reduce boilerplate code that a simple Logger that does the same thing with
 * messages regardless of the error level has to implement.
 */
abstract class AbstractLogger implements LoggerInterface
{
    /**
     * System is unusable.
     *
     * @param string $message
     * @param array $context
     * @param bool $microTimeInFloat
     * @return null
     */
    public function emergency($message, $microTimeInFloat = false, array $context = array())
    {
        $this->log(LogLevel::EMERGENCY, $message, $microTimeInFloat, $context);
    }

    /**
     * Action must be taken immediately.
     *
     * Example: Entire website down, database unavailable, etc. This should
     * trigger the SMS alerts and wake you up.
     *
     * @param string $message
     * @param array $context
     * @param bool $microTimeInFloat
     * @return null
     */
    public function alert($message, $microTimeInFloat = false, array $context = array())
    {
        $this->log(LogLevel::ALERT, $message, $microTimeInFloat, $context);
    }

    /**
     * Critical conditions.
     *
     * Example: Application component unavailable, unexpected exception.
     *
     * @param string $message
     * @param array $context
     * @param bool $microTimeInFloat
     * @return null
     */
    public function critical($message, $microTimeInFloat = false, array $context = array())
    {
        $this->log(LogLevel::CRITICAL, $message, $microTimeInFloat, $context);
    }

    /**
     * Runtime errors that do not require immediate action but should typically
     * be logged and monitored.
     *
     * @param string $message
     * @param array $context
     * @param bool $microTimeInFloat
     * @return null
     */
    public function error($message, $microTimeInFloat = false, array $context = array())
    {
        $this->log(LogLevel::ERROR, $message, $microTimeInFloat, $context);
    }

    /**
     * Exceptional occurrences that are not errors.
     *
     * Example: Use of deprecated APIs, poor use of an API, undesirable things
     * that are not necessarily wrong.
     *
     * @param string $message
     * @param array $context
     * @param bool $microTimeInFloat
     * @return null
     */
    public function warning($message, $microTimeInFloat = false, array $context = array())
    {
        $this->log(LogLevel::WARNING, $message, $microTimeInFloat, $context);
    }

    /**
     * Normal but significant events.
     *
     * @param string $message
     * @param array $context
     * @param bool $microTimeInFloat
     * @return null
     */
    public function notice($message, $microTimeInFloat = false, array $context = array())
    {
        $this->log(LogLevel::NOTICE, $message, $microTimeInFloat, $context);
    }

    /**
     * Interesting events.
     *
     * Example: User logs in, SQL logs.
     *
     * @param string $message
     * @param array $context
     * @param bool $microTimeInFloat
     * @return null
     */
    public function info($message, $microTimeInFloat = false, array $context = array())
    {
        $this->log(LogLevel::INFO, $message, $microTimeInFloat, $context);
    }

    /**
     * Detailed debug information.
     *
     * @param string $message
     * @param array $context
     * @param bool $microTimeInFloat
     * @return null
     */
    public function debug($message, $microTimeInFloat = false, array $context = array())
    {
        $this->log(LogLevel::DEBUG, $message, $microTimeInFloat, $context);
    }
}

/* EOF */