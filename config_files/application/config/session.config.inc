

/**
 * Define the session handler
 * Currently one of:
 *  - default: Use PHP Default Session
 *  - none: Don't use sessions at all
 *  - redis: Store sessions in Redis
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
