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
        require LIB_PATH . $lib . DS . "$lib.autoload.inc";
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
     * @param $lang Language to load
     * @throws \Exception
     */
    public function language($lang)
    {
        try {
            $langFile = file_get_contents(LANGUAGE_PATH . "$lang.language.json", true);
            $start = strpos($langFile, '{');
            $langBody = json_decode(trim(substr($langFile, $start)), true);

            if($langBody) {
                $GLOBALS['language'][$lang] = $langBody;
            } else {
                throw new \Exception('Invalid Language file: ' . LANGUAGE_PATH . "$lang.language.json");
            }
        } catch (\Exception $e) {
            throw $e;
        }
    }


    /**
     * Load the specified config
     * @param $config config to load
     * @throws \Exception
     */
    public function config($config)
    {
        try {
            $configFile = file_get_contents(CONFIG_PATH . "$config.config.json", true);
            $start = strpos($configFile, '{');
            $configBody = json_decode(trim(substr($configFile, $start)), TRUE);

            if($configBody) {
                if(!isset($GLOBALS['config'][$config]) || !is_array($GLOBALS['config'][$config])) {
                    $GLOBALS['config'][$config] = array();
                }
                $GLOBALS['config'][$config] = array_merge($GLOBALS['config'][$config], $configBody);
            } else {
                throw new \Exception('Invalid Config file: ' . CONFIG_PATH . "$config.config.json");
            }
        } catch (\Exception $e) {
            throw $e;
        }
    }
}

/* EOF */