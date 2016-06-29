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
     * @ Mysql call
     */
    public function indexAction()
    {
        // TODO: Implement IndexAction() method.
        $this->res->setBody(array('title'=>'Welcome','message'=>'Welcome to SpeediFii'));
        $this->sendOK();
    }
    
    /**
     * @inheritDoc
     */
    public function ViewAction()
    {
        // TODO: Implement ViewAction() method.
        $this->sendOK();
    }
}

/* EOF */