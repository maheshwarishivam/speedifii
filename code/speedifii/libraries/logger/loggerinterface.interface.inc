<?php

namespace speedifii\libraries\logger;


/**
 * Describes a logger instance
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
 */
interface LoggerInterface
{
    /**
     * System is unusable.
     *
     * @param string $message
     * @param array $context
     * @param bool $microTimeInFloat
     * @return null
     */
    public function emergency($message, $microTimeInFloat = false, array $context = array());

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
    public function alert($message, $microTimeInFloat = false, array $context = array());

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
    public function critical($message, $microTimeInFloat = false, array $context = array());

    /**
     * Runtime errors that do not require immediate action but should typically
     * be logged and monitored.
     *
     * @param string $message
     * @param array $context
     * @param bool $microTimeInFloat
     * @return null
     */
    public function error($message, $microTimeInFloat = false, array $context = array());

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
    public function warning($message, $microTimeInFloat = false, array $context = array());

    /**
     * Normal but significant events.
     *
     * @param string $message
     * @param array $context
     * @param bool $microTimeInFloat
     * @return null
     */
    public function notice($message, $microTimeInFloat = false, array $context = array());

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
    public function info($message, $microTimeInFloat = false, array $context = array());

    /**
     * Detailed debug information.
     *
     * @param string $message
     * @param array $context
     * @param bool $microTimeInFloat
     * @return null
     */
    public function debug($message, $microTimeInFloat = false, array $context = array());

    /**
     * Logs with an arbitrary level.
     *
     * @param mixed $level
     * @param string $message
     * @param array $context
     * @param bool $microTimeInFloat
     * @return null
     */
    public function log($level, $message, $microTimeInFloat, array $context = array());
}

/* EOF */