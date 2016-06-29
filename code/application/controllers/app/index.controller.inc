<?php

use speedifii\controllers\BaseController;

/**
 * Class IndexController
 */
class IndexController extends BaseController
{
    
    private $index = null;   
    
    private $indexCurl = null;
    
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
     * Get the correct API URL
     * @param string $data
     * @return string
     */
    private function apiUrl($data = '/') {

        return $GLOBALS['config']['application']['api_url'].trim($data, '/');

    }

    /**
     * @ Mysql call
     */
    public function indexAction()
    {
        $this->index = new IndexModel();
        // TODO: Implement IndexAction() method.
        
        //$where = array('id' => 6);
        $result = $this->index->user_list('users');
        
        echo "<pre>"; print_r($result); die;
        
        $this->res->setBody(array('title' => 'Welcome!', 'message' => 'Hello SpeediFii Mysql user List', 'list' => $result));
        $this->res->setHeader("AuthToken", 'sdsdhkjsdkjshd');
        $this->res->setCookie("WBSessionTxT", "kjshdkshdkjsjd", $GLOBALS['config']['session']['timeout']);
        $this->sendOK();
    }
    
    /**
     * @ Curl call
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
     * @ Curl call
     */
    public function listAction()
    {
        $this->indexCurl = new IndexCurlModel();
        
        $params =array(
            'page' => 1,
            'limit' => 100,
            'version' => 1
        );
        
        $where = array(
            'url' => $this->apiUrl('company/users'),
            'method' => 'GET',
            'headers' => $this->headers,
            'params' => $params
        );
        
        $result = $this->indexCurl->userList($where);
        
        $this->res->setBody(array('title' => 'Welcome!', 'message' => 'Hello Curl User List', 'list' => $result));
        $this->res->setHeader("AuthToken", 'sdsdhkjsdkjshd');
        $this->res->setCookie("WBSessionTxT", "kjshdkshdkjsjd", $GLOBALS['config']['session']['timeout']);
        $this->sendOK();
    }
    
    /**
     * @ Curl call
     */
    public function editAction($id)
    {
        $this->indexCurl = new IndexCurlModel();
        // TODO: Implement IndexAction() method.
        
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
     * @ Curl call
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