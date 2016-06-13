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

}


/* EOF */