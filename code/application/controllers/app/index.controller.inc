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