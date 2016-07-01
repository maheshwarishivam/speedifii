/**
 * Configure how sessions should be handled
 *
 * sessionHandler: Define the session handler
 *     Currently one of:
 *         - default: Use PHP Default Session
 *         - none: Don't use sessions at all
 * name: The name of session cookie
 * timeout: session timeout
 */
{
  "session": {
    "sessionHandler": "default",
    "name": "SpeediFii",
    "timeout": 1880,
    "redisHost": '127.0.0.1',
    "redisPort": '6379',
    "redisPassword": 'redisPassword',
    "redisDatabase": '1'
  }
}
