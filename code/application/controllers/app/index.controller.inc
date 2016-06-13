<?php

use speedifii\controllers\BaseController;

/**
 * Class IndexController
 */
class IndexController extends BaseController
{
    /**
     * IndexController constructor.
     */
    public function __construct()
    {
        parent::__construct();
    }

    /**
     * @inheritDoc
     */
    public function IndexAction()
    {
        // TODO: Implement IndexAction() method.
        $this->res->setBody(array('title' => 'Welcome!', 'message' => 'Hello SpeediFii'));
        $this->res->setHeader("AuthToken", 'sdsdhkjsdkjshd');
        $this->res->setCookie("WBSessionTxT", "kjshdkshdkjsjd", $GLOBALS['config']['session']['timeout']);
        $this->sendOK();

        //Write application logs after output is sent
        //TODO: Write application logs
    }
}

/* EOF */