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
        
    }

    /**
     * @ Mysql call
     */
    public function indexAction()
    {
        $this->index = new Index();
        // TODO: Implement IndexAction() method.
        $data = array('email' => 'ppppppp');
        $where = array('id' => 6, 'name' => 'praveen');
        $result = $this->index->user_list('users', $where);
        echo "<pre>"; print_r($result); die;
        
        $this->res->setBody(array('title' => 'Welcome!', 'message' => 'Hello SpeediFii'));
        $this->res->setHeader("AuthToken", 'sdsdhkjsdkjshd');
        $this->res->setCookie("WBSessionTxT", "kjshdkshdkjsjd", $GLOBALS['config']['session']['timeout']);
        $this->sendOK();
    }
    
    /**
     * @ Curl call
     */
    public function listAction()
    {
        $this->index = new Index_curl();
        // TODO: Implement IndexAction() method.
        $data = array('email' => 'ppppppp');
        $where = array('id' => 6, 'name' => 'praveen');
        $result = $this->index->user_list('users', $where);
        
        $this->res->setBody(array('title' => 'Welcome!', 'message' => 'Hello Curl User List', 'list' => $result));
        $this->res->setHeader("AuthToken", 'sdsdhkjsdkjshd');
        $this->res->setCookie("WBSessionTxT", "kjshdkshdkjsjd", $GLOBALS['config']['session']['timeout']);
        $this->sendOK();
    }
    
    /**
     * @ Curl call
     */
    public function editAction()
    {
        $this->index = new Index_curl();
        // TODO: Implement IndexAction() method.
        $data = array('email' => 'ppppppp');
        $where = array('id' => 6, 'name' => 'praveen');
        $result = $this->index->user_list('users', $where);
        
        $this->res->setBody(array('title' => 'Welcome!', 'message' => 'Hello Curl User Edit', 'list' => $result));
        $this->res->setHeader("AuthToken", 'sdsdhkjsdkjshd');
        $this->res->setCookie("WBSessionTxT", "kjshdkshdkjsjd", $GLOBALS['config']['session']['timeout']);
        $this->sendOK();
    }
}

/* EOF */