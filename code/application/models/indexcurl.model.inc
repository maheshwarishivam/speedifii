<?php

//namespace application\model;

use application\model\CurlModel;

class IndexCurlModel extends CurlModel
{
    
    /**
     * IndexModel constructor.
     */
    public function __construct()
    {
        parent::__construct();
    }
    
    public function userList($data){
        
        $this->setUrl($data['url']);
        $this->setMethod($data['method']);
        $this->setHeaders($data['headers']);
        $this->setParams($data['params']);
        
        $this->exec();
        
        return $this->toArray();
    }

    
    public function userDetail($data){
        
        $this->setUrl($data['url']);
        $this->setMethod($data['method']);
        $this->setHeaders($data['headers']);
        
        $this->exec();
        
        return $this->toArray();
    }    

    
    public function updateUserDetail($data){
        
        $this->setUrl($data['url']);
        $this->setMethod($data['method']);
        $this->setHeaders($data['headers']);
        $this->setReqType($data['reqType']);
        $this->setRawBody($data['rawbody']);
        
        $this->exec();
        
        return $this->toArray();
    } 

    
    public function userDelete($data){
        
        $this->setUrl($data['url']);
        $this->setMethod($data['method']);
        $this->setHeaders($data['headers']);
        
        $this->exec();
        
        return $this->toArray();
    }     

    
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