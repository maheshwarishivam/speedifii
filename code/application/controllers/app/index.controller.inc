<?php

use speedifii\controllers\BaseController;
use \speedifii\libraries\logger\Logger;

/**
 * Class IndexController
 * @package application\controllers\app\
 */
class IndexController extends BaseController
{
    /**
     * @ Index Action
     */
    public function indexAction()
    {
        // TODO: Implement IndexAction() method.
        $this->res->setBody(array('title'=>'Welcome','message'=>'Welcome to SpeediFii'));

        var_dump($GLOBALS['config']);

        var_dump($GLOBALS['language']);

        $this->sendOK();
    }
}

/* EOF */