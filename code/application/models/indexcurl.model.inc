<?php

use application\model\CurlModel;

/**
 * Class IndexController
 * @package application\controllers\app\
 */
class IndexCurlModel extends CurlModel
{
    
    /**
     * IndexModel constructor.
     */
    public function __construct()
    {
        parent::__construct();
    }
    
    /**
     * @Curl Call userList Model Function
     */
    public function userList($data){
        
        $this->setUrl($data['url']);
        $this->setMethod($data['method']);
        $this->setHeaders($data['headers']);
        $this->setParams($data['params']);
        
        $this->exec();
        
        return $this->toArray();
    }

    /**
     * @Curl Call userDetail Model Function
     */
    public function userDetail($data){
        
        $this->setUrl($data['url']);
        $this->setMethod($data['method']);
        $this->setHeaders($data['headers']);
        
        $this->exec();
        
        return $this->toArray();
    }    

    /**
     * @Curl Call updateUserDetails Model Function
     */
    public function updateUserDetail($data){
        
        $this->setUrl($data['url']);
        $this->setMethod($data['method']);
        $this->setHeaders($data['headers']);
        $this->setReqType($data['reqType']);
        $this->setRawBody($data['rawbody']);
        
        $this->exec();
        
        return $this->toArray();
    } 

    /**
     * @Curl Call userDelete Model Function
     */
    public function userDelete($data){
        
        $this->setUrl($data['url']);
        $this->setMethod($data['method']);
        $this->setHeaders($data['headers']);
        
        $this->exec();
        
        return $this->toArray();
    }     

    /**
     * @Curl Call addUser Model Function
     */
    public function addUser($data){
        
        $this->setUrl($data['url']);
        $this->setMethod($data['method']);
        $this->setHeaders($data['headers']);
        $this->setReqType($data['rawType']);
        $this->setRawBody($data['rawBody']);
        
        $this->exec();
        
        return $this->toArray();
    } 
    
}


/* EOF */