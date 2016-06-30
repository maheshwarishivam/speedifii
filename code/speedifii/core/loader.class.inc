<?php

namespace speedifii\core;
/**
 * Class Loader
 * @package speedifii\core
 */
class Loader
{

    /**
     * Loader constructor.
     */
    public function __construct()
    {

    }

    /**
     * Load the specified model
     * @param $model
     */
    public function model($model)
    {
        require MODEL_PATH . "$model.model.inc";
    }

    /**
     * Load the specified library
     * @param $lib
     */
    public function library($lib)
    {
        require LIB_PATH . $lib . DS . "logger.autoload.inc";
    }

    /**
     * Load the specified helper
     * @param $helper
     */
    public function helper($helper)
    {
        require HELPER_PATH . "$helper.helper.inc";
    }

    /**
     * Load the specified language
     * @param $lang
     */
    public function language($lang)
    {
        require LANGUAGE_PATH . "$lang.language.inc";
    }


    /**
     * Load the specified config
     * @param $lang
     */
    public function config($config)
    {
        try{
            $configfile = file_get_contents(CONFIG_PATH . "$config.config.inc", true);
            $start = strpos($configfile, '{');
            $config_body = json_decode(trim(substr($configfile, $start)), TRUE);

            $GLOBALS['config']=array_merge($GLOBALS['config'],$config_body);
        } catch (Exception $e) {
            throw $e;
        }
    }
    
 

}


/* EOF */