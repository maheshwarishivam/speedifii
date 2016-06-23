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
        
        $this->curl->setUrl($data['url']);
        $this->curl->setMethod($data['method']);
        $this->curl->setHeaders($data['headers']);
        $this->curl->call();
        
        return $this->curl->toArray();
    }

    
    public function userDetail($data){
        
        $this->curl->setUrl($data['url']);
        $this->curl->setMethod($data['method']);
        $this->curl->setHeaders($data['headers']);
        $this->curl->call();
        
        return $this->curl->toArray();
    }    

    
    public function updateUserDetail($data){
        
        $this->curl->setUrl($data['url']);
        $this->curl->setMethod($data['method']);
        $this->curl->setHeaders($data['headers']);
        $this->curl->setReqType($data['reqType']);
        $this->curl->setRawBody($data['rawbody']);
        $this->curl->call();
        
        return $this->curl->toArray();
    } 

    
    public function userDelete($data){
        
        $this->curl->setUrl($data['url']);
        $this->curl->setMethod($data['method']);
        $this->curl->setHeaders($data['headers']);
        $this->curl->call();
        
        return $this->curl->toArray();
    }     

    
    public function addUser($data){
        
        $this->curl->setUrl($data['url']);
        $this->curl->setMethod($data['method']);
        $this->curl->setHeaders($data['headers']);
        $this->curl->setReqType($data['rawType']);
        $this->curl->setRawBody($data['rawBody']);
        $this->curl->call();
        
        return $this->curl->toArray();
    } 
    
}


/* EOF */