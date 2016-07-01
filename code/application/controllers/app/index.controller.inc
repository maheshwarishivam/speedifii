<?php

use speedifii\controllers\BaseController;

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
        $this->sendOK();
    }
}

/* EOF */