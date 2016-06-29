<?php

use speedifii\controllers\BaseController;

/**
 * Class IndexController
 * @package application\controllers\app\
 */
class IndexController extends BaseController 
{
    
    /**
     * @var MySql Model Object
     */
    private $index = null;   
    
    /**
     * @var Curl Model Object
     */
    private $indexCurl = null;
    
    /**
     * @var Headers Object
     */
    private $headers = null;


    /**
     * IndexController constructor.
     */
    public function __construct()
    {
        parent::__construct();
        $this->headers = array(
            'Content-Type:application/json',
            'APIKey:62f7b668181f54c08191cf62a2373ff7',
            'AuthToken:396dbaa0de83aeb3971c6b6cdca35a0f'
        );
    }

    /**
     * @Mysql Call Dummy Function
     */
    public function indexAction()
    {
        $this->index = new IndexModel();
        
        //$where = array('id' => 6);
        $result = $this->index->user_list('users');
        
        echo "<pre>"; print_r($result); die;
        
        $this->res->setBody(array('title' => 'Welcome!', 'message' => 'Hello SpeediFii Mysql user List', 'list' => $result));
        $this->res->setHeader("AuthToken", 'sdsdhkjsdkjshd');
        $this->res->setCookie("WBSessionTxT", "kjshdkshdkjsjd", $GLOBALS['config']['session']['timeout']);
        $this->sendOK();
    }
    
    /**
     * @Curl Call Add Function
     */
    public function addAction()
    {
        if($_POST){
            $this->indexCurl = new IndexCurlModel();
            $rawBody = '{ "fname": "'.$_POST['fname'].'", "lname" : "'.$_POST['lname'].'", "email_id": "'.$_POST['email_id'].'", "phone" : "'.$_POST['phone'].'", "department" : "'.$_POST['department'].'", "password": '.$_POST['password'].' }';
            $where = array(
                'url' => $this->apiUrl('company/adduser'),
                'method' => 'POST',
                'headers' => $this->headers,
                'rawBody' => $rawBody,
                'rawType' => 'raw'
            );

            $result = $this->indexCurl->addUser($where);
           
            if($result['status'] == 200){ 
                $this->redirect('index.php/list');
            }
        } else {
        
            $this->res->setBody(array('title' => 'Welcome!', 'message' => 'Hello SpeediFii Add user'));
            $this->res->setHeader("AuthToken", 'sdsdhkjsdkjshd');
            $this->res->setCookie("WBSessionTxT", "kjshdkshdkjsjd", $GLOBALS['config']['session']['timeout']);
            $this->sendOK();
        }
    }
    
    /**
     * @Curl Call List function
     */
    public function list2Action()
    {
        $this->indexCurl = new IndexCurlModel();
        
        $params =array(
            'page' => 1,
            'limit' => 100,
            'version' => 1
        );
        
        $headers1 = array('content-type: multipart/form-data');
        
        $where = array(
            'url' => 'http://www.zopnow.com/pincode.json',
            'method' => 'POST',
            'headers' => $headers1,
            'body' => array('pincode' => '110058')
        );
        
        $result = $this->indexCurl->userList($where);
        echo "<pre>"; print_r($result); die;
    }
    
    /**
     * @Curl Call List function
     */
    public function listAction()
    {
        $this->indexCurl = new IndexCurlModel();
        
        $params =array(
            'page' => 1,
            'limit' => 100,
            'version' => 1
        );
        
        $headers1 = array('APIKey:62f7b668181f54c08191cf62a2373ff7', 'AuthToken: 396dbaa0de83aeb3971c6b6cdca35a0f');
        
        $where = array(
            'url' => 'http://api.raccoon.dev.canbrand.in/upload/image',
            'method' => 'POST',
            'headers' => $headers1,
            'body' => array('type' => 'course')
        );
        
        $result = $this->indexCurl->userList($where);
        echo "<pre>"; print_r($result); die;
        $this->res->setBody(array('title' => 'Welcome!', 'message' => 'Hello Curl User List', 'list' => $result));
        $this->res->setHeader("AuthToken", 'sdsdhkjsdkjshd');
        $this->res->setCookie("WBSessionTxT", "kjshdkshdkjsjd", $GLOBALS['config']['session']['timeout']);
        $this->sendOK();
    }
    
    /**
     * @Curl Call Edit function
     */
    public function editAction($id)
    {
        $this->indexCurl = new IndexCurlModel();
        
        if($_POST){
            
            $raw = '{ "fname": "'.$_POST['name'].'", "lname" : "'.$_POST['surname'].'", "email_id": "'.$_POST['email'].'" }';
            
            $data = array(
                
                'url' => $this->apiUrl('company/updateuser/'.$id),
                'method' => 'PUT',
                'headers' => $this->headers,
                'rawbody' => $raw,
                'reqType' => 'raw'
            );
            
            $result = $this->indexCurl->updateUserDetail($data);
            
            if($result['status'] == 200){ 
                $this->redirect('index.php/list'); 
            }
            
        } else {

            $where = array(
                'url' => $this->apiUrl('company/user/'.$id),
                'method' => 'GET',
                'headers' => $this->headers
            );
            
            $result = $this->indexCurl->userDetail($where);

            if($result['status'] == 200){
                $this->res->setBody(array('title' => 'Welcome!', 'message' => 'Hello Curl User Edit', 'list' => $result));
                $this->res->setHeader("AuthToken", 'sdsdhkjsdkjshd');
                $this->res->setCookie("WBSessionTxT", "kjshdkshdkjsjd", $GLOBALS['config']['session']['timeout']);
                $this->sendOK();
            }
        }
    }
    
    /**
     * @Curl Delete Call Function
     */
    public function deleteAction($id)
    {
        $this->indexCurl = new IndexCurlModel();
        
        $where = array(
            'url' => $this->apiUrl('company/deleteuser/'.$id.'/1'),
            'method' => 'GET',
            'headers' => $this->headers
        );
        
        $result = $this->indexCurl->userDelete($where);
        
        if($result['status'] == 200){
            $this->redirect('index.php/list');
        }
    }
}

/* EOF */