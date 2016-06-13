<?php
namespace speedifii;

use speedifii\libraries\uuid\UUID;

/**
 * Class Bootstrap
 * @package speedifii
 */
class Bootstrap
{

    /**
     * Bootstrap constructor.
     *
     * Private to prevent instantiation
     */
    private function __construct()
    {

    }

    /**
     * Bootstrap main function
     */
    public static function run()
    {

        self::init();

        self::autoload();

        self::handleSessions();

        self::dispatch();
    }

    /**
     * Function to Initialize the Framework
     */
    private static function init()
    {

        // Define path constants

        define('DS', DIRECTORY_SEPARATOR);

        define('ROOT', realpath(__dir__ . DS . '..') . DS);

        define('APP_PATH', ROOT . 'application' . DS);

        define('FRAMEWORK_PATH', ROOT . 'speedifii' . DS);

        define('PUBLIC_PATH', ROOT . 'public' . DS);


        define('CONFIG_PATH', APP_PATH . 'config' . DS);

        define('CONTROLLER_PATH', APP_PATH . 'controllers' . DS);

        define('HELPER_PATH', APP_PATH . 'helpers' . DS);

        define('LANGUAGE_PATH', APP_PATH . 'languages' . DS);

        define('LIB_PATH', APP_PATH . 'libraries' . DS);

        define('MODEL_PATH', APP_PATH . 'models' . DS);

        define('VIEW_PATH', APP_PATH . 'views' . DS);


        define('CORE_CONFIG_PATH', FRAMEWORK_PATH . 'config' . DS);

        define('CORE_CONTROLLER_PATH', FRAMEWORK_PATH . 'controllers' . DS);

        define('CORE_HELPER_PATH', FRAMEWORK_PATH . 'helpers' . DS);

        define('CORE_LIB_PATH', FRAMEWORK_PATH . 'libraries' . DS);

        define('CORE_MODEL_PATH', FRAMEWORK_PATH . 'models' . DS);

        define('CORE_PATH', FRAMEWORK_PATH . 'core' . DS);

        // Define platform, controller, action, for example:

        // index.php?p=admin&c=Goods&a=add

        define('PLATFORM', isset($_GET['p']) ? $_GET['p'] : 'app');

        define('CONTROLLER', isset($_GET['c']) ? $_GET['c'] : 'Index');

        define('ACTION', isset($_GET['a']) ? $_GET['a'] : 'index');

        define('CURR_CONTROLLER_PATH', CONTROLLER_PATH . PLATFORM . DS);

        define('CURR_VIEW_PATH', VIEW_PATH . PLATFORM . DS);

        // Load global configuration
        global $config;
        $config = array();
        require CORE_CONFIG_PATH . 'defaults.config.inc';

        //Load Application's configuration files
        require CONFIG_PATH . 'application.config.inc';
        require CONFIG_PATH . 'session.config.inc';
        require CONFIG_PATH . 'autoload.config.inc';
        require CONFIG_PATH . 'log.config.inc';

        //Load other required classes
        require CORE_PATH . 'loader.class.inc';

        require CORE_PATH . 'request.class.inc';

        require CORE_PATH . 'response.class.inc';

        require CORE_MODEL_PATH . 'base.model.inc';

        require CORE_CONTROLLER_PATH . 'base.controller.inc';

        //Load core helpers
        require CORE_HELPER_PATH . 'validation.helper.inc';

        //Load core Libraries
        //Logger Library
        require CORE_LIB_PATH . 'logger' . DS . 'logger.autoload.inc';

        //UUID Library
        require CORE_LIB_PATH . 'uuid' . DS . 'uuid.autoload.inc';

        //Set Timezone
        date_default_timezone_set($GLOBALS['config']['application']['timezone']);

        //Language is available from $GLOBALS['config']['application']['language'];

    }

    /**
     * Function to autoload classes, configs, languages etc.
     */
    private static function autoload()
    {
        // Autoload config files
        foreach ($GLOBALS['config']['autoload']['config'] as $fileName) {
            if (!empty($fileName)) {
                require CONFIG_PATH . "$fileName.config.inc";
            }
        }

        // Autoload helpers
        foreach ($GLOBALS['config']['autoload']['helpers'] as $fileName) {
            if (!empty($fileName)) {
                require HELPER_PATH . "$fileName.helper.inc";
            }
        }

        // Autoload libraries
        foreach ($GLOBALS['config']['autoload']['libraries'] as $fileName) {
            if (!empty($fileName)) {
                require LIB_PATH . $fileName . DS . "$fileName.autoload.inc";
            }
        }

        // Autoload models
        foreach ($GLOBALS['config']['autoload']['models'] as $fileName) {
            if (!empty($fileName)) {
                require MODEL_PATH . "$fileName.model.inc";
            }
        }

        // Autoload controllers
        foreach ($GLOBALS['config']['autoload']['controllers'] as $fileName) {
            if (!empty($fileName)) {
                require CONTROLLER_PATH . "$fileName.controller.inc";
            }
        }

        // Autoload languages
        foreach ($GLOBALS['config']['autoload']['languages'] as $fileName) {
            if (!empty($fileName)) {
                require LANGUAGE_PATH . "$fileName.language.inc";
            }
        }

        //Autoload current Language
        require LANGUAGE_PATH . $GLOBALS['config']['application']['language'] . '.language.inc';

        //Autoload current Controller
        require CURR_CONTROLLER_PATH . CONTROLLER . '.controller.inc';

    }

    /**
     * Function to register and start session
     */
    private static function handleSessions()
    {
        if ($GLOBALS['config']['session']['sessionHandler'] != 'none') {
            //Set Name of Session cookie to be used. This should come from config
            session_name($GLOBALS['config']['session']['name']);

            ini_set('session.gc-maxlifetime', $GLOBALS['config']['session']['timeout']);
            ini_set("session.cookie_lifetime", $GLOBALS['config']['session']['timeout']);

            //Start Session
            session_start();
            //Renew the session cookie
            setcookie(session_name(), session_id(), time() + $GLOBALS['config']['session']['timeout'], '/');
        }
    }

    /**
     * Function to dispatch control to Controller
     */
    private static function dispatch()
    {
        //Define Unique identifier for Application Logs

        $sessionId = false;
        if ($GLOBALS['config']['session']['sessionHandler'] != 'none') {
            //Session is available, use the session ID
            $sessionId = session_id();
        }

        define('LOG_IDENTIFIER', ($sessionId ? $sessionId . ' | ' : '') . UUID::v4());

        //Register Error, Exception and Shutdown Handlers


        // Instantiate the controller class and call its action method
        $controller_name = CONTROLLER . 'Controller';

        $action_name = ACTION . 'Action';

        $controller = new $controller_name();

        $controller->$action_name();

    }

}

/* EOF */