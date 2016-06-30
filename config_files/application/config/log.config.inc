/**
* Configuration for handling application logs
*
* directory: Log Files Directory
* level: Log Level
*     Possible Values are (in order of highest priority to lowest):
*         - emergency;
*         - alert;
*         - critical;
*         - error;
*         - warning;
*         - notice;
*         - info;
*         - debug;
*/
{
  "log": {
    "directory": "/var/www/html/speedifii/code/logs",
    "level": "debug",
    "logFilePrefix": "application_"
  }
}