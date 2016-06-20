<?php

use speedifii\controllers\BaseController;

/**
 * Class IndexController
 */
class IndexController extends BaseController 
{
    
    private $index = null;

    /**
     * IndexController constructor.
     */
    public function __construct()
    {
        parent::__construct();
        $this->index = new Index();
    }

    /**
     * @inheritDoc
     */
    public function indexAction()
    {
       
        // TODO: Implement IndexAction() method.
        $data = array('email' => 'ppppppp');
        $where = array('id' => 6, 'name' => 'praveen');
        $result = $this->index->user_list('users');
        echo "<pre>"; print_r($result); die;
        
        $this->res->setBody(array('title' => 'Welcome!', 'message' => 'Hello SpeediFii'));
        $this->res->setHeader("AuthToken", 'sdsdhkjsdkjshd');
        $this->res->setCookie("WBSessionTxT", "kjshdkshdkjsjd", $GLOBALS['config']['session']['timeout']);
        $this->sendOK();
    }
    
    /**
     * @inheritDoc
     */
    public function insertAction()
    {
        // TODO: Implement ViewAction() method.
        $data = array('name' => 'praveen', 'email' => 'p98saxena@gmail.com');
        $result = $this->index->user_insert('users', $data);
        echo "<pre>"; print_r($result); die;
        
        $this->res->setBody(array('title' => 'Welcome!', 'message' => 'Hello SpeediFii View'));
        $this->res->setHeader("AuthToken", 'sdsdhkjsdkjshd');
        $this->res->setCookie("WBSessionTxT", "kjshdkshdkjsjd", $GLOBALS['config']['session']['timeout']);
        $this->sendOK();
    }
    
    
    /**
     * @inheritDoc
     */
    public function deleteAction()
    {
        // TODO: Implement ViewAction() method.
        $data = array('id' => 3);
        $result = $this->index->user_delete('users', $data);
        echo "<pre>"; print_r($result); die;

    }
    
    
    /**
     * @inheritDoc
     */
    public function updateAction()
    {
        // TODO: Implement ViewAction() method.
        $where = array('id' => 3);
        $data = array('name' => 'praveen', 'email' => 'p98saxena@gmail.com');
        $result = $this->index->user_update('users', $data, $where);
        echo "<pre>"; print_r($result); die;

    }
    
}

/* EOF */